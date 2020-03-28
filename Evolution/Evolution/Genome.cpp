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

Genome::Genome(double _radius, double _period, double _chance, double _phase1, double _phase2) {
	radius = _radius;
	period = _period;
	chance = _chance;
	phase1 = _phase1;
	phase2 = _phase2;
}

Genome operator-(const Genome& a, const Genome& b) {
	Genome c = a;
	c.radius -= b.radius;
	c.period -= b.period;
	c.chance -= b.chance;
	c.phase1 -= b.phase1;
	c.phase2 -= b.phase2;
	return c;
}

Genome operator/(const Genome& a, const Genome& b) {
	Genome c = a;
	c.radius /= b.radius;
	c.period /= b.period;
	c.chance /= b.chance;
	c.phase1 /= b.phase1;
	c.phase2 /= b.phase2;
	return c;
}

double Genome::distance(const Genome& a, const Genome& b) {
	auto c = (a - b) / b;
	return sqrt(
		pow(c.radius, 2) +
		pow(c.period, 2) +
		pow(c.chance, 2) +
		pow(c.phase1, 2) +
		pow(c.phase2, 2));
}

Genome Genome::mutate() {
	Genome g = *this;
	double k = 0.01;

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