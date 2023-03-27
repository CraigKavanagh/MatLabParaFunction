#pragma once
#include<vector>
#include<SFML/System/Vector2.hpp>
using namespace std;

typedef sf::Vector2f Vec2;

class Curve{
protected:
	vector<Vec2> points;
	float lastT = 0;
	int iterationsPerTimeStep = 1;

public:
	virtual Vec2 getPoint(float t) = 0 ;

	virtual vector<Vec2>& getNextPoints(float t) = 0 ;

	virtual void reset() {
		lastT = 0;
		points.clear();
	}
};


class FunctionOfX: public Curve{
	float (*fn)(float);
	
public:
	FunctionOfX(float (*fn)(float), int ipts = 1) :fn(fn) {
		iterationsPerTimeStep = ipts;
	}
	Vec2 getPoint(float t);
	vector<Vec2>& getNextPoints(float t);
};

class Parametric : public Curve {
	Vec2 (*fn)(float);

public:
	Parametric(Vec2 (*fn)(float), int ipts = 1) :fn(fn) {
		iterationsPerTimeStep = ipts;
	}
	Vec2 getPoint(float t);
	vector<Vec2>& getNextPoints(float t);
};