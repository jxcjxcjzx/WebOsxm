/*****************************************************************************
** File Name:      snake
** Author:           MaosiDiaoxian
** Date:            2010/0802
** Copyright:               *
** Description:    snake game         
******************************************************************************
**                         Important Edit History                            *
** --------------------------------------------------------------------------*
** DATE           NAME             DESCRIPTION                               *
** 2010/08/02    MaosiDiaoxian             Create                                 *
******************************************************************************/

/**--------------------------------------------------------------------------*
 **                         Include Files                                    *
 **--------------------------------------------------------------------------*/
 #include <stdio.h>
 #include <time.h>
 #include <assert.h>
 #include "pcc32.h"
 
/**--------------------------------------------------------------------------*
 **                         MACRO DEFINITION                                 *
 **--------------------------------------------------------------------------*/
#define uint8 unsigned char
#define uint16 unsigned int

#define SNAKE_MIN_LEN 5
#define SNAKE_MAX_LEN 600
#define WIDTH 32
#define HEIGHT 24
#define S_TIME 350

#define QUIT 0
#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif
#define OVER 2

#define CALTIME(x) (S_TIME-(x)*22)
/**--------------------------------------------------------------------------*
 **                         TYPE AND STRUCT                                *
 **--------------------------------------------------------------------------*/
enum SNAKE_DIR{
	U,
	D,
	L,
	R
};//snake direction

struct COORDINATE{
	uint8 x;
	uint8 y;
};

struct SNAKE{
	uint8 length;
	struct COORDINATE body[SNAKE_MAX_LEN];
	enum SNAKE_DIR direction;
};
	
/**--------------------------------------------------------------------------*
 **                         EXTERNAL DECLARE                                 *
 **--------------------------------------------------------------------------*/
 
/**--------------------------------------------------------------------------*
 **                         STATIC DEFINITION                                *
 **--------------------------------------------------------------------------*/
 
/**--------------------------------------------------------------------------*
 **                         GLOBAL DEFINITION                                *
 **--------------------------------------------------------------------------*/
struct COORDINATE food;
/*---------------------------------------------------------------------------*/
/*                          LOCAL FUNCTION DECLARE                           */
/*---------------------------------------------------------------------------*/
uint8 Menu();//display menu
uint8 SetDifficulty(uint8 *diff);//set difficulty
void	DrawWall();
void	DrawSnake(struct SNAKE *snake);
void	DrawFood();
uint8 ShowOver(uint16 *score);
void ShowPause ();//show pause interface
void InitSnake(struct SNAKE *snake);//init snake's length
uint8 InitFood (struct SNAKE *snake);
uint8 InSnake (struct SNAKE *snake, uint8 x, uint8 y);
uint8 MoveSnake (struct SNAKE *snake);
uint8 IsOver(struct SNAKE *snake, uint8 x, uint8 y);

/**--------------------------------------------------------------------------*
 **                         FUNCTION DEFINITION                              *
 **--------------------------------------------------------------------------*/
 
 /**--------------------------------------------------------------------------*
Name:		Menu
Discribe:		menu interface
Return:		diff , QUIT
 **--------------------------------------------------------------------------*/
uint8 Menu()//这里是菜单选择的界面
{
	uint8 choose = 1, ischoose = 1;
	uint8 diff = 1,i;
//display menu interface
	system("cls");//clear screen首先清屏
	printf("************************************************\n");
	printf("    Start game.\n");
	printf("    Choose Difficulty.\n");
	printf("    Quit.\n");
	printf(" \n Warning:Please select English input method.");
	printf("\n\n");
	printf("    Welcome to join QQ group:31066229\n");
	printf("************************************************\n");	
	do{	
		for(i=1;i<=3;i++){
			gotoTextPos(2,i);//光标移到(2,i)处
			if(i==choose)
				printf("%c",16);//这里显示的是选择的三角
			else
				printf(" ");
		}
		//get keydown
		switch(jkGetKey()){
			//获取键盘按键，方向键只能通过扫描码获取
			case JK_UP:
				if (choose>1)
					choose --;
				break;
			case JK_DOWN:
				if (choose<3)
					choose ++;
				break;
			case JK_ENTER:
				ischoose = 0;
				break;
			default:;
		}
	}while (ischoose);
	switch (choose){
		case 2:
			SetDifficulty(&diff);//选择难度的界面
		case 1:
			return diff;
		case 3:
			return QUIT;
	}
}

 /**--------------------------------------------------------------------------*
Name:		SetDifficulty
Discribe:		choose difficulty interface
Return:		0
 **--------------------------------------------------------------------------*/
