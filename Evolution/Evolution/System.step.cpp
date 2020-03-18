#include "geometry.h"
#include "System.h"
#include "random.h"
#include <iostream>
#include <math.h>

void System::step() {
	// checking borders
	for (auto& creature : creatures) {
		auto posNew = creature.pos + geom::direction(creature.dir) * creature.vel * dt; // position after small movement
		if (posNew.x < 0)
			creature.dir = M_PI - creature.dir;
		if (posNew.y < 0)
			creature.dir = -creature.dir;
		if (posNew.x > box.x)
			creature.dir = M_PI - creature.dir;
		if (posNew.y > box.y)
			creature.dir = -creature.dir;
	}

	

	// moving
	for (auto& creature : creatures) {
		creature.timer-=dt;
		if (creature.timer < 0) {
			creature.dir = random::floatRandom(0, 2*M_PI, 2);
			creature.timer = random::floatRandom(0, 5, 2);

			// reproducing
			if (creature.hp > 2) {
				creature.hp = 1;
				additionalCreatures.push_back(creature);
				additionalCreatures.push_back(creature);
				creature.hp = -1;
			}
		}
		creature.pos += geom::direction(creature.dir)*creature.vel*dt;
	}

	// hp increasing
	for (auto& creature : creatures) {
		creature.hp += 0.02* dt;
	}

	fillChunks();

	// virus
	for (auto& creature : creatures) {
		bool finish = 0;
		for (auto& virus : creature.virus) {
			virus.progress += dt;
			if (virus.progress > phases[0]) {
				virus.timer -= dt;
				if (virus.timer <= 0) {
					for (Creature* victim : getNeighbors(creature.pos)) {
						if (geom::distance(creature.pos, victim->pos) < virus.genome.radius && random::floatRandom(0, 1, 3) < virus.genome.chance) {
							if (!victim->virus.size())
								victim->virus.push_back(Virus(virus.genome));
						}
					}
					virus.timer = virus.genome.period;
				}

				creature.hp -= virus.damage * dt;
			}
			if (virus.progress > phases[1])
				finish = 1;
		}
		if (finish)
			creature.virus = {};
	}

	

	// additional creatures
	for (auto& creature : additionalCreatures) {
		if (!random::intRandom(0, 999))
			creature.virus.push_back({});
		creatures.push_back(creature);
	}
	additionalCreatures = {};

	// killing
	for (int i = 0; i < creatures.size(); i++) {
		if (creatures[i].hp < 0) {
			creatures.erase(creatures.begin() + i);
			i--;
		}
	}
	
}