#include "Map.h"

Map::Map(int h, int w) {
	width = w;
	height = h;
	map = new int* [height];
	for (int i = 0; i < height; i++) {
		map[i] = new int[width];
	}
}

void Map::display() {
	set_position(0, 0);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			switch (map[i][j]) 
			{
			case WALL: 
				set_text_color(FOREGROUND_BLUE|FOREGROUND_INTENSITY);
				cout << "¡ö";
				set_text_color(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				break;
			case SPACE:
				cout << "  ";
				break;
			}
		}
		cout << endl;
	}
}

void Map::set_map(int **Template) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = Template[i][j];
		}
	}
}

int Map::get_point(int h, int w) {
	return map[h][w];
}