#include "2048.h"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

static int newy = -1, newx = -1;	/* 记录新添加元素的位置 */
char enable_color = 0;
short __map[14] = { 0,				/* __map[0] 没用 */
	220, 214, 208, 202, 196, 124, 88, 22, 4, 12, 5, 21, COLOR_WHITE,
};

/* 生成没有被占用的格子的pos */
static int _rand(int **board)
{
	int pos;
	/* TODO 改进随机算法 */
	srand(time(NULL));
	do {
		pos = rand()%(GRID_COUNT*GRID_COUNT);
	} while (0 != board[pos/GRID_COUNT][pos%GRID_COUNT]);

	return pos;
}

/*
 * 初始化ncurses库
 */
int init_curses(void)
{
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	if (has_colors()) {
		enable_color = 1;
		start_color();
	}
	return 0;
}
/*
 * 初始化内存
 */
int init_game(int **board)
{
	int i, j, pos;
	/* 清零 */
	for (i = 0; i < GRID_COUNT; ++i)
		for (j = 0; j < GRID_COUNT; ++j)
			board[i][j] = 0;
	/* 初始数字 */
	for (i = 0; i < INIT_COUNT; ++i) {
		pos = _rand(board);
		board[pos/GRID_COUNT][pos%GRID_COUNT] = 2;
	}
	
	return 0;
}

/*
 * 打印游戏边框和说明等
 */
int draw_border(void)
{
	int x, y;
	/*		 +----+----+----+
	 *		 ^ ^  ^			^
	 *		 | |  |			|
	 * acs_? 1 2  3			4
	 */
	int acs_1, acs_2, acs_3, acs_4;

	for (y = 0; y < LINES; ++y)
		for (x = 0; x < COLS; ++x)
			mvprintw(y, x, " ");

	/* 一些说明信息 */
	mvprintw(0, SX+UI_WIDTH/2-4, "2048Game");
	mvprintw(UI_HEIGHT+SY, SX, "Usag:  Up Down Left Right Space R");
	mvprintw(UI_HEIGHT+SY+1, SX, "\tUp: move up");
	mvprintw(UI_HEIGHT+SY+2, SX, "\tDown: move down");
	mvprintw(UI_HEIGHT+SY+3, SX, "\tLeft: move left");
	mvprintw(UI_HEIGHT+SY+4, SX, "\tRight: move right");
	mvprintw(UI_HEIGHT+SY+5, SX, "\tR: try again");
	mvprintw(UI_HEIGHT+SY+6, SX, "\tSpace: Quit game");

	/*
	 * 表格由每行构成，每行由上诉acs_1~4组成
	 * 每行的不同只有acs_1~4不同
	 */
	for (y = 0; y < UI_HEIGHT; y ++) {
		if (0 == y) {
			acs_1 = ACS_ULCORNER;
			acs_2 = ACS_HLINE;
			acs_3 = ACS_TTEE;
			acs_4 = ACS_URCORNER;
		} else if (UI_HEIGHT-1 == y) {
			acs_1 = ACS_LLCORNER;
			acs_2 = ACS_HLINE;
			acs_3 = ACS_BTEE;
			acs_4 = ACS_LRCORNER;
		} else if (0 == y%4) {
			acs_1 = ACS_LTEE;
			acs_2 = ACS_HLINE;
			acs_3 = ACS_PLUS;
			acs_4 = ACS_RTEE;
		} else {
			acs_1 = ACS_VLINE;
			acs_2 = ' ';
			acs_3 = acs_1;
			acs_4 = acs_1;
		}
				/* 绘制表格 */
		mvaddch(SY+y, SX, acs_1);
		for (x = 1; x < UI_WIDTH-1; x ++) {
			if (0 == x % 7)
				mvaddch(SY+y, SX+x, acs_3);
			else
				mvaddch(SY+y, SX+x, acs_2);
		}
		mvaddch(SY+y, SX+UI_WIDTH-1, acs_4);
	}
	return 0;
}

/*
 * 根据key（方向键）来进行游戏
 * @return:
 *		0		胜利
 *		-1		失败
 *		其他值	继续游戏
 */
