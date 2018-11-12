#include "Collider.h"

Collider* Collider::s_pInstance = 0;

Collider::Collider() {
	v = *(TheGame::Instance()->getGameObjects());
}

void Collider::update() {
	for (iter1 = v.begin(); iter1 != v.end(); iter1++) {
		for (iter2 = v.begin(); iter2 != v.end(); iter2++) {
			if (*(*iter1)->getTag() == "Bullet" && *(*iter2)->getTag() == "Enemy") {
				v.erase(iter1);
				v.erase(iter2);
			}
		}
	}
}

void Collider::clean() {
	
}