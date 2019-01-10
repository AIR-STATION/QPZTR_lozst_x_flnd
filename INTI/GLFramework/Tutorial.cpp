#include "stdafx.h"
#include "Tutorial.h"
#include "GLFramework.h"

S02Tutorial::S02Tutorial()
{
}

S02Tutorial::~S02Tutorial()
{
}

void S02Tutorial::init()
{
	m_Camera.setDistance(200.f);
	m_Camera.setPerspective(30.f, 0.125f, 3500.f);
	m_Camera.setSensitivity(1.f);

	putDate_one = false;
	putDate_two = false;

	tmp_startDate = 0;
	tmp_endDate = 0;
}

void S02Tutorial::exit()
{

}

void S02Tutorial::reset()
{
}

void S02Tutorial::render()
{
	m_Camera.ready();
	whitespace();
	SelectionUI();
}

void S02Tutorial::reshape(int w, int h)
{

}

void S02Tutorial::keyboard(int key, bool pressed, int x, int y, bool special)
{
	if (pressed)
	{
		switch (key)
		{
			case ' ': m_Framework->toScene("Main"); break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				if (putDate_one)
				{
					if (tmp_startDate < 10000000)
					tmp_startDate = tmp_startDate*10 + (key-48);
				}
				else if (tmp_endDate < 10000000)
				{
					tmp_endDate = tmp_endDate * 10 + (key - 48);
				}
			break;
		}
	}
}

void S02Tutorial::mouse(int button, bool pressed, int x, int y)
{
	if (pressed)
	{
		printf("%d %d\n", x, DEF_WIN_HEIGHT - y);
		SelectProcess(x, DEF_WIN_HEIGHT - y);
	}
}

void S02Tutorial::motion(bool pressed, int x, int y)
{
}

void S02Tutorial::update(float fDeltaTime)
{
}

void S02Tutorial::whitespace()
{
	glColor3f(0.88f, 0.88f, 0.88f);
	glBegin(GL_QUADS);
	glVertex2f(-DEF_WIN_WIDTH, -DEF_WIN_HEIGHT);
	glVertex2f(-DEF_WIN_WIDTH, DEF_WIN_HEIGHT);
	glVertex2f(DEF_WIN_WIDTH, DEF_WIN_HEIGHT);
	glVertex2f(DEF_WIN_WIDTH, -DEF_WIN_HEIGHT);
	glEnd();
}

void S02Tutorial::SelectionUI()
{
	glLineWidth(2.f);
	glColor3f(0.65f, 0.59f, 0.62f);
	glBegin(GL_QUADS);
	glVertex2f(50.f, -42.f);
	glVertex2f(50.f, -31.f);

	glVertex2f(25.f, -31.f);
	glVertex2f(25.f, -42.f);
	glEnd();

	glColor3f(0.12f, 0.12f, 0.12f);
	print("Settings", -110, 85, -150);
	print("Sampling Rate", -110, 45, -150);
	print("D         m        s         t        tick.", -32.5f, 45, -150);
	print("Date", -92, 20, -150);
	print("Next", 63, -65, -150);

	if (tmp_startDate > 0)
	{
		char tmp[9];
		sprintf(tmp, "%d", tmp_startDate);
		print(tmp, -65, 20, -150);
	}
	if (tmp_endDate > 0)
	{
		char tmp[9];
		sprintf(tmp, "%d", tmp_endDate);
		print(tmp, -10, 20, -150);
	}
	

	SelectionUI_SamplingRate();
	SelectionUI_Date();

}

