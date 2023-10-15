#include <iostream>
#include <random>
using namespace std;


int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(1, 10);

   int* size;
   size= new int;
   cin >>*size;
   int* num;
   num = new int[*size];
   for(int i=0;i<*size;i++){
       num[i]=distribution(gen);
   }
   for(int i=0;i<*size;i++){
       cout<<num[i]<< " ";
   }

   delete [] num;
   delete size;





    return 0;
}