uint8 SetDifficulty(uint8 *diff)//显示选择难度的界面
{
	assert (NULL != diff);
	system("cls");//to show set difficulty level interface
	gotoTextPos(0,HEIGHT/2-4);
	printf("                     %c\n\n",30);//显示正三角
	printf("                     %c\n",31);//显示倒三角
	printf("\nPlease press UP or DOWN to choose difficulty level.");
	while (1)
	{		
		gotoTextPos(0,HEIGHT/2-3);
		printf("Difficulty level:    %d",*diff);
		
		switch(jkGetKey()){
			//获取按键信息并选择难度
			case JK_UP:
				if (*diff > 1)
					(*diff) --;
				break;
			case JK_DOWN:
				if (*diff < 9)
					(*diff) ++;
				break;
			case JK_ENTER:
				return 0;
			default:;
		}
	}
}

 /**--------------------------------------------------------------------------*
Name:		InitSnake
Discribe:		Initialize length, coordinate and direction;
Return:		
 **--------------------------------------------------------------------------*/
void InitSnake(struct SNAKE *snake)//初始化蛇的位置长度方向
{
	uint8 i = 0;
	assert (NULL!=snake);
	snake->length = SNAKE_MIN_LEN;//初始化长度
	snake->direction = R;//初始化方向
	for (;i<SNAKE_MIN_LEN;i++){
		//初始化蛇身的坐标
		snake->body[i].x=SNAKE_MIN_LEN-i;
		snake->body[i].y=5;
	}
}
 
 /**--------------------------------------------------------------------------*
Name:		
Discribe:		if in the snake
Return:		TRUE,FALSE
 **--------------------------------------------------------------------------*/
uint8 InSnake(struct SNAKE *snake, uint8 x, uint8 y)//判断某一点是否在蛇身内
 {
 	uint8 i;
	for(i=0;i<snake->length;i++){
		//如果某一点与蛇身某一部分相同，即返回1
		if((x==snake->body[i].x) && (y==snake->body[i].y))
			return 1;
	}
	return 0;
 }
  /**--------------------------------------------------------------------------*
Name:		DrawFood
Discribe:		
Return:		
 **--------------------------------------------------------------------------*/
uint8 InitFood (struct SNAKE *snake)//初始化食物
{
	uint8 i;
	
	srand((unsigned)time(NULL));//初始化随机因子
	do{
		//生成随机数，如果食物与蛇身重叠，就重新生成	
		food.x = rand()%(WIDTH-2)+1;
		food.y = rand()%(HEIGHT-4)+1;
	}while(InSnake(snake,food.x,food.y));
	return 0;//初始化成功后返回
}
 /**--------------------------------------------------------------------------*
Name:		Display
Discribe:		
Return:		
 **--------------------------------------------------------------------------*/
void ShowPause()//显示暂停的界面
{
	int key;

	system("cls");
	setTextColor(RED_ORANGE);
	gotoTextPos(0,HEIGHT/2-6);
	printf("     * * * *        *       *       *  * * * *  * * * * *\n");
	printf("     *       *     * *      *       * *         *        \n");
	printf("     *       *    *   *     *       * *         *        \n");
	printf("     * * * *     * * * *    *       *  * * * *  * * * * *\n");
	printf("     *          *       *   *       *         * *        \n");		
	printf("     *         *         *   *     *          * *        \n");
	printf("     *        *           *   * * *    * * * *  * * * * *\n");
	setTextColor(WHITE);
	printf("\n\n                Please press ENTER to continue.");
	while(key=jkGetKey()){
		//只当按下回车键时退出循环返回游戏
		if(key==JK_ENTER)
			break;
	}
 }
		
  /**--------------------------------------------------------------------------*
Name:		MoveSnake
Discribe:		
Return:		nofood
 **--------------------------------------------------------------------------*/			
