#pragma once

#include <SFML/Audio.hpp>
#include <map>

namespace hgw
{
	class SoundManager
	{
	public:

		SoundManager();
		~SoundManager() {};

		sf::Sound StartGameSound;
		sf::Sound GridClickSound;
		sf::Sound ClickSound1;
		sf::Sound ClickSound2;

	private:
		sf::SoundBuffer StartGameBuffer;
		sf::SoundBuffer GridClickBuffer;
		sf::SoundBuffer ClickBuffer1;
		sf::SoundBuffer ClickBuffer2;

		void LoadFromFile();
		void SetBuffers();
	};
}