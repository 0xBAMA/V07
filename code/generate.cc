#include <iostream>
#include <string>
#include <chrono>
#include <unistd.h>
#include <cstdio>
#include "../resources/voraldo/v7.h"

//stream class shit
using std::cout;
using std::endl;
using std::cin;


//Chrono class aliases
using Clock=std::chrono::high_resolution_clock;
using milliseconds=std::chrono::milliseconds;


void draw_axes_and_corners();



int init_x = 512;
int init_y = 256;
int init_z = 256;

vec dimensions(init_x,init_y,init_z);

int startval = 0;
int endval = 1;

Voraldo *main_block;


int main()
{
  char numstring[5];//used when rendering multiple frames

  main_block = new Voraldo();
  main_block->init_block(dimensions);

  vec center = vec(floor(init_x/2),floor(init_y/2),floor(init_z/2));

  auto tick = Clock::now(); //variable to hold start of the timekeeping
  auto tock = Clock::now(); //variable to hold end of timekeeping



  tick = Clock::now();




  // main_block->draw_perlin_noise( 0.04, 0.5, main_block->get_vox( 25, 20,false ) );
  // main_block->draw_perlin_noise( 0.04, 0.4, main_block->get_vox( 40, 50,false ) );
  // main_block->draw_perlin_noise( 0.04, 0.3, main_block->get_vox(  7,255,false ) );
  // main_block->draw_perlin_noise( 0.04,-0.45, main_block->get_vox( 22, 30, false ) );
  //
  // main_block->draw_cylinder(vec( 0, 127.5, 127.5), vec( 512, 127.5, 127.5), 70, main_block->get_vox(  13, 255, false ) );
  // main_block->draw_cylinder(vec( 255.5, 0, 127.5 ), vec( 255.5, 255, 127.5 ), 70, main_block->get_vox(  13, 255, false ) );
  // main_block->draw_cylinder(vec( 255.5, 127.5, 0 ), vec( 255.5, 127.5, 255 ), 70, main_block->get_vox(  13, 255, false ) );
  //
  //
  //
  // main_block->draw_cylinder(vec( 0, 127.5, 127.5), vec( 512, 127.5, 127.5),  60, main_block->get_vox(  12, 255, false ) );
  // main_block->draw_cylinder(vec( 255.5, 127.5, 0 ), vec( 255.5, 127.5, 255 ),  60, main_block->get_vox(  12, 255, false ) );
  // main_block->draw_cylinder(vec( 255.5, 0, 127.5 ), vec( 255.5, 255, 127.5 ),  60, main_block->get_vox(  12, 255, false ) );
  //
  //
  //
  // main_block->draw_cylinder(vec( 0, 127.5, 127.5), vec( 512, 127.5, 127.5),  50, main_block->get_vox(   0,   0, false ) );
  // main_block->draw_cylinder(vec( 255.5, 127.5, 0 ), vec( 255.5, 127.5, 255 ),  50, main_block->get_vox(   0,   0, false ) );
  // main_block->draw_cylinder(vec( 255.5, 0, 127.5 ), vec( 255.5, 255, 127.5 ),  50, main_block->get_vox(   0,   0, false ) );
  //
  //
  // main_block->draw_perlin_noise( 0.05, 0.4, main_block->get_vox(  0, 0, false ) );
  //
  // main_block->mask_all_nonzero();
  //
  // main_block->draw_cylinder(vec(     0, 127.5, 127.5), vec( 512, 127.5, 127.5),  10, main_block->get_vox(   48,   255, false ) );
  // main_block->draw_cylinder(vec( 255.5, 127.5, 0 ), vec( 255.5, 127.5, 255 ),  10, main_block->get_vox(   48,   255, false ) );
  // main_block->draw_cylinder(vec( 255.5, 0, 127.5 ), vec( 255.5, 255, 127.5 ),  10, main_block->get_vox(   48,   255, false ) );
  //
  //
  // main_block->mask_unmask_all();
  // main_block->mask_by_state(48);
  // main_block->mask_invert_mask();
  //
  // main_block->draw_perlin_noise( 0.1, 0.5, main_block->get_vox(  0, 0, false ) );
  // main_block->draw_perlin_noise( 0.10, 0.4, main_block->get_vox(  10, 255, false ) );
  // main_block->draw_perlin_noise( 0.12, 0.5, main_block->get_vox(  47, 255, false ) );
  // main_block->draw_perlin_noise( 0.15, 0.4, main_block->get_vox(   0,   0, false ) );
  // main_block->draw_perlin_noise( 0.15, 0.2, main_block->get_vox(   3, 255, false ) );
  // main_block->draw_perlin_noise( 0.15, 0.1, main_block->get_vox(   7, 255, false ) );




  main_block->load("save.png");




  // main_block->draw_sphere( vec(255.5,127.5,127.5), 200, main_block->get_vox(   7,  10, false ) );
  //
  // main_block->draw_perlin_noise( 0.01,   0.51, main_block->get_vox(  12, 255, false ) );
  // main_block->draw_perlin_noise( 0.01,   0.50, main_block->get_vox(  30, 255, false ) );
  // main_block->draw_perlin_noise( 0.01,   0.49, main_block->get_vox(   0,  0, false ) );
  //
  //
  // main_block->draw_perlin_noise( 0.01,  0.4, main_block->get_vox(  57, 30, false ) );
  // main_block->draw_perlin_noise( 0.01, -0.6, main_block->get_vox(  61, 30, false ) );
  //
  // main_block->draw_perlin_noise( 0.05, 0.6, main_block->get_vox(  0, 0, false ) );







//FRAMING
  bool draw_axes = true;
  if( draw_axes )
  {
    draw_axes_and_corners();
  }




  // main_block->lighting->apply_ambient_occlusion();
  // main_block->lighting->apply_directional_lighting(5.0, 3.14, 0.25*3.14, 3.14/3, 0.15, true);
  // main_block->lighting->scale_lighting_intensity(4.0);

  tock = Clock::now();

  cout << endl << endl << "drawing all shapes took " << std::chrono::duration_cast<milliseconds>(tock-tick).count() << " milliseconds" << endl;






  tick = Clock::now();
  main_block->save("save.png");
  tock = Clock::now();

  std::cout << "saving block to file took " << std::chrono::duration_cast<milliseconds>(tock-tick).count() << " milliseconds" << endl;




  tick = Clock::now();
  main_block->display("generate_preview.png",  3.14, 3.14/3.0, 3.14/3.0, 0.4, false);
  tock = Clock::now();

  // std::cout << "generate's renderer took " << std::chrono::duration_cast<milliseconds>(tock-tick).count() << " milliseconds" << endl << endl << endl;

  return 0;
}


