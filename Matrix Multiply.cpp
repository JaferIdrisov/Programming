#include <iostream>
#include <random>
using namespace std;

void show(int M[3][3]){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << M[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(1, 100);
  int matrix1[3][3], matrix2[3][3],matrix3[3][3];
  for(int i=0;i<3;i++){
      for (int j=0;j<3;j++){
          matrix1[i][j]=distribution(gen);
      }
  }
    printf("Matrix 1:\n");
    show(matrix1);

    for(int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            matrix2[i][j]=distribution(gen);
        }
    }

    printf("Matrix 2:\n");
    show(matrix2);

    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            matrix3[i][j]=0;
            for(int k=0;k<3;k++){
                matrix3[i][j]+=matrix1[i][k]*matrix2[k][j];
            }
        }
    }

    printf("Resul of matrix1*matrix2:\n");
    show(matrix3);


    return 0;
}
