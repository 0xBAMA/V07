#include <iostream>
#include <vector>

#include "../resources/lodepng.h"

//this file is just to produce lists of numbers, etc, or quickly testing other code/libraries

int main(){

	std::vector<unsigned char> image;
	const char * filename1 = "save.png";
	const char * filename2 = "save2.png";

	unsigned width, height;

  //decode
  unsigned error = lodepng::decode(image, width, height, filename1);

  //if there's an error, display it
  if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;

	//Encode the image
  error = lodepng::encode(filename2, image, width, height);

  //if there's an error, display it
  if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;

	return 0;
}
