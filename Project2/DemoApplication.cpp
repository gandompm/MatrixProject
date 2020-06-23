#include "Matrix.h"
#include <iostream>
using namespace std;


int main()
{
    int data[] = { 1,2,3,4,3,3,2,2,3,2,2,3,2,1,3,2,3,4,2,3,2,3,4,3,2};
    int data2[] = { 1,2,3,4,3,3,2,2,3,2,2,3,2,1,3,2,3,4,2,3,2,3,4,3,2 };

    Matrix<int> m1(data,4,4);
    Matrix<int> m2(data2,4,4); 


    cout << "First Matrix: " << endl;
    m1.printData();
    cout << "Second Matrix: " << endl;
    m2.printData();
    cout << "Addition Matrix: " << endl;
    m1 += m2;
    m1.printData();
    cout << endl;
    m2.printData();
   
    cout << "Multiplication Matrix: " << endl;
    m1 *= m2;
    m1.printData();

    Matrix<int> m3(data,2,2);
    m2 = &m1; // copy assignment
    m3 = std::move(m1); // move assignment 


    bool isequal = (m1 == m2);
    cout << endl; 
    cout << "the equality: " << isequal << endl;

        
  

    return 0;
}

