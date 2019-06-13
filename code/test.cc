#include "../resources/voraldo/v7.h"


Voraldo *main_block;


int main(){

  std::vector<unsigned char> vessel_image;
  std::vector<unsigned char> water_image;

  unsigned width, height;

  int index = 0;

  int init_x = 512;
  int init_y = 256;
  int init_z = 256;

  vec dimensions(init_x,init_y,init_z);



  Voraldo *main_block;
  main_block = new Voraldo();
  main_block->init_block(dimensions);


  std::string vessel_filename = "../resources/models/vessels.png";
  std::string water_filename = "../resources/models/water.png";






  //get that image - it is 160 pixels wide, and 160*160= 25600 pixels tall

  //decode
  unsigned error = lodepng::decode( vessel_image, width, height, vessel_filename.c_str( ) );

  //if there's an error, display it
  if(error) std::cout << "vessel - decoder error " << error << ": " << lodepng_error_text( error ) << std::endl;


  //decode
  error = lodepng::decode( water_image, width, height, water_filename.c_str( ) );

  //if there's an error, display it
  if(error) std::cout << "water - decoder error " << error << ": " << lodepng_error_text( error ) << std::endl;



  int water_index = 0;
  int vessel_index = 0;


  RGBA temp;


  for(int z = 0; z < 160; z++)
  {
    for(int y = 0; y < 160; y++)
    {
      for(int x = 0; x < 160; x++)
      {

        temp.red   = vessel_image[vessel_index]; vessel_index++;
        temp.green = vessel_image[vessel_index]; vessel_index++;
        temp.blue  = vessel_image[vessel_index]; vessel_index++;
        temp.alpha = vessel_image[vessel_index]; vessel_index++;

        main_block->set_data_by_vector_index( vec( x, y, z ), main_block->get_vox( temp, false ), true, false );



      }

    }

  }

  for(int z = 0; z < 176; z++)
  {
    for(int y = 0; y < 176; y++)
    {
      for(int x = 0; x < 176; x++)
      {

        temp.red   = water_image[water_index]; water_index++;
        temp.green = water_image[water_index]; water_index++;
        temp.blue  = water_image[water_index]; water_index++;
        temp.alpha = water_image[water_index]; water_index++;
        
        main_block->set_data_by_vector_index( vec( 400 - x, y, z ), main_block->get_vox( temp, false ), true, false );

      }

    }

  }





  main_block->save("heads.png");










	return 0;
}
