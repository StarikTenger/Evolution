#include "Virus.h"
#include <cmath>

Virus::Virus(Genome _genome) {
	genome = _genome;
	damage = 0.005 * (pow(genome.radius, 3) * genome.chance / genome.period) / 10 + 0.03;
}
