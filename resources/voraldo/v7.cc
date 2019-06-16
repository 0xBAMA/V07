#include "v7.h"

#include "../perlin.h"
//perlin noise generation




using std::cout;
using std::endl;

using std::vector;






//---------------------------
Voraldo::Voraldo()
{

  //colors

	palette.resize(100);

  palette[0] = {  0,  0,  0,  0}; //black - here used to represent 'emtpy'



//REDS

  palette[ 1] = {254,  0,  0,255};         //MS Light Red High
  palette[ 2] = {235,138, 96,255};        //MS Light Red Low
  palette[ 3] = {126,  0,  0,255};       //MS Dark Red High
  palette[ 4] = {138, 54, 34,255};      //MS Dark Red Low
  palette[ 5] = {120, 24, 38,255};     //T Dark Red
  palette[ 6] = {165, 45, 39,255};    //T Red

//ORANGES

  palette[ 7] = {255, 77,  0,255};      //Orange 1
  palette[ 8] = {255,120, 30,255};     //Orange 2
  palette[ 9] = {243,120, 43,255};    //Orange 3
  palette[10] = {201,109, 69,255};   //T Orange

 //YELLOWS

  palette[11] = {255,255,  4,255};              //MS Light Yellow High
  palette[12] = {255,217, 63,255};             //MS Light Yellow Low
  palette[13] = {127,107,  0,255};            //Dark Gold
  palette[14] = {126,126,  0,255};           //MS Dark Yellow High
  palette[15] = {170, 92, 61,255};          //MS Dark Yellow Low
  palette[16] = {204,165, 98,255};         //T Yellow Dark
  palette[17] = {207,194,129,255};        //T Yellow Tan
  palette[18] = {209,202,128,255};       //T Yellow
  palette[19] = {162,157,107,255};      //T Tan
  palette[20] = {131,107, 63,255};     //T Light Brown
  palette[21] = { 99, 73, 44,255};    //T Brown
  palette[22] = { 65, 51, 37,255};   //T Dark Brown

//GREENS

  palette[23] = {  6,255,  4,255};          //MS Light Green High
  palette[24] = {108,217, 71,255};         //MS Light Green Low
  palette[25] = {  4,126,  0,255};        //MS Dark Green High
  palette[26] = { 12,126, 69,255};       //MS Dark Green Low
  palette[27] = {151,181,138,255};      //T Light Green
  palette[28] = {101,132, 92,255};     //T Med Green
  palette[29] = { 34, 58, 48,255};    //T Med-Dark Green
  palette[30] = { 32, 44, 17,255};   //T Dark Green

//BLUE/INDIGO

  palette[31] = {  0,  0,126,255};             //MS Dark Blue High
  palette[32] = { 34, 52,209,255};            //MS Dark Blue Low
  palette[33] = {  0,  0,255,255};           //MS Light Blue High
  palette[34] = { 76,129,251,255};          //MS Light Blue Low
  palette[35] = { 62, 62,138,255};         //T Med Blue
  palette[36] = { 76,110,173,255};        //T Dark blue
  palette[37] = {124,168,213,255};       //T Blue
  palette[38] = {172,220,241,255};      //T Light Blue
  palette[39] = {  4,126,126,255};     //MS Dark Teal High
  palette[40] = { 68,170,204,255};    //MS Dark Teal Low
  palette[41] = {  6,255,255,255};   //MS Light Teal High
  palette[42] = {123,226,249,255};  //MS Light Teal low

//VIOLET

  palette[43] = {254,  0,255,255};          //MS Light Purple High
  palette[44] = {226, 61,105,255};         //MS Light Purple Low
  palette[45] = { 82, 30, 46,255};        //T Maroon
  palette[46] = {126,  0,126,255};       //MS Dark Purple High
  palette[47] = { 92, 46,120,255};      //MS Dark Purple Low
  palette[48] = { 88, 38, 79,255};     //T Darker Purple
  palette[49] = { 80, 59,104,255};    //T Dark Purple
  palette[50] = {133, 91,105,255};   //T Purple
  palette[51] = {223,185,202,255};  //T Pink

//GREYSCALE

  palette[52] = {255,255,255,255};             //White
  palette[53] = {190,190,190,255};            //MS Light Grey High
  palette[54] = {181,181,181,255};           //MS Light Grey Low
  palette[55] = {126,126,126,255};          //MS Dark Grey High
  palette[56] = { 94, 96,110,255};         //MS Dark Grey Low
  palette[57] = {212,237,237,255};        //T Lighter Grey
	palette[58] = {172,194,195,255};			 //T Light Grey
  palette[59] = {134,149,152,255};      //T Med Light Grey
  palette[60] = { 95, 99,103,255};     //T Med Grey
  palette[61] = { 58, 59, 61,255};    //T Dark-Med Grey
  palette[62] = { 40, 34, 31,255};   //T Dark Grey
  palette[63] = {  0,  0,  0,255};  //Black


// weird desaturated palette "steam lords"
  palette[64] = { 33, 59, 37,255};	              //#213b25 dark green
  palette[65] = { 58,	96,	74,255};	             //#3a604a medium green
  palette[66] = { 79,119, 84,255};	            //#4f7754 light green
  palette[67] = {161,159,124,255}; 	           //#a19f7c light tan
  palette[68] = {119,116,	79,255};	          //#77744f medium tan
  palette[69] = {119,	92,	79,255};	         //#775c4f light rose
  palette[70] = { 96,	59,	58,255};	        //#603b3a dark rose
  palette[71] = { 59,	33,	55,255};	       //#3b2137 purple
  palette[72] = { 23,	14,	25,255};      	//#170e19 darkest blue (0)
  palette[73] = { 47,	33,	59,255};	     //#2f213b dark blue (1)
  palette[74] = { 67,	58,	96,255};	    //#433a60 dark blue (2)
  palette[75] = { 79,	82,119,255};	   //#4f5277 dark blue (3)
  palette[76] = {101,115,140,255};	  //#65738c light blue (4)
  palette[77] = {124,148,161,255};	 //#7c94a1 light blue (5)
  palette[78] = {160,185,186,255};	//#a0b9ba light blue (6)
  palette[79] = {192,209,204,255}; //#c0d1cc light blue (7)



  data.resize(0);
  // call draw.init_block(x,y,z,noise_fill)
  // to populate the data array
}

Voraldo::~Voraldo()
{

}






//  _________________    ________
//  \______   \      \  /  _____/
//   |     ___/   |   \/   \  ___
//   |    |  /    |    \    \_\  \
//   |____|  \____|__  /\______  /
//                   \/        \/ //saving the block to send to OpenGL, loading the same format


//     _________ __   _____
//    / ___/ __ `/ | / / _ \
//   (__  ) /_/ /| |/ /  __/
//  /____/\__,_/ |___/\___/
// ----------------------- // this is fundamental to the interoperability of the two programs gen and vu

void Voraldo::save_16_bit( std::string filename )
{
  // using namespace cimg_library;

  int width = x_dim;
  int height = y_dim;
  int depth = z_dim;

  // cout << "saving block of " << width << " " << height << " " << depth << endl;


  Vox temp;
  RGBA temporary_color;

  // std::vector<unsigned char> image;
	std::vector<unsigned char> color_image;
	std::vector<unsigned char> alpha_grayscale_image;


  unsigned image_width = width;
  unsigned image_height = height * depth;

  int color_image_size = 3 * width * height * depth;
	int alpha_grayscale_image_size = 2 * width * height * depth;

  color_image.resize( color_image_size );
	alpha_grayscale_image.resize( alpha_grayscale_image_size );




  int color_image_index = 0;
	int alpha_grayscale_image_index = 0;

	// put the data in the image

  for(int z = 0; z < depth; z++)
  {
    for(int y = 0; y < height; y++)
    {
      for(int x = 0; x < width; x++)
      {

        temp = get_data_by_vector_index(vec( x, y, z ) );

        temporary_color = temp.color;


				color_image[color_image_index] = temporary_color.red;
				color_image_index++;

				color_image[color_image_index] = temporary_color.green;
				color_image_index++;

				color_image[color_image_index] = temporary_color.blue;
				color_image_index++;


        alpha_grayscale_image[alpha_grayscale_image_index] = temporary_color.alpha;
				alpha_grayscale_image_index++;

				alpha_grayscale_image[alpha_grayscale_image_index] = temporary_color.alpha_low;
				alpha_grayscale_image_index++;


      }

    }

  }

  //z * height * width  +  y * width  +  x

	unsigned error = lodepng::encode("current_model/" + filename + "_color_8bit.png", color_image, image_width, image_height,  LodePNGColorType::LCT_RGB, 8 );

	if(error) std::cout << "encoder error on the color image step " << error << ": "<< lodepng_error_text(error) << std::endl;

	error = lodepng::encode("current_model/" + filename + "_alpha_16bit.png", alpha_grayscale_image, image_width, image_height,  LodePNGColorType::LCT_GREY, 16 );

	if(error) std::cout << "encoder error on the alpha image step " << error << ": "<< lodepng_error_text(error) << std::endl;



}


//      __                __
//     / /___  ____ _____/ /
//    / / __ \/ __ `/ __  /
//   / / /_/ / /_/ / /_/ /
//  /_/\____/\__,_/\__,_/
// --------------------- // this is significant, because it allows external editing of models, i.e. with GIMP

void Voraldo::load_16_bit( std::string filename )
{
	std::vector<unsigned char> color_image;
	std::vector<unsigned char> alpha_image;


	unsigned width, height;

	int color_image_index = 0;
	int alpha_image_index = 0;


	//decode
	unsigned error = lodepng::decode( color_image, width, height, "current_model/" + filename + "color_8bit.png",  LodePNGColorType::LCT_RGB, 8 );

	//if there's an error, display it
	if(error) std::cout << "decoder error in color image step - " << error << ": " << lodepng_error_text( error ) << std::endl;



	error = lodepng::decode( alpha_image, width, height, "current_model/" + filename + "alpha_16bit.png",  LodePNGColorType::LCT_GREY, 16 );

	if(error) std::cout << "decoder error in alpha image step - " << error << ": " << lodepng_error_text( error ) << std::endl;



	// initialize block with dimensions 512 x 256 x 256

	init_block( vec( 512, 256, 256 ) );

	// now get the data out of the image

	RGBA temp;

	for(int z = 0; z < 256; z++)
  {
    for(int y = 0; y < 256; y++)
    {
      for(int x = 0; x < 512; x++)
      {
				temp.red   = color_image[color_image_index];
				color_image_index++;

				temp.green = color_image[color_image_index];
				color_image_index++;

				temp.blue  = color_image[color_image_index];
				color_image_index++;


				temp.alpha = alpha_image[alpha_image_index];
				alpha_image_index++;

				temp.alpha_low = alpha_image[alpha_image_index];
				alpha_image_index++;


				set_data_by_vector_index( vec( x, y, z ), get_vox( temp, false ), true, false );
      }
    }
  }




}



