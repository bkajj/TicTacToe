#include <iostream>

#include "src/hpp/DEFINITIONS.hpp"
#include "src/hpp/States/SettingsState.hpp"
#include "src/hpp/States/MainMenuState.hpp"

namespace hgw
{
	SettingsState::SettingsState(GameDataRef data) : _data(data)
	{

	}

	void SettingsState::Init()
	{
		this->_data->assets.LoadTexture("Backgound", MAIN_MENU_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Settings", MAIN_MENU_SETTINGS_ICON_FILEPATH);

		this->_data->assets.LoadTexture("Music On", MAIN_MENU_MUSIC_ON_ICON_FILEPATH);
		this->_data->assets.LoadTexture("Music Off", MAIN_MENU_MUSIC_OFF_ICON_FILEPATH);
		this->_data->assets.LoadTexture("Sound On", MAIN_MENU_SOUND_ON_ICON_FILEPATH);
		this->_data->assets.LoadTexture("Sound Off", MAIN_MENU_SOUND_OFF_ICON_FILEPATH);

		this->_data->assets.LoadTexture("Bar", VOLUME_BAR_FILEPATH);
		this->_data->assets.LoadTexture("Point", VOLUME_POINT_FILEPATH);

		this->_bar.setTexture(this->_data->assets.GetTexture("Bar"));
		this->_point.setTexture(this->_data->assets.GetTexture("Point"));


		this->_settings.setTexture(this->_data->assets.GetTexture("Settings"));
		this->_background.setTexture(this->_data->assets.GetTexture("Background"));

		if (this->_data->sounds.IsMuted())
		{
			this->_sound.setTexture(this->_data->assets.GetTexture("Sound Off"));
		}
		else
		{
			this->_sound.setTexture(this->_data->assets.GetTexture("Sound On"));
		}

		if (this->_data->music.IsMuted())
		{
			this->_music.setTexture(this->_data->assets.GetTexture("Music Off"));
		}
		else
		{
			this->_music.setTexture(this->_data->assets.GetTexture("Music On"));
		}

		this->_bar.setPosition((SCREEN_WIDTH / 2) - (this->_bar.getGlobalBounds().width / 1.5f),
			(SCREEN_HEIGHT / 10) - (this->_bar.getGlobalBounds().height / 4));

		this->_point.setPosition((SCREEN_WIDTH / 2) - (this->_point.getGlobalBounds().width / 1.5f),
			(SCREEN_HEIGHT / 10) - (this->_point.getGlobalBounds().height / 4));

		this->_sound.setPosition((SCREEN_WIDTH / 2) + (this->_sound.getGlobalBounds().width / 1.5f),
			(SCREEN_HEIGHT / 10) - (this->_sound.getGlobalBounds().height / 2));

		this->_music.setPosition((SCREEN_WIDTH / 4) - (this->_music.getGlobalBounds().width / 1.5f),
			(SCREEN_HEIGHT / 10) - (this->_music.getGlobalBounds().height / 2));

		this->_settings.setPosition((this->_data->window.getSize().x / 2) - (this->_settings.getLocalBounds().width / 2),
			(this->_data->window.getSize().y) - (this->_settings.getLocalBounds().height * 1.90f));
	}

	void SettingsState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.IsSpriteClicked(this->_sound, sf::Mouse::Left, event.type, this->_data->window))
			{
				if (this->_data->sounds.IsMuted())
				{
					this->_data->sounds.UnMute();
					this->_data->sounds.Play(this->_data->sounds.ClickSound1);

					this->_sound.setTexture(this->_data->assets.GetTexture("Sound On"));
				}
				else
				{
					this->_data->sounds.Mute();
					this->_data->sounds.Play(this->_data->sounds.ClickSound1);

					this->_sound.setTexture(this->_data->assets.GetTexture("Sound Off"));
				}
			}
			else if (this->_data->input.IsSpriteClicked(this->_music, sf::Mouse::Left, event.type, this->_data->window))
			{
				if (this->_data->music.IsMuted())
				{
					this->_data->sounds.Play(this->_data->sounds.ClickSound1);

					if (this->_data->music.IsLoaded())
					{
						this->_data->music.gameMusic.stop();
						this->_data->music.UnMute();
						this->_data->music.gameMusic.play();
					}
					else
					{
						this->_data->music.UnMute();
						this->_data->music.LoopPlay(this->_data->music.gameMusic, 60.0f);
					}	

					this->_music.setTexture(this->_data->assets.GetTexture("Music On"));
				}
				else
				{
					this->_data->sounds.Play(this->_data->sounds.ClickSound1);

					this->_data->music.gameMusic.stop();
					this->_data->music.Mute();

					this->_music.setTexture(this->_data->assets.GetTexture("Music Off"));
				}
			}
			else if (this->_data->input.IsSpriteClicked(this->_settings, sf::Mouse::Left, event.type, this->_data->window))
			{
				this->_data->sounds.Play(this->_data->sounds.ClickSound1);
				this->_data->machine.RemoveState();
			}
			float x1 = sf::Mouse::getPosition().x;
			if (this->_data->input.IsSpritePressed(this->_point, sf::Mouse::Left, this->_data->window))
			{
				float x2 = sf::Mouse::getPosition().x;
				std::cout << sf::Mouse::getPosition(this->_data->window).x << std::endl;
				this->_point.setPosition(sf::Mouse::getPosition(this->_data->window).x - this->_point.getLocalBounds().width / 2,
					(SCREEN_HEIGHT / 10) - (this->_point.getGlobalBounds().height / 4));
			}
		}
	}

	void SettingsState::Update(float dt)
	{

	}

	void SettingsState::Draw(float dt)
	{
		this->_data->window.clear();

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_music);
		this->_data->window.draw(this->_sound);
		this->_data->window.draw(this->_settings);
		this->_data->window.draw(this->_bar);
		this->_data->window.draw(this->_point);

		this->_data->window.display();
	}
}