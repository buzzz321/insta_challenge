/*
 * Imagecontrol.h
 *
 *  Created on: 22 nov 2011
 *      Author: anders
 */

#ifndef IMAGECONTROL_H_
#define IMAGECONTROL_H_
#include "image.h"

class ImageControl {
private:
	Image m_myImage;

public:
	ImageControl();
	ImageControl(std::string filename);

	int calc(const std::vector<RGBQUAD> &leftborder, const std::vector<RGBQUAD> &rightborder);
	int stdev(const std::vector<RGBQUAD> &leftborder, const std::vector<RGBQUAD> &rightborder, double r_mean, double b_mean, double g_mean);
	int unshredd();
	virtual ~ImageControl();
};

#endif /* IMAGECONTROL_H_ */
