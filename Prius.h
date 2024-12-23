#ifndef PRIUS_H
#define PRIUS_H

//#include "ElonBullet.h"
#include <SFML/Graphics.hpp>

class Prius
{
public:
	Prius(sf::Texture &texture, float x, float y, float sizeX, float sizeY, int screenWidth, int screenHeight, bool isBad = false, bool isFacingLeft = true, int speeed = 100);
	Prius(sf::Texture &texture, sf::Vector2f position, sf::Vector2f size, sf::Vector2f windowSize, bool isBad = false, bool isFacingLeft = true, int speeed = 100);
	virtual ~Prius();
	bool isShot(float mouseX, float mouseY);
	void draw(sf::RenderWindow &target);
	void setPosition(float xPos, float yPos);
	sf::Sprite getSprite();
	void setScale(const sf::Vector2f factors);
	void setScale(float factorX, float factorY);
	bool isDangerous();
	void stop();

protected:

private:
	//sf::RectangleShape priusBasic;
	sf::Sprite priusSprite;
	bool has_Ms_D;
	bool stopped;

public:
	// Sets the color of the prius
	void setColor(const sf::Color color);
	// Update Prius
	void update(float dt);
	// Moves the Prius to the direction it's facing
	void move(float dt);
	bool isOffScreen(int windowWidth);
	void setSpeed(float newSpeed);
	void setOrigin(float x, float y);
	sf::Vector2f getSize();
	sf::Vector2f getPosition();
	bool getFacingLeft();
	//bool collidesWithBullet(std::vector<ElonBullet> &vect);
	bool attacked = false;
	bool excorsized = false;

private:
	float speed;
	bool facingLeft;
	sf::Vector2f scaleSize;
	sf::Vector2f screenSize;
};


#endif
