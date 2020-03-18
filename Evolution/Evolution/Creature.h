#pragma once
#include "geometry.h"
#include "Virus.h"

class Creature {
public:
	Vec2 pos;

	double dir = 0;
	double vel = 0;
	double hp = 1;
	double timer = 1;

	std::vector<Virus> virus;

	Creature() {};
	Creature(Vec2 _pos, double _dir, double _vel);
};

