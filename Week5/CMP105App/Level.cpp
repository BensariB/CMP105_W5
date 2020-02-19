#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	zombTexture.loadFromFile("gfx/animZombie.png");
	zombie.setSize(sf::Vector2f(55, 108));
	zombie.setPosition(100, 100);
	zombie.setTexture(&zombTexture);

	marioTexture.loadFromFile("gfx/MarioSheetT.png");
	mario.setSize(sf::Vector2f(15, 21));
	mario.setPosition(200, 200);
	mario.setTexture(&marioTexture);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Escape)) {
		window->close();
	}
	zombie.setInput(input);
	zombie.handleInput(dt);
	mario.setInput(input);
	mario.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	zombie.update(dt);
	mario.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(zombie);
	window->draw(mario);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}