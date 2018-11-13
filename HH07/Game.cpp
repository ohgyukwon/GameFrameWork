#include "Game.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}

		m_bRunning = true;

		if (!TheTextureManager::Instance()->load("Assets/animate-alpha.png", "animate", m_pRenderer)) {
			return false;
		}

		if (!TheTextureManager::Instance()->load("Assets/wall.png", "wall", m_pRenderer)) {
			return false;
		}

		if (!TheTextureManager::Instance()->load("Assets/wall_broken.png", "wall_broken", m_pRenderer)) {
			return false;
		}

		if (!TheTextureManager::Instance()->load("Assets/bullet.png", "bullet", m_pRenderer)) {
			return false;
		}

		m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate", "Player")));
		m_gameObjects.push_back(new Enemy(new LoaderParams(500, 100,  64, 128, "wall", "Enemy")));
	}
	else {
		m_bRunning = false;
		return false;
	}
	return true;
}

void Game::render() {
	SDL_RenderClear(m_pRenderer);
	SDL_SetRenderDrawColor(m_pRenderer, 0, 150, 255, 255);	// ¹è°æ »ö±ò
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
	SDL_RenderPresent(m_pRenderer);
}

void Game::update() {
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		for (std::vector<GameObject*>::size_type j = 0; j != m_gameObjects.size(); j++) {
			m_gameObjects[i]->Collide(m_gameObjects[j]);
			m_gameObjects[j]->Collide(m_gameObjects[i]);
		}
	}
}

void Game::clean() {
	TheInputHandler::Instance()->clean();
	std::cout << "cleanning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents() {
	TheInputHandler::Instance()->update();
}

void Game::quit() {
	m_bRunning = false;
}