#include "src/hpp/SoundManager.hpp"

namespace hgw
{
	void SoundManager::LoadSound(std::string name, std::string filename)
	{
		sf::SoundBuffer buffer;

		if (buffer.loadFromFile(filename))
		{
			this->_sounds[name] = buffer;
		}
	}

	sf::SoundBuffer &SoundManager::GetSound(std::string name)
	{
		return this->_sounds.at(name);
	}
}