#include <iostream>

//#include "resources/CImg.h"

//this file is just to produce lists of numbers, etc, or quickly testing other code

int main(){

	// cimg_library::CImg<unsigned char> img( 100, 100, 1, 3, 0 );
	//
	// const unsigned char dark_gold[3] = {127,107,0};
	//
	//
	// img.draw_point(  0,  0, dark_gold);
	// img.draw_point( 20, 20, dark_gold);
	// img.draw_point( 99, 99, dark_gold);
	// img.draw_point(100,100, dark_gold);
	//
	//
	// img.save_png("test.png");



	// int num_points = 0;
	//
	// for(double x = -0.45; x <= 0.45; x += 0.1){
	// 	for(double y = -0.45; y <= 0.45; y += 0.1){
	// 		for(double z = -0.45; z <= 0.45; z += 0.1){
	// 			std::cout << x << " " << y << " " << z << std::endl;
	// 			num_points++;
	// 		}
	// 		std::cout << std::endl;
	// 	}
	// }
	//
	// std:: cout << num_points;

	double inc = 1.0f/395.0f; std::cout << inc << std::endl << std::endl;


	for(double i = -0.5; i < 0.5; i += inc)
	{
		std::cout << i << ",";
	}

	return 0;
}
