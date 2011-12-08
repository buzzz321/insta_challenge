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
#include <cmath>

ImageControl::ImageControl() {
    // TODO Auto-generated constructor stub

}

ImageControl::ImageControl(std::string filename) {
    m_myImage.setFilename(filename);
}

int ImageControl::unshredd() {
    bool ok = m_myImage.loadPNG();
    bool found= false;

    assert(ok);
    for (unsigned int shreddnr = 0; shreddnr < m_myImage.getShredds() - 1; ++shreddnr) {
        std::cout << "shreddnr: " << shreddnr << std::endl;

        std::vector<RGBQUAD> rightborder = m_myImage.getShredPixelBorders(shreddnr, false);

        for (unsigned int testshredd = 0; testshredd < m_myImage.getShredds() - 1; ++testshredd) {
            if ( testshredd != shreddnr ) {
                std::vector<RGBQUAD> leftborder = m_myImage.getShredPixelBorders(testshredd, true);
                found = calc(leftborder, rightborder);

                if (found) {
                    std::cout << "shreddnr: " << shreddnr << " testshredd: " << testshredd << std::endl;
                }
            }
        }

    }

    return 0;
}

int ImageControl::calc(const std::vector<RGBQUAD> &leftborder, const std::vector<RGBQUAD> &rightborder) {
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
        std::cout <<(int) index <<": "<< abs(p2.rgbRed-p1.rgbRed) << " " << abs(p2.rgbGreen-p1.rgbGreen) << " " << abs(p2.rgbBlue-p1.rgbBlue) << "\n";
    }
    double avg = static_cast<double>(red + green + blue) / static_cast<double>(leftborder.size());
    std::cout << "avg: " << avg << std::endl;

    return avg < 50.0 ? 1 : 0;
}

int ImageControl::stdev(const std::vector<RGBQUAD> &leftborder, const std::vector<RGBQUAD> &rightborder, double r_mean, double b_mean, double g_mean) {
    double r_squaresum = 0.0;
    double g_squaresum = 0.0;
    double b_squaresum = 0.0;

    for(size_t index = 0; index < leftborder.size(); ++index) {
        RGBQUAD p1 = leftborder[index];
        RGBQUAD p2 = rightborder[index];

        r_squaresum += std::pow(static_cast<double>(p2.rgbRed-p1.rgbRed), 2.0);
        g_squaresum += std::pow(static_cast<double>(p2.rgbGreen-p1.rgbGreen), 2.0);
        b_squaresum += std::pow(static_cast<double>(p2.rgbBlue-p1.rgbBlue), 2.0);
    }
    return 0;
}
ImageControl::~ImageControl() {
    // TODO Auto-generated destructor stub
}

