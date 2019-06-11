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


// The environment - land and sky
  main_block->draw_sphere(vec(255.5, 127.5, 127.5), 500, main_block->get_vox( 57, 1, false) );
  main_block->draw_minecraft_style_terrain();

// Center of the space
  vec castle_center = vec(255.5, 100, 127.5);



  vec a, b, c, d, e, f, g, h;

// main walls
  a = castle_center + vec(-50,  77,  50);
  b = castle_center + vec(-50,   0,  50);
  c = castle_center + vec( 50,  77,  50);
  d = castle_center + vec( 50,   0,  50);
  e = castle_center + vec(-50,  77, -50);
  f = castle_center + vec(-50,   0, -50);
  g = castle_center + vec( 50,  77, -50);
  h = castle_center + vec( 50,   0, -50);

  main_block->draw_quadrilateral_hexahedron(a, b, c, d, e, f, g, h, main_block->get_vox( 60, 255, false) );

// cutout for courtyard
  a = castle_center + vec(-40,  77,  40);
  b = castle_center + vec(-40,   5,  40);
  c = castle_center + vec( 40,  77,  40);
  d = castle_center + vec( 40,   5,  40);
  e = castle_center + vec(-40,  77, -40);
  f = castle_center + vec(-40,   5, -40);
  g = castle_center + vec( 40,  77, -40);
  h = castle_center + vec( 40,   5, -40);

  main_block->draw_quadrilateral_hexahedron(a, b, c, d, e, f, g, h, main_block->get_vox( 0, 0, false) );


  a = castle_center + vec(-45,  80,  45);
  b = castle_center + vec(-45,   0,  45);
  c = castle_center + vec( 45,  80,  45);
  d = castle_center + vec( 45,   0,  45);
  e = castle_center + vec(-45,  80, -45);
  f = castle_center + vec(-45,   0, -45);
  g = castle_center + vec( 45,  80, -45);
  h = castle_center + vec( 45,   0, -45);

// cut out space for towers
  main_block->draw_cylinder(a, b, 12, main_block->get_vox( 0, 0, false) );
  main_block->draw_cylinder(c, d, 12, main_block->get_vox( 0, 0, false) );
  main_block->draw_cylinder(e, f, 12, main_block->get_vox( 0, 0, false) );
  main_block->draw_cylinder(g, h, 12, main_block->get_vox( 0, 0, false) );

// draw the stairs for the spiral staircase...

  vec fe_tower_location = f;
  vec ba_tower_location = b;
  vec dc_tower_location = d;
  vec hg_tower_location = h;

// "rotated" vectors to represent stair edges
  vec displacement_vectors[8] = {vec(1,0,0), vec(1,0,1), vec(0,0,1), vec(-1,0,1), vec(-1,0,0), vec(-1,0,-1), vec(0,0,-1), vec(1,0,-1)};

// normalize and multiply to make them all the same lengths
  for(int i = 0; i < 8; i++)
    displacement_vectors[i] = 10.0f * normalize(displacement_vectors[i]);

  int index1 = 0;
  int index2 = 1;


  for(int i = 0; i < 40; i++)
  {
    // drawing the steps for this level
    main_block->draw_triangle(fe_tower_location, fe_tower_location + displacement_vectors[index1], fe_tower_location + displacement_vectors[index2], 2.0, main_block->get_vox( 20, 255, false) );
    main_block->draw_triangle(ba_tower_location, ba_tower_location + displacement_vectors[index1], ba_tower_location + displacement_vectors[index2], 2.0, main_block->get_vox( 20, 255, false) );
    main_block->draw_triangle(dc_tower_location, dc_tower_location + displacement_vectors[index1], dc_tower_location + displacement_vectors[index2], 2.0, main_block->get_vox( 20, 255, false) );
    main_block->draw_triangle(hg_tower_location, hg_tower_location + displacement_vectors[index1], hg_tower_location + displacement_vectors[index2], 2.0, main_block->get_vox( 20, 255, false) );

    // increment the indicies for the displacement vectors
    index1++; index2++;
    if(index1 == 8) index1 = 0;
    if(index2 == 8) index2 = 0;

    // move 'em on up
    fe_tower_location += vec(0,1.75,0);
    ba_tower_location += vec(0,1.75,0);
    dc_tower_location += vec(0,1.75,0);
    hg_tower_location += vec(0,1.75,0);
  }


// platform at the top of the stairs
  main_block->draw_cylinder(fe_tower_location, fe_tower_location + vec(0,2,0), 10, main_block->get_vox( 20, 255, false) );
  main_block->draw_cylinder(ba_tower_location, ba_tower_location + vec(0,2,0), 10, main_block->get_vox( 20, 255, false) );
  main_block->draw_cylinder(dc_tower_location, dc_tower_location + vec(0,2,0), 10, main_block->get_vox( 20, 255, false) );
  main_block->draw_cylinder(hg_tower_location, hg_tower_location + vec(0,2,0), 10, main_block->get_vox( 20, 255, false) );


