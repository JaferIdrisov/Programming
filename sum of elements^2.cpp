#include <iostream>
#include <random>
#include <cmath>
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

int result=0;
int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(1, 10);


  int matrix1[3][3];
  for(int i=0;i<3;i++){
      for (int j=0;j<3;j++){
          matrix1[i][j]=distribution(gen);
      }
  }
    printf("Matrix 1:\n");
    show(matrix1);

    for(int i=0;i<3;i++){
        for (int j=0;j<3;j++){

            result+=pow(matrix1[i][j],2);
        }
    }
    cout<<result;


    return 0;
}
