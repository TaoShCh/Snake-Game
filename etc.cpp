#include "common.h"
#include "Map.h"
#include "Snake.h"
#include <direct.h>
#include <string.h>
#include <fstream>
#include <algorithm>
int point = 0;

void set_position(int x, int y) {
	HANDLE stdhd = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {x, y};
	SetConsoleCursorPosition(stdhd, pos);
}

void set_text_color(int attribute) {
	HANDLE stdhd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(stdhd, attribute);
}

void display_point(Map* m, Snake* s, int speed) {
	point = speed * (s->length - 4);
	set_position(m->width - 7, m->height);
	cout << "Your point: " << point;
}


void game_begin() {
	game_init();
	cout << "This Snake Game is a project in Advanced Progamming 2019 autumn course" << endl;
	cout << "Developed by Tao Shaocheng @ NJU" << endl << endl;
	set_text_color(FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Press direction keys to control the snake" << endl;
	cout << "The super food will appear after you eat 5 common food" << endl;
	cout << "The super food can give you triple points but it will disappear after a period of time" << endl << endl;
	set_text_color(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	cout << "Enter Your Speed Please(1 to 20 recommended)" << endl;
	cout << "The higher speed you choose, the more points you will get" << endl;
}

void update_rank(string player) {
	char dir[200];
	_getcwd(dir, 200);
	char filename[200];
	char tmp[12] = "\\rank.txt";
	strcpy_s(filename, dir);
	strcat_s(filename, tmp);
	ifstream infile(filename);
	string players[11];
	int points[11];
	int count = 0;
	if (infile) {
		while (infile >> players[count] >> points[count]) {
			count++;
		}
	}
	players[count] = player;
	points[count] = point;
	int id = count;
	for (int i = count; i > 0; i--) {
		if (points[i] > points[i - 1]) {
			swap(players[i], players[i - 1]);
			swap(points[i], points[i - 1]);
			id = i - 1;
		}
		else break;
	}
	infile.close();
	if (id < 10) {
		set_text_color(FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "Congratulations! You enter the top10 scoring list!" << endl << endl;
		set_text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
	set_text_color(FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Top10 List" << endl;
	set_text_color(FOREGROUND_RED | FOREGROUND_GREEN|FOREGROUND_BLUE);
	ofstream outfile(filename);
	for (int i = 0; i < min(10, count + 1); i++) {
		outfile << players[i] << endl << points[i] << endl;
		if (i == id) {
			set_text_color(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			cout << i + 1 << ". " << players[i] << " " << points[i] << endl;
			set_text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
			cout << i+1 << ". " << players[i] << " " << points[i] << endl;
	}
	outfile.close();
}

void game_over(string player, Map *m) {
	system("cls");
	cout << "Game Over" << endl;
	update_rank(player);
}

void get_input(int* speed, string* player) {
	int tmp_speed;
	string tmp_player;
	cin >> tmp_speed;
	while (cin.good() != 1) {
		cout << "Please enter a number" << endl;
		cin.clear();
		string rubbish;
		cin >> rubbish;
		cin >> tmp_speed;
	}
	cout << endl << "Enter your name(in English) please" << endl;
	cin >> tmp_player;
	*speed = tmp_speed;
	*player = tmp_player;
}
