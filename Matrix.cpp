#include "Matrix.h"
Matrix::Matrix() {
	rowCount = 1, columnCount = 1;
	r = new double*[1];
	for (int i = 0; i < rowCount; i++)
	{
		r[i] = new double[columnCount];
	}
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < columnCount; j++)
		{
			r[i][j] = 0;
		}
	}
}
Matrix::Matrix(Matrix& m) {
	rowCount = m.GetRowCount();
	columnCount = m.GetColumnCount();
	r = new double*[rowCount];
	for (int i = 0; i < rowCount; i++)
	{
		r[i] = new double[columnCount];
	}
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < columnCount; j++)
		{
			r[i][j] = m.GetItem(i, j);
		}
	}
}
Matrix::Matrix(int row, int column) {
	if (row < 0 || column < 0) { row = column = 1; }
	rowCount = row, columnCount = column;
	r = new double*[rowCount];
	for (int i = 0; i < rowCount; i++)
	{
		r[i] = new double[columnCount];
	}
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < columnCount; j++)
		{
			r[i][j] = 0;
		}
	}
}
Matrix::Matrix(int row, int column, double value) {
	if (row < 0 || column < 0) { row = column = 1; }
	rowCount = row, columnCount = column;
	r = new double*[rowCount];
	for (int i = 0; i < rowCount; i++)
	{
		r[i] = new double[columnCount];
	}
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < columnCount; j++)
		{
			r[i][j] =value;
		}
	}
}
double Matrix::GetItem(int row, int column) {
	if (row >= rowCount || column >= columnCount) return -1;
	if (row < 0 || column < 0) return -1;
	return r[row][column];
}
double Matrix::GetItem(int position[2]) {
	if (position[0] >= rowCount || position[1] >= columnCount) return -1;
	if (position[0] < 0 || position[1] < 0) return -1;
	return r[position[0]][position[1]];
}
bool Matrix::SetItem(int row, int column, double value) {
	if (row >= rowCount || column >= columnCount) return false;
	if (row < 0 || column < 0) return false;
	r[row][column] = value;
	return true;
}
bool Matrix::SetItem(int position[2], double value) {
	if (position[0] >= rowCount || position[1] >= columnCount) return false;
	if (position[0] < 0 || position[1] < 0) return false;
	r[position[0]][position[1]] = value;
	return true;
}
int Matrix::GetRowCount() { return rowCount; }
int Matrix::GetColumnCount() { return columnCount; }
void Matrix::RowMultiply(int row, double time) {
	if (row < 0 || row >= rowCount) return;
	for (int i = 0; i < columnCount; i++)
	{
		r[row][i] *= time;
	}
}
void Matrix::ColumnMultiply(int column, double time) {
	if (column < 0 || column >= columnCount) return;
	for (int i = 0; i < rowCount; i++)
	{
		r[i][column] *= time;
	}
}
double Matrix::CalcDeterminant() {
	if (rowCount != columnCount) return -2147483648.0;
	if (rowCount == 1) return GetItem(0, 0);
	if (rowCount == 2) return GetItem(0, 0) * GetItem(1, 1) - GetItem(0, 1) * GetItem(1, 0);
	Matrix temp(rowCount,columnCount);
	double res = 1.0;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < columnCount; j++)
		{
			temp.SetItem(i, j, r[i][j]);
		}
	}
	while (true)
	{
		if (temp.GetRowCount() == 2) {
			res *= (temp.GetItem(0, 0) * temp.GetItem(1, 1) - temp.GetItem(0, 1) * temp.GetItem(1, 0));
			break;
		}
		//找到第一列第一个不为0的数，这个数不变
		int row = 0;
		while (row < temp.GetRowCount() && temp.GetItem(row, 0) == 0) row++;
		if (row == temp.GetRowCount()) { res *= 0; break; }
		//计算到结果中去
		res *= temp.GetItem(row, 0);
		res *= (row % 2 == 0 ? 1 : -1);
		//把该列除了选中的这个数全部置0
		for (int i = 0; i < temp.GetRowCount(); i++)
		{
			if(i == row || temp.GetItem(i, 0) == 0) continue;
			double coefficience = temp.GetItem(i, 0) / temp.GetItem(row, 0);
			for (int j = 1; j < columnCount; j++)
			{
				double val = temp.GetItem(i, j) - coefficience * temp.GetItem(row, j);
				temp.SetItem(i, j, val);
			}
			temp.SetItem(i, 0, 0);
		}
		Matrix p(temp.GetRowCount() - 1, temp.GetRowCount() - 1);
		for (int i = 0; i < p.GetRowCount(); i++)
		{
			for (int j = 0; j < p.GetColumnCount(); j++)
			{
				p.SetItem(i, j, temp.GetItem(i + 1, j + 1));
			}
		}
		temp.Reshape(p);
		
	}
	return res;
}
int Matrix::Rank() {
	if (rowCount == 1 || columnCount == 1) return 1;
	Matrix temp(rowCount, columnCount);
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < columnCount; j++)
		{
			temp.SetItem(i, j, r[i][j]);
		}
	}
	int rank = 0;
	while (true)
	{
		if (temp.GetRowCount() == 1) {
			bool isAllZero = true;
			for (int i = 0; i < temp.GetColumnCount(); i++)
			{
				if (temp.GetItem(0, i) != 0) {
					isAllZero = false;
					break;
				}
			}
			rank += (isAllZero ? 0 : 1);
			break;
		}
		if (temp.GetColumnCount() == 1) {
			bool isAllZero = true;
			for (int i = 0; i < temp.GetRowCount(); i++)
			{
				if (temp.GetItem(i, 0) != 0) {
					isAllZero = false;
					break;
				}
			}
			rank += (isAllZero ? 0 : 1);
			break;
		}
		//找到第一列第一个不为0的数，这个数不变
		int row = 0;
		while (row < temp.GetRowCount() && temp.GetItem(row, 0) == 0) row++;
		//如果这一列全为0,则只需要计算剩下的列的秩
		if (row == temp.GetRowCount()) {
			Matrix p(temp.GetRowCount(), temp.GetColumnCount() - 1);
			for (int i = 0; i < p.GetRowCount(); i++)
			{
				for (int j = 0; j < p.GetColumnCount(); j++)
				{
					p.SetItem(i, j, temp.GetItem(i, j + 1));
				}
			}
			temp.Reshape(p);
			continue;
		}
		//将其他行的第一个数变为0
		for (int i = 0; i < temp.GetRowCount(); i++)
		{
			if (i == row || temp.GetItem(i, 0) == 0) continue;
			double coefficience = temp.GetItem(i, 0) / temp.GetItem(row, 0);
			for (int j = 1; j < columnCount; j++)
			{
				double val = temp.GetItem(i, j) - coefficience * temp.GetItem(row, j);
				temp.SetItem(i, j, val);
			}
		}
		Matrix p(temp.GetRowCount() - 1, temp.GetColumnCount() - 1);
		int curRow = 0, curColumn = 0;
		for (int i = 0; i < temp.GetRowCount(); i++)
		{
			if(i == row) continue;
			for (int j = 1; j < temp.GetColumnCount(); j++)
			{
				p.SetItem(curRow, curColumn++, temp.GetItem(i, j));
			}
			curRow++;
			curColumn = 0;
		}
		temp.Reshape(p);
		rank++;
	}
	return rank;
}
Matrix Matrix::Inverse() {
	if (rowCount != columnCount) return Matrix(1, 1, 0);
	if(CalcDeterminant() == 0) return Matrix(1, 1, 0);
	int n = rowCount;
	Matrix partner(n, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Matrix p(n - 1, n - 1);
			int curRow = 0, curColumn = 0;
			for (int a = 0; a < n; a++)
			{
				if (a == i) continue;
				for (int b = 0; b < n; b++)
				{
					if(b == j) continue;
					p.SetItem(curRow, curColumn++, GetItem(a, b));
				}
				curRow++;
				curColumn = 0;
			}
			partner.SetItem(j, i, p.CalcDeterminant() * ((i + j) % 2 == 0 ? 1 : -1));
		}
	}
	return partner * (1.0 / CalcDeterminant());
}
void Matrix::SetToZeroMatrix() {
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < columnCount; j++)
		{
			r[i][j] = 0;
		}
	}
}
void Matrix::Transpose() {
	double** p = new double*[columnCount];
	for (int i = 0; i < columnCount; i++)
	{
		p[i] = new double[rowCount];
	}
	for (int i = 0; i < columnCount; i++)
	{
		for (int j = 0; j < rowCount; j++)
		{
			p[i][j] = r[j][i];
		}
	}
	for (int i = 0; i < rowCount; i++)
	{
		delete[] r[i];
	}
	delete[] r;
	r = p;
	int temp = rowCount;
	rowCount = columnCount;
	columnCount = temp;
}
void Matrix::SwapRows(int row1, int row2) {
	if (row1 < 0 || row2 < 0) return;
	if (row2 >= rowCount || row1 >= rowCount) return;
	for (int i = 0; i < columnCount; i++)
	{
		double temp = r[row1][i];
		r[row1][i] = r[row2][i];
		r[row2][i] = temp;
	}
}
void Matrix::SwapColumns(int column1, int column2) {
	if (column1 < 0 || column2 < 0) return;
	if (column1 >= columnCount || column2 >= columnCount) return;
	for (int i = 0; i < rowCount; i++)
	{
		double temp = r[i][column1];
		r[i][column1] = r[i][column2];
		r[i][column2] = temp;
	}
}
void Matrix::Reshape(int row, int column, double value) {
	double** p = new double*[row];
	for (int i = 0; i < row; i++)
	{
		p[i] = new double[column];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			p[i][j] = value;
		}
	}
	for (int i = 0; i < rowCount; i++)
	{
		delete[] r[i];
	}
	delete[] r;
	r = p;
	rowCount = row;
	columnCount = column;
}
void Matrix::Reshape(Matrix& m) {
	for (int i = 0; i < rowCount; i++)
	{
		delete[] r[i];
	}
	delete[] r;
	rowCount = m.GetRowCount();
	columnCount = m.GetColumnCount();
	r = new double*[rowCount];
	for (int i = 0; i < rowCount; i++)
	{
		r[i] = new double[columnCount];
	}
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < columnCount; j++)
		{
			r[i][j] = m.GetItem(i, j);
		}
	}
	
}
Matrix::~Matrix() {
	for (int i = 0; i < rowCount; i++)
	{
		delete[] r[i];
	}
	delete[] r;
}
Matrix Matrix::operator*(double time) {
	Matrix temp(rowCount, columnCount);
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < columnCount; j++)
		{
			temp.SetItem(i, j, r[i][j] * time);
		}
	}
	return temp;
}



