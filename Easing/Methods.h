/*==============================================================================
 Note to Students:
 Each method in this file corresponds to one of the green curves
 plotted in the application main screen

 Your task is to modify each method so that the green curve matches 
 the grey (thicker) curve.
 
 Don't add new methods or remove any existing methods 

 Tackle these one at a time, get each one working before moving on to the next.


███    ███  ██████  ██████  ██ ███████ ██    ██     ███    ███ ███████ ████████ ██   ██  ██████  ██████      ██████   ██████  ██████  ██ ███████ ███████
████  ████ ██    ██ ██   ██ ██ ██       ██  ██      ████  ████ ██         ██    ██   ██ ██    ██ ██   ██     ██   ██ ██    ██ ██   ██ ██ ██      ██
██ ████ ██ ██    ██ ██   ██ ██ █████     ████       ██ ████ ██ █████      ██    ███████ ██    ██ ██   ██     ██████  ██    ██ ██   ██ ██ █████   ███████
██  ██  ██ ██    ██ ██   ██ ██ ██         ██        ██  ██  ██ ██         ██    ██   ██ ██    ██ ██   ██     ██   ██ ██    ██ ██   ██ ██ ██           ██
██      ██  ██████  ██████  ██ ██         ██        ██      ██ ███████    ██    ██   ██  ██████  ██████      ██████   ██████  ██████  ██ ███████ ███████ ▄█


██████  ██    ██ ████████     ██████   ██████      ███    ██  ██████  ████████      █████  ██████  ██████      ███    ██ ███████ ██     ██      ██████  ██████      ██████  ███████ ███    ███  ██████  ██    ██ ███████
██   ██ ██    ██    ██        ██   ██ ██    ██     ████   ██ ██    ██    ██        ██   ██ ██   ██ ██   ██     ████   ██ ██      ██     ██     ██    ██ ██   ██     ██   ██ ██      ████  ████ ██    ██ ██    ██ ██
██████  ██    ██    ██        ██   ██ ██    ██     ██ ██  ██ ██    ██    ██        ███████ ██   ██ ██   ██     ██ ██  ██ █████   ██  █  ██     ██    ██ ██████      ██████  █████   ██ ████ ██ ██    ██ ██    ██ █████
██   ██ ██    ██    ██        ██   ██ ██    ██     ██  ██ ██ ██    ██    ██        ██   ██ ██   ██ ██   ██     ██  ██ ██ ██      ██ ███ ██     ██    ██ ██   ██     ██   ██ ██      ██  ██  ██ ██    ██  ██  ██  ██
██████   ██████     ██        ██████   ██████      ██   ████  ██████     ██        ██   ██ ██████  ██████      ██   ████ ███████  ███ ███       ██████  ██   ██     ██   ██ ███████ ██      ██  ██████    ████   ███████


███████ ██   ██ ██ ███████ ████████ ██ ███    ██  ██████      ███    ███ ███████ ████████ ██   ██  ██████  ██████  ███████
██       ██ ██  ██ ██         ██    ██ ████   ██ ██           ████  ████ ██         ██    ██   ██ ██    ██ ██   ██ ██
█████     ███   ██ ███████    ██    ██ ██ ██  ██ ██   ███     ██ ████ ██ █████      ██    ███████ ██    ██ ██   ██ ███████
██       ██ ██  ██      ██    ██    ██ ██  ██ ██ ██    ██     ██  ██  ██ ██         ██    ██   ██ ██    ██ ██   ██      ██
███████ ██   ██ ██ ███████    ██    ██ ██   ████  ██████      ██      ██ ███████    ██    ██   ██  ██████  ██████  ███████

==============================================================================*/

#pragma once
#include"TargetFunctions.h"

sf::Vector2f line1(float t) {

    sf::Vector2f result;
    float startX =  0.0;
    float startY =  0.0;
    float endX = +1.0;
    float endY = +1.0;

    // As this is the parametric form of a line, we need to calculate and return both x(t) and y(t) 
    // We can return both x(t) and y(t) as x & y component of a vector

    result.x = startX + t*(endX - startX);
    result.y = startY + t*(endY - startY);

    return result;
}

sf::Vector2f line2(float t) {

    sf::Vector2f result;
    sf::Vector2f start(0,0);
    sf::Vector2f end;

    // what is the difference between this parametric form of a line and the previous function?

    result = start + t * (end - start);

    return result;
}

sf::Vector2f circleMove(float t) {

    //0 <= t <= 2PI
    sf::Vector2f result;

    result.x = cos(t);
    result.y = sin(t);

    return result;
}

sf::Vector2f circleScale(float t) {

    //0 <= t <= 2PI
    sf::Vector2f result;

    result.x = cos(t);
    result.y = sin(t);

    return result;
}

