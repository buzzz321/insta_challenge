/*
 * Imagecontrol.cc
 *
 *  Created on: 22 nov 2011
 *      Author: anders
 */

#include "Imagecontrol.h"
#include <iostream>
#include <cassert>
#include <cstdlib>

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
        for (unsigned int testshredd = 0; testshredd < m_myImage.getShredds(); ++testshredd) {
            std::vector<RGBQUAD> leftborder = m_myImage.getShredPixelBorders(testshredd, true);
            calc(leftborder, rightborder);
        }

    }

    return 0;
}

int ImageControl::calc(std::vector<RGBQUAD> leftborder, std::vector<RGBQUAD> rightborder) {
    std::vector<RGBQUAD> retVal;
    unsigned long red = 0;
    unsigned long green = 0;
    unsigned long blue = 0;

     for(size_t index = 0; index < leftborder.size(); ++index) {
         RGBQUAD p1 = leftborder[index];
         RGBQUAD p2 = rightborder[index];

         red += abs(p2.rgbRed-p1.rgbRed);
         green += abs(p2.rgbGreen-p1.rgbGreen);
         blue += abs(p2.rgbBlue-p1.rgbBlue);
         std::cout <<(int) p2.rgbRed <<": "<< abs(p2.rgbRed-p1.rgbRed) << " " << abs(p2.rgbGreen-p1.rgbGreen) << " " << abs(p2.rgbBlue-p1.rgbBlue) << "\n";
     }

    return 0;
}

ImageControl::~ImageControl() {
    // TODO Auto-generated destructor stub
}

