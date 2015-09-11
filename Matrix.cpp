#include<iostream>
#include<iomanip>
#include"Matrix.h"
using namespace std;

Matrix::Matrix(int row, int col, std::string title){
	numRows = row;
	numCols = col;
	name = title;

	populateMatrix();
}

Matrix::Matrix(std::string title){
	name = title;
	getRowColInput();
	populateMatrix();
}

void Matrix::populateMatrix(){
	for (int row = 0; row < numRows; row++){
		matrix.push_back(new Row(numCols));
		for (int col = 0; col < numCols; col++){
			double entryTemp;
			cout << "Entry for row " << row+1 << ", column " << col+1 << ": ";
			cin >> entryTemp;
			matrix[row]->container[col] = entryTemp;
		}
	}
}

void Matrix::getRowColInput(){
	cout << "Matrix " << name << ":" << endl;
	cout << "Enter number of rows: ";
	cin >> numRows;
	cout << "Enter number of columns: ";
	cin >> numCols;
}

void Matrix::print(){
	for (int row = 0; row < numRows; row++){
		cout << "[";
		for (int col = 0; col < numCols; col++){
			cout << setw(8) << right << matrix[row]->container[col];
		}
		cout << " ]" << endl;
	}
}