#include "Player.h"


void Player::load(int x, int y, int width, int height, std::string textureID) {
	GameObject::load(x, y, width, height, textureID);
}

void Player::draw(SDL_Renderer* pRenderer) {
	GameObject::draw(pRenderer);
}

void Player::clean() {
	GameObject::clean();
}

void Player::update() {
	setMovingspeed(-1, 0, 100);
	m_currentFrame = int(((SDL_GetTicks() / 50) % 6));
}

void Player::setMovingspeed(int x, int y, int dist) {
	GameObject::setMovingspeed(x, y, dist);
}