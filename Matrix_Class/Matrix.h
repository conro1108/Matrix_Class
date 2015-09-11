#ifndef m_test
#define m_test
#include"Row.h"
#include<vector>
#include<string>

class Matrix{
public:
	Matrix(int row, int col, std::string title);
	Matrix(std::string title);
	Matrix();
	vector<Row*> matrix;

	void getRowColInput();
	void populateMatrix();
	void print();
private:
	std::string name;
	int numRows, numCols;
};
#endif