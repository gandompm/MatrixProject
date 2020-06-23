#pragma once


class Matrix
{
private: 
	// how to have an array with undefined size!! 
	double ** data;
	int row;
	int col;
	void setRowCol(int, int);

	
public: 
	Matrix(int,int);
	Matrix(double**,int,int);
	Matrix(Matrix&); // copy constructor 
	Matrix(Matrix&&) noexcept; // move constructor 
	void printData(); 
	Matrix* operator +(Matrix &);
	Matrix* operator -(Matrix &);
	Matrix* operator *(Matrix &);
	void operator = (Matrix *);
	void operator = (Matrix &&) noexcept;
	void operator +=(Matrix &);
	void operator -=(Matrix &);
	void operator *=(Matrix &);
	bool operator ==(Matrix &);
	bool operator !=(Matrix &);
	int getRow();
	int getCol();
	~Matrix();
};


