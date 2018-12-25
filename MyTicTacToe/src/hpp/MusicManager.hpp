#pragma once

#include <SFML/Audio.hpp>

namespace hgw
{
	class MusicManager
	{
	public:
		MusicManager() {};
		~MusicManager() {};

		sf::Music gameMusic;

		void LoopPlay(sf::Music &music, float soundVolume = 100.0f);
		void Play(sf::Music &music, float soundVolume = 100.0f);

		void Mute();
		void UnMute();

		bool IsMuted();
		bool IsLoaded();

	private:
		bool muted = true;
		bool loaded = false;
	};
}