#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "sources/Matrix.cpp"


using namespace std;
using namespace zich;

int main(){


    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix mat1{identity,3,3};

    std::vector<double> vec = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    Matrix mat2{vec,3,3};
    
    // std::vector<double> arr_cin = {1, 1, 1, 1, 1, 1, 1, 1, 1,1,1,1};
    // Matrix mat_cin{arr_cin,3,4};
    // // cout<<mat1;
    // cout << (mat1);

    // istringstream cin{"[1 1 1 1], [1 1 1 1], [1 1 1 1]\n"};
    // is >> mat1;
    // cout <<"m: "<< (mat1)<<endl;
    // Matrix mat1; 
    // Matrix mat2;
    string oper;
    // cout<<"Please give a matrix: "<<endl;
    // cin>>mat1;
    // cout<<mat1<<endl;
    // cout<<"Please give another matrix: "<<endl;
    // cin>>mat2;
    cout<<"Please choose operator: "<<endl;
    cin>>oper;

    if (oper == "+")
    {
      cout<<mat1+mat2<<endl;
      
    }else if (oper == "-")
    {
      cout<<mat1-mat2<<endl;
      cout<<-mat1<<endl;

    }else if (oper == "+=")
    {
      cout<<(mat1+=mat2)<<endl;
    }
    
    
    
    return 0;
}