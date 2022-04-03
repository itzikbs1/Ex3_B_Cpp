#include <iostream>
#include <stdlib.h>
#include <string>
// #include "Demo.cpp"
// #include <vector>
// #include <vecintrin.h>
#include "Matrix.hpp"
// #include <stdexcept>
#include "cmath"
using namespace std;
using namespace zich;

        Matrix::Matrix(){
            
        }
        // Matrix::Matrix(vector<vector<double>> mat, int row, int col){
        //     (*this).row = row;
        //     (*this).col = col;
        //     for (size_t i = 0; i < (*this).row; i++){
        //             for (size_t j = 0; j < (*this).col; j++)
        //             {
        //                 (*this).mat[i][j] = mat[i][j];
        //             }
        //         }
        // }
        Matrix::Matrix(vector<double> m, int row, int col){
            size_t x=0;
            for(int i=0; i<row; i++){
                vector<double> vec;
                for(int j=0; j<col; j++){
                    vec.push_back(m[x]);
                    x++;
                }
                (*this).mat.push_back(vec);
                // this->mat.push_back(vec);
            }
            (*this).row = row;
            (*this).col = col;
            // this->row = row;
            // this->col = col;
        }
        //  Matrix::Matrix(Matrix &m){
            
        //     size_t x=0;
        //     for(int i=0; i<row; i++){
        //         vector<double> vec;
        //         for(int j=0; j<col; j++){
        //             vec.push_back(m[x]);
        //             x++;
        //         }
        //         (*this).mat.push_back(vec);
        //         // this->mat.push_back(vec);
        //     }
        //     (*this).row = row;
        //     (*this).col = col;
        //     // this->row = row;
        //     // this->col = col;
        // }

        Matrix Matrix::operator+(Matrix &a){
            // cout<<"44"<<endl;
            if(a.row != (*this).row || a.col != (*this).col){
                throw("Iligiel of size matrtix");
            }
            // Matrix m(vector<double> vec, a.getrow(), a.getcol());
            Matrix m = Matrix(a);
            for (size_t i = 0; i < (*this).row; i++){
                for (size_t j = 0; j < (*this).col; j++)
                {
                    m.mat[i][j] = a.mat[i][j] + (*this).mat[i][j];
                }
            }
            return m;
            }

        Matrix Matrix::operator+(double scalr){
            Matrix m = Matrix(*this);
            for (int i = 0; i < (*this).getrow(); i++)
            {
                for (int j = 0; j < (*this).getcol(); j++)
                {
                    m.mat[i][j]+= scalr;
                }
            }
            return m;
        }
        Matrix Matrix::operator+(){
            Matrix m = Matrix(*this);
            for (int i = 0; i < (*this).getrow(); i++)
            {
                for (int j = 0; j < (*this).getcol(); j++)
                {
                    if(m.mat[i][j] < 0){
                    m.mat[i][j] *= -1;
                }
            }
            }
            return m;
        }

        Matrix Matrix::operator+=(Matrix &a){
            for (size_t i = 0; i < (*this).row; i++)
            {
                for (size_t j = 0; j < (*this).col; j++)
                {
                    (*this).mat[i][j] += a.mat[i][j];
                }
            }
            return (*this);
        }
        Matrix Matrix::operator+=(double scalr){
            for (size_t i = 0; i < (*this).row; i++)
            {
                for (size_t j = 0; j < (*this).col; j++)
                {
                    (*this).mat[i][j]+= scalr;
                }
            }
            return (*this);
        }
        Matrix Matrix::operator-(Matrix &a){
            Matrix m = Matrix((*this));
                if(a.row != (*this).row || a.col != (*this).col){
                    throw("Iligiel of size matrtix");
                }
                for (size_t i = 0; i < (*this).row; i++){
                    for (size_t j = 0; j < (*this).col; j++)
                    {
                        m.mat[i][j] -= a.mat[i][j];
                    }
                }
                return m;
        }

       Matrix Matrix::operator-(double scalr){
            Matrix m = Matrix((*this));
               
                for (size_t i = 0; i < (*this).row; i++){
                    for (size_t j = 0; j < (*this).col; j++)
                    {
                        m.mat[i][j] -= scalr;
                    }
                }
                return m;
        }
        Matrix Matrix::operator-(){//return new one
            Matrix m = Matrix(*this);
            int minus_one = -1;
            for (size_t i = 0; i < (*this).row; i++){
                    for (size_t j = 0; j < (*this).col; j++)
                    {
                        if(m.mat[i][j] != 0){
                        m.mat[i][j] *= minus_one;
                    }
                    }
                }
                return m;

        }
        Matrix Matrix::operator-=(Matrix &a){
            // Matrix m;
                if(a.row != (*this).row || a.col != (*this).col){
                    throw("Iligiel of size matrtix");
                }
                for (size_t i = 0; i < (*this).row; i++){
                    for (size_t j = 0; j < (*this).col; j++)
                    {
                        (*this).mat[i][j] -= a.mat[i][j];
                    }
                }
                return (*this);
        }
        Matrix Matrix::operator-=(double scalr){
            
            for (size_t i = 0; i < (*this).row; i++){
                for (size_t j = 0; j < (*this).col; j++)
                {
                    (*this).mat[i][j] -= scalr;
            }
            }
            return (*this);
        }
        bool Matrix::compare_equal(Matrix &a, Matrix &b){

            if(a.row != b.row || a.col != b.col){
                    throw("Iligiel of size matrtix");
                }
            for (size_t i = 0; i < a.row; i++)
            {
                for (size_t j = 0; j < a.col; j++)
                {
                    if (a.mat[i][j] != b.mat[i][j])
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        double Matrix::amount(Matrix &m){
            double sum = 0;
            for (size_t i = 0; i < m.row; i++)
            {
                for (size_t j = 0; j < m.col; j++)
                {
                    sum += m.mat[i][j];
                }
            }
            return sum;
        }
        bool Matrix::operator>(Matrix &a){
            double sum_mat = Matrix::amount(*this);
            double sum_a = Matrix::amount(a);
            if (sum_mat > sum_a)
            {
                return true;
            }
            return false;
        }
        bool Matrix::operator>=(Matrix &a){
            double sum_mat = Matrix::amount(*this);
            double sum_a = Matrix::amount(a);
            if (sum_mat >= sum_a)
            {
                return true;
            }
            return false;
        }
        bool Matrix::operator<(Matrix &a){
            double sum_mat = Matrix::amount(*this);
            double sum_a = Matrix::amount(a);
            if (sum_mat < sum_a)
            {
                return true;
            }
            return false;
        }
        bool Matrix::operator<=(Matrix &a){
            double sum_mat = Matrix::amount(*this);
            double sum_a = Matrix::amount(a);
            if (sum_mat <= sum_a)
            {
                return true;
            }
            return false;
        }
        bool Matrix::operator==(Matrix &a){
            return Matrix::compare_equal(*this, a);
        }
        bool Matrix::operator!=(Matrix &a){
            return !(Matrix::compare_equal(*this, a));
        }
        // Matrix Matrix::operator*(double scalr){
        //     return Matrix();
        // }
        Matrix Matrix::operator++(int n){
        Matrix m = Matrix(*this);
        for (size_t i = 0; i < m.row; i++)
            {
                for (size_t j = 0; j < m.col; j++)
                {
                    (*this).mat[i][j] += 1;
                }
            }
            return m;
        }
        Matrix Matrix::operator++(){
            for (size_t i = 0; i < (*this).row; i++)
            {
                for (size_t j = 0; j < (*this).col; j++)
                {
                    (*this).mat[i][j] += 1;
                }
            }
            return *this;
        }
        Matrix Matrix::operator--(int n){
            Matrix m = Matrix(*this);
            for (size_t i = 0; i < m.row; i++)
            {
                for (size_t j = 0; j < m.col; j++)
                {
                    (*this).mat[i][j] -= 1;
                }
            }
            return m;
        }
        Matrix Matrix::operator--(){
            for (size_t i = 0; i < (*this).row; i++)
            {
                for (size_t j = 0; j < (*this).col; j++)
                {
                    (*this).mat[i][j] -= 1;
                }
            }
            return *this;
        }



        Matrix Matrix::operator*(Matrix &a){
            // if((*this).row != a.row || (*this).col != a.col){
            //         throw("Iligiel of size matrtix");
            //     }
            if((*this).col != a.row){
                    throw("Iligiel of size matrtix");
                }
            Matrix m = Matrix();
            for (size_t i = 0; i < a.row; i++)
            {
                for (size_t j = 0; j < a.col; j++)
                {
                    m.mat[i][j] = (*this).mat[i][j] * a.mat[i][j];
                }
            }
            return m;
        }
        // Matrix operator*(double scalr, Matrix mat){
        //     return Matrix();
        // }
        Matrix Matrix::operator*=(Matrix &a){
            // if((*this).row != a.row || (*this).col != a.col){
            //         throw("Iligiel of size matrtix");
            //     }
            if((*this).col != a.row){
                    throw("Iligiel of size matrtix");
                }
            for (size_t i = 0; i < a.row; i++)
            {
                for (size_t j = 0; j < a.col; j++)
                {
                   (*this).mat[i][j] *= a.mat[i][j];
                }
            }
            return (*this);
        }
        Matrix Matrix::operator*=(double scalr){
            
            for (size_t i = 0; i < (*this).row; i++)
            {
                for (size_t j = 0; j < (*this).col; j++)
                {
                   (*this).mat[i][j] *= scalr;
                }
            }
            return (*this);
        }
        // ostream& operator<<(ostream& ostream, Matrix m){
        //     ostream << &m;
            // ostream << ;
        //     return ostream;
        // }
        // istream& operator>>(istream& in, Matrix m){
            // in >> &m;
            // cin>&m;
        //     return in;
        // }
        // string Matrix::print_mat(Matrix &a){
        //     string s;
        //     for (size_t i = 0; i < a.row; i++)
        //     {
        //         for (size_t j = 0; j < a.col; j++)
        //         {
        //             // cout<<"a[i][j]"<<a.mat[i][j]<<endl;
        //             s+=a.mat[i][j];
        //         }
        //     }
        //     return s;
        // }

// int main(){

    // for (double i = 0; i < 10; i++)
    // {
        // vector<double> vec1 = {i*random,i*random,i*random,i*random,i*random,i*random,i*random,i*random,i*random};
        // Matrix matrix(vec1, 3, 3);
        // CHECK(((matrix*mat_identity_3) == matrix));

        // vector<double> arr1 = {i,i,i,i,i,i,i,i,i};//3x3
        // vector<double> arr2 = {i,i,i,i,i,i,i,i,i};//3x3
    // vector<double> identity_3 = {1,0,0,0,1,0,0,0,1};//3x3
    // vector<double> vec1 = {1,1,1,1,1,1,1,1,1};//3x3
    // vector<double> vec_vec = {1,0,0,0,1,0,0,0,1};//3x3
    // vector<double> arr = {2,1,1,1,2,1,1,1,2};//3x3   arr = identity_3 + vec1
    // Matrix mat1(identity_3,3,3);
    // Matrix mat_arr(arr,3,3);
    // Matrix mat_vec(vec1,3,3);
    // Matrix mat_vec_vec(vec_vec,3,3);
    // int scalr = 5;
    // cout<<"324";
    // cout<<(mat1+=mat_vec)<<endl;
    // cout<<mat1<<endl;
    // cout<<mat_vec<<endl; 
    // cout<<"************************************"<<endl;
    // cout<<(mat_vec+=scalr)<<endl;
    // // cout<<mat1<<endl;
    // cout<<mat_vec<<endl;
    // cout<<mat_vec<<endl;
    // cout<<mat1<<endl;
    // cout<<mat_arr<<endl;
    // cout<<"************************************"<<endl;
    // cout<<(mat_arr*=scalr)<<endl;
    // cout<<(++mat_arrmat1)<<endl;
    // cout<<(mat1<mat_vec)<<endl;
    // cout<<(mat1<=mat_vec)<<endl;
    // cout<<(mat1==mat_vec_vec)<<endl;
    // cout<<(mat1!=mat_vec_vec)<<endl;
    // cout<<mat_vec<<endl;
    // cout<<mat1<<endl;
    // cout<<"************************************"<<endl;
    // cout<<(mat1-mat_vec)<<endl;
    // cout<<mat_arr<<endl;
    // cout<<mat_vec<<endl; 
    // cout<<"************************************"<<endl;

    // cout<<(-mat1)<<endl;
    // cout<<mat1<<endl;
    // cout<<mat_vec<<endl; 
    // cout<<"************************************"<<endl;
        // vector<double> arr = {pow(i,2),pow(i,2),pow(i,2),pow(i,2),pow(i,2),pow(i,2),pow(i,2),pow(i,2),pow(i,2)};//3x3
        // Matrix mat1(arr1, 3, 3);
        // Matrix mat2(arr1, 3, 3);
        // Matrix mat(arr, 3, 3);
        // cout<<"309";
        // cout<<Matrix::print_mat(mat1)<<endl;
        // cout<<"row"<<mat1.getrow()<<endl;
        // cout<<"col"<<mat1.getcol()<<endl;
        // for (int i = 0; i < mat.getrow(); i++)
        //     {
        //         cout<<"314"<<endl;
        //         for (int j = 0; j < mat.getcol(); j++)
        //         {
        //             cout<<"mat[i][j]"<<mat.getmat()[i][j]<<endl;
        //             cout<<"****************************************************************"<<endl;
        //             cout<<"m[i][j]"<<mat1.getmat()[i][j]*mat2.getmat()[i][j]<<endl;
        //         }
                
        //     }
    // }
//     return 0;
// }