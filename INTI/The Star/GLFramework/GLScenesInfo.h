#pragma once
#define _SCENES_
/*--------------------ADD SCENES HERE--------------------*/

/*~~~~~HEADER FILES~~~~*/
#include "Scene00_Main.h"
#include "Tutorial.h"

struct GLSceneInfo
{
	std::string name;
	GLScene*	pScene;
	bool		bInitAtStart{ true };
};

/*~~~~~~~SCENES~~~~~~~*/
const GLSceneInfo SCENES[] =
{
	{"Main", new S00Logo, false},
	{"Tutorial", new S02Tutorial, true},
};

/*~~~STARTING SCENE~~~*/
const std::string STARTING_SCENE { "Tutorial" };

/*-------------------------------------------------------*/
