#pragma once
#include "Genome.h";

class Virus {
public:
	double progress = 0;
	double damage = 0.1;

	double timer = 0;

	Genome genome;

	Virus() {};
	Virus(Genome _genome);
};

