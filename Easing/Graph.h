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
#include"Viewport.h"

using namespace std;


typedef vector<sf::Vector2f> PointList;

struct Curve{
	PointList points;
	sf::Color color = sf::Color::White;
	float thickness = 1;

};
class Graph
{
	static const int MAX_POINTS = 50000;
	sf::Vertex* line;

	vector<Curve*> curves;
	sf::Font font;

	sf::RenderWindow& window;

public:
	static const int Unit{ 500 };

	Graph(sf::RenderWindow& window):window(window) {
		font.loadFromFile("cmr12.ttf");
		line = new sf::Vertex[MAX_POINTS];
	};
	void drawGraph();
	void addPoint(int i, sf::Vector2f point);
	void reset();
	void addCurve(sf::Color color = sf::Color::White, float thinckness = 0.005){
		auto curve = new Curve;
		curve->color = color;
		curve->thickness = thinckness;
		curves.push_back(curve);
	}

	void centredText(string s, sf::Vector2f pos, int size=50, bool rightJust=false) {
		auto text = sf::Text{s, font };
		text.setCharacterSize(size);
		text.setScale(1,-1);
		auto lb = text.getLocalBounds();
		auto gb = text.getGlobalBounds();

		auto center = sf::Vector2f(text.getGlobalBounds().width / (rightJust ? 1.f : 2.f), text.getGlobalBounds().height / 2.f);
		//auto localBounds = center + sf::Vector2f(text.getLocalBounds().width/(rightJust ? 1. : 2.),  +text.getLocalBounds().height/2.);

		text.setOrigin(center.x, center.y);
		text.setPosition(pos);
		window.draw(text);
	}
};

