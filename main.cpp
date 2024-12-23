#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "Prius.h"
#include <vector>
#include <time.h>
#include <sstream>
#include "ElonBullet.h"
#include "HolyObject.h"
#include "Player.h"
#include "SceneManager.h"
#include "Scene1.h"

// Every 5 points (in score), give a new holy object. Holy objects will be used to attack the bad prii. 
//   Don't waste holy objects.
// For every bad prius that gets through, the demonic goat queen will get stronger.
// For every bad prius attacked without holy objects, health will diminish. play evil goat scream
// Maybe holy water can help restore health

// ------ LONG TERM TODO -------
// TODO: Find demonic goat queen


// ------ TOP PIORITY --------
// TODO: Add a demonic goat queen strength bar in the bottom left corner.
// TODO: Add a health bar at the bottom left corner, under strength bar.
// TODO: Make game over state effective.


using namespace sf;

sf::Vector2f windowSize;

RenderWindow window(
	VideoMode::getDesktopMode(),
	"Attack the Prius!",
	Style::None | Style::Fullscreen, // titlebar appearance, resize options
	sf::ContextSettings(0, 0, 3, 1, 1, 0, false)
);
// TODO: Hide cursor, so that Elon Musk appears to be the cursor. He is worthy. :) // I question this 5 years later
sf::Color meowColor = sf::Color(0, 0, 0);

Vector2f size = Vector2f(50, 50);
SceneManager sceneManager = SceneManager();

int main() {
	
	srand(time(0));
	window.setFramerateLimit(60);
	windowSize = Vector2f(window.getSize().x, window.getSize().y);

	HolyObject test = HolyObject(window.getSize().x / 2, window.getSize().y / 2);

	Time dt;
	Clock clck;
	sceneManager.addScene(std::make_shared<Scene1>(window));
	sceneManager.load(0);
	while (window.isOpen()) {



		Event e;
		while (window.pollEvent(e)) {

			if (e.type == Event::Closed) {
				sceneManager.unload();
				window.close();
			}
			if (e.type == Event::KeyPressed) {
				if (e.key.code == Keyboard::Escape) {
					sceneManager.unload();
					window.close();
				}
			}
		}
		window.clear();
		sceneManager.update(e, dt);
		sceneManager.render();
		dt = clck.restart();
	}

	return 0;
}