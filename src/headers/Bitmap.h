#pragma once

#ifndef BITMAP_H_
#define BITMAP_H_

#include <string>
#include <cstdint>
#include <memory>

class Bitmap 
{
private:
	int m_width{0};
	int m_height{0};
	std::unique_ptr<uint8_t[]> m_pPixels{nullptr};


public:
	Bitmap(int, int);
	void setPixel(int, int, uint8_t, uint8_t, uint8_t);
	bool write(std::string);
	virtual ~Bitmap();
};



#endif /* BITMAP_H_ */
