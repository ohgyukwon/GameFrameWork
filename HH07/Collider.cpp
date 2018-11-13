#include "Collider.h"

Collider* Collider::s_pInstance = 0;

Collider::Collider() {

}

void Collider::update() {
	
}

void Collider::clean() {
	
}

bool Collider::Collision(GameObject* object1, GameObject* object2) {
	rc1_left = object1->getPositionX();
	rc1_right = object1->getPositionX() + object1->getWidth();
	rc1_up = object1->getPositionY();
	rc1_down = object1->getPositionY() + object1->getHeight();

	rc2_left = object2->getPositionX();
	rc2_right = object2->getPositionX() + object2->getWidth();
	rc2_up = object2->getPositionY();
	rc2_down = object2->getPositionY() + object2->getHeight();
}