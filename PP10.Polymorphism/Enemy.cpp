#include "Enemy.h"


void Enemy::load(int x, int y, int width, int height, std::string textureID) {
	GameObject::load(x, y, width, height, textureID);
}

void Enemy::draw(SDL_Renderer* pRenderer) {
	GameObject::draw(pRenderer);
}

void Enemy::clean() {

}

void Enemy::update() {
	setMovingspeed(1, 1, 100);
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Enemy::setMovingspeed(int x, int y, int dist) {
	GameObject::setMovingspeed(x, y, dist);
}