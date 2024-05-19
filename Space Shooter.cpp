#include<graphics.h>
#include <stdlib.h>
#include<iostream>
using namespace std;



level_ex()
{

	srand(8);
	initwindow(600, 600);
	int x1 = 270, x2 = 330, y1 = 570, y2 = 590;

	int bullet = 0;
	int bullet_x;
	double bullet_y;
	int enemy_x[12];
	for (int a = 0; a < 12; a++)
	{
		do
		{
			enemy_x[a] = rand() % 570 + 30;	//rand use to randomly choose the position of the enemy
		} while (enemy_x[a] % 33 != 0);
	}
	double enemy_y1 = 20;
	double enemy_y2 = 20;
	int rad[12] = { 15, 15, 15, 15,15,15 ,15, 15, 15, 15,15,15 }; // radius of alliens
	double down = 0;
	int counter = 0;
	while (1)
	{


		setcolor(GREEN);
		rectangle(x1, y1, x2, y2);

		if (GetAsyncKeyState(VK_UP))//for upward movement of spceship
		{
			y1 -= 5;
			y2 -= 5;

		}
		if (GetAsyncKeyState(VK_DOWN))//for down movement of spceship
		{
			y1 += 5;
			y2 += 5;
		}
		if (GetAsyncKeyState(VK_RIGHT))//for right movement of spceship
		{
			x1 += 5;
			x2 += 5;

		}
		if (GetAsyncKeyState(VK_LEFT))//for left movement of spceship
		{
			x1 -= 5;
			x2 -= 5;

		}
		if (GetAsyncKeyState(VK_SPACE) && bullet == 0)
		{
			bullet_x = x1;
			bullet_y = y1;  //new bullets issue because of same variable used as it will be//
			bullet = 1;

		}
		if (bullet == 1)
		{
			setcolor(YELLOW);
			circle(bullet_x, bullet_y, 5); // for creating bullet 
			bullet_y -= 10;
		}
		if (bullet_y <= 0)
		{
			bullet = 0;     //for eliIMINATING BULLET
			bullet_y = y1;
		}
		for (int i = 0; i < 6; i++)
		{
			if (bullet_y <= (enemy_y1 + (down)) && bullet_x >= enemy_x[i] - 15 && bullet_x <= enemy_x[i] + 15)
			{
				rad[i] = 0;
				bullet = 0;    //bullet reset and allien remove
				bullet_y = y1;
			}
		}

		if (counter % 20 == 0)
		{
			for (int i = 6; i < 12; i++)
			{
				setcolor(BLUE);
				circle(enemy_x[i], enemy_y2 + down, rad[i]); // allien register
			}
		}

	
		for (int i = 0; i < 6; i++)
		{
			setcolor(RED);
			circle(enemy_x[i], enemy_y1 + down, rad[i]); // allien register
		}

		down += 0.25;
		delay(10);
		cleardevice();
		counter++;
	}
	getch();
}

int main()
{
	level_ex();



	system("pause");
	return 0;
}





