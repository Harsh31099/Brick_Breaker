#include<stdio.h>
#include<conio.h>
#include<dos.h>
void instructions();
void menu();
void levels();
void score();
void bricks();
void bricks1();
void movingBoardBall();
void winner();
void callingsToPlay();
void callingsToPlay1();
void movingBoardBallGreater1(int tillBallPaint);
void movingBoardBallGreater2(int tillBallPaint);
void movingBoardBallSmaller1(int tillBallPaint);
void movingBoardBallSmaller2(int tillBallPaint);
void bricksBreak(int *array,int offset,int brickNumber);
void horizontalLine(int left,int top,int endPoint,char characterUsed,int colourUsed);
void verticalLine(int left,int top,int endPoint,char characterUsed,int colourUsed);
void rectangle(int left,int top,int endPointHorizontal,int endPointVertical,int colourUsed);
int getScan(void);
int array[11]={11,17,23,29,35,41,47,53,59,65,71};
int array1[20]={11,14,17,20,23,26,29,32,35,38,41,44,47,50,53,56,59,62,65,68};
int boardLeft=33,boardTop=22,ballLeft=38,ballTop=21,counter=0,data;
void winner()
{
	clrscr();
	rectangle(10,2,71,24,5);
	rectangle(13,3,68,23,5);
	gotoxy(33,6);
	textcolor(3);
	cprintf("BRICK AND BALL");
	gotoxy(32,7);
	textcolor(11);
	cprintf("~~~~~~~~~~~~~~~~");
	rectangle(23,11,57,19,5);
	gotoxy(35,14);
	textcolor(3);
	cprintf("YEAAAH......");
	gotoxy(27,16);
	textcolor(3);
	cprintf("CONGRATS ! YOU WON THE GAME");
	gotoxy(27,21);
	cprintf("PRESS any Key for MENU PAGE .");
	getch();
}
void score()
{
	clrscr();
	rectangle(10,2,71,24,5);
	rectangle(13,3,68,23,5);
	gotoxy(33,6);
	textcolor(3);
	cprintf("BRICK AND BALL");
	gotoxy(32,7);
	textcolor(11);
	cprintf("~~~~~~~~~~~~~~~~");
	rectangle(23,11,57,19,5);
	gotoxy(33,15);
	textcolor(3);
	cprintf("YOUR SCORE : %d",counter);
	gotoxy(27,21);
	cprintf("PRESS any Key for MENU PAGE .");
}
void main()
{
	clrscr();
	_setcursortype(_NOCURSOR);
	menu();
}
void menu()
{
	char ch;
	up: clrscr();
	rectangle(10,2,71,24,5);
	rectangle(13,3,68,23,5);
	gotoxy(33,6);
	textcolor(3);
	cprintf("BRICK AND BALL");
	gotoxy(32,7);
	textcolor(11);
	cprintf("~~~~~~~~~~~~~~~~");
	gotoxy(25,9);
	textcolor(11);
	cprintf("************ MENU *************");
	rectangle(23,11,57,19,5);
	gotoxy(31,13);
	textcolor(11);
	cprintf("-> PREES 1 to PLAY !");
	gotoxy(27,15);
	textcolor(11);
	cprintf("-> PRESS 2 for INSTRUCTIONS !");
	gotoxy(31,17);
	cprintf("-> PRESS 3 to EXIT !");
	gotoxy(27,21);
	cprintf("PLZZzz ! ENTER YOUR CHOICE .");
	while(1)
	{
		if(kbhit())
		{
			ch=getch();
			if(ch=='1')
			{
				levels();
				break;
			}
			else if(ch=='2')
			{
				instructions();
				goto up;
			}
			else if(ch=='3')return;
		}
	}
	boardLeft=33;boardTop=22;ballLeft=38;ballTop=21;counter=0;
	menu();
}
void levels()
{
	char ch;
	clrscr();
	rectangle(10,2,71,24,5);
	rectangle(13,3,68,23,5);
	gotoxy(33,6);
	textcolor(3);
	cprintf("BRICK AND BALL");
	gotoxy(32,7);
	textcolor(11);
	cprintf("~~~~~~~~~~~~~~~~");
	gotoxy(25,9);
	textcolor(11);
	cprintf("************ MENU *************");
	rectangle(23,11,57,19,5);
	gotoxy(27,13);
	textcolor(11);
	cprintf("-> PREES 1 for LEVEL 1 !");
	gotoxy(27,15);
	textcolor(11);
	cprintf("-> PRESS 2 for LEVEL 2 !");
	gotoxy(27,17);
	cprintf("-> PRESS 3 to BACK !");
	gotoxy(27,21);
	cprintf("PLZZzz ! ENTER YOUR CHOICE .");
	while(1)
	{
		if(kbhit())
		{
			ch=getch();
			if(ch=='1')
			{
				bricks();
				break;
			}
			else if(ch=='2')
			{
				bricks1();
				break;
			}
			else if(ch=='3')return;
		}
	}
}
void instructions()
{
	clrscr();
	rectangle(10,2,71,24,5);
	rectangle(13,3,68,23,5);
	gotoxy(34,5);
	textcolor(11);
	cprintf("INSTRUCTIONS");
	gotoxy(32,6);
	textcolor(11);
	cprintf("~~~~~~~~~~~~~~~~");
	rectangle(15,8,66,19,5);
	gotoxy(17,10);
	textcolor(12);
	cprintf("-> You have to break BRICKS,Each Brick gives You");
	gotoxy(17,11);
	textcolor(12);
	cprintf("a POINT . DIRECTION of BALL will adjust using");
	gotoxy(17,12);
	textcolor(12);
	cprintf("moving BOARD .");
	gotoxy(17,13);
	textcolor(12);
	cprintf("-> DIRECTION of BOARDS will Set using RIGHT/LEFT");
	gotoxy(17,14);
	textcolor(12);
	cprintf("KEY . ");
	gotoxy(17,15);
	textcolor(12);
	cprintf("-> If your BALL crosses moving BOARD downwards");
	gotoxy(17,16);
	textcolor(12);
	cprintf("that time you will OUT !");
	gotoxy(17,17);
	textcolor(12);
	cprintf("-> PRESS SPACE BAR KEY to PAUSE the GAME . ");
	gotoxy(31,21);
	textcolor(11);
	cprintf("PRESS '1' to  BACK !");
	while(1)
	{
		if(kbhit())
		{
			if(getch()=='1')return;
		}
	}
}
void bricks()
{
	clrscr();
	rectangle(10,2,71,24,4);

	rectangle(11,3,16,4,10);       //brick1
	rectangle(17,3,22,4,9);       //brick2
	rectangle(23,3,28,4,3);       //brick3
	rectangle(29,3,34,4,8);       //brick4
	rectangle(35,3,40,4,5);       //brick5          //line1
	rectangle(41,3,46,4,6);       //brick6
	rectangle(47,3,52,4,12);       //brick7
	rectangle(53,3,58,4,2);       //brick8
	rectangle(59,3,64,4,9);       //brick9
	rectangle(65,3,70,4,12);       //brick10

	rectangle(11,5,16,6,11);       //brick1
	rectangle(17,5,22,6,12);       //brick2
	rectangle(23,5,28,6,13);       //brick3
	rectangle(29,5,34,6,14);       //brick4
	rectangle(35,5,40,6,15);       //brick5          //line2
	rectangle(41,5,46,6,1);       //brick6
	rectangle(47,5,52,6,5);       //brick7
	rectangle(53,5,58,6,8);       //brick8
	rectangle(59,5,64,6,9);       //brick9
	rectangle(65,5,70,6,10);       //brick10

	rectangle(11,7,16,8,6);       //brick1
	rectangle(17,7,22,8,4);       //brick2
	rectangle(23,7,28,8,2);       //brick3
	rectangle(29,7,34,8,8);       //brick4
	rectangle(35,7,40,8,12);       //brick5          //line3
	rectangle(41,7,46,8,11);       //brick6
	rectangle(47,7,52,8,1);       //brick7
	rectangle(53,7,58,8,15);       //brick8
	rectangle(59,7,64,8,7);       //brick9
	rectangle(65,7,70,8,14);       //brick10


	rectangle(11,9,16,10,10);       //brick1
	rectangle(17,9,22,10,1);       //brick2
	rectangle(23,9,28,10,5);       //brick3
	rectangle(29,9,34,10,8);       //brick4
	rectangle(35,9,40,10,3);       //brick5          //line4
	rectangle(41,9,46,10,7);       //brick6
	rectangle(47,9,52,10,6);       //brick7
	rectangle(53,9,58,10,4);       //brick8
	rectangle(59,9,64,10,13);       //brick9
	rectangle(65,9,70,10,8);       //brick10
	callingsToPlay();
	clrscr();
	score();
	getch();
}
void bricks1()
{
	clrscr();
	rectangle(10,2,71,24,4);

	rectangle(11,3,13,4,4);
	rectangle(11,5,13,6,1);
	rectangle(11,7,13,8,2);
	rectangle(11,9,13,10,3);
	rectangle(11,11,13,12,5);

	rectangle(17,3,19,4,6);
	rectangle(17,5,19,6,7);
	rectangle(17,7,19,8,8);
	rectangle(17,9,19,10,9);
	rectangle(17,11,19,12,10);

	rectangle(23,3,25,4,1);
	rectangle(23,5,25,6,2);
	rectangle(23,7,25,8,4);
	rectangle(23,9,25,10,6);

	rectangle(29,3,31,4,11);
	rectangle(29,5,31,6,12);
	rectangle(29,7,31,8,14);

	rectangle(35,3,37,4,8);
	rectangle(35,5,37,6,9);
	rectangle(35,7,37,8,12);
	rectangle(35,9,37,10,13);
	rectangle(35,11,37,12,5);

	rectangle(41,3,43,4,4);
	rectangle(41,5,43,6,1);

	rectangle(47,3,49,4,14);
	rectangle(47,5,49,6,1);
	rectangle(47,7,49,8,8);
	rectangle(47,9,49,10,13);
	rectangle(47,11,49,12,5);

	rectangle(53,3,55,4,1);
	rectangle(53,5,55,6,2);
	rectangle(53,7,55,8,4);

	rectangle(59,3,61,4,11);
	rectangle(59,5,61,6,2);
	rectangle(59,7,61,8,8);
	rectangle(59,9,61,10,6);

	rectangle(65,3,67,4,6);
	rectangle(65,5,67,6,7);
	rectangle(65,7,67,8,8);
	rectangle(65,9,67,10,9);
	rectangle(65,11,67,12,10);
	callingsToPlay1();
	clrscr();
	score();
	getch();
}
void callingsToPlay1()
{
	boardLeft=33;boardTop=22;ballLeft=38;ballTop=21;counter=0;
	gotoxy(ballLeft,ballTop);
	printf("@");
	gotoxy(boardLeft,boardTop);
	printf("***********");
	gotoxy(75,4);
	textcolor(4);
	cprintf("SCORE:");
	gotoxy(77,6);
	cprintf("0");
	while(1)
	{
		gotoxy(23,16);
		printf("PRESS ENTER KEY to PLAY the GAME !");
		gotoxy(23,16);
		printf("                                  ");
		if(kbhit())
		{
			data=getScan();
			break;
		}
	}
	if(data==28)
	{
		movingBoardBallGreater2(9);
		rectangle(23,9,25,10,15);
		movingBoardBallGreater1(7);
		rectangle(29,7,31,8,15);
		movingBoardBallGreater2(5);
		rectangle(23,5,25,6,15);
		movingBoardBallGreater1(3);
		rectangle(29,3,31,4,15);
		bricksBreak(array1,6,4);
		movingBoardBallSmaller1(4);
		rectangle(29,5,31,6,15);
		movingBoardBallSmaller2(7);
		rectangle(23,7,25,8,15);
		movingBoardBallSmaller1(21);
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(13);
			rectangle(47,11,49,12,15);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(13);
			rectangle(65,11,67,12,15);
			movingBoardBallSmaller1(19);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(9);
			rectangle(53,7,55,8,15);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(13);
			rectangle(35,11,37,12,15);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(13);
			rectangle(17,11,19,12,15);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(10);
			bricksBreak(array1,4,10);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(9);
			rectangle(47,9,49,10,15);
			movingBoardBallGreater2(7);
			rectangle(41,5,43,6,15);
			movingBoardBallSmaller2(11);
			bricksBreak(array1,8,12);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(11);
			rectangle(59,9,61,10,15);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(11);
			bricksBreak(array1,16,10);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(9);
			rectangle(35,9,37,10,15);
			movingBoardBallGreater1(6);
			bricksBreak(array1,10,6);
			movingBoardBallSmaller1(11);
			bricksBreak(array1,12,12);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(9);
			bricksBreak(array1,4,8);
			movingBoardBallSmaller2(12);
			bricksBreak(array1,2,12);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(5);
			rectangle(47,3,49,4,15);
			rectangle(47,5,49,6,15);
			movingBoardBallGreater2(3);
			rectangle(41,3,43,4,15);
			movingBoardBallSmaller1(4);
			bricksBreak(array1,12,4);
			bricksBreak(array1,12,6);
			movingBoardBallSmaller2(10);
			bricksBreak(array1,8,10);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(7);
			rectangle(65,7,67,8,15);
			movingBoardBallGreater2(5);
			rectangle(59,5,61,6,15);
			movingBoardBallGreater1(3);
			rectangle(65,3,67,4,15);
			movingBoardBallSmaller2(5);
			bricksBreak(array1,16,6);
			movingBoardBallSmaller1(7);
			bricksBreak(array1,18,8);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(9);
			rectangle(35,7,37,8,15);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(9);
			rectangle(11,9,13,10,15);
			movingBoardBallGreater1(7);
			rectangle(17,7,19,8,15);
			movingBoardBallGreater2(5);
			rectangle(11,5,13,6,15);
			movingBoardBallGreater1(3);
			rectangle(17,3,19,4,15);
			movingBoardBallSmaller2(5);
			bricksBreak(array1,0,6);
			movingBoardBallSmaller1(7);
			bricksBreak(array1,2,8);
			movingBoardBallSmaller2(9);
			bricksBreak(array1,0,10);
			movingBoardBallSmaller1(10);
			rectangle(17,9,19,10,15);
			movingBoardBallSmaller2(11);
			rectangle(11,11,13,12,15);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(9);
			bricksBreak(array1,8,8);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(9);
			rectangle(59,7,61,8,15);
			movingBoardBallSmaller1(12);
			bricksBreak(array1,18,12);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(5);
			rectangle(35,3,37,4,15);
			rectangle(35,5,37,6,15);
			movingBoardBallGreater1(3);
			bricksBreak(array1,10,4);
			movingBoardBallSmaller2(5);
			bricksBreak(array1,8,6);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(11);
			rectangle(65,9,67,10,15);
			movingBoardBallGreater2(9);
			bricksBreak(array1,16,8);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(3);
			movingBoardBallSmaller2(4);
			bricksBreak(array1,6,6);
			movingBoardBallGreater2(3);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(3);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(5);
			bricksBreak(array1,18,6);
			bricksBreak(array1,18,4);
			movingBoardBallGreater2(3);
			rectangle(59,3,61,4,15);
			movingBoardBallSmaller1(8);
			bricksBreak(array1,18,10);
			movingBoardBallGreater1(5);
			movingBoardBallGreater2(3);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(4);
			bricksBreak(array1,8,4);
			movingBoardBallSmaller2(6);
			bricksBreak(array1,6,8);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(5);
			bricksBreak(array1,16,4);
			movingBoardBallSmaller1(12);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(11);
			bricksBreak(array1,12,10);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(7);
			bricksBreak(array1,4,6);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(3);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(3);
			movingBoardBallSmaller1(7);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(3);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(13);
			bricksBreak(array1,0,12);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(3);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(7);
			movingBoardBallGreater2(3);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(3);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(3);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(3);
			movingBoardBallSmaller1(6);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(3);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(14);
			movingBoardBallGreater1(9);
			bricksBreak(array1,2,10);
			movingBoardBallGreater2(7);
			rectangle(11,7,13,8,15);
			movingBoardBallGreater1(5);
			bricksBreak(array1,2,6);
			movingBoardBallGreater2(4);
			rectangle(11,3,13,4,15);
			movingBoardBallGreater1(3);
			bricksBreak(array1,2,4);
			movingBoardBallSmaller2(4);
			bricksBreak(array1,0,4);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(3);
			movingBoardBallSmaller1(5);
			rectangle(53,3,55,4,15);
			rectangle(53,5,55,6,15);
			movingBoardBallSmaller2(7);
			bricksBreak(array1,12,8);
			movingBoardBallSmaller1(8);
			bricksBreak(array1,12,8);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(5);
			rectangle(23,3,25,4,15);
			movingBoardBallSmaller2(15);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(3);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(6);
			movingBoardBallGreater2(3);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(3);
			movingBoardBallSmaller2(5);
			bricksBreak(array1,4,4);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(9);
			bricksBreak(array1,14,8);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(7);
			bricksBreak(array1,14,6);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(3);
			movingBoardBallSmaller2(8);
			bricksBreak(array1,0,8);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(3);
			gotoxy(ballTop,ballLeft);
			movingBoardBallSmaller1(5);
			bricksBreak(array1,14,4);
		}
		else return;
	}
	counter+=100;
	winner();
}
void callingsToPlay()
{
	gotoxy(ballLeft,ballTop);
	printf("@");
	gotoxy(boardLeft,boardTop);
	printf("***********");
	gotoxy(75,4);
	textcolor(4);
	cprintf("SCORE:");
	gotoxy(77,6);
	cprintf("0");
	while(1)
	{
		gotoxy(23,16);
		printf("PRESS ENTER KEY to PLAY the GAME !");
		gotoxy(23,16);
		printf("                                  ");
		if(kbhit())
		{
			data=getScan();
			break;
		}
	}
	if(data==28)
	{
		movingBoardBallGreater1(10);
		bricksBreak(array,6,10);
		movingBoardBallSmaller1(21);
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(11);
			movingBoardBallGreater2(10);
			bricksBreak(array,9,10);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(10);
			bricksBreak(array,5,10);
			movingBoardBallGreater1(8);
			bricksBreak(array,6,8);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(13);
			movingBoardBallGreater2(8);
			bricksBreak(array,9,8);
			bricksBreak(array,8,8);
			movingBoardBallSmaller2(9);
			bricksBreak(array,8,10);
			movingBoardBallGreater1(6);
			bricksBreak(array,9,6);
			movingBoardBallSmaller1(9);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(8);
			bricksBreak(array,5,8);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(10);
			bricksBreak(array,1,10);
			movingBoardBallSmaller2(20);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(10);
			bricksBreak(array,2,10);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(6);
			bricksBreak(array,6,6);
			movingBoardBallSmaller1(10);
			bricksBreak(array,7,10);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(10);
			bricksBreak(array,3,10);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(12);
			movingBoardBallGreater1(10);
			bricksBreak(array,0,10);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(10);
			bricksBreak(array,4,10);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(6);
			bricksBreak(array,8,6);
			movingBoardBallSmaller1(15);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(4);
			bricksBreak(array,6,4);
			bricksBreak(array,5,4);
			movingBoardBallSmaller2(5);
			bricksBreak(array,5,6);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(13);
			movingBoardBallGreater2(4);
			bricksBreak(array,8,4);
			movingBoardBallSmaller2(7);
			bricksBreak(array,7,8);
			movingBoardBallGreater2(6);
			bricksBreak(array,7,6);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(8);
			bricksBreak(array,2,8);
			bricksBreak(array,3,8);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(16);
			movingBoardBallGreater1(8);
			bricksBreak(array,1,8);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(3);
			movingBoardBallSmaller1(4);
			bricksBreak(array,7,4);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(6);
			bricksBreak(array,1,6);
			movingBoardBallSmaller2(14);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(6);
			bricksBreak(array,3,6);
			bricksBreak(array,4,8);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(14);
			movingBoardBallGreater1(4);
			bricksBreak(array,1,4);
			movingBoardBallSmaller1(5);
			bricksBreak(array,2,6);
			movingBoardBallSmaller2(15);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(4);
			bricksBreak(array,4,4);
			movingBoardBallSmaller1(5);
			bricksBreak(array,4,6);
			movingBoardBallGreater2(4);
			bricksBreak(array,3,4);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(14);
			movingBoardBallGreater1(3);
			bricksBreak(array,2,4);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(3);
			movingBoardBallSmaller1(14);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(3);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(8);
			bricksBreak(array,0,8);
			movingBoardBallSmaller2(10);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(3);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(9);
			movingBoardBallGreater2(4);
			bricksBreak(array,9,4);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(3);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(3);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(3);
			movingBoardBallSmaller1(5);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(3);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(17);
			movingBoardBallGreater1(3);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(3);
			movingBoardBallSmaller1(10);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(3);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(11);
			movingBoardBallGreater1(6);
			bricksBreak(array,0,6);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(3);
			movingBoardBallSmaller1(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater1(20);
			movingBoardBallGreater2(3);
			movingBoardBallSmaller2(21);
		}
		else return;
		if(ballLeft>=boardLeft&&boardLeft+10>=ballLeft)
		{
			movingBoardBallGreater2(4);
			bricksBreak(array,0,4);
			clrscr();
			winner();
		}
		else return;
	}
	else return;
}
void movingBoardBallGreater1(int tillBallPaint)
{
	while(ballTop>tillBallPaint)
	{
		gotoxy(ballLeft,ballTop);
		printf(" ");
		gotoxy(++ballLeft,--ballTop);
		printf("@");
		delay(80);
		if(kbhit())
		{
			data=getScan();
			if(data==77 || data==75)
			{
				gotoxy(boardLeft,boardTop);
				printf("           ");
				switch(data)
				{
					case 77:
					if(boardLeft>59)boardLeft-=3;
					else boardLeft+=3;
					break;
					case 75:
					if(boardLeft<15)boardLeft+=3;
					else boardLeft-=3;
					break;
				}
				gotoxy(boardLeft,boardTop);
				printf("***********");
				data=0;
			}
			else if(data == 79)
			{
				while(1)
				{
					gotoxy(23,16);
					printf("PRESS ENTER KEY to PLAY the GAME !");
					gotoxy(23,16);
					printf("                                  ");
					if(kbhit())
					{
						data=getScan();
						if(data==28) break;
					}
				}
			}
		}
	}
}
void movingBoardBallGreater2(int tillBallPaint)
{
	while(ballTop>tillBallPaint)
	{
		gotoxy(ballLeft,ballTop);
		printf(" ");
		gotoxy(--ballLeft,--ballTop);
		printf("@");
		delay(80);
		if(kbhit())
		{
			data=getScan();
			if(data==77 || data==75)
			{
				gotoxy(boardLeft,boardTop);
				printf("           ");
				switch(data)
				{
					case 77:
					if(boardLeft>59)boardLeft-=3;
					else boardLeft+=3;
					break;
					case 75:
					if(boardLeft<15)boardLeft+=3;
					else boardLeft-=3;
					break;
				}
				gotoxy(boardLeft,boardTop);
				printf("***********");
				data=0;
			}
			else if(data == 79)
			{
				while(1)
				{
					gotoxy(23,16);
					printf("PRESS ENTER KEY to PLAY the GAME !");
					gotoxy(23,16);
					printf("                                  ");
					if(kbhit())
					{
						data=getScan();
						if(data==28) break;
					}
				}
			}
		}
	}
}
void movingBoardBallSmaller1(int tillBallPaint)
{
	while(ballTop<tillBallPaint)
	{
		gotoxy(ballLeft,ballTop);
		printf(" ");
		gotoxy(++ballLeft,++ballTop);
		printf("@");
		delay(80);
		if(kbhit())
		{
			data=getScan();
			if(data==77 || data==75)
			{
				gotoxy(boardLeft,boardTop);
				printf("           ");
				switch(data)
				{
					case 77:
					if(boardLeft>59)boardLeft-=3;
					else boardLeft+=3;
					break;
					case 75:
					if(boardLeft<15)boardLeft+=3;
					else boardLeft-=3;
					break;
				 }
					gotoxy(boardLeft,boardTop);
					printf("***********");
					data=0;
			}
			else if(data==79)
			{
				while(1)
				{
					gotoxy(23,16);
					printf("PRESS ENTER KEY to PLAY the GAME !");
					gotoxy(23,16);
					printf("                                  ");
					if(kbhit())
					{
						data=getScan();
						if(data==28) break;
					}
				}
			}
		}
	}
}
void movingBoardBallSmaller2(int tillBallPaint)
{
	while(ballTop<tillBallPaint)
	{
		gotoxy(ballLeft,ballTop);
		printf(" ");
		gotoxy(--ballLeft,++ballTop);
		printf("@");
		delay(80);
		if(kbhit())
		{
			data=getScan();
			if(data==77 || data==75)
			{
				gotoxy(boardLeft,boardTop);
				printf("           ");
				switch(data)
				{
					case 77:
					if(boardLeft>59)boardLeft-=3;
					else boardLeft+=3;
					break;
					case 75:
					if(boardLeft<15)boardLeft+=3;
					else boardLeft-=3;
					break;
				 }
					gotoxy(boardLeft,boardTop);
					printf("***********");
					data=0;
			}
			else if(data==79)
			{
				while(1)
				{
					gotoxy(23,16);
					printf("PRESS ENTER KEY to PLAY the GAME !");
					gotoxy(23,16);
					printf("                                  ");
					if(kbhit())
					{
						data=getScan();
						if(data==28) break;
					}
				}
			}
		}
	}
}
void bricksBreak(int *array,int offset,int brickNumber)
{
	int temp=array[offset];
	while(array[offset]<array[offset+1])
	{
		gotoxy(array[offset],brickNumber);
		printf(" ");
		counter++;
		gotoxy(array[offset]++,brickNumber-1);
		printf(" ");
		counter++;
	}
	array[offset]=temp;
	gotoxy(76,6);
	printf("    ");
	gotoxy(76,6);
	textcolor(4);
	cprintf("%d",counter);
	array[offset]=temp;
}
void horizontalLine(int left,int top,int endPoint,char characterUsed,int colourUsed)
{
	while(left<endPoint)
	{
		gotoxy(left++,top);
		textcolor(colourUsed);
		cprintf("%c",characterUsed);
	}
}
void verticalLine(int left,int top,int endPoint,char characterUsed,int colourUsed)
{
	while(top<endPoint)
	{
		gotoxy(left,top++);
		textcolor(colourUsed);
		cprintf("%c",characterUsed);
	}
}
void rectangle(int left,int top,int endPointHorizontal,int endPointVertical,int colourUsed)
{
	verticalLine(left,top,endPointVertical,179,colourUsed);             //line 1
	verticalLine(endPointHorizontal,top,endPointVertical,179,colourUsed);       //line 2

	horizontalLine(left,top,endPointHorizontal,196,colourUsed);    	//line1
	horizontalLine(left,endPointVertical,endPointHorizontal,196,colourUsed);	//line2

	gotoxy(left,top);							   //topLeft
	textcolor(colourUsed);
	cprintf("%c",218);

	gotoxy(endPointHorizontal,top);               //topRight
	textcolor(colourUsed);
	cprintf("%c",191);

	gotoxy(left,endPointVertical);
	textcolor(colourUsed);			  //bottomLeft
	cprintf("%c",192);

	gotoxy(endPointHorizontal,endPointVertical);	//bottomRight
	textcolor(colourUsed);
	cprintf("%c",217);
}
int getScan(void)
{
	union REGS i,o;
	i.h.ah=0;
	int86(0x16,&i,&o);
	return(o.h.ah);
}
