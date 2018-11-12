#pragma once

#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"
#include "InputHandler.h"

class Collider {
public:
	static Collider* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new Collider();
		}
		return s_pInstance;
	}
	void update();
	void clean();
private:
	Collider();
	~Collider();
	static Collider* s_pInstance;
	std::vector<GameObject*> v;
	std::vector<GameObject*>::iterator iter1, iter2;
};

typedef Collider TheCollider;