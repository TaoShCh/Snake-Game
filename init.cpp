#include "Map.h"
void game_init() {
	SetConsoleTitleA("Snake Game");
	HANDLE stdhd = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(stdhd, &CursorInfo);
	CursorInfo.bVisible = false; 
	SetConsoleCursorInfo(stdhd, &CursorInfo);
	
}

void map_init(Map *this_map, int height, int width) {
	int **Template;
	Template = new int* [height];
	for (int i = 0; i < height; i++) {
		Template[i] = new int[width];
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			Template[i][j] = SPACE;
		}
	}
	for (int i = 0; i < height; i++) {
		Template[i][0] = WALL;
		Template[i][width - 1] = WALL;
	}
	for (int i = 0; i < width; i++) {
		Template[0][i] = WALL;
		Template[height - 1][i] = WALL;
	}
	this_map->set_map(Template);
}