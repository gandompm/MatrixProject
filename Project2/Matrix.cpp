/*


#include "Matrix.h"
#include <cassert>
#include <iostream>
using namespace std;

template <typename T>
Matrix<T>::Matrix(T* arra, int row, int col) {

	cout << "constructor is being called" << endl;
	setRowCol(row, col);
	data = arra;
}


template <typename T>
Matrix<T>::Matrix(int row, int col) {

	cout << "constructor 2 is being called" << endl;
	setRowCol(row, col);
	int counter = 0;
	data = new T[(row * col)];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			data[counter++] = 0;
			// memset
		}
	}
}

template <typename T>
Matrix<T>::Matrix(Matrix & ma) {
	cout << "copy constructor is being called" << endl;
	*this = &ma;
}

template <typename T>
Matrix<T>::Matrix(Matrix && matrix) noexcept {

	cout << "move constructor is being called" << endl;
	this->row = std::move(matrix.row);
	this->col = std::move(matrix.col);
	int counter = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			this->data[counter] = std::move(matrix.data[counter]);
		}
	}
}

 template <typename T>
 void Matrix<T>::setRowCol(int r, int c) {
	row = r;
	col = c;
}


 template <typename T>
 void Matrix<T>::printData() {
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

 template <typename T>
Matrix<T>* Matrix<T>::operator+(Matrix& m2) {

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

template <typename T>
Matrix<T>* Matrix<T>::operator-(Matrix& m2) {

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
	return this;
}


template <typename T>
Matrix<T>* Matrix<T>::operator*(Matrix& m2) {

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
	// we retrun the address of a local variable! does that make sence?
	// at the end of the scope it will be destroyed!
	return m3;
}


template <typename T>
void Matrix<T>::operator=(Matrix* m2) {
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

template <typename T>
void Matrix<T>::operator=(Matrix&& m2) noexcept {

	this->row = std::move(m2.row);
	this->col = std::move(m2.col);
	int counter = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			this->data[counter] = std::move(m2.data[counter]);
			counter++;
		}
	}
}



template <typename T>
void Matrix<T>::operator+=(Matrix& m2) {

	*this = *this + m2;
}

template <typename T>
void Matrix<T>::operator-=(Matrix& m2) {

	*this = *this - m2;
}

template <typename T>
void Matrix<T>::operator*=(Matrix& m2) {

	*this = *this * m2;
}

template <typename T>
bool Matrix<T>::operator==(Matrix& m2) {

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


template <typename T>
bool Matrix<T>::operator!=(Matrix& m2) {

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


template <typename T>
int Matrix<T>::getRow() {
	return row;
}

template <typename T>
int Matrix<T>::getCol() {
	return col;
}

template <typename T>
 Matrix<T>::~Matrix() {
	cout << "destructor is being called" << endl;
}
*/

