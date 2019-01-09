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

	SamplingRate = 0;
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

		switch (key)
		{
			//TODO: Create Process made by python to Load Data
		case ' ': m_Framework->toScene("Main"); break;
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
	glColor3f(0.f, 0.f, 0.f);
	print("Settings", -110, 85, -150);
	print("Sampling Rate", -110, 45, -150);
	print("1         3        5        10        min.", -32.5f, 45, -150);
	print("Date", -92, 20, -150);
	
	SelectionUI_SamplingRate();
	SelectionUI_Date();
}

void S02Tutorial::SelectionUI_SamplingRate()
{
	glBegin(GL_LINES);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex2f(-400.f, 45.f);
	glVertex2f(400.f, 45.f);

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

	switch (SamplingRate)
	{
	case 0:
		glVertex2f(-45.f, 24.f);
		glVertex2f(-30.f, 24.f);

		glVertex2f(-45.f, 28.f);
		glVertex2f(-30.f, 28.f);
		break;
	case 1:
		glVertex2f(-30.f, 24.f);
		glVertex2f(-15.f, 24.f);

		glVertex2f(-30.f, 28.f);
		glVertex2f(-15.f, 28.f);
		break;
	case 2:
		glVertex2f(-15.f, 24.f);
		glVertex2f(0.f, 24.f);

		glVertex2f(-15.f, 28.f);
		glVertex2f(0.f, 28.f);
		break;
	case 3:
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

	glEnd();
}

void S02Tutorial::SelectProcess(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		if (x > 147 + 84 * i && x < 147 + 84 * (i + 1))
			if (y > 430 && y < 460)
				SamplingRate = i;
	}
}