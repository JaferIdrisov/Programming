#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

double sum(double var1, double var2);

double sub(double var1, double var2);

double mul(double var1, double var2);

double div(double var1, double var2);

unsigned long long fact(int n);

void mat(int matrix1[3][3], int matrix2[3][3]);


int main() {
    while (true) {
        int choice, var3;
        double var1, var2;
        char operation;
        int matrix1[3][3];
        int matrix2[3][3];

        cout << "Which type of operation you want to use:" << "\n" << "1 - Sum of matrix" << "\n" << "2 - Factorial"
             << "\n" << "3 - Common operations" << "\n" << "4 - Exit" << "\n";
        cin
                >> choice;

        switch (choice) {
            case 1:
                mat(matrix1, matrix2);
                break;

            case 2:
                cout << "Enter number to find it factorial:" << "\n";
                cin >> var3;
                cout << "Result: " << fact(var3) << endl;
                break;


            case 3:
                cout << "Enter math expression:" << "\n";

                cin >> var1 >> operation >> var2;
                switch (operation) {
                    case '+':
                        cout << "Result: " << sum(var1, var2) << endl;
                        break;

                    case '*':
                        cout << "Result: " << mul(var1, var2) << endl;
                        break;

                    case '-':
                        cout << "Result: " << sub(var1, var2) << endl;
                        break;

                    case '/':
                        cout << "Result: " << div(var1, var2) << endl;
                        break;

                    case '^':
                        cout << "Result: " << pow(var1, var2) << endl;
                        break;


                    default:
                        return 0;
                }
                break;

            case 4:
                cout << "Exiting the program";
                exit(EXIT_SUCCESS);


            default:
                return 0;
        }
    }
}


double sum(double var1, double var2) {
    return var1 + var2;
}

double sub(double var1, double var2) {
    return var1 - var2;
}

double mul(double var1, double var2) {
    return var1 * var2;
}

double div(double var1, double var2) {
    if (var2 == 0) {
        cout << "You cant divide by zero";
    } else {
        return var1 / var2;
    }

}

unsigned long long int fact(int n) {
    unsigned long long int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

void mat(int matrix1[3][3], int matrix2[3][3]) {
    cout << "Enter matrix1:" << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix1[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix1[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";

    cout << "Enter matrix2:" << "\t";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix2[i][j] = rand() % 10;
        }
    }

    cout << "\n";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix2[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
    cout << "Sum of matrix:" << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix1[i][j] + matrix2[i][j] << "\t";
        }
        cout << "\n";
    }

}
