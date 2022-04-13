#include <iostream>

using namespace std;

int main(){
    int a = 0;
    cout << &a;
    int* b = &a;
    *b = 5;
    int** c = &b;
}