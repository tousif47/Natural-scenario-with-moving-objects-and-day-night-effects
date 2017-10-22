#include <stdio.h>
#include <iostream>
#include <glut.h>
#include <math.h>

using namespace std;

int n = 0;
int w = 0;

int boatstatus = 0;
int planestatus = 0;
int cloudStatus = 1;

float boatX = 0;
float boatY = 0;

float planeX = 0;
float planeY = 0;

float cloudX = 0;
float cloudY = 0;

void DrawCircle(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < num_segments; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle 

		float x = r * cosf(theta);//calculate x 
		float y = r * sinf(theta);//calculate y 

		glVertex2f(x + cx, y + cy);//output vertex 
	}
	glEnd();
}

void tree()
{
	if(n==0)
	{
		//Tree body dark
		glBegin(GL_POLYGON);
		glColor3f(.616, .333, .208);
		glVertex2i(1490 - 22, 505 - 50);
		glVertex2i(1500 - 22, 500 - 50);
		glVertex2i(1500 - 22, 400 - 50);
		glVertex2i(1495 - 22, 350 - 50);
		glVertex2i(1490 - 22, 200 - 50);
		glVertex2i(1480 - 22, 50);

		glVertex2i(1530 + 2, 50);
		glVertex2i(1520 + 2, 200 - 50);
		glVertex2i(1515 + 2, 350 - 50);
		glVertex2i(1510 + 2, 400 - 50);
		glVertex2i(1510 + 2, 500 - 50);
		glVertex2i(1520 + 2, 505 - 50);
		glEnd();

		//Tree body
		glBegin(GL_POLYGON);
		glColor3f(.8, .537, .365);
		glVertex2i(1490 - 20, 505 - 50);
		glVertex2i(1500 - 20, 500 - 50);
		glVertex2i(1500 - 20, 400 - 50);
		glVertex2i(1495 - 20, 350 - 50);
		glVertex2i(1490 - 20, 200 - 50);
		glVertex2i(1480 - 20, 50);

		glColor3f(.616, .333, .208);
		glVertex2i(1530, 50);
		glVertex2i(1520, 200 - 50);
		glVertex2i(1515, 350 - 50);
		glVertex2i(1510, 400 - 50);
		glVertex2i(1510, 500 - 50);
		glVertex2i(1520, 505 - 50);
		glEnd();

		//Tree body left side dark
		glBegin(GL_POLYGON);
		glColor3f(.616, .333, .208);
		glVertex2i(1410 - 2, 490 - 50);
		glVertex2i(1420 - 2, 450 - 50);
		glVertex2i(1440 - 2, 410 - 50);
		glVertex2i(1470 - 2, 380 - 50);
		glVertex2i(1470 - 2, 350 - 50);
		glVertex2i(1480 - 2, 340 - 50);

		glVertex2i(1480, 360 - 50);
		glVertex2i(1470, 372 - 50);
		glVertex2i(1470, 412 - 50);
		glVertex2i(1442, 432 - 50);
		glVertex2i(1422, 490 - 50);
		glVertex2i(1422, 510 - 50);
		glEnd();

		//Tree body left side
		glBegin(GL_POLYGON);
		glColor3f(.8, .537, .365);
		glVertex2i(1410, 490 - 50);
		glVertex2i(1420, 450 - 50);
		glVertex2i(1440, 410 - 50);
		glVertex2i(1470, 380 - 50);
		glVertex2i(1470, 350 - 50);
		glVertex2i(1480, 340 - 50);

		glVertex2i(1480, 360 - 50);
		glVertex2i(1470, 370 - 50);
		glVertex2i(1470, 410 - 50);
		glVertex2i(1440, 430 - 50);
		glVertex2i(1420, 490 - 50);
		glVertex2i(1420, 510 - 50);
		glEnd();

		//Tree body Right side dark
		glBegin(GL_POLYGON);
		glColor3f(.616, .333, .208);
		glVertex2i(1511, 230 - 3);
		glVertex2i(1531, 270 - 3);
		glVertex2i(1541, 290 - 3);
		glVertex2i(1551, 320 - 3);
		glVertex2i(1566, 380 - 3);
		glVertex2i(1581, 420 - 3);
		glVertex2i(1591, 440 - 3);
		glVertex2i(1591, 450 - 3);

		glVertex2i(1585, 470 + 3);
		glVertex2i(1590, 440 + 23);
		glVertex2i(1580, 420 + 23);
		glVertex2i(1560, 380 + 23);
		glVertex2i(1552, 330 + 23);
		glVertex2i(1542, 290 + 45);
		glVertex2i(1530, 270 + 43);
		glVertex2i(1510, 250 + 40);
		glEnd();

		//Tree body Right side
		glBegin(GL_POLYGON);
		glColor3f(.616, .333, .208);
		glVertex2i(1510, 230);
		glVertex2i(1530, 270);
		glVertex2i(1540, 290);
		glVertex2i(1550, 320);
		glVertex2i(1565, 380);
		glVertex2i(1580, 420);
		glVertex2i(1590, 440);
		glVertex2i(1590, 450);
	
		glColor3f(.8, .537, .365);
		glVertex2i(1585, 470);
		glVertex2i(1590, 440 + 20);
		glVertex2i(1580, 420 + 20);
		glVertex2i(1560, 380 + 20);
		glVertex2i(1550, 330 + 20);
		glVertex2i(1540, 290 + 40);
		glVertex2i(1530, 270 + 40);
		glVertex2i(1510, 250 + 40);
		glEnd();

		//dark circle
		glColor3f(0.3137, 0.5137, 0.1412);
		DrawCircle(1590, 500, 83, 2000);
		glColor3f(0.3137, 0.5137, 0.1412);
		DrawCircle(1590, 600, 73, 2000);
		glColor3f(0.3137, 0.5137, 0.1412);
		DrawCircle(1410, 510, 83, 2000);
		glColor3f(0.3137, 0.5137, 0.1412);
		DrawCircle(1410, 600, 73, 2000);
		glColor3f(0.3137, 0.5137, 0.1412);
		DrawCircle(1495, 530, 83, 2000);
		glColor3f(0.3137, 0.5137, 0.1412);
		DrawCircle(1495, 630, 103, 2000);

		//down right
		glColor3f(0.576, .808, .3137);
		DrawCircle(1590, 500, 80, 2000);

		//top right
		glColor3f(0.576, .808, .3137);
		DrawCircle(1590, 600, 70, 2000);

		//down left
		glColor3f(0.576, .808, .3137);
		DrawCircle(1410, 510, 80, 2000);

		//top left
		glColor3f(0.576, .808, .3137);
		DrawCircle(1410, 600, 70, 2000);

		//middle top
		glColor3f(0.576, .808, .3137);
		DrawCircle(1495, 530, 80, 2000);

		//middle
		glColor3f(0.576, .808, .3137);
		DrawCircle(1495, 630, 100, 2000);

		//cTree dark
		glBegin(GL_POLYGON);
		glColor3f(.616, .333, .208);
		glVertex2i(900 - 22, 505 - 50);
		glVertex2i(910 - 22, 500 - 50);
		glVertex2i(910 - 22, 400 - 50);
		glVertex2i(905 - 22, 350 - 50);
		glVertex2i(900 - 22, 200 - 50);
		glVertex2i(890 - 22, 50);

		glVertex2i(940 + 2, 50);
		glVertex2i(930 + 2, 200 - 50);
		glVertex2i(925 + 2, 350 - 50);
		glVertex2i(920 + 2, 400 - 50);
		glVertex2i(920 + 2, 500 - 50);
		glVertex2i(930 + 2, 505 - 50);
		glEnd();

		//cTree
		glBegin(GL_POLYGON);
		glColor3f(.8, .537, .365);
		glVertex2i(900 - 20, 505 - 50);
		glVertex2i(910 - 20, 500 - 50);
		glVertex2i(910 - 20, 400 - 50);
		glVertex2i(905 - 20, 350 - 50);
		glVertex2i(900 - 20, 200 - 50);
		glVertex2i(890 - 20, 50);

		glColor3f(.616, .333, .208);
		glVertex2i(940, 50);
		glVertex2i(930, 200 - 50);
		glVertex2i(925, 350 - 50);
		glVertex2i(920, 400 - 50);
		glVertex2i(920, 500 - 50);
		glVertex2i(930, 505 - 50);
		glEnd();

		//leaves dark left
		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910, 660);
		glVertex2i(760, 450);
		glVertex2i(910, 470);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910, 540);
		glVertex2i(760, 370);
		glVertex2i(910, 390);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910, 460);
		glVertex2i(760, 290);
		glVertex2i(910, 320);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910, 380);
		glVertex2i(760, 210);
		glVertex2i(910, 230);
		glEnd();

		//leaves dark right
		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910, 660);
		glVertex2i(1060, 450);
		glVertex2i(910, 470);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910, 540);
		glVertex2i(1060, 370);
		glVertex2i(910, 390);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910, 460);
		glVertex2i(1060, 290);
		glVertex2i(910, 320);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910, 380);
		glVertex2i(1060, 210);
		glVertex2i(910, 230);
		glEnd();

		//leaves left
		glBegin(GL_TRIANGLES);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910, 660 - 2);
		glVertex2i(760 + 3, 450 + 2);
		glVertex2i(910, 470);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910, 540 - 2);
		glVertex2i(760 + 3, 370 + 2);
		glVertex2i(910, 390);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910, 460 - 2);
		glVertex2i(760 + 3, 290 + 2);
		glVertex2i(910, 320);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910, 380 - 2);
		glVertex2i(760 + 3, 210 + 2);
		glVertex2i(910, 230);
		glEnd();

		//leaves right
		glBegin(GL_TRIANGLES);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910, 660 - 2);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(1060 - 3, 450 + 2);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910, 470);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910, 540 - 2);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(1060 - 3, 370 + 2);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910, 390);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910, 460 - 2);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(1060 - 3, 290 + 2);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910, 320);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910, 380 - 2);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(1060 - 3, 210 + 2);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910, 230);
		glEnd();

		//2ndTree
		//cTree dark
		glBegin(GL_POLYGON);
		glColor3f(.616, .333, .208);
		glVertex2i(900 - 22 + 100, 505 - 50);
		glVertex2i(910 - 22 + 100, 500 - 50);
		glVertex2i(910 - 22 + 100, 400 - 50);
		glVertex2i(905 - 22 + 100, 350 - 50);
		glVertex2i(900 - 22 + 100, 200 - 50);
		glVertex2i(890 - 22 + 100, 50);

		glVertex2i(940 + 2 + 100, 50);
		glVertex2i(930 + 2 + 100, 200 - 50);
		glVertex2i(925 + 2 + 100, 350 - 50);
		glVertex2i(920 + 2 + 100, 400 - 50);
		glVertex2i(920 + 2 + 100, 500 - 50);
		glVertex2i(930 + 2 + 100, 505 - 50);
		glEnd();

		//cTree
		glBegin(GL_POLYGON);
		glColor3f(.8, .537, .365);
		glVertex2i(900 - 20 + 100, 505 - 50);
		glVertex2i(910 - 20 + 100, 500 - 50);
		glVertex2i(910 - 20 + 100, 400 - 50);
		glVertex2i(905 - 20 + 100, 350 - 50);
		glVertex2i(900 - 20 + 100, 200 - 50);
		glVertex2i(890 - 20 + 100, 50);

		glColor3f(.616, .333, .208);
		glVertex2i(940 + 100, 50);
		glVertex2i(930 + 100, 200 - 50);
		glVertex2i(925 + 100, 350 - 50);
		glVertex2i(920 + 100, 400 - 50);
		glVertex2i(920 + 100, 500 - 50);
		glVertex2i(930 + 100, 505 - 50);
		glEnd();

		//leaves dark left
		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910 + 100, 660);
		glVertex2i(760 + 100, 450);
		glVertex2i(910 + 100, 470);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910 + 100, 540);
		glVertex2i(760 + 100, 370);
		glVertex2i(910 + 100, 390);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910 + 100, 460);
		glVertex2i(760 + 100, 290);
		glVertex2i(910 + 100, 320);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910 + 100, 380);
		glVertex2i(760 + 100, 210);
		glVertex2i(910 + 100, 230);
		glEnd();

		//leaves dark right
		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910 + 100, 660);
		glVertex2i(1060 + 100, 450);
		glVertex2i(910 + 100, 470);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910 + 100, 540);
		glVertex2i(1060 + 100, 370);
		glVertex2i(910 + 100, 390);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910 + 100, 460);
		glVertex2i(1060 + 100, 290);
		glVertex2i(910 + 100, 320);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910 + 100, 380);
		glVertex2i(1060 + 100, 210);
		glVertex2i(910 + 100, 230);
		glEnd();

		//leaves left
		glBegin(GL_TRIANGLES);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910 + 100, 660 - 2);
		glVertex2i(760 + 3 + 100, 450 + 2);
		glVertex2i(910 + 100, 470);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910 + 100, 540 - 2);
		glVertex2i(760 + 3 + 100, 370 + 2);
		glVertex2i(910 + 100, 390);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910 + 100, 460 - 2);
		glVertex2i(760 + 3 + 100, 290 + 2);
		glVertex2i(910 + 100, 320);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910 + 100, 380 - 2);
		glVertex2i(760 + 3 + 100, 210 + 2);
		glVertex2i(910 + 100, 230);
		glEnd();

		//leaves right
		glBegin(GL_TRIANGLES);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910 + 100, 660 - 2);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(1060 - 3 + 100, 450 + 2);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910 + 100, 470);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910 + 100, 540 - 2);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(1060 - 3 + 100, 370 + 2);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910 + 100, 390);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910 + 100, 460 - 2);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(1060 - 3 + 100, 290 + 2);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910 + 100, 320);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910 + 100, 380 - 2);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(1060 - 3 + 100, 210 + 2);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910 + 100, 230);
		glEnd();

		//3rd
		//cTree
		glBegin(GL_POLYGON);
		glColor3f(.8, .537, .365);
		glVertex2i(900 - 20 + 300, 505 - 50);
		glVertex2i(910 - 20 + 300, 500 - 50);
		glVertex2i(910 - 20 + 300, 400 - 50);
		glVertex2i(905 - 20 + 300, 350 - 50);
		glVertex2i(900 - 20 + 300, 200 - 50);
		glVertex2i(890 - 20 + 300, 50);

		glColor3f(.616, .333, .208);
		glVertex2i(940 + 300, 50);
		glVertex2i(930 + 300, 200 - 50);
		glVertex2i(925 + 300, 350 - 50);
		glVertex2i(920 + 300, 400 - 50);
		glVertex2i(920 + 300, 500 - 50);
		glVertex2i(930 + 300, 505 - 50);
		glEnd();

		//leaves dark left
		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910 + 300, 660);
		glVertex2i(760 + 300, 450);
		glVertex2i(910 + 300, 470);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910 + 300, 540);
		glVertex2i(760 + 300, 370);
		glVertex2i(910 + 300, 390);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910 + 300, 460);
		glVertex2i(760 + 300, 290);
		glVertex2i(910 + 300, 320);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910 + 300, 380);
		glVertex2i(760 + 300, 210);
		glVertex2i(910 + 300, 230);
		glEnd();

		//leaves dark right
		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910 + 300, 660);
		glVertex2i(1060 + 300, 450);
		glVertex2i(910 + 300, 470);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910 + 300, 540);
		glVertex2i(1060 + 300, 370);
		glVertex2i(910 + 300, 390);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910 + 300, 460);
		glVertex2i(1060 + 300, 290);
		glVertex2i(910 + 300, 320);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910 + 300, 380);
		glVertex2i(1060 + 300, 210);
		glVertex2i(910 + 300, 230);
		glEnd();

		//leaves left
		glBegin(GL_TRIANGLES);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910 + 300, 660 - 2);
		glVertex2i(760 + 3 + 300, 450 + 2);
		glVertex2i(910 + 300, 470);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910 + 300, 540 - 2);
		glVertex2i(760 + 3 + 300, 370 + 2);
		glVertex2i(910 + 300, 390);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910 + 300, 460 - 2);
		glVertex2i(760 + 3 + 300, 290 + 2);
		glVertex2i(910 + 300, 320);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910 + 300, 380 - 2);
		glVertex2i(760 + 3 + 300, 210 + 2);
		glVertex2i(910 + 300, 230);
		glEnd();

		//leaves right
		glBegin(GL_TRIANGLES);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910 + 300, 660 - 2);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(1060 - 3 + 300, 450 + 2);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910 + 300, 470);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910 + 300, 540 - 2);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(1060 - 3 + 300, 370 + 2);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910 + 300, 390);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910 + 300, 460 - 2);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(1060 - 3 + 300, 290 + 2);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910 + 300, 320);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910 + 300, 380 - 2);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(1060 - 3 + 300, 210 + 2);
		glColor3f(0.576, .808, .3137);
		glVertex2i(910 + 300, 230);
		glEnd();
	}
}

