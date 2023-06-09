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
#include<vector>
#include<iostream>
#include <SFML\System\Vector2.hpp>
#include <stdexcept> // To use runtime_error


using namespace std;
using namespace sf;

typedef vector<Vector2f> PointList;

class ThickLine
{
public:
	static Vector2f norm(Vector2f v) {
		float len = sqrt(v.x * v.x + v.y * v.y);
		return v / len;
	}

	static Vector2f getNormal(Vector2f p, Vector2f next) {
		Vector2f line = next - p;
		return norm(Vector2f(-line.y, line.x));
	}

	static float sqLen(Vector2f v) {
		float slen = v.x * v.x + v.y * v.y;
		return slen;
	}

	static bool len(Vector2f v) {
		
		return sqrt(v.x * v.x + v.y * v.y) < 0.5;
	}

	static void convert(PointList& in, PointList& out, float width) {

		float epsilon = 25;
		if (1 >= in.size()) return;

		int i = 0;
		float thickness = width / 2;
		for (auto p : in) {
			try {
				//Vector2f p1 = in[i + 1];
				if (i == 0 or i == in.size() - 1) {


					Vector2f normal;
					if (i == 0) normal = getNormal(p, in[i + 1]);
					else        normal = getNormal(in[i - 1], p);

					Vector2f a = p - thickness * normal;
					Vector2f b = p + thickness * normal;
					


					out.push_back(a);
					out.push_back(b);
				}
				else {

					Vector2f normal = getNormal(p, in[i + 1]);

					//Vector2f tangent = norm(norm(in[i + 1] - p) + norm(p - in[i - 1])); // suspect
					Vector2f tangent = norm(in[i + 1] - p);

					Vector2f miter = Vector2f(-tangent.y, tangent.x); //normal of the tangent

					//The length of the miter can be found by projecting it on one of the normals, using the dot product :
					float length = thickness / (miter.x * normal.x + miter.y * normal.y);
					Vector2f a = p - length * miter;
					Vector2f b = p + length * miter;


					
					out.push_back(a);
					out.push_back(b);
				}
			}
			catch (runtime_error& e) {
				;//cout << e.what();
			}

			i++;
		}

	}
};

