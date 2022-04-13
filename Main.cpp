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
    
    string oper;
    bool ans = true;
    while(ans){
    cout<<"Please choose operator: "<<endl;
    cin>>oper;

    if (oper == "+"){
      cout<<"mat1+mat2"<<endl;
      cout<<mat1+mat2<<endl;
      
    }else if (oper == "+u"){
      cout<<"+mat1"<<endl;
      cout<<+mat1<<endl;
    }
    else if (oper == "+="){
      cout<<"mat1+=mat2"<<endl;
      cout<<(mat1+=mat2)<<endl;
    }
    else if (oper == "-"){
      cout<<"mat1-mat2"<<endl;
      cout<<mat1-mat2<<endl;

    }else if (oper == "-u"){
      cout<<"-mat1"<<endl;
      cout<<-mat1<<endl;
    }
    else if (oper == "-="){
      cout<<"mat1-=mat2"<<endl;
      cout<<(mat1-=mat2)<<endl;
    }
    else if(oper == ">"){
      cout<<"mat1>mat2"<<endl;
      cout<<(mat1>mat2)<<endl;
    }
    else if(oper == ">="){
      cout<<"mat1>=mat2"<<endl;
      cout<<(mat1>=mat2)<<endl;
    }
    else if(oper == "<"){
      cout<<"mat1<mat2"<<endl;
      cout<<(mat1<mat2)<<endl;
    }
    else if(oper == "<="){
      cout<<"mat1<=mat2"<<endl;
      cout<<(mat1<=mat2)<<endl;
    }
    else if(oper == "!="){
      cout<<"mat1!=mat2"<<endl;
      cout<<(mat1!=mat2)<<endl;
    }
    else if(oper == "++b"){//before
    cout<<"++mat1"<<endl;
      cout<<++mat1<<endl;
    }
    else if(oper == "++"){//after
    cout<<"mat1++"<<endl;
      cout<<mat1++<<endl;
    }
    else if(oper == "--b"){//before
    cout<<"--mat1"<<endl;
      cout<<--mat1<<endl;
    }
    else if(oper == "--"){//after
    cout<<"mat1--"<<endl;
      cout<<mat1--<<endl;
    }
    else if(oper == "*"){
      cout<<"mat1*mat2"<<endl;
      cout<<mat1*mat2<<endl;
    }
    else if(oper == "*=m"){
      cout<<"mat1*=mat2"<<endl;
      cout<<(mat1*=mat2)<<endl;
    }
    else if(oper == "*=s"){
      double scalar;
      cout<<"Please choose scalar"<<endl;
      cin >> scalar;
      cout<<"mat1*=scalar"<<endl;
      cout<<(mat1*=scalar)<<endl;
    }
    else if(oper == "=="){
      cout<<"mat1==mat2"<<endl;
      cout<<(mat1==mat2)<<endl;
    }
    else if(oper == "s*m"){//scalar*matrix
      double scalar;
      cout<<"Please choose scalar"<<endl;
      cin >> scalar;
      cout<<"scalar*mat1"<<endl;
      cout<<(scalar*mat1)<<endl;
    }
    else if(oper == "s*m"){//matrix*scalar
      double scalar;
      cout<<"Please choose scalar"<<endl;
      cin >> scalar;
      cout<<"mat1*scalar"<<endl;
      cout<<(mat1*scalar)<<endl;
    }
    else if(oper == "stop"){
      ans = false;
    }
    }
    return 0;
}
//run code with clang++ Main.cpp -o Main and after ./Main