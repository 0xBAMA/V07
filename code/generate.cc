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



//SHIP

//   vec middle_front_point_1 = vec( 90, 126, 116 ); //side one is towards the negative z
//   vec middle_front_point_2 = vec( 90, 126, 138 ); //side one is towards the positive z
//
//   vec middle_back_point_1 = vec( 440, 120, 112 );
//   vec middle_back_point_2 = vec( 440, 120, 142 );
//
//   vec outer_point_1 = vec( 420, 64, 20 );
//   vec outer_point_2 = vec( 420, 64, 234 );
//
//   vec ball_1_center = ( middle_front_point_1 + middle_back_point_1 + outer_point_1 ) + vec( 40, -10, -25 );
//   vec ball_2_center = ( middle_front_point_2 + middle_back_point_2 + outer_point_2 ) + vec( 40, -10,  25 );
//
//
//
//
//
//   ball_1_center = vec( ball_1_center[0]/3.0 + 24, ball_1_center[1]/3.0 - 4, ball_1_center[2]/3.0 + 3 );
//   ball_2_center = vec( ball_2_center[0]/3.0 + 24, ball_2_center[1]/3.0 - 4, ball_2_center[2]/3.0 - 3 );
//
//
//   vec inc = vec(0,1,0);
//
//
//   main_block->draw->draw_triangle( middle_front_point_1, middle_back_point_1, outer_point_1, get_vox(19,1.0,1.0,false));
//   // main_block->draw->draw_triangle( middle_front_point_1+inc, middle_back_point_1+inc, outer_point_1+inc, get_vox(19,1.0,1.0,false));
//
//   main_block->draw->draw_triangle( middle_front_point_2, middle_back_point_2, outer_point_2, get_vox(19,1.0,1.0,false));
//   // main_block->draw->draw_triangle( middle_front_point_2+inc, middle_back_point_2+inc, outer_point_2+inc, get_vox(19,1.0,1.0,false));
//
//
//
//   main_block->draw->draw_line_segment(middle_back_point_1, outer_point_1, get_vox(19,1.0,1.0,false));
//   main_block->draw->draw_line_segment(middle_back_point_2, outer_point_2, get_vox(19,1.0,1.0,false));
//
//
// //fins
//   main_block->draw->draw_triangle( middle_back_point_1 + vec(-5,0,0), middle_back_point_1 + vec(-35,0,0), middle_back_point_1 + vec(10,20,0), get_vox(19,1.0,1.0,false));
//   main_block->draw->draw_triangle( middle_back_point_2 + vec(-5,0,0), middle_back_point_2 + vec(-35,0,0), middle_back_point_2 + vec(10,20,0), get_vox(19,1.0,1.0,false));
//
//   main_block->draw->draw_triangle( outer_point_1 + vec(-5,0,0), outer_point_1 + vec(-35,7,7), outer_point_1 + vec(10,20,-15), get_vox(19,1.0,1.0,false));
//   main_block->draw->draw_triangle( outer_point_2 + vec(-5,0,0), outer_point_2 + vec(-35,7,-7), outer_point_2 + vec(10,20, 15), get_vox(19,1.0,1.0,false));
//
//
//
//
//   middle_front_point_1 += vec( 2, -2, 0);
//   middle_front_point_2 += vec( 2, -2, 0);
//
//   middle_back_point_1 += vec( -2, -2, 0);
//   middle_back_point_2 += vec( -2, -2, 0);
//
//   outer_point_1 += vec( -4, -4, 4);
//   outer_point_2 += vec( -4, -4, -4);
//
//
//   main_block->draw->draw_triangle( middle_front_point_1, middle_back_point_1, outer_point_1, get_vox(57,1.0,1.0,false));
//   main_block->draw->draw_triangle( middle_front_point_2, middle_back_point_2, outer_point_2, get_vox(57,1.0,1.0,false));
//
//
//   // middle_front_point_1 += vec( 1, -1, 0);
//   // middle_front_point_2 += vec( 1, -1, 0);
//   //
//   // middle_back_point_1 += vec( -1, -1, 0);
//   // middle_back_point_2 += vec( -1, -1, 0);
//   //
//   // outer_point_1 += vec( -2, -2, 2);
//   // outer_point_2 += vec( -2, -2, -2);
//
//   middle_front_point_1 += vec( 2, -2, 0);
//   middle_front_point_2 += vec( 2, -2, 0);
//
//   middle_back_point_1 += vec( -2, -2, 0);
//   middle_back_point_2 += vec( -2, -2, 0);
//
//   outer_point_1 += vec( -4, -4, 4);
//   outer_point_2 += vec( -4, -4, -4);
//
//
//   main_block->draw->draw_triangle( middle_front_point_1, middle_back_point_1, outer_point_1, get_vox(61,1.0,1.0,false));
//   main_block->draw->draw_triangle( middle_front_point_2, middle_back_point_2, outer_point_2, get_vox(61,1.0,1.0,false));
//
//   middle_front_point_1 += vec( 2, -2, 0);
//   middle_front_point_2 += vec( 2, -2, 0);
//
//   middle_back_point_1 += vec( -2, -2, 0);
//   middle_back_point_2 += vec( -2, -2, 0);
//
//   outer_point_1 += vec( -4, -4, 4);
//   outer_point_2 += vec( -4, -4, -4);
//
//   main_block->draw->draw_triangle( middle_front_point_1, middle_back_point_1, outer_point_1, get_vox(57,1.0,1.0,false));
//   main_block->draw->draw_triangle( middle_front_point_2, middle_back_point_2, outer_point_2, get_vox(57,1.0,1.0,false));
//
//
//   middle_front_point_1 += vec( 2, -2, 0);
//   middle_front_point_2 += vec( 2, -2, 0);
//
//   middle_back_point_1 += vec( -2, -2, 0);
//   middle_back_point_2 += vec( -2, -2, 0);
//
//   outer_point_1 += vec( -4, -4, 4);
//   outer_point_2 += vec( -4, -4, -4);
//
//
//   main_block->draw->draw_triangle( middle_front_point_1, middle_back_point_1, outer_point_1, get_vox(61,1.0,1.0,false));
//   main_block->draw->draw_triangle( middle_front_point_2, middle_back_point_2, outer_point_2, get_vox(61,1.0,1.0,false));
//
//   middle_front_point_1 += vec( 2, -2, 0);
//   middle_front_point_2 += vec( 2, -2, 0);
//
//   middle_back_point_1 += vec( -2, -2, 0);
//   middle_back_point_2 += vec( -2, -2, 0);
//
//   outer_point_1 += vec( -4, -4, 4);
//   outer_point_2 += vec( -4, -4, -4);
//
//
//   main_block->draw->draw_triangle( middle_front_point_1, middle_back_point_1, outer_point_1, get_vox(57,1.0,1.0,false));
//   main_block->draw->draw_triangle( middle_front_point_2, middle_back_point_2, outer_point_2, get_vox(57,1.0,1.0,false));
//
//
//   middle_front_point_1 += vec( 2, -2, 0);
//   middle_front_point_2 += vec( 2, -2, 0);
//
//   middle_back_point_1 += vec( -2, -2, 0);
//   middle_back_point_2 += vec( -2, -2, 0);
//
//   outer_point_1 += vec( -4, -4, 4);
//   outer_point_2 += vec( -4, -4, -4);
//
//
//   main_block->draw->draw_triangle( middle_front_point_1, middle_back_point_1, outer_point_1, get_vox(61,1.0,1.0,false));
//   main_block->draw->draw_triangle( middle_front_point_2, middle_back_point_2, outer_point_2, get_vox(61,1.0,1.0,false));
//
//
//   main_block->draw->mask_all_nonzero();
//   main_block->draw->mask_invert_mask();
//
//   main_block->draw->draw_sphere(ball_1_center, 30, get_vox(7,1.0,1.0,false));
//   main_block->draw->draw_sphere(ball_1_center, 29, get_vox(0,0.0,1.0,false));
//
//
//   main_block->draw->draw_sphere(ball_2_center, 30, get_vox(7,1.0,1.0,false));
//   main_block->draw->draw_sphere(ball_2_center, 29, get_vox(0,0.0,1.0,false));
//
//   main_block->draw->mask_unmask_all();
//
//
//   // main_block->draw->draw_tube(ball_1_center,ball_2_center,2,4,get_vox(52,1.0,1.0,false));
//
//
//
//   // vec middle_front_point_1 = vec( 90, 126, 116 );
//   // vec middle_front_point_2 = vec( 90, 126, 138 );
//   //
//   // vec middle_back_point_1 = vec( 440, 120, 112 );
//   // vec middle_back_point_2 = vec( 440, 120, 142 );
//
//
//   main_block->draw->draw_tube(ball_1_center, ball_1_center + vec(-100,0,0),5,7,get_vox(58,1.0,1.0,false));
//   main_block->draw->draw_tube(ball_2_center, ball_2_center + vec(-100,0,0),5,7,get_vox(58,1.0,1.0,false));
//
//   // main_block->draw->draw_tube(ball_1_center, middle_front_point_1,5,7,get_vox(58,1.0,1.0,false));
//   // main_block->draw->draw_tube(ball_2_center, middle_front_point_2,5,7,get_vox(58,1.0,1.0,false));
//
//
//
//
//
//
//   // main_block->draw->draw_sphere(ball_1_center, 21, get_vox(58,0.1,1.0,false));
//   // main_block->draw->draw_sphere(ball_1_center, 20, get_vox(0,0.0,1.0,false));
//   //
//   // main_block->draw->draw_sphere(ball_2_center, 21, get_vox(58,0.1,1.0,false));
//   // main_block->draw->draw_sphere(ball_2_center, 20, get_vox(0,0.0,1.0,false));
//
//
//   main_block->draw->mask_all_nonzero();
//
//   vec betwixt_the_balls = ball_1_center + ball_2_center;
//
//   betwixt_the_balls = vec(betwixt_the_balls[0]/2,betwixt_the_balls[1]/2,betwixt_the_balls[2]/2);
//
//   main_block->draw->draw_regular_icosahedron(0,0,0,15,betwixt_the_balls + vec(0,-10,0), get_vox(62,1.0,1.0,false), 3, get_vox(62,1.0,1.0,false), 2, get_vox(23,0.3,1.0,false));






