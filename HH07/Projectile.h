#pragma once

#include "SDLGameObject.h"
#include "InputHandler.h"
#include "Game.h"
#include "TextureManager.h"

class Projectile :public SDLGameObject {
public:
	Projectile(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
private:
};