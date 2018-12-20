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

		void LoadSound(std::string name, std::string filename);
		sf::SoundBuffer &GetSound(std::string name);
		sf::Sound sound;

	private:
		std::map<std::string, sf::SoundBuffer> _sounds;
	};
}