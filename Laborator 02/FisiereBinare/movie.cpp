#include "movie.h"
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>

void Movie::init() {
    this->length = 0;
    this->year = 0;
    this->score = 0;
    this->name[0] = '\0';
}

void Movie::set_name(const char* name) {
    strcpy(this->name, name);
}

void Movie::set_score(double score) {
    this->score = score;
}

void Movie::set_year(unsigned year) {
    this->year = year;
}

void Movie::set_length(unsigned length) {
    this->length = length;
}

const char* Movie::get_name() const {
    return this->name;
}

double Movie::get_score() const {
    return this->score;
}

unsigned Movie::get_year() const {
    return this->year;
}

unsigned Movie::get_length() const {
    return this->length;
}
