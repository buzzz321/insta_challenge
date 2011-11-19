/*
 * Image.cpp
 *
 *  Created on: 19 nov 2011
 *      Author: anders
 */

#include "image.h"
#include <iostream>

using namespace std;
using namespace boost;

image::image(): m_filename("") {

}

image::image(string filename): m_filename(filename) {

}

int
image::readImage() {
	gil::png_read_image(m_filename, m_im);

	return 0;
}

image::~image() {
	// TODO Auto-generated destructor stub
}

