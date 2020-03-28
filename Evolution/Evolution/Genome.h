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
	Genome(double _radius, double _period, double _chance, double _phase1, double _phase2);

	Genome mutate();

	static double distance(const Genome& a, const Genome& b);
};

Genome operator-(const Genome& a, const Genome& b);
Genome operator/(const Genome& a, const Genome& b);



