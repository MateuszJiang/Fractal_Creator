#pragma once

#include "headers/ZoomList.h"

ZoomList::ZoomList(int w, int h) :m_width(w), m_height(h) {}

void ZoomList::add(const Zoom& z) 
{
	zooms.push_back(z);

	m_xCenter += (z.x - m_width / 2) * m_scale;
	m_yCenter += -(z.y - m_height / 2) * m_scale;

	m_scale *= z.scale;
}

std::pair<double, double> ZoomList::doZoom(int x, int y) 
{
	double xFractal = (x - m_width / 2) * m_scale + m_xCenter;
	double yFractal = (y - m_height / 2) * m_scale + m_yCenter;

	return std::pair<double, double>(xFractal, yFractal);
}
