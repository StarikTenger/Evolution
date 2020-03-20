#include "Genome.h"
#include "random.h"
#include <cmath>

Genome::Genome() {
	radius = random::floatRandom(1, 20, 1);
	period = random::floatRandom(0.1, 20, 1);
	chance = random::floatRandom(0, 1, 3);
	phase1 = random::floatRandom(1, 10, 1);
	phase2 = random::floatRandom(1, 10, 1);
}

Genome Genome::mutate() {
	Genome g = *this;
	double k = 0.1;

	g.radius += random::floatRandom(-1, 1, 3) * k;
	g.period += random::floatRandom(-0.1, 0.1, 3) * k;
	g.chance += random::floatRandom(-0.1, 0.1, 3) * k;
	g.phase1 += random::floatRandom(-2, 2, 1) * k;
	g.phase2 += random::floatRandom(-2, 2, 1) * k;

	g.radius = abs(g.radius);
	g.period = abs(g.period);
	g.chance = abs(g.chance);
	g.phase1 = abs(g.phase1);
	g.phase2 = abs(g.phase2);

	return g;
}