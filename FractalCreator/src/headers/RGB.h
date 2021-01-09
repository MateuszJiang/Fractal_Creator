#pragma once

#ifndef RGB_H_
#define RGB_H_

struct RGB 
{
	double r;
	double g;
	double b;

	RGB(double, double, double);
};

RGB operator-(const RGB&, const RGB&);

#endif /* RGB_H_ */
