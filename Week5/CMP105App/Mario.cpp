#include "Mario.h"
#include <iostream>

Mario::Mario()
{
	//walking:
	walk.addFrame(sf::IntRect(0, 0, 15, 21));
	walk.addFrame(sf::IntRect(15, 0, 15, 21));
	walk.addFrame(sf::IntRect(30, 0, 15, 21));
	walk.addFrame(sf::IntRect(45, 0, 15, 21));
	walk.setFrameSpeed(0.1f);
	
	//swimming:
	swim.addFrame(sf::IntRect(0, 21, 16, 20));
	swim.addFrame(sf::IntRect(16, 21, 16, 20));
	swim.addFrame(sf::IntRect(32, 21, 16, 20));
	swim.setFrameSpeed(0.2f);

	duck.addFrame(sf::IntRect(0, 41, 16, 20));
	duck.addFrame(sf::IntRect(16, 41, 16, 20));
	duck.setFrameSpeed(0.2f);

	currentAnimation = &walk;
	setTextureRect(currentAnimation->getCurrentFrame());
	moving = 0;
	stop = 0;
	norm = 0;
	flip = 0;
}

Mario::~Mario()
{
}

void Mario::update(float dt)
{
	if (stop == 1 && (currentAnimation->getCurrentFrame().left == 0 || currentAnimation->getCurrentFrame().left == 60 || currentAnimation->getCurrentFrame().left == 32) ) {
		moving = 0;
		currentAnimation->reset();
		stop = 0;
	}
	setTextureRect(currentAnimation->getCurrentFrame());
	if (moving) {
		currentAnimation->animate(dt);
		move(getVelocity()* dt);
		if (currentAnimation->getCurrentFrame().left == 45 || currentAnimation->getCurrentFrame().left == 32 || currentAnimation->getCurrentFrame().left == 16) {
			stop = 1;
		}
	}
}

void Mario::handleInput(float dt)
{
	norm = 0;
	if (input->isKeyDown(sf::Keyboard::Down)) {
		currentAnimation = &duck;
		setTextureRect(currentAnimation->getCurrentFrame());
		norm = 1;
	}

	if (input->isKeyDown(sf::Keyboard::S)) {
		currentAnimation = &swim;
		setTextureRect(currentAnimation->getCurrentFrame());
		norm = 1;
	}

	if (input->isKeyDown(sf::Keyboard::Right)) {
		moving = 1;
		flip = 0;
		setTextureRect(currentAnimation->getCurrentFrame());
		setVelocity(100, 0);
	}

	if (input->isKeyDown(sf::Keyboard::Left)) {
		moving = 1;
		flip = 1;
		setTextureRect(currentAnimation->getCurrentFrame());
		setVelocity(-100, 0);
	}
	if (norm == 0) {
		currentAnimation = &walk;
	}
	currentAnimation->setFlipped(flip);
}
