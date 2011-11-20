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
using namespace boost;

image::image() :
		m_filename("") {
	FreeImage_Initialise();
}

image::image(string filename) :
		m_filename(filename) {
	FreeImage_Initialise();
}

/* gil version..
int image::readImage() {
	try {
		//gil::png_read_image(m_filename, m_im);
		gil::png_read_image(m_filename, dynamic_img);

	} catch (std::exception &ex) {
		cout << ex.what() << endl;
	}
	return 0;
}
*/
int image::readPNGInfo() {
	FREE_IMAGE_FORMAT fif = FreeImage_GetFileType(m_filename.data(), 0); //Automatocally detects the format(from over 20 formats!)
	cout << FreeImage_GetFormatFromFIF(fif) << endl;

	FIBITMAP *imagen = FreeImage_Load(fif, m_filename.data());

	FREE_IMAGE_COLOR_TYPE ct = FreeImage_GetColorType(imagen);
	switch (ct) {
	case FIC_MINISBLACK:
		cout << "FIC_MINISBLACK: " << ct << endl;
		break;
	case FIC_MINISWHITE:
		cout << "FIC_MINISWHITE: " << ct << endl;
		break;
	case FIC_PALETTE:
		cout << "FIC_PALETTE: " << ct << endl;
		break;
	case FIC_RGB:
		cout << "FIC_RGB: " << ct << endl;
		break;
	case FIC_RGBALPHA:
		cout << "FIC_RGBALPHA: " << ct << endl;
		break;
	case FIC_CMYK:
		cout << "FIC_CMYK: " << ct << endl;
		break;
	default:
		cout << "unknown format: " << ct << endl;
		break;
	}

	cout << "BPP: " << FreeImage_GetBPP(imagen) << endl;

	FIBITMAP *bitmap = FreeImage_Copy(imagen, 32, FreeImage_GetHeight(imagen), 32 + 32, 0);

	if (FreeImage_Save(FIF_PNG, bitmap, "sub.png", 0)) {
	// bitmap successfully saved!
	}

	FreeImage_Unload(bitmap);
	FreeImage_Unload(imagen);

	return 0;
}

image::~image() {
	// TODO Auto-generated destructor stub
	FreeImage_DeInitialise();
}

