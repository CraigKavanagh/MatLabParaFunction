#pragma once
#include <SFML\Graphics.hpp>

class Viewport
{
	int width;
	int height;
	int xOrigin;
	int yOrigin;
	int windowHeight;
	int windowWidth;

public:
	Viewport(int w, int h, int x, int y, int ww, int wh) :width(w), height(h), xOrigin(x), yOrigin(y), windowWidth(ww), windowHeight(wh) {};
	sf::Vector2f screenSpace(sf::Vector2f point);
};

