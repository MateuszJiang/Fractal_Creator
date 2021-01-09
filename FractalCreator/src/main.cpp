#pragma once

#include <SFML/Graphics.hpp>
#include "headers/Menu.h"
#include "headers/WindowProperties.h"
#include "headers/FractalCreator.h"
#include "headers/RGB.h"
#include "headers/Zoom.h"
#include <iostream>

void Fractals(std::string,COLORS,SIZES);

int main() 
{
	// creating the window displaying the game
	sf::RenderWindow main_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Fractal Creator", sf::Style::Default);
	main_window.setVerticalSyncEnabled(true);

	// creating menu items
	Menu menu;

	//getting the font
	sf::Font font;
	if (!font.loadFromFile("used/fonts/ComicSans.ttf"))
		return EXIT_FAILURE;

	// vars for creating fractal
	std::string name;                    // name of fractal unused 4 now
	SIZES size = SIZES::SMALL;          // size of fractal
	COLORS color = COLORS::RED;        // color of fractal

	// The loop in which the process is happening
	while (main_window.isOpen())
	{
		sf::Event event;
		while ( main_window.pollEvent(event) )
		{
			switch (event.type)
			{
				case sf::Event::KeyReleased:
				{

					if ( menu.GetMenuIndex() == MENUINDEX::MAINMENU )
					{
						switch (event.key.code)
						{
						case sf::Keyboard::Up:
							menu.MoveUp();
							break;
						case sf::Keyboard::Down:
							menu.MoveDown();
							break;
						case sf::Keyboard::Enter:
							switch (menu.GetPressedMenu())
							{
							case 0:
								std::cout << "here" << std::endl;
								menu.ChangeMenuIndex(MENUINDEX::NEWFRACTAL);
								break;
							case 1:
								menu.ChangeMenuIndex(MENUINDEX::READFRACTAL);
								break;
							case 2:
								// for now there are no options
								break;
							case 3:
								main_window.close();
								break;
							}
						}

					}
					
					else if ( menu.GetMenuIndex() == MENUINDEX::NEWFRACTAL )
					{
						switch (event.key.code)
						{
						case sf::Keyboard::Up:
							menu.MoveUp();
							break;
						case sf::Keyboard::Down:
							menu.MoveDown();
							break;
						case sf::Keyboard::Enter:
							switch (menu.GetPressedNewFractal())
							{
							case 0:
								menu.ChangeMenuIndex(MENUINDEX::COLOR);
								break;
							case 1:
								menu.ChangeMenuIndex(MENUINDEX::SIZE);
								break;
							case 2:
								Fractals("image/test.bmp", color, size);
								menu.ChangeMenuIndex(MENUINDEX::MAINMENU);
								break;
							case 3:
								menu.ChangeMenuIndex(MENUINDEX::MAINMENU);
								break;
							}
						}

					}

					else if (menu.GetMenuIndex() == MENUINDEX::READFRACTAL)
					{
						if (event.key.code == sf::Keyboard::Escape)
							menu.ChangeMenuIndex(MENUINDEX::MAINMENU);
					}

					else if ( menu.GetMenuIndex() == MENUINDEX::COLOR )
					{
						switch (event.key.code)
						{
						case sf::Keyboard::Up:
							menu.MoveUp();
							break;
						case sf::Keyboard::Down:
							menu.MoveDown();
							break;
						case sf::Keyboard::Enter:
							switch (menu.GetPressedColor())
							{
							case 0:
								color = COLORS::WHITE;
								menu.ChangeMenuIndex(MENUINDEX::NEWFRACTAL);
								break;
							case 1:
								color = COLORS::BLUE;
								menu.ChangeMenuIndex(MENUINDEX::NEWFRACTAL);
								break;
							case 2:
								color = COLORS::RED;		
								menu.ChangeMenuIndex(MENUINDEX::NEWFRACTAL);
								break;
							case 3:
								color = COLORS::GREEN;
								menu.ChangeMenuIndex(MENUINDEX::NEWFRACTAL);
								break;
							case 4:
								color = COLORS::PURPLE;
								menu.ChangeMenuIndex(MENUINDEX::NEWFRACTAL);
								break;
							case 5:
								color = COLORS::YELLOW;
								menu.ChangeMenuIndex(MENUINDEX::NEWFRACTAL);
								break;
							case 6:
								color = COLORS::AQUA;
								menu.ChangeMenuIndex(MENUINDEX::NEWFRACTAL);
								break;
							case 7:
								color = COLORS::PINK;
								menu.ChangeMenuIndex(MENUINDEX::NEWFRACTAL);
								break;
							}
							break;
						}

					}

					else if (menu.GetMenuIndex() == MENUINDEX::SIZE)
					{
						switch (event.key.code)
						{
						case sf::Keyboard::Up:
							menu.MoveUp();
							break;
						case sf::Keyboard::Down:
							menu.MoveDown();
							break;
						case sf::Keyboard::Enter:
							switch (menu.GetPressedSize())
							{
							case 0:
								size = SIZES::SMALL;
								menu.ChangeMenuIndex(MENUINDEX::NEWFRACTAL);
								break;
							case 1:
								size = SIZES::MEDIUM;
								menu.ChangeMenuIndex(MENUINDEX::NEWFRACTAL);
								break;
							case 2:
								size = SIZES::BIG;
								menu.ChangeMenuIndex(MENUINDEX::NEWFRACTAL);
								break;
							case 3:
								size = SIZES::LARGE;
								menu.ChangeMenuIndex(MENUINDEX::NEWFRACTAL);
								break;
							case 4:
								size = SIZES::VLARGE;
								menu.ChangeMenuIndex(MENUINDEX::NEWFRACTAL);
								break;
							case 5:
								size = SIZES::LUDICROUS;
								menu.ChangeMenuIndex(MENUINDEX::NEWFRACTAL);
								break;
							}
							break;
						}

					}

				}
			}
		}

		// final drawing of everything with help of Menu.h f-ns
		main_window.clear(sf::Color::Black); 
		menu.draw_proper_menu(main_window);
		main_window.display();

	}
	return 0;
}


