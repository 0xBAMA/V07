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


  vec loc1 = vec(30, 30, 30);
  vec loc2 = vec(30, 30,127);
  vec loc3 = vec(30, 30,225);

  vec loc4 = vec(30,127, 30);
  vec loc5 = vec(30,127,127);
  vec loc6 = vec(30,127,225);

  vec loc7 = vec(30,225, 30);
  vec loc8 = vec(30,225,127);
  vec loc9 = vec(30,225,225);



  for(int num = 0; num <= 78; num++)
  {
    main_block->draw_sphere(loc1 + vec(5*num,std::rand()%10-5,std::rand()%20-10), 5, main_block->get_vox(num,false));
    main_block->draw_sphere(loc2 + vec(5*num,std::rand()%10-5,std::rand()%20-10), 5, main_block->get_vox(num,false));
    main_block->draw_sphere(loc3 + vec(5*num,std::rand()%10-5,std::rand()%20-10), 5, main_block->get_vox(num,false));

    main_block->draw_sphere(loc4 + vec(5*num,std::rand()%10-5,std::rand()%20-10), 5, main_block->get_vox(num,false));
    main_block->draw_sphere(loc5 + vec(5*num,std::rand()%10-5,std::rand()%20-10), 5, main_block->get_vox(num,false));
    main_block->draw_sphere(loc6 + vec(5*num,std::rand()%10-5,std::rand()%20-10), 5, main_block->get_vox(num,false));

    main_block->draw_sphere(loc7 + vec(5*num,std::rand()%10-5,std::rand()%20-10), 5, main_block->get_vox(num,false));
    main_block->draw_sphere(loc8 + vec(5*num,std::rand()%10-5,std::rand()%20-10), 5, main_block->get_vox(num,false));
    main_block->draw_sphere(loc9 + vec(5*num,std::rand()%10-5,std::rand()%20-10), 5, main_block->get_vox(num,false));

  }

  // main_block->mask_all_nonzero();

  main_block->draw_noise();


// FRAMING

  bool draw_axes = false;

  if( draw_axes )
  {

// along the x axes
  main_block->draw_cylinder(vec(0,0,0), vec(init_x,0,0),0.75, main_block->get_vox(1,false));
  main_block->draw_cylinder(vec(0,0,init_z-1), vec(init_x,0,init_z-1),0.75, main_block->get_vox(1,false));
  main_block->draw_cylinder(vec(0,init_y-1,0), vec(init_x,init_y-1,0),0.75, main_block->get_vox(1,false));
  main_block->draw_cylinder(vec(0,init_y-1,init_z-1), vec(init_x,init_y-1,init_z-1),0.75, main_block->get_vox(1,false));

// along the y axes
  main_block->draw_cylinder(vec(0,0,0), vec(0,init_y,0),0.75, main_block->get_vox(23,false));
  main_block->draw_cylinder(vec(init_x-1,0,0), vec(init_x-1,init_y,0),0.75, main_block->get_vox(23,false));
  main_block->draw_cylinder(vec(init_x-1,0,init_z-1), vec(init_x-1,init_y,init_z-1),0.75, main_block->get_vox(23,false));
  main_block->draw_cylinder(vec(0,0,init_z-1), vec(0,init_y,init_z-1),0.75, main_block->get_vox(23,false));

// along the z axes
  main_block->draw_cylinder(vec(0,0,0), vec(0,0,init_z),0.75, main_block->get_vox(33,false));
  main_block->draw_cylinder(vec(init_x-1,0,0), vec(init_x-1,0,init_z),0.75, main_block->get_vox(33,false));
  main_block->draw_cylinder(vec(0,init_y-1,0), vec(0,init_y-1,init_z),0.75, main_block->get_vox(33,false));
  main_block->draw_cylinder(vec(init_x-1,init_y-1,0), vec(init_x-1,init_y-1,init_z),0.75, main_block->get_vox(33,false));

// points at the corners
  main_block->draw_point(vec(0,0,0), main_block->get_vox(62,false));
  main_block->draw_point(vec(0,0,init_z-1), main_block->get_vox(62,false));
  main_block->draw_point(vec(0,init_y-1,0), main_block->get_vox(62,false));
  main_block->draw_point(vec(init_x-1,0,0), main_block->get_vox(62,false));

  main_block->draw_point(vec(init_x-1,init_y-1,0), main_block->get_vox(62,false));
  main_block->draw_point(vec(0,init_y-1,init_z-1), main_block->get_vox(62,false));
  main_block->draw_point(vec(init_x-1,0,init_z-1), main_block->get_vox(62,false));
  main_block->draw_point(vec(init_x-1,init_y-1,init_z-1), main_block->get_vox(62,false));

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


/*
 if(fork()){
    if(fork()){
      for(int i = startval; i < endval; i += 4)
      {
        std::cout << "frame number " << i;
        tick = Clock::now();

        sprintf(numstring, "%04d", i);//this is a better solution on string formatting
        main_block->io->display("animation/new_output"+ std::string(numstring) +".png",  3.14, 0.002*i*3.14/3.0, 3.14/3.0, 0.4, false);

        tock = Clock::now();
        std::cout << " took " << std::chrono::duration_cast<milliseconds>(tock-tick).count() << " milliseconds" << endl;

       }//end for
   }else{
     for(int i = startval+1; i < endval; i += 4)
     {
       std::cout << "frame number " << i;
       tick = Clock::now();

       sprintf(numstring, "%04d", i);//this is a better solution on string formatting
       main_block->io->display("animation/new_output"+ std::string(numstring) +".png",  3.14, 0.002*i*3.14/3.0, 3.14/3.0, 0.4, false);

       tock = Clock::now();
       std::cout << " took " << std::chrono::duration_cast<milliseconds>(tock-tick).count() << " milliseconds" << endl;

      }//end for
   }
 }else{
   if(fork()){
     for(int i = startval+2; i < endval; i += 4)
     {
       std::cout << "frame number " << i;
       tick = Clock::now();

       sprintf(numstring, "%04d", i);//this is a better solution on string formatting
       main_block->io->display("animation/new_output"+ std::string(numstring) +".png",  3.14, 0.002*i*3.14/3.0, 3.14/3.0, 0.4, false);

       tock = Clock::now();
       std::cout << " took " << std::chrono::duration_cast<milliseconds>(tock-tick).count() << " milliseconds" << endl;

      }//end for
  }else{
    for(int i = startval+3; i < endval; i += 4)
    {
      std::cout << "frame number " << i;
      tick = Clock::now();

      sprintf(numstring, "%04d", i);//this is a better solution on string formatting
      main_block->io->display("animation/new_output"+ std::string(numstring) +".png",  3.14, 0.002*i*3.14/3.0, 3.14/3.0, 0.4, false);

      tock = Clock::now();
      std::cout << " took " << std::chrono::duration_cast<milliseconds>(tock-tick).count() << " milliseconds" << endl;

     }//end for
  }
}
*/

  return 0;
}
