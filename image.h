/*
 * Image.h
 *
 *  Created on: 19 nov 2011
 *      Author: anders
 */

#ifndef IMAGE_H_
#define IMAGE_H_

#include <string>
#include <vector>

#include <FreeImage.h>


class image {
private:
	std::string m_filename;
	std::vector<FIBITMAP *> m_image_shredds();
	FIBITMAP *m_image;
	unsigned int m_width;
	unsigned int m_height;
	unsigned int m_shredds;


public:
	image();
	image(std::string filename);

	bool loadPNG();
	std::vector<std::vector<RGBQUAD> > getShredPixelBorders(unsigned int shredNumber);
	virtual ~image();
//    void shredImage();
    static const int SHRED_WIDTH = 32;
};

#endif /* IMAGE_H_ */
