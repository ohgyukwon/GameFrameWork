#pragma once

#include "SDLGameObject.h"
#include "InputHandler.h"
#include "Game.h"
#include "Projectile.h"

class Player :public SDLGameObject {
public:
	Player(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
private:
	int bulletActive = 1;
	void handleInput();
	std::vector<GameObject*> m_bullets;
};