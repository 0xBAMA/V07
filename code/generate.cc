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

// PALETTE TEST
  // vec loc1 = vec(30, 30, 30);
  // vec loc2 = vec(30, 30,127);
  // vec loc3 = vec(30, 30,225);
  //
  // vec loc4 = vec(30,127, 30);
  // vec loc5 = vec(30,127,127);
  // vec loc6 = vec(30,127,225);
  //
  // vec loc7 = vec(30,225, 30);
  // vec loc8 = vec(30,225,127);
  // vec loc9 = vec(30,225,225);
  //
  //
  //
  // for(int num = 0; num <= 78; num++)
  // {
  //   // main_block->draw_sphere(loc1 + vec(5*num,std::rand()%10-5,std::rand()%20-10), 5, main_block->get_vox(num,255,false));
  //   // main_block->draw_sphere(loc2 + vec(5*num,std::rand()%10-5,std::rand()%20-10), 5, main_block->get_vox(num,255,false));
  //   // main_block->draw_sphere(loc3 + vec(5*num,std::rand()%10-5,std::rand()%20-10), 5, main_block->get_vox(num,255,false));
  //
  //   main_block->draw_sphere(loc1 + vec(5.75*num,0,0), 5, main_block->get_vox(num,255,false));
  //   main_block->draw_sphere(loc2 + vec(5.75*num,0,0), 5, main_block->get_vox(num,255,false));
  //   main_block->draw_sphere(loc3 + vec(5.75*num,0,0), 5, main_block->get_vox(num,255,false));
  //
  //   main_block->draw_sphere(loc4 + vec(5.75*num,std::rand()%15-7.5,std::rand()%20-10), 5, main_block->get_vox(num,255,false));
  //   main_block->draw_sphere(loc5 + vec(5.75*num,std::rand()%15-7.5,std::rand()%20-10), 5, main_block->get_vox(num,255,false));
  //   main_block->draw_sphere(loc6 + vec(5.75*num,std::rand()%15-7.5,std::rand()%20-10), 5, main_block->get_vox(num,255,false));
  //
  //   main_block->draw_sphere(loc7 + vec(5.75*num,std::rand()%20-10,std::rand()%20-10), 5, main_block->get_vox(num,255,false));
  //   main_block->draw_sphere(loc8 + vec(5.75*num,std::rand()%20-10,std::rand()%20-10), 5, main_block->get_vox(num,255,false));
  //   main_block->draw_sphere(loc9 + vec(5.75*num,std::rand()%20-10,std::rand()%20-10), 5, main_block->get_vox(num,255,false));
  //
  // }
  //
  // main_block->mask_all_nonzero();
  //
  // main_block->draw_sphere(vec(256,127,127), 74.9, main_block->get_vox(62,10,false));
  //
  // main_block->draw_cylinder(loc1-vec(30,0,0), loc1+vec(500,0,0),1, main_block->get_vox(62,255,false));
  // main_block->draw_cylinder(loc2-vec(30,0,0), loc2+vec(500,0,0),1, main_block->get_vox(62,255,false));
  // main_block->draw_cylinder(loc3-vec(30,0,0), loc3+vec(500,0,0),1, main_block->get_vox(62,255,false));
  //
  // main_block->draw_cylinder(loc4-vec(30,0,0), loc4+vec(500,0,0),1, main_block->get_vox(62,255,false));
  // main_block->draw_cylinder(loc5-vec(30,0,0), loc5+vec(500,0,0),1, main_block->get_vox(62,255,false));
  // main_block->draw_cylinder(loc6-vec(30,0,0), loc6+vec(500,0,0),1, main_block->get_vox(62,255,false));
  //
  // main_block->draw_cylinder(loc7-vec(30,0,0), loc7+vec(500,0,0),1, main_block->get_vox(62,255,false));
  // main_block->draw_cylinder(loc8-vec(30,0,0), loc8+vec(500,0,0),1, main_block->get_vox(62,255,false));
  // main_block->draw_cylinder(loc9-vec(30,0,0), loc9+vec(500,0,0),1, main_block->get_vox(62,255,false));




