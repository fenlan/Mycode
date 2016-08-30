#ifndef _2048_H
#define _2048_H

#include <math.h>

/* 游戏界面和格子采用如下形式：
 *	|<-   UI_WIDTH	 ->|
 *	+------+------+....+ -
 *	|	   |	  |    | ^
 *	| 2048 | 1024 |    | |
 *	|	   |	  |    |
 *	+------+------+....+ UI_HEIGHT
 *	.	   .	  .    . |
 *	.	   .	  .    . V
 *	+------+------+....+ -
 */
#define GRID_COUNT	4					/* 游戏界面的格子大小 */
#define UI_WIDTH	(7*GRID_COUNT+1)	/* 游戏界面宽 */
#define UI_HEIGHT	(4*GRID_COUNT+1)	/* 游戏界面高 */
#define INIT_COUNT	2					/* 初始的数的数目 */
#define SY			((LINES - UI_HEIGHT- 5)/2)	/* 游戏界面位置 */
#define SX			((COLS - UI_WIDTH)/2)		/* 水平居中 */
#ifndef KEY_SPACE
#define KEY_SPACE	(' ')	/* 空格键 */
#endif
#ifndef KEY_R
#define KEY_R	('r')		/* r键 */
#endif
#undef ARRAY_SIZE
#define ARRAY_SIZE(a)	(sizeof(a)/sizeof(a[0]))
#define log2(x)	(log(x)/log(2))

/*
 * 不同数字对应的定义颜色
 */
#define COLOR_MAIN	13
#define COLOR_NEW	12
#define COLOR_2		1
#define COLOR_4		2
#define COLOR_8		3
#define COLOR_16	4
#define COLOR_32	5
#define COLOR_64	6
#define COLOR_128	7
#define COLOR_216	8
#define COLOR_512	9
#define COLOR_1024	10
#define COLOR_2048	11

#define pair(c_name)	init_pair(c_name, __map[c_name], COLOR_BLACK)

extern char enable_color;			/* 是否允许使用颜色 */
extern short __map[14];				/* 元素与颜色的对应 */

/*
 * 初始化ncurses库，判断是否能开启颜色
 */
int init_curses(void);
/*
 * 初始化内存
 */
int init_game(int **board);
/*
 * 退出游戏并释放空间
 */
int exit_game(int **board);
/*
 * 打印游戏边框和说明等
 */
int draw_border(void);			
/*
 * 根据key（方向键）来进行游戏
 * @return:
 *		0		胜利
 *		-1		失败
 *		其他值	继续游戏
 */
int mymove(int **board, int key);
/*
 * 绘制格子，把board刷新到屏幕
 */
int refresh_game(int **board);
/*
 * 判断胜利还是失败
 * @return:
 *		0		胜利
 *		-1		失败
 *		其他值	继续游戏
 */

int win_or_over(int **board);
/*
 * 判断按键是不是合法
 * @return:
 * 		0	不是
 * 		!0	是
 */
int is_legal_key(int key);

#endif