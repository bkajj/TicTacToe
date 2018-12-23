#include <sstream>
#include <iostream>

#include "src/hpp/DEFINITIONS.hpp"

#include "src/hpp/States/MainMenuState.hpp"
#include "src/hpp/States/GameState2P.hpp"

namespace hgw
{
	// add setsmoth() to textres
	MainMenuState::MainMenuState(GameDataRef data) : _data(data)
	{

	}

	void MainMenuState::Init()
	{
		this->_data->assets.LoadTexture("Background", MAIN_MENU_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("1P Play Button", MAIN_MENU_1P_PLAY_BUTTON);
		this->_data->assets.LoadTexture("2P Play Button", MAIN_MENU_2P_PLAY_BUTTON);
		this->_data->assets.LoadTexture("Game Title", MAIN_MENU_TITLE_PATH);

		this->_background.setTexture(this->_data->assets.GetTexture("Background"));
		this->_1pPlayButton.setTexture(this->_data->assets.GetTexture("1P Play Button"));
		this->_2pPlayButton.setTexture(this->_data->assets.GetTexture("2P Play Button"));
		this->_title.setTexture(this->_data->assets.GetTexture("Game Title"));

		this->_1pPlayButton.setPosition((SCREEN_WIDTH / 1.75f) - (this->_1pPlayButton.getGlobalBounds().width / 1.75f),
			(SCREEN_HEIGHT / 2) - (this->_1pPlayButton.getGlobalBounds().height / 2));

		this->_2pPlayButton.setPosition((SCREEN_WIDTH / 2) - (this->_1pPlayButton.getGlobalBounds().width / 2),
			(this->_1pPlayButton.getGlobalBounds().height * 3.5f));

		this->_title.setPosition((SCREEN_WIDTH / 2) - (this->_title.getGlobalBounds().width / 2),
			(this->_title.getGlobalBounds().height * 0.1f));
	}

	void MainMenuState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.IsSpriteClicked(this->_2pPlayButton, sf::Mouse::Left, event.type,
				this->_data->window))
			{
				this->_data->sounds.Play(this->_data->sounds.StartGameSound);
				this->_data->machine.AddState(StateRef(new GameState2P(_data)), true);
			}
		}
	}

	void MainMenuState::Update(float dt)
	{

	}
	void MainMenuState::Draw(float dt)
	{
		this->_data->window.clear();
		
		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_1pPlayButton);
		this->_data->window.draw(this->_2pPlayButton);
		this->_data->window.draw(this->_title);

		this->_data->window.display();
	}
}