// BLOCKS
//
//   vec c = vec(255, 127, 127); //center
//
//   vec a_o = vec( -20,  20,  20); //offsets for points a-h
//   vec b_o = vec( -20, -20,  20);
//   vec c_o = vec(  20,  20,  20);
//   vec d_o = vec(  20, -20,  20);
//   vec e_o = vec( -20,  20, -20);
//   vec f_o = vec( -20, -20, -20);
//   vec g_o = vec(  20,  20, -20);
//   vec h_o = vec(  20, -20, -20);
//
//   vec point1,point2;
//
//
//   main_block->draw->draw_quadrilateral_hexahedron( c+a_o, c+b_o, c+c_o, c+d_o, c+e_o, c+f_o, c+g_o, c+h_o, get_vox(23,0.3,1.0,false));
//
//   c = vec(255 + 100, 127, 127);
//
//   main_block->draw->draw_quadrilateral_hexahedron( c+a_o, c+b_o, c+c_o, c+d_o, c+e_o, c+f_o, c+g_o, c+h_o, get_vox(23,0.3,1.0,false));
//
//   c = vec(255 - 100, 127, 127);
//
//   main_block->draw->draw_quadrilateral_hexahedron( c+a_o, c+b_o, c+c_o, c+d_o, c+e_o, c+f_o, c+g_o, c+h_o, get_vox(23,0.3,1.0,false));
//
//   c = vec(255, 127 + 50, 127);
//
//   main_block->draw->draw_quadrilateral_hexahedron( c+a_o, c+b_o, c+c_o, c+d_o, c+e_o, c+f_o, c+g_o, c+h_o, get_vox(23,0.3,1.0,false));
//
//   c = vec(255, 127 - 50, 127);
//
//   main_block->draw->draw_quadrilateral_hexahedron( c+a_o, c+b_o, c+c_o, c+d_o, c+e_o, c+f_o, c+g_o, c+h_o, get_vox(23,0.3,1.0,false));
//
//   c = vec(255, 127, 127 + 50);
//
//   point1 = c+e_o;
//
//   main_block->draw->draw_quadrilateral_hexahedron( c+a_o, c+b_o, c+c_o, c+d_o, c+e_o, c+f_o, c+g_o, c+h_o, get_vox(23,0.3,1.0,false));
//
//   c = vec(255, 127, 127 - 50);
//
//   point2 = c+a_o;
//
//   main_block->draw->draw_quadrilateral_hexahedron( c+a_o, c+b_o, c+c_o, c+d_o, c+e_o, c+f_o, c+g_o, c+h_o, get_vox(23,0.3,1.0,false));
//
//   main_block->draw->draw_line_segment(point1, point2, get_vox(1,1.0,1.0,false));
//
//   // main_block->draw->draw_tube(point1, point2,5,10, get_vox(62,0.3,1.0,false));
//