// cutout for the top stair (quarter circle)
  main_block->draw_triangle(fe_tower_location, fe_tower_location + displacement_vectors[7], fe_tower_location + displacement_vectors[0], 3.0, main_block->get_vox( 0, 0, false) );
  main_block->draw_triangle(ba_tower_location, ba_tower_location + displacement_vectors[7], ba_tower_location + displacement_vectors[0], 3.0, main_block->get_vox( 0, 0, false) );
  main_block->draw_triangle(dc_tower_location, dc_tower_location + displacement_vectors[7], dc_tower_location + displacement_vectors[0], 3.0, main_block->get_vox( 0, 0, false) );
  main_block->draw_triangle(hg_tower_location, hg_tower_location + displacement_vectors[7], hg_tower_location + displacement_vectors[0], 3.0, main_block->get_vox( 0, 0, false) );

  main_block->draw_triangle(fe_tower_location, fe_tower_location + displacement_vectors[0], fe_tower_location + displacement_vectors[1], 3.0, main_block->get_vox( 0, 0, false) );
  main_block->draw_triangle(ba_tower_location, ba_tower_location + displacement_vectors[0], ba_tower_location + displacement_vectors[1], 3.0, main_block->get_vox( 0, 0, false) );
  main_block->draw_triangle(dc_tower_location, dc_tower_location + displacement_vectors[0], dc_tower_location + displacement_vectors[1], 3.0, main_block->get_vox( 0, 0, false) );
  main_block->draw_triangle(hg_tower_location, hg_tower_location + displacement_vectors[0], hg_tower_location + displacement_vectors[1], 3.0, main_block->get_vox( 0, 0, false) );


  a += vec(0,2,0);
  b += vec(0,2,0);
  c += vec(0,2,0);
  d += vec(0,2,0);
  e += vec(0,2,0);
  f += vec(0,2,0);
  g += vec(0,2,0);
  h += vec(0,2,0);


// draw outer walls of towers
  main_block->draw_tube(a, b, 9, 12, main_block->get_vox( 60, 255, false) );
  main_block->draw_tube(c, d, 9, 12, main_block->get_vox( 60, 255, false) );
  main_block->draw_tube(e, f, 9, 12, main_block->get_vox( 60, 255, false) );
  main_block->draw_tube(g, h, 9, 12, main_block->get_vox( 60, 255, false) );


// draw central post of towers
  main_block->draw_cylinder(a, b, 2, main_block->get_vox( 60, 255, false) );
  main_block->draw_cylinder(c, d, 2, main_block->get_vox( 60, 255, false) );
  main_block->draw_cylinder(e, f, 2, main_block->get_vox( 60, 255, false) );
  main_block->draw_cylinder(g, h, 2, main_block->get_vox( 60, 255, false) );

// tower caps
  main_block->draw_cylinder(a, a+vec(0,8,0), 14, main_block->get_vox( 60, 255, false) );
  main_block->draw_cylinder(c, c+vec(0,8,0), 14, main_block->get_vox( 60, 255, false) );
  main_block->draw_cylinder(e, e+vec(0,8,0), 14, main_block->get_vox( 60, 255, false) );
  main_block->draw_cylinder(g, g+vec(0,8,0), 14, main_block->get_vox( 60, 255, false) );

  main_block->draw_cylinder(a+vec(0,2,0), a+vec(0,8,0), 10, main_block->get_vox( 0, 0, false) );
  main_block->draw_cylinder(c+vec(0,2,0), c+vec(0,8,0), 10, main_block->get_vox( 0, 0, false) );
  main_block->draw_cylinder(e+vec(0,2,0), e+vec(0,8,0), 10, main_block->get_vox( 0, 0, false) );
  main_block->draw_cylinder(g+vec(0,2,0), g+vec(0,8,0), 10, main_block->get_vox( 0, 0, false) );

// crenelations for towers - lengthen displacement vectors
  for(int i = 0; i < 8; i++)
    displacement_vectors[i] = 15.0f * normalize(displacement_vectors[i]);

  for(int i = 0; i < 8; i++)
  {
    main_block->draw_cylinder(a+vec(0,8,0), a+vec(0,8,0)+displacement_vectors[i], 2, main_block->get_vox( 0, 0, false) );
    main_block->draw_cylinder(c+vec(0,8,0), c+vec(0,8,0)+displacement_vectors[i], 2, main_block->get_vox( 0, 0, false) );
    main_block->draw_cylinder(e+vec(0,8,0), e+vec(0,8,0)+displacement_vectors[i], 2, main_block->get_vox( 0, 0, false) );
    main_block->draw_cylinder(g+vec(0,8,0), g+vec(0,8,0)+displacement_vectors[i], 2, main_block->get_vox( 0, 0, false) );
  }

// walkways on the walls - wood layer (20) then empty layer for negative space


