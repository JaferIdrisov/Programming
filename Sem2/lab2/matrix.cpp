#include "classes.h"

int Mat::count = 1;
bool Mat::CheckM(Mat *first, Mat &second) {
    if (this->cols != second.cols || this->rows != second.rows) {
        //std::cerr << "Invalid rows or cols";
        return false;
    }
    return true;
}

Mat::Mat(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
    id=count++;
    values = new double *[rows];
    for (int i = 0; i < rows; i++) {
        values[i] = new double[cols];
    }
    std::cout << "Matrix "<<id<<" was created"<< std::endl;
}

Mat::~Mat() {
    if (values != nullptr) {
        std::cout << "Matrix "<<id<<" was deleted"<< std::endl;
        for (int i = 0; i < rows; i++) {
            delete[] values[i];
        }
        delete[] values;
    }
}

void Mat::Value(int row, int col, double value) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        values[row][col] = value;
        return;
    }
}

void Mat::print(int row, int col) {
    double p = *&values[row][col];
    std::cout << p << std::endl;
}

double Mat::getValue(int row, int col) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        return values[row][col];
    }
}

int Mat::getRows() {
    return this->rows;
}

int Mat::getCols() {
    return this->cols;
}

Mat *Mat::operator=(const Mat &other) {
    if (this != &other) {
        if (values != nullptr) {
            for (int i = 0; i < rows; ++i) {
                delete[] values[i];
            }
            delete[] values;
        }
        this->rows = other.rows;
        this->cols = other.cols;
        this->values = new double *[rows];
        for (int i = 0; i < rows; ++i) {
            values[i] = new double[cols];
            for (int j = 0; j < cols; ++j) {
                values[i][j] = other.values[i][j];
            }
        }
    }
    return this;
}


Mat Mat::operator+(const Mat &other) {
    if (this->cols != other.cols || this->rows != other.rows) std::cerr << "Error dims"<<std::endl;
    Mat temp = Mat(other.cols, other.rows);
    for (int i = 0; i < other.rows; i++)
        for (int j = 0; j < other.cols; j++) {
            temp.values[i][j] = this->values[i][j] + other.values[i][j];
        }
    return temp;
}

Mat Mat::operator-(Mat &other) {
    if (this->cols != other.cols || this->rows != other.rows) std::cerr << "Error dims"<<std::endl;
    Mat temp = Mat(other.getRows(), other.getCols());
    for (int i = 0; i < this->getRows(); i++) {
        for (int j = 0; j < this->getCols(); j++) {
            temp.values[i][j] = this->values[i][j] - other.values[i][j];
        }
    }
    return temp;
}

Mat Mat::operator*(double scalar) {
    Mat temp = Mat(this->getRows(), this->getCols());
    for (int i = 0; i < this->getRows(); i++) {
        for (int j = 0; j < this->getCols(); j++) {
            temp.values[i][j] = this->values[i][j] * scalar;
        }
    }
    return temp;
}

Mat Mat::operator*(Mat &other) {
    if (this->cols!=other.rows) std::cerr << "Error dims"<<std::endl;
    Mat temp = Mat(this->getRows(), this->getCols());
    for (int i = 0; i < this->getRows(); i++) {
        for (int j = 0; j < this->getCols(); j++) {
            for (int k = 0; k < this->getRows(); k++) {
                temp.values[i][j] += this->values[i][k] * other.values[k][j];
            }
        }
    }
    return temp;
}


Vect Vect::operator*(Mat &matrix) {
    if (this->dimention!=matrix.getCols()) std::cerr << "Error dims"<<std::endl;
    Vect temp = Vect(matrix.getCols(), new double[matrix.getCols()]);
    for (int i = 0; i < matrix.getRows(); i++) {
        double sum = 0;
        for (int j = 0; j < matrix.getCols(); j++) {
            sum += values[j] * matrix.getValue(i, j);
        }
        temp.values[i] = sum;
    }
    return temp;
}

Mat Mat::negativeMatrix(Mat) {
    Mat temp = Mat(this->getRows(), this->getCols());
    for (int i = 0; i < this->getRows(); i++) {
        for (int j = 0; j < this->getCols(); j++) {
            temp.values[i][j] = this->values[i][j] * -1;
        }
    }
    return temp;
}




