//Wild Function
Matrix operator*(Matrix& ma, Matrix& mb) { 
	if (ma.GetColumnCount() != mb.GetRowCount()) return Matrix(1, 1, 0);
	Matrix res(ma.GetRowCount(), mb.GetColumnCount());
	for (int i = 0; i < ma.GetRowCount(); i++)
	{
		for (int j = 0; j < mb.GetColumnCount(); j++)
		{
			double temp = 0;
			for (int k = 0; k < ma.GetColumnCount(); k++)
			{
				temp += (ma.GetItem(i, k)*mb.GetItem(k, j));
			}
			res.SetItem(i, j, temp);
		}
	}
	return res; 
}
Matrix operator+(Matrix& ma, Matrix& mb){ 
	if (ma.GetRowCount() != mb.GetRowCount()) return Matrix(1, 1, 0);
	if (ma.GetColumnCount() != mb.GetColumnCount()) return Matrix(1, 1, 0);
	Matrix res(ma.GetRowCount(), ma.GetColumnCount());
	for (int i = 0; i < ma.GetRowCount(); i++)
	{
		for (int j = 0; j < ma.GetColumnCount(); j++)
		{
			res.SetItem(i, j, ma.GetItem(i, j) + mb.GetItem(i, j));
		}
	}
	return res; 
}
Matrix operator-(Matrix& ma, Matrix& mb){ 
	if (ma.GetRowCount() != mb.GetRowCount()) return Matrix(1, 1, 0);
	if (ma.GetColumnCount() != mb.GetColumnCount()) return Matrix(1, 1, 0);
	Matrix res(ma.GetRowCount(), ma.GetColumnCount());
	for (int i = 0; i < ma.GetRowCount(); i++)
	{
		for (int j = 0; j < ma.GetColumnCount(); j++)
		{
			res.SetItem(i, j, ma.GetItem(i, j) - mb.GetItem(i, j));
		}
	}
	return res;
}