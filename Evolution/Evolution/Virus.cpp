#include "Virus.h"
#include <cmath>

Virus::Virus(Genome _genome) {
	genome = _genome;
	damage = 0.005 * (pow(genome.radius, 2) * genome.chance / genome.period) + 0.03;
}
