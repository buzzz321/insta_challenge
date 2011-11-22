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


class Image {
private:
	std::string m_filename;
	std::vector<FIBITMAP *> m_image_shredds();
	FIBITMAP *m_image;
	unsigned int m_width;
	unsigned int m_height;
	unsigned int m_shredds;


public:
	Image();
	Image(std::string filename);

	bool loadPNG();
	std::vector<RGBQUAD> getShredPixelBorders(unsigned int shrednumber, bool leftside);
	virtual ~Image();
    std::string getFilename() const;
    void setFilename(std::string filename);
    unsigned int getHeight() const;
    unsigned int getShredds() const;
    unsigned int getWidth() const;
//    void shredImage();
    static const int SHRED_WIDTH = 32;
};

#endif /* IMAGE_H_ */
