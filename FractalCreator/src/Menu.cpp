#include "headers/Menu.h"
#include <iostream>

Menu::Menu()
{
	if (!font.loadFromFile("used/fonts/ComicSans.ttf"))
	{
		exit(10);
	}

	// loop for creating the menu options, name excluded and done outside coz of obv reason ( same 4 all menus possible )
	// TITLE
	app_name.setFont(font);
	app_name.setFillColor(sf::Color::Red);
	app_name.setPosition(sf::Vector2f(((WINDOW_WIDTH / 2) - 205), 300));
	app_name.setString("FRACTAL CREATOR");
	//main menu
	for (int i = 0; i < MENU_ITEMS; i++)
	{
		menu[i].setFont(font);
		menu[i].setFillColor(sf::Color::White);
		menu[i].setPosition(sf::Vector2f( ((WINDOW_WIDTH / 2) - 150), ( 500 + 100 * i ) ));

	}
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("New Fractal");
	menu[1].setString("Read Fractal");
	menu[2].setString("Options");
	menu[3].setString("Exit");

	// new fratal
	for (int i = 0; i < NEW_FRAC_ITEMS; i++)
	{
		new_fractal[i].setFont(font);
		new_fractal[i].setFillColor(sf::Color::White);
		new_fractal[i].setPosition(sf::Vector2f( ((WINDOW_WIDTH / 2) - 150), ( 500 + 100 * i ) ));
	}
	new_fractal[0].setFillColor(sf::Color::Red);
	new_fractal[0].setString("Color");
	new_fractal[1].setString("Size");
	new_fractal[2].setString("Create");
	new_fractal[3].setString("Back");

	//colors
	for (int i = 0; i < COLORS::CountColor; i++)
	{
		colors_of_fractal[i].setFont(font);
		colors_of_fractal[i].setFillColor(sf::Color::White);
		colors_of_fractal[i].setPosition(sf::Vector2f( ((WINDOW_WIDTH / 2) - 150), (500 + 100 * i)));
	}
	colors_of_fractal[0].setFillColor(sf::Color::Red);
	colors_of_fractal[0].setString("White");
	colors_of_fractal[1].setString("Blue");
	colors_of_fractal[2].setString("Red");
	colors_of_fractal[3].setString("Green");
	colors_of_fractal[4].setString("Yellow");
	colors_of_fractal[5].setString("Purple");
	colors_of_fractal[6].setString("Aqua");
	colors_of_fractal[7].setString("Pink");

	//sizes
	for (int i = 0; i < SIZES::CountSize; i++)
	{
		sizes_of_fractal[i].setFont(font);
		sizes_of_fractal[i].setFillColor(sf::Color::White);
		sizes_of_fractal[i].setPosition(sf::Vector2f( ((WINDOW_WIDTH / 2) - 150), (500 + 100 * i)));
	}
	sizes_of_fractal[0].setFillColor(sf::Color::Red);
	sizes_of_fractal[0].setString("Small");
	sizes_of_fractal[1].setString("Medium");
	sizes_of_fractal[2].setString("Big");
	sizes_of_fractal[3].setString("Large");
	sizes_of_fractal[4].setString("Very Large");
	sizes_of_fractal[5].setString("Ludicrous");

	menuIndex = MAINMENU;
	mainMenuIndex = 0;
	newFractalIndex = 0;
	colorMenuIndex = 0;
	sizeMenuIndex = 0;
}

Menu::~Menu() {} // destructor

// drawing in the window
void Menu::draw_proper_menu(sf::RenderWindow& window)
{
	switch (menuIndex)
	{
	case MAINMENU:
		draw_title(window);
		draw_menu(window);
		break;

	case NEWFRACTAL:
		draw_title(window);
		draw_new_fractal(window);
		break;

	case READFRACTAL:
		draw_read_fractal(window);
		break;

	case COLOR:
		draw_title(window);
		draw_color_menu(window);
		break;

	case SIZE:
		draw_title(window);
		draw_size_menu(window);
		break;
	}
}

