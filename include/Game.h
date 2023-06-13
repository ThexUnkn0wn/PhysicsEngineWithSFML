#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


/*
	Class that acts as the game engine.
	Wraper class.
*/




class Game
{
private:
	//Variables
	//Window
	sf::RenderWindow* m_window;
	sf::VideoMode m_videoMode;
	sf::Event m_event;
	

	//Mouse positions
	sf::Vector2i m_mousePosWindow;
	sf::Vector2f m_mousePosView;

	//Resources
	sf::Font m_font;

	//Text
	sf::Text m_uiText;

	//Game logic
	bool m_endGame;
	unsigned m_points;
	int m_health;

	float m_enemySpawnTimer;
	float m_enemySpawnTimerMax;
	int m_maxEnemies;
	bool m_mouseHeld;



	//Game objects
	std::vector<sf::RectangleShape> m_enemies;
	sf::RectangleShape m_enemy;


	//Private functions
	void initVariables();
	void initWindow();
	void initFonts();
	void initText();
	void initEnemies();
public:
	// Constructors / Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;
	const bool getEndGame() const;


	//Functions
	void spawnEnemy();

	void pollEvents();
	void updateMousePositions();
	void updateText();
	void updateEnemies();
	void update();

	void renderText(sf::RenderTarget& target);
	void renderEnemies(sf::RenderTarget& target);
	void render();

};

