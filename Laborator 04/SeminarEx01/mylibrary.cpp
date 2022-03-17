#define _CRT_SECURE_NO_WARNINGS
#include "MyLibrary.h"
#include <cstring>
#include <cstdarg>

MyLibrary::MyLibrary(std::ostream& output_stream) : output_stream(output_stream) {
    this->books_count = 0;
    this->books = new int[0];
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int* books) : output_stream(output_stream) {
    this->books_count = books_count;
    this->books = new int[books_count];
    for (unsigned i = 0; i < books_count; i++)
        this->books[i] = books[i];
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int min, int max) : output_stream(output_stream) {
    this->books_count = books_count;
    this->books       = new int[books_count];
    for (unsigned i = 0; i < books_count; i++)
        this->books[i] = min + rand() % max + 1;
}

MyLibrary::MyLibrary(std::ostream& output_stream, const char* books_values) : output_stream(output_stream) {
    this->books_count = 0;
    for (unsigned i = 0; i < strlen(books_values); i++) {
        if (books_values[i] == ';')
        {
            this->books_count++;
        }
    }
    if (strlen(books_values) != 0)
    {
        this->books_count++;
    }
    
    this->books = new int[this->books_count];

    int index = 0;
    char *buffer = new char[strlen(books_values) + 1];

    strcpy(buffer, books_values);
    char* book = strtok(buffer, ";");

    while (book != nullptr) {
        this->books[index++] = atoi(book);
        book = strtok(nullptr, ";");
    }

    delete[] buffer;
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, ...) : output_stream(output_stream) {
    this->books_count = books_count;
    this->books = new int[books_count];
    
    va_list args;
    va_start(args, books_count);
    for (unsigned i = 0; i < books_count; i++) {
        this->books[i] = va_arg(args, int);
    }
    va_end(args);
}

MyLibrary::MyLibrary(const MyLibrary& obj) : MyLibrary(obj.output_stream, obj.books_count, obj.books) {}

MyLibrary::~MyLibrary() {
    delete[] books;
}

void MyLibrary::print_books() const{
    if (this->books_count == 0) {
        this->output_stream << -1 << "\n";
        return;
    }

    this->output_stream << this->books_count << "\n";
    for (unsigned i = 0; i < this->books_count; i++)
        this->output_stream << this->books[i] << " ";
    this->output_stream << "\n";
}

void MyLibrary::update_book_id_by_index(unsigned book_index, int book_id) {
    if (book_index < this->books_count)
        this->books[book_index] = book_id;
}

int MyLibrary::get_books_count() const {
    return this->books_count;
}

int MyLibrary::get_book_id_by_index(unsigned book_index) const {
    if (book_index < this->books_count)
        return this->books[book_index];
    return -1;
}
