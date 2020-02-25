#define WALL 1
#define FOOD 2
#define SPACE 0
#define MAX_SIZE 500
class Map
{
private:
	int width, height;
	int map[MAX_SIZE][MAX_SIZE];

public:

	Map(int w, int h);

};

