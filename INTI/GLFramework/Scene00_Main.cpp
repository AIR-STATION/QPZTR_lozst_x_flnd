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

	if (file.fail())  //���� bad() �Լ��� ���� �ϸ�..
	{
		printf("�ش� ��ο� ��ġ�ϴ� ������ �������� �ʽ��ϴ�.");
		return;
	}
	while (file.good()) //eof, bad, fail �Լ��� ������ ���� ��ȯ�� ������..
	{
		std::vector<std::string> row = config->csv_read_row(file, ',');

		if (!row[0].find("#")) //���� csv ���� �ȿ� # ���ڰ� �������
		{
			continue; //�׳� �ǳ� �پ��
		}
		else //#���ڰ� ���� ���
		{
			for (int i = 0, leng = row.size() - 2; i<leng; i++)
				printf("%f", strtof((row[i]).c_str(), 0)); //�˸°� ���
		}
	}

	file.close(); //���� ����� �Ϸ� �� �ݾ��ش�.

	return;

}
