﻿#pragma once

#include "stdafx.h"

class GameEngine
{
private:
	sf::Window _window;
	bool _isStarted;

	// Helpers
	ExceptionHandler& _exception_handler;
	GameLogger& _game_logger;

public:
	GameEngine();
	~GameEngine();

	void Initialize();
	void Start();

private:
	void Update();
	void Draw();
};
