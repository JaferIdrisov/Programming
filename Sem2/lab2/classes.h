#include <iostream>


class Mat {
private:
    int id;
    int rows;
    int cols;
    double **values;
public:
    static int count;
    Mat *operator=(const Mat &other);
    Mat operator+(const Mat &other);
    Mat operator-(Mat &other);
    Mat operator*(double scalar);
    Mat operator*(Mat &other);
    Mat(int rows, int cols);
    Mat negativeMatrix(Mat);
    ~Mat();
    int getRows();
    int getCols();
    bool CheckM(Mat *first, Mat &second);
    void Value(int row, int col, double value);
    double getValue(int row, int col);

    void print(int row, int col);
};



class Vect {
private:
    int id;
    int dimention;
    double *values;
public:
    static int count;
    Vect(int dim, double *rawValues);
    ~Vect();
    Vect *operator=(const Vect &other);
    Vect operator+(Vect &other);
    Vect operator-(Vect &other);
    Vect operator*(Vect &other);
    Vect operator/(Vect &other);
    Vect operator*(double scalar);
    Vect operator*(Mat &matrix);
    Vect negativeVect(Vect);
    int getDimention();
    //bool CheckV(Vect *first, Vect &second);
    void printV();
};