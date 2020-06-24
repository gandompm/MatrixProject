#pragma once


class Matrix
{
private: 
	// defining a pointer in order to store the address of an undifined array size  
	double * data;
	// number of row and column of the matrix
	int row;
	int col;
	// initializing the instance variables 
	void setRowCol(int, int);


public: 
	// constructor without any data 
	Matrix(int,int);
	Matrix(double*,int,int);
	// copy constructor 
	Matrix(Matrix&); 
	// move constructor inorder to take the advantage of move semantic 
	Matrix(Matrix&&) noexcept; 
	void printData(); 
	/*
	 overloading the plus operator 
	 it doesn't modify it's parameter, so it should be defined const
	 it doesn't modify any instance variable, so the function should be defined as const.
	 receive a Matrix object and return a pointer to a new object. 
	*/
	Matrix* operator +(const Matrix &) const;
	Matrix* operator -(const Matrix &) const;
	Matrix* operator *(const Matrix &) const;
	/*
	the function is of type void, because the new result will be assigned to the current object. 
	*/
	void operator = (const Matrix *);
	void operator = (Matrix &&) noexcept;
	void operator +=(const Matrix &);
	void operator -=(const Matrix &);
	void operator *=(const Matrix &);
	bool operator ==(const Matrix &) const;
	bool operator !=(const Matrix &) const;
	int getRow();
	int getCol();
	// reallocating the memory 
	~Matrix();
};


