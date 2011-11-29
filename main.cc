#include <iostream>
#include "image.h"
#include "Imagecontrol.h"
#include <FreeImage.h>

using namespace std;

int main() {
	ImageControl uat("TokyoPanoramaShredded.png");
	BYTE a,b;
	a=1;
	b=2;

	uat.unshredd();

	cout << "hejsan " <<(unsigned int) (a-b) << endl;
	return 0;
}
