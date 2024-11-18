#include<iostream>                   // x x x x
									 // x x x x
                                     // x x x x
									 // x x x x
using namespace std;


void input_matrix(int matrix[][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << "Input number of: " << i + 1 << " string and " << j + 1 << " column: ";
			cin >> matrix[i][j];
		}
	}
}
void read_matrix(int matrix[][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << "\n";
	}
}
bool check_equal(int matrix_1[][4], int matrix_2[][4]) {
	bool flag = true;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (matrix_1[i][j] != matrix_2[i][j]) {
				flag = false;
				return flag;
			}
		}
	}
	return flag;
}
void zeroing_matrix(int matrix[][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i != j) {
				matrix[i][j] = 0;
			}
		}
	}
}
int main() {
	int matrix_1[4][4];
	int matrix_2[4][4];
	cout << "Input matrix 1\n";
	input_matrix(matrix_1);
	read_matrix(matrix_1);
	cout << "Input matrix 2\n";
	input_matrix(matrix_2);
	read_matrix(matrix_2);
	if (check_equal(matrix_1, matrix_2)) {
		cout << "matrix 1 = matrix 2\n";
		zeroing_matrix(matrix_1);
		read_matrix(matrix_1);
	}
	else {
		cout << "matrix 1 != matrix 2";
	}
}