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
                throw("Iligiel of size of row or col OR the size of the vector not equal to the row and col");
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
                throw("Iligiel of size matrix");
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
        //return new matrix with the same value of this matrix
        Matrix Matrix::operator+(){
            Matrix m = Matrix(*this);
            return m;
        }

        Matrix Matrix::operator+=(const Matrix &matrix){
            if(matrix.row != this->row || matrix.col != this->col){
                throw("Iligiel of size matrix");
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

        //return new matrix with multiplication every index with minus one
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
                    throw("Iligiel of size matrix");
                }
                for (size_t i = 0; i < this->row; i++){
                    for (size_t j = 0; j < this->col; j++)
                    {
                        this->mat[i][j] -= matrix.mat[i][j];
                    }
                }
                return (*this);
        }

        //check if every index on the two matrices is the same value return false if not else true
        bool Matrix::compare_equal(const Matrix &matrix1,const Matrix &matrix2){

            if(matrix1.row != matrix2.row || matrix1.col != matrix2.col){
                throw("Iligiel of size matrix");
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
        //check if this matrix equal to the another matrix in the amount and the size if equal operator return true else false
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
                    throw("Iligiel of size matrix");
                }
            Matrix m = Matrix(this->row, matrix.col);
        
            for (size_t i = 0; i < (*this).row; i++)
            {
                for (size_t j = 0; j < matrix.col; j++)
                {
                    m.mat[i][j] = 0;
                    
                    for(size_t k=0; k<matrix.row; k++){
                    m.mat[i][j] += (this->mat[i][k] * matrix.mat[k][j]);
                    }
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
                    throw invalid_argument("Iligiel of size matrix");
                }
            Matrix m = Matrix(this->row, matrix.col);
        
            for (size_t i = 0; i < this->row; i++)
            {
                for (size_t j = 0; j < matrix.col; j++)
                {
                    for(size_t k=0; k<matrix.row; k++){
                        m.mat[i][j] += (this->mat[i][k] * matrix.mat[k][j]);
                    }
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
        //count the num of col in the matrix
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
        //operator get the input and put him in a matrix
        istream& operator>>(istream& in,  Matrix &mat){
        cout<<"365"<<endl;
        int row =0;
        string get_row;
        int mat_size = 0;
        bool ans = false;
        vector<double> v;
        
        while(getline(in, get_row, ',')){
            cout<<"370"<<endl;
            if(mat_size == get_row.size() && ans){
                cout<<"372"<<endl;
                throw("not valid input");
            }
            // cout<<"peek "<<in.peek()<<endl;
            // if (get_row[0] == '\n')
            // {
            //     break;
            // }
            
            string c;
            for (size_t i = 0; i < get_row.size(); i++)
            {
                cout<<"378"<<endl;
                cout<<"get_row: "<<get_row[i]<<endl;
                cout<<"size "<<get_row.size()<<endl;
                if(get_row[i] != '[' && get_row[i] != ']' && get_row[i] != ' ' && get_row[i] != '\n' && get_row[i] != ','){
                    c = get_row[i];
                    double d = stod(c);
                    v.push_back(d);
                    cout<<"383"<<endl;
                }
            }
            cout<<"388"<<endl;
            row++;
            mat_size = get_row.size();
            ans = true;
        }
        cout<<"398"<<endl;
        int col = num_of_col(get_row);
        
        mat = Matrix(v, row, col);
        return in;
    }
};