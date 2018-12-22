#include "src/hpp/SoundManager.hpp"
#include "src/hpp/DEFINITIONS.hpp"

namespace hgw
{
	SoundManager::SoundManager()
	{
		LoadFromFile();
		SetBuffers();
	}

	void SoundManager::LoadFromFile()
	{
		StartGameBuffer.loadFromFile(START_GAME_CLICK_SOUND_FILEPATH);
		GridClickBuffer.loadFromFile(GRID_CLICK_SOUND_FILEPATH);
		ClickBuffer1.loadFromFile(CLICK_SOUND_1_FILEPATH);
		ClickBuffer2.loadFromFile(CLICK_SOUND_2_FILEPATH);
	}

	void SoundManager::SetBuffers()
	{
		StartGameSound.setBuffer(StartGameBuffer);
		GridClickSound.setBuffer(GridClickBuffer);
		ClickSound1.setBuffer(ClickBuffer1);
		ClickSound2.setBuffer(ClickBuffer2); 
	}
}