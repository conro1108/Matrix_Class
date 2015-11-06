#include<iostream>
#include<iomanip>
#include"Matrix.h"
using namespace std;

//matrices with titles are intended for use in later calculator programs for matrices that are
//entered by user. constructors without titles are for internal use, and just initialize a properly
//sized matrix of zeroes, but does not prompt for values
Matrix::Matrix(int row, int col, std::string title){
	numRows = row;
	numCols = col;
	name = title;

	initializeMatrix();
	populateMatrix();
}

Matrix::Matrix(std::string title){
	name = title;
	getRowColInput();
	initializeMatrix();
	populateMatrix();
}

Matrix::Matrix(int row, int col){
	name = "NULL";
	numRows = row;
	numCols = col;
	initializeMatrix();
}

Matrix::Matrix(){
	name = "NULL";
	getRowColInput();
	initializeMatrix();
}

void Matrix::initializeMatrix(){
	for (int row = 0; row < numRows; row++){
		matrix.push_back(new Row(numCols));
	}
}

void Matrix::populateMatrix(){
	cout << "\nMatrix " << name << ":" << endl;
	for (int rowIndex = 0; rowIndex < numRows; rowIndex++){
		for (int colIndex = 0; colIndex < numCols; colIndex++){
			double entryTemp;
			cout << "Entry for row " << rowIndex+1 << ", column " << colIndex+1 << ": ";
			cin >> entryTemp;
			matrix[rowIndex]->row[colIndex] = entryTemp;
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
	for (int rowIndex = 0; rowIndex < numRows; rowIndex++){
		cout << "[";
		for (int colIndex = 0; colIndex < numCols; colIndex++){
			cout << setw(8) << right << matrix[rowIndex]->row[colIndex];
		}
		cout << " ]" << endl;
	}
}

bool Matrix::operator==(const Matrix& otherMatrix) const{
	bool returnValue = true;
	
	if (numRows != otherMatrix.numRows || numCols != otherMatrix.numCols){
		returnValue = false;
	}

	for (int rowIndex = 0; rowIndex < numRows; rowIndex++){
		for (int colIndex = 0; colIndex < numCols; colIndex++){
			if (matrix[rowIndex]->row[colIndex] != otherMatrix.matrix[rowIndex]
				->row[colIndex]){
				returnValue = false;
			}
		}
	}

	return returnValue;
}

bool Matrix::operator!=(const Matrix& otherMatrix) const{
	bool returnValue = false;

	if (numRows != otherMatrix.numRows || numCols != otherMatrix.numCols){
		returnValue = true;
	}

	for (int rowIndex = 0; rowIndex < numRows; rowIndex++){
		for (int colIndex = 0; colIndex < numCols; colIndex++){
			if (matrix[rowIndex]->row[colIndex] != otherMatrix.matrix[rowIndex]
				->row[colIndex]){
				returnValue = true;
			}
		}
	}

	return returnValue;
}

Matrix Matrix::operator+(const Matrix& otherMatrix) const{
	if (numRows != otherMatrix.numRows || numCols != otherMatrix.numCols){
		cout << "Cannot add matrices with different dimensions" << endl;
	}
	else{
		for (int rowIndex = 0; rowIndex < numRows; rowIndex++){
			for (int colIndex = 0; colIndex < numCols; colIndex++){
				matrix[rowIndex]->row[colIndex] += otherMatrix.matrix[rowIndex]
					->row[colIndex];
			}
		}
	}
	return *this;
}

Matrix Matrix::operator-(const Matrix& otherMatrix) const{
	if (numRows != otherMatrix.numRows || numCols != otherMatrix.numCols){
		cout << "Cannot subtract matrices with different dimensions" << endl;
	}
	else{
		for (int rowIndex = 0; rowIndex < numRows; rowIndex++){
			for (int colIndex = 0; colIndex < numCols; colIndex++){
				matrix[rowIndex]->row[colIndex] -= otherMatrix.matrix[rowIndex]
					->row[colIndex];
			}
		}
	}
	return *this;
}

Matrix Matrix::operator*(const Matrix& otherMatrix) const{
	double entryTemp = -1;
	

	if (numCols != otherMatrix.numRows){
		cout << "These matrices can not be multiplied - incompatible size" << endl;
		return *this;
	}

	else{ //matrices are correct sixe to multiply - [a x n] * [n x b], so we create an [a x b]
		  //matrix to store the result

		Matrix product(numRows, otherMatrix.numCols);

		//the rowIndex and colIndex for loops iterate through each entry in the product matrix
		for (int rowIndex = 0; rowIndex < product.numRows; rowIndex++){
			for (int colIndex = 0; colIndex < product.numCols; colIndex++){
				entryTemp = 0; 
				//productIndex loop iterates through the row vector of first mtx and column vector of
				//2nd mtx to calculate values of each product entry
				for (int productIndex = 0; productIndex < numCols; productIndex++)
				{
					entryTemp += (matrix[rowIndex]->row[productIndex] * 
						otherMatrix.matrix[productIndex]->row[colIndex]);
				}
				product.matrix[rowIndex]->row[colIndex] = entryTemp;
			}
		}
		return product;
	}
}

const Matrix& Matrix::operator=(const Matrix& otherMatrix){
	if (this != &otherMatrix){
		numRows = otherMatrix.numRows;
		numCols = otherMatrix.numCols;
		for (int rowIndex = 0; rowIndex < numRows; rowIndex++){
			for (int colIndex = 0; colIndex < numCols; colIndex++){
				matrix[rowIndex]->row[colIndex] = otherMatrix.matrix[rowIndex]->row[colIndex];
			}
		}
	}
	return *this;
}