//     _________ __   _____
//    / ___/ __ `/ | / / _ \
//   (__  ) /_/ /| |/ /  __/
//  /____/\__,_/ |___/\___/
// ----------------------- // this is fundamental to the interoperability of the two programs gen and vu

void Voraldo::save( std::string filename )
{
  // using namespace cimg_library;

  int width = x_dim;
  int height = y_dim;
  int depth = z_dim;

  // cout << "saving block of " << width << " " << height << " " << depth << endl;


  Vox temp;
  RGBA temporary_color;

  std::vector<unsigned char> image;

  unsigned image_width = width;
  unsigned image_height = height * depth;

  int size = 4 * width * height * depth;

  image.resize( size );

  // cout << "vector declared with " << image.capacity() << " elements" << endl;
  // cout << "vector max size of " << image.max_size() << " elements" << endl << endl;


  int index = 0;

	// put the data in the image

  for(int z = 0; z < depth; z++)
  {
    for(int y = 0; y < height; y++)
    {
      for(int x = 0; x < width; x++)
      {

        temp = get_data_by_vector_index(vec( ( float ) x, ( float ) y, ( float ) z ) );

        temporary_color = temp.color;

        image[index] = temporary_color.red;   index++;
        image[index] = temporary_color.green; index++;
        image[index] = temporary_color.blue;  index++;
        image[index] = temporary_color.alpha; index++;


      }

    }

  }

  //z * height * width  +  y * width  +  x

  unsigned error = lodepng::encode(filename.c_str(), image, image_width, image_height);
  if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
}


//      __                __
//     / /___  ____ _____/ /
//    / / __ \/ __ `/ __  /
//   / / /_/ / /_/ / /_/ /
//  /_/\____/\__,_/\__,_/
// --------------------- // this is significant, because it allows external editing of models, i.e. with GIMP

void Voraldo::load( std::string filename )
{
	std::vector<unsigned char> image;

	unsigned width, height;

	int index = 0;

	//decode
	unsigned error = lodepng::decode( image, width, height, filename.c_str( ) );

	//if there's an error, display it
	if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text( error ) << std::endl;

	// initialize block with dimensions 512 x 256 x 256

	init_block( vec( 512, 256, 256 ) );

	// now get the data out of the image

	RGBA temp;

	for(int z = 0; z < 256; z++)
  {
    for(int y = 0; y < 256; y++)
    {
      for(int x = 0; x < 512; x++)
      {

				temp.red   = image[index]; index++;
				temp.green = image[index]; index++;
				temp.blue  = image[index]; index++;
				temp.alpha = image[index]; index++;

				set_data_by_vector_index( vec( ( float ) x, ( float ) y, ( float ) z ), get_vox( temp, false ), true, false );

      }

    }

  }




}










void Voraldo::init_block(vec dimensions)
{

	if(data.size() != 0)
	{
		data.resize(0);
	}

	x_dim = dimensions[0];
	y_dim = dimensions[1];
	z_dim = dimensions[2];

	num_cells = x_dim * y_dim * z_dim;

  data.resize(x_dim);

  for( int i = 0; i < x_dim; i++ )
  {

    data[i].resize(y_dim);

    for( int j = 0; j < y_dim; j++ )
      data[i][j].resize(z_dim);

  }

  for( int x = 0; x < x_dim; x++ )
  {
    for( int y = 0; y < y_dim; y++ )
    {
      for( int z = 0; z < z_dim; z++ )
      {//per voxel

       	// data[x][y][z].color.red = x/2;
        // data[x][y][z].color.green = y;
        // data[x][y][z].color.blue = z;
        // data[x][y][z].color.alpha = 100;

        data[x][y][z].color.red   = 0;
        data[x][y][z].color.green = 0;
        data[x][y][z].color.blue  = 0;
        data[x][y][z].color.alpha = data[x][y][z].color.alpha_low  = 0;


        data[x][y][z].mask = false;
      }
    }
  }















	// data.resize( num_cells + 1 );
  //
	// Vox temp;
  //
	// for( int x = 0; x < x_dim; x++ )
	// {
	// 	for( int y = 0; y < y_dim; y++ )
	// 	{
	// 		for( int z = 0; z < z_dim; z++ )
	// 		{
	// 			temp.mask = false;
	// 			temp.color = palette[0];
	// 			temp.location = vec(x,y,z);
	// 		}
	// 	}
	// }
}// init_block does need a nested for loop

void Voraldo::clear_all()
{ // note that this function has a bit more to it than you might initially think -
  //  first - deliberately do not unmask - there is a separate function for that operation - mask_unmask_all()
  //  second - this relies upon the state of the mask variables for each cell, a masked cell is not cleared

  for( int x = 0; x < x_dim; x++ )
  {
    for( int y = 0; y < y_dim; y++ )
    {
      for( int z = 0; z < z_dim; z++ )
      {// per voxel

        if(!data[x][y][z].mask)
        {
          data[x][y][z].color = {  0,  0,  0,  0};
        }
      }
    }
  }
}

//     _____      _____    _____________  __.
//    /     \    /  _  \  /   _____/    |/ _|
//   /  \ /  \  /  /_\  \ \_____  \|      <
//  /    Y    \/    |    \/        \    |  \
//  \____|__  /\____|__  /_______  /____|__ \
//          \/         \/        \/        \/

void Voraldo::mask_unmask_all()
{
  // nlohmann::json j;
  // j["type"] = "unmask_all";
  // std::cout << j.dump() << endl;

  for( int x = 0; x < x_dim; x++ )
  {
    for( int y = 0; y < y_dim; y++ )
    {
      for( int z = 0; z < z_dim; z++ )
      {//per voxel

        data[x][y][z].mask = false;
      }
    }
  }
}

void Voraldo::mask_invert_mask()
{
  // nlohmann::json j;
  // j["type"] = "invert_mask";
  // std::cout << j.dump() << endl;

  for( int x = 0; x < x_dim; x++ )
  {
    for( int y = 0; y < y_dim; y++ )
    {
      for( int z = 0; z < z_dim; z++ )
      {//per voxel

        data[x][y][z].mask = data[x][y][z].mask ? false:true;
      }
    }
  }
}

void Voraldo::mask_all_nonzero()
{
 for( int x = 0; x < x_dim; x++ )
 {
   for( int y = 0; y < y_dim; y++ )
   {
     for( int z = 0; z < z_dim; z++ )
     {
       if( !compare_colors( data[x][y][z].color, {  0,  0,  0,  0} ) )
       {//per voxel

         data[x][y][z].mask = true;
       }
     }
   }
 }
}

void Voraldo::mask_by_state(unsigned char s)
{
 for( int x = 0; x < x_dim; x++ )
 {
   for( int y = 0; y < y_dim; y++ )
   {
     for( int z = 0; z < z_dim; z++ )
     {//per voxel

       if( compare_colors( data[x][y][z].color, palette[s] ) )
       {
         data[x][y][z].mask = true;
       }
     }
   }
 }
}

//  ____________________.___   _____  .______________._______   _______________ _________
//  \______   \______   \   | /     \ |   \__    ___/|   \   \ /   /\_   _____//   _____/
//   |     ___/|       _/   |/  \ /  \|   | |    |   |   |\   Y   /  |    __)_ \_____  \
//   |    |    |    |   \   /    Y    \   | |    |   |   | \     /   |        \/        \
//   |____|    |____|_  /___\____|__  /___| |____|   |___|  \___/   /_______  /_______  /
//                    \/            \/                                      \/        \/

void Voraldo::draw_perlin_noise(float scale, float threshold, Vox set, bool draw, bool mask)
{
  // old version
  //
  // void Voraldo::draw_perlin_noise(/*int seed, unsigned char alpha*/ Vox set, bool draw, bool mask)
  // std::srand(seed);
  // for(int i = 0; i < num_cells; i++)
  // {
  //    if(std::rand()%696 == 69 && std::rand()%696 < 30)
  //    {
  //      if(!data.at(i).mask)
  //      {
  //         data.at(i).state = (std::rand()%30)+1;//this is a little different
  //         data.at(i).alpha = alpha;
  //         data.at(i).mask = mask;
  //         data.at(i).lighting_intensity = lighting_intensity;
  //      }
  //    }
  // }


	PerlinNoise p;


	if(threshold >= 0)
	{
	  for( int x = 0; x < x_dim; x++ )
	  {
	    for( int y = 0; y < y_dim; y++ )
	    {
	      for( int z = 0; z < z_dim; z++ )
	      {//per voxel

	        if( p.noise( scale*x, scale*y, scale*z ) < threshold )
	        {
	          draw_point( vec( x, y, z ), set, draw, mask );
	        }
	      }
	    }
	  }
	}
	else
	{
		threshold = std::abs(threshold);

		for( int x = 0; x < x_dim; x++ )
		{
			for( int y = 0; y < y_dim; y++ )
			{
				for( int z = 0; z < z_dim; z++ )
				{//per voxel

					if( p.noise( scale*x, scale*y, scale*z ) > threshold )
					{
						draw_point( vec( x, y, z ), set, draw, mask );
					}
				}
			}
		}
	}
}

void Voraldo::draw_point(vec point, Vox set, bool draw, bool mask)
{
  set_data_by_vector_index(point,set,draw,mask);
}

