#include "classes.h"

int Vect::count=1;

Vect::Vect(int dim, double *rawValues) {
    this->dimention = dim;
    this->values = rawValues;
    id=count++;
    std::cout << "Vector "<<id<<" was created"<< std::endl;
}
Vect::~Vect(){
    std::cout << "Vector "<<id<<" was deleted"<< std::endl;
    delete[] values;
}

bool Check(Vect *first, Vect &second) {
    return first->getDimention() == second.getDimention();
}

Vect *Vect::operator=(const Vect &other) {
    this->dimention = other.dimention;
    this->values = other.values;
    return this;
}


Vect Vect::operator+(Vect &other) {
    if (Check(this, other)) {
        Vect temp = Vect(other.dimention, new double[other.dimention]);
        temp.dimention = this->dimention;
        for (int i = 0; i < this->dimention; i++)
            temp.values[i] = this->values[i] + other.values[i];
        return temp;
    }
    throw std::runtime_error("Invalid dimention of second vector");
}

Vect Vect::operator-(Vect &other) {
    if (this == nullptr) {
        Vect temp = Vect(other.dimention, new double[other.dimention]);
        temp.dimention = other.dimention;
        for (int i = 0; i < other.dimention; i++)
            temp.values[i] = 0 - other.values[i];
        return temp;
    }
    if (Check(this, other)) {
        Vect temp = Vect(other.dimention, new double[other.dimention]);
        temp.dimention = this->dimention;
        for (int i = 0; i < this->dimention; i++)
            temp.values[i] = this->values[i] - other.values[i];
        return temp;
    }
    throw std::runtime_error("Invalid dimention of second vector");
}

Vect Vect::operator*(Vect &other) {
    if (Check(this, other)) {
        Vect temp = Vect(other.dimention, new double[other.dimention]);
        temp.dimention = this->dimention;
        for (int i = 0; i < this->dimention; i++)
            temp.values[i] = this->values[i] * other.values[i];
        return temp;
    }
    throw std::runtime_error("Invalid dimention of second vector");
}

Vect Vect::operator/(Vect &other) {
    if (Check(this, other)) {
        Vect temp = Vect(other.dimention, new double[other.dimention]);
        temp.dimention = this->dimention;
        for (int i = 0; i < this->dimention; i++)
            temp.values[i] = this->values[i] / other.values[i];
        return temp;
    }
    throw std::runtime_error("Invalid dimention of second vector");
}

Vect Vect::operator*(double scalar) {
    Vect temp = Vect(dimention, new double[dimention]);
    for (int i = 0; i < dimention; ++i) {
        temp.values[i] = values[i] * scalar;
    }
    return temp;
}

Vect Vect::negativeVect(Vect) {
    Vect temp = Vect(dimention, new double[dimention]);
    for (int i = 0; i < dimention; ++i) {
        temp.values[i] = values[i] * -1;
    }
    return temp;
}


int Vect::getDimention() {

    return this->dimention;
}

void Vect::printV() {
    for (int i = 0; i < this->dimention; i++) {

        std::cout << this->values[i] << " "<<std::endl;
    }
}




