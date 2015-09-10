#ifndef m_test
#define m_test
#include"Row.h"
#include<vector>
#include<string>
class Matrix{
public:
	Matrix(int row, int col, std::string title);
	Matrix(std::string title);
	vector<Row*> matrix;
	void getRowColInput();

private:
	int numRows, numCols;
}
#endif