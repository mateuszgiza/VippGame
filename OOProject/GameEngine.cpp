﻿#include "stdafx.h"

#include "GameEngine.h"

GameEngine::GameEngine()
{
	init();
}

GameEngine::~GameEngine()
{
	delete render_window_;
	render_window_ = nullptr;
}

void GameEngine::init()
{
	render_window_ = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML works!");

	if (!font.loadFromFile("consola.ttf"))
	{
		// error...
	}

	fps_counter_ = new FpsCounter(font);
}

void GameEngine::start()
{
	while (render_window_->isOpen())
	{
		sf::Time elapsed_time = update_clock_.restart();

		sf::Event event;
		while (render_window_->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				render_window_->close();
		}

		render_window_->clear(sf::Color::Black);

		GameTime game_time(elapsed_time);

		update(game_time);
		draw();

		render_window_->display();
	}
}

void GameEngine::update(GameTime& game_time)
{
	fps_counter_->update();
}

void GameEngine::draw()
{
	fps_counter_->display(*render_window_);
}
