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
            if(fif != FIF_UNKNOWN) {
                        cout << FreeImage_GetFormatFromFIF(fif) << " Format\n";
                            }
                cout << message;
                    cout << " ***\n";
}



image::image() :
		m_filename(""), m_image(NULL), m_width(0), m_height(0), m_shredds(0) {
	FreeImage_Initialise();
        FreeImage_SetOutputMessage(FreeImageErrorHandler);

}

image::image(string filename) :
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

std::vector<std::vector<RGBQUAD> > image::getShredPixelBorders(
		unsigned int shredNumber) {
	std::vector<std::vector<RGBQUAD> > retVal;

	if (shredNumber < m_shredds) {
		for (unsigned int xpos = 0; xpos < 2; ++xpos) {
			vector<RGBQUAD> row;
			RGBQUAD quad;
			for (unsigned int ypos = 0; ypos < m_height; ++ypos) {
				FreeImage_GetPixelColor(m_image, (unsigned int)((xpos + shredNumber) * SHRED_WIDTH), ypos, &quad);
				row.push_back(quad);
			}
			retVal.push_back(row);
		}
	}

	return retVal;
}

bool image::loadPNG() {
	FREE_IMAGE_FORMAT fif = FreeImage_GetFileType(m_filename.data(), 0); //Automatically detects the format(from over 20 formats!)
	cout << FreeImage_GetFormatFromFIF(fif) << endl;

	m_image = FreeImage_Load(fif, m_filename.data());

	if (m_image) {
		m_width = FreeImage_GetWidth(m_image);
		m_height = FreeImage_GetHeight(m_image);

		m_shredds = m_width / SHRED_WIDTH;
	}
	return m_image != NULL;
}

image::~image() {
	// TODO Auto-generated destructor stub
	if (m_image != NULL) {
		FreeImage_Unload(m_image);
	}
	FreeImage_DeInitialise();
}

