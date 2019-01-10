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
	void MouseWidget();
	void loading();
private:

	SettingData* config = SettingData::getInstance();

	std::vector<std::string> row;

	int date[10000];
	float data[10000][3];
	int dataNum;

	bool dateGrid;
	//
	float max;
	float min;
	float wideFix;
	float step_per_pixel;
	//

	int mx, my;
	bool clicked;
	bool mouseGrid;
};

