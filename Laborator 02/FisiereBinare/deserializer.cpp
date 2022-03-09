#include "deserializer.h"
#include <iostream>

bool Deserializer::read_buffer(void* buffer, unsigned size) {
    return fread(buffer, 1, size, this->file) == size;
}

bool Deserializer::read_movie(Movie& movie) {
    unsigned year;
    unsigned length;
    double score;
    char name[200];

    if (this->read_buffer(&year, sizeof(year)) == false)
        return false;
    if (this->read_buffer(&length, sizeof(length)) == false)
        return false;
    if (this->read_buffer(&score, sizeof(score)) == false)
        return false;

    int name_length;
    if (this->read_buffer(&name_length, sizeof(name_length)) == false)
        return false;

    if (this->read_buffer(&name, sizeof(char) * name_length + 1) == false)
        return false;

    movie.set_year(year);
    movie.set_length(length);
    movie.set_score(score);
    movie.set_name(name);

    return true;
}

bool Deserializer::init(const char* file_name) {
    this->file = fopen(file_name, "rb");
    return this->file != nullptr;
}

void Deserializer::close() {
    if (this->file != nullptr)
        fclose(this->file);
}

bool Deserializer::read(MovieSeries& series) {
    unsigned size;
    if (this->read_buffer(&size, sizeof(size)) == false)
        return false;;
    for (unsigned index = 0; index < size; index++) {
        Movie movie;
        if (this->read_movie(movie) == false)
            return false;
        series.add(movie);
    }

    
    return true;
}