void treenight()
{
	if(n==1)
	{
		//Tree body dark
		glBegin(GL_POLYGON);
		glColor3f(.616, .333, .208);
		glVertex2i(1490 - 22, 505 - 50);
		glVertex2i(1500 - 22, 500 - 50);
		glVertex2i(1500 - 22, 400 - 50);
		glVertex2i(1495 - 22, 350 - 50);
		glVertex2i(1490 - 22, 200 - 50);
		glVertex2i(1480 - 22, 50);

		glVertex2i(1530 + 2, 50);
		glVertex2i(1520 + 2, 200 - 50);
		glVertex2i(1515 + 2, 350 - 50);
		glVertex2i(1510 + 2, 400 - 50);
		glVertex2i(1510 + 2, 500 - 50);
		glVertex2i(1520 + 2, 505 - 50);
		glEnd();

		//Tree body
		glBegin(GL_POLYGON);
		glColor3f(.8, .537, .365);
		glVertex2i(1490 - 20, 505 - 50);
		glVertex2i(1500 - 20, 500 - 50);
		glVertex2i(1500 - 20, 400 - 50);
		glVertex2i(1495 - 20, 350 - 50);
		glVertex2i(1490 - 20, 200 - 50);
		glVertex2i(1480 - 20, 50);

		glColor3f(.616, .333, .208);
		glVertex2i(1530, 50);
		glVertex2i(1520, 200 - 50);
		glVertex2i(1515, 350 - 50);
		glVertex2i(1510, 400 - 50);
		glVertex2i(1510, 500 - 50);
		glVertex2i(1520, 505 - 50);
		glEnd();

		//Tree body left side dark
		glBegin(GL_POLYGON);
		glColor3f(.616, .333, .208);
		glVertex2i(1410 - 2, 490 - 50);
		glVertex2i(1420 - 2, 450 - 50);
		glVertex2i(1440 - 2, 410 - 50);
		glVertex2i(1470 - 2, 380 - 50);
		glVertex2i(1470 - 2, 350 - 50);
		glVertex2i(1480 - 2, 340 - 50);

		glVertex2i(1480, 360 - 50);
		glVertex2i(1470, 372 - 50);
		glVertex2i(1470, 412 - 50);
		glVertex2i(1442, 432 - 50);
		glVertex2i(1422, 490 - 50);
		glVertex2i(1422, 510 - 50);
		glEnd();

		//Tree body left side
		glBegin(GL_POLYGON);
		glColor3f(.8, .537, .365);
		glVertex2i(1410, 490 - 50);
		glVertex2i(1420, 450 - 50);
		glVertex2i(1440, 410 - 50);
		glVertex2i(1470, 380 - 50);
		glVertex2i(1470, 350 - 50);
		glVertex2i(1480, 340 - 50);

		glVertex2i(1480, 360 - 50);
		glVertex2i(1470, 370 - 50);
		glVertex2i(1470, 410 - 50);
		glVertex2i(1440, 430 - 50);
		glVertex2i(1420, 490 - 50);
		glVertex2i(1420, 510 - 50);
		glEnd();

		//Tree body Right side dark
		glBegin(GL_POLYGON);
		glColor3f(.616, .333, .208);
		glVertex2i(1511, 230 - 3);
		glVertex2i(1531, 270 - 3);
		glVertex2i(1541, 290 - 3);
		glVertex2i(1551, 320 - 3);
		glVertex2i(1566, 380 - 3);
		glVertex2i(1581, 420 - 3);
		glVertex2i(1591, 440 - 3);
		glVertex2i(1591, 450 - 3);

		glVertex2i(1585, 470 + 3);
		glVertex2i(1590, 440 + 23);
		glVertex2i(1580, 420 + 23);
		glVertex2i(1560, 380 + 23);
		glVertex2i(1552, 330 + 23);
		glVertex2i(1542, 290 + 45);
		glVertex2i(1530, 270 + 43);
		glVertex2i(1510, 250 + 40);
		glEnd();

		//Tree body Right side
		glBegin(GL_POLYGON);
		glColor3f(.616, .333, .208);
		glVertex2i(1510, 230);
		glVertex2i(1530, 270);
		glVertex2i(1540, 290);
		glVertex2i(1550, 320);
		glVertex2i(1565, 380);
		glVertex2i(1580, 420);
		glVertex2i(1590, 440);
		glVertex2i(1590, 450);
	
		glColor3f(.8, .537, .365);
		glVertex2i(1585, 470);
		glVertex2i(1590, 440 + 20);
		glVertex2i(1580, 420 + 20);
		glVertex2i(1560, 380 + 20);
		glVertex2i(1550, 330 + 20);
		glVertex2i(1540, 290 + 40);
		glVertex2i(1530, 270 + 40);
		glVertex2i(1510, 250 + 40);
		glEnd();

		//dark circle
		glColor3f(0.3137, 0.5137, 0.1412);
		DrawCircle(1590, 500, 83, 2000);
		glColor3f(0.3137, 0.5137, 0.1412);
		DrawCircle(1590, 600, 73, 2000);
		glColor3f(0.3137, 0.5137, 0.1412);
		DrawCircle(1410, 510, 83, 2000);
		glColor3f(0.3137, 0.5137, 0.1412);
		DrawCircle(1410, 600, 73, 2000);
		glColor3f(0.3137, 0.5137, 0.1412);
		DrawCircle(1495, 530, 83, 2000);
		glColor3f(0.3137, 0.5137, 0.1412);
		DrawCircle(1495, 630, 103, 2000);

		//down right
		glColor3f(0.35686, 0.713725, 0.1215686);
		DrawCircle(1590, 500, 80, 2000);

		//top right
		glColor3f(0.35686, 0.713725, 0.1215686);
		DrawCircle(1590, 600, 70, 2000);

		//down left
		glColor3f(0.35686, 0.713725, 0.1215686);
		DrawCircle(1410, 510, 80, 2000);

		//top left
		glColor3f(0.35686, 0.713725, 0.1215686);
		DrawCircle(1410, 600, 70, 2000);

		//middle top
		glColor3f(0.35686, 0.713725, 0.1215686);
		DrawCircle(1495, 530, 80, 2000);

		//middle
		glColor3f(0.35686, 0.713725, 0.1215686);
		DrawCircle(1495, 630, 100, 2000);

		//cTree dark
		glBegin(GL_POLYGON);
		glColor3f(.616, .333, .208);
		glVertex2i(900 - 22, 505 - 50);
		glVertex2i(910 - 22, 500 - 50);
		glVertex2i(910 - 22, 400 - 50);
		glVertex2i(905 - 22, 350 - 50);
		glVertex2i(900 - 22, 200 - 50);
		glVertex2i(890 - 22, 50);

		glVertex2i(940 + 2, 50);
		glVertex2i(930 + 2, 200 - 50);
		glVertex2i(925 + 2, 350 - 50);
		glVertex2i(920 + 2, 400 - 50);
		glVertex2i(920 + 2, 500 - 50);
		glVertex2i(930 + 2, 505 - 50);
		glEnd();

		//cTree
		glBegin(GL_POLYGON);
		glColor3f(.8, .537, .365);
		glVertex2i(900 - 20, 505 - 50);
		glVertex2i(910 - 20, 500 - 50);
		glVertex2i(910 - 20, 400 - 50);
		glVertex2i(905 - 20, 350 - 50);
		glVertex2i(900 - 20, 200 - 50);
		glVertex2i(890 - 20, 50);

		glColor3f(.616, .333, .208);
		glVertex2i(940, 50);
		glVertex2i(930, 200 - 50);
		glVertex2i(925, 350 - 50);
		glVertex2i(920, 400 - 50);
		glVertex2i(920, 500 - 50);
		glVertex2i(930, 505 - 50);
		glEnd();

		//leaves dark left
		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910, 660);
		glVertex2i(760, 450);
		glVertex2i(910, 470);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910, 540);
		glVertex2i(760, 370);
		glVertex2i(910, 390);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910, 460);
		glVertex2i(760, 290);
		glVertex2i(910, 320);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910, 380);
		glVertex2i(760, 210);
		glVertex2i(910, 230);
		glEnd();

		//leaves dark right
		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910, 660);
		glVertex2i(1060, 450);
		glVertex2i(910, 470);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910, 540);
		glVertex2i(1060, 370);
		glVertex2i(910, 390);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910, 460);
		glVertex2i(1060, 290);
		glVertex2i(910, 320);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910, 380);
		glVertex2i(1060, 210);
		glVertex2i(910, 230);
		glEnd();

		//leaves left
		glBegin(GL_TRIANGLES);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910, 660 - 2);
		glVertex2i(760 + 3, 450 + 2);
		glVertex2i(910, 470);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910, 540 - 2);
		glVertex2i(760 + 3, 370 + 2);
		glVertex2i(910, 390);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910, 460 - 2);
		glVertex2i(760 + 3, 290 + 2);
		glVertex2i(910, 320);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910, 380 - 2);
		glVertex2i(760 + 3, 210 + 2);
		glVertex2i(910, 230);
		glEnd();

		//leaves right
		glBegin(GL_TRIANGLES);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910, 660 - 2);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(1060 - 3, 450 + 2);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910, 470);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910, 540 - 2);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(1060 - 3, 370 + 2);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910, 390);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910, 460 - 2);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(1060 - 3, 290 + 2);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910, 320);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910, 380 - 2);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(1060 - 3, 210 + 2);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910, 230);
		glEnd();

		//2ndTree
		//cTree dark
		glBegin(GL_POLYGON);
		glColor3f(.616, .333, .208);
		glVertex2i(900 - 22 + 100, 505 - 50);
		glVertex2i(910 - 22 + 100, 500 - 50);
		glVertex2i(910 - 22 + 100, 400 - 50);
		glVertex2i(905 - 22 + 100, 350 - 50);
		glVertex2i(900 - 22 + 100, 200 - 50);
		glVertex2i(890 - 22 + 100, 50);

		glVertex2i(940 + 2 + 100, 50);
		glVertex2i(930 + 2 + 100, 200 - 50);
		glVertex2i(925 + 2 + 100, 350 - 50);
		glVertex2i(920 + 2 + 100, 400 - 50);
		glVertex2i(920 + 2 + 100, 500 - 50);
		glVertex2i(930 + 2 + 100, 505 - 50);
		glEnd();

		//cTree
		glBegin(GL_POLYGON);
		glColor3f(.8, .537, .365);
		glVertex2i(900 - 20 + 100, 505 - 50);
		glVertex2i(910 - 20 + 100, 500 - 50);
		glVertex2i(910 - 20 + 100, 400 - 50);
		glVertex2i(905 - 20 + 100, 350 - 50);
		glVertex2i(900 - 20 + 100, 200 - 50);
		glVertex2i(890 - 20 + 100, 50);

		glColor3f(.616, .333, .208);
		glVertex2i(940 + 100, 50);
		glVertex2i(930 + 100, 200 - 50);
		glVertex2i(925 + 100, 350 - 50);
		glVertex2i(920 + 100, 400 - 50);
		glVertex2i(920 + 100, 500 - 50);
		glVertex2i(930 + 100, 505 - 50);
		glEnd();

		//leaves dark left
		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910 + 100, 660);
		glVertex2i(760 + 100, 450);
		glVertex2i(910 + 100, 470);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910 + 100, 540);
		glVertex2i(760 + 100, 370);
		glVertex2i(910 + 100, 390);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910 + 100, 460);
		glVertex2i(760 + 100, 290);
		glVertex2i(910 + 100, 320);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910 + 100, 380);
		glVertex2i(760 + 100, 210);
		glVertex2i(910 + 100, 230);
		glEnd();

		//leaves dark right
		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910 + 100, 660);
		glVertex2i(1060 + 100, 450);
		glVertex2i(910 + 100, 470);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910 + 100, 540);
		glVertex2i(1060 + 100, 370);
		glVertex2i(910 + 100, 390);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910 + 100, 460);
		glVertex2i(1060 + 100, 290);
		glVertex2i(910 + 100, 320);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910 + 100, 380);
		glVertex2i(1060 + 100, 210);
		glVertex2i(910 + 100, 230);
		glEnd();

		//leaves left
		glBegin(GL_TRIANGLES);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910 + 100, 660 - 2);
		glVertex2i(760 + 3 + 100, 450 + 2);
		glVertex2i(910 + 100, 470);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910 + 100, 540 - 2);
		glVertex2i(760 + 3 + 100, 370 + 2);
		glVertex2i(910 + 100, 390);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910 + 100, 460 - 2);
		glVertex2i(760 + 3 + 100, 290 + 2);
		glVertex2i(910 + 100, 320);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910 + 100, 380 - 2);
		glVertex2i(760 + 3 + 100, 210 + 2);
		glVertex2i(910 + 100, 230);
		glEnd();

		//leaves right
		glBegin(GL_TRIANGLES);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910 + 100, 660 - 2);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(1060 - 3 + 100, 450 + 2);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910 + 100, 470);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910 + 100, 540 - 2);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(1060 - 3 + 100, 370 + 2);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910 + 100, 390);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910 + 100, 460 - 2);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(1060 - 3 + 100, 290 + 2);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910 + 100, 320);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910 + 100, 380 - 2);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(1060 - 3 + 100, 210 + 2);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910 + 100, 230);
		glEnd();

		//3rd
		//cTree
		glBegin(GL_POLYGON);
		glColor3f(.8, .537, .365);
		glVertex2i(900 - 20 + 300, 505 - 50);
		glVertex2i(910 - 20 + 300, 500 - 50);
		glVertex2i(910 - 20 + 300, 400 - 50);
		glVertex2i(905 - 20 + 300, 350 - 50);
		glVertex2i(900 - 20 + 300, 200 - 50);
		glVertex2i(890 - 20 + 300, 50);

		glColor3f(.616, .333, .208);
		glVertex2i(940 + 300, 50);
		glVertex2i(930 + 300, 200 - 50);
		glVertex2i(925 + 300, 350 - 50);
		glVertex2i(920 + 300, 400 - 50);
		glVertex2i(920 + 300, 500 - 50);
		glVertex2i(930 + 300, 505 - 50);
		glEnd();

		//leaves dark left
		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910 + 300, 660);
		glVertex2i(760 + 300, 450);
		glVertex2i(910 + 300, 470);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910 + 300, 540);
		glVertex2i(760 + 300, 370);
		glVertex2i(910 + 300, 390);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910 + 300, 460);
		glVertex2i(760 + 300, 290);
		glVertex2i(910 + 300, 320);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910 + 300, 380);
		glVertex2i(760 + 300, 210);
		glVertex2i(910 + 300, 230);
		glEnd();

		//leaves dark right
		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910 + 300, 660);
		glVertex2i(1060 + 300, 450);
		glVertex2i(910 + 300, 470);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910 + 300, 540);
		glVertex2i(1060 + 300, 370);
		glVertex2i(910 + 300, 390);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910 + 300, 460);
		glVertex2i(1060 + 300, 290);
		glVertex2i(910 + 300, 320);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(910 + 300, 380);
		glVertex2i(1060 + 300, 210);
		glVertex2i(910 + 300, 230);
		glEnd();

		//leaves left
		glBegin(GL_TRIANGLES);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910 + 300, 660 - 2);
		glVertex2i(760 + 3 + 300, 450 + 2);
		glVertex2i(910 + 300, 470);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910 + 300, 540 - 2);
		glVertex2i(760 + 3 + 300, 370 + 2);
		glVertex2i(910 + 300, 390);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910 + 300, 460 - 2);
		glVertex2i(760 + 3 + 300, 290 + 2);
		glVertex2i(910 + 300, 320);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910 + 300, 380 - 2);
		glVertex2i(760 + 3 + 300, 210 + 2);
		glVertex2i(910 + 300, 230);
		glEnd();

		//leaves right
		glBegin(GL_TRIANGLES);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910 + 300, 660 - 2);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(1060 - 3 + 300, 450 + 2);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910 + 300, 470);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910 + 300, 540 - 2);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(1060 - 3 + 300, 370 + 2);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910 + 300, 390);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910 + 300, 460 - 2);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(1060 - 3 + 300, 290 + 2);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910 + 300, 320);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910 + 300, 380 - 2);
		glColor3f(0.3137, 0.5137, 0.1412);
		glVertex2i(1060 - 3 + 300, 210 + 2);
		glColor3f(0.35686, 0.713725, 0.1215686);
		glVertex2i(910 + 300, 230);
		glEnd();
	}
}

