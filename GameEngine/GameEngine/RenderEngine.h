#pragma once
#include "Singleton.h"
#include "Debug.h"
#include "EngineGUI.h"
#include "GameView.h"

//SFML
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/View.hpp>

using namespace Utility;
using namespace sf;

namespace Engine {
	class RenderEngine : public Singleton<RenderEngine>
	{
		friend class Singleton<RenderEngine>;
		
		public:
			bool IsOpen();
			void Update();
			void Shutdown();
			void CloseWindow();

		private:
			RenderEngine();

		private:
			RenderWindow window;
			Clock deltaClock;
			Color backgroundColour;			
	};
}

