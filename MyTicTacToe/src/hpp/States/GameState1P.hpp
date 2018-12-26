#pragma once

#include "src/hpp/States/GameState2P.hpp"

namespace hgw
{
	class GameState1P : private GameState2P
	{
		GameState1P(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		
	};
}