void city()
{
	glBegin(GL_POLYGON);
	glColor3f(0.298, .561, .619);
	glVertex2i(2000, 950);
	glVertex2i(2000, 1050);
	glVertex2i(1950, 1050);
	glVertex2i(1950, 1060);
	glVertex2i(1940, 1060);
	glVertex2i(1940, 1000);
	glVertex2i(1900, 1000);
	glVertex2i(1900, 1050);
	glVertex2i(1875, 1075);
	glVertex2i(1850, 1050);
	glVertex2i(1850, 950);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.298, .561, .619);
	glVertex2i(1920, 950);
	glVertex2i(1920, 1140);
	glVertex2i(1890, 1140);
	glVertex2i(1890, 950);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.298, .561, .619);
	glVertex2i(1850, 950);
	glVertex2i(1850, 1050);
	glVertex2i(1840, 1050);
	glVertex2i(1840, 1030);
	glVertex2i(1800, 1030);
	glVertex2i(1800, 950);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.298, .561, .619);
	glVertex2i(1800, 950);
	glVertex2i(1800, 970);
	glVertex2i(1700, 970);
	glVertex2i(1700, 950);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.298, .561, .619);
	glVertex2i(1700, 950);
	glVertex2i(1700, 1010);
	glVertex2i(1650, 1010);
	glVertex2i(1650, 950);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.298, .561, .619);
	glVertex2i(1710, 1010);
	glVertex2i(1675, 1030);
	glVertex2i(1640, 1010);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.298, .561, .619);
	glVertex2i(1650, 950);
	glVertex2i(1650, 1060);
	glVertex2i(1655, 1065);
	glVertex2i(1605, 1065);
	glVertex2i(1610, 1060);
	glVertex2i(1610, 950);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.298, .561, .619);
	glVertex2i(1610, 950);
	glVertex2i(1610, 980);
	glVertex2i(1580, 980);
	glVertex2i(1580, 950);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.298, .561, .619);
	glVertex2i(0, 950);
	glVertex2i(80, 950);
	glVertex2i(80, 1050);
	glVertex2i(0, 1090);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.298, .561, .619);
	glVertex2i(80, 950);
	glVertex2i(110, 950);
	glVertex2i(110, 970);
	glVertex2i(80, 970);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.298, .561, .619);
	glVertex2i(110, 1100);
	glVertex2i(110, 950);
	glVertex2i(180, 950);
	glVertex2i(180, 1100);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.298, .561, .619);
	glVertex2i(180, 1000);
	glVertex2i(180, 950);
	glVertex2i(230, 950);
	glVertex2i(230, 1000);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.298, .561, .619);
	glVertex2i(230, 1100);
	glVertex2i(220, 950);
	glVertex2i(290, 950);
	glVertex2i(280, 1100);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.298, .561, .619);
	glVertex2i(300, 950);
	glVertex2i(400, 950);
	glVertex2i(400, 1180);
	glVertex2i(300, 1180);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.298, .561, .619);
	glVertex2i(400, 1050);
	glVertex2i(400, 950);
	glVertex2i(480, 950);
	glVertex2i(480, 1050);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.298, .561, .619);
	glVertex2i(480, 950);
	glVertex2i(530, 950);
	glVertex2i(530, 1080);
	glVertex2i(535, 1090);
	glVertex2i(475, 1090);
	glVertex2i(480, 1080);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.298, .561, .619);
	glVertex2i(530, 950);
	glVertex2i(630, 950);
	glVertex2i(630, 1000);
	glVertex2i(530, 1000);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.298, .561, .619);
	glVertex2i(630, 950);
	glVertex2i(1000, 950);
	glVertex2i(1000, 1010);
	glVertex2i(980, 1010);
	glVertex2i(980, 1110);
	glVertex2i(900, 1110);
	glVertex2i(900, 1050);
	glVertex2i(870, 1070);
	glVertex2i(840, 1050);
	glVertex2i(840, 990);
	glVertex2i(810, 990);
	glVertex2i(810, 1090);
	glVertex2i(770, 1090);
	glVertex2i(770, 1040);
	glVertex2i(730, 1040);
	glVertex2i(630, 1020);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.298, .561, .619);
	glVertex2i(730, 1040);
	glVertex2i(760, 1040);
	glVertex2i(745, 1100);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.298, .561, .619);
	glVertex2i(650, 1000);
	glVertex2i(680, 1000);
	glVertex2i(665, 1100);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.298, .561, .619);
	glVertex2i(1650 - 550, 950);
	glVertex2i(1650 - 550, 1060);
	glVertex2i(1655 - 550, 1065);
	glVertex2i(1605 - 550, 1065);
	glVertex2i(1610 - 550, 1060);
	glVertex2i(1610 - 550, 950);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.298, .561, .619);
	glVertex2i(1650 - 700, 950 + 60);
	glVertex2i(1650 - 700, 1060 + 60);
	glVertex2i(1655 - 700, 1065 + 60);
	glVertex2i(1605 - 700, 1065 + 60);
	glVertex2i(1610 - 700, 1060 + 60);
	glVertex2i(1610 - 700, 950 + 60);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.298, .561, .619);
	glVertex2i(1700 - 550, 950);
	glVertex2i(1700 - 550, 1010);
	glVertex2i(1650 - 550, 1010);
	glVertex2i(1650 - 550, 950);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.298, .561, .619);
	glVertex2i(1710 - 550, 1010);
	glVertex2i(1675 - 550, 1030);
	glVertex2i(1640 - 550, 1010);
	glEnd();

	glBegin(GL_POLYGON); 
	glColor3f(0.298, .561, .619);
	glVertex2i(1200, 1095);
	glVertex2i(1200, 950);
	glVertex2i(1320, 950);
	glVertex2i(1320, 1095);
	glVertex2i(1330, 1105);
	glVertex2i(1190, 1105);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.298, .561, .619);
	glVertex2i(1430, 1020);
	glVertex2i(1380, 950);
	glVertex2i(1520, 950);
	glVertex2i(1470, 1020);
	glVertex2i(1455, 1100);
	glVertex2i(1450, 1120);
	glVertex2i(1445, 1100);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.298, .561, .619);
	glVertex2i(280, 950);
	glVertex2i(1600, 950);
	glVertex2i(1600, 970);
	glVertex2i(280, 970);
	glEnd();
}

