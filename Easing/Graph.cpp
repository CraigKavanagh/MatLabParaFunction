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
#include"globals.h"
#include "Graph.h"
#include <cassert>
#include"ThickLine.h"



void Graph::drawGraph() {

    float unit = Unit;
    
    sf::Vector2f origin(0, 0);
    sf::Vector2f width(1, 1);
    if (parametric) {
        width = sf::Vector2f(5, 5);
        origin = sf::Vector2f(unit/2, unit/2);
    }

    sf::Vertex boundary[5];

    boundary[0].position = sf::Vector2f(0, unit);
    boundary[0].color = sf::Color::White;
    boundary[1].position = sf::Vector2f(0, 0);
    boundary[1].color = sf::Color::White;
    boundary[2].position = sf::Vector2f(unit, 0);
    boundary[2].color = sf::Color::White;
    boundary[3].position = sf::Vector2f(unit, unit);
    boundary[3].color = sf::Color::White;
    boundary[4].position = sf::Vector2f(0, unit);
    boundary[4].color = sf::Color::White;
    window.draw(boundary, 5, sf::LineStrip);

    sf::Vertex axes[4];
    //x-axis
    axes[0].position = sf::Vector2f(0   , origin.y);
    axes[0].color = sf::Color::White;
    axes[1].position = sf::Vector2f(unit, origin.y);
    axes[1].color = sf::Color::White;
    
    //y-axis
    axes[2].position = sf::Vector2f(origin.x, 0);
    axes[2].color = sf::Color::White;
    axes[3].position = sf::Vector2f(origin.x, unit);
    axes[3].color = sf::Color::White;

    window.draw(axes, 4, sf::Lines);

    sf:Color ticKColor = sf::Color::White;
    const int NUM_TICKS = 22;
    sf::Vertex ticks[NUM_TICKS * 2];
    for (int i = 0; i < NUM_TICKS * 2; i++) {
        ticks[i].color = ticKColor;
    }
    float tickLength = 0.02 * unit;
    int i = 0;
    for (int t = 0; t <= unit; t+=(unit/10)) {
        ticks[i++].position = sf::Vector2f((float)t, origin.y);
        ticks[i++].position = sf::Vector2f((float)t, origin.y -tickLength);
    }
    for (int t = 0; t <= unit; t += (unit / 10)) {
        ticks[i++].position = sf::Vector2f(origin.x, (float)t );
        ticks[i++].position = sf::Vector2f(origin.x -tickLength, (float)t );
    }


    window.draw(ticks, NUM_TICKS * 2, sf::Lines);

    float textOffset = unit/20.0f;
    int labelTextSize = 40;
    int axisTextSize = 25;

    if (parametric) {
        //xaxis
        centredText("t", sf::Vector2f(unit / 2, -textOffset), labelTextSize);
        centredText("f(t)", sf::Vector2f(-textOffset, unit / 2), labelTextSize, true);
        centredText("-1.0", sf::Vector2f(unit * 0.3, origin.y - textOffset / 2), axisTextSize);
        centredText("1.0",  sf::Vector2f(unit * 0.7, origin.y - textOffset/2), axisTextSize);
        centredText("-2.0", sf::Vector2f(unit * 0.1, origin.y - textOffset / 2), axisTextSize);
        centredText("2.0", sf::Vector2f(unit * 0.9, origin.y - textOffset / 2), axisTextSize);
        //yaxis
        centredText("-1.0", sf::Vector2f(origin.y - textOffset/2, unit * 0.3 + textOffset / 3), axisTextSize, true);
        centredText("1.0", sf::Vector2f(origin.y - textOffset/2, unit * 0.7 + textOffset / 3), axisTextSize, true);
        centredText("-2.0", sf::Vector2f(origin.y - textOffset/2, unit * 0.1 + textOffset / 3), axisTextSize, true);
        centredText("2.0", sf::Vector2f(origin.y - textOffset/2, unit * 0.9 + textOffset / 3), axisTextSize, true);
    }
    else {
        centredText("t", sf::Vector2f(unit / 2, -textOffset), labelTextSize);
        centredText("f(t)", sf::Vector2f(-textOffset, unit / 2), labelTextSize, true);
        centredText("0.0", sf::Vector2f(0, -textOffset), axisTextSize);
        centredText("1.0", sf::Vector2f(unit, origin.y - textOffset), axisTextSize);
        centredText("0.0", sf::Vector2f(-textOffset, 0), axisTextSize, true);
        centredText("1.0", sf::Vector2f(origin.y - textOffset, unit), axisTextSize, true);
    }

    for (auto& c : curves) {
        PointList q;
        int i = 0;
        ThickLine::convert(c->points, q, c->thickness);
        for (auto& p : q) {
            assert(i < MAX_POINTS);
            line[i].position = sf::Vector2f(p.x*unit/width.x+origin.x, p.y*unit/width.y + origin.y);
            line[i].color = c->color;
            i++;
        }
        window.draw(line, i, sf::TriangleStrip);
       
        //draw endpoint
        if (c->points.size() > 0) {
            float radius = max(c->thickness*150.0f, 5.0f);
            CircleShape circle(radius);
            circle.setOrigin(radius, radius);
            circle.setFillColor(c->color);

            circle.setPointCount(10);

            Vector2f end = c->points.back();
            circle.setPosition(sf::Vector2f(end.x * unit / width.x + origin.x, end.y * unit / width.y + origin.y));

            window.draw(circle);
        }
    }    
}

void Graph::addPoint(int curve, sf::Vector2f point) {
    curves[curve]->points.push_back(point);

}

void Graph::reset() {
    for (auto& c : curves) c->points.clear();
}
