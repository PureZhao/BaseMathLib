# BaseMathLib

## 2021.7.13 Update

### Functions

- Name change **Matrix::CalcDeterminant()** to **Matrix::Determinant()**
- Delete functions **Matrix::GetItem()** and **Matrix::SetItem()**
- Add overload function **Matrix::operator\[]()** to replace functions **Matrix::GetItem()** and **Matrix::SetItem()**
- Move inner-class function **Matrix::operator\*()** to outer-class function **operator\*()**
- Add function **Matrix::ToArray()**
- Add function **Matrix::operator=()**
- Add static functions **Matrix::Zeros()** and **Matrix::Unit()**

### Bug Fixed

- Fixed the function **Matrix::Determinant()** returns incorrect computing result

-----------