void sky()
{
	if(n==0)
	{
		glBegin(GL_POLYGON);
		glColor3f(0.34, 0.808, 1.0);
		glVertex2i(2000, 1500);
		glVertex2i(0, 1500);
		glColor3f(2.49, 1.87, 1.0);
		glVertex2i(0, 970);
		glVertex2i(2000, 970);
		glEnd();
	}
}

void skynight()
{
	if(n==1)
	{
		glBegin(GL_POLYGON);
		glColor3f(0.04705, 0.078431, 0.50588);
		glVertex2i(2000, 1500);
		glVertex2i(0, 1500);
		glColor3f(0.403921, 0.44705, 0.94509);
		glVertex2i(0, 970);
		glVertex2i(2000, 970);
		glEnd();
	}
}

void sun()
{
	if(n==0)
	{
		glColor3f(1.0, 1.0, 0.792156);
		DrawCircle(1400, 1300, 105, 2000);

		glColor3f(1.0, 0.9176470, 0.63529411);
		DrawCircle(1400, 1300, 100, 2000);

		glColor3f(0.99647843, 0.87058823, 0.43921568);
		DrawCircle(1400, 1300, 90, 2000);

		glColor3f(0.99647843, 0.84313725, 0.30588235);
		DrawCircle(1400, 1300, 85, 2000);

		glColor3f(0.9490196, 0.6745098, 0.1098039);
		DrawCircle(1400, 1300, 75, 2000);
	}
}

