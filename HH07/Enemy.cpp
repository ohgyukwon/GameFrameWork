#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) :

	SDLGameObject(pParams) {

}

void Enemy::draw() {
	TextureManager::Instance()->draw(m_textureID,
		(int)m_position.getX(), (int)m_position.getY()
		, m_width, m_height, TheGame::Instance()->getRenderer());
}

void Enemy::update() {
	m_velocity.setX(0);
	m_velocity.setY(0);
	//handleInput();
	SDLGameObject::update();
}

void Enemy::clean() {

}

void Enemy::Collide(GameObject* pCollider) {
	if (pCollider->getTag() == "Bullet") {
		m_textureID = "wall_broken";
	}
}

void Enemy::handleInput() {
	if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
		m_velocity.setX(1);
	}

	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_velocity = (*vec - m_position) / 100;
}

std::string Enemy::getTag() {
	return m_tag;
}