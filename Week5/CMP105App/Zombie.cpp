#include "Zombie.h"

Zombie::Zombie() {
	walk.addFrame(sf::IntRect(0, 0, 55, 108));
	walk.addFrame(sf::IntRect(55, 0, 55, 108));
	walk.addFrame(sf::IntRect(110, 0, 55, 108));
	walk.addFrame(sf::IntRect(165, 0, 55, 108));
	walk.addFrame(sf::IntRect(220, 0, 55, 108));
	walk.addFrame(sf::IntRect(275, 0, 55, 108));
	walk.addFrame(sf::IntRect(330, 0, 55, 108));
	walk.addFrame(sf::IntRect(385, 0, 55, 108));
	walk.setFrameSpeed(0.1f);
	currentAnimation = &walk;
	setTextureRect(currentAnimation->getCurrentFrame());
	moving = 0;
}

Zombie::~Zombie()
{
}

void Zombie::update(float dt){
	setTextureRect(currentAnimation->getCurrentFrame());
	if (moving) {
		currentAnimation->animate(dt);
		move(getVelocity() * dt);
		//if animation is flipped:
		//frame = sf::IntRect(frame.left + frame.width, frame.top, -frame.width, frame.height);
		if (currentAnimation->getCurrentFrame() == sf::IntRect(385, 0, 55, 108) || currentAnimation->getCurrentFrame() == sf::IntRect(385 + 55, 0, -55, 108)) {
			moving = 0;
			currentAnimation->reset();
		}
		
	}
}

void Zombie::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Right)) {
		setVelocity(55, 0);
		currentAnimation = &walk;
		setTextureRect(currentAnimation->getCurrentFrame());
		moving = 1;
		currentAnimation->setFlipped(0);
	}

	if (input->isKeyDown(sf::Keyboard::Left)) {
		setVelocity(-55, 0);
		currentAnimation = &walk;
		setTextureRect(currentAnimation->getCurrentFrame());
		moving = 1;
		currentAnimation->setFlipped(1);
	}
}
