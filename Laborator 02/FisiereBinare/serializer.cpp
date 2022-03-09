#include "serializer.h"

bool Serializer::write_buffer(const void* buffer, unsigned size) {
    return fwrite(buffer, 1, size, this->file) == size;
}

bool Serializer::write_movie(const Movie& movie) {
    unsigned year = movie.get_year();
    unsigned length = movie.get_length();
    double score = movie.get_score();
    const char* name = movie.get_name();

    if (this->write_buffer(&year, sizeof(year)) == false)
        return false;
    if (this->write_buffer(&length, sizeof(length)) == false)
        return false;
    if (this->write_buffer(&score, sizeof(score)) == false)
        return false;

    int name_length = strlen(name);
    if (this->write_buffer(&name_length, sizeof(name_length)) == false)
        return false;

    if (this->write_buffer(name, sizeof(char) * name_length + 1) == false)
        return false;

    return true;
}

bool Serializer::init(const char* file_name) {
    this->file = fopen(file_name, "wb");
    return this->file != nullptr;
}

void Serializer::close() {
    if (this->file != nullptr)
        fclose(this->file);
}

bool Serializer::write(const MovieSeries& series) {
    
    unsigned size = series.get_size();
    if (this->write_buffer(&size, sizeof(size)) == false)
        return false;
    for (unsigned index = 0; index < size; index++)
        if (this->write_movie(series.get_movie(index)) == false)
            return false;
    return true;

}
