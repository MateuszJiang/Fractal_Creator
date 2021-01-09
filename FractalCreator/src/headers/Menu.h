#pragma once

#include <SFML/Graphics.hpp>
#include "headers/WindowProperties.h"
#include <iostream>


class Menu
{
public:
	Menu();
	~Menu();

	void draw_proper_menu(sf::RenderWindow&);
	void draw_menu(sf::RenderWindow&);
	void draw_new_fractal(sf::RenderWindow&);
	void draw_color_menu(sf::RenderWindow&);
	void draw_size_menu(sf::RenderWindow&);
	void draw_read_fractal(sf::RenderWindow&);
	void draw_title(sf::RenderWindow&);

	// moving up/down menu options
	void MoveUp();			
	void MoveDown();

	MENUINDEX GetMenuIndex() { return menuIndex; }
	int GetPressedMenu() { return mainMenuIndex; }
	int GetPressedNewFractal() { return newFractalIndex; }
	int GetPressedColor() { return colorMenuIndex; }
	int GetPressedSize() { return sizeMenuIndex; }

	// changes the Index of menu stage in which we operate so we can see and navigate the proper menu
	void ChangeMenuIndex(MENUINDEX mIndex) { menuIndex = mIndex; }
private:
	MENUINDEX menuIndex;
	int mainMenuIndex;
	int newFractalIndex;
	int colorMenuIndex;
	int sizeMenuIndex;

	sf::Font font;

	sf::Text app_name;
	sf::Text menu[MENU_ITEMS];
	sf::Text new_fractal[NEW_FRAC_ITEMS];
	sf::Text colors_of_fractal[COLORS::CountColor];
	sf::Text sizes_of_fractal[SIZES::CountSize];
};