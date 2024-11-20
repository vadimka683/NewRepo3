#include<iostream>
using namespace std;

void pimple_start(bool pimp_flag[][12]) {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			pimp_flag[i][j] = true;
		}
	}
}

void read_pimple(bool pimp_flag[][12]) {
	for (int i = 0; i < 12; i++) {
		cout << i + 1 << "\t";
		for (int j = 0; j < 12; j++) {
			char a;
			a = (pimp_flag[i][j]) ? 'O' : 'X';
			cout << a << " ";
		}
		cout << "\n";
	}
	int count = 1;
	for (int i = 0; i < 12; i++) {
		cout << i + 1 << ":" << "\t";
		for (int j = 0; j < 12; j++) {
			cout << count++ << "\t";
		}
		cout << "\n";
	}
}

void pop(bool pimpl[][12]) {
	int X, Y;
	cout << "Input top border: ";
	cin >> X;
	cout << "input low border: ";
	cin >> Y;
	X--; Y--;
	int X_1, X_2, Y_1, Y_2;
	if (X > Y) {
		swap(X, Y);
	}
	X_1 = X / 12;
	X_2 = X % 12;
	Y_1 = Y / 12;
	Y_2 = Y % 12;
	for (int i = X_1; i <= Y_1; i++) {
		if (Y_2 > X_2) {
			for (int j = X_2; j <= Y_2; j++) {
				if (pimpl[i][j]) {
					cout << "Pop! ";
				}
				pimpl[i][j] = false;
			}
		}
		else {
			for (int j = X_2; j >= Y_2; j--) {
				if (pimpl[i][j]) {
					cout << "Pop! ";
				}
				pimpl[i][j] = false;
			}
		}
	}
	cout << "\n";
	read_pimple(pimpl);
}

bool check(bool pimpl[][12]) {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			if (pimpl[i][j]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	bool pimple_flag[12][12];
	pimple_start(pimple_flag);
	while (!check(pimple_flag)) {
		pop(pimple_flag);
	}
}