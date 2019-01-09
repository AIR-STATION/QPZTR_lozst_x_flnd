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
	reshape(800, 600);
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
	glOrtho(0, 800, 0, 600, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void S00Logo::keyboard(int key, bool pressed, int x, int y, bool special)
{
	if (pressed)
		switch (key)
		{
		case 'a':
			break;
		}
}

void S00Logo::mouse(int button, bool pressed, int x, int y)
{

}

void S00Logo::motion(bool pressed, int x, int y)
{

}

void S00Logo::render()
{
	whitespace();
}

void S00Logo::update(float fDeltaTime)
{
	
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

void S00Logo::loading()
{
	std::ifstream file("test.csv");

	if (file.fail())  //만약 bad() 함수가 실패 하면..
	{
		printf("해당 경로에 위치하는 파일이 존재하지 않습니다.");
		return;
	}
	while (file.good()) //eof, bad, fail 함수가 거짓의 참을 반환할 때까지..
	{
		std::vector<std::string> row = config->csv_read_row(file, ',');

		if (!row[0].find("#")) //만약 csv 파일 안에 # 문자가 있을경우
		{
			continue; //그냥 건너 뛰어라
		}
		else //#문자가 없을 경우
		{
			for (int i = 0, leng = row.size() - 2; i<leng; i++)
				printf("%f", strtof((row[i]).c_str(), 0)); //알맞게 출력
		}
	}

	file.close(); //파일 입출력 완료 후 닫아준다.

	return;

}
