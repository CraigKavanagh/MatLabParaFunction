#include "curve.h"
Vec2 FunctionOfX::getPoint(float t) {
	return Vec2(t, fn(t));
}

vector<Vec2>& FunctionOfX::getNextPoints(float t){

	points.clear();

	int iterations = iterationsPerTimeStep;
	double step = (t - lastT) / iterations;


	for (double rt = lastT; rt < t; rt += step) {
		points.push_back(getPoint(rt));
	}

	lastT = t;

	return points;
}



Vec2 Parametric::getPoint(float t) {
	return fn(t);
}

vector<Vec2>& Parametric::getNextPoints(float t) {
	
	points.clear();

	int iterations = iterationsPerTimeStep;
	double step = (t - lastT) / iterations;


	for (double rt = lastT; rt < t; rt += step) {
		points.push_back(getPoint(rt));
	}

	lastT = t;

	return points;
}