void Voraldo::draw_line_segment(vec v1, vec v2, Vox set, bool draw, bool mask)
{
  vec starting_point = v1;
	vec current_point = starting_point;
	vec line_vector = (v2-v1);

	int length = glm::length(line_vector);

	for(int i = 0; i < length; i++)
	{
		current_point[0] = std::floor(starting_point[0] + i*(line_vector[0]/length));
		current_point[1] = std::floor(starting_point[1] + i*(line_vector[1]/length));
		current_point[2] = std::floor(starting_point[2] + i*(line_vector[2]/length));

    if(current_point[0] < 0 || current_point[0] >= x_dim ||
       current_point[1] < 0 || current_point[1] >= y_dim ||
       current_point[2] < 0 || current_point[2] >= z_dim )
    {
      break;
    }

    draw_point(current_point,set,draw,mask);
	}
}

void Voraldo::draw_triangle(vec v0, vec v1, vec v2, float thickness, Vox set, bool draw, bool mask)
{

 //point zero is the origin point

 	vec side1 = v1-v0;
 	vec side2 = v2-v0;

 	vec c1(0,0,0);
 	vec c2(0,0,0);
  //c1 and c2 are the ends of the line segment that is going to be drawn
  // these endpoints are ranged along the two sides so as to achieve coverage

 	float length;

 	if(glm::length(side1) > glm::length(side2))
 	{
    // length = std::floor(glm::length(side1));
 		length = glm::length(side1);
 	}
 	else
 	{
 		// length = std::floor(glm::length(side2));
    length = glm::length(side2);
  }

 	if( length <= 2 && thickness <= 2 )
  {
 		draw_point(v0,set);
 		draw_point(v1,set);
 		draw_point(v2,set);
 	}
  else
  {
    // // legacy triangle algorithm - has a lot of artifacts
 		// side1 = side1/length;
 		// side2 = side2/length;
    //
 		// for(double i = 0; i < length; i+=0.1)
 		// {
    //
 		// 	c1[0] = v0[0] + i*side1[0];
 		// 	c1[1] = v0[1] + i*side1[1];
 		// 	c1[2] = v0[2] + i*side1[2];
    //
 		// 	c2[0] = v0[0] + i*side2[0];
 		// 	c2[1] = v0[1] + i*side2[1];
 		// 	c2[2] = v0[2] + i*side2[2];
    //
 		// 	draw_line_segment(c1,c2,set,draw,mask);
    //
 		// }



    // NEW TRIANGLE ALGORITHM - based on the quadrilateral hexahedron function, it's more of a triangular prism

    bool face1, face2, face3, face4, face5;   face1 = face2 = face3 = face4 = face5 = false;
    vec testvec;


    vec triangle_center = ( v0 + v1 + v2 ) / 3.0f;

    vec triangle_normal_pos = normalize( cross( side1, side2 ) );
    vec triangle_normal_neg = -1.0f * triangle_normal_pos;

    vec v0_up   = v0 + thickness * triangle_normal_pos;
    vec v0_down = v0 + thickness * triangle_normal_neg;

    vec v1_up   = v1 + thickness * triangle_normal_pos;
    vec v1_down = v1 + thickness * triangle_normal_neg;

    vec v2_up   = v2 + thickness * triangle_normal_pos;
    vec v2_down = v2 + thickness * triangle_normal_neg;

    // there are 5 planes to test against

      // the two triangular faces, face1 and face2

      // three sides, face3, face4 and face5

    vec face1_point = v0_up;
    vec face1_normal = triangle_normal_pos;

    vec face2_point = v0_down;
    vec face2_normal = triangle_normal_neg;


    // face3 is between v0 and v1
    vec face3_point = v0;
    vec face3_normal = cross( v0_up - v0_down, v0 - v1 );

    // face4 is between v1 and v2
    vec face4_point = v1;
    vec face4_normal = cross( v1_up - v1_down, v1 - v2 );

    // face5 is between v2 and v0
    vec face5_point = v2;
    vec face5_normal = cross( v2_up - v2_down, v2 - v0 );


    //note on planetest:
    // return false if the point is above the plane
   	// return true if the point is below the plane


    // these only have to run once, to confirm the normals are correct - they check a point
    // that is known to be in the triangular prism - if the plane test fails, invert the normal

    if( !planetest( face3_point, face3_normal, triangle_center ) )
    {
      face3_normal = -1.0f * face3_normal;
    }

    if( !planetest( face4_point, face4_normal, triangle_center ) )
    {
      face4_normal = -1.0f * face4_normal;
    }

    if( !planetest( face5_point, face5_normal, triangle_center ) )
    {
      face5_normal = -1.0f * face5_normal;
    }

    for( int x = 0; x < x_dim; x++ )
    {
      for( int y = 0; y < y_dim; y++ )
      {
        for( int z = 0; z < z_dim; z++ )
        {//per voxel

          testvec = vec(x,y,z);

          face1 = planetest( face1_point, face1_normal, testvec );
          face2 = planetest( face2_point, face2_normal, testvec );
          face3 = planetest( face3_point, face3_normal, testvec );
          face4 = planetest( face4_point, face4_normal, testvec );
          face5 = planetest( face5_point, face5_normal, testvec );

          if( face1 && face2 && face3 && face4 && face5 )
          {
            draw_point(testvec,set,draw,mask);
          }
        }
      }
    }
 	}
}

void Voraldo::draw_sphere(vec center_point, double radius, Vox set, bool draw, bool mask)
{

 vec index;
 for(int i = 0; i < x_dim; i++)
 	{
 		for(int j = 0; j < y_dim; j++)
 		{
 			for(int k = 0; k < z_dim; k++)
 			{//per voxel

 				double testx = (i-center_point[0])*(i-center_point[0]);	//apply offsets and square
 				double testy = (j-center_point[1])*(j-center_point[1]);
 				double testz = (k-center_point[2])*(k-center_point[2]);

 				if((testx + testy + testz) < radius*radius)
 				{	//pretty self explainatory, equation of sphere
          index = vec(i,j,k);
 					draw_point(index,set,draw,mask);
 				}
 			}
 		}
 	}
}

void Voraldo::draw_ellipsoid(vec center_point, vec radii, Vox set, bool draw, bool mask)
{
  vec index;

  for(int i = 0; i < x_dim; i++)
 	{
 		for(int j = 0; j < y_dim; j++)
 		{
 			for(int k = 0; k < z_dim; k++)
 			{//per voxel

 				double testx = (i-center_point[0])*(i-center_point[0]);	//apply offsets and square
 				double testy = (j-center_point[1])*(j-center_point[1]);
 				double testz = (k-center_point[2])*(k-center_point[2]);

 				double radx = radii[0]*radii[0];
 				double rady = radii[1]*radii[1];
 				double radz = radii[2]*radii[2];

 				double result = testx/radx + testy/rady + testz/radz;

 				if(result <= 1){	//point inside ellipsoid - do we want to be able to invert this?
 					//(outside, or on the surface, with >= and ==, respectively)
          index = vec(i,j,k);
 					draw_point(index,set,draw,mask);
 				}
 			}
 		}
 	}
}

void Voraldo::draw_cylinder(vec bvec, vec tvec, double radius, Vox set, bool draw, bool mask)
{
 	vec ndirection = tvec - bvec;

	auto bx0 = bvec[0]; auto ba = ndirection[0];	auto tx0 = tvec[0]; auto ta = ndirection[0];
	auto by0 = bvec[1]; auto bb = ndirection[1];	auto ty0 = tvec[1]; auto tb = ndirection[1];
	auto bz0 = bvec[2]; auto bc = ndirection[2];	auto tz0 = tvec[2]; auto tc = ndirection[2];

	//I did this on a whiteboard

	double bplanetest = 0.0;
	double tplanetest = 0.0;

	double point_to_line_distance = 0.0;

 vec index;

	for(int i = 0; i < x_dim; i++)
  {
		for(int j = 0; j < y_dim; j++)
    {
			for(int k = 0; k < z_dim; k++)
      {//per voxel

				//planetests
				bplanetest = ba * (i - bx0) + bb * (j - by0) + bc * (k - bz0);
				tplanetest = ta * (i - tx0) + tb * (j - ty0) + tc * (k - tz0);

				//using the basic equation for a plane, we can do an interesting test

				//These variables will be greater than zero if the test point is on the side of the plane
				//that the normal vector is pointing towards, and less than zero if the test point is on
				//the side of the plane that the normal vector is not pointing towards. That is to say, in
				//my case - bplanetest tells me whether the point is above the bottom plane, and tplanetest
				//tells me whether the point is above the top plane. If it is above the bottom, and below
				//the top - we are within the ends of the cylinder, and can proceed. Thus, the condition
				//for the following if statement:

				if(bplanetest >= 0 && tplanetest <= 0){

					//do the point to line distance thing
					//algorithm from http://mathworld.wolfram.com/Point-LineDistance3-Dimensional.html

					//This test takes as a precondition that the point is determined to be within the slice
					//of space established by two parallel planes. Now that this is known, we will see how
					//far they are from the line, which runs perpendicular to both planes. If both of these
					//sequential tests evaluate positively, we know we are within the extents of the cylinder.

					point_to_line_distance = glm::length(cross(tvec-bvec,bvec-vec(i,j,k)))/glm::length(tvec-bvec);
					if(point_to_line_distance <= radius)
          {
            // cout << "point to line distance test passed" << endl;
            index = vec(i,j,k);
						draw_point(index,set,draw,mask);
					}
				}
			}
		}
	}
}

