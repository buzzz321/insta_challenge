#include <iostream>
#include "image.h"
#include <FreeImage.h>

using namespace std;

int main() {
	image uat("TokyoPanoramaShredded.png");

	uat.loadPNG();
	std::vector<std::vector<RGBQUAD> > ans = uat.getShredPixelBorders(0);

	std::vector<RGBQUAD> temp = ans[0];
	cout << "hejsan" << endl;
	return 0;
}
