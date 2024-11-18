#include<iostream>
using namespace std;

void input_matrix(float matrix[][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << "input number matrix of: " << i + 1 << "string and " << j + 1 << " column: ";
			cin >> matrix[i][j];
		}
	}
}
void input_vector(float* vector) {
	for (int i = 0; i < 4; i++) {
		cout << "input vector number " << i + 1 << " : ";
		cin >> vector[i];
	}
}

void mult(float matrix[][4], float* old_vector, float* new_vector) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			new_vector[i] += matrix[i][j] * old_vector[j];
		}
	}
}

void read_vector(float* vector) {
	for (int i = 0; i < 4; i++) {
		cout << vector[i] << "\n";
	}
	cout << "\n";
}

void read_matrix(float matrix[][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main() {
	float matrix[4][4];
	float old_vector[4];
	float new_vector[4] = {0,0,0,0};
	cout << "Input matrix\n";
	input_matrix(matrix);
	cout << "input vector\n";
	input_vector(old_vector);
	mult(matrix, old_vector, new_vector);
	read_matrix(matrix);
	read_vector(old_vector);
	read_vector(new_vector);
}