void draw_axes_and_corners()
{

  main_block->mask_unmask_all();

// along the x axes
  main_block->draw_cylinder(vec(0,0,0), vec(init_x,0,0),1.5, main_block->get_vox(1,255,false));
  main_block->draw_cylinder(vec(0,0,init_z-1), vec(init_x,0,init_z-1),1.5, main_block->get_vox(1,255,false));
  main_block->draw_cylinder(vec(0,init_y-1,0), vec(init_x,init_y-1,0),1.5, main_block->get_vox(1,255,false));
  main_block->draw_cylinder(vec(0,init_y-1,init_z-1), vec(init_x,init_y-1,init_z-1),1.5, main_block->get_vox(1,255,false));

// along the y axes
  main_block->draw_cylinder(vec(0,0,0), vec(0,init_y,0),1.5, main_block->get_vox(23,255,false));
  main_block->draw_cylinder(vec(init_x-1,0,0), vec(init_x-1,init_y,0),1.5, main_block->get_vox(23,255,false));
  main_block->draw_cylinder(vec(init_x-1,0,init_z-1), vec(init_x-1,init_y,init_z-1),1.5, main_block->get_vox(23,255,false));
  main_block->draw_cylinder(vec(0,0,init_z-1), vec(0,init_y,init_z-1),1.5, main_block->get_vox(23,255,false));

// along the z axes
  main_block->draw_cylinder(vec(0,0,0), vec(0,0,init_z),1.5, main_block->get_vox(33,255,false));
  main_block->draw_cylinder(vec(init_x-1,0,0), vec(init_x-1,0,init_z),1.5, main_block->get_vox(33,255,false));
  main_block->draw_cylinder(vec(0,init_y-1,0), vec(0,init_y-1,init_z),1.5, main_block->get_vox(33,255,false));
  main_block->draw_cylinder(vec(init_x-1,init_y-1,0), vec(init_x-1,init_y-1,init_z),1.5, main_block->get_vox(33,255,false));

// points at the corners
  main_block->draw_sphere(vec(0,0,0), 3, main_block->get_vox(62,255,false));
  main_block->draw_sphere(vec(0,0,init_z-1), 3, main_block->get_vox(62,255,false));
  main_block->draw_sphere(vec(0,init_y-1,0), 3, main_block->get_vox(62,255,false));
  main_block->draw_sphere(vec(init_x-1,0,0), 3, main_block->get_vox(62,255,false));

  main_block->draw_sphere(vec(init_x-1,init_y-1,0), 3, main_block->get_vox(62,255,false));
  main_block->draw_sphere(vec(0,init_y-1,init_z-1), 3, main_block->get_vox(62,255,false));
  main_block->draw_sphere(vec(init_x-1,0,init_z-1), 3, main_block->get_vox(62,255,false));
  main_block->draw_sphere(vec(init_x-1,init_y-1,init_z-1), 3, main_block->get_vox(62,255,false));

}
