#include <math.h>

#pragma once

static const float speed = 5.0f;
static const int maxHp = 100;
static const int minY = -100;
static const int maxY = 100;
static const int minX = -100;
static const int maxX = 100;
static const int bulletCD = 0.8f;
static const sf::Vector2f gravity(0,15); //HACK (30 is old)
static const sf::IntRect texture_rect(0,0,256,256);
static const sf::Vector2f texture_origin(texture_rect.width * 0.5f, texture_rect.height * 0.5f);