void Menu::draw_menu(sf::RenderWindow& window)
{
	for (int i = 0; i < MENU_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}
void Menu::draw_new_fractal(sf::RenderWindow& window)
{
	for (int i = 0; i < NEW_FRAC_ITEMS; i++)
	{
		window.draw(new_fractal[i]);
	}
}
void Menu::draw_color_menu(sf::RenderWindow& window)
{
	for (int i = 0; i < COLORS::CountColor; i++)
	{
		window.draw(colors_of_fractal[i]);
	}
}
void Menu::draw_size_menu(sf::RenderWindow& window)
{
	for (int i = 0; i < SIZES::CountSize; i++)
	{
		window.draw(sizes_of_fractal[i]);
	}
}
void Menu::draw_read_fractal(sf::RenderWindow& window)
{
	sf::Texture fractal;
	if (!fractal.loadFromFile("used/image/test.bmp"))
		std::cout << "Fractal texture not read" << std::endl;
	sf::Sprite background;

	sf::Vector2u TextureSize;  //Added to store texture size.
	sf::Vector2u WindowSize;   //Added to store window size.
	sf::Vector2u size = fractal.getSize();

	TextureSize = fractal.getSize(); //Get size of texture.
	WindowSize = window.getSize();             //Get size of window.

	float ScaleX = (float)WindowSize.x / TextureSize.x;
	float ScaleY = (float)WindowSize.y / TextureSize.y;     //Calculate scale.

	background.setTexture(fractal);
	background.setScale(ScaleX, ScaleY);      //Set scale.  
	window.draw(background);
}
void Menu::draw_title(sf::RenderWindow& window)
{
	window.draw(app_name);
}

// menu navigation
void Menu::MoveUp()
{
	switch (menuIndex)
	{
	case MAINMENU:
		if (mainMenuIndex > 0)
		{
			menu[mainMenuIndex].setFillColor(sf::Color::White);
			mainMenuIndex--;
			menu[mainMenuIndex].setFillColor(sf::Color::Red);
		}
		break;

	case NEWFRACTAL:
		if (newFractalIndex > 0)
		{
			new_fractal[newFractalIndex].setFillColor(sf::Color::White);
			newFractalIndex--;
			new_fractal[newFractalIndex].setFillColor(sf::Color::Red);
		}
		break;

	case COLOR:
		if (colorMenuIndex > 0)
		{
			colors_of_fractal[colorMenuIndex].setFillColor(sf::Color::White);
			colorMenuIndex--;
			colors_of_fractal[colorMenuIndex].setFillColor(sf::Color::Red);
		}
		break;

	case SIZE:
		if (sizeMenuIndex > 0)
		{
			sizes_of_fractal[sizeMenuIndex].setFillColor(sf::Color::White);
			sizeMenuIndex--;
			sizes_of_fractal[sizeMenuIndex].setFillColor(sf::Color::Red);
		}
		break;
	}
}

void Menu::MoveDown()
{
	switch (menuIndex)
	{
	case MAINMENU:
		if (mainMenuIndex +1 < MENU_ITEMS)
		{
			menu[mainMenuIndex].setFillColor(sf::Color::White);
			mainMenuIndex++;
			menu[mainMenuIndex].setFillColor(sf::Color::Red);
		}
		break;

	case NEWFRACTAL:
		if (newFractalIndex +1 < NEW_FRAC_ITEMS)
		{
			new_fractal[newFractalIndex].setFillColor(sf::Color::White);
			newFractalIndex++;
			new_fractal[newFractalIndex].setFillColor(sf::Color::Red);
		}
		break;

	case COLOR:
		if (colorMenuIndex +1 < COLORS::CountColor)
		{
			colors_of_fractal[colorMenuIndex].setFillColor(sf::Color::White);
			colorMenuIndex++;
			colors_of_fractal[colorMenuIndex].setFillColor(sf::Color::Red);
		}
		break;

	case SIZE:
		if (sizeMenuIndex +1 < SIZES::CountSize)
		{
			sizes_of_fractal[sizeMenuIndex].setFillColor(sf::Color::White);
			sizeMenuIndex++;
			sizes_of_fractal[sizeMenuIndex].setFillColor(sf::Color::Red);
		}
		break;
	}
}