void Voraldo::draw_tube(vec bvec, vec tvec, double inner_radius, double outer_radius, Vox set, bool draw, bool mask)
{
  vec ndirection = tvec - bvec;

 	auto bx0 = bvec[0]; auto ba = ndirection[0];	auto tx0 = tvec[0]; auto ta = ndirection[0];
 	auto by0 = bvec[1]; auto bb = ndirection[1];	auto ty0 = tvec[1]; auto tb = ndirection[1];
 	auto bz0 = bvec[2]; auto bc = ndirection[2];	auto tz0 = tvec[2]; auto tc = ndirection[2];

 	//I did this on a whiteboard

 	double bplanetest = 0.0;
 	double tplanetest = 0.0;

 	double point_to_line_distance = 0.0;
  vec index;

 	for(int i = 0; i < x_dim; i++)
  {
 		for(int j = 0; j < y_dim; j++)
    {
 			for(int k = 0; k < z_dim; k++)
      {//per voxel

 				//planetests
 				bplanetest = ba * (i - bx0) + bb * (j - by0) + bc * (k - bz0);
 				tplanetest = ta * (i - tx0) + tb * (j - ty0) + tc * (k - tz0);

 				//using the basic equation for a plane, we can do an interesting test

 				//These variables will be greater than zero if the test point is on the side of the plane
 				//that the normal vector is pointing towards, and less than zero if the test point is on
 				//the side of the plane that the normal vector is not pointing towards. That is to say, in
 				//my case - bplanetest tells me whether the point is above the bottom plane, and tplanetest
 				//tells me whether the point is above the top plane. If it is above the bottom, and below
 				//the top - we are within the ends of the cylinder, and can proceed. Thus, the condition
 				//for the following if statement:

 				if(bplanetest >= 0 && tplanetest <= 0){
 					//do the point to line distance thing
 					//algorithm from http://mathworld.wolfram.com/Point-LineDistance3-Dimensional.html

 					//This test takes as a precondition that the point is determined to be within the slice
 					//of space established by two parallel planes. Now that this is known, we will see how
 					//far they are from the line, which runs perpendicular to both planes. If both of these
 					//sequential tests evaluate positively, we know we are within the extents of the cylinder.

 					point_to_line_distance = glm::length(cross(tvec-bvec,bvec-vec(i,j,k)))/glm::length(tvec-bvec);

 					if(point_to_line_distance <= outer_radius && point_to_line_distance >= inner_radius)
          {
            index = vec(i,j,k);
            draw_point(index,set,draw,mask);
 					}
 				}
 			}
 		}
 	}
}

void Voraldo::draw_quadrilateral_hexahedron(vec a, vec b, vec c, vec d, vec e, vec f, vec g, vec h, Vox set, bool draw, bool mask)
{
	  vec center = a + b + c + d + e + f + g + h;
	 	center = vec(center[0]/8, center[1]/8, center[2]/8);

	 	bool plusx1 = false;
	 	bool plusx2 = false;

	 //    888   Y88b  /
	 //  __888__  Y88b/
	 //    888     Y88b
	 //    888     /Y88b
	 //           /  Y88b

	 	//CDGH

	 	//TRIANGLES ARE CDH, CGH

	 	vec plusx_side1 = vec(c[0]-d[0],c[1]-d[1],c[2]-d[2]);
	 	vec plusx_side2 = vec(h[0]-d[0],h[1]-d[1],h[2]-d[2]);

	 	vec plusx_side3 = vec(c[0]-g[0],c[1]-g[1],c[2]-g[2]);
	 	vec plusx_side4 = vec(h[0]-g[0],h[1]-g[1],h[2]-g[2]);

	 	vec plusx_planevec1 = cross(plusx_side1,plusx_side2);
	 	vec plusx_planept1 = d;

	 	vec plusx_planevec2 = cross(plusx_side3,plusx_side4);
	 	vec plusx_planept2 = g;

	 	if(!planetest(plusx_planept1,plusx_planevec1,center))
	 	{	//if the center fails the plane test, flip the normal
	 		plusx_planevec1 = vec(-1*plusx_planevec1[0],-1*plusx_planevec1[1],-1*plusx_planevec1[2]);
	 	}

	 	if(!planetest(plusx_planept2,plusx_planevec2,center))
	 	{	//if the center fails the plane test, flip the normal
	 		plusx_planevec2 = vec(-1*plusx_planevec2[0],-1*plusx_planevec2[1],-1*plusx_planevec2[2]);
	 	}

	 //-------------------------------------------


	 	bool minusx1 = false;
	 	bool minusx2 = false;

	 //       Y88b  /
	 //  ____  Y88b/
	 //         Y88b
	 //         /Y88b
	 //        /  Y88b

	 	//ABEF

	 	//TRIANGLES ARE ABF, AEF

	 	vec minusx_side1 = vec(a[0]-b[0],a[1]-b[1],a[2]-b[2]);
	 	vec minusx_side2 = vec(f[0]-b[0],f[1]-b[1],f[2]-b[2]);

	 	vec minusx_side3 = vec(a[0]-e[0],a[1]-e[1],a[2]-e[2]);
	 	vec minusx_side4 = vec(f[0]-e[0],f[1]-e[1],f[2]-e[2]);

	 	vec minusx_planevec1 = cross(minusx_side1,minusx_side2);
	 	vec minusx_planept1 = b;

	 	vec minusx_planevec2 = cross(minusx_side3,minusx_side4);
	 	vec minusx_planept2 = e;

	 	if(!planetest(minusx_planept1,minusx_planevec1,center))
	 	{	//if the center fails the plane test, flip the normal
	 		minusx_planevec1 = vec(-1*minusx_planevec1[0],-1*minusx_planevec1[1],-1*minusx_planevec1[2]);
	 	}

	 	if(!planetest(minusx_planept2,minusx_planevec2,center))
	 	{	//if the center fails the plane test, flip the normal
	 		minusx_planevec2 = vec(-1*minusx_planevec2[0],-1*minusx_planevec2[1],-1*minusx_planevec2[2]);
	 	}

	 //-------------------------------------------


	 	bool plusy1 = false;
	 	bool plusy2 = false;

	 //    888   Y88b  /
	 //  __888__  Y888/
	 //    888     Y8/
	 //    888      Y
	 //            /
	 //          _/

	 	//ACEG

	 	//TRIANGLES ARE ACG, AEG

	 	vec plusy_side1 = vec(a[0]-c[0],a[1]-c[1],a[2]-c[2]);
	 	vec plusy_side2 = vec(g[0]-c[0],g[1]-c[1],g[2]-c[2]);

	 	vec plusy_side3 = vec(a[0]-e[0],a[1]-e[1],a[2]-e[2]);
	 	vec plusy_side4 = vec(g[0]-e[0],g[1]-e[1],g[2]-e[2]);

	 	vec plusy_planevec1 = cross(plusy_side1,plusy_side2);
	 	vec plusy_planept1 = c;

	 	vec plusy_planevec2 = cross(plusy_side3,plusy_side4);
	 	vec plusy_planept2 = e;

	 	if(!planetest(plusy_planept1,plusy_planevec1,center))
	 	{	//if the center fails the plane test, flip the normal
	 		plusy_planevec1 = vec(-1*plusy_planevec1[0],-1*plusy_planevec1[1],-1*plusy_planevec1[2]);
	 	}

	 	if(!planetest(plusy_planept2,plusy_planevec2,center))
	 	{	//if the center fails the plane test, flip the normal
	 		plusy_planevec2 = vec(-1*plusy_planevec2[0],-1*plusy_planevec2[1],-1*plusy_planevec2[2]);
	 	}

	 //-------------------------------------------


	 	bool minusy1 = false;
	 	bool minusy2 = false;

	 //       Y88b  /
	 //  ____  Y888/
	 //         Y8/
	 //          Y
	 //         /
	 //       _/

	 	//BDFH

	 	//TRIANGLES ARE BDH, BFH
	 	vec minusy_side1 = vec(b[0]-d[0],b[1]-d[1],b[2]-d[2]);
	 	vec minusy_side2 = vec(h[0]-d[0],h[1]-d[1],h[2]-d[2]);

	 	vec minusy_side3 = vec(b[0]-f[0],b[1]-f[1],b[2]-f[2]);
	 	vec minusy_side4 = vec(h[0]-f[0],h[1]-f[1],h[2]-f[2]);

	 	vec minusy_planevec1 = cross(minusy_side1,minusy_side2);
	 	vec minusy_planept1 = d;

	 	vec minusy_planevec2 = cross(minusy_side3,minusy_side4);
	 	vec minusy_planept2 = f;

	 	if(!planetest(minusy_planept1,minusy_planevec1,center))
	 	{	//if the center fails the plane test, flip the normal
	 		minusy_planevec1 = vec(-1*minusy_planevec1[0],-1*minusy_planevec1[1],-1*minusy_planevec1[2]);
	 	}

	 	if(!planetest(minusy_planept2,minusy_planevec2,center))
	 	{	//if the center fails the plane test, flip the normal
	 		minusy_planevec2 = vec(-1*minusy_planevec2[0],-1*minusy_planevec2[1],-1*minusy_planevec2[2]);
	 	}


	 //-------------------------------------------


	 	bool plusz1 = false;
	 	bool plusz2 = false;


	 //    888    ~~~d88P
	 //  __888__    d88P
	 //    888     d88P
	 //    888    d88P
	 //          d88P___

	 	//ABCD

	 	//TRIANGLES ARE ABD, ACD

	 	vec plusz_side1 = vec(a[0]-b[0],a[1]-b[1],a[2]-b[2]);
	 	vec plusz_side2 = vec(d[0]-b[0],d[1]-b[1],d[2]-b[2]);

	 	vec plusz_side3 = vec(a[0]-c[0],a[1]-c[1],a[2]-c[2]);
	 	vec plusz_side4 = vec(d[0]-c[0],d[1]-c[1],d[2]-c[2]);

	 	vec plusz_planevec1 = cross(plusz_side1,plusz_side2);
	 	vec plusz_planept1 = b;

	 	vec plusz_planevec2 = cross(plusz_side3,plusz_side4);
	 	vec plusz_planept2 = c;

	 	if(!planetest(plusz_planept1,plusz_planevec1,center))
	 	{	//if the center fails the plane test, flip the normal
	 		plusz_planevec1 = vec(-1*plusz_planevec1[0],-1*plusz_planevec1[1],-1*plusz_planevec1[2]);
	 	}

	 	if(!planetest(plusz_planept2,plusz_planevec2,center))
	 	{	//if the center fails the plane test, flip the normal
	 		plusz_planevec2 = vec(-1*plusz_planevec2[0],-1*plusz_planevec2[1],-1*plusz_planevec2[2]);
	 	}

	 //-------------------------------------------


	 	bool minusz1 = false;
	 	bool minusz2 = false;

	 //        ~~~d88P
	 //  ____    d88P
	 //         d88P
	 //        d88P
	 //       d88P___

	 	//EFGH

	 	//TRIANGLES ARE EFH, EGH
	 	vec minusz_side1 = vec(e[0]-f[0],e[1]-f[1],e[2]-f[2]);
	 	vec minusz_side2 = vec(h[0]-f[0],h[1]-f[1],h[2]-f[2]);

	 	vec minusz_side3 = vec(e[0]-g[0],e[1]-g[1],e[2]-g[2]);
	 	vec minusz_side4 = vec(h[0]-g[0],h[1]-g[1],h[2]-g[2]);

	 	vec minusz_planevec1 = cross(minusz_side1,minusz_side2);
	 	vec minusz_planept1 = f;

	 	vec minusz_planevec2 = cross(minusz_side3,minusz_side4);
	 	vec minusz_planept2 = g;

	 	if(!planetest(minusz_planept1,minusz_planevec1,center))
	 	{	//if the center fails the plane test, flip the normal
	 		minusz_planevec1 = vec(-1*minusz_planevec1[0],-1*minusz_planevec1[1],-1*minusz_planevec1[2]);
	 	}

	 	if(!planetest(minusz_planept2,minusz_planevec2,center))
	 	{	//if the center fails the plane test, flip the normal
	 		minusz_planevec2 = vec(-1*minusz_planevec2[0],-1*minusz_planevec2[1],-1*minusz_planevec2[2]);
	 	}


	 //-------------------------------------------

	 //  ╔╦╗┌─┐┌─┐┌┬┐  ╦  ┌─┐┌─┐┌─┐
	 //   ║ ├┤ └─┐ │   ║  │ ││ │├─┘
	 //   ╩ └─┘└─┘ ┴   ╩═╝└─┘└─┘┴

	 	vec current;

	 	for(int i = 0; i < x_dim; i++)
	 	{
	 		for(int j = 0; j < y_dim; j++)
	 		{
	 			for(int k = 0; k < z_dim; k++)
	 			{

	 				current = vec(i,j,k);

	 				bool plusxtest = planetest(plusx_planept1,plusx_planevec1,current)&&planetest(plusx_planept2,plusx_planevec2,current);
	 				bool minusxtest = planetest(minusx_planept1,minusx_planevec1,current)&&planetest(minusx_planept2,minusx_planevec2,current);
	 				bool plusytest = planetest(plusy_planept1,plusy_planevec1,current)&&planetest(plusy_planept2,plusy_planevec2,current);
	 				bool minusytest = planetest(minusy_planept1,minusy_planevec1,current)&&planetest(minusy_planept2,minusy_planevec2,current);
	 				bool plusztest = planetest(plusz_planept1,plusz_planevec1,current)&&planetest(plusz_planept2,plusz_planevec2,current);
	 				bool minusztest = planetest(minusz_planept1,minusz_planevec1,current)&&planetest(minusz_planept2,minusz_planevec2,current);

	 				bool xtest = plusxtest&&minusxtest;
	 				bool ytest = plusytest&&minusytest;
	 				bool ztest = plusztest&&minusztest;


	 				if(xtest && ytest && ztest)
	 				{
	 					draw_point(current,set,draw,mask);
	 				}
	 			}
	 		}
	 	}
}

