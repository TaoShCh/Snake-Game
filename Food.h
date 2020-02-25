#include "common.h"
#include <stdlib.h>
#include <time.h>
class Food
{
	friend class Snake;
private:
	int h, w;
	int count;
	int type;
	int step;
public:
	Food();
	void generate_new_food(Map *m, Snake *s);
	void display();
	void clear();
	void step_count(Map *m, Snake *s);
};

