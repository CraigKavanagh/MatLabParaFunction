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
#pragma comment(lib,"TargetFunctions.lib")

float sqr(float n);
float cub(float n);


float moveHorizLineTarget(float t);

float changeSlopeTarget(float t);

float changeSlopeAndMoveTarget(float t); 

float makeParabolicTarget(float t);

float moveParabolsLeftTarget(float t);

float moveParabolaUpTarget(float t);

float moveCubicLeftTarget(float t);

float moveCubicDownTarget(float t);

float invertParabolaTarget(float t);

float widenParabolaTarget(float t);

float widenAndMoveParabolaTarget(float t);

float easeInTarget(float t);

float easeInUpsideDownTarget(float t);

float easeInFlipVertTarget(float t);

float easeOutTarget(float t);

float easeInThruCentreTarget(float t);

float easeOutThruCentreTarget(float t);

float easeInOutTarget(float t);

float easeInCubicTarget(float t);

float easeInOutCubicTarget(float t);

float easeInCubicThruCenterTarget(float t);


sf::Vector2f line1Target(float t);

sf::Vector2f line2Target(float t);

sf::Vector2f circleMoveTarget(float t);

sf::Vector2f circleScaleTarget(float t);

sf::Vector2f circleMoveAndScaleTarget(float t);

sf::Vector2f ellipseTarget(float t);

sf::Vector2f circleHalfTimesTarget(float t);

sf::Vector2f circleThreeTimesTarget(float t);

sf::Vector2f circleThreeTimesMoveRightTarget(float t);

sf::Vector2f spiralTarget(float t);

sf::Vector2f expSpiralTarget(float t);

sf::Vector2f doughnutTarget(float t);

sf::Vector2f cartoidTarget(float t);

sf::Vector2f circleTarget(float t);

sf::Vector2f astroidTarget(float t);

sf::Vector2f hypocycloidTarget(float t); 

sf::Vector2f heartTarget(float t);