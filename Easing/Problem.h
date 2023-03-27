/*==============================================================================
Do not edit any code in this file!!!


██████   ██████      ███    ██  ██████  ████████     ███████ ██████  ██ ████████
██   ██ ██    ██     ████   ██ ██    ██    ██        ██      ██   ██ ██    ██
██   ██ ██    ██     ██ ██  ██ ██    ██    ██        █████   ██   ██ ██    ██
██   ██ ██    ██     ██  ██ ██ ██    ██    ██        ██      ██   ██ ██    ██
██████   ██████      ██   ████  ██████     ██        ███████ ██████  ██    ██


████████ ██   ██ ██ ███████     ███████ ██ ██      ███████ ██
   ██    ██   ██ ██ ██          ██      ██ ██      ██      ██
   ██    ███████ ██ ███████     █████   ██ ██      █████   ██
   ██    ██   ██ ██      ██     ██      ██ ██      ██
   ██    ██   ██ ██ ███████     ██      ██ ███████ ███████ ██

==============================================================================*/
#pragma once
#include <string>
#include<assert.h>
#include<vector>
#include<SFML/System/Vector2.hpp>
using namespace std;

typedef  sf::Vector2f Vec2;

struct Problem
{
	Problem():title(""), description(""), target(NULL), starter(NULL) { assert("default contructor should not be called"); };
	Problem(string title, int index, string description, string starterFunction,  
		float (*starter)(float), float (*target)(float), bool s=false, Vec2(*pstarter)(float) = NULL, Vec2(*ptarget)(float) =NULL, float interval = 1.0f) :
		title(title), index(index), description(description), starterFunction(starterFunction), target(target), starter(starter), showBall(s),
		pstarter(pstarter), ptarget(ptarget), interval(interval)
	{
	};
	
	bool check();
	string title;
	int index = 0;
	float interval;
	string description;
	string starterFunction;
	float lastStarterT = 0;
	float lastTargetT = 0;

	bool passing = false;
	bool showBall = false;

	float (*target)(float);
	float (*starter)(float);

	//parametric
	Vec2 (*ptarget)(float);
	Vec2 (*pstarter)(float);

	Vec2 getPointStarter(float t);
	Vec2 getPointTarget(float t);

	vector<Vec2> starterPoints;
	vector<Vec2> targetPoints;

	vector<Vec2>& getNextStarterPoints(float t);
	vector<Vec2>& getNextTargetPoints(float t);

	void reset(){
		lastStarterT = 0;
		lastTargetT = 0;
	}
};

