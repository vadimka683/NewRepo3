#include<iostream>
using namespace std;

void input_array(int arr[][5][10]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << "enter the height of the building: ";
			int a;
			cin >> a;
			for (int h = 0; h < a; h++) {
				arr[i][j][h] = 1;
			}
		}
	}
}

void read_array(int arr[][5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

void horizontal_cut(int arr[][5][10],int arr_cut[][5]) {
	int level;
	cout << "Input level: ";
	cin >> level;
	level--;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[i][j][level] == 1) {
				arr_cut[i][j] = 1;
			}
			else {
				arr_cut[i][j] = 0;
			}
		}
	}
}

int main() {
	int array[5][5][10];
	int array_cut[5][5];
	input_array(array);
	int i = 2;
	while (i != 0) {
		horizontal_cut(array, array_cut);
		read_array(array_cut);
	}
}