void moon()
{
	if(n==1)
	{
		glColor3f(1.0, 1.0, 0.843137);
		DrawCircle(1450, 1300, 75, 2000);

		glColor3f(0.95686, 0.90980, 0.701960);
		DrawCircle(1450, 1300, 65, 2000);
	}
}

void river()
{
	if(n==0)
	{
		glBegin(GL_POLYGON);
		glColor3f(.106, .69, .918);
		glVertex2i(0, 200);
		glColor3f(1.4, .8, .949);
		glVertex2i(1000, 200);
		glColor3f(0.106, 1.69, .918);
		glVertex2i(2000, 200);
		glColor3f(0.733, 0.886, .953);
		glVertex2i(2000, 970);
		glColor3f(0.733, 0.886, .953);
		glVertex2i(0, 970);
		glEnd();
	}
}

void rivernight()
{
	if(n==1)
	{
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.58431, 0.866666667);
		glVertex2i(0, 200);
		glColor3f(0.0666667, 0.670588, 0.8);
		glVertex2i(2000, 200);
		glColor3f(0.0, 0.486274, 0.72549);
		glVertex2i(2000, 970);
		glColor3f(0.0, 0.486274, 0.72549);
		glVertex2i(0, 970);
		glEnd();
	}
}

void field()
{
	if(n==0)
	{
		//Middle ground 
		glBegin(GL_POLYGON);
		glColor3f(0.545, .671, .0313);
		glVertex2i(0, 0);
		glVertex2i(2000, 0);
		glVertex2i(2000, 350);
		glVertex2i(1900, 350);
		glVertex2i(1800, 320);
		glVertex2i(1700, 350);
		glVertex2i(1600, 370);
		glVertex2i(1500, 375);
		glVertex2i(1350, 365);
		glVertex2i(1200, 390);
		glVertex2i(1000, 410);
		glVertex2i(1700 - 700, 350 + 60);
		glVertex2i(1600 - 700, 370 + 50);
		glVertex2i(1500 - 700, 375 + 50);
		glVertex2i(1350 - 700, 365 + 50);
		glVertex2i(1200 - 700, 390 + 60);
		glVertex2i(1000 - 700, 410 + 50);
		glVertex2i(200, 455);
		glVertex2i(100, 465);
		glVertex2i(0, 455);
		glEnd();

		//Middle ground 
		glBegin(GL_POLYGON);
		glColor3f(.537, 1.776, .239);
		glVertex2i(0, 0);
		glVertex2i(2000, 0);

		glColor3f(0.6549, .780, .1098);
		glVertex2i(2000, 350 - 5);
		glVertex2i(1900, 350 - 5);
		glVertex2i(1800, 320 - 5);
		glVertex2i(1700, 350 - 5);
		glVertex2i(1600, 370 - 5);
		glVertex2i(1500, 375 - 5);
		glVertex2i(1350, 365 - 5);
		glVertex2i(1200, 390 - 5);
		glVertex2i(1000, 410 - 5);
		glVertex2i(1700 - 700, 350 + 55);
		glVertex2i(1600 - 700, 370 + 45);
		glVertex2i(1500 - 700, 375 + 45);
		glVertex2i(1350 - 700, 365 + 45);
		glVertex2i(1200 - 700, 390 + 55);
		glVertex2i(1000 - 700, 410 + 45);
		glVertex2i(200, 455 - 5);
		glVertex2i(100, 465 - 5);
		glVertex2i(0, 455 - 5);
		glEnd();
	}
}

