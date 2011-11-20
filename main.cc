#include <iostream>
#include "image.h"

using namespace std;

int main() {
	image uat("TokyoPanoramaShredded.png");

	uat.readPNGInfo();
	uat.readImage();

	cout << "hejsan" << endl;
	return 0;
}
