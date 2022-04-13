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

        public:
        
        Matrix();
        Matrix(int row, int col);
        Matrix(const vector<double> &mat, int row, int col);
        Matrix operator+(const Matrix &matrix);
        Matrix operator+();
        Matrix operator+=(const Matrix &matrix);
        Matrix operator-(const Matrix &matrix);
        Matrix operator-();
        Matrix operator-=(const Matrix &matrix);
        bool operator>(const Matrix &matrix) const;
        bool operator>=(const Matrix &matrix) const;
        bool operator<(const Matrix &matrix) const;
        bool operator<=(const Matrix &matrix) const;
        bool operator!=(const Matrix &matrix) const;

        Matrix operator++ ();
        Matrix operator++ (int n);
        Matrix operator-- ();
        Matrix operator-- (int n);

        Matrix operator*(const Matrix &matrix);
        Matrix operator*=(const Matrix &matrix);
        Matrix operator*=(double scalr);

        bool static compare_equal(const Matrix &matrix1,const Matrix &matrix2);
        double static amount(const Matrix &matrix);
        friend bool operator==(const Matrix &matrix, const Matrix &matrix2);
        friend Matrix operator*(double scalr,Matrix &matrix);
        friend Matrix operator*(Matrix &matrix, double scalr);
        friend std::ostream& operator<<(ostream& os,const Matrix &m);
        friend std::istream& operator>>(istream& in, Matrix& m);
        int num_of_col(string str);
    };
}