#include "common.h"

class Map
{
	friend class Snake;
	friend class Food;
	friend void display_point(Map* m, Snake* s, int speed);
private:
	int width, height;
	int **map;

public:
	Map(int h, int w);
	void display();
	void set_map(int **Template);
	int get_point(int h, int w);
};

