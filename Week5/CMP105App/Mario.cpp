#include "Mario.h"

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
}

Mario::~Mario()
{
}

void Mario::update(float dt)
{
	if (stop == 1 && currentAnimation->getCurrentFrame() == (sf::IntRect(0, 0, 15, 21))) {
		moving = 0;
		currentAnimation->reset();
		stop = 0;
	}
	setTextureRect(currentAnimation->getCurrentFrame());
	if (moving) {
		currentAnimation->animate(dt);
		move(getVelocity()* dt);
		if (currentAnimation->getCurrentFrame() == (sf::IntRect(45, 0, 15, 21))) {
			stop = 1;
		}
	}
	
}

void Mario::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Down)) {
		currentAnimation = &duck;
		setTextureRect(currentAnimation->getCurrentFrame());
		currentAnimation->animate(dt);
		input->setKeyUp(sf::Keyboard::Down);
	}

	if (input->isKeyDown(sf::Keyboard::S)) {
		currentAnimation = &swim;
		setTextureRect(currentAnimation->getCurrentFrame());
		currentAnimation->animate(dt);
		input->setKeyUp(sf::Keyboard::S);
	}

	if (input->isKeyDown(sf::Keyboard::Right)) {
		moving = 1;
		currentAnimation->setFlipped(0);
		setTextureRect(currentAnimation->getCurrentFrame());
		setVelocity(100, 0);
		//input->setKeyUp(sf::Keyboard::Right);
	}

	if (input->isKeyDown(sf::Keyboard::Left)) {
		moving = 1;
		currentAnimation->setFlipped(1);
		setTextureRect(currentAnimation->getCurrentFrame());
		setVelocity(-100, 0);
		//input->setKeyUp(sf::Keyboard::Left);
	}
}
