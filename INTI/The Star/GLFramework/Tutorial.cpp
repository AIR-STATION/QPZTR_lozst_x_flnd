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
	m_SoundPlayer.init();
	m_SoundPlayer.selectFolder("Resources");

	m_Camera.setDistance(200.f);
	m_Camera.setPerspective(30.f, 0.125f, 3500.f);
	m_Camera.setSensitivity(1.f);

	m_SoundPlayer.play();
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

	print("Press Space bar to Start                                      ...And \"b\" for One Shot.", -50, 0, -150);
	print("BGM : Septentrion", 100, 100, -150);
}

void S02Tutorial::reshape(int w, int h)
{

}

void S02Tutorial::keyboard(int key, bool pressed, int x, int y, bool special)
{
	if (pressed)

		switch (key)
		{
		case ' ': m_Framework->toScene("Opening"); break;
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
