#include "../include/Game.h"


//Private functions
void Game::initVariables()
{
	this->m_window = nullptr;

    //Game logic
    this->m_endGame = false;
    this->m_points = 0;
    this->m_health = 20;

    this->m_enemySpawnTimerMax = 20.f;
    this->m_enemySpawnTimer = this->m_enemySpawnTimerMax;
    
    this->m_maxEnemies = 5;
    this->m_mouseHeld = false;
}

void Game::initWindow()
{
	this->m_videoMode.height = 600;
	this->m_videoMode.width = 800;

	this->m_window = new sf::RenderWindow(this->m_videoMode, "Game Demo", sf::Style::Titlebar | sf::Style::Close);

    this->m_window->setFramerateLimit(60);
}

void Game::initFonts()
{
    if (!this->m_font.loadFromFile("Fonts/Roboto-Light.ttf")) 
    {
        std::cout << "ERROR::GAME::INITFONTS::Failed to load font!" << "\n";
    }
}

void Game::initText()
{
    this->m_uiText.setFont(this->m_font);
    this->m_uiText.setCharacterSize(24);
    this->m_uiText.setFillColor(sf::Color::White);
    this->m_uiText.setString("NONE");
}

void Game::initEnemies()
{
    this->m_enemy.setPosition(10.f,10.f);
    this->m_enemy.setSize(sf::Vector2f(100.f, 100.f));
    //this->m_enemy.setScale(sf::Vector2f(0.5f, 0.5f));
    this->m_enemy.setFillColor(sf::Color::Cyan);
    //this->m_enemy.setOutlineColor(sf::Color::Green);
    //this->m_enemy.setOutlineThickness(1.f);
}

// Constructors / Destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
    this->initFonts();
    this->initText();
    this->initEnemies();
}

Game::~Game()
{
	delete this->m_window;
}


//Accessors
const bool Game::running() const
{
	return this->m_window->isOpen();
}

const bool Game::getEndGame() const
{
    return this->m_endGame;
}


//Functions



void Game::spawnEnemy()
{
    /**
        @return void

        Spawns enemies and sets their types and colors. Spawns them at random positions.
        -Sets a random position.
        -Sets a random color.
        -Adds ebeny to the vector.
    */

    this->m_enemy.setPosition(
        static_cast<float>(rand() % static_cast<int>(this->m_window->getSize().x - this->m_enemy.getSize().x)),
        //static_cast<float>(rand() % static_cast<int>(this->m_window->getSize().y - this->m_enemy.getSize().y))
        0.f
    );

    //Randomize enemy type
    int type = rand() % 5;

    switch (type)
    {
    case 0:
        this->m_enemy.setFillColor(sf::Color::Magenta);
        this->m_enemy.setSize(sf::Vector2f(10.f, 10.f));
        break;
    case 1:
        this->m_enemy.setFillColor(sf::Color::Blue);
        this->m_enemy.setSize(sf::Vector2f(30.f, 30.f));
        break;
    case 2:
        this->m_enemy.setFillColor(sf::Color::Cyan);
        this->m_enemy.setSize(sf::Vector2f(50.f, 50.f));
        break;
    case 3:
        this->m_enemy.setFillColor(sf::Color::Red);
        this->m_enemy.setSize(sf::Vector2f(70.f, 70.f));
        break;
    case 4:
        this->m_enemy.setFillColor(sf::Color::Green);
        this->m_enemy.setSize(sf::Vector2f(100.f, 100.f));
        break;
    default:
        this->m_enemy.setFillColor(sf::Color::Yellow);
        break;
    }

    

    //Spawn the enemy
    this->m_enemies.push_back(this->m_enemy);

    //Remove the enemies at end of screen

}

void Game::pollEvents()
{
    //Event polling
    while (this->m_window->pollEvent(this->m_event))
    {
        switch (this->m_event.type)
        {
        case sf::Event::Closed:
            this->m_window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->m_event.key.code == sf::Keyboard::Escape)
                this->m_window->close();
            break;
        }
    }
}

