#pragma once
#include "geometry.h"
#include "Virus.h"
#include "CreatureGenome.h"

class Creature {
public:
	Vec2 pos;

	double dir = 0;
	double vel = 0;
	double hp = 1;
	double timer = 1;

	CreatureGenome genome;

	std::vector<Virus> virus;
	std::vector<Genome> immunity;

	Creature() {};
	Creature(Vec2 _pos, double _dir, double _vel);
};

