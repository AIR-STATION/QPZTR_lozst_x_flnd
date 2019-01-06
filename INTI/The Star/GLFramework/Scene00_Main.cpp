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

}

void S00Logo::exit()
{
}

void S00Logo::reset()
{
}

void S00Logo::render()
{
	
	print("Test Page", 0, 0, -150);
}

void S00Logo::reshape(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	glOrtho(0, 800, 0, 600, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}

void S00Logo::keyboard(int key, bool pressed, int x, int y, bool special)
{
	if (pressed)
		switch (key)
		{
		case '1': m_Framework->toScene("Opening"); break;
		case '2': m_Framework->toScene("Tutorial"); break;
		case '3': m_Framework->toScene("Ingame"); break;
		}
		
}

void S00Logo::mouse(int button, bool pressed, int x, int y)
{
}

void S00Logo::motion(bool pressed, int x, int y)
{
}

void S00Logo::update(float fDeltaTime)

{
}
