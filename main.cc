#include <iostream>
#include "image.h"
#include "Imagecontrol.h"
#include <FreeImage.h>

using namespace std;

int main() {
	ImageControl uat("TokyoPanoramaShredded.png");

	uat.unshredd();

	cout << "hejsan" << endl;
	return 0;
}
