#pragma once

#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include "headers/Zoom.h"
#include "headers/Mandelbrot.h"
#include "headers/Bitmap.h"
#include "headers/ZoomList.h"
#include "headers/RGB.h"
#include <string>
#include <cstdint>
#include <memory>
#include <math.h>
#include <vector>

class FractalCreator {
private:
	int m_width;
	int m_height;
	std::unique_ptr<int[]> m_histogram;
	std::unique_ptr<int[]> m_fractal;
	Bitmap m_bitmap;
	ZoomList m_zoomList;
	int m_total { 0 };

	std::vector<int> m_ranges;
	std::vector<RGB> m_colors;
	std::vector<int> m_rangeTotals;

	bool m_bGotFirstRange{false};

private:
	void calculateIteration();
	void calculateTotalIterations();
	void calculateRangeTotals();
	void drawFractal();
	void writeBitmap(std::string);


public:
	FractalCreator();
	FractalCreator(int, int);

	int getRange(int) const;
	void addRange(double, const RGB&);
	void addZoom(const Zoom&);
	virtual ~FractalCreator();
	void run(std::string);
};

#endif /* FRACTALCREATOR_H_ */
