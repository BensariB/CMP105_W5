#pragma once
#include "Framework/Animation.h"
#include "Framework/GameObject.h"

class Zombie : public GameObject
{
public:
	bool moving;

	Zombie();
	~Zombie();

	void update(float dt) override;
	void handleInput(float dt);

protected:
	Animation walk;
	Animation* currentAnimation;
};

