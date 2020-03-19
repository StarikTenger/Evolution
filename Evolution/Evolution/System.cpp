#include "System.h"
#include "geometry.h"
#include "random.h"

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace geom;
using namespace random;
using namespace std;

System::System(){
	for (int i = 0; i < 50; i++) {
		creatures.push_back(Creature(Vec2(random::intRandom(0, 600), random::intRandom(0, 600)), random::floatRandom(0, 2 * M_PI, 3), 2));
	}
	creatures[0].virus.push_back({});

	
}

System::~System() {
}

void System::fillChunks() {
	chunks = {};
	int sizeX = box.x / chunkSize + 1;
	int sizeY = box.y / chunkSize + 1;

	for (int x = 0; x < sizeX; x++) {
		chunks.push_back({});
		for (int y = 0; y < sizeX; y++) {
			chunks[x].push_back({});
		}
	}

	for (auto& creature : creatures) {
		int x = creature.pos.x / chunkSize;
		int y = creature.pos.y / chunkSize;
		chunks[x][y].push_back(&creature);
	}
}

std::vector<Creature*> System::getNeighbors(Vec2 pos) {
	std::vector<Creature*> neighbors;
	int x0 = pos.x / chunkSize;
	int y0 = pos.y / chunkSize;
	for (int x = max(0, x0 - 1); x <= min((int)chunks.size() - 1, x0 + 1); x++)
		for (int y = max(0, y0 - 1); y <= min((int)chunks.size() - 1, y0 + 1); y++)
			for (auto c : chunks[x][y])
				neighbors.push_back(c);

	return neighbors;
}