void Fractals(std::string fName, COLORS color, SIZES size)
{
	
	FractalCreator *fractalCreator;
	switch (size)
	{
	case SIZES::SMALL :
		fractalCreator = new FractalCreator(800, 600);
		fractalCreator->addZoom(Zoom(295, 202, 0.1));
		fractalCreator->addZoom(Zoom(312, 304, 0.1));
		break;
	case SIZES::MEDIUM :
		fractalCreator = new FractalCreator(1650, 1000);
		break;
	case SIZES::BIG :
		fractalCreator = new FractalCreator(1920, 1080);
		break;
	case SIZES::LARGE :
		fractalCreator = new FractalCreator(3000, 2000);
		break;
	case SIZES::VLARGE :
		fractalCreator = new FractalCreator(3840, 2160);
		break;
	case SIZES::LUDICROUS :
		fractalCreator = new FractalCreator(7680, 4320);
		break;
	default:
		fractalCreator = new FractalCreator(800, 600);
		fractalCreator->addZoom(Zoom(295, 202, 0.1));
		fractalCreator->addZoom(Zoom(312, 304, 0.1));
		break;
	}
	
	switch (color) 
	{
	case COLORS::AQUA :
		fractalCreator->addRange(0.0, RGB(0, 0, 0));
		fractalCreator->addRange(0.3, RGB(0, 184, 150));
		fractalCreator->addRange(0.5, RGB(0, 190, 255));
		fractalCreator->addRange(1.0, RGB(0, 225, 255));
	case COLORS::BLUE :
		fractalCreator->addRange(0.0, RGB(0, 0, 0));
		fractalCreator->addRange(0.3, RGB(0, 0, 180));
		fractalCreator->addRange(0.5, RGB(0, 0, 225));
		fractalCreator->addRange(1.0, RGB(0, 0, 255));
	case COLORS::GREEN :
		fractalCreator->addRange(0.0, RGB(0, 0, 0));
		fractalCreator->addRange(0.3, RGB(0, 180, 0));
		fractalCreator->addRange(0.5, RGB(0, 225, 0));
		fractalCreator->addRange(1.0, RGB(0, 255, 0));
	case COLORS::PINK :
		fractalCreator->addRange(0.0, RGB(0, 0, 0));
		fractalCreator->addRange(0.3, RGB(226, 28, 166));
		fractalCreator->addRange(0.5, RGB(226, 56, 160));
		fractalCreator->addRange(1.0, RGB(226, 94, 160));
	case COLORS::PURPLE :
		fractalCreator->addRange(0.0, RGB(0, 0, 0));
		fractalCreator->addRange(0.3, RGB(127, 0, 151));
		fractalCreator->addRange(0.5, RGB(119, 0, 124));
		fractalCreator->addRange(1.0, RGB(107, 0, 150));
	case COLORS::RED :
		fractalCreator->addRange(0.0, RGB(0, 0, 0));
		fractalCreator->addRange(0.3, RGB(180, 0, 0));
		fractalCreator->addRange(0.5, RGB(225, 0, 0));
		fractalCreator->addRange(1.0, RGB(255, 0, 0));
	case COLORS::WHITE :
		fractalCreator->addRange(0.0, RGB(0, 0, 0));
		fractalCreator->addRange(0.3, RGB(255, 255, 255));
		fractalCreator->addRange(0.5, RGB(255, 255, 255));
		fractalCreator->addRange(1.0, RGB(255, 255, 255));
	case COLORS::YELLOW :
		fractalCreator->addRange(0.0, RGB(0, 0, 0));
		fractalCreator->addRange(0.3, RGB(211, 210, 0));
		fractalCreator->addRange(0.5, RGB(211, 180, 0));
		fractalCreator->addRange(1.0, RGB(211, 156, 0));
	}
	
	fractalCreator->run(fName);
	delete fractalCreator;

}