void fieldnight()
{
	if(n==1)
	{
		//Middle ground 
		glBegin(GL_POLYGON);
		glColor3f(0.545, 0.671, 0.0313);
		glVertex2i(0, 0);
		glVertex2i(2000, 0);
		glVertex2i(2000, 350);
		glVertex2i(1900, 350);
		glVertex2i(1800, 320);
		glVertex2i(1700, 350);
		glVertex2i(1600, 370);
		glVertex2i(1500, 375);
		glVertex2i(1350, 365);
		glVertex2i(1200, 390);
		glVertex2i(1000, 410);
		glVertex2i(1700 - 700, 350 + 60);
		glVertex2i(1600 - 700, 370 + 50);
		glVertex2i(1500 - 700, 375 + 50);
		glVertex2i(1350 - 700, 365 + 50);
		glVertex2i(1200 - 700, 390 + 60);
		glVertex2i(1000 - 700, 410 + 50);
		glVertex2i(200, 455);
		glVertex2i(100, 465);
		glVertex2i(0, 455);
		glEnd();

		//Middle ground 
		glBegin(GL_POLYGON);
		glColor3f(0.403921, 0.807843, 0.0);
		glVertex2i(0, 0);
		glVertex2i(2000, 0);

		glColor3f(0.6549, .780, .1098);
		glVertex2i(2000, 350 - 5);
		glVertex2i(1900, 350 - 5);
		glVertex2i(1800, 320 - 5);
		glVertex2i(1700, 350 - 5);
		glVertex2i(1600, 370 - 5);
		glVertex2i(1500, 375 - 5);
		glVertex2i(1350, 365 - 5);
		glVertex2i(1200, 390 - 5);
		glVertex2i(1000, 410 - 5);
		glVertex2i(1700 - 700, 350 + 55);
		glVertex2i(1600 - 700, 370 + 45);
		glVertex2i(1500 - 700, 375 + 45);
		glVertex2i(1350 - 700, 365 + 45);
		glVertex2i(1200 - 700, 390 + 55);
		glVertex2i(1000 - 700, 410 + 45);
		glVertex2i(200, 455 - 5);
		glVertex2i(100, 465 - 5);
		glVertex2i(0, 455 - 5);
		glEnd();
	}
}

void bridge()
{
	//pillars dark
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2i(440 - 2, 615 - 2);
	glVertex2i(520 + 2, 615 - 2);
	glVertex2i(520 + 2, 830 + 2);
	glVertex2i(440 - 2, 830 + 2);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2i(1040 - 2, 615 - 2);
	glVertex2i(1120 + 2, 615 - 2);
	glVertex2i(1120 + 2, 830 + 2);
	glVertex2i(1040 - 2, 830 + 2);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2i(1640 - 2, 615 - 2);
	glVertex2i(1720 + 2, 615 - 2);
	glVertex2i(1720 + 2, 830 + 2);
	glVertex2i(1640 - 2, 830 + 2);
	glEnd();

	//pillars
	glBegin(GL_POLYGON);
	glColor3f(0.35294, 0.35294, 0.35294);
	glVertex2i(440, 615);
	glVertex2i(520, 615);
	glColor3f(0.5215686, 0.5215686, 0.5215686);
	glVertex2i(520, 830);
	glVertex2i(440, 830);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.35294, 0.35294, 0.35294);
	glVertex2i(1040, 615);
	glVertex2i(1120, 615);
	glColor3f(0.5215686, 0.5215686, 0.5215686);
	glVertex2i(1120, 830);
	glVertex2i(1040, 830);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.35294, 0.35294, 0.35294);
	glVertex2i(1640, 615);
	glVertex2i(1720, 615);
	glColor3f(0.5215686, 0.5215686, 0.5215686);
	glVertex2i(1720, 830);
	glVertex2i(1640, 830);
	glEnd();

	//body
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2i(0, 830 + 2);
	glVertex2i(2000, 830 + 2);
	glVertex2i(2000, 900 + 2);
	glVertex2i(0, 900 + 2);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.5215686, 0.5215686, 0.5215686);
	glVertex2i(0, 830 + 4);
	glVertex2i(2000, 830 + 4);
	glColor3f(0.643137, 0.643137, 0.643137);
	glVertex2i(2000, 900);
	glVertex2i(0, 900);
	glEnd();

	//towers dark
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2i(470, 900);
	glVertex2i(490, 900);
	glVertex2i(490, 1100);
	glVertex2i(470, 1100);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2i(1070, 900);
	glVertex2i(1090, 900);
	glVertex2i(1090, 1100);
	glVertex2i(1070, 1100);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2i(1670, 900);
	glVertex2i(1690, 900);
	glVertex2i(1690, 1100);
	glVertex2i(1670, 1100);
	glEnd();

	//towers
	glBegin(GL_POLYGON);
	glColor3f(0.643137, 0.643137, 0.643137);
	glVertex2i(470 + 2, 900 + 2);
	glVertex2i(490 - 2, 900 + 2);
	glVertex2i(490 - 2, 1100 - 2);
	glVertex2i(470 + 2, 1100 - 2);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.643137, 0.643137, 0.643137);
	glVertex2i(1070 + 2, 900 + 2);
	glVertex2i(1090 - 2, 900 + 2);
	glVertex2i(1090 - 2, 1100 - 2);
	glVertex2i(1070 + 2, 1100 - 2);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.643137, 0.643137, 0.643137);
	glVertex2i(1670 + 2, 900 + 2);
	glVertex2i(1690 - 2, 900 + 2);
	glVertex2i(1690 - 2, 1100 - 2);
	glVertex2i(1670 + 2, 1100 - 2);
	glEnd();
}

