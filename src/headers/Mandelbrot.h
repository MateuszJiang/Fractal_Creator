#pragma once

#ifndef MANDELBROT_H_
#define MANDELBROT_H_

class Mandelbrot 
{
public:
	static const int MAX_ITERATIONS = 1000;

	Mandelbrot();
	virtual ~Mandelbrot();

	static int getIterations(double, double);
};

#endif /* MANDELBROT_H_ */
