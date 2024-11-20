#include<iostream>
using namespace std;

void input_array(int dig[][5]) {
	int number = 1;
	int mult = 1;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {                   
			dig[i][(5 + j * mult - i % 2) % 5] = number++;
		}
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