uint8 MoveSnake(struct SNAKE *snake)
 {
 	assert(NULL!=snake);
 	uint8 i, nofood=0;
	uint8 x=snake->body[0].x, y=snake->body[0].y;//蛇头坐标
	uint8 lx=snake->body[snake->length-1].x,ly=snake->body[snake->length-1].y;//蛇尾坐标
	switch (snake->direction){
		case U: y-=1;break;
		case D: y+=1;break;//如果方向向上，y坐标-1，否则+1
		case L: x -=1;break;
		case R: x+=1;break;
		default:;
	}
	if ((x==food.x) && ( y==food.y)){
		//判断是否吃到食物
		snake->length++;//吃到食物，长度加一
		nofood = TRUE;//没有食物
	}
	for(i=snake->length-1; i>0;i--){
		//蛇头以下的部分移动
		snake->body[i]=snake->body[i-1];
	}
	if(IsOver(snake, x, y))//移到后如果结束，则返回OVER
		return OVER;	
	if(!nofood){
		//如果没有吃到食物，将原来蛇尾擦除
		gotoTextPos(lx*2,ly);//光标定位到原来蛇尾位置
		printf("　");//将它擦除
	}
	snake->body[0].x=x,snake->body[0].y=y;
	DrawSnake(snake);//画出新的蛇
	return nofood;//返回是否有食物或游戏结束
  }
  /**--------------------------------------------------------------------------*
Name:		DrawWall
Discribe:		
Return:		
 **--------------------------------------------------------------------------*/
void DrawWall()//画出四面墙
 {
 	uint8 x=0,y=0;
	setTextColor(RED);//设置墙的颜色
	gotoTextPos(0,0);
	for(x=0;x<WIDTH;x++){
		printf("■");
	}
	gotoTextPos(0,HEIGHT-3);
	for(x=0;x<WIDTH;x++){
		printf("■");
	}
	for(y=1;y<HEIGHT-3;y++){
		gotoTextPos(0,y);
		printf("■");
		gotoTextPos(WIDTH*2-2,y);
		printf("■");
	}
}
   /**--------------------------------------------------------------------------*
Name:		DrawSnake
Discribe:		draw snake body
Return:		
 **--------------------------------------------------------------------------*/
 void DrawSnake(struct SNAKE *snake)//画出蛇 的全身
 {
 	uint8 i;

	setTextColor(YELLOW);//设置蛇的颜色
	for(i=0;i<snake->length;i++){
		gotoTextPos(snake->body[i].x*2,snake->body[i].y);
		printf("■");
	}
 }
   /**--------------------------------------------------------------------------*
Name:		DrawFood
Discribe:		
Return:		
 **--------------------------------------------------------------------------*/
void DrawFood()//画出食物
{
	setTextColor(YELLOW);
	gotoTextPos(food.x*2,food.y);
	printf("●");
}
 
    /**--------------------------------------------------------------------------*
Name:		IsOver
Discribe:		
Return:		
 **--------------------------------------------------------------------------*/
 uint8 IsOver(struct SNAKE *snake, uint8 x, uint8 y)
 {//判断是否撞到墙或吃到自己 
 	assert(NULL!=snake);
 	if(0==x ||WIDTH-1==x|| 0==y || HEIGHT-3==y||InSnake(snake, x, y))
		return 1;
	return 0;
  }

    /**--------------------------------------------------------------------------*
Name:		ShowOver
Discribe:		
Return:		
 **--------------------------------------------------------------------------*/
