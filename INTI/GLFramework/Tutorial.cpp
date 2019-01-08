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

	print("Press Space bar to Start", -50, 0, -150);
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
}

void S02Tutorial::motion(bool pressed, int x, int y)
{
}

void S02Tutorial::update(float fDeltaTime)
{
}