int mymove(int **board, int key)
{
	int win;
	int curr, i, j;
	int pos;
	
	/* board[y][x]: y, 行; x, 列
	 * 算法梗概：
	 * 1. 这个操作是按照一行或一列扫描来工作。
	 * 2. 对于每一行或每一列。
	 *		假如下就是一行（0表示空白）：
	 *		2 0 16 0
	 *		^	 ^
	 *		|	 |
	 *		curr j
	 *		假设是从左向右扫描（这个方向和按键有关的）
	 *		使用三个量：curr	当前已处理的位置
	 *					i		标记处理到了哪一行(列)
	 *					j		某一行(列)的某一数字
	 */
	switch(key) {
		case KEY_LEFT: /* 向左 */
			for (i = 0; i < GRID_COUNT; ++i) {
				curr = -1;
				for (j = 0; j < GRID_COUNT; ++j) {
					if (0 == board[i][j])	/* 空格子 */
						continue;

					if (-1 != curr && board[i][curr] == board[i][j] )
						board[i][curr] *= 2;
					else
						board[i][++curr] = board[i][j];
					if (curr != j)
						board[i][j] = 0;
				}
			}
			break;
		case KEY_RIGHT: /* 向右 */
			for (i = 0; i < GRID_COUNT; ++i) {
				curr = GRID_COUNT;
				for (j = GRID_COUNT-1; j > -1; j --) {
					if (0 == board[i][j])
						continue;
					if (GRID_COUNT != curr && board[i][curr] == board[i][j])
						board[i][curr] *= 2;
					else
						board[i][--curr] = board[i][j];
					if (curr != j)
						board[i][j] = 0;
				}
			}
			break;
		case KEY_UP: /* 向上 */
			for (i = 0; i < GRID_COUNT; ++i) {
				curr = -1;
				for (j = 0; j < GRID_COUNT; ++j) {
					if (0 == board[j][i])
						continue;
					if (-1 != curr && board[curr][i] == board[j][i])
						board[curr][i] *= 2;
					else
						board[++curr][i] = board[j][i];
					if (curr != j)
						board[j][i] = 0;
				}
			}
			break;
		case KEY_DOWN: /* 向下 */
			for (i = 0; i < GRID_COUNT; ++i) {
				curr = GRID_COUNT;
				for (j = GRID_COUNT-1; j > -1; j --) {
					if (0 == board[j][i])
						continue;
					if (GRID_COUNT != curr && board[curr][i] == board[j][i])
						board[curr][i] *= 2;
					else
						board[--curr][i] = board[j][i];
					if (curr != j)
						board[j][i] = 0;
				}
			}
		break;
	}
	/* 在这里检测是否输赢才合理 */
	win = win_or_over(board);
	if (-1 == win)
		return win;
	/* 随机添加新的‘2’的位置 */
	pos = _rand(board);
	/* 为了使新元素是特殊颜色，这里需要记录下的new* */
	newy = pos/GRID_COUNT;
	newx = pos%GRID_COUNT;
	board[newy][newx] = 2;
	
	return win;
}

/*
 * 绘制格子，把board刷新到屏幕
 */
int refresh_game(int **board)
{
	int x, y;
	short color_name;
	clear();
	draw_border();
	/* 主要颜色 */
	if (enable_color) {
		pair(COLOR_MAIN);
		wattron(stdscr, COLOR_PAIR(COLOR_MAIN));
	}

	/* 渲染数字 */
	for (y = 0; y < GRID_COUNT; ++y)
		for (x = 0; x < GRID_COUNT; ++x) {
			if (0 == board[y][x])
				continue;
			color_name = (short)log2((double)board[y][x]);
#ifdef DEBUG
			mvprintw(0, 0, "%d", (int)color_name);
#endif
			pair(color_name);
			attron(COLOR_PAIR(color_name));
			mvprintw(SY+2+y*4, SX+2+x*7, "%4d", board[y][x]);
			attroff(COLOR_PAIR(color_name));
			if (newy == y && newx == x) {
				pair(COLOR_NEW);
				attron(COLOR_PAIR(COLOR_NEW));
				mvprintw(SY+2+y*4, SX+2+x*7, "%4d", board[y][x]);
				attroff(COLOR_PAIR(COLOR_NEW));
			}
		}
	refresh();
	return 0;
}

/*
 * 判断胜利还是失败
 * @return:
 *		0		胜利
 *		-1		失败
 *		其他值	继续游戏
 */
int win_or_over(int **board)
{
	int i, j, count = 0;
	for (i = 0; i < GRID_COUNT; ++i)
		for (j = 0; j < GRID_COUNT; ++j) {
			if (2048 == board[i][j])
				return 0;
			if (0 != board[i][j])
				++ count;
		}
	if (GRID_COUNT*GRID_COUNT == count)
		return -1;
	return 1;
}

/*
 * 退出游戏并释放空间
 */
int exit_game(int **board)
{
	int i;
	endwin();
	wattroff(stdscr, COLOR_PAIR(COLOR_MAIN));
	for (i = 0; i < GRID_COUNT; ++i)
		free(board[i]);
	free(board);
	return 0;
}

/*
 * 判断按键是不是合法
 * @return:
 * 		0	不是
 *		!0	是
 */
int is_legal_key(int const key)
{
	int legal_keys[] = { KEY_LEFT, KEY_UP, KEY_RIGHT,
		KEY_DOWN, KEY_R, KEY_SPACE,
	};
	int i;
	for (i = 0; i < ARRAY_SIZE(legal_keys); ++i)
		if (key == legal_keys[i])
			return 1;
	return 0;
}