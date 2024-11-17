#include<iostream>
using namespace std;

void read_table(char tabel[][1]) {
	cout << "      TABLE:\n";
	for (int i = 0; i < 9; i++) {
		if (i == 2 || i == 5) {
			cout << tabel[i][0] << "\n";
		}                                
		else {
			cout << tabel[i][0] << "\t";
		}
	}
	cout << "\n\n";
}
bool check(char table[][1], char winner[1]) {
	bool flag = false;
	for (int i = 0; i < 9; i += 3) {
		if (table[i][0] == table[i + 1][0] && table[i][0] == table[i + 2][0] && (table[i][0] == 'X' || table[i][0] == 'O')) {
			winner[0] = (table[i][0] == 'X') ? '1' : '2';
			flag = true;
			return flag;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (table[i][0] == table[i + 3][0] && table[i][0] == table[i + 6][0] && (table[i][0] == 'X' || table[i][0] == 'O')) {
			winner[0] = (table[i][0] == 'X') ? '1' : '2';
			flag = true;
			return flag;
		}
	}
	if (table[0][0] == table[4][0] && table[0][0] == table[8][0] && (table[0][0] == 'X' || table[0][0] == 'O')) {
		winner[0] = (table[0][0] == 'X') ? '1' : '2';
		flag = true;
		return flag;
	}
	if (table[2][0] == table[4][0] && table[2][0] == table[6][0] && (table[2][0] == 'X' || table[2][0] == 'O')) {
		winner[0] = (table[2][0] == 'X') ? '1' : '2';
		flag = true;
		return flag;
	}
	return flag;
}
void play() {
	char table[9][1];
	char winner[1] = { 0 };
	for (int i = 0; i < 9; i++) {
		table[i][0] = '#';
	}
	cout << "Welcome to the new game!\n";
	read_table(table);
	int count = 0;
	bool flag = false;
	while (count < 9) {
		if (!flag) {
			cout << "player 1. Input move: ";
			int X;
			cin >> X;
			table[X - 1][0] = 'X';
			flag = true;
		}
		else {
			cout << "player 2. Input move: ";
			int X;
			cin >> X;
			table[X - 1][0] = 'O';
			flag = false;
		}
		read_table(table);
		if (check(table, winner)) {
			cout << "Winner player: " << winner[0];
			return;
		}
	}
	cout << "DRAW";
	return;
}
int main() {
	do {
		cout << "\nif you want to start a new game click: p\nif you want exit click: o ";
		char a;
		cin >> a;
		if (a == 'p') {
			play();
		}
		else if (a == 'o') {
			return 0;
		}
		else {
			cout << "Input valid command\n";
		}
	} while (true);
}