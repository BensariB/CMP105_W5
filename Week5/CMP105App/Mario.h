#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class Mario : public GameObject
{
public:
	bool moving;
	bool stop;
	Mario();
	~Mario();

	void update(float dt) override;
	void handleInput(float dt);

protected:
	Animation walk;
	Animation swim;
	Animation duck;
	Animation* currentAnimation;
};

