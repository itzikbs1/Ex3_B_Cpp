#include <iostream>
#include <stdlib.h>
#include <string>
#include "Matrix.hpp"
#include "cmath"
using namespace std;
namespace zich{


        Matrix::Matrix(){
            // this->mat = vector<vector<double>> mat;
            this->col = 0;
            this->row = 0;
        }
        Matrix::Matrix(int row, int col){
            this->col = col;
            this->row = row;

            for (size_t i = 0; i < row; i++)
            {
                vector<double> vec;
                for (size_t j = 0; j < col; j++)
                {
                    vec.push_back(0);
                }
                this->mat.push_back(vec);
            }
            
        }
        //constructor for the Matrix check if row or col less then zero
        Matrix::Matrix(const vector<double> &m, int row, int col){
            if(row<0 || col<0 || m.size() != row*col){
                // cout<<"m.size"<<m.size()<<endl;
                // cout<<"33"<<endl;
                throw("Iligiel of size of row or col ");
            }
            size_t x=0;
            for(int i=0; i<row; i++){
                vector<double> vec;
                for(int j=0; j<col; j++){
                    vec.push_back(m[x]);
                    x++;
                }
                this->mat.push_back(vec);
            }
            this->row = row;
            this->col = col;
        }
        //check if the row differents or the col differents throw exception
        //return new matrix of operator+ of the two matrices
        Matrix Matrix::operator+(const Matrix &matrix){
            if(matrix.row != this->row || matrix.col != this->col){
                throw("Iligiel of size matrtix");
            }
            Matrix m = Matrix(matrix);
            for (size_t i = 0; i < this->row; i++){
                for (size_t j = 0; j < this->col; j++)
                {
                    m.mat[i][j] = matrix.mat[i][j] + this->mat[i][j];
                }
            }
            return m;
            }

        Matrix Matrix::operator+(double scalr){
            Matrix m = Matrix(*this);
            for (size_t i = 0; i < this->getrow(); i++)
            {
                for (size_t j = 0; j < this->getcol(); j++)
                {
                    m.mat[i][j]+= scalr;
                }
            }
            return m;
        }

        //return new matrix with the same value of this matrix
        Matrix Matrix::operator+(){
            Matrix m = Matrix(*this);
            // for (size_t i = 0; i < this->getrow(); i++)
            // {
            //     for (size_t j = 0; j < this->getcol(); j++)
            //     {
            //         m.mat[i][j] *= 1;
            // }
            // }
            return m;
        }

        Matrix Matrix::operator+=(const Matrix &matrix){
            if(matrix.row != this->row || matrix.col != this->col){
                throw("Iligiel of size matrtix");
            }
            for (size_t i = 0; i < this->row; i++)
            {
                for (size_t j = 0; j < this->col; j++)
                {
                    this->mat[i][j] += matrix.mat[i][j];
                }
            }
            return (*this);
        }

        //return this matrix with += scalr to every index
        Matrix Matrix::operator+=(double scalr){
            
            for (size_t i = 0; i < this->row; i++)
            {
                for (size_t j = 0; j < this->col; j++)
                {
                    this->mat[i][j] += scalr;
                }
            }
            return (*this);
        }

        //check if the row differents or the col differents throw exception
        //return new matrix of operator- of the two matrices
        Matrix Matrix::operator-(const Matrix &matrix){
            Matrix m = Matrix((*this));
                if(matrix.row != this->row || matrix.col != this->col){
                    throw("Iligiel of size matrtix");
                }
                for (size_t i = 0; i < this->row; i++){
                    for (size_t j = 0; j < this->col; j++)
                    {
                        m.mat[i][j] -= matrix.mat[i][j];
                    }
                }
                return m;
        }

