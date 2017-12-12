#include "stdafx.h"
#include "EngineGUI.h"

Engine::EngineGUI::EngineGUI()
{
}

void Engine::EngineGUI::Initialize(RenderWindow& window) {
	SFML::Init(window);
	StyleColorsDark(); //TODO: Reload last saved theme
}

void Engine::EngineGUI::Shutdown()
{
	SFML::Shutdown();
}

void Engine::EngineGUI::ProcessEvents(Event e)
{
	SFML::ProcessEvent(e);

	if (e.type == Event::KeyPressed) {
		if (e.key.code == Keyboard::Z && e.key.control) {
			Undo();
		} else if (e.key.code == Keyboard::Y && e.key.control) {
			Redo();
		} else if (e.key.code == Keyboard::X && e.key.control) {
			Cut();
		} else if (e.key.code == Keyboard::C && e.key.control) {
			Copy();
		} else if (e.key.code == Keyboard::V && e.key.control) {
			Paste();
		}
	}
}

void Engine::EngineGUI::Update(RenderWindow & window, Time deltaClock)
{
	SFML::Update(window, deltaClock);
}

void Engine::EngineGUI::Draw()
{
	//Draw some widgets here	
	MenuBar();
	StatsWindow();

	//ShowTestWindow();
}

void Engine::EngineGUI::Render(RenderWindow & window)
{
	SFML::Render(window);
}

#pragma region Windows
void Engine::EngineGUI::StatsWindow()
{
	const float DISTANCE = 10.0f;
	float frameRate = GetIO().Framerate;
	float cpuThread = 1000.0f / frameRate;

	//Handle plot lines data
	fpsNodes.push_back(frameRate);
	if (fpsNodes.size() >= 101) {
		fpsNodes.erase(fpsNodes.begin());
	}
	float values[100];
	copy(fpsNodes.begin(), fpsNodes.end(), values);

	//Position and setup window
	ImVec2 windowPosition = ImVec2(GetIO().DisplaySize.x - DISTANCE, DISTANCE * 2);
	ImVec2 windowPivot = ImVec2(1.0f, 0.0f);
	SetNextWindowPos(windowPosition, ImGuiCond_Always, windowPivot);
	PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, 0.3f)); //Transparent background
	Begin("Stats", (bool*)0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings);
	Text("FPS: %.1f", frameRate);
	Text("CPU: %.1f ms", cpuThread);
	PlotLines("", values, IM_ARRAYSIZE(values), 0, "", 30, 65, ImVec2(0, 80)); //Minus 1 so the line doesnt just dip hard to the 0
	End();
	PopStyleColor();
}

void Engine::EngineGUI::MenuBar()
{

	if (BeginMainMenuBar()) {
		if (BeginMenu("File")) {

			if (MenuItem("Save")) {

			}

			Separator();

			if (MenuItem("Quit", "ALT+F4")) {
				RenderEngine::getInstance().CloseWindow();
			}

			EndMenu();
		}

		if (BeginMenu("Edit")) {
			if (MenuItem("Undo", "CTRL+Z")) {
				Undo();
			}

			if (MenuItem("Redo", "CTRL+Y", false, false)) {
				Redo();
			}

			Separator();

			if (MenuItem("Cut", "CTRL+X")) {
				Cut();
			}

			if (MenuItem("Copy", "CTRL+C")) {
				Copy();
			}

			if (MenuItem("Paste", "CTRL+V")) {
				Paste();
			}

			EndMenu();
		}

		if (BeginMenu("Window")) {
			if (BeginMenu("Theme")) {
				if (MenuItem("Classic")) {
					StyleColorsClassic();
				}

				if (MenuItem("Dark")) {
					StyleColorsDark();
				}

				if (MenuItem("Light")) {
					StyleColorsLight();
				}
				EndMenu();
			}
			EndMenu();
		}
		EndMainMenuBar();
	}
	
}
#pragma endregion

#pragma region Menu Functions
void Engine::EngineGUI::Undo()
{
	Debug::getInstance().Log("Undo");
}

void Engine::EngineGUI::Redo()
{
	Debug::getInstance().Log("Redo");
}

void Engine::EngineGUI::Cut()
{
	Debug::getInstance().Log("Cut");
}

void Engine::EngineGUI::Copy()
{
	Debug::getInstance().Log("Copy");
}

void Engine::EngineGUI::Paste()
{
	Debug::getInstance().Log("Paste");
}
#pragma endregion

