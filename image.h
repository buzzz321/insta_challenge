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
//#include <boost/mpl/vector.hpp>
//#include <boost/gil/gil_all.hpp>
//#include <boost/gil/extension/io/png_dynamic_io.hpp>
//#include <boost/gil/extension/dynamic_image/dynamic_image_all.hpp>
//
//typedef boost::mpl::vector<boost::gil::rgb16_image_t, boost::gil::rgba16_image_t,
//		boost::gil::rgb16_planar_image_t,boost::gil::rgb16s_image_t,
//		boost::gil::rgb8_image_t,boost::gil::rgba8_image_t,
//		boost::gil::rgba32_image_t,boost::gil::rgb32_image_t,
//		boost::gil::rgb32_planar_image_t,boost::gil::rgb32f_image_t> my_images_t;

class image {
private:
	std::string m_filename;
//	boost::gil::rgb16_image_t m_im;
//	boost::gil::any_image<my_images_t> dynamic_img;

public:
	image();
	image(std::string filename);

	int readPNGInfo();
	//int readImage();
	virtual ~image();
};

#endif /* IMAGE_H_ */
