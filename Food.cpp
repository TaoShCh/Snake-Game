#include "Food.h"
#include "Map.h"
#include "Snake.h"

Food::Food() {
	count = 5;
	step = 0;
}

void Food::generate_new_food(Map *m, Snake *s) {
	srand((unsigned)time(NULL));
	count++;
	if (count % 6 == 0) {
		type = BIG;
	}
	else type = SMALL;
	int x = rand() % (m->width - 2) + 1;
	int y = rand() % (m->height - 2) + 1;
	while (s->in_snake(y, x) || m->get_point(y, x) == WALL) {
		x = rand() % (m->width - 2) + 1;
		y = rand() % (m->height - 2) + 1;
	}
	h = y;
	w = x;
}

void Food::display() {
	set_position(2 * w, h);
	if (type == BIG) {
		set_text_color(FOREGROUND_RED);
		cout << "¡ï";
		set_text_color(0);
	}
	else cout << "¡î";
}

void Food::clear() {
	set_position(2 * w, h);
	cout << "  ";
}

void Food::step_count(Map *m, Snake *s) {
	if (type != BIG) return;
	step += 1;
	set_position(2 * (m->width + 1), m->height / 2);
	cout << "  ";
	set_position(2 * (m->width + 1), m->height / 2);
	set_text_color(FOREGROUND_RED);
	cout << 30 - step;
	set_text_color(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	if (step == 30) {
		clear();
		generate_new_food(m, s);
		display();
		step = 0;
		set_position(2 * (m->width + 1), m->height / 2);
		cout << "  ";
	}
}