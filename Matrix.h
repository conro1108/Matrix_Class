#ifndef m_test
#define m_test
#include"Row.h"
#include<vector>
#include<string>

class Matrix{
public:
    Matrix(int row, int col, std::string title);
    Matrix(std::string title);
    Matrix(int row, int col);
    Matrix();
    vector<Row*> matrix;

    void initializeMatrix();
    void getRowColInput();
    void populateMatrix();
    void print();

    bool operator==(const Matrix&) const;
    bool operator!=(const Matrix&) const;
    Matrix operator+(const Matrix&) const;
    Matrix operator-(const Matrix&) const;
    Matrix operator*(const Matrix&) const; //matrix multiplication
    Matrix operator*(const double&) const; //scalar multiplication

    const Matrix& operator=(const Matrix&);


private:
    std::string name;
    int numRows, numCols;
};
#endif