// those along the x axis
  vec wa, wb, wc, wd, we, wf, wg, wh;

  wa = castle_center + vec(-38, 77, 48);
  wb = castle_center + vec(-38, 70, 48);
  wc = castle_center + vec( 38, 77, 48);
  wd = castle_center + vec( 38, 70, 48);
  we = castle_center + vec(-38, 77, 42);
  wf = castle_center + vec(-38, 70, 42);
  wg = castle_center + vec( 38, 77, 42);
  wh = castle_center + vec( 38, 70, 42);

  main_block->draw_quadrilateral_hexahedron(wa, wb, wc, wd, we, wf, wg, wh, main_block->get_vox( 20, 255, false) );

  wa = castle_center + vec(-38, 77, 48);
  wb = castle_center + vec(-38, 72, 48);
  wc = castle_center + vec( 38, 77, 48);
  wd = castle_center + vec( 38, 72, 48);
  we = castle_center + vec(-38, 77, 42);
  wf = castle_center + vec(-38, 72, 42);
  wg = castle_center + vec( 38, 77, 42);
  wh = castle_center + vec( 38, 72, 42);

  main_block->draw_quadrilateral_hexahedron(wa, wb, wc, wd, we, wf, wg, wh, main_block->get_vox( 0, 0, false) );

  main_block->draw_cylinder((wa+we)/2.0f, (wc+wg)/2.0f, 3, main_block->get_vox( 0, 0, false) );

  wa = castle_center + vec(-38, 77, -48);
  wb = castle_center + vec(-38, 70, -48);
  wc = castle_center + vec( 38, 77, -48);
  wd = castle_center + vec( 38, 70, -48);
  we = castle_center + vec(-38, 77, -42);
  wf = castle_center + vec(-38, 70, -42);
  wg = castle_center + vec( 38, 77, -42);
  wh = castle_center + vec( 38, 70, -42);

  main_block->draw_quadrilateral_hexahedron(wa, wb, wc, wd, we, wf, wg, wh, main_block->get_vox( 20, 255, false) );

  wa = castle_center + vec(-38, 77, -48);
  wb = castle_center + vec(-38, 72, -48);
  wc = castle_center + vec( 38, 77, -48);
  wd = castle_center + vec( 38, 72, -48);
  we = castle_center + vec(-38, 77, -42);
  wf = castle_center + vec(-38, 72, -42);
  wg = castle_center + vec( 38, 77, -42);
  wh = castle_center + vec( 38, 72, -42);

  main_block->draw_quadrilateral_hexahedron(wa, wb, wc, wd, we, wf, wg, wh, main_block->get_vox( 0, 0, false) );

  main_block->draw_cylinder((wa+we)/2.0f, (wc+wg)/2.0f, 3, main_block->get_vox( 0, 0, false) );

// crenelations

  // for(int i = 0; i < )


//--------------------------------------


// those along the z axis

  wa = castle_center + vec(-42, 77, 38);
  wb = castle_center + vec(-42, 70, 38);
  wc = castle_center + vec(-48, 77, 38);
  wd = castle_center + vec(-48, 70, 38);
  we = castle_center + vec(-42, 77,-38);
  wf = castle_center + vec(-42, 70,-38);
  wg = castle_center + vec(-48, 77,-38);
  wh = castle_center + vec(-48, 70,-38);

  main_block->draw_quadrilateral_hexahedron(wa, wb, wc, wd, we, wf, wg, wh, main_block->get_vox( 20, 255, false) );

  wa = castle_center + vec(-42, 77, 38);
  wb = castle_center + vec(-42, 72, 38);
  wc = castle_center + vec(-48, 77, 38);
  wd = castle_center + vec(-48, 72, 38);
  we = castle_center + vec(-42, 77,-38);
  wf = castle_center + vec(-42, 72,-38);
  wg = castle_center + vec(-48, 77,-38);
  wh = castle_center + vec(-48, 72,-38);

  main_block->draw_quadrilateral_hexahedron(wa, wb, wc, wd, we, wf, wg, wh, main_block->get_vox( 0, 0, false) );

  main_block->draw_cylinder((wg+we)/2.0f, (wc+wa)/2.0f, 3, main_block->get_vox( 0, 0, false) );

  wa = castle_center + vec(42, 77, 38);
  wb = castle_center + vec(42, 70, 38);
  wc = castle_center + vec(48, 77, 38);
  wd = castle_center + vec(48, 70, 38);
  we = castle_center + vec(42, 77,-38);
  wf = castle_center + vec(42, 70,-38);
  wg = castle_center + vec(48, 77,-38);
  wh = castle_center + vec(48, 70,-38);

  main_block->draw_quadrilateral_hexahedron(wa, wb, wc, wd, we, wf, wg, wh, main_block->get_vox( 20, 255, false) );

  wa = castle_center + vec(42, 77, 38);
  wb = castle_center + vec(42, 72, 38);
  wc = castle_center + vec(48, 77, 38);
  wd = castle_center + vec(48, 72, 38);
  we = castle_center + vec(42, 77,-38);
  wf = castle_center + vec(42, 72,-38);
  wg = castle_center + vec(48, 77,-38);
  wh = castle_center + vec(48, 72,-38);

  main_block->draw_quadrilateral_hexahedron(wa, wb, wc, wd, we, wf, wg, wh, main_block->get_vox( 0, 0, false) );

  main_block->draw_cylinder((wg+we)/2.0f, (wc+wa)/2.0f, 3, main_block->get_vox( 0, 0, false) );

// crenelations












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
