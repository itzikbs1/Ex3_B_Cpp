#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>


using namespace std;
namespace zich{



class Matrix{

        private:
        vector<vector<double>> mat;
        int row;
        int col;

        // Matrix(){
        //     this->mat = {};
        //     this->row = 0;
        //     this->col = 0;
        // }
        // Matrix(std::vector<double> mat={}, int row=0, int col=0){Matrix::mat = mat, Matrix::row = row, Matrix::col = col;}

            // this->mat = mat;
            // this->row = row;
            // this->col = col;
        // }

        // Matrix(vector<double> mat={}, int row=0, int col=0){
        //     this->mat = mat;
        //     this->row = row;
        //     this->col = col;
        // }
        // Matrix(Matrix m){
        //     this->mat = m.mat;
        //     this->row = m.row;
        //     this->col = m.col;
        // }
        public:
        
        Matrix();
        // Matrix(Matrix &m);
        Matrix(vector<double> mat, int row, int col);
        Matrix(vector<vector<double>> mat, int row, int col);
        Matrix operator+(Matrix &a);
        Matrix operator+(double scalr);
        Matrix operator+();
        Matrix operator+=(Matrix &a);
        Matrix operator+=(double scalr);
        Matrix operator-(Matrix &a);
        Matrix operator-(double scalr);
        Matrix operator-();
        Matrix operator-=(Matrix &a);
        Matrix operator-=(double scalr);
        bool operator>(Matrix &a);
        bool operator>=(Matrix &a);
        bool operator<(Matrix &a);
        bool operator<=(Matrix &a);
        bool operator==(Matrix &a);
        bool operator!=(Matrix &a);

        Matrix operator++ ();
        Matrix operator++ (int n);
        Matrix operator-- ();
        Matrix operator-- (int n);

        Matrix operator*(Matrix &mat);
        Matrix operator*=(Matrix &mat);
        Matrix operator*=(double scalr);

        bool compare_equal(Matrix &a, Matrix &b);
        double amount(Matrix &m);

        friend Matrix operator*(double scalr, Matrix& mat);
        friend std::ostream& operator<<(ostream& os,const Matrix &m);
        friend std::istream& operator>>(istream& in, const Matrix& m);
        friend std::ostream& operator<<(ostream& os,const Matrix &m){
            for (size_t i = 0; i < m.row; i++)
            {
                os << "[";
                for (size_t j = 0; j < m.col; j++)
                {
                    // cout<<"a[i][j]"<<a.mat[i][j]<<endl;
                    os << m.mat[i][j];
                    if(j != m.col-1){
                    os << " ";
                    }
                }
                os << "]\n";
            }
            return os;
        }
        friend std::istream& operator>>(istream& in, const Matrix& m){
            return in;
        }
        friend Matrix operator*(double scalr, Matrix& mat){
          return Matrix();
        }
        string print_mat(Matrix &a);
        // friend Matrix operator*(double scalr, Matrix& mat){

            // Matrix m;
            // for (size_t i = 0; i < mat.row; i++)
            // {
            //     for (size_t j = 0; j < mat.col; j++)
            //     {
            //         m.mat[i][j] = mat.mat[i][j] * scalr;
            //     }
            // }
        //     return Matrix();
        // }
        int getrow(){
            return row;
        }
        int getcol(){
            return col;
        }
        vector<vector<double>> getmat(){
            return mat;
        }
    };
}