#include "Projectile.h"

Projectile::Projectile(const LoaderParams* pParams) :

	SDLGameObject(pParams) {

}

void Projectile::draw() {
	TextureManager::Instance()->draw(m_textureID,
		(int)m_position.getX(), (int)m_position.getY()
		, m_width, m_height, TheGame::Instance()->getRenderer());
}

void Projectile::update() {
	m_velocity.setX(7);
	SDLGameObject::update();
}

void Projectile::clean() {

}