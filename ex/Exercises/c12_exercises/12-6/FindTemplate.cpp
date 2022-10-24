#include <cstddef>
import <iostream>;
import <array>;
import <concepts>;
import spreadsheet_cell;

using namespace std;

static const size_t NOT_FOUND{ static_cast<size_t>(-1) };

template <equality_comparable T>    //// Use the predefined std::equality_comparable concept.
size_t Find(const T& value, const T* arr, size_t size)
{
	for (size_t i{ 0 }; i < size; i++) {
		if (arr[i] == value) {
			return i; // Found it; return the index.
		}
	}
	return NOT_FOUND; // Failed to find it; return NOT_FOUND.
}

template <equality_comparable T, size_t N>    //// Use the predefined std::equality_comparable concept.
size_t Find(const T& value, const T(&arr)[N])
{
	return Find(value, arr, N);
}

int main()
{
	int myInt{ 3 }, intArray[]{ 1, 2, 3, 4 };
	const size_t sizeIntArray{ size(intArray) };

	size_t res;
	res = Find(myInt, intArray, sizeIntArray);        // calls Find<int> by deduction.
	res = Find<int>(myInt, intArray, sizeIntArray);   // calls Find<int> explicitly.
	res = Find(myInt, intArray);
	if (res != NOT_FOUND) { cout << res << endl; }
	else { cout << "Not found" << endl; }

	double myDouble{ 5.6 }, doubleArray[]{ 1.2, 3.4, 5.7, 7.5 };
	const size_t sizeDoubleArray{ size(doubleArray) };

	res = Find(myDouble, doubleArray, sizeDoubleArray);         // calls Find<double> by deduction.
	res = Find<double>(myDouble, doubleArray, sizeDoubleArray); // calls Find<double> explicitly.
	if (res != NOT_FOUND) { cout << res << endl; }
	else { cout << "Not found" << endl; }

	//res = Find(myInt, doubleArray, sizeDoubleArray);        // DOES NOT COMPILE! Arguments are different types.
	res = Find<double>(myInt, doubleArray, sizeDoubleArray);  // calls Find<double> explicitly, even with myInt.

	SpreadsheetCell cell1{ 10 };
	SpreadsheetCell cellArray[]{ SpreadsheetCell{ 4 }, SpreadsheetCell{ 10 } };
	const size_t sizeCellArray{ size(cellArray) };

	res = Find(cell1, cellArray, sizeCellArray);                  // calls Find<SpreadsheetCell> by deduction.
	res = Find<SpreadsheetCell>(cell1, cellArray, sizeCellArray); // calls Find<SpreadsheetCell> explicitly.
}