void Voraldo::draw_regular_icosahedron(double x_rot, double y_rot, double z_rot, double scale, vec center_point, Vox vertex_material, double verticies_radius, Vox edge_material, double edge_thickness, Vox face_material,bool draw_faces, bool draw, bool mask)
{
  double phi = (1 + std::sqrt(5.0))/2.0;

  float face_thickness = 1.5f;

//rotation matricies allowing rotation of the polyhedron
 	mat rotation_x_axis;
 //refernces [column][row] - sin and cos take arguments in radians
 		rotation_x_axis[0][0] = 1;                       rotation_x_axis[1][0] = 0;                      rotation_x_axis[2][0] = 0;
 		rotation_x_axis[0][1] = 0;                       rotation_x_axis[1][1] = std::cos(x_rot);        rotation_x_axis[2][1] = -1.0*std::sin(x_rot);
 		rotation_x_axis[0][2] = 0;                       rotation_x_axis[1][2] = std::sin(x_rot);        rotation_x_axis[2][2] = std::cos(x_rot);

 	mat rotation_y_axis;
 		rotation_y_axis[0][0] = std::cos(y_rot);         rotation_y_axis[1][0] = 0;                      rotation_y_axis[2][0] = std::sin(y_rot);
 		rotation_y_axis[0][1] = 0;                       rotation_y_axis[1][1] = 1;                      rotation_y_axis[2][1] = 0;
 		rotation_y_axis[0][2] = -1.0*std::sin(y_rot);    rotation_y_axis[1][2] = 0;                      rotation_y_axis[2][2] = std::cos(y_rot);

 	mat rotation_z_axis;
 		rotation_z_axis[0][0] = std::cos(z_rot);         rotation_z_axis[1][0] = -1.0*std::sin(z_rot);   rotation_z_axis[2][0] = 0;
 		rotation_z_axis[0][1] = std::sin(z_rot);         rotation_z_axis[1][1] = std::cos(z_rot);        rotation_z_axis[2][1] = 0;
 		rotation_z_axis[0][2] = 0;                       rotation_z_axis[1][2] = 0;                      rotation_z_axis[2][2] = 1;

  mat rotation = rotation_x_axis * rotation_y_axis * rotation_z_axis; //multiply these all together

  vec a,b,c,d,e,f,g,h,i,j,k,l;
//the work for this is in my journal, the entry on 3/1/2019
//it is based on the idea that the points of a regular icosahedron lie on the points defined by three mutually orthogonal golden rectangles that share a center point at the origin
//i.e. these rectanges are abcd,efgh and ijkl
  a = rotation * vec(  0,  1*scale,  phi*scale) + center_point; e = rotation * vec(  1*scale,  phi*scale,  0) + center_point; i = rotation * vec(  phi*scale,  0,  1*scale) + center_point;
  b = rotation * vec(  0,  1*scale, -phi*scale) + center_point; f = rotation * vec( -1*scale, -phi*scale,  0) + center_point; j = rotation * vec(  phi*scale,  0, -1*scale) + center_point;
  c = rotation * vec(  0, -1*scale,  phi*scale) + center_point; g = rotation * vec( -1*scale,  phi*scale,  0) + center_point; k = rotation * vec( -phi*scale,  0,  1*scale) + center_point;
  d = rotation * vec(  0, -1*scale, -phi*scale) + center_point; h = rotation * vec(  1*scale, -phi*scale,  0) + center_point; l = rotation * vec( -phi*scale,  0, -1*scale) + center_point;
//nonzero components of the coordinates are scaled by the scale input argument. The result of that operation is multiplied by the composed rotation matrix, then added to the shape's center point


  if(draw_faces)
  {//draw the faces -
    draw_triangle( a, g, e, face_thickness, face_material, draw, mask); //AGE
    draw_triangle( a, i, e, face_thickness, face_material, draw, mask); //AIE
    draw_triangle( a, c, i, face_thickness, face_material, draw, mask); //ACI
    draw_triangle( a, c, k, face_thickness, face_material, draw, mask); //ACK
    draw_triangle( a, g, k, face_thickness, face_material, draw, mask); //AGK
    draw_triangle( l, b, g, face_thickness, face_material, draw, mask); //LBG
    draw_triangle( l, g, k, face_thickness, face_material, draw, mask); //LGK
    draw_triangle( l, f, k, face_thickness, face_material, draw, mask); //LFK
    draw_triangle( l, d, f, face_thickness, face_material, draw, mask); //LDF
    draw_triangle( l, d, b, face_thickness, face_material, draw, mask); //LDB
    draw_triangle( k, f, c, face_thickness, face_material, draw, mask); //KFC
    draw_triangle( f, h, c, face_thickness, face_material, draw, mask); //FHC
    draw_triangle( h, i, c, face_thickness, face_material, draw, mask); //HIC
    draw_triangle( e, j, i, face_thickness, face_material, draw, mask); //EJI
    draw_triangle( b, g, e, face_thickness, face_material, draw, mask); //BGE
    draw_triangle( f, h, d, face_thickness, face_material, draw, mask); //FHD
    draw_triangle( d, h, j, face_thickness, face_material, draw, mask); //DHJ
    draw_triangle( d, b, j, face_thickness, face_material, draw, mask); //DBJ
    draw_triangle( b, j, e, face_thickness, face_material, draw, mask); //BJE
    draw_triangle( h, i, j, face_thickness, face_material, draw, mask); //HIJ
  }




  if(edge_thickness)
  {//nonzero value passed for edge thickness
    //draw the edges
   //use cylinders of radius edge_thickness - more general than line segments
      draw_cylinder(a,c, edge_thickness, edge_material, draw, mask); //AC
      draw_cylinder(a,e, edge_thickness, edge_material, draw, mask); //AE
      draw_cylinder(a,g, edge_thickness, edge_material, draw, mask); //AG
      draw_cylinder(a,i, edge_thickness, edge_material, draw, mask); //AI
      draw_cylinder(a,k, edge_thickness, edge_material, draw, mask); //AK

      draw_cylinder(b,d, edge_thickness, edge_material, draw, mask); //BD
      draw_cylinder(b,e, edge_thickness, edge_material, draw, mask); //BE
      draw_cylinder(b,g, edge_thickness, edge_material, draw, mask); //BG
      draw_cylinder(b,j, edge_thickness, edge_material, draw, mask); //BJ
      draw_cylinder(b,l, edge_thickness, edge_material, draw, mask); //BL

      draw_cylinder(c,f, edge_thickness, edge_material, draw, mask); //CF
      draw_cylinder(c,h, edge_thickness, edge_material, draw, mask); //CH
      draw_cylinder(c,i, edge_thickness, edge_material, draw, mask); //CI
      draw_cylinder(c,k, edge_thickness, edge_material, draw, mask); //CK

      draw_cylinder(d,f, edge_thickness, edge_material, draw, mask); //DF
      draw_cylinder(d,h, edge_thickness, edge_material, draw, mask); //DH
      draw_cylinder(d,j, edge_thickness, edge_material, draw, mask); //DJ
      draw_cylinder(d,l, edge_thickness, edge_material, draw, mask); //DL

      draw_cylinder(e,g, edge_thickness, edge_material, draw, mask); //EG
      draw_cylinder(e,i, edge_thickness, edge_material, draw, mask); //EI
      draw_cylinder(e,j, edge_thickness, edge_material, draw, mask); //EJ

      draw_cylinder(f,h, edge_thickness, edge_material, draw, mask); //FH
      draw_cylinder(f,k, edge_thickness, edge_material, draw, mask); //FK
      draw_cylinder(f,l, edge_thickness, edge_material, draw, mask); //FL

      draw_cylinder(g,k, edge_thickness, edge_material, draw, mask); //GK
      draw_cylinder(g,l, edge_thickness, edge_material, draw, mask); //GL

      draw_cylinder(h,i, edge_thickness, edge_material, draw, mask); //HI
      draw_cylinder(h,j, edge_thickness, edge_material, draw, mask); //HJ

      draw_cylinder(i,j, edge_thickness, edge_material, draw, mask); //IJ

      draw_cylinder(k,l, edge_thickness, edge_material, draw, mask); //KL

  }

  if(verticies_radius)
  {//nonzero value passed for vertex radius
    //draw the vertexes
    draw_sphere(a, verticies_radius, vertex_material, draw, mask);
    draw_sphere(b, verticies_radius, vertex_material, draw, mask);
    draw_sphere(c, verticies_radius, vertex_material, draw, mask);
    draw_sphere(d, verticies_radius, vertex_material, draw, mask);

    draw_sphere(e, verticies_radius, vertex_material, draw, mask);
    draw_sphere(f, verticies_radius, vertex_material, draw, mask);
    draw_sphere(g, verticies_radius, vertex_material, draw, mask);
    draw_sphere(h, verticies_radius, vertex_material, draw, mask);

    draw_sphere(i, verticies_radius, vertex_material, draw, mask);
    draw_sphere(j, verticies_radius, vertex_material, draw, mask);
    draw_sphere(k, verticies_radius, vertex_material, draw, mask);
    draw_sphere(l, verticies_radius, vertex_material, draw, mask);
  }
}