// STAR TREK EQUIPMENT FIXTURE
  vec a,b,c,d,e,f,g,h,v;

  a = vec( 250,225,225 );
  b = vec( 250, 30,225 );
  c = vec( 270,225,225 );
  d = vec( 270, 30,225 );
  e = vec( 250,225, 30 );
  f = vec( 250, 30, 30 );
  g = vec( 270,225, 30 );
  h = vec( 270, 30, 30 );

  v = vec( 100,  0,  0 );

  main_block->draw_quadrilateral_hexahedron(   a,   b,   c,   d,   e,   f,   g,   h, main_block->get_vox( 62, 255, false ) );
  main_block->draw_quadrilateral_hexahedron( a+v, b+v, c+v, d+v, e+v, f+v, g+v, h+v, main_block->get_vox( 62, 255, false ) );
  main_block->draw_quadrilateral_hexahedron( a-v, b-v, c-v, d-v, e-v, f-v, g-v, h-v, main_block->get_vox( 62, 255, false ) );


  a = vec( 258,225,225 );
  b = vec( 258, 30,225 );
  c = vec( 262,225,225 );
  d = vec( 262, 30,225 );
  e = vec( 258,225, 30 );
  f = vec( 258, 30, 30 );
  g = vec( 262,225, 30 );
  h = vec( 262, 30, 30 );

  main_block->draw_quadrilateral_hexahedron(   a,   b,   c,   d,   e,   f,   g,   h, main_block->get_vox(  8, 255, false ) );
  main_block->draw_quadrilateral_hexahedron( a+v, b+v, c+v, d+v, e+v, f+v, g+v, h+v, main_block->get_vox(  8, 255, false ) );
  main_block->draw_quadrilateral_hexahedron( a-v, b-v, c-v, d-v, e-v, f-v, g-v, h-v, main_block->get_vox(  8, 255, false ) );



  main_block->mask_all_nonzero();

  main_block->mask_invert_mask();

  main_block->draw_cylinder( vec( 130,  60,   60), vec( 390,  60,   60), 15, main_block->get_vox( 12, 5, false ) );
  main_block->draw_cylinder( vec( 130,  95,   60), vec( 390,  95,   60), 10, main_block->get_vox( 11, 5, false ) );
  main_block->draw_cylinder( vec( 130, 127.5, 60), vec( 390, 127.5, 60), 10, main_block->get_vox( 11, 5, false ) );
  main_block->draw_cylinder( vec( 130, 160,   60), vec( 390, 160,   60), 10, main_block->get_vox( 11, 5, false ) );
  main_block->draw_cylinder( vec( 130, 195,   60), vec( 390, 195,   60), 15, main_block->get_vox( 12, 5, false ) );

  main_block->draw_cylinder( vec( 130,  60,   195), vec( 390,  60,   195), 15, main_block->get_vox( 12, 5, false ) );
  main_block->draw_cylinder( vec( 130,  95,   195), vec( 390,  95,   195), 10, main_block->get_vox( 11, 5, false ) );
  main_block->draw_cylinder( vec( 130, 127.5, 195), vec( 390, 127.5, 195), 10, main_block->get_vox( 11, 5, false ) );
  main_block->draw_cylinder( vec( 130, 160,   195), vec( 390, 160,   195), 10, main_block->get_vox( 11, 5, false ) );
  main_block->draw_cylinder( vec( 130, 195,   195), vec( 390, 195,   195), 15, main_block->get_vox( 12, 5, false ) );



  main_block->draw_cylinder( vec( 130, 195, 160  ), vec( 390, 195, 160  ), 10, main_block->get_vox( 11, 5, false ) );
  main_block->draw_cylinder( vec( 130, 195, 127.5), vec( 390, 195, 127.5), 10, main_block->get_vox( 11, 5, false ) );
  main_block->draw_cylinder( vec( 130, 195,  95  ), vec( 390,195,   95  ), 10, main_block->get_vox( 11, 5, false ) );

  main_block->draw_cylinder( vec( 130, 60, 160  ), vec( 390, 60, 160  ), 10, main_block->get_vox( 11, 5, false ) );
  main_block->draw_cylinder( vec( 130, 60, 127.5), vec( 390, 60, 127.5), 10, main_block->get_vox( 11, 5, false ) );
  main_block->draw_cylinder( vec( 130, 60,  95  ), vec( 390, 60,  95  ), 10, main_block->get_vox( 11, 5, false ) );



  main_block->draw_sphere( vec( 255.5, 127.5, 127.5 ), 25, main_block->get_vox( 34, 5, false ) );
  main_block->draw_sphere( vec( 255.5, 127.5, 127.5 ) + v, 25, main_block->get_vox( 34, 5, false ) );
  main_block->draw_sphere( vec( 255.5, 127.5, 127.5 ) - v, 25, main_block->get_vox( 34, 5, false ) );

  main_block->mask_unmask_all();

  main_block->draw_cylinder( vec( 390,225,225 ), vec( 130,225,225 ), 5, main_block->get_vox( 18, 200, false ) );
  main_block->draw_cylinder( vec( 390, 30,225 ), vec( 130, 30,225 ), 5, main_block->get_vox( 18, 200, false ) );
  main_block->draw_cylinder( vec( 390,225, 30 ), vec( 130,225, 30 ), 5, main_block->get_vox( 18, 200, false ) );
  main_block->draw_cylinder( vec( 390, 30, 30 ), vec( 130, 30, 30 ), 5, main_block->get_vox( 18, 200, false ) );

  main_block->draw_tube( vec( 405, 127.5, 127.5), vec( 102, 127.5, 127.5), 10, 15, main_block->get_vox( 19, 200, false ) );

  main_block->mask_all_nonzero();

  main_block->draw_sphere( vec( 255.5, 127.5, 127.5), 200, main_block->get_vox( 15, 30, false ) );
  main_block->draw_sphere( vec( 255.5, 127.5, 127.5), 195, main_block->get_vox( 15,  0, false ) );





// FRAMING

  bool draw_axes = true;

  if( draw_axes )
  {

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
  main_block->draw_point(vec(0,0,0), main_block->get_vox(62,255,false));
  main_block->draw_point(vec(0,0,init_z-1), main_block->get_vox(62,255,false));
  main_block->draw_point(vec(0,init_y-1,0), main_block->get_vox(62,255,false));
  main_block->draw_point(vec(init_x-1,0,0), main_block->get_vox(62,255,false));

  main_block->draw_point(vec(init_x-1,init_y-1,0), main_block->get_vox(62,255,false));
  main_block->draw_point(vec(0,init_y-1,init_z-1), main_block->get_vox(62,255,false));
  main_block->draw_point(vec(init_x-1,0,init_z-1), main_block->get_vox(62,255,false));
  main_block->draw_point(vec(init_x-1,init_y-1,init_z-1), main_block->get_vox(62,255,false));

  }



  // main_block->mask_all_nonzero();


  // main_block->draw_sphere(betwixt_the_balls, 1000, main_block->get_vox(35,0.001,1.0,false));

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

  // main_block->io->display("generate_preview.png",  3.14, 3.14/3.0, 3.14/3.0, 0.4, false);

  tock = Clock::now();

  std::cout << "generate's renderer took " << std::chrono::duration_cast<milliseconds>(tock-tick).count() << " milliseconds" << endl << endl << endl;

  return 0;
}
