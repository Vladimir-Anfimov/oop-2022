#include "movieseries.h"
#include <iostream>

void MovieSeries::init() {
    this->size = 0;
}

void MovieSeries::add(const Movie& ep) {
    this->movies[size] = ep;
    size += 1;
}

void MovieSeries::print() const {
    for (unsigned i = 0; i < size; i++)
        std::cout << this->movies[i].get_name() << " " << this->movies[i].get_score() << " "
                  << this->movies[i].get_year() << " " << this->movies[i].get_length() <<'\n';
}

unsigned MovieSeries::get_size() const {
    return this->size;
}

const Movie& MovieSeries::get_movie(unsigned index) const {
    return this->movies[index];
}