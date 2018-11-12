#include "Player.h"

Player::Player(const LoaderParams* pParams) :
	SDLGameObject(pParams) {
	
}

void Player::draw() {
	SDLGameObject::draw();
}

void Player::update() {
	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput();
	bulletActive = int(((SDL_GetTicks() / 10) % 11));
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	SDLGameObject::update();
}

void Player::clean() {

}

void Player::handleInput() {
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
		m_velocity.setX(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
		m_velocity.setX(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
		m_velocity.setY(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
		m_velocity.setY(2);
	}
	if (TheInputHandler::Instance()->isKeyPressed(SDL_SCANCODE_SPACE)) {
		if (bulletActive == 0) {
			TheGame::Instance()->getGameObjects()->push_back(new Projectile(new LoaderParams(this->m_position.getX() + 80, this->m_position.getY() + 40, 16, 16, "bullet")));
		}
	}
}