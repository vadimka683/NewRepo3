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
	cout << "\n\n";                               // x x x  0 1 2
}                                                 // x x x  3 4 5
bool check(char table[][1], char winner[1]) {     // x x x  6 7 8
	bool flag = false;
	for (int j = 0, i = 0; j < 9 && i < 3; j += 3, i++) {
		if (table[j][0] == table[j + 1][0] && table[j][0] == table[j + 2][0] && (table[j][0] == 'X' || table[j][0] == 'O')) {
			winner[0] = (table[j][0] == 'X') ? '1' : '2';
			flag = true;
			return flag;
		}else if (table[i][0] == table[i + 3][0] && table[i][0] == table[i + 6][0] && (table[i][0] == 'X' || table[i][0] == 'O')) {
			winner[0] = (table[i][0] == 'X') ? '1' : '2';
			flag = true;
			return flag;
		}
	}
	if (table[0][0] == table[4][0] && table[0][0] == table[8][0] && (table[0][0] == 'X' || table[0][0] == 'O')) {
		winner[0] = (table[0][0] == 'X') ? '1' : '2';
		flag = true;
		return flag;
	}else if (table[2][0] == table[4][0] && table[2][0] == table[6][0] && (table[2][0] == 'X' || table[2][0] == 'O')) {
		winner[0] = (table[2][0] == 'X') ? '1' : '2';
		flag = true;
		return flag;
	}
	return flag;
}
int play() {
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
		count++;
		int X;
		if (!flag) {
			do {
				cout << "player 1. Input move: ";
				cin >> X;
				if (table[X - 1][0] != '#') {
					cout<<"impossible move\n";
				}
			} while (table[X - 1][0] != '#');
			table[X - 1][0] = 'X';
			flag = true;
		}
		else {
			do {
				cout << "player 2. Input move: ";
				cin >> X;
				if (table[X - 1][0] != '#') {
					cout << "impossible move\n";
				}
			} while (table[X - 1][0] != '#');
			table[X - 1][0] = 'O';
			flag = false;
		}
		read_table(table);
		if (count > 3) {
			if (check(table, winner)) {
				cout << "Winner player: " << winner[0];
				if (winner[0] == '1') { return 1; }
				else { return 2; };
			}
		}
	}
	cout << "DRAW";
	return 3;
}
int main() {
	int count_first = 0, count_second = 0;
	do {
		cout << "\nif you want to start a new game click: p\nif you want exit click: o ";
		char a;
		cin >> a;
		if (a == 'p') {
			int a = play();
			if (a == 1) { count_first++; }
			else if (a == 2) { count_second++; }
			else { count_first++; count_second++; }
		}
		else if (a == 'o') {
			return 0;
		}
		else {
			cout << "Input valid command\n";
		}
		cout << "\nFirst have " << count_first << " points";
		cout << "\nSecond have " << count_second << " points";
	} while (true);
}