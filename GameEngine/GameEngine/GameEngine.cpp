#include "stdafx.h"
#include "LuaManager.h"
#include "Debug.h"
#include "RenderEngine.h"
#include "EntityManager.h"
#include "ComponentFactory.h"

using namespace std;

//Brought in namespaces
using namespace Utility;
using namespace Managers;
using namespace Engine;
using namespace Factories;

void registerManagers() {
	//Register All managers
	Debug::getInstance();
	RenderEngine::getInstance();
	EntityManager::getInstance();
	ComponentFactory::getInstance();
	LuaManager::getInstance();

	Debug::getInstance().Spacer();
}

int main()
{
	registerManagers();

	while (RenderEngine::getInstance().IsOpen()) {
		RenderEngine::getInstance().Update();
	}
	RenderEngine::getInstance().Shutdown();
}