void boat(int x)
{
	//back part
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2i(118, 640);
	glVertex2i(192, 640);
	glVertex2i(192, 677);
	glVertex2i(113, 667);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(.4078, .275, .063);
	glVertex2i(120, 640);
	glVertex2i(190, 640);
	glVertex2i(190, 675);
	glVertex2i(115, 665);
	glEnd();

	//boat main
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2i(189, 760);
	glVertex2i(189, 650);
	glVertex2i(282, 650);
	glVertex2i(282, 760);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(.7647, .7647, .7647);
	glVertex2i(190, 760);
	glVertex2i(190, 650);
	glColor3f(1, 1, 1);
	glVertex2i(280, 650);
	glVertex2i(280, 760);
	glEnd();

	//chimny
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2i(205, 797);
	glVertex2i(205, 765);
	glVertex2i(230, 765);
	glVertex2i(230, 797);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(.7647, .7647, .7647);
	glVertex2i(207, 795);
	glVertex2i(207, 765);
	glColor3f(1, 1, 1);
	glVertex2i(228, 765);
	glVertex2i(228, 795);
	glEnd();

	//boat top base
	glBegin(GL_POLYGON);
	glColor3f(1.0f / 255 * 181, 1.0f / 255 * 42, 1.0f / 255 * 46);
	glVertex2i(185, 770);
	glVertex2i(185, 750);
	glColor3f(1.0f / 255 * 253, 1.0f / 255 * 0, 1.0f / 255 * 6);
	glVertex2i(285, 755);
	glVertex2i(285, 775);
	glEnd();

	//window
	glColor3f(0, 0, 0);
	DrawCircle(243, 720, 17, 720);

	glColor3f((1.0f / 255) * 11, (1.0f / 255) * 119, (1.0f / 255) * 136);
	DrawCircle(243, 720, 15, 720);

	//front part
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2i(262, 662);
	glVertex2i(102, 652);
	glVertex2i(122, 598);
	glVertex2i(220, 593);
	glVertex2i(322, 598);
	glVertex2i(372, 712);
	glVertex2i(282, 692);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(.4078, .275, .063);
	glVertex2i(260, 660);
	glVertex2i(100, 650);
	glVertex2i(120, 600);
	glVertex2i(220, 595);
	glVertex2i(320, 600);

	glColor3f(.6039, .4549, .321568);
	glVertex2i(370, 710);
	glVertex2i(280, 690);
	glEnd();
}

void moveboat()
{
	if(boatstatus == 1)
	{
		boatX += 3;
		w += 1;

	}
	if(boatX>2300)
	{
		boatX = -400;
	}
	glPushMatrix();
	glTranslatef(boatX, boatY, 0);
	boat(1);
	glPopMatrix();
}

void plane(int x)
{
	//left wing dark
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(330, 1360);
	glVertex2i(345, 1380);
	glVertex2i(390, 1380);
	glVertex2i(380, 1310);
	glEnd();

	//left wing
	glBegin(GL_POLYGON);
	glColor3f(0.756862, 0.5372549, 0.878431);
	glVertex2i(330 + 2, 1360 + 2);
	glVertex2i(345 + 2, 1380 - 2);
	glVertex2i(390 - 2, 1380 - 2);
	glVertex2i(380 - 2, 1310 + 2);
	glEnd();

	//left flap dark
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(135, 1380);
	glVertex2i(160, 1380);
	glVertex2i(150, 1350);
	glVertex2i(130, 1350);
	glEnd();

	//left flap
	glBegin(GL_POLYGON);
	glColor3f(0.756862, 0.5372549, 0.878431);
	glVertex2i(135 + 2, 1380 - 2);
	glVertex2i(160 -2, 1380 - 2);
	glVertex2i(150 - 2, 1350 + 2);
	glVertex2i(130 + 2, 1350 + 2);
	glEnd();

	//mainbody tail dark
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(100, 1400);
	glVertex2i(120, 1410);
	glVertex2i(140, 1360);
	glVertex2i(90, 1350);
	glEnd();

	//mainbody dark
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(90, 1350);
	glVertex2i(140, 1360);
	glVertex2i(190, 1363);
	glVertex2i(350, 1363);
	glVertex2i(350, 1263);
	glVertex2i(330, 1263);
	glVertex2i(190, 1293);
	glVertex2i(175, 1330);
	glVertex2i(110, 1335);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(350, 1363);
	glVertex2i(370, 1333);
	glVertex2i(370, 1263);
	glVertex2i(350, 1263);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(370, 1333);
	glVertex2i(430, 1323);
	glVertex2i(405, 1263);
	glVertex2i(370, 1263);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(430, 1323);
	glVertex2i(435, 1315);
	glVertex2i(460, 1295);
	glVertex2i(405, 1263);
	glEnd();

	//mainbody tail
	glBegin(GL_POLYGON);
	glColor3f(0.756862, 0.5372549, 0.878431);
	glVertex2i(100 + 2, 1400 - 2);
	glVertex2i(120 - 2, 1410 - 3);
	glVertex2i(140 - 2, 1360);
	glVertex2i(90 + 2, 1350);
	glEnd();

	//mainbody
	glBegin(GL_POLYGON);
	glColor3f(0.756862, 0.5372549, 0.878431);
	glVertex2i(90 + 2, 1350);
	glVertex2i(140 - 2, 1360);
	glVertex2i(190, 1363 - 2);
	glVertex2i(350, 1363 - 2);
	glVertex2i(350, 1263 + 2);
	glVertex2i(330, 1263 + 2);
	glVertex2i(190, 1293 + 2);
	glVertex2i(175, 1330 + 2);
	glVertex2i(110, 1335 + 2);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.756862, 0.5372549, 0.878431);
	glVertex2i(350, 1363 - 2);
	glVertex2i(370, 1333 - 2);
	glVertex2i(370, 1263 + 2);
	glVertex2i(350, 1263 + 2);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.756862, 0.5372549, 0.878431);
	glVertex2i(370, 1333 - 2);
	glVertex2i(430, 1323 - 2);
	glVertex2i(405, 1263 + 2);
	glVertex2i(370, 1263 + 2);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.756862, 0.5372549, 0.878431);
	glVertex2i(430, 1323 - 2);
	glVertex2i(435, 1315 - 2);
	glVertex2i(460 - 2, 1295);
	glVertex2i(405, 1263 + 2);
	glEnd();

	//right wing dark
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(300, 1293);
	glVertex2i(280, 1200);
	glVertex2i(350, 1200);
	glVertex2i(390, 1293);
	glEnd();

	//right wing
	glBegin(GL_POLYGON);
	glColor3f(0.756862, 0.5372549, 0.878431);
	glVertex2i(300 + 2, 1293 - 2);
	glVertex2i(280 + 2, 1200 + 2);
	glVertex2i(350 - 2, 1200 + 2);
	glVertex2i(390 - 2, 1293 - 2);
	glEnd();

	//right flap dark
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(100, 1300);
	glVertex2i(115, 1340);
	glVertex2i(155, 1340);
	glVertex2i(125, 1300);
	glEnd();

	//right flap
	glBegin(GL_POLYGON);
	glColor3f(0.756862, 0.5372549, 0.878431);
	glVertex2i(100 + 2, 1300 + 2);
	glVertex2i(115 + 2, 1340 - 2);
	glVertex2i(155 - 2, 1340 - 2);
	glVertex2i(125 - 2, 1300 + 2);
	glEnd();

	//cockpit dark
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(310, 1363);
	glVertex2i(350, 1363);
	glVertex2i(370, 1333);
	glVertex2i(340, 1323);
	glVertex2i(290, 1333);
	glEnd();

	//cockpit
	glBegin(GL_POLYGON);
	glColor3f(0.9372549, 0.9372549, 0.9372549);
	glVertex2i(310 + 2, 1363 - 2);
	glVertex2i(350 - 2, 1363 - 2);
	glVertex2i(370 - 2, 1333);
	glVertex2i(340, 1323 + 2);
	glVertex2i(290 + 2, 1333 + 2);
	glEnd();

	//star dark
	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(105 - 2, 1375 + 2);
	glVertex2i(125 + 2, 1375 + 2);
	glVertex2i(115, 1355 - 2);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(105 - 2, 1365 - 2);
	glVertex2i(125 + 2, 1365 - 2);
	glVertex2i(115, 1385 + 2);
	glEnd();

	//star
	glBegin(GL_TRIANGLES);
	glColor3f(0.929411, 0.109803, 0.141176);
	glVertex2i(105, 1375);
	glVertex2i(125, 1375);
	glVertex2i(115, 1355);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.929411, 0.109803, 0.141176);
	glVertex2i(105, 1365);
	glVertex2i(125, 1365);
	glVertex2i(115, 1385);
	glEnd();
}

