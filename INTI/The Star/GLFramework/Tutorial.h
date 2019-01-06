#pragma once
#include "GLScene.h"

/* UTILITIES */
#include "Camera.h"
#include "SoundPlayer.h"
/* ------------ */

class S02Tutorial :
	public GLScene
{
public:
	S02Tutorial();
	virtual ~S02Tutorial();

	virtual void init();
	virtual void exit();
	virtual void reset();
	virtual void render();
	virtual void reshape(int w, int h);
	virtual void keyboard(int key, bool pressed, int x, int y, bool special);
	virtual void mouse(int button, bool pressed, int x, int y);
	virtual void motion(bool pressed, int x, int y);
	virtual void update(float fDeltaTime);

private:

	Camera	m_Camera;

	SoundPlayer	m_SoundPlayer;
};
