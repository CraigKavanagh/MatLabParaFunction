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
#include "Problem.h"

bool Problem::check() {
	float error = 0.001f;

	float t = 0;
	float step = 0.01;
	if(target && starter)
		for (; t < 1.0; t += step) {
			if (fabs(target(t) - starter(t)) > error)
				return false;
		}
	else
		for (; t < 1.0; t += step) {
			if ((fabs(ptarget(t).x - pstarter(t).x) > error || fabs(ptarget(t).y - pstarter(t).y) > error))
				return false;
		}
	return true;
}

Vec2  Problem::getPointTarget(float t) {
	t *= interval;
	Vec2 point;
	if (ptarget) {
		point = ptarget(t);
	}
	else {
		point.x = t;
		point.y = target(t);

	}
	return point;
}

Vec2  Problem::getPointStarter(float t) {
	t *= interval;
	Vec2 point;
	if (pstarter) {
		point = pstarter(t);
	}
	else {
		point.x = t;
		point.y = starter(t);
	}
	return point;
}

vector<Vec2>& Problem::getNextStarterPoints(float t) {
	starterPoints.clear();

	int iterations = (interval > 1.1) ? 20 : 1;
	double step = (t - lastStarterT) / iterations;


	for (double rt = lastStarterT; rt < t; rt += step) {
		starterPoints.push_back(getPointStarter(rt));
	}

	lastStarterT = t;

	return starterPoints;
}
vector<Vec2>& Problem::getNextTargetPoints(float t) {
	targetPoints.clear();

	int iterations = (interval > 1.1) ? 20 : 1;
	double step = (t - lastTargetT) / iterations;


	for (double rt = lastTargetT; rt < t; rt += step) {
		targetPoints.push_back(getPointTarget(rt));
	}

	lastTargetT = t;

	return targetPoints;
}