       Matrix Matrix::operator-(double scalr){
            Matrix m = Matrix((*this));
               
                for (size_t i = 0; i < this->row; i++)
                {
                    for (size_t j = 0; j < this->col; j++)
                    {
                        m.mat[i][j] -= scalr;
                    }
                }
                return m;
        }
        //return new matrix with multu.. every index with minus one
        Matrix Matrix::operator-(){//return new one
            Matrix m = Matrix(*this);
            int minus_one = -1;
            for (size_t i = 0; i < this->row; i++){
                    for (size_t j = 0; j < this->col; j++)
                    {
                        if(m.mat[i][j] != 0){
                        m.mat[i][j] *= minus_one;
                    }
                    }
                }
                return m;
        }
        Matrix Matrix::operator-=(const Matrix &matrix){
                if(matrix.row != this->row || matrix.col != this->col){
                    throw("Iligiel of size matrtix");
                }
                for (size_t i = 0; i < this->row; i++){
                    for (size_t j = 0; j < this->col; j++)
                    {
                        this->mat[i][j] -= matrix.mat[i][j];
                    }
                }
                return (*this);
        }

        //return this matrix with += scalr to every index
        Matrix Matrix::operator-=(double scalr){
            
            for (size_t i = 0; i < this->row; i++){
                for (size_t j = 0; j < this->col; j++)
                {
                    this->mat[i][j] -= scalr;
            }
            }
            return (*this);
        }
        //check if every index on the two matrices is the same value return false if not else true
        bool Matrix::compare_equal(const Matrix &matrix1,const Matrix &matrix2){

            if(matrix1.row != matrix2.row || matrix1.col != matrix2.col){
                throw("Iligiel of size matrtix");
                }
            for (size_t i = 0; i < matrix1.row; i++)
            {
                for (size_t j = 0; j < matrix1.col; j++)
                {
                    if (matrix1.mat[i][j] != matrix2.mat[i][j])
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        //return amount of the matrix
        double Matrix::amount(const Matrix &m){
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
        //check if this matrix bigger(amount) from the matrix that the operator get return true if yes else false
        bool Matrix::operator>(const Matrix &matrix) const{
            if(matrix.row != this->row || matrix.col != this->col){
                throw("The Matrices with out with the same size!");
                }
                double sum_mat = Matrix::amount(*this);
                double sum_matrix = Matrix::amount(matrix);
                
                return sum_mat > sum_matrix;
        }
        //check if this matrix bigger or equal(amount) from the matrix that the operator get return true if yes else false
        bool Matrix::operator>=(const Matrix &matrix) const{
            if(matrix.row != this->row || matrix.col != this->col){
                throw("The Matrices with ouut  with the same size!");
                }
            double sum_mat = Matrix::amount(*this);
            double sum_matrix = Matrix::amount(matrix);
            
            return sum_mat >= sum_matrix;
        }
        //check if this matrix less(amount) from the matrix that the operator get return true if yes else false
        bool Matrix::operator<(const Matrix &matrix) const{
            if(matrix.row != this->row || matrix.col != this->col){
                throw("The Matrices with out with the same size!");
                }
            double sum_mat = Matrix::amount(*this);
            double sum_matrix = Matrix::amount(matrix);
            
            return sum_mat < sum_matrix;
        }
        //check if this matrix less or equal(amount) from the matrix that the operator get return true if yes else false
        bool Matrix::operator<=(const Matrix &matrix) const{
            if(matrix.row != this->row || matrix.col != this->col){
                throw("The Matrices with out with the same size!");
                }
            double sum_mat = Matrix::amount(*this);
            double sum_matrix = Matrix::amount(matrix);
            
            return sum_mat <= sum_matrix;
        }
        //check if the matrices the same one return true if yes else false
        // bool Matrix::operator==(const Matrix &matrix) const{
        //     if(matrix.row != this->row || matrix.col != this->col){
        //         throw("The Matrices with out with the same size!");
        //         }
        //     return Matrix::compare_equal(*this, matrix);
        // }
                //check if the matrices the same one return true if yes else false
        // bool zich::operator==(const Matrix &matrix,const Matrix &matrix2){
        //     if(matrix.row != matrix2.row || matrix.col != matrix2.col){
        //         throw("The Matrices with out with the same size!");
        //         }
        //     return Matrix::compare_equal(matrix, matrix2);
        // }
        bool operator==(const Matrix &matrix,const Matrix &matrix2){
            if(matrix.row != matrix2.row || matrix.col != matrix2.col){
                throw("The Matrices with out with the same size!");
                }
            return Matrix::compare_equal(matrix, matrix2);
        }
        //check if the matrices not the same one return true if yes else false
        bool Matrix::operator!=(const Matrix &matrix) const{
            if(matrix.row != this->row || matrix.col != this->col){
                throw("The Matrices with out with the same size!");
                }
            return !(Matrix::compare_equal(*this, matrix));
        }
        // Matrix Matrix::operator*(double scalr){
        //     return Matrix();
        // }
        //increase the values in the matrix in one and return before the increases
        Matrix Matrix::operator++(int n){
        Matrix m = Matrix(*this);
        for (size_t i = 0; i < m.row; i++)
            {
                for (size_t j = 0; j < m.col; j++)
                {
                    this->mat[i][j] += 1;
                }
            }
            return m;
        }
        //increase the values in the matrix in one and return after the increase
        Matrix Matrix::operator++(){
            for (size_t i = 0; i < this->row; i++)
            {
                for (size_t j = 0; j < this->col; j++)
                {
                    this->mat[i][j] += 1;
                }
            }
            return *this;
        }
        //decrease the values in the matrix in one and return before the decreases
        Matrix Matrix::operator--(int n){
            Matrix m = Matrix(*this);
            for (size_t i = 0; i < m.row; i++)
            {
                for (size_t j = 0; j < m.col; j++)
                {
                    this->mat[i][j] -= 1;
                }
            }
            return m;
        }
        //decreases the values in the matrix in one and after before the decreases
        Matrix Matrix::operator--(){
            for (size_t i = 0; i < this->row; i++)
            {
                for (size_t j = 0; j < this->col; j++)
                {
                    this->mat[i][j] -= 1;
                }
            }
            return *this;
        }


        //check if the col not equal to the row than throw exception else return new matrix with the multiplication between the two matrices
        Matrix Matrix::operator*(const Matrix& matrix){
            
            if(this->col != matrix.row){
                // cout<<"318"<<endl;
                    throw("Iligiel of size matrtix");
                }
            Matrix m = Matrix(this->row, matrix.col);// = Matrix(*this);
            // m.mat = this->mat;
            // m.row = this->row;
            // m.col = matrix.col;
        
            for (size_t i = 0; i < (*this).row; i++)
            {
                // double sum=0;
                for (size_t j = 0; j < matrix.col; j++)
                {
                    m.mat[i][j] = 0;
                    
                    for(size_t k=0; k<matrix.row; k++){
                    m.mat[i][j] += (this->mat[i][k] * matrix.mat[k][j]);
                    }
                    // cout<<"m.mat[i][j]: "<<m.mat[i][j]<<endl;
                    // cout<<"i: "<<i<<endl;
                    // cout<<"j: "<<j<<endl;
                    
                    // m.mat[i][j] = sum;
                    // sum=0;
                }
            }
            return m;
        }
        //return new matrix with the multiplication between the matrix and scalr
        Matrix operator*(double scalr,Matrix &matrix){
            
            Matrix m = Matrix(matrix);
        
            for (size_t i = 0; i < matrix.row; i++)
            {
                for (size_t j = 0; j < matrix.col; j++)
                {
                    m.mat[i][j] *= scalr;
                }
            }
            return m;
        }
        //return new matrix with the multiplication between the matrix and scalr
        Matrix operator*(Matrix &matrix, double scalr){
            
            return scalr*matrix;
        }
        //check if the col not equal to the row than throw exception else return new matrix with the multiplication between the two matrices
        Matrix Matrix::operator*=(const Matrix &matrix){
            if(this->col != matrix.row){
                    throw invalid_argument("Iligiel of size matrtix");
                }
            // Matrix m = Matrix(*this);
            Matrix m = Matrix(this->row, matrix.col);
        
            for (size_t i = 0; i < this->row; i++)
            {
                // double sum=0;
                for (size_t j = 0; j < matrix.col; j++)
                {
                    for(size_t k=0; k<matrix.row; k++){
                    m.mat[i][j] += (this->mat[i][k] * matrix.mat[k][j]);
                    // this->mat[i][k] *= matrix.mat[k][j];
                    }
                    // this->mat[i][j] = sum;
                    // sum=0;
                }
            }
            *this = m;
            return *this;
        }
        //return the same matrix multiplication with scalr
        Matrix Matrix::operator*=(double scalr){
            
            for (size_t i = 0; i < this->row; i++)
            {
                for (size_t j = 0; j < this->col; j++)
                {
                    this->mat[i][j] *= scalr;
                }
            }
            return *this;
        }

        ostream& operator<<(ostream& os,const Matrix &m){
            for (size_t i = 0; i < m.row; i++)
            {
                os << "[";
                for (size_t j = 0; j < m.col; j++)
                {
                    os << m.mat[i][j];
                    if(j != m.col-1){
                    os << " ";
                    }
                }
                if(i != m.row-1){
                os << "]\n";
                }else{
                    os << "]";
                }
            }
            return os;
        }
      
        // istream& operator>>(istream& in, Matrix &m){

        //     string str;
        //     for (size_t i = 0; i < m.row; i++)
        //     {
        //         getline(in, str, ',');
        //         for (size_t j = 0; j < m.col; j++)
        //         {
        //             // in >> m.mat[i][j];
        //             in >> m.mat[i][j];
        //         // in >> m.mat[i][j];
        //         }
        //     }
        //     return in;
        // }
        // double convert_str_to_double(string str){
        //     double result;
        //     double d;
        //     for (size_t i = 0; i < str.size(); i++)
        //     {
        //         if(str[i] >= 48 && str[i] <= 57){
                    
        //             d = (str.size()-1-i)*(str[i] - 48);
        //         }
        //         result += d;
        //     }
        //     return result;
        // }
        int num_of_col(string str){
            int size=0;
            for (size_t i = 0; i < str.size(); i++)
            {
                if(str[i] != '[' && str[i] != ']' && str[i] != ' ' && str[i] != '\n' && str[i] != ','){
                    size++;
                }
            }
            return size;
        } 
        istream& operator>>(istream& in,  Matrix &mat){ // operator input >>
        
        int row =0;
        string getMat;
        // row=3;
    //    int row_temp = row;
        int mat_size;
        // vector<double> vec;
        bool ans = false;
        vector<double> v;
        // cout<<"486"<<endl;
        while(getline(in, getMat, ',')){
            // cout<<"488"<<endl;
            if(mat_size == getMat.size() && ans){
                throw("not valid input");
            }
            string c;
            for (size_t i = 0; i < getMat.size(); i++)
            {
                // cout<<"492"<<endl;
                if(getMat[i] != '[' && getMat[i] != ']' && getMat[i] != ' ' && getMat[i] != '\n' && getMat[i] != ','){
                    c = getMat[i];
                    double d = stod(c);
                    v.push_back(d);
                }
            }
            row++;
        }
        int col = num_of_col(getMat);
        mat_size = getMat.size();
        ans = true;
        // cout<<"502"<<endl;
        // cout<<"row: "<<row<<endl;
        // cout<<"col: "<<col<<endl;
        mat = Matrix(v, row, col);
        // cout<<"mat: "<<mat<<endl;
        return in;
    }
  
};

// // #include <iostream>
// // #include <stdlib.h>
// // #include <string>
// // #include "Matrix.hpp"
// // #include "cmath"
//   int main(){
//  vector<double> vector;
//     for (double i = 0; i < 100; ++i) {
//         vector.push_back(i);
//     }
//     /**
//      * Here we will check adding,substructing of 2 different shape matrix.
//      * we can add and substruct A and B if and only if the two matrix have same rows and cols size.
//      */
//     Matrix A{vector, 10, 10};
//     Matrix B{vector, 5, 20};
//     return 0;
//   }
// std::vector<double> arr1 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
// std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
// std::vector<double> arr_b = {3, 0, 0, 0, 3, 0, 0, 0, 3};
// std::vector<double> arr_c = {2, 0, 0, 0, 2, 0, 0, 0, 2};
// std::vector<double> arr_d= {4, 0, 0, 0, 4, 0, 0, 0, 4};
// std::vector<double> arr_e= {4, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 0};
// std::vector<double> arr_f= {5, 0, 0, 0, 5, 0, 0, 0, 5, 0, 0, 0};
// std::vector<double> arr_h= {9, 0, 0, 0, 9, 0, 0, 0, 9, 0, 0, 0};
//     Matrix mat1{identity,3,3};
//     Matrix mat2{arr_b,3,3};
//     Matrix mat3{arr_c,3,3};
//     Matrix mat4{arr_d,3,3};
//     Matrix mat5{arr_e,4,3};
//     Matrix mat6{arr_f,4,3};
//     mat1+=mat3;
//     // CHECK_EQ(mat2,mat1);
//     mat2+=mat1;
//     mat4+=mat3;
//     // CHECK_EQ(mat4,mat2);
//     mat1+=mat1;
//     // CHECK_EQ(mat1,mat2);
//     mat1+= mat3;
//     mat3+= mat2;
//     // CHECK_EQ(mat3,mat1);
//     mat5+=mat6;
//     return 0;
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

// // TEST_CASE ("ADD/SUB/MULTY") {
//     cout<<"10"<<endl;
//     vector<double> vector;
//     for (double i = 0; i < 100; ++i) {
//         vector.push_back(i);
//     }
//     cout<<"10"<<endl;
//     /**
//      * Here we will check adding,substructing of 2 different shape matrix.
//      * we can add and substruct A and B if and only if the two matrix have same rows and cols size.
//      */
//     // Matrix::Matrix A = Matrix(vector, 10, 10);
//     // Matrix A{vector, 10, 10};
//     // Matrix B{vector, 5, 20};
//     // CHECK_THROWS(A + B);
//     // CHECK_THROWS(B + A);
//     // CHECK_THROWS(A - B);
//     // CHECK_THROWS(B - A);
//     // CHECK_THROWS(A += B);
//     // CHECK_THROWS(B += A);
//     // CHECK_THROWS(A -= B);
//     // CHECK_THROWS(B -= A);
//     /**
//      * A and B can be multiply if and only if:
//      * A is n*m matrix
//      * B is m*k matrix
//      */
//     vector.clear();
//     for (double i = 0; i < 30; ++i) {
//         vector.push_back(i);
//     }
//     Matrix C{vector, 5, 6};
//     vector.clear();
//     for (double i = 0; i < 60; ++i) {
//         vector.push_back(i);
//     }
//     Matrix D{vector, 6, 10};
//     //A is 10*10
//     //B is 5*20
//     //C is 5*6
//     //D is 6*10
//     // only A*A, D*A and C*D are allowed
// //     CHECK_NOTHROW(A * A);
// //     CHECK_THROWS(A * B);
// //     CHECK_THROWS(A * C);
// //     CHECK_THROWS(A * D);
// //     CHECK_THROWS(B * A);
// //     CHECK_THROWS(B * B);
// //     CHECK_THROWS(B * C);
// //     CHECK_THROWS(B * D);
// //     CHECK_THROWS(C * A);
// //     CHECK_THROWS(C * B);
// //     CHECK_THROWS(C * C);
// //     CHECK_NOTHROW(C * D);
// //     CHECK_NOTHROW(D * A);
// //     CHECK_THROWS(D * B);
// //     CHECK_THROWS(D * C);
// //     CHECK_THROWS(D * D);
// //     CHECK_NOTHROW(A *= A);
// //     CHECK_THROWS(A *= B);
// //     CHECK_THROWS(A *= C);
// //     CHECK_THROWS(A *= D);
// //     CHECK_THROWS(B *= A);
// //     CHECK_THROWS(B *= B);
// //     CHECK_THROWS(B *= C);
// //     CHECK_THROWS(B *= D);
// //     CHECK_THROWS(C *= A);
// //     CHECK_THROWS(C *= B);
// //     CHECK_THROWS(C *= C);
// //     CHECK_NOTHROW(C *= D);
// //     CHECK_NOTHROW(D *= A);
// //     CHECK_THROWS(D *= B);
// //     CHECK_THROWS(D *= C);
// //     CHECK_THROWS(D *= D);
// // }
//     return 0;
// }