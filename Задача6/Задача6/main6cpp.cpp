#include<iostream>
using namespace std;

void input_array(int dig[][5]) {
	int number = 0;
	int mult = 1;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {                                   // 0 1 2 3 4 4 3 2 1 0 4
			dig[i][(number%10 - i % 2 * (j * 2 + 1))] = number++;                      // 4 3 2 1 0
		}
		cout << i % 2;
		mult *= (-1);
	}
}
void read_array(int dig[][5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {                 
			cout<<dig[i][j]<<" ";
		}
		cout << "\n";
	}
}

int main() {
	int digits[5][5];
	input_array(digits);
	read_array(digits);
}