void Game::updateMousePositions()
{
    /**
        @ return void

        Update the mouse positions:
            - Mouse position relative to the window (Vector2i)
    */

    this->m_mousePosWindow = sf::Mouse::getPosition(*this->m_window);
    this->m_mousePosView = this->m_window->mapPixelToCoords(this->m_mousePosWindow);
}

void Game::updateText()
{
    std::stringstream ss;
    ss << "Points: " << this->m_points<<"\n"
       << "Health: "<< this->m_health;
    this->m_uiText.setString(ss.str());
}

void Game::updateEnemies()
{
    /**
        @return void

        Update the enemy spawn timer and spawns enemies
        when the total amount fo enemies is smaller that the maximum.
        Moves the enemies downwards.
        Removes the enemies at the edge of the screen. //TODO
    */


    //Updateing the timer for enemy spawning
    if (this->m_enemies.size() < this->m_maxEnemies)
    {
        if (this->m_enemySpawnTimer >= this->m_enemySpawnTimerMax)
        {
            //Spawn the enemy and reset the timer
            this->spawnEnemy();
            this->m_enemySpawnTimer = 0.f;
        }
        else
            this->m_enemySpawnTimer += 1.f;
    }
    
    //Moveing and updateing enemies
    for (int i=0;i<this->m_enemies.size();++i) 
    {
        bool deleted = false;

        this->m_enemies[i].move(0.f, 5.f);

        //If the enemy is past the bottom of the screen
        if (this->m_enemies[i].getPosition().y > this->m_window->getSize().y)
        {
            this->m_enemies.erase(this->m_enemies.begin() + i);
            this->m_health -= 1;
            std::cout << "Health: " << this->m_health << "\n";
        }
    }

    
    //check if clicked upon
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (this->m_mouseHeld == false) 
        {
            this->m_mouseHeld = true;
            bool deleted = false;
            for (size_t i = 0; i < this->m_enemies.size() && deleted == false; ++i) {
                if (this->m_enemies[i].getGlobalBounds().contains(this->m_mousePosView))
                {
                    //Gain points
                    if (this->m_enemies[i].getFillColor() == sf::Color::Magenta)
                        this->m_points += 10;
                    else if(this->m_enemies[i].getFillColor() == sf::Color::Blue)
                        this->m_points += 7;
                    else if (this->m_enemies[i].getFillColor() == sf::Color::Cyan)
                        this->m_points += 5;
                    else if (this->m_enemies[i].getFillColor() == sf::Color::Red)
                        this->m_points += 3;
                    else if (this->m_enemies[i].getFillColor() == sf::Color::Green)
                        this->m_points += 1;
                    
                    std::cout << "Points: " << this->m_points << "\n";

                    //Delete the enemy
                    deleted = true;
                    this->m_enemies.erase(this->m_enemies.begin() + i);

                }
            }
        }   
    }
    else
    {
        this->m_mouseHeld = false;
    }


}

void Game::update()
{
    this->pollEvents();
    if (this->m_endGame==false) 
    {
        this->updateMousePositions();

        this->updateText();

        this->updateEnemies();
    }
    
    //End game condition
    if (this->m_health <= 0)
        this->m_endGame = true;
}



void Game::renderText(sf::RenderTarget& target)
{
    target.draw(this->m_uiText);
}

void Game::renderEnemies(sf::RenderTarget& target)
{
    for (auto& e : this->m_enemies)
    {
        target.draw(e);
    }
}

void Game::render()
{
    /**
        @return void
        - clear old frame
        - render objects
        - display new frame in window
     
        Renders the game objects.
    */

    this->m_window->clear();

    //Draw game objects
    this->renderEnemies(*this->m_window);

    this->renderText(*this->m_window);

    this->m_window->display();

}
