#include<iostream>
using namespace std;

void input_start_square(char battle[][12]) {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			battle[i][j] = '#';
		}
	}
}

void read_square(char battle[][12]) {
	cout << "  0 1 2 3 4 5 6 7 8 9\n";
	for (int i = 1; i < 11; i++) {
		cout << i - 1 << " ";
		for (int j = 1; j < 11; j++) {
			cout << battle[i][j]<<" ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void small_ship(char battle[][12]) {
	int x, y;
	do {
		cout << "Input coordinates small ship: ";
		cin >> x >> y;
		x++;
		y++;
		if (x < 0 || x > 10 || y < 0 || y > 10) {
			cout << "Inposidle coordinates!";
		}
	} while (x < 0 || x > 10 || y < 0 || y > 10
		|| battle[x][y] != '#' || battle[x + 1][y] != '#'
		|| battle[x][y + 1] != '#' || battle[x + 1][y + 1] != '#'
		|| battle[x - 1][y - 1] != '#' || battle[x - 1][y] != '#'
		|| battle[x][y - 1] != '#' || battle[x - 1][y + 1] != '#' || battle[x + 1][y - 1] != '#');
	battle[x][y] = 'O';
	read_square(battle);
}
void over_ship(char battle[][12], int num) {
	int x, y, x_f, y_f;
	bool flag;
	do {
		flag = true;
		if (num == 1) {
			cout << "Input coordinates start litle ship: ";
		}else if (num == 2) {
			cout << "Input coordinates start middle ship: ";
		}else if (num == 3) {
			cout << "Input coordinates start big ship: ";
		}
		cin >> x >> y;
		x++; y++;
		if (num == 1) {
			cout << "Input coordinates finish litle ship: ";
		}else if (num == 2) {
			cout << "Input coordinates finish middle ship: ";
		}else if (num == 3) {
			cout << "Input coordinates finish big ship: ";
		}
		cin >> x_f >> y_f;
		x_f++;y_f++;                                                                   // # X #
		if (x_f < 0 || x_f > 10 || y_f < 0 || y_f > 10							       // # X #      //
				|| battle[x_f][y_f] != '#' || battle[x_f + 1][y_f] != '#'              // # X #      // # # # # #
				|| battle[x_f][y_f + 1] != '#' || battle[x_f + 1][y_f + 1] != '#'      // # X #      // # X X X #
				|| battle[x_f - 1][y_f - 1] != '#' || battle[x_f - 1][y_f] != '#'      // # # #      // # # # # #
				|| battle[x_f][y_f - 1] != '#' || battle[x_f - 1][y_f + 1] != '#' || battle[x_f + 1][y_f - 1] != '#'){
			flag = false;
			cout << "Inposidle coordinates!";
		}
		else if (x < 0 || x > 10 || y < 0 || y > 10
			|| battle[x][y] != '#' || battle[x + 1][y] != '#'
			|| battle[x][y + 1] != '#' || battle[x + 1][y + 1] != '#'
			|| battle[x - 1][y - 1] != '#' || battle[x - 1][y] != '#'
			|| battle[x][y - 1] != '#' || battle[x - 1][y + 1] != '#' || battle[x + 1][y - 1] != '#'){
		}
		else if (x - x_f != 0 && y - y_f != 0) {
			flag = false;
			cout << "Inposidle coordinates!";
		}
		else if ((num == 3 && (abs(x - x_f) != 3 && abs(y - y_f) != 3)) || (num == 2 && (abs(x - x_f) != 2 && abs(y - y_f) != 2))) {
			flag = false;
			cout << "Inposidle coordinates!";
		}
	} while (!flag);
	if (num == 1) {
		battle[x_f][y_f] = 'O';
		battle[x][y] = 'O';
	}
	else if (num == 2) {
		if (x - x_f == 2 && y - y_f == 0) {
			battle[x_f][y_f] = 'O';
			battle[x][y] = 'O';
			battle[x_f + 1][y_f] = 'O';
		}
		else if (x - x_f == -2 && y - y_f == 0) {
			battle[x_f][y_f] = 'O';
			battle[x][y] = 'O';
			battle[x + 1][y] = 'O';
		}
		else if (y - y_f == 2 && x - x_f == 0) {
			battle[x_f][y_f] = 'O';
			battle[x][y] = 'O';
			battle[x_f][y_f + 1] = 'O';
		}
		else if (y - y_f == -2 && x - x_f == 0) {
			battle[x_f][y_f] = 'O';
			battle[x][y] = 'O';
			battle[x][y + 1] = 'O';
		}
	}
	else if (num == 3) {
		if (x - x_f == 3 && y - y_f == 0) {
			battle[x_f][y_f] = 'O';
			battle[x][y] = 'O';
			battle[x_f + 1][y_f] = 'O';
			battle[x_f + 2][y_f] = 'O';
		}
		else if (x - x_f == -3 && y - y_f == 0) {
			battle[x_f][y_f] = 'O';
			battle[x][y] = 'O';
			battle[x + 1][y] = 'O';
			battle[x + 2][y] = 'O';
		}
		else if (y - y_f == 3 && x - x_f == 0) {
			battle[x_f][y_f] = 'O';
			battle[x][y] = 'O';
			battle[x_f][y_f + 1] = 'O';
			battle[x_f][y_f + 2] = 'O';
		}
		else if (y - y_f == -3 && x - x_f == 0) {
			battle[x_f][y_f] = 'O';
			battle[x][y] = 'O';
			battle[x][y + 1] = 'O';
			battle[x][y + 2] = 'O';
		}
		else {
			cout << "Inposidle coordinates!";
		}
	}
	read_square(battle);
}

void ships(char battle[][12]) {
	int count_small = 4, count_litle = 3, count_middle = 2, count_big = 1;
	while (count_small != 0) {
		small_ship(battle);
		--count_small;
	}
	while (count_litle != 0) {
		over_ship(battle, 1);
		--count_litle;
	}
	while (count_middle != 0) {
		over_ship(battle, 2);
		--count_middle;
	}
	while (count_big != 0) {
		over_ship(battle, 3);
		--count_big;
	}
	system("cls");
}

bool var(char battle_1[][12], char battle_2[][12], char battle_1_add[][12], char battle_2_add[][12], bool F) {
	bool strik;
	if (F) {
		strik = false;
		cout << "First player move:\n";
		read_square(battle_1_add);
		int x = 0, y = 0;
		do {
			cout << "Enter the strike coordinates: ";
			cin >> x >> y;
			x++; y++;
		} while (x < 0 || x > 10 || y < 0 || y > 10);
		if (battle_2[x][y] == '#') {
			battle_1_add[x][y] = 'X';
		}
		else {
			battle_1_add[x][y] = 'O';
			strik = true;
			battle_2[x][y] = 'i';
			if ((battle_2[x + 1][y] == '#' || battle_2[x + 1][y] == 'i') && (battle_2[x][y + 1] == '#' || battle_2[x][y + 1] == 'i')
				&& (battle_2[x + 1][y + 1] == '#' || battle_2[x + 1][y + 1] == 'i') && (battle_2[x - 1][y - 1] == '#' || battle_2[x - 1][y - 1] == 'i')
				&& (battle_2[x - 1][y] == '#' || battle_2[x - 1][y] == 'i') && (battle_2[x][y - 1] == '#' || battle_2[x][y - 1] == 'i')
				&& (battle_2[x - 1][y + 1] == '#' || battle_2[x - 1][y + 1] == 'i') && (battle_2[x + 1][y - 1] == '#' || battle_2[x + 1][y - 1] == 'i')) {
				battle_1_add[x + 1][y] = 'X'; battle_1_add[x][y + 1] = 'X';
				battle_1_add[x + 1][y + 1] = 'X'; battle_1_add[x - 1][y - 1] = 'X';
				battle_1_add[x - 1][y] = 'X'; battle_1_add[x][y - 1] = 'X';
				battle_1_add[x - 1][y + 1] = 'X'; battle_1_add[x + 1][y - 1] = 'X';
			}
		}
		read_square(battle_1_add);
		return strik;
	}
	else {
		strik = true;
		cout << "Second player move:\n";
		read_square(battle_2_add);
		int x = 0, y = 0;
		do {
			cout << "Enter the strike coordinates: ";
			cin >> x >> y;
			x++; y++;
		} while (x < 0 || x > 10 || y < 0 || y > 10);
		if (battle_1[x][y] == '#') {
			battle_2_add[x][y] = 'X';
		}
		else {
			battle_2_add[x][y] = 'O';
			battle_1[x][y] = 'i';
			strik = false;
			if ((battle_1[x + 1][y] == '#' || battle_1[x + 1][y] == 'i') && (battle_1[x][y + 1] == '#' || battle_1[x][y + 1] == 'i')
					&& (battle_1[x + 1][y + 1] == '#' || battle_1[x + 1][y + 1] == 'i') && (battle_1[x - 1][y - 1] == '#' || battle_1[x - 1][y - 1] == 'i')
					&& (battle_1[x - 1][y] == '#' || battle_1[x - 1][y] == 'i') && (battle_1[x][y - 1] == '#' || battle_1[x][y - 1] == 'i')
					&& (battle_1[x - 1][y + 1] == '#' || battle_1[x - 1][y + 1] == 'i') && (battle_1[x + 1][y - 1] == '#' || battle_1[x + 1][y - 1] == 'i')) {
				battle_2_add[x + 1][y] = 'X'; battle_2_add[x][y + 1] = 'X';
				battle_2_add[x + 1][y + 1] = 'X'; battle_2_add[x - 1][y - 1] = 'X';
				battle_2_add[x - 1][y] = 'X'; battle_2_add[x][y - 1] = 'X';
				battle_2_add[x - 1][y + 1] = 'X'; battle_2_add[x + 1][y - 1] = 'X';
			}
		}
		read_square(battle_2_add);
		return strik;
	}
}
bool check_win(char battle_1[][12], char battle_2[][12], char* win) {
	bool flag = false;
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {
			if (battle_1[i][j] == 'O') {
				flag = true;
			}
		}
	}
	if (!flag) {
		win[0] = '2';
		return flag;
	}
	if (flag) {
		flag = false;
		for (int i = 1; i < 11; i++) {
			for (int j = 1; j < 11; j++) {
				if (battle_2[i][j] == 'O') {
					flag = true;
				}
			}
		}
	}
	if (!flag) {
		win[0] = { 1 };
		return flag;
	}
	return flag;
}
void play(char battle_1[][12], char battle_2[][12], char battle_1_add[][12], char battle_2_add[][12],char* win) {
	bool flag = true;
	while (check_win(battle_1,battle_2,win)) {
		if (flag) {
			flag = var(battle_1, battle_2, battle_1_add, battle_2_add, flag);
		}
		else {
			flag = var(battle_1, battle_2, battle_1_add, battle_2_add, flag);
		}
	}
	cout << win[0] << " Player winner\n";
	read_square(battle_1);
	read_square(battle_2);
}
int main() {
	char battlefield_1[12][12];
	char battlefield_2[12][12];
	char battlefield_1_add[12][12];
	char battlefield_2_add[12][12];
	char winner[1] = {'0'};
	input_start_square(battlefield_1);
	input_start_square(battlefield_2);
	cout << "Player 1 input your ships\n";
	ships(battlefield_1);
	cout << "Player 2 input your ships\n";
	ships(battlefield_2);
	input_start_square(battlefield_1_add);
	input_start_square(battlefield_2_add);
	play(battlefield_1, battlefield_2, battlefield_1_add, battlefield_2_add,winner);
}