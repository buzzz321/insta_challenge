/*
 * Image.h
 *
 *  Created on: 19 nov 2011
 *      Author: anders
 */

#ifndef IMAGE_H_
#define IMAGE_H_

#include <string>
#include <boost/gil/gil_all.hpp>
#include <boost/gil/extension/io/png_dynamic_io.hpp>

class image {
private:
	std::string m_filename;
	boost::gil::rgb8_image_t m_im;
public:
	image();
	image(std::string filename);

	int readImage();
	virtual ~image();
};

#endif /* IMAGE_H_ */
