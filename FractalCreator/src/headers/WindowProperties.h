#pragma once

#ifndef WINDOWPROPERTIES_H_
#define WINDOWPROPERTIES_H_

#define WINDOW_WIDTH 2000		// resolution
#define WINDOW_HEIGHT 1500

#define MENU_ITEMS 4 // # of menu items
#define NEW_FRAC_ITEMS 4

enum MENUINDEX   // which menu is user in ( used to give proper option loops in menu .h/.cpp and main.cpp
{
	MAINMENU,
	NEWFRACTAL,
	READFRACTAL,
	COLOR,
	SIZE
};

// all for proper choices in menu
enum SIZES
{
	SMALL,
	MEDIUM,
	BIG,
	LARGE,
	VLARGE,
	LUDICROUS,
	CountSize
};

enum COLORS
{
	WHITE,
	BLUE,
	RED,
	GREEN,
	PURPLE,
	YELLOW,
	AQUA,
	PINK,
	CountColor
};





#endif // !WINDOWPROPERTIES_H_
