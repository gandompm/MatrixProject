#include "Matrix.h"
#include <cassert> 
#include <iostream>
using namespace std;


Matrix::Matrix(double* array, int row, int col) {

	cout << "constructor is being called" << endl;
	setRowCol(row, col);
	int counter = 0;
	data = new double[static_cast<int64_t>(row) * static_cast<int64_t>(col)];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			data[counter] = *(array + counter);
			counter ++;
		}
	}
}


Matrix::Matrix(int row, int col) {

	cout << "constructor 2 is being called" << endl;
	setRowCol(row, col);
	int counter = 0;
	data = new double[int64_t(row * col)];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			data[counter++] = 0;
		}
	}
}

Matrix::Matrix(Matrix & newMatrix) {
	cout << "copy constructor is being called" << endl;
	setRowCol(newMatrix.row, newMatrix.col);
	int counter = 0;
	data = new double[int64_t(newMatrix.row * newMatrix.col)];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			data[counter] = newMatrix.data[counter];
			counter++;
		}
	}
}

Matrix::Matrix(Matrix&& matrix) noexcept {

	cout << "move constructor is being called" << endl;
	this->row = std::move(matrix.row);
	this->col = std::move(matrix.col);
	int counter = 0;
	this->data = matrix.data;
	matrix.data = nullptr;
}


void Matrix::setRowCol(int r, int c) {
	row = r;
	col = c;
}


void Matrix::printData() {
	int counter = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << this->data[counter++] << ' ';
		}
		cout << endl;
	}
}


Matrix* Matrix::operator+(const Matrix& m2) const{

	assert(this->row == m2.row && this->col == m2.col);
	int counter = 0;
	Matrix* m3 = new Matrix(row, m2.col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			m3->data[counter] = this->data[counter] + m2.data[counter];
			counter++;
		}
	}

	return m3;
}


Matrix* Matrix::operator-(const Matrix& m2) const{

	assert(this->row == m2.row && this->col == m2.col);
	int counter = 0;
	Matrix* m3 = new Matrix(row, m2.col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			m3->data[counter] = this->data[counter] - m2.data[counter];
			counter++;
		}
	}
	return m3;
}


Matrix* Matrix::operator*(const Matrix& m2) const{

	assert(this->col == m2.row);
	Matrix* m3 = new Matrix(row, m2.col);
	int counter = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < m2.col; j++)
		{
			for (int k = 0; k < col; k++)
			{
				m3->data[counter] += (this->data[i * col + k] * m2.data[k * m2.col + j]);
			}
			counter++;
		}
	}

	return m3;
}


void Matrix::operator=(const Matrix* m2) {
	setRowCol(m2->row, m2->col);
	int counter = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			this->data[counter] = m2->data[counter];
			counter++;
		}
	}
}


void Matrix::operator=(Matrix&& m2) noexcept {

	this->row = std::move(m2.row);
	this->col = std::move(m2.col);
	
	this->data = m2.data;
	m2.data = nullptr;
}




void Matrix::operator+=(const Matrix& m2){

	*this = *this + m2;
}


void Matrix::operator-=(const Matrix& m2) {

	*this = *this - m2;
}


void Matrix::operator*=(const Matrix& m2) {

	*this = *this * m2;
}


bool Matrix::operator==(const Matrix& m2) const{

	int counter = 0;
	if (this->row == m2.row && this->col == m2.col)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (this->data[counter] != m2.data[counter])
				{
					return false;
				}
				else
					return true;
				counter++;
			}
		}
	}
	else
		return false;
}


bool Matrix::operator!=(const Matrix& m2) const{

	int counter = 0;
	if (this->row == m2.row && this->col == m2.col)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (this->data[counter] != m2.data[counter])
				{
					return true;
				}
				else
					return false;
				counter++;
			}
		}
	}
	else
		return true;
}


int Matrix::getRow() {
	return row;
}


int Matrix::getCol() {
	return col;
}

Matrix::~Matrix() {

	cout << "destructor is being called" << endl;
	if (data != nullptr)
	{
		delete data;
		data = nullptr;
	}
}