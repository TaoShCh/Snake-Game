#include "Map.h"
#include "Snake.h"
#include "Food.h"
#include <conio.h>
int main()
{
	game_begin();
	int speed;
	string player;
	get_input(&speed, &player);
	system("cls");
	int width = 20, height = 20;
	Map *map = new Map(height, width);
	Snake* snake = new Snake();
	Food* food = new Food();
	map_init(map, height, width);
	map->display();	
	snake->display();
	food->generate_new_food(map, snake);
	food->display();
	display_point(map, snake, speed);
	while (1) {
		if (_kbhit()) {
			char input = _getch();
			if (input == -32) {
				input = _getch();
				snake->change_direction(input);
			}		
		}
		Sleep(1000/speed);
		snake->clear();
		snake->move();
		if (snake->hit_itself() || snake->hit_wall(map)) {
			game_over(player, map);
			break;
		}
		if (snake->eat_food(food, map)) {
			display_point(map, snake, speed);
			food->clear();
			food->generate_new_food(map, snake);
			food->display();
		}
		food->step_count(map, snake);
		snake->display();
	}
}

