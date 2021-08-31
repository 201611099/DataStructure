#include "./labyrinth.h"

#define MAP_SIZE_X 8
#define MAP_SIZE_Y 9

int	map[MAP_SIZE_Y][MAP_SIZE_X] = {
	{0, 0, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 0, 1, 1, 1, 1},
	{1, 1, 1, 0, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 1, 0, 0},
	{1, 1, 1, 1, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 0, 2}
};

int	offset[4][2] = { // x, y
	{0, -1}, //위
	{1, 0}, //오른
	{0, 1}, //아래
	{-1, 0} //왼
};

Stack	*stack;

void	display_map()
{
	char	ch;
	
	system("clear");
	printf("----------MAP----------\n");
	for (int i = 0; i < MAP_SIZE_Y; i++)
	{
		for (int j = 0; j < MAP_SIZE_X; j++)
		{
			if (map[i][j] == 0)
				ch = 'O';
			else if (map[i][j] == 1)
				ch = 'X';
			else
				ch = 'E';
			if(ch == 'O')
				printf("%c[31m%c",27, ch);
			else if (ch == 'E')
				printf("%c[32m%c", 27, ch);
			else
				printf("%c[0m%c",27, ch);
		}
		printf("\n\n");
	}
	usleep(500 * 1000);
}

void	put_print()
{
	printLinkedList(stack);
}

t_bool	find_available_dir(t_data *cur_pos)
{
	int	next_x;
	int	next_y;

	map[cur_pos->y_pos][cur_pos->x_pos] = 1;
	for (int i = 0; i < 4; i++)
	{
		next_x = cur_pos->x_pos + offset[i][0];
		next_y = cur_pos->y_pos + offset[i][1];
		if (map[next_y][next_x] % 2 == 0 &&
				next_y >= 0 && next_y <= MAP_SIZE_Y &&
				next_x >= 0 && next_x <= MAP_SIZE_X)
		{
			push_list(stack, *cur_pos);
			cur_pos->y_pos += offset[i][1];
			cur_pos->x_pos += offset[i][0];
			return (TRUE);
		}
	}
	return (FALSE); 
		//스택이 비어있을때까지 빠져나오나 스택이 비어있으면 유효하지 않은 맵 출구가 없다.
}

int main(void)
{
	t_data	cur_pos;
	cur_pos.x_pos = 0;
	cur_pos.y_pos = 0;
	stack = createLinkedList();

	printf("Start position: (%d, %d)\n", cur_pos.x_pos, cur_pos.y_pos);
	display_map();
	while (map[cur_pos.y_pos][cur_pos.x_pos] < 2)
	{
			display_map();
		if(find_available_dir(&cur_pos) == FALSE)
		{

			if (stack->currentElementCount == 0)
			{
				display_map();
				printf("유효하지 않은 맵입니다.\n");
				return (1);
			}
			cur_pos = pop_list(stack);
		}
	}
	push_list(stack, cur_pos);
	display_map();
	put_print();

	return (0);
}

/*
0 0 0 1 1 1 0 0 0
0 1 1 1 1 1 0 1 0
0 0 0 0 0 0 0 1 0
1 1 1 1 0 1 1 1 0
1 1 1 1 1 1 0 1 0
1 1 1 1 1 1 1 0 0
1 1 1 1 1 1 1 0 1
1 1 1 1 1 1 1 0 E
*/

/*
while (출구 찾을 때까지)
{
	find함수에서 할 일	 
		1. 현재 위치에서 나아갈 수 있는 방향 검사
		2. 나아갈 수 있는 방향이 있다면 현재 위치를 스택에 push & 현재 위치 1로 만듦
		3.(아니면 매개변수(cur_pos)를 포인터 형식으로 넘겨서 함수 내에서 값 바꿔도 메인에 반영되도록 하면 좋을 것 같음) void형으로 만들기.
		// 3-1. 나아갈 방향 반환하고 다시 메인으로 돌아가서 방향 보고 cur_pos를 바꿔줌
}
*/
