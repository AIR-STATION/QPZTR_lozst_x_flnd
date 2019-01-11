#include "stdafx.h"
#include "Scene00_Main.h"
#include "GLFramework.h"

S00Logo::S00Logo()
{
}

S00Logo::~S00Logo()
{
}

void S00Logo::init()
{
	printf("\n\n");
	reshape(800, 600);
	ZeroMemory(data, sizeof(float) * 30000);
	dataNum = 0;
	loading();

	dateGrid = true;

	mx = 0;
	my = 0;

	//그래프 상하 축척 수정
	max = 0.f;
	min = 100000.f;
	wideFix = 1.f;

	for (int i = 0; i < dataNum; i++)
	{
		if (data[i][2] > max)
			max = data[i][2];
		if (data[i][2] < min)
			min = data[i][2];
	}
	wideFix = max - min;
	step_per_pixel = wideFix / 480.f;

	clicked = false;
	mouseGrid = true;
	drag = false;

	ZoomIn = 0;

	xDist = 0;
	yDist = 0;
	drag_mouse_xy[0] = 0;
	drag_mouse_xy[1] = 0;
}

void S00Logo::exit()
{
}

void S00Logo::reset()
{
}

void S00Logo::reshape(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	glOrtho(0 + xDist, 800 + xDist, 0 + yDist, 600 + yDist, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}

void S00Logo::loading()
{
	std::ifstream file("data.csv");

	if (file.fail())  //만약 bad() 함수가 실패 하면..
	{
		printf("해당 경로에 위치하는 파일이 존재하지 않습니다.");
		return;
	}
	while (file.good()) //eof, bad, fail 함수가 거짓의 참을 반환할 때까지..
	{
		row = config->csv_read_row(file, ',');

		if (row.size() == 1)
		{
			//data num 받아올 수 있긴 한데... 의미가 없어졌음
			continue;
		}
		if (!row[0].find("#")) //만약 csv 파일 안에 # 문자가 있을경우
		{
			continue; //그냥 건너 뛰어라
		}
		else //#문자가 없을 경우
		{
			for (int i = 0, leng = row.size(); i < leng; i++)
			{
				if (i == 0)
				{
					date[dataNum] = atoi((row[i]).c_str());
				}
				else
				{
					data[dataNum][i] = strtof((row[i]).c_str(), 0);
				}
			}
			dataNum++;
		}
	}

	file.close(); //파일 입출력 완료 후 닫아준다.

	return;

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void S00Logo::keyboard(int key, bool pressed, int x, int y, bool special)
{
	if (pressed)
		switch (key)
		{
		case 'g': if (dateGrid) dateGrid = false; else dateGrid = true; break;
		case 'm': if (mouseGrid) mouseGrid = false; else mouseGrid = true; break;
		case '+': ZoomIn += 10; reshape(800 + ZoomIn, 600 + ZoomIn); break;
		case '-': ZoomIn -= 10; reshape(800 + ZoomIn, 600 + ZoomIn); break;
		}
}

void S00Logo::mouse(int button, bool pressed, int x, int y)
{
	if (button == 0)		//LEFT MOUSE BUTTON
	{
		if (pressed)
		{
			clicked = true;
		}
		else
		{
			clicked = false;
		}
	}
	else if (button == 2)	//RIGHT MOUSE BUTTON
	{
		if (pressed)
		{
			drag = true;
			drag_mouse_xy[0] = xDist + x;
			drag_mouse_xy[1] = yDist + 600-y;
		}
		else
		{
			drag = false;
			if (xDist < 0)
			{
				xDist = 0;
			}
			if (ZoomIn < point(xDist))
			{
				xDist = (float)(ZoomIn / (float)(800.f+ZoomIn)) * 800.f;
			}
			if (yDist < 0)
			{
				yDist = 0;
			}
			if (ZoomIn < point(yDist))
			{
				yDist = (float)(ZoomIn / (float)(600.f + ZoomIn)) * 600.f;
			}
			reshape(800 + ZoomIn, 600 + ZoomIn);
		}
	}
	else if (button == 3)
	{
		ZoomIn += 5;
		reshape(800 + ZoomIn, 600 + ZoomIn);
	}
	else if (button == 4)
	{
		ZoomIn -= 5;
		reshape(800 + ZoomIn, 600 + ZoomIn);
	}
}

void S00Logo::motion(bool pressed, int x, int y)
{
	mx = x;
	my = y;
	if (drag)
	{
		xDist = drag_mouse_xy[0] - x;
		yDist = drag_mouse_xy[1] - (600-y);
		reshape(800 + ZoomIn, 600 + ZoomIn);
	}
}

void S00Logo::render()
{
	whitespace();
	UI();
	DrawGraph();
	MouseWidget();
}

void S00Logo::update(float fDeltaTime)
{
	if (ZoomIn < 0)
	{
		ZoomIn = 0;
		reshape(800 + ZoomIn, 600 + ZoomIn);
	}
}

void S00Logo::whitespace()
{
	glColor3f(0.88f, 0.88f, 0.88f);
	glBegin(GL_QUADS);
	glVertex2f(0.f, 0.f);
	glVertex2f(0.f, DEF_WIN_HEIGHT);
	glVertex2f(DEF_WIN_WIDTH, DEF_WIN_HEIGHT);
	glVertex2f(DEF_WIN_WIDTH, 0.f);
	glEnd();
}

void S00Logo::UI()
{
	glLineWidth(2.f);
	glBegin(GL_LINES);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex2f(0.f, 560.f);
	glVertex2f(800.f, 560.f);
	glVertex2f(0.f, 40.f);
	glVertex2f(800.f, 40.f);
	glEnd();

	glColor3f(0.2f, 0.2f, 0.2f);
	//char tmp[22];
	//sprintf(tmp, "%d ~ %d", config->Date_From, config->Date_To);
	//print(tmp, 20, 575, 0);

	char tmp2[60];
	sprintf(tmp2, "Sampling Rate : %d   (0:Date, 1:minute, 2: second, 3: tick)",config->SamplingRate);
	print(tmp2, 60, 20, 0);
	
	for (int i = 0; i < dataNum - 1; i++)
	{
		if ((i == 0 || date[i] != date[i - 1]))
		{
			char tmp[20];
			sprintf(tmp, "%d", date[i]);
			print(tmp, 730.f - (800.f / (float)(dataNum - 1)) * (float)(i), 570, 0);
		}
	}
	char _tmp[20];
	sprintf(_tmp, "%.2f", max);
	print(_tmp, 745.f, 545.f, 0);

	char _tmp2[20];
	sprintf(_tmp2, "%.2f", min);
	print(_tmp2, 745.f, 65.f, 0);

	for (int i = 1; i < 4; i++)
	{
		char tmp[20];
		sprintf(tmp, "%.2f", min + (step_per_pixel*120.f) * i);
		print(tmp, 745.f, 65.f + 120.f*i, 0);
	}

	if (mouseGrid && my < 560 && my > 40)
	{
		float mouse_on_chart = ((600.f - my) - 60.f) * step_per_pixel + min;

		char _tmp3[20];
		sprintf(_tmp3, "%.2f", mouse_on_chart);
		print(_tmp3, 745.f, 600.f - (my - 5.f), 0);
	}
}

void S00Logo::DrawGraph()
{
	//
	glLineWidth(0.8f);
	glBegin(GL_LINES);

	glColor3f(0.76f, 0.76f, 0.76f);
	for (int i = 0; i < 5; i++)
	{
		glVertex2d(0.f, 60.f + 120.f*i);
		glVertex2d(800.f, 60.f + 120.f*i);
	}
	
	glVertex2d(0.f, 300.f);
	glVertex2d(800.f, 300.f);
	glVertex2d(0.f, 420.f);
	glVertex2d(800.f, 420.f);

	for (int i = 0; i < dataNum - 1; i++)
	{
		if ((i == 0 || date[i] != date[i - 1]) && dateGrid)
		{
			glColor3f(0.32f, 0.32f, 0.32f);
			glVertex2f(800.f - (800.f / (float)(dataNum - 1)) * (float)i, 40.f);
			glVertex2f(800.f - (800.f / (float)(dataNum - 1)) * (float)i, 560.f);
		}

		if (data[i + 1][2] - data[i][2] > 0)
			glColor3f(0.12f, 0.12f, 0.95f);
		else
			glColor3f(0.95f, 0.12f, 0.12f);
		glVertex2f(800.f - (800.f / (float)(dataNum - 1)) * (float)i,(data[i][2] - min) /wideFix * 480.f + 60.f);
		glVertex2f(800.f - (800.f / (float)(dataNum - 1)) * (float)(i + 1), (data[i+1][2] - min) / wideFix * 480.f + 60.f);

		if (data[i][2] == max)
		{
			glColor3f(0.9f, 0.2f, 0.3f);
			glVertex2f(800.f - (800.f / (float)(dataNum - 1)) * (float)i, 540.f);
			glVertex2f(800.f, 540.f);
		}
		if (data[i][2] == min)
		{
			glColor3f(0.3f, 0.2f, 0.9f);
			glVertex2f(800.f - (800.f / (float)(dataNum - 1)) * (float)i, 60.f);
			glVertex2f(800.f, 60.f);
		}
	}
	
	

	glEnd();
}

void S00Logo::MouseWidget()
{
	if (mouseGrid && my < 560 && my > 40)
	{
		glLineWidth(0.8f);
		glColor3f(0.35f, 0.35f, 0.35f);

		glBegin(GL_LINES);
		glVertex2f(0.f, 600.f-my);
		glVertex2f(800.f, 600.f-my);
		glVertex2f(mx, 40.f);
		glVertex2f(mx, 560.f);
		glEnd();
	}
	if (clicked && my < 560 && my > 40)
	{
		// 이거 나중에하셈
		/*glColor3f(0.9f, 0.9f, 0.6f);
		glBegin(GL_QUADS);
		glVertex2f(mx + 5.f, 600.f-(my + 5.f));
		glVertex2f(mx + 5.f, 600.f- (my + 60.f));
		glVertex2f(mx + 80.f, 600.f - (my + 60.f));
		glVertex2f(mx + 80.f, 600.f - (my + 5.f));
		glEnd();*/

		float tmp_ending_cost = 0.f;
		for (int i = 0; i < dataNum - 1; i++)
		{
			if (800.f - (800.f / (float)(dataNum - 1)) * (float)i > mx && 800.f - (800.f / (float)(dataNum - 1)) * (float)(i+1) < mx)
			{
				tmp_ending_cost = data[i][2];
			}
		}
		char _tmp[20];
		sprintf(_tmp, "%.2f", tmp_ending_cost);
		print(_tmp, mx + 10.f, 600.f-(my-5.f), 0);
	}
}

int S00Logo::point(int location)
{
	return location + ((float)(location*ZoomIn)/800.f);
}

float S00Logo::point(float location)
{
	return location + ((location*(float)ZoomIn) / 800.f);
}