#include <iostream>
#include <string>
#include <chrono>
#include <unistd.h>
#include <cstdio>
#include "../resources/voraldo/v.h"

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
  main_block->draw->init_block(dimensions);

  vec center = vec(floor(init_x/2),floor(init_y/2),floor(init_z/2));

  auto tick = Clock::now(); //variable to hold start of the timekeeping
  auto tock = Clock::now(); //variable to hold end of timekeeping



  tick = Clock::now();





  vec middle_front_point_1 = vec( 90, 126, 116 ); //side one is towards the negative z
  vec middle_front_point_2 = vec( 90, 126, 138 ); //side one is towards the positive z

  vec middle_back_point_1 = vec( 440, 120, 112 );
  vec middle_back_point_2 = vec( 440, 120, 142 );

  vec outer_point_1 = vec( 420, 64, 2 * (38 - 28) );
  vec outer_point_2 = vec( 420, 64, 2 * (89 + 28) );

  vec ball_1_center = ( middle_front_point_1 + middle_back_point_1 + outer_point_1 );
  vec ball_2_center = ( middle_front_point_2 + middle_back_point_2 + outer_point_2 );





  ball_1_center = vec( ball_1_center[0]/3.0 + 24, ball_1_center[1]/3.0 - 4, ball_1_center[2]/3.0 + 3 );
  ball_2_center = vec( ball_2_center[0]/3.0 + 24, ball_2_center[1]/3.0 - 4, ball_2_center[2]/3.0 - 3 );


  main_block->draw->draw_triangle( middle_front_point_1, middle_back_point_1, outer_point_1, get_vox(19,1.0,1.0,false));
  main_block->draw->draw_triangle( middle_front_point_2, middle_back_point_2, outer_point_2, get_vox(19,1.0,1.0,false));

  middle_front_point_1 += vec( 1, -1, 0);
  middle_front_point_2 += vec( 1, -1, 0);

  middle_back_point_1 += vec( -1, -1, 0);
  middle_back_point_2 += vec( -1, -1, 0);

  outer_point_1 += vec( -2, -2, 2);
  outer_point_2 += vec( -2, -2, -2);


  main_block->draw->draw_triangle( middle_front_point_1, middle_back_point_1, outer_point_1, get_vox(57,1.0,1.0,false));
  main_block->draw->draw_triangle( middle_front_point_2, middle_back_point_2, outer_point_2, get_vox(57,1.0,1.0,false));


  middle_front_point_1 += vec( 1, -1, 0);
  middle_front_point_2 += vec( 1, -1, 0);

  middle_back_point_1 += vec( -1, -1, 0);
  middle_back_point_2 += vec( -1, -1, 0);

  outer_point_1 += vec( -2, -2, 2);
  outer_point_2 += vec( -2, -2, -2);


  main_block->draw->draw_triangle( middle_front_point_1, middle_back_point_1, outer_point_1, get_vox(61,1.0,1.0,false));
  main_block->draw->draw_triangle( middle_front_point_2, middle_back_point_2, outer_point_2, get_vox(61,1.0,1.0,false));

  middle_front_point_1 += vec( 1, -1, 0);
  middle_front_point_2 += vec( 1, -1, 0);

  middle_back_point_1 += vec( -1, -1, 0);
  middle_back_point_2 += vec( -1, -1, 0);

  outer_point_1 += vec( -2, -2, 2);
  outer_point_2 += vec( -2, -2, -2);


  main_block->draw->draw_triangle( middle_front_point_1, middle_back_point_1, outer_point_1, get_vox(57,1.0,1.0,false));
  main_block->draw->draw_triangle( middle_front_point_2, middle_back_point_2, outer_point_2, get_vox(57,1.0,1.0,false));


  middle_front_point_1 += vec( 1, -1, 0);
  middle_front_point_2 += vec( 1, -1, 0);

  middle_back_point_1 += vec( -1, -1, 0);
  middle_back_point_2 += vec( -1, -1, 0);

  outer_point_1 += vec( -2, -2, 2);
  outer_point_2 += vec( -2, -2, -2);


  main_block->draw->draw_triangle( middle_front_point_1, middle_back_point_1, outer_point_1, get_vox(61,1.0,1.0,false));
  main_block->draw->draw_triangle( middle_front_point_2, middle_back_point_2, outer_point_2, get_vox(61,1.0,1.0,false));

  middle_front_point_1 += vec( 1, -1, 0);
  middle_front_point_2 += vec( 1, -1, 0);

  middle_back_point_1 += vec( -1, -1, 0);
  middle_back_point_2 += vec( -1, -1, 0);

  outer_point_1 += vec( -2, -2, 2);
  outer_point_2 += vec( -2, -2, -2);


  main_block->draw->draw_triangle( middle_front_point_1, middle_back_point_1, outer_point_1, get_vox(57,1.0,1.0,false));
  main_block->draw->draw_triangle( middle_front_point_2, middle_back_point_2, outer_point_2, get_vox(57,1.0,1.0,false));


  middle_front_point_1 += vec( 1, -1, 0);
  middle_front_point_2 += vec( 1, -1, 0);

  middle_back_point_1 += vec( -1, -1, 0);
  middle_back_point_2 += vec( -1, -1, 0);

  outer_point_1 += vec( -2, -2, 2);
  outer_point_2 += vec( -2, -2, -2);


  main_block->draw->draw_triangle( middle_front_point_1, middle_back_point_1, outer_point_1, get_vox(61,1.0,1.0,false));
  main_block->draw->draw_triangle( middle_front_point_2, middle_back_point_2, outer_point_2, get_vox(61,1.0,1.0,false));


  main_block->draw->mask_all_nonzero();
  main_block->draw->mask_invert_mask();

  main_block->draw->draw_sphere(ball_1_center, 20, get_vox(8,1.0,1.0,false));
  main_block->draw->draw_sphere(ball_1_center, 19, get_vox(0,0.0,1.0,false));


  main_block->draw->draw_sphere(ball_2_center, 20, get_vox(8,1.0,1.0,false));
  main_block->draw->draw_sphere(ball_2_center, 19, get_vox(0,0.0,1.0,false));

  main_block->draw->mask_unmask_all();


  main_block->draw->draw_tube(ball_1_center,ball_2_center,2,4,get_vox(52,1.0,1.0,false));

  main_block->draw->draw_tube(ball_1_center, ball_1_center + vec(-100,0,0),5,7,get_vox(58,1.0,1.0,false));
  main_block->draw->draw_tube(ball_2_center, ball_2_center + vec(-100,0,0),5,7,get_vox(58,1.0,1.0,false));

  // main_block->draw->draw_tube(ball_1_center, middle_front_point_1,5,7,get_vox(58,1.0,1.0,false));
  // main_block->draw->draw_tube(ball_2_center, middle_front_point_2,5,7,get_vox(58,1.0,1.0,false));


  main_block->draw->draw_sphere(ball_1_center, 11, get_vox(58,0.1,1.0,false));
  main_block->draw->draw_sphere(ball_1_center, 10, get_vox(0,0.0,1.0,false));

  main_block->draw->draw_sphere(ball_2_center, 11, get_vox(58,0.1,1.0,false));
  main_block->draw->draw_sphere(ball_2_center, 10, get_vox(0,0.0,1.0,false));


  main_block->draw->mask_all_nonzero();

  vec betwixt_the_balls = ball_1_center + ball_2_center;

  betwixt_the_balls = vec(betwixt_the_balls[0]/2,betwixt_the_balls[1]/2,betwixt_the_balls[2]/2);

  main_block->draw->draw_sphere(betwixt_the_balls, 20, get_vox(57,0.1,1.0,false));
  main_block->draw->draw_sphere(betwixt_the_balls, 19, get_vox( 0,0.0,1.0,false));

  vec ladder_point_1 = ball_1_center + vec(-30,0,0);
  vec ladder_point_2 = ball_2_center + vec(-30,0,0);

  for(int i = 0; i <= 90; i+= 5)
    main_block->draw->draw_tube(ladder_point_1 + vec(-i*2,0,0),ladder_point_2 + vec(-i*2,0,0),2,3,get_vox(52,1.0,1.0,false));






  bool draw_axes = true;

  if( draw_axes )
  {

// along the x axes
  main_block->draw->draw_line_segment(vec(0,0,0), vec(init_x,0,0), get_vox(1,1.0,1.0,false));
  main_block->draw->draw_line_segment(vec(0,0,init_z-1), vec(init_x,0,init_z-1), get_vox(1,1.0,1.0,false));
  main_block->draw->draw_line_segment(vec(0,init_y-1,0), vec(init_x,init_y-1,0), get_vox(1,1.0,1.0,false));
  main_block->draw->draw_line_segment(vec(0,init_y-1,init_z-1), vec(init_x,init_y-1,init_z-1), get_vox(1,1.0,1.0,false));

// along the y axes
  main_block->draw->draw_line_segment(vec(0,0,0), vec(0,init_y,0), get_vox(33,1.0,1.0,false));
  main_block->draw->draw_line_segment(vec(init_x-1,0,0), vec(init_x-1,init_y,0), get_vox(33,1.0,1.0,false));
  main_block->draw->draw_line_segment(vec(init_x-1,0,init_z-1), vec(init_x-1,init_y,init_z-1), get_vox(33,1.0,1.0,false));
  main_block->draw->draw_line_segment(vec(0,0,init_z-1), vec(0,init_y,init_z-1), get_vox(33,1.0,1.0,false));

// along the z axes
  main_block->draw->draw_line_segment(vec(0,0,0), vec(0,0,init_z), get_vox(23,1.0,1.0,false));
  main_block->draw->draw_line_segment(vec(init_x-1,0,0), vec(init_x-1,0,init_z), get_vox(23,1.0,1.0,false));
  main_block->draw->draw_line_segment(vec(0,init_y-1,0), vec(0,init_y-1,init_z), get_vox(23,1.0,1.0,false));
  main_block->draw->draw_line_segment(vec(init_x-1,init_y-1,0), vec(init_x-1,init_y-1,init_z), get_vox(23,1.0,1.0,false));

// points at the corners
  main_block->draw->draw_point(vec(0,0,0), get_vox(62,1.0,1.0,false));
  main_block->draw->draw_point(vec(0,0,init_z-1), get_vox(62,1.0,1.0,false));
  main_block->draw->draw_point(vec(0,init_y-1,0), get_vox(62,1.0,1.0,false));
  main_block->draw->draw_point(vec(init_x-1,0,0), get_vox(62,1.0,1.0,false));

  main_block->draw->draw_point(vec(init_x-1,init_y-1,0), get_vox(62,1.0,1.0,false));
  main_block->draw->draw_point(vec(0,init_y-1,init_z-1), get_vox(62,1.0,1.0,false));
  main_block->draw->draw_point(vec(init_x-1,0,init_z-1), get_vox(62,1.0,1.0,false));
  main_block->draw->draw_point(vec(init_x-1,init_y-1,init_z-1), get_vox(62,1.0,1.0,false));

  }



  // main_block->draw->mask_all_nonzero();


  // main_block->draw->draw_sphere(betwixt_the_balls, 1000, get_vox(35,0.001,1.0,false));

  // main_block->lighting->apply_ambient_occlusion();
  // main_block->lighting->apply_directional_lighting(5.0, 3.14, 0.25*3.14, 3.14/3, 0.15, true);
  // main_block->lighting->scale_lighting_intensity(4.0);

  tock = Clock::now();

  cout << endl << endl << "drawing all shapes took " << std::chrono::duration_cast<milliseconds>(tock-tick).count() << " milliseconds" << endl;






  tick = Clock::now();

  main_block->io->save("save.png");

  tock = Clock::now();

  std::cout << "saving block to file took " << std::chrono::duration_cast<milliseconds>(tock-tick).count() << " milliseconds" << endl;




  tick = Clock::now();

  main_block->io->display("generate_preview.png",  3.14, 3.14/3.0, 3.14/3.0, 0.4, false);

  tock = Clock::now();

  std::cout << "generate's renderer took " << std::chrono::duration_cast<milliseconds>(tock-tick).count() << " milliseconds" << endl;


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
