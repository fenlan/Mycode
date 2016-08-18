#include <stdlib.h>
#include "2048.h"
#include <ncurses.h>

int main(int argc, char **argv)
{
	int **board, i;
	int win, key;

	init_curses();
	/* 初始化游戏 */
	board = (int **)calloc(GRID_COUNT, sizeof(int *));
	if (NULL == board)
		exit(1);
	/* TODO 完善分配 */
	for (i = 0; i < GRID_COUNT; i ++) {
		board[i] = (int*)calloc(GRID_COUNT, sizeof(int));
		if (NULL == board[i])
			exit(1);
	}
	init_game(board);
	
	/* 开始游戏，按空格键退出游戏 */
	for (;;) {
		refresh_game(board);
		do {
			key = getch();
			/* 只有6个有效键 包括r键*/
		} while (!is_legal_key(key));
		if (KEY_R == key) {
			init_game(board);
			mvprintw(2, SX+UI_WIDTH/2-4, "New Game");
			refresh();
			getch();
			continue;
		}
		if (KEY_SPACE == key) {
			mvprintw(SY+UI_HEIGHT/2, SX+UI_WIDTH/4-1, "Quit gaming, thanks");
			break;
		}
		win = mymove(board, key);
		if (0 == win) {
			mvprintw(SY+UI_HEIGHT/2, SX+UI_WIDTH/4-1, "You are winner！");
			break;
		} else if (-1 == win) {
			mvprintw(SY+UI_HEIGHT/2, SX+UI_WIDTH/4-4, "Game Over!");
			break;
		}
	}
	exit_game(board);
	return 0;
}
