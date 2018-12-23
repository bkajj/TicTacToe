#pragma once

#include <SFML/Audio.hpp>
#include <map>

namespace hgw
{
	class SoundManager
	{
	public:
		SoundManager() {};
		~SoundManager() {};

		sf::Sound StartGameSound;
		sf::Sound GridClickSound;
		sf::Sound ClickSound1;
		sf::Sound ClickSound2;

		void Init();

		void Play(sf::Sound &sound);

		void Mute();
		void unMute();

	private:
		sf::SoundBuffer StartGameBuffer;
		sf::SoundBuffer GridClickBuffer;
		sf::SoundBuffer ClickBuffer1;
		sf::SoundBuffer ClickBuffer2;

		bool muted = false;
		bool isLoaded = false;

		void LoadFromFile();
		void SetBuffers();
	};
}