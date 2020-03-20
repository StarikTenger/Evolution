#pragma once
#include "Color.h"

class Genome {
public:

	double radius = 10;
	double period = 0.5;
	double chance = 0.5;
	double phase1 = 10;
	double phase2 = 5;

	Genome();

	Genome mutate();
};

