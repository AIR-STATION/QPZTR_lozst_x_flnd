#pragma once
#include "GLScene.h"

/* UTILITIES */
#include "SettingData.h"

/* ------------ */

class S00Logo :
	public GLScene
{
public:
	S00Logo();
	virtual ~S00Logo();

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
	void UI();
	void DrawGraph();
	void loading();
private:

	SettingData* config = SettingData::getInstance();

	std::vector<std::string> row;

	float data[10000];
	int dataNum;
};

