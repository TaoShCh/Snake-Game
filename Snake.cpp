#include "Snake.h"
#include "Map.h"
#include "Food.h"
Snake::Snake() {
	length = 4;
	body[0] = { 5,2 };
	body[1] = { 4,2 };
	body[2] = { 3,2 };
	body[3] = { 2,2 };
	direction = DOWN;
}

void Snake::move_down() {
	for (int i = length - 1; i > 0; i--) {
		body[i] = body[i - 1];
	}
	body[0].h++;
}

void Snake::move_up() {
	for (int i = length - 1; i > 0; i--) {
		body[i] = body[i - 1];
	}
	body[0].h--;
}

void Snake::move_left() {
	for (int i = length - 1; i > 0; i--) {
		body[i] = body[i - 1];
	}
	body[0].w--;
}

void Snake::move_right() {
	for (int i = length - 1; i > 0; i--) {
		body[i] = body[i - 1];
	}
	body[0].w++;
}

void Snake::move() {
	switch (direction) {
		case LEFT:
			move_left();
			break;
		case RIGHT:
			move_right();
			break;
		case UP:
			move_up();
			break;
		case DOWN:
			move_down();
			break;
		default:
			break;
	}
}

void Snake::display() {
	set_position(2 * body[0].w, body[0].h);
	cout << "¡ô";
	for (int i = 1; i < length; i++) {
		set_position(2 * body[i].w, body[i].h);
		cout << "¡ñ";
	}
}

void Snake::clear() {
	for (int i = 0; i < length; i++) {
		set_position(2 * body[i].w, body[i].h);
		cout << "  ";
	}
}
void Snake::change_direction(char input) {
	switch (input)
	{
	case 72:
		if(direction != DOWN)
			direction = UP;
		break;
	case 75:
		if(direction != RIGHT)
			direction = LEFT;
		break;
	case 80:
		if(direction != UP)
			direction = DOWN;
		break;
	case 77:
		if(direction != LEFT)
			direction = RIGHT;
		break;
	default: break;
	}
}

bool Snake::hit_wall(Map *m) {
	if (m->map[body[0].h][body[0].w] == WALL) {
		return 1;
	}
	else return 0;
}

bool Snake::hit_itself() {
	for (int i = 1; i < length; i++) {
		if (body[i].h == body[0].h && body[i].w == body[0].w) {
			return 1;
		}
	}
	return 0;
}

bool Snake::in_snake(int h, int w) {
	for (int i = 0; i < length; i++) {
		if (body[i].h == h && body[i].w == w) {
			return 1;
		}
	}
	return 0;
}

bool Snake::eat_food(Food *f, Map *m) {
	if (body[0].h == f->h && body[0].w == f->w) {
		if(f->type == SMALL)
			length_increase(m);
		else {
			f->step = 0;
			set_position(2 * (m->width + 1), m->height / 2);
			cout << "  ";
			length_increase(m);
			length_increase(m);
			length_increase(m);
		}
		return 1;
	}
	else return 0;
}

void Snake::length_increase(Map *m) {
	int x = 2 * body[length - 1].w - body[length - 2].w;
	int y = 2 * body[length - 1].h - body[length - 2].h;
	if (in_snake(y, x) || m->get_point(y, x) == WALL) {
		x = body[length - 1].w;
		y = body[length - 1].h + 1;
	}
	if (in_snake(y, x) || m->get_point(y, x) == WALL) {
		x = body[length - 1].w;
		y = body[length - 1].h - 1;
	}
	if (in_snake(y, x) || m->get_point(y, x) == WALL) {
		x = body[length - 1].w + 1;
		y = body[length - 1].h;
	}
	if (in_snake(y, x) || m->get_point(y, x) == WALL) {
		x = body[length - 1].w - 1;
		y = body[length - 1].h;
	}
	body[length].h = y;
	body[length].w = x;
	length++;
}