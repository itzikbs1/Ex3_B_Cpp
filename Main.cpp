#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "Matrix.cpp"


using namespace std;
using namespace zich;

int main(){

    // int row;
    // cout << "Please enter positive number that is the row:";
    // cin >> row;

    // int col;
    // cout << "Please enter positive number that is the columns :";
    // cin >> col;

    // vector<double> vec(10);
    // Matrix mat = Matrix(vec ,row, col);
    // cout << "Please enter the values of the matrix :";
    // cin >> mat;

    // cout << mat;
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix mat1{identity,3,3};
    
    std::vector<double> arr_cin = {1, 1, 1, 1, 1, 1, 1, 1, 1,1,1,1};
    Matrix mat_cin{arr_cin,3,4};
    // cout<<mat1;
    cout << (mat1);

    istringstream is{"[1 1 1 1], [1 1 1 1], [1 1 1 1]\n"};
    is >> mat1;
    cout <<"m: "<< (mat1)<<endl;
    return 0;
}