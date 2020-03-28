#include "Control.h"
#include "getMilliCount.h"
#include <iostream>
#include <fstream>
#include <sstream>

Control::Control() {
	for (int i = 0; i < 100; i++) {
		keyMatches.push_back({});
	}
	std::ifstream keys("keys.conf");
	while (keys) {
		std::string key;
		keys >> key;
		while (keys) {
			std::string key1;
			keys >> key1;
			if (key1 == "END")
				break;
			keyMatches[getKey(key1)].push_back(getKey(key));

		}
	}
}

Control::~Control() {

}

Vec2 Control::getCursorPos() {
	return geom::rotate((mouse.pos - drawSys.cam.border/2) / drawSys.cam.scale, drawSys.cam.angle);
}

void Control::loadConfig() {
	
}


void Control::saveConfig() {
	
}

void Control::step() {
	int timeMs = getMilliCount();
	if (timeMs - timePrev > dt) {
		timePrev = timeMs;

		
		events();
		drawSys.mouse = mouse;
		
		
		for (int i = 0; i < 50; i++) {
			sys.step();
		}

		drawSys.scale.x *= pow(1.1, mouse.delta);
		if (keys[UP])
			drawSys.scale.y *= 1.05;
		if (keys[DOWN])
			drawSys.scale.y /= 1.05;

		if (keys[SPACE])
			drawSys.mode = 1;
		else
			drawSys.mode = 0;

		// count parameters
		Parameter param;
		param.population = sys.creatures.size();
		param.ill = 0;
		param.damage = 0;
		for (const auto& c : sys.creatures) {
			if (c.virus.size()) {
				param.ill++;
				param.phase1 += c.virus[0].genome.phase1 / param.ill;
				param.phase2 += c.virus[0].genome.phase2 / param.ill;
				param.damage += c.virus[0].damage / param.ill;
			}
		}
		graph.push_front(param);
		if (graph.size() > 6000)
			graph.pop_back();

		drawSys.graph = &graph;
		drawSys.system = &sys;
		drawSys.draw();
		drawSys.window->display();

		
	}
}
