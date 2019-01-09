#pragma once
#include "GLScene.h"

/* UTILITIES */
#include "Camera.h"
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

	void whitespace();
	void SelectionUI();
	void SelectionUI_SamplingRate();
	void SelectionUI_Date();
	void SelectProcess(int x, int y);
private:
	
	Camera	m_Camera;

	//
	int SamplingRate;
	//
};