uint8 ShowOver(uint16 *score)//显示结束的界面
{
	uint8 key;
	setTextColor(WHITE);
	gotoTextPos(16,HEIGHT/2-3);
	printf("================================");
	gotoTextPos(16,HEIGHT/2-2);
	printf("           GAME OVER");
	gotoTextPos(16,HEIGHT/2-1);
	printf("================================");
	gotoTextPos(16,HEIGHT/2+1);
	printf("       YOU GOT SCORE: %u",*score);
	sleep(2000);//等待2秒
	gotoTextPos(16,HEIGHT/2-2);
	printf("      给作者留言?(Y/N) [ ]    ");
	do{
		gotoTextPos(40,HEIGHT/2-2);
		key=getche();
	}while('Y'!=key &&'y'!=key&& 'N'!=key&&'n'!=key);
	if ('Y' == key||'y'==key)//如果是，打开浏览器访问该网页
			system ("start http://luoyun2112.blog.163.com/blog/static/120037256201076105728211/");

	do{
		//询问是否重玩
		gotoTextPos(16,HEIGHT/2-2);
		printf("        Replay?(Y/N) [ ]    ");
		do{
			gotoTextPos(38,HEIGHT/2-2);
			key=getche();
		}while('Y'!=key && 'N'!=key);
	}while('\r'!=getch());
	*score=0;
	return key;
}
	
int main (void)
{
	uint8 level=0,diff,nofood=1,pause=0;
	uint16 score = 0;
	struct SNAKE snake ={5,{0,0},R};//赋与初值,初始化变量
	
	fixConsoleSize(WIDTH*2,HEIGHT);//设置窗口大小
	setCursorVisible(FALSE);//设置光标宽度为零，即不显示光标
	setConsoleTitle("Snake 贪吃蛇QQ group:31066229");//设置窗口标题
	
Play:	diff= Menu();//首先显示菜单
	if (!diff)//如果返回零，退出游戏
		return 0;
	system("cls");//清屏以显示游戏界面
	InitSnake(&snake);//初始化蛇
	nofood = InitFood(&snake);//初始化食物
	DrawFood();//画出食物
	DrawWall();//画出围墙
	DrawSnake(&snake);//画出蛇
	do{
		if(pause){
			//如果暂停
			ShowPause();//显示暂停界面
			pause = 0;//当从暂停界面退出时，pause赋为0，表示没有暂停
			system("cls");//将暂停界面清屏
			DrawFood();//画出食物
			DrawWall();//画出围墙
			DrawSnake(&snake);//画出蛇
        }
		if (nofood){
			// had eaten food如果吃到了食物
			nofood = InitFood(&snake);//重新初始化食物
			score +=50;//加分
			DrawFood();//再画出食物
		}
		if(level<=12)//calculate level如果不大于12级
			level=diff+(snake.length-5)/10;//计算等级
		setTextColor(GREY);//设置文本颜色
		gotoTextPos(0,HEIGHT-1);//光标定位，并输出分数
		printf("score:%u",score);
		gotoTextPos(WIDTH,HEIGHT-1);//光标定位，并输出等级
		printf("level:%u",level);
		sleep(CALTIME(level));//snake's vilocity,暂停一段时间，这里是蛇的运动速度
		if (jkHasKey()){
			//扫描是否有按键按下
			switch(jkGetKey()){
				//如果有，看是什么键
				case JK_UP://上方向键时
					if(snake.direction != D)//如果蛇不向下运动，蛇运动方向为上
						snake.direction = U; break;
				case JK_DOWN:
					if(snake.direction!=U)//同上
						snake.direction = D; break;
				case JK_LEFT:
					if(snake.direction!=R)
						snake.direction = L; break;
				case JK_RIGHT:
					if(snake.direction!= L)
						snake.direction = R; break;
				case JK_ENTER: pause = 1;//按回车表示暂停
				default: ;//其它按键忽略
			}
		}
		nofood= MoveSnake(&snake);//移到蛇，并返回是否吃到食物或游戏结束
	}while(OVER!=nofood);
	if('Y'==ShowOver(&score))//显示游戏结束的界面
		goto Play;//goto语句不宜太多，此处仅因重玩功能属临时加上而作者又太懒

	return 0;
}