main_block->draw->draw_sphere(vec(255,127,127), 75.5, get_vox(57,1.0,1.0,false));

main_block->draw->draw_sphere(vec(255,127,127), 75.2, get_vox(62,1.0,1.0,false));






// FRAMING

  bool draw_axes = true;

  if( draw_axes )
  {

// along the x axes
  main_block->draw->draw_line_segment(vec(0,0,0), vec(init_x,0,0), get_vox(1,1.0,1.0,false));
  main_block->draw->draw_line_segment(vec(0,0,init_z-1), vec(init_x,0,init_z-1), get_vox(1,1.0,1.0,false));
  main_block->draw->draw_line_segment(vec(0,init_y-1,0), vec(init_x,init_y-1,0), get_vox(1,1.0,1.0,false));
  main_block->draw->draw_line_segment(vec(0,init_y-1,init_z-1), vec(init_x,init_y-1,init_z-1), get_vox(1,1.0,1.0,false));

// along the y axes
  main_block->draw->draw_line_segment(vec(0,0,0), vec(0,init_y,0), get_vox(23,1.0,1.0,false));
  main_block->draw->draw_line_segment(vec(init_x-1,0,0), vec(init_x-1,init_y,0), get_vox(23,1.0,1.0,false));
  main_block->draw->draw_line_segment(vec(init_x-1,0,init_z-1), vec(init_x-1,init_y,init_z-1), get_vox(23,1.0,1.0,false));
  main_block->draw->draw_line_segment(vec(0,0,init_z-1), vec(0,init_y,init_z-1), get_vox(23,1.0,1.0,false));

// along the z axes
  main_block->draw->draw_line_segment(vec(0,0,0), vec(0,0,init_z), get_vox(33,1.0,1.0,false));
  main_block->draw->draw_line_segment(vec(init_x-1,0,0), vec(init_x-1,0,init_z), get_vox(33,1.0,1.0,false));
  main_block->draw->draw_line_segment(vec(0,init_y-1,0), vec(0,init_y-1,init_z), get_vox(33,1.0,1.0,false));
  main_block->draw->draw_line_segment(vec(init_x-1,init_y-1,0), vec(init_x-1,init_y-1,init_z), get_vox(33,1.0,1.0,false));

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
