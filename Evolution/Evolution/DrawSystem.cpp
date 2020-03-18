#include "DrawSystem.h"
#include <math.h>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>



DrawSystem::DrawSystem(){
	window = new sf::RenderWindow(sf::VideoMode(1200, 600), "The Virus");
	loadTextures();
	
}

DrawSystem::~DrawSystem(){}

void DrawSystem::drawScene() {
	System& sys = *system;
	w = window->getSize().x;
	h = window->getSize().y;
	window->setView(sf::View(sf::FloatRect(0, 0, w, h)));

	for (const auto& creature : sys.creatures) {
		Color col = { 100, 100, 100 };
		if (creature.virus.size()) {
			col = { 255, 100, 100 };
			if (creature.virus[0].progress < sys.phases[0])
				col = { 255, 225, 0 };
		}
		fillCircle(creature.pos, 2.0, col);
	}

}

void DrawSystem::drawInterface() {
	System& sys = *system;
	w = window->getSize().x;
	h = window->getSize().y;
	window->setView(sf::View(sf::FloatRect(0, 0, w, h)));

	int x = 600;
	for (const auto& p : *parameters) {
		x++;
		fillRect(x, 300, 1, p.population * 0.05 * scale, Color(29, 196, 74));
		fillRect(x, 300, 1, p.ill * 0.05 * scale, Color(255, 162, 0));
	}
}

void DrawSystem::draw() {
	System& sys = *system;
	window->clear();

	drawScene();
	
	drawInterface();
}
