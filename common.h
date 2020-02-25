#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

#define MAX_SIZE 500
#define WALL 1
#define SPACE 0
#define FOOD 2
#define SUPER_FOOD 3
#define SNAKE 4
#define MAX_LENGTH 500
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4
#define BIG 1
#define SMALL 0

class Map;
class Snake;
class Food;
void game_init();
void map_init(Map* this_map, int height, int width);
void set_position(int x, int y);
void game_over(string player, Map *m);
void set_text_color(int attribute);
void display_point(Map* m, Snake* s, int speed);
void game_begin();
void get_input(int* speed, string* player);