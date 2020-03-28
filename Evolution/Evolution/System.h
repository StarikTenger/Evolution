#pragma once
#include <vector>
#include <deque>
#include <fstream>
#include "Vec2.h"
#include <string>
#include <SFML/Graphics.hpp>
#include "Creature.h"

class System{
public:
	double dt = 0.02;
	double chunkSize = 10;
	double immunityK = 100;
	double immunityThreshold = 0.1;

	Vec2 box = { 600, 600 };

	std::vector<Creature> creatures;
	std::vector<Creature> additionalCreatures;

	//std::vector<double> phases = {10.0, 12.0};

	std::vector<std::vector<std::vector<Creature*>>> chunks;

	System();
	~System();

	void step();
	void fillChunks();

	std::vector<Creature*> getNeighbors(Vec2 pos);
};