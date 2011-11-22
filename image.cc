/*
 * Image.cpp
 *
 *  Created on: 19 nov 2011
 *      Author: anders
 */

#include "image.h"
#include <FreeImage.h>
#include <stdio.h>
#include <iostream>

using namespace std;

/**
 *  FreeImage error handler
 *      @param fif Format / Plugin responsible for the error 
 *          @param message Error message
 *          */
void FreeImageErrorHandler(FREE_IMAGE_FORMAT fif, const char *message) {
	cout << "\n*** ";
	if (fif != FIF_UNKNOWN) {
		cout << FreeImage_GetFormatFromFIF(fif) << " Format\n";
	}
	cout << message;
	cout << " ***\n";
}

Image::Image() :
		m_filename(""), m_image(NULL), m_width(0), m_height(0), m_shredds(0) {
	FreeImage_Initialise();
	FreeImage_SetOutputMessage(FreeImageErrorHandler);

}

Image::Image(string filename) :
		m_filename(filename), m_image(NULL), m_width(0), m_height(0), m_shredds(
				0) {
	FreeImage_Initialise();
}

//void image::shredImage() {
//	unsigned int width = FreeImage_GetWidth(m_image);
//
//	FIBITMAP *bitmap = FreeImage_Copy(m_image, SHRED_WIDTH,
//			FreeImage_GetHeight(m_image), SHRED_WIDTH + SHRED_WIDTH, 0);
//
//	FreeImage_Unload(bitmap);
//}

std::vector<RGBQUAD> Image::getShredPixelBorders(unsigned int shrednumber,
		bool leftside) {
	std::vector<RGBQUAD> retVal;

	if (shrednumber < m_shredds) {
		unsigned int borderno = leftside ? 0 : 1;

		RGBQUAD quad;
		for (unsigned int ypos = 0; ypos < m_height; ++ypos) {
			FreeImage_GetPixelColor(m_image,
					(unsigned int) ((borderno + shrednumber) * SHRED_WIDTH), ypos,
					&quad);
			retVal.push_back(quad);
		}

	}

	return retVal;
}

bool Image::loadPNG() {
	FREE_IMAGE_FORMAT fif = FreeImage_GetFileType(m_filename.data(), 0); //Automatically detects the format(from over 20 formats!)
	cout << FreeImage_GetFormatFromFIF(fif) << endl;

	m_image = FreeImage_Load(fif, m_filename.data());

	if (m_image) {
		m_width = FreeImage_GetWidth(m_image);
		m_height = FreeImage_GetHeight(m_image);

		m_shredds = m_width / SHRED_WIDTH;
		cout << "width: " << m_width << endl;
		cout << "height: " << m_height << endl;
		cout << "shredds: " << m_shredds << endl;
	}
	return m_image != NULL;
}

std::string Image::getFilename() const {
	return m_filename;
}

unsigned int Image::getHeight() const {
	return m_height;
}

unsigned int Image::getShredds() const {
	return m_shredds;
}

unsigned int Image::getWidth() const {
	return m_width;
}

void Image::setFilename(std::string filename) {
	m_filename = filename;
}

Image::~Image() {
	// TODO Auto-generated destructor stub
	if (m_image != NULL) {
		FreeImage_Unload(m_image);
	}
	FreeImage_DeInitialise();
}