void moveplane()
{
	if(planestatus == 1)
	{
		planeX += 6;
		w += 1;

	}
	if(planeX>2300)
	{
		planeX = -400;
	}
	glPushMatrix();
	glTranslatef(planeX, planeY, 0);
	plane(1);
	glPopMatrix();
}

void cloud(int x)
{
	glColor3f(0.447, 0.624, 0.812);
	DrawCircle(196 + 400, 1280 - 20, 60, 2000);//left
	DrawCircle(236 + 400, 1350 - 20, 55, 2000);//left
	DrawCircle(360 + 400, 1374 - 20, 55, 2000);//right
	DrawCircle(400 + 400, 1324 - 20, 55, 2000);//right
	DrawCircle(290 + 400, 1393, 60, 2000);//top
	DrawCircle(296 + 400, 1296, 80, 2000);//middle

	glColor3f(0.933, 0.933, 0.933);
	DrawCircle(200 + 400, 1280 - 20, 60, 2000);//1
	DrawCircle(240 + 400, 1350 - 20, 55, 2000);//2
	DrawCircle(360 + 400, 1370 - 20, 55, 2000);//3
	DrawCircle(400 + 400, 1320 - 20, 55, 2000);//4
	DrawCircle(290 + 400, 1390, 60, 2000);//4
	DrawCircle(300 + 400, 1300, 80, 2000);//middle

	glColor3f(0.447, 0.624, 0.812);//last
	DrawCircle(96 + 1400, 1280 - 20, 60, 2000);//left
	DrawCircle(136 + 1400, 1350 - 20, 55, 2000);//left
	DrawCircle(260 + 1400, 1374 - 20, 55, 2000);//right
	DrawCircle(300 + 1400, 1324 - 20, 55, 2000);//right
	DrawCircle(190 + 1400, 1393, 60, 2000);//top
	DrawCircle(196 + 1400, 1296, 80, 2000);//middle

	glColor3f(0.933, 0.933, 0.933);//last
	DrawCircle(100 + 1400, 1280 - 20, 60, 2000);//1
	DrawCircle(140 + 1400, 1350 - 20, 55, 2000);//2
	DrawCircle(260 + 1400, 1370 - 20, 55, 2000);//3
	DrawCircle(300 + 1400, 1320 - 20, 55, 2000);//4
	DrawCircle(190 + 1400, 1390, 60, 2000);//4
	DrawCircle(200 + 1400, 1300, 80, 2000);//middle
}

void nightcloud(int x)
{
	glColor3f(0.447, 0.447, 0.447);
	DrawCircle(196 + 400, 1280 - 20, 60, 2000);//left
	DrawCircle(236 + 400, 1350 - 20, 55, 2000);//left
	DrawCircle(360 + 400, 1374 - 20, 55, 2000);//right
	DrawCircle(400 + 400, 1324 - 20, 55, 2000);//right
	DrawCircle(290 + 400, 1393, 60, 2000);//top
	DrawCircle(296 + 400, 1296, 80, 2000);//middle

	glColor3f(0.733, 0.733, 0.733);
	DrawCircle(200 + 400, 1280 - 20, 60, 2000);//1
	DrawCircle(240 + 400, 1350 - 20, 55, 2000);//2
	DrawCircle(360 + 400, 1370 - 20, 55, 2000);//3
	DrawCircle(400 + 400, 1320 - 20, 55, 2000);//4
	DrawCircle(290 + 400, 1390, 60, 2000);//4
	DrawCircle(300 + 400, 1300, 80, 2000);//middle

	glColor3f(0.447, 0.447, 0.447);//last
	DrawCircle(96 + 1400, 1280 - 20, 60, 2000);//left
	DrawCircle(136 + 1400, 1350 - 20, 55, 2000);//left
	DrawCircle(260 + 1400, 1374 - 20, 55, 2000);//right
	DrawCircle(300 + 1400, 1324 - 20, 55, 2000);//right
	DrawCircle(190 + 1400, 1393, 60, 2000);//top
	DrawCircle(196 + 1400, 1296, 80, 2000);//middle

	glColor3f(0.733, 0.733, 0.733);//last
	DrawCircle(100 + 1400, 1280 - 20, 60, 2000);//1
	DrawCircle(140 + 1400, 1350 - 20, 55, 2000);//2
	DrawCircle(260 + 1400, 1370 - 20, 55, 2000);//3
	DrawCircle(300 + 1400, 1320 - 20, 55, 2000);//4
	DrawCircle(190 + 1400, 1390, 60, 2000);//4
	DrawCircle(200 + 1400, 1300, 80, 2000);//middle
}

void movecloud()
{
	if(cloudStatus == 1)
	{
		cloudX -= 1;
		w += 1;

	}
	if(cloudX<-1500)
	{
		cloudX = 2000;
	}
	glPushMatrix();
	glTranslatef(cloudX, cloudY, 0);
	if(n==0)
	{
		cloud(1);
	}
	else if(n==1)
	{
		nightcloud(1);
	}
	glPopMatrix();
}

void keyboard(unsigned char key, int x, int y)
{
	if(key=='1')
	{
		n = 1;
	}
	else if(key=='0')
	{
		n = 0;
	}
	else if (key == 'B' || key == 'b')
	{
		boatstatus = 1;
	}
	else if (key == 'S' || key == 's')
	{
		boatstatus = 0;
	}
	else if(key == 'P' || key == 'p')
	{
		planestatus = 1;
	}
	else if (key == 'O' || key == 'o')
	{
		planestatus = 0;
	}
}

void myDisplay(void)
{
	sky();
	skynight();
	sun();
	moon();
	movecloud();
	river();
	rivernight();
	moveplane();
	city();
	bridge();
	field();
	fieldnight();
	moveboat();
	tree();
	treenight();

	glFlush();
	glutPostRedisplay();
	glutSwapBuffers();
}

void myInit(void)
{
	glClearColor(0.0, 0.0, 1.0, 0.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 2000.0, 0.0, 1500.0);
}

void main(int argc, char** argv)
{
	cout<<"Press 0 for day effect\nPress 1 for night effect\nPress B for boat move\nPress S for boat stop\nPress P for plane move\nPress O for plane stop";
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(2000, 1500);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("Group-8!");
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