void Voraldo::draw_heightmap(/*std::string filename, std::vector<Vox> materials,*/ bool draw, bool mask)
{
  using namespace cimg_library;
  unsigned char current_color;
  unsigned char current_height;
  unsigned char current_colormap;

  CImg<unsigned char> heightmap("heights.png");
  CImg<unsigned char> colormap("greycolors.png");

  for(int x = 0; x < 512; x++)
  {
    for(int z = 0; z < 512; z++)
    {// per pixel in heightmap image

      current_height = heightmap.atXY(x,z);
      current_colormap = colormap.atXY(x,z);

      if(current_colormap < 30){
        current_color = 62; //black
      }else if(current_colormap < 60){
        current_color = 61; // t dark grey
      }else if(current_colormap < 90){
        current_color = 60; // t dark med
      }else if(current_colormap < 120){
        current_color = 59; // t med light
      }else if(current_colormap < 150){
        current_color = 58; // t light
      }else{
        current_color = 57; // t lighter
      }

      draw_point(vec(x,current_height/3,z),get_vox(current_color,255,false),draw,mask);


      //for(int y = 0; y < current_height/3; y++){
        //draw_point(vec(x,y,z),get_vox(current_color,1,0.3,false),draw,mask);
      //}
      //cout << heightmap.atXY(x,z) << " ";
    }
    //cout << endl;
  }


    //go up to y

  return;
}



void Voraldo::draw_minecraft_style_terrain( vec offset, vec scale, bool draw, bool mask)
{
	PerlinNoise p;

	// float grass_threshold = 0.35f;
	float land_threshold  = 0.35f;
	float rock_threshold  = 0.60f;

	Vox grass_material, land_material, rock_material;

	grass_material = get_vox( 25, 255, false);
	land_material  = get_vox( 21, 255, false);
	rock_material  = get_vox( 59, 255, false);

	float y_scale_factor;

	float noise_sample = 0.0f;

	for( int y = 0; y < y_dim; y++ ) // y comes first because I don't want to have to recalculate this y_scale_factor inside three nested loops
	{// compute y_scale_factor once per slice on the y axis

		cout << (y_scale_factor = 2.0f - ( y / 75.0f )) << endl;

		for( int z = 0; z < z_dim; z++ )
		{
			for( int x = 0; x < x_dim; x++ )
			{//per voxel

				// noise_sample = y_scale_factor * p.noise( scale.x * x + offset.x, scale.y * y + offset.y, scale.z * z + offset.z ); // single octave

				// noise_sample = y_scale_factor * (p.noise( scale.x * x + offset.x, scale.y * y + offset.y, scale.z * z + offset.z ) +
																					// p.noise( scale.x * (x*2.0f) + offset.x, scale.y * (y*2.0f) + offset.y, scale.z * (z*2.0f) + offset.z )); // two octaves

				// noise_sample = y_scale_factor * (p.noise( scale.x * x + offset.x, scale.y * y + offset.y, scale.z * z + offset.z ) +
				// 																	0.5 * p.noise( scale.x * (x*2.0f) + offset.x, scale.y * (y*2.0f) + offset.y, scale.z * (z*2.0f) + offset.z ) +
				// 																		0.25 * p.noise( scale.x * (x*4.0f) + offset.x, scale.y * (y*4.0f) + offset.y, scale.z * (z*4.0f) + offset.z )); // three octaves

				noise_sample = y_scale_factor * (0.5 * p.noise( scale.x * x + offset.x, scale.y * y + offset.y, scale.z * z + offset.z ) +
																					 p.noise( scale.x * (x*2.0f) + offset.x, scale.y * (y*2.0f) + offset.y, scale.z * (z*2.0f) + offset.z ) -
																						2.0 * p.noise( scale.x * (x*4.0f) + offset.x, scale.y * (y*4.0f) + offset.y, scale.z * (z*4.0f) + offset.z ) +
																							4.0 * p.noise( scale.x * (x*8.0f) + offset.x, scale.y * (y*8.0f) + offset.y, scale.z * (z*8.0f) + offset.z )	); // four octaves

				if( noise_sample > rock_threshold )
				{
					draw_point( vec( x, y, z ), rock_material, draw, mask );
				}
				else if( noise_sample > land_threshold )
				{
					draw_point( vec( x, y, z ), land_material, draw, mask );
				}
				// else if( noise_sample > grass_threshold )
				// {
				// 	draw_point( vec( x, y, z ), grass_material, draw, mask );
				// }
			}
		}
	}

	// grass pass

	vec current_location;

	for(int x = 0; x < 512; x++)
	{
		for(int z = 0; z < 256; z++)
		{
			for(int y = 256; y > 0; y--)
			{
				current_location = vec(x,y,z);
				if(compare_colors(get_data_by_vector_index(current_location).color, land_material.color))
				{//surface layer
					set_data_by_vector_index(current_location, grass_material);
					break;
				}
			}
		}
	}


	// flowers

	for(int x = 0; x < 512; x++)
	{
		for(int z = 0; z < 256; z++)
		{
			for(int y = 256; y > 0; y--)
			{
				current_location = vec(x,y,z);
				if(compare_colors(get_data_by_vector_index(current_location).color, grass_material.color))
				{//surface layer
					if(std::rand()%500 == 69)
					{
						set_data_by_vector_index(current_location+vec(0,2,0), get_vox(43,255,false));
					}
					else if(std::rand()%100 == 69)
					{
						set_data_by_vector_index(current_location+vec(0,2,0), get_vox(41,255,false));
					}
					else if(std::rand()%100 == 23)
					{
						set_data_by_vector_index(current_location+vec(0,2,0), get_vox(11,255,false));
					}
					else if(std::rand()%100 == 10)
					{
						set_data_by_vector_index(current_location+vec(0,2,0), get_vox(1,255,false));
					}
					else if(std::rand()%100 == 10)
					{
						set_data_by_vector_index(current_location+vec(0,2,0), get_vox(7,255,false));
					}
					break;
				}
			}
		}
	}

	// add some features to the stone layer

	mask_by_state(59);
	mask_invert_mask();

	draw_perlin_noise(0.2, 0.3, get_vox(56, 255, false));

	mask_unmask_all();
}


void Voraldo::blur( int radius, bool change_alpha)
{
	vec index;
  Vox temp_vox;
  int sum;
  int tot;

	RGBA temp_color;

	double ratio;


	//vector to hold temporary colors (avoid the corruption I was seeing)



	// for(int x = 0; x < x_dim; x++)
	// {
	// 	for(int y = 0; y < y_dim; y++)
	// 	{
	// 		for(int z = 0; z < z_dim; z++)
	// 		{
	// 			sum = 0;
	// 			tot = 0;
	// 			index = vec(x,y,z);
	//
	//
	// 			for (int inner_x = -1 * radius; inner_x <= 1 * radius; inner_x++)
	// 			{
	// 				for (int inner_y = -1 * radius; inner_y <= 1 * radius; inner_y++)
	// 				{
	// 					for (int inner_z = -1 * radius; inner_z <= 1 * radius; inner_z++)
	// 					{
	// 						temp_vox = get_data_by_vector_index(index + vec(inner_x, inner_y, inner_z));
	// 						sum += temp_vox.color.alpha;
	// 						tot += 255;
	// 					}
	// 				}
	// 			}
	//
	//
	//
	// 			// temp_vox = get_data_by_vector_index(index);
	// 			//
	// 			// if(temp_vox.color.alpha > 1)
	// 			// {
	// 			// 	ratio = 1.0 - 0.5 * ((double)sum) / ((double)tot);
	// 			//
	// 			// 	temp_color.red = temp_vox.color.red * ratio;
	// 			// 	temp_color.green = temp_vox.color.green * ratio;
	// 			// 	temp_color.blue = temp_vox.color.blue * ratio;
	// 			// 	temp_color.alpha = temp_vox.color.alpha; // there was severe artifacting when the alpha was being
	// 			// 	// manipulated at the same time as the sweep through the data (corrupted neighborhoods)
	// 			//
	// 			// 	set_data_by_vector_index(index, get_vox(temp_color, false));
	// 			// 	ratio = 1.0 - 0.1 * ((double)sum) / ((double)tot);
	// 			//
	// 			// 	temp_color.red = temp_vox.color.red * ratio;
	// 			// 	temp_color.green = temp_vox.color.green * ratio;
	// 			// 	temp_color.blue = temp_vox.color.blue * ratio;
	// 			// 	temp_color.alpha = temp_vox.color.alpha; // there was severe artifacting when the alpha was being
	// 			// 	// manipulated at the same time as the sweep through the data (corrupted neighborhoods)
	// 			//
	// 			//
	// 			// 	set_data_by_vector_index(index, get_vox(temp_color, false));
	// 			// }
	//
	// 			// if( ratio < 0.1 )
	// 			// {
	// 			// 	set_data_by_vector_index(index, get_vox(1, 1, false));
	// 			// }
	// 			// else if( ratio < 0.15 )
	// 			// {
	// 			// 	set_data_by_vector_index(index, get_vox(33, 1, false));
	// 			// }
	// 			// else if( ratio < 0.21 )
	// 			// {
	// 			// 	set_data_by_vector_index(index, get_vox(33, 255, false));
	// 			// }
	// 			// else if( ratio < 0.25 )
	// 			// {
	// 			// 	set_data_by_vector_index(index, get_vox(7, 20, false));
	// 			// }
	// 			// else if( ratio < 0.3 )
	// 			// {
	// 			// 	set_data_by_vector_index(index, get_vox(23, 2, false));
	// 			// }
	// 			// else if( ratio < 0.5 )
	// 			// {
	// 			// 	set_data_by_vector_index(index, get_vox(33, 25, false));
	// 			// }
	// 			// else
	// 			// {
	// 			// 	set_data_by_vector_index(index, get_vox(63, 255, false));
	// 			// }
	// 		}
	// 	}
	// }
}




