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

	int calc(std::vector<RGBQUAD> leftborder, std::vector<RGBQUAD> rightborder);
	int unshredd();
	virtual ~ImageControl();
};

#endif /* IMAGECONTROL_H_ */
