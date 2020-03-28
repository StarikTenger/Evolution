#include "CreatureGenome.h"
#include "random.h"

CreatureGenome CreatureGenome::mutate() {
	CreatureGenome g = *this;
	double k = 0.01;

	g.velocity += random::floatRandom(-1, 1, 3) * k;
	g.limit += random::floatRandom(-1, 1, 3) * k;

	return g;
}
