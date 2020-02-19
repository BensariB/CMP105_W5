#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class Mario : public GameObject
{
public:
	
	Mario();
	~Mario();

	void update(float dt) override;
	void handleInput(float dt);

protected:
	bool moving;
	bool stop;
	bool norm;
	bool flip;
	Animation walk;
	Animation swim;
	Animation duck;
	Animation* currentAnimation;
};