// redundant code from previous menu 

/*  other version of drawing ( before changes )

else if (is_on && new_frac_input == NONE)
					{
						switch (event.key.code)
						{
						case sf::Keyboard::Up:
							menu.MoveUpNew();
							break;
						case sf::Keyboard::Down:
							menu.MoveDownNew();
							break;
						case sf::Keyboard::Enter:
							switch (menu.GetPressedNewFractal())
							{
							case 0:
								new_frac_input = NAME;
								break;
							case 1:
								new_frac_input = COLOR;
								break;
							case 2:
								new_frac_input = SIZE;
								break;
							case 3:
								is_on = false;
								break;
							}
						}
					}
					else if (is_on && new_frac_input == NAME)
					{
						if (event.key.code == sf::Keyboard::Enter)
						{
							new_frac_input = NONE;
							name = playerInput.toAnsiString();
							std::cout << " HEL " << name;
						}
						else if (event.text.unicode < 128)
						{
							std::cout << "ASCII character typed: " << static_cast<wchar_t>(event.text.unicode) << std::endl;
							playerInput += event.text.unicode;
							playerText.setString(playerInput);
						}


					}
					else if (is_on && new_frac_input == COLOR)
					{
						if (event.type == sf::Event::TextEntered)
						{
							if (event.text.unicode < 128)
							{
								playerInput += event.text.unicode;
								playerText.setString(playerInput);
							}
						}
						else if (event.key.code == sf::Keyboard::Enter)
						{
							new_frac_input = NONE;
							name = playerInput.toAnsiString();
							std::cout << " HEL " << name;
						}
					}
					else if (is_on && new_frac_input == SIZE)
					{
						if (event.type == sf::Event::TextEntered)
						{
							if (event.text.unicode < 128)
							{
								playerInput += event.text.unicode;
								playerText.setString(playerInput);
							}
						}
						else if (event.key.code == sf::Keyboard::Enter)
						{
							new_frac_input = NONE;
							name = playerInput.toAnsiString();
							std::cout << " HEL " << name;
						}
					}




if (is_on && new_frac_input == NONE)
{
	menu.draw_new_fractal(main_window);
}
else if (is_on && (new_frac_input == NAME || new_frac_input == COLOR || new_frac_input == SIZE))
{
	main_window.draw(playerText);
}
else
	menu.draw_menu(main_window);

*/