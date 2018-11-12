#include "Projectile.h"
#include <iostream>
using namespace std;

Projectile::Projectile(const LoaderParams* pParams) :

	SDLGameObject(pParams) {
}

void Projectile::draw() {
	TextureManager::Instance()->draw(m_textureID,
		(int)m_position.getX(), (int)m_position.getY()
		, m_width, m_height, TheGame::Instance()->getRenderer());
}

void Projectile::update() {
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_acceleration.setX(7);
	SDLGameObject::update();
}

void Projectile::clean() {

}

std::string Projectile::getTag() {
	return m_tag;
}