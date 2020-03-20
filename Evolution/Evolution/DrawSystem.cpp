#include "DrawSystem.h"
#include <math.h>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <algorithm>



DrawSystem::DrawSystem(){
	window = new sf::RenderWindow(sf::VideoMode(1200, 900), "The Virus");
	loadTextures();
	
}

DrawSystem::~DrawSystem(){}

void DrawSystem::drawScene() {
	System& sys = *system;
	w = window->getSize().x;
	h = window->getSize().y;
	window->setView(sf::View(sf::FloatRect(0, 0, w, h)));

	for (const auto& creature : sys.creatures) {
		Color col = { 143, 235, 52 };
		col = { 100, 100, 100 };
		if (creature.virus.size()) {
			col = { 255, 100, 100 };
			if (creature.virus[0].progress < creature.virus[0].genome.phase1)
				col = { 255, 225, 0 };
			col = { creature.virus[0].damage * 2000, creature.virus[0].genome.phase1 * 50, 0 };
		}
		
		if (creature.virus.size() && creature.virus[0].progress > creature.virus[0].genome.phase1)
			col.b = 20;

		fillCircle(creature.pos, creature.hp * 2, col);
	
		
	}

}

void DrawSystem::drawInterface() {
	System& sys = *system;
	w = window->getSize().x;
	h = window->getSize().y;
	window->setView(sf::View(sf::FloatRect(0, 0, w, h)));

	double x = 1200;
	double limitPopulation = 0;
	double limitDamage = 0;
	for (const auto& p : *parameters) {
		x -= scale.x;
		if (x < 600)
			break;
		limitPopulation = std::max(limitPopulation, (double)p.population);
		limitDamage = std::max(limitDamage, (double)p.damage);
	}
	x = 1200;
	for (const auto& p : *parameters) {
		x -= scale.x;
		if (x < 600)
			break;
		
		double v1 = p.population * 0.05 * scale.y;
		double v2 = p.ill * 0.05 * scale.y;
		double v3 = p.damage / limitDamage  * 300 ;
		fillRect(x, 300 - v1/2, 1, v1, Color(29, 196, 74));
		fillRect(x, 300 - v2/2, 1, v2, Color(255, 162, 0));
		if(p.ill)
			fillRect(x, 600 - v3/2, 1, v3, Color(255, 0, 0));

		double t1 = p.phase1 * 0.3;
		double t2 = t1 + p.phase2 *0.3;
		//std::cout << p.phase1 << "\n";

		if (p.ill)
			fillRect(x, 900 - t2 / 2, 1, t2, Color(255, 0, 149));

		if (p.ill)
			fillRect(x, 900 - t1 / 2, 1, t1, Color(0, 213, 255));
		
	}
}

void DrawSystem::draw() {
	System& sys = *system;
	window->clear();

	drawScene();
	
	drawInterface();
}