//  ___________________ ____ ___
//  \_   ___ \______   \    |   \
//  /    \  \/|     ___/    |   /
//  \     \___|    |   |    |  /
//   \______  /____|   |______/
//          \/
//  _____________________ _______  ________  __________________________________________
//  \______   \_   _____/ \      \ \______ \ \_   _____/\______   \_   _____/\______   \
//   |       _/|    __)_  /   |   \ |    |  \ |    __)_  |       _/|    __)_  |       _/
//   |    |   \|        \/    |    \|    `   \|        \ |    |   \|        \ |    |   \
//   |____|_  /_______  /\____|__  /_______  /_______  / |____|_  /_______  / |____|_  /
//          \/        \/         \/        \/        \/         \/        \/         \/


void Voraldo::display(std::string filename, float x_rot, float y_rot, float z_rot, float scale, bool perspective)
{
  using namespace cimg_library;

 	int image_x_dimension = 1919;
 	int image_y_dimension = 1079;

 	CImg<float> img(image_x_dimension,image_y_dimension,1,3,0);

 	const unsigned char	gold[3] = {255,215,0};
 	const unsigned char dark_gold[3] = {127,107,0};
 	const unsigned char white[3] = {255,255,255};
 	const unsigned char black[3] = {0,0,0};
 	const unsigned char pink[3] = {255,0,255};

//draw the border for the image
 	//frame top
 	img.draw_line(0,1,image_x_dimension,1,gold);
 	img.draw_line(0,2,image_x_dimension,2,dark_gold);

 	//frame bottom
 	img.draw_line(0,image_y_dimension-2,image_x_dimension,image_y_dimension-2,dark_gold);
 	img.draw_line(0,image_y_dimension-1,image_x_dimension,image_y_dimension-1,gold);

 	//frame left from low x low y to low x high y
 	img.draw_line(1,0,1,image_y_dimension,gold);
 	img.draw_line(2,0,2,image_y_dimension,dark_gold);

 	//frame right from high x low y to high x high y
 	img.draw_line(image_x_dimension-2,0,image_x_dimension-2,image_y_dimension,dark_gold);
 	img.draw_line(image_x_dimension-2,0,image_x_dimension-2,image_y_dimension,gold);


 	int block_xdim = x_dim;                 int block_ydim = y_dim;                 int block_zdim = z_dim;
 	int block_xdim_squared = block_xdim*block_xdim; int block_ydim_squared = block_ydim*block_ydim;	int block_zdim_squared = block_zdim*block_zdim;

 	vec d_center = vec(block_xdim/2.0,block_ydim/2.0,block_zdim/2.0);

//rotation matricies allowing rotation of the viewer's position
 	mat rotation_x_axis;
 //refernces [column][row] - sin and cos take arguments in radians
 		rotation_x_axis[0][0] = 1;                       rotation_x_axis[1][0] = 0;                      rotation_x_axis[2][0] = 0;
 		rotation_x_axis[0][1] = 0;                       rotation_x_axis[1][1] = std::cos(x_rot);        rotation_x_axis[2][1] = -1.0*std::sin(x_rot);
 		rotation_x_axis[0][2] = 0;                       rotation_x_axis[1][2] = std::sin(x_rot);        rotation_x_axis[2][2] = std::cos(x_rot);

 	mat rotation_y_axis;
 		rotation_y_axis[0][0] = std::cos(y_rot);         rotation_y_axis[1][0] = 0;                      rotation_y_axis[2][0] = std::sin(y_rot);
 		rotation_y_axis[0][1] = 0;                       rotation_y_axis[1][1] = 1;                      rotation_y_axis[2][1] = 0;
 		rotation_y_axis[0][2] = -1.0*std::sin(y_rot);    rotation_y_axis[1][2] = 0;                      rotation_y_axis[2][2] = std::cos(y_rot);

 	mat rotation_z_axis;
 		rotation_z_axis[0][0] = std::cos(z_rot);         rotation_z_axis[1][0] = -1.0*std::sin(z_rot);   rotation_z_axis[2][0] = 0;
 		rotation_z_axis[0][1] = std::sin(z_rot);         rotation_z_axis[1][1] = std::cos(z_rot);        rotation_z_axis[2][1] = 0;
 		rotation_z_axis[0][2] = 0;                       rotation_z_axis[1][2] = 0;                      rotation_z_axis[2][2] = 1;

//the three vectors defining the x,y,z of "display space" i.e. screen space, used for positioning camera in world space
 	vec d_xvec = rotation_x_axis * rotation_y_axis * rotation_z_axis * vec(1,0,0);
 	vec d_yvec = rotation_x_axis * rotation_y_axis * rotation_z_axis * vec(0,1,0);
 	vec d_zvec = rotation_x_axis * rotation_y_axis * rotation_z_axis * vec(0,0,1);

//this is somewhat abstract - starting from the center of the block, define a sphere
//this sphere has a radius such that the corners of the box are on the surface of the sphere
//multiplying this radius by some amount >1 will move us out from there, a sphere with the same center
//the camera is then located somewhere on this sphere, in a position determined by the use of the rotation matricies

 	//tip radius is the radius of the sphere that touches the tips of the block's corners
 	float tip_radius = std::sqrt(block_xdim_squared+block_ydim_squared+block_zdim_squared)/2.0;
 	float max_dist = 2*2.2*tip_radius;
 	float min_dist = 0.2*tip_radius;
 	//factor of two is for the incremental step of length 0.5
 	//factor of 2.2 is for the tip radius plus the camera sphere radius, 1+1.2

 	vec cam_position = d_center - 1.2f*tip_radius * d_yvec; vec cam_up = scale*d_zvec; vec cam_right = scale*d_xvec;

 	int image_center_x = (image_x_dimension-1)/2; int image_current_x;
 	int image_center_y = (image_y_dimension-1)/2; int image_current_y;

 	vec vector_starting_point,vector_test_point;
 	vec vector_increment = 0.5f*normalize(-1.0f*(cam_position-d_center));

 	vec block_min = vec(0,0,0);
 	vec block_max = vec(block_xdim,block_ydim,block_zdim);

 	Vox temp;
 	RGBA	curr_color;
  float temp_alpha, curr_alpha;

  std::stack<Vox> empty_voxtack;
  std::stack<Vox> voxtack;

  unsigned char image_color[3];

 	bool line_box_intersection, color_set;

 	float t0 = 0;
 	float t1 = 9999;

  float tmin, tmax;
  float alpha_sum;


 	for(float x = -(image_x_dimension/2-5); x <= (image_x_dimension/2-5); x++)
 		for(float y = -(image_y_dimension/2-5); y <= (image_y_dimension/2-5); y++)
 		{//init (reset)
 			line_box_intersection = false; color_set = false;    //reset flag values for the new pixel
      curr_alpha = 1.0; curr_color.red = 0; curr_color.green = 0; curr_color.blue = 0;

      voxtack = empty_voxtack;                             //reset the stack by setting it equal to an empty stack

 			image_current_x = image_center_x + x; image_current_y = image_center_y + y; //x and y values for the new pixel

 			if(perspective == true) //this gets added inside the loop - note that the linetest will have to consider the perspective corrected ray
      {//this isn't working very well
        vector_increment = 0.5f*normalize(-1.0f*(cam_position-d_center));
 				vector_increment = vector_increment + x*0.001f*cam_right - y*0.001f*cam_up;
      }
      //orthogonal display will have vector_increment equal for all pixels i.e. no divergence

 			vector_starting_point = cam_position + x*cam_up + y*cam_right;

 			//figure out if the parametric line established by parameter z and
 			//	L = vector_starting_point + z*vector_increment
 			//intersects with the box established by (0,0,0) (x,y,z)
 			//i.e. block_min and block_max

 			//The goal here is to know whether or not there is data to sample behind any given pixel - this offers a significant speedup
 			line_box_intersection = intersect_ray_bbox(block_min,block_max,vector_starting_point,vector_increment,tmin,tmax,t0,t1);

 			if(line_box_intersection)
 			{//the ray hits the box, we will need to step through the box
        alpha_sum = 0;
 				for(float z = tmin; z <= tmax; z+=0.5) //go from close intersection point (tmin) to far intersection point (tmax)
 				{
 					vector_test_point = floor(vector_starting_point + z*vector_increment);  //get the test point
 					temp = get_data_by_vector_index(vector_test_point);                     //get the data at the test point
          alpha_sum += temp.color.alpha;
          if(!compare_colors(temp.color, palette[0]))
          {
            voxtack.push(temp);
          }
          if(alpha_sum > 4.0) break;
 				}//end for (z)
        //the for loop is completed, now process the stack

        img.draw_point(image_current_x,image_current_y,black);
        while(!voxtack.empty())
        {
          temp = voxtack.top(); voxtack.pop();

          // image_color[0] = temp.color.red   * (temp.lighting_intensity);
          // image_color[1] = temp.color.green * (temp.lighting_intensity);
          // image_color[2] = temp.color.blue  * (temp.lighting_intensity);

          image_color[0] = temp.color.red;
          image_color[1] = temp.color.green;
          image_color[2] = temp.color.blue;

          if( temp.color.alpha != 0 )
          {
            if(temp.color.alpha == 255){
              img.draw_point(image_current_x,image_current_y,image_color);
            }else{
              img.draw_point(image_current_x,image_current_y,image_color,0.01*(temp.color.alpha));
            }
          }
        }
 			}
 			else //I saw a ray that did not hit the box, I want to paint it black
 			{
        img.draw_point(image_current_x,image_current_y,black);
 			}
 		}//end for (x and y)

 	img.save_png(filename.c_str());
}