void S02Tutorial::SelectionUI_SamplingRate()
{
	glBegin(GL_LINES);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex2f(-100.f, 45.f);
	glVertex2f(100.f, 45.f);

	glColor3f(0.40f, 0.40f, 0.40f);
	glVertex2f(-45.f, 24.f);
	glVertex2f(-45.f, 28.f);

	glVertex2f(-30.f, 24.f);
	glVertex2f(-30.f, 28.f);

	glVertex2f(-15.f, 24.f);
	glVertex2f(-15.f, 28.f);

	glVertex2f(0.f, 24.f);
	glVertex2f(0.f, 28.f);

	glVertex2f(15.f, 28.f);
	glVertex2f(15.f, 24.f);

	glColor3f(0.8f, 0.2f, 0.2f);
	switch (config->SamplingRate)
	{
	case 0:
		
		glVertex2f(-45.f, 24.f);
		glVertex2f(-45.f, 28.f);

		glVertex2f(-30.f, 24.f);
		glVertex2f(-30.f, 28.f);

		glVertex2f(-45.f, 24.f);
		glVertex2f(-30.f, 24.f);

		glVertex2f(-45.f, 28.f);
		glVertex2f(-30.f, 28.f);
		break;
	case 1:
		glVertex2f(-30.f, 24.f);
		glVertex2f(-30.f, 28.f);

		glVertex2f(-15.f, 24.f);
		glVertex2f(-15.f, 28.f);

		glVertex2f(-30.f, 24.f);
		glVertex2f(-15.f, 24.f);

		glVertex2f(-30.f, 28.f);
		glVertex2f(-15.f, 28.f);
		break;
	case 2:
		glVertex2f(-15.f, 24.f);
		glVertex2f(-15.f, 28.f);

		glVertex2f(0.f, 24.f);
		glVertex2f(0.f, 28.f);

		glVertex2f(-15.f, 24.f);
		glVertex2f(0.f, 24.f);

		glVertex2f(-15.f, 28.f);
		glVertex2f(0.f, 28.f);
		break;
	case 3:
		glVertex2f(0.f, 24.f);
		glVertex2f(0.f, 28.f);

		glVertex2f(15.f, 28.f);
		glVertex2f(15.f, 24.f);

		glVertex2f(0.f, 24.f);
		glVertex2f(15.f, 24.f);

		glVertex2f(0.f, 28.f);
		glVertex2f(15.f, 28.f);
		break;
	}
	glEnd();
}

void S02Tutorial::SelectionUI_Date()
{
	glBegin(GL_LINES);
	glColor3f(0.40f, 0.40f, 0.40f);
	glVertex2f(-45.f, 10.f);
	glVertex2f(-45.f, 14.f);

	glVertex2f(-15.f, 10.f);
	glVertex2f(-15.f, 14.f);

	glVertex2f(15.f, 10.f);
	glVertex2f(15.f, 14.f);

	if (putDate_one)
	{
		glVertex2f(-45.f, 10.f);
		glVertex2f(-15.f, 10.f);

		glVertex2f(-45.f, 14.f);
		glVertex2f(-15.f, 14.f);
	}
	if (putDate_two)
	{
		glVertex2f(-15.f, 10.f);
		glVertex2f(15.f, 10.f);
		
		glVertex2f(-15.f, 14.f);
		glVertex2f(15.f, 14.f);
	}

	glEnd();
}

void S02Tutorial::SelectProcess(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		if (x > 147 + 84 * i && x < 147 + 84 * (i + 1))
			if (y > 430 && y < 460)
				config->SamplingRate = i;
	}
	//
	if (x > 147 && x < 147 + 168)
		if (y > 340 && y < 390)
		{
			if (putDate_one)
			{
				putDate_one = false;
			}
			else
			{
				putDate_one = true;
				putDate_two = false;
			}
		}
	if (x > 147 + 168 && x < 147 + 168 + 168)
		if (y > 340 && y < 390)
		{
			if (putDate_two)
			{
				putDate_two = false;
			}
			else
			{
				putDate_two = true;
				putDate_one = false;
			}
		}
	//

	if (x > 541 && x < 680)
		if (y > 66 && y < 125)
		{
			config->Date_From = tmp_startDate;
			config->Date_To = tmp_endDate;

			//Save csv for DataCrop (tick,startDate,endDate)
			config->save();		
			//Create Process made by python to Load Data
			config->LoadData();
			
			m_Framework->toScene("Main");
		}
}
