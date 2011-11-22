/*
 * Imagecontrol.cc
 *
 *  Created on: 22 nov 2011
 *      Author: anders
 */

#include "Imagecontrol.h"
#include <iostream>
#include <cassert>

ImageControl::ImageControl() {
    // TODO Auto-generated constructor stub

}

ImageControl::ImageControl(std::string filename) {
    m_myImage.setFilename(filename);
}

int ImageControl::unshredd() {
    bool ok = m_myImage.loadPNG();

    assert(ok);
    for (unsigned int shreddnr = 0; shreddnr < m_myImage.getShredds() - 1; ++shreddnr) {
        std::cout << shreddnr << std::endl;

        std::vector<RGBQUAD> rightborder = m_myImage.getShredPixelBorders(shreddnr, false);
        for (unsigned int testshredd = 1; testshredd < m_myImage.getShredds(); ++testshredd) {
            std::vector<RGBQUAD> leftborder = m_myImage.getShredPixelBorders(testshredd, true);
        }

    }

    return 0;
}

ImageControl::~ImageControl() {
    // TODO Auto-generated destructor stub
}