//  .____    .___  ________  ___ ______________.___ _______    ________
//  |    |   |   |/  _____/ /   |   \__    ___/|   |\      \  /  _____/
//  |    |   |   /   \  ___/    ~    \|    |   |   |/   |   \/   \  ___
//  |    |___|   \    \_\  \    Y    /|    |   |   /    |    \    \_\  \
//  |_______ \___|\______  /\___|_  / |____|   |___\____|__  /\______  /
//          \/           \/       \/                       \/        \/


void Voraldo::lighting_ambient_occlusion()
{
  vec index;
  Vox temp_vox;
  int sum;
  int tot;

	RGBA temp_color;

	double ratio;

	for(int x = 0; x < x_dim; x++)
	{
		for(int y = 0; y < y_dim; y++)
		{
			for(int z = 0; z < z_dim; z++)
			{
				sum = 0;
				tot = 0;
				index = vec(x,y,z);


				for (int inner_x = -1; inner_x <= 1; inner_x++)
				{
					for (int inner_y = -1; inner_y <= 1; inner_y++)
					{
						for (int inner_z = -1; inner_z <= 1; inner_z++)
						{
							temp_vox = get_data_by_vector_index(index + vec(inner_x, inner_y, inner_z));
							sum += temp_vox.color.alpha;
							tot += 255;
						}
					}
				}

				// 1.0 - full neighborhood

				// 0.75 -

				// 0.5 -

				// 0.25 -

				// 0.1 -

				// <0.01 - no adjustment255

				temp_vox = get_data_by_vector_index(index);

				if(temp_vox.color.alpha > 1)
				{
					ratio = 1.0 - 0.5 * ((double)sum) / ((double)tot);

					temp_color.red = temp_vox.color.red * ratio;
					temp_color.green = temp_vox.color.green * ratio;
					temp_color.blue = temp_vox.color.blue * ratio;
					temp_color.alpha = temp_vox.color.alpha; // there was severe artifacting when the alpha was being
					// manipulated at the same time as the sweep through the data (corrupted neighborhoods)


					set_data_by_vector_index(index, get_vox(temp_color, false));
					ratio = 1.0 - 0.1 * ((double)sum) / ((double)tot);

					temp_color.red = temp_vox.color.red * ratio;
					temp_color.green = temp_vox.color.green * ratio;
					temp_color.blue = temp_vox.color.blue * ratio;
					temp_color.alpha = temp_vox.color.alpha; // there was severe artifacting when the alpha was being
					// manipulated at the same time as the sweep through the data (corrupted neighborhoods)


					set_data_by_vector_index(index, get_vox(temp_color, false));

				}

				// if( ratio < 0.1 )
				// {
				// 	set_data_by_vector_index(index, get_vox(1, 1, false));
				// }
				// else if( ratio < 0.15 )
				// {
				// 	set_data_by_vector_index(index, get_vox(33, 1, false));
				// }
				// else if( ratio < 0.21 )
				// {
				// 	set_data_by_vector_index(index, get_vox(33, 255, false));
				// }
				// else if( ratio < 0.25 )
				// {
				// 	set_data_by_vector_index(index, get_vox(7, 20, false));
				// }
				// else if( ratio < 0.3 )
				// {
				// 	set_data_by_vector_index(index, get_vox(23, 2, false));
				// }
				// else if( ratio < 0.5 )
				// {
				// 	set_data_by_vector_index(index, get_vox(33, 25, false));
				// }
				// else
				// {
				// 	set_data_by_vector_index(index, get_vox(63, 255, false));
				// }
			}
		}
	}
}








//   ____ ______________.___.____    .______________.______________ _________
//  |    |   \__    ___/|   |    |   |   \__    ___/|   \_   _____//   _____/
//  |    |   / |    |   |   |    |   |   | |    |   |   ||    __)_ \_____  \
//  |    |  /  |    |   |   |    |___|   | |    |   |   ||        \/        \
//  |______/   |____|   |___|_______ \___| |____|   |___/_______  /_______  /
//                                  \/                          \/        \/



Vox Voraldo::get_data_by_vector_index(vec index)
{
  int x,y,z;

  x = (int) index[0];
  y = (int) index[1];
  z = (int) index[2];


  bool x_valid = ( x < x_dim && x >= 0 );
  bool y_valid = ( y < y_dim && y >= 0 );
  bool z_valid = ( z < z_dim && z >= 0 );

  bool point_valid = x_valid && y_valid && z_valid;


  //std::cout << "the index is " << index[0] << " " << index[1] << " " << index[2] << endl;

  //std::cout << "index validated: " << data_index << " versus max array size of " << num_cells << endl;


  if(point_valid)
   return data[x][y][z];
  else
  {
    Vox default_val;
    default_val.color = {  0,  0,  0,  0};
    default_val.mask = false;
    return default_val;
  }
}

void Voraldo::set_data_by_vector_index(vec index, Vox set, bool draw, bool mask, bool force)
{
 // int data_index = index[2]*y_dim*x_dim + index[1]*x_dim + index[0];

 int x,y,z;

 x = (int) index[0];
 y = (int) index[1];
 z = (int) index[2];


 bool x_valid = ( x < x_dim && x >= 0 );
 bool y_valid = ( y < y_dim && y >= 0 );
 bool z_valid = ( z < z_dim && z >= 0 );

 bool point_valid = x_valid && y_valid && z_valid;

 if(point_valid)
 {
  if(!data[x][y][z].mask)
  {
   if(draw)
   {
    data[x][y][z] = set;
   }
    data[x][y][z].mask = mask; //this takes precedence over the Vox value of mask
  }

  if(force)
  {
    data[x][y][z] = set;
  }
 }
}


bool Voraldo::planetest(vec plane_point, vec plane_normal, vec test_point)
{
  //return false if the point is above the plane
	//return true if the point is below the plane

	double result = 0.0;

	//equation of plane

	// a (x-x1) + b (y-y1) + c (z-z1) = 0

	double a = plane_normal[0];
	double b = plane_normal[1];
	double c = plane_normal[2];

	double x1 = plane_point[0];
	double y1 = plane_point[1];
	double z1 = plane_point[2];

	double x = test_point[0];
	double y = test_point[1];
	double z = test_point[2];

	result = a * (x - x1) + b * (y - y1) + c * (z - z1);

	return (result < 0)?true:false;
}

bool Voraldo::intersect_ray_bbox(vec bbox_min, vec bbox_max, vec ray_org, vec ray_dir, float &tmin, float &tmax, float t0, float t1)
{/*
 * Ray-box intersection using IEEE numerical properties to ensure that the
 * test is both robust and efficient, as described in:
 *
 *      Amy Williams, Steve Barrus, R. Keith Morley, and Peter Shirley
 *      "An Efficient and Robust Ray-Box Intersection Algorithm"
 *      Journal of graphics tools, 10(1):49-54, 2005
 *
 */

//I pulled this code after three attempts at my own implementation didn't work
  vec bbox[2];
	int sign[3];

	vec inv_direction = vec(1/ray_dir[0],1/ray_dir[1],1/ray_dir[2]);

	sign[0] = (inv_direction[0] < 0);
	sign[1] = (inv_direction[1] < 0);
	sign[2] = (inv_direction[2] < 0);

	bbox[0] = bbox_min;
	bbox[1] = bbox_max;


	//already declared (passed in by reference so that they can be used)
  tmin = (bbox[sign[0]][0] - ray_org[0]) * inv_direction[0];
  tmax = (bbox[1-sign[0]][0] - ray_org[0]) * inv_direction[0];

  float tymin = (bbox[sign[1]][1] - ray_org[1]) * inv_direction[1];
  float tymax = (bbox[1-sign[1]][1] - ray_org[1]) * inv_direction[1];

  if ( (tmin > tymax) || (tymin > tmax) )
    return false;
  if (tymin > tmin)
    tmin = tymin;
  if (tymax < tmax)
    tmax = tymax;

  float tzmin = (bbox[sign[2]][2] - ray_org[2]) * inv_direction[2];
  float tzmax = (bbox[1-sign[2]][2] - ray_org[2]) * inv_direction[2];

  if ( (tmin > tzmax) || (tzmin > tmax) )
    return false;
  if (tzmin > tmin)
    tmin = tzmin;
  if (tzmax < tmax)
    tmax = tzmax;
  return ( (tmin < t1) && (tmax > t0) );

}




bool Voraldo::compare_colors(RGBA first, RGBA second)
{

  auto red1 = first.red;
  auto red2 = second.red;

  auto green1 = first.green;
  auto green2 = second.green;

  auto blue1 = first.blue;
  auto blue2 = second.blue;

  // auto alpha1 = first.alpha;
  // auto alpha2 = second.alpha;


  return ( ( red1 == red2 ) && ( green1 == green2 ) && ( blue1 == blue2 ) ); // && ( alpha1 == alpha2 ) );
}




Vox Voraldo::get_vox( int palette_number, float alpha, bool mask )
{
  Vox temp;

	temp.color = palette[palette_number];

	if(alpha > 255)
	{
		temp.color.alpha = 255;
		temp.color.alpha_low = 255;
	}
	else if( alpha - std::floor(alpha) != 0 )
	{ // use decimal to represent the low bits, map 0 to 1 to the range 0 to 255

		temp.color.alpha = (unsigned char) std::floor(alpha);
		temp.color.alpha_low = (unsigned char) ((alpha - std::floor(alpha)) * 255);

	}
	else
	{	// no decimal, just cast as unsigned char

		temp.color.alpha = (unsigned char) alpha;
		temp.color.alpha_low = 0;
	}

  temp.mask = mask;

  return temp;

}

// this one's pretty much only for the load function
Vox Voraldo::get_vox( RGBA color, bool mask )
{
  Vox temp;

  temp.color = color;
  temp.mask = mask;

  return temp;

}


float Voraldo::clamp(float value, float low, float high)
{
  if(value > high)
  {
    return high;
  }
  else if(value < low)
  {
    return low;
  }
  else
  {
    return value;
  }
}
