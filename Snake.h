#include "common.h"

struct Node {
	int h, w;
};
class Snake
{
	friend class Food;
	friend void display_point(Map* m, Snake* s, int speed);
private:
	Node body[MAX_LENGTH];
	int length;
	int direction;

	void move_right();
	void move_left();
	void move_up();
	void move_down();
public:
	Snake();
	void move();
	void display();
	void clear();
	void change_direction(char input);
	bool hit_wall(Map *m);
	bool hit_itself();
	bool in_snake(int h, int w);
	bool eat_food(Food *f, Map *m);
	void length_increase(Map *m);
};