sf::Vector2f circleMoveAndScale(float t) {

    //0 <= t <= 2PI
    sf::Vector2f result;

    result.x = cos(t);
    result.y = sin(t);

    return result;
}

sf::Vector2f ellipse(float t) {

    //0 <= t <= 2PI
    sf::Vector2f result;

    result.x = cos(t);
    result.y = sin(t);

    return result;
}

sf::Vector2f circleHalfTimes(float t) {

    //0 <= t <= 2PI
    sf::Vector2f result;

    result.x = cos(t);
    result.y = sin(t);

    return result;
}

sf::Vector2f circleThreeTimes(float t) {

    //0 <= t <= 2PI
    sf::Vector2f result;

    result.x = cos(t);
    result.y = sin(t);

    return result;
}

sf::Vector2f circleThreeTimesMoveRight(float t) {

    //0 <= t <= 2PI
    sf::Vector2f result;

    result.x = 1 + cos(t);
    result.y =     sin(t);

    return result;
}

sf::Vector2f spiral(float t) {

    //0 <= t <= 2PI
    sf::Vector2f result;

    float s = t * 5;
    float r = 2.0; // radius needs to increase with time (t)

    result.x = r * cos(s);
    result.y = r * sin(s);

    return result;
}

sf::Vector2f expSpiral(float t) {

    //0 <= t <= 2PI
    sf::Vector2f result;

    float s = t * 5; //don't change

    float r = 2.0; //<= this is the only line to change

    result.x = r * cos(s);//don't change
    result.y = r * sin(s);//don't change

    return result;
}

sf::Vector2f doughnut(float t) {

    //0 <= t <= 2PI
    sf::Vector2f result;

    float radius = 1.0;

    result.x = radius * cos(t) + -cos(30 * t);
    result.y = radius * sin(t) + -sin(30 * t);
 
    return result;
}

sf::Vector2f cartoid(float t) {

    //0 <= t <= 2PI
    sf::Vector2f r;
    float a = 0.0; // Why does this look like a circle when a=0 ? 

    r.x = cos(t) + a * cos(2 * t);
    r.y = sin(t) + a * sin(2 * t);

    return r;
}


sf::Vector2f astroid(float t) {

    //0 <= t <= 2PI
    sf::Vector2f r;

    r.x = cub(cos(t));   // cub(x) =>  x*x*x 
    r.y = cub(sin(t));


    return r;
}

sf::Vector2f hypocycloid(float t) {

    //0 <= t <= 2PI
    sf::Vector2f r;

    float a = 2.0;

    float b = a / 3;  //hint: can you see "threeness" in the green curve? That is controlled by the "3" on here

    r.x = (a-b)*cos(t) + b*cos((a/b - 1)*t);
    r.y = (a-b)*sin(t) - b*sin((a/b - 1)*t);

    return r;
}

sf::Vector2f heart(float t) {

    //0 <= t <= 2PI
    sf::Vector2f result;

    float scale = (1 / 16.0f); // try modifying this line first

    result.x = scale*((16 * cub(sin(t))));
    result.y = scale*(13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t));

    return result;
}



/*
      ____
   .d""  ""b.        `7MMF' `YMM'                        `7MM"""Mq.
 .P'  ,..., `W,        MM   .M'                            MM   `MM.
6' ,MP   YM   `b       MM .d"     .gP"Ya `7MMpMMMb.        MM   ,M9 ,pW"Wq.`7M'    ,A    `MF'.gP"Ya `7Mb,od8      pd*"*b.  ,pP""Yq.   pd*"*b.  pd""b.
M  MP     `    M       MMMMM.    ,M'   Yb  MM    MM        MMmmdM9 6W'   `Wb VA   ,VAA   ,V ,M'   Yb  MM' "'     (O)   j8 6W'    `Wb (O)   j8 (O)  `8b
M  Mb          M       MM  VMA   8M""""""  MM    MM        MM      8M     M8  VA ,V  VA ,V  8M""""""  MM             ,;j9 8M      M8     ,;j9      ,89
Y. `Wbm..."   ,9       MM   `MM. YM.    ,  MM    MM        MM      YA.   ,A9   VVV    VVV   YM.    ,  MM          ,-='    YA.    ,A9  ,-='       ""Yb.
 Yb.  ``''  .d'      .JMML.   MMb.`Mbmmd'.JMML  JMML.    .JMML.     `Ybmd9'     W      W     `Mbmmd'.JMML.       Ammmmmmm  `Ybmmd9'  Ammmmmmm       88
   `Ybq__pdP'                                                                                                                                 (O)  .M'
                                                                                                                                               bmmmd'
*/