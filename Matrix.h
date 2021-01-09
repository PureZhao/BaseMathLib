#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
public:
	Matrix();
	Matrix(Matrix& m);
	Matrix(int row, int column);
	Matrix(int row, int column, double value);
	double GetItem(int row, int column);
	double GetItem(int position[2]);
	bool SetItem(int row, int column,double value);
	bool SetItem(int position[2], double value);
	int GetRowCount();
	int GetColumnCount();
	void RowMultiply(int row, double time);
	void ColumnMultiply(int column, double time);
	Matrix Inverse();
	double CalcDeterminant();
	int Rank();
	void SetToZeroMatrix();
	void Transpose();
	void SwapRows(int row1, int row2);
	void SwapColumns(int column1, int column2);
	void Reshape(int row, int column, double value = 0);
	void Reshape(Matrix& m);
	~Matrix();
	Matrix operator*(double time);
private:
	double** r;
	int rowCount, columnCount;
};
Matrix operator*(Matrix& ma, Matrix& mb);
Matrix operator+(Matrix& ma, Matrix& mb);
Matrix operator-(Matrix& ma, Matrix& mb);

#endif

