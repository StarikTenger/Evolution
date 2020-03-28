#pragma once

class CreatureGenome {
public:
	double velocity = 2;
	double limit = 2;

	CreatureGenome mutate();
};


