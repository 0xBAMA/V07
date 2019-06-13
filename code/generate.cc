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

  main_block->draw_quadrilateral_hexahedron(a, b, c, d, e, f, g, h, main_block->get_vox(57, 1, false) );


  a = castle_center + vec(-45,  80,  45);
  b = castle_center + vec(-45,   0,  45);
  c = castle_center + vec( 45,  80,  45);
  d = castle_center + vec( 45,   0,  45);
  e = castle_center + vec(-45,  80, -45);
  f = castle_center + vec(-45,   0, -45);
  g = castle_center + vec( 45,  80, -45);
  h = castle_center + vec( 45,   0, -45);

// cut out space for towers
  main_block->draw_cylinder(a, b, 12, main_block->get_vox(57, 1, false) );
  main_block->draw_cylinder(c, d, 12, main_block->get_vox(57, 1, false) );
  main_block->draw_cylinder(e, f, 12, main_block->get_vox(57, 1, false) );
  main_block->draw_cylinder(g, h, 12, main_block->get_vox(57, 1, false) );

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

    main_block->draw_line_segment(fe_tower_location + vec(0,0.75,0), fe_tower_location + displacement_vectors[index1] + vec(0,0.75,0), main_block->get_vox( 21, 255, false) );
    main_block->draw_line_segment(ba_tower_location + vec(0,0.75,0), ba_tower_location + displacement_vectors[index1] + vec(0,0.75,0), main_block->get_vox( 21, 255, false) );
    main_block->draw_line_segment(dc_tower_location + vec(0,0.75,0), dc_tower_location + displacement_vectors[index1] + vec(0,0.75,0), main_block->get_vox( 21, 255, false) );
    main_block->draw_line_segment(hg_tower_location + vec(0,0.75,0), hg_tower_location + displacement_vectors[index1] + vec(0,0.75,0), main_block->get_vox( 21, 255, false) );



    // railings
    main_block->draw_cylinder(fe_tower_location + displacement_vectors[index1] + vec(0,5,0), fe_tower_location + displacement_vectors[index2] + vec(0,6.75,0), 1.0, main_block->get_vox( 21, 255, false) );
    main_block->draw_cylinder(ba_tower_location + displacement_vectors[index1] + vec(0,5,0), ba_tower_location + displacement_vectors[index2] + vec(0,6.75,0), 1.0, main_block->get_vox( 21, 255, false) );
    main_block->draw_cylinder(dc_tower_location + displacement_vectors[index1] + vec(0,5,0), dc_tower_location + displacement_vectors[index2] + vec(0,6.75,0), 1.0, main_block->get_vox( 21, 255, false) );
    main_block->draw_cylinder(hg_tower_location + displacement_vectors[index1] + vec(0,5,0), hg_tower_location + displacement_vectors[index2] + vec(0,6.75,0), 1.0, main_block->get_vox( 21, 255, false) );

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
  main_block->draw_triangle(fe_tower_location, fe_tower_location + displacement_vectors[7], fe_tower_location + displacement_vectors[0], 3.0, main_block->get_vox(57, 1, false) );
  main_block->draw_triangle(ba_tower_location, ba_tower_location + displacement_vectors[7], ba_tower_location + displacement_vectors[0], 3.0, main_block->get_vox(57, 1, false) );
  main_block->draw_triangle(dc_tower_location, dc_tower_location + displacement_vectors[7], dc_tower_location + displacement_vectors[0], 3.0, main_block->get_vox(57, 1, false) );
  main_block->draw_triangle(hg_tower_location, hg_tower_location + displacement_vectors[7], hg_tower_location + displacement_vectors[0], 3.0, main_block->get_vox(57, 1, false) );

  main_block->draw_triangle(fe_tower_location, fe_tower_location + displacement_vectors[0], fe_tower_location + displacement_vectors[1], 3.0, main_block->get_vox(57, 1, false) );
  main_block->draw_triangle(ba_tower_location, ba_tower_location + displacement_vectors[0], ba_tower_location + displacement_vectors[1], 3.0, main_block->get_vox(57, 1, false) );
  main_block->draw_triangle(dc_tower_location, dc_tower_location + displacement_vectors[0], dc_tower_location + displacement_vectors[1], 3.0, main_block->get_vox(57, 1, false) );
  main_block->draw_triangle(hg_tower_location, hg_tower_location + displacement_vectors[0], hg_tower_location + displacement_vectors[1], 3.0, main_block->get_vox(57, 1, false) );


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

  main_block->draw_cylinder(a+vec(0,2,0), a+vec(0,8,0), 10, main_block->get_vox(57, 1, false) );
  main_block->draw_cylinder(c+vec(0,2,0), c+vec(0,8,0), 10, main_block->get_vox(57, 1, false) );
  main_block->draw_cylinder(e+vec(0,2,0), e+vec(0,8,0), 10, main_block->get_vox(57, 1, false) );
  main_block->draw_cylinder(g+vec(0,2,0), g+vec(0,8,0), 10, main_block->get_vox(57, 1, false) );

// crenelations for towers - lengthen displacement vectors
  for(int i = 0; i < 8; i++)
    displacement_vectors[i] = 15.0f * normalize(displacement_vectors[i]);

  for(int i = 0; i < 8; i++)
  {
    main_block->draw_cylinder(a+vec(0,8,0), a+vec(0,8,0)+displacement_vectors[i], 2, main_block->get_vox(57, 1, false) );
    main_block->draw_cylinder(c+vec(0,8,0), c+vec(0,8,0)+displacement_vectors[i], 2, main_block->get_vox(57, 1, false) );
    main_block->draw_cylinder(e+vec(0,8,0), e+vec(0,8,0)+displacement_vectors[i], 2, main_block->get_vox(57, 1, false) );
    main_block->draw_cylinder(g+vec(0,8,0), g+vec(0,8,0)+displacement_vectors[i], 2, main_block->get_vox(57, 1, false) );
  }

// walkways on the walls - wood layer (20) then empty layer for negative space


// those along the x axis
  vec wa, wb, wc, wd, we, wf, wg, wh;

// wood layer
  wa = castle_center + vec(-38, 77, 48);
  wb = castle_center + vec(-38, 70, 48);
  wc = castle_center + vec( 38, 77, 48);
  wd = castle_center + vec( 38, 70, 48);
  we = castle_center + vec(-38, 77, 42);
  wf = castle_center + vec(-38, 70, 42);
  wg = castle_center + vec( 38, 77, 42);
  wh = castle_center + vec( 38, 70, 42);

  // upper walkway
  main_block->draw_quadrilateral_hexahedron(wa, wb, wc, wd, we, wf, wg, wh, main_block->get_vox( 20, 255, false) );

  vec shift = vec(0,-20, 0);

  // middle walkway
  main_block->draw_quadrilateral_hexahedron(wa+shift, wb+shift, wc+shift, wd+shift, we+shift, wf+shift, wg+shift, wh+shift, main_block->get_vox( 20, 255, false) );

  shift *= 2.0f;

  // lower walkway
  main_block->draw_quadrilateral_hexahedron(wa+shift, wb+shift, wc+shift, wd+shift, we+shift, wf+shift, wg+shift, wh+shift, main_block->get_vox( 20, 255, false) );




// empty layer
  wa = castle_center + vec(-38, 77, 48);
  wb = castle_center + vec(-38, 72, 48);
  wc = castle_center + vec( 38, 77, 48);
  wd = castle_center + vec( 38, 72, 48);
  we = castle_center + vec(-38, 77, 42);
  wf = castle_center + vec(-38, 72, 42);
  wg = castle_center + vec( 38, 77, 42);
  wh = castle_center + vec( 38, 72, 42);

  // upper walkway
  main_block->draw_quadrilateral_hexahedron(wa, wb, wc, wd, we, wf, wg, wh, main_block->get_vox(57, 1, false) );

  shift = vec(0,-20, 0);

  // middle walkway
  main_block->draw_quadrilateral_hexahedron(wa+shift, wb+shift, wc+shift, wd+shift, we+shift, wf+shift, wg+shift, wh+shift, main_block->get_vox(57, 1, false) );

  shift *= 2.0f;

  // lower walkway
  main_block->draw_quadrilateral_hexahedron(wa+shift, wb+shift, wc+shift, wd+shift, we+shift, wf+shift, wg+shift, wh+shift, main_block->get_vox(57, 1, false) );


// crown of the doorway
  main_block->draw_cylinder((wa+we)/2.0f, (wc+wg)/2.0f, 3, main_block->get_vox(57, 1, false) );

  shift = vec(0,-20, 0);

  // lower walkway
  main_block->draw_cylinder(((wa+we)/2.0f)+shift, ((wc+wg)/2.0f)+shift, 3, main_block->get_vox(57, 1, false) );

  shift *= 2.0f;

  // even lower walkway
  main_block->draw_cylinder(((wa+we)/2.0f)+shift, ((wc+wg)/2.0f)+shift, 3, main_block->get_vox(57, 1, false) );


// wood layer
  wa = castle_center + vec(-38, 77, -48);
  wb = castle_center + vec(-38, 70, -48);
  wc = castle_center + vec( 38, 77, -48);
  wd = castle_center + vec( 38, 70, -48);
  we = castle_center + vec(-38, 77, -42);
  wf = castle_center + vec(-38, 70, -42);
  wg = castle_center + vec( 38, 77, -42);
  wh = castle_center + vec( 38, 70, -42);

  main_block->draw_quadrilateral_hexahedron(wa, wb, wc, wd, we, wf, wg, wh, main_block->get_vox( 20, 255, false) );

  shift = vec(0,-20, 0);

  // middle walkway
  main_block->draw_quadrilateral_hexahedron(wa+shift, wb+shift, wc+shift, wd+shift, we+shift, wf+shift, wg+shift, wh+shift, main_block->get_vox( 20, 255, false) );

  shift *= 2.0f;

  // lower walkway
  main_block->draw_quadrilateral_hexahedron(wa+shift, wb+shift, wc+shift, wd+shift, we+shift, wf+shift, wg+shift, wh+shift, main_block->get_vox( 20, 255, false) );



// empty layer
  wa = castle_center + vec(-38, 77, -48);
  wb = castle_center + vec(-38, 72, -48);
  wc = castle_center + vec( 38, 77, -48);
  wd = castle_center + vec( 38, 72, -48);
  we = castle_center + vec(-38, 77, -42);
  wf = castle_center + vec(-38, 72, -42);
  wg = castle_center + vec( 38, 77, -42);
  wh = castle_center + vec( 38, 72, -42);

  main_block->draw_quadrilateral_hexahedron(wa, wb, wc, wd, we, wf, wg, wh, main_block->get_vox(57, 1, false) );

  shift = vec(0,-20, 0);

  // middle walkway
  main_block->draw_quadrilateral_hexahedron(wa+shift, wb+shift, wc+shift, wd+shift, we+shift, wf+shift, wg+shift, wh+shift, main_block->get_vox(57, 1, false) );

  shift *= 2.0f;

  // lower walkway
  main_block->draw_quadrilateral_hexahedron(wa+shift, wb+shift, wc+shift, wd+shift, we+shift, wf+shift, wg+shift, wh+shift, main_block->get_vox(57, 1, false) );


// crown of the doorway
  main_block->draw_cylinder((wa+we)/2.0f, (wc+wg)/2.0f, 3, main_block->get_vox(57, 1, false) );

  shift = vec(0,-20, 0);

  // lower walkway
  main_block->draw_cylinder(((wa+we)/2.0f)+shift, ((wc+wg)/2.0f)+shift, 3, main_block->get_vox(57, 1, false) );

  shift *= 2.0f;

  // even lower walkway
  main_block->draw_cylinder(((wa+we)/2.0f)+shift, ((wc+wg)/2.0f)+shift, 3, main_block->get_vox(57, 1, false) );


//--------------------------------------


// those along the z axis

// wood layer
  wa = castle_center + vec(-42, 77, 38);
  wb = castle_center + vec(-42, 70, 38);
  wc = castle_center + vec(-48, 77, 38);
  wd = castle_center + vec(-48, 70, 38);
  we = castle_center + vec(-42, 77,-38);
  wf = castle_center + vec(-42, 70,-38);
  wg = castle_center + vec(-48, 77,-38);
  wh = castle_center + vec(-48, 70,-38);

  // upper walkway
  main_block->draw_quadrilateral_hexahedron(wa, wb, wc, wd, we, wf, wg, wh, main_block->get_vox( 20, 255, false) );

  shift = vec(0,-20, 0);

  // middle walkway
  main_block->draw_quadrilateral_hexahedron(wa+shift, wb+shift, wc+shift, wd+shift, we+shift, wf+shift, wg+shift, wh+shift, main_block->get_vox( 20, 255, false) );

  shift *= 2.0f;

  // lower walkway
  main_block->draw_quadrilateral_hexahedron(wa+shift, wb+shift, wc+shift, wd+shift, we+shift, wf+shift, wg+shift, wh+shift, main_block->get_vox( 20, 255, false) );



// empty layer
  wa = castle_center + vec(-42, 77, 38);
  wb = castle_center + vec(-42, 72, 38);
  wc = castle_center + vec(-48, 77, 38);
  wd = castle_center + vec(-48, 72, 38);
  we = castle_center + vec(-42, 77,-38);
  wf = castle_center + vec(-42, 72,-38);
  wg = castle_center + vec(-48, 77,-38);
  wh = castle_center + vec(-48, 72,-38);

  // upper walkway
  main_block->draw_quadrilateral_hexahedron(wa, wb, wc, wd, we, wf, wg, wh, main_block->get_vox(57, 1, false) );

  shift = vec(0,-20, 0);

  // middle walkway
  main_block->draw_quadrilateral_hexahedron(wa+shift, wb+shift, wc+shift, wd+shift, we+shift, wf+shift, wg+shift, wh+shift, main_block->get_vox(57, 1, false) );

  shift *= 2.0f;

  // lower walkway
  main_block->draw_quadrilateral_hexahedron(wa+shift, wb+shift, wc+shift, wd+shift, we+shift, wf+shift, wg+shift, wh+shift, main_block->get_vox(57, 1, false) );



// crown of doorway
  main_block->draw_cylinder((wg+we)/2.0f, (wc+wa)/2.0f, 3, main_block->get_vox(57, 1, false) );

  shift = vec(0,-20, 0);

  // lower walkway
  main_block->draw_cylinder(((wg+we)/2.0f)+shift, ((wc+wa)/2.0f)+shift, 3, main_block->get_vox(57, 1, false) );

  shift *= 2.0f;

  // even lower walkway
  main_block->draw_cylinder(((wg+we)/2.0f)+shift, ((wc+wa)/2.0f)+shift, 3, main_block->get_vox(57, 1, false) );

// wood layer
  wa = castle_center + vec(42, 77, 38);
  wb = castle_center + vec(42, 70, 38);
  wc = castle_center + vec(48, 77, 38);
  wd = castle_center + vec(48, 70, 38);
  we = castle_center + vec(42, 77,-38);
  wf = castle_center + vec(42, 70,-38);
  wg = castle_center + vec(48, 77,-38);
  wh = castle_center + vec(48, 70,-38);

  // upper walkway
  main_block->draw_quadrilateral_hexahedron(wa, wb, wc, wd, we, wf, wg, wh, main_block->get_vox( 20, 255, false) );

  shift = vec(0,-20, 0);

  // middle walkway
  main_block->draw_quadrilateral_hexahedron(wa+shift, wb+shift, wc+shift, wd+shift, we+shift, wf+shift, wg+shift, wh+shift, main_block->get_vox( 20, 255, false) );

  shift *= 2.0f;

  // lower walkway
  main_block->draw_quadrilateral_hexahedron(wa+shift, wb+shift, wc+shift, wd+shift, we+shift, wf+shift, wg+shift, wh+shift, main_block->get_vox( 20, 255, false) );



// empty layer
  wa = castle_center + vec(42, 77, 38);
  wb = castle_center + vec(42, 72, 38);
  wc = castle_center + vec(48, 77, 38);
  wd = castle_center + vec(48, 72, 38);
  we = castle_center + vec(42, 77,-38);
  wf = castle_center + vec(42, 72,-38);
  wg = castle_center + vec(48, 77,-38);
  wh = castle_center + vec(48, 72,-38);

  main_block->draw_quadrilateral_hexahedron(wa, wb, wc, wd, we, wf, wg, wh, main_block->get_vox(57, 1, false) );

  shift = vec(0,-20, 0);

  // middle walkway
  main_block->draw_quadrilateral_hexahedron(wa+shift, wb+shift, wc+shift, wd+shift, we+shift, wf+shift, wg+shift, wh+shift, main_block->get_vox(57, 1, false) );

  shift *= 2.0f;

  // lower walkway
  main_block->draw_quadrilateral_hexahedron(wa+shift, wb+shift, wc+shift, wd+shift, we+shift, wf+shift, wg+shift, wh+shift, main_block->get_vox(57, 1, false) );


  main_block->draw_cylinder((wg+we)/2.0f, (wc+wa)/2.0f, 3, main_block->get_vox(57, 1, false) );

  shift = vec(0,-20, 0);

  // lower walkway
  main_block->draw_cylinder(((wg+we)/2.0f)+shift, ((wc+wa)/2.0f)+shift, 3, main_block->get_vox(57, 1, false) );

  shift *= 2.0f;

  // even lower walkway
  main_block->draw_cylinder(((wg+we)/2.0f)+shift, ((wc+wa)/2.0f)+shift, 3, main_block->get_vox(57, 1, false) );

// crenelations

  for(int i = 0; i <= 60; i+=6)
  {
    main_block->draw_cylinder(castle_center+vec(-30+i, 76, 50), castle_center+vec(-30+i, 76, -50), 1, main_block->get_vox(57, 1, false) );
    main_block->draw_cylinder(castle_center+vec(50, 76, -30+i), castle_center+vec(-50, 76, -30+i), 1, main_block->get_vox(57, 1, false) );
  }

// roadway
  a = castle_center + vec(-280,  35,  10);
  b = castle_center + vec(-280,   5,  10);
  c = castle_center + vec( -40,  35,  10);
  d = castle_center + vec( -40,   5,  10);
  e = castle_center + vec(-280,  35, -10);
  f = castle_center + vec(-280,   5, -10);
  g = castle_center + vec( -40,  35, -10);
  h = castle_center + vec( -40,   5, -10);

  vec k = vec(0,-2,0);

  main_block->draw_quadrilateral_hexahedron(a+k, b+k, c+k, d+k, e+k, f+k, g+k, h+k, main_block->get_vox(20, 255, false) );

  main_block->draw_quadrilateral_hexahedron(a, b, c, d, e, f, g, h, main_block->get_vox(57, 1, false) );

  main_block->draw_cylinder( (a+e)/2.0f, (c+g)/2.0f, 10,  main_block->get_vox(57, 1, false) );


  main_block->mask_by_state(60);

  main_block->mask_invert_mask();


  main_block->draw_cylinder( (a+e)/2.0f, (c+g)/2.0f, 12,  main_block->get_vox(61, 255, false) );

  a = castle_center + vec( -80,  35,  12);
  b = castle_center + vec( -80,   5,  12);
  c = castle_center + vec( -40,  35,  12);
  d = castle_center + vec( -40,   5,  12);
  e = castle_center + vec( -80,  35, -12);
  f = castle_center + vec( -80,   5, -12);
  g = castle_center + vec( -40,  35, -12);
  h = castle_center + vec( -40,   5, -12);

  main_block->draw_quadrilateral_hexahedron(a, b, c, d, e, f, g, h, main_block->get_vox(61, 255, false) );

  main_block->mask_unmask_all();

  main_block->mask_by_state(60);

  main_block->mask_by_state(61);

// the rungs of the gate
  for ( int i = -8; i <= 8; i+=4 )
  {
    main_block->draw_line_segment(castle_center+vec(-48,5,i), castle_center+vec(-48,50,i), main_block->get_vox(13, 255, false) );
  }


// the basic shape of the keep
  a = castle_center + vec(-30,  60,  30);
  b = castle_center + vec(-30,   0,  30);
  c = castle_center + vec( 30,  60,  30);
  d = castle_center + vec( 30,   0,  30);
  e = castle_center + vec(-30,  60, -30);
  f = castle_center + vec(-30,   0, -30);
  g = castle_center + vec( 30,  60, -30);
  h = castle_center + vec( 30,   0, -30);

  main_block->draw_quadrilateral_hexahedron(a, b, c, d, e, f, g, h, main_block->get_vox( 60, 255, false) );

// cut out the inside
  a = castle_center + vec(-26,  55,  26);
  b = castle_center + vec(-26,   5,  26);
  c = castle_center + vec( 26,  55,  26);
  d = castle_center + vec( 26,   5,  26);
  e = castle_center + vec(-26,  55, -26);
  f = castle_center + vec(-26,   5, -26);
  g = castle_center + vec( 26,  55, -26);
  h = castle_center + vec( 26,   5, -26);

  main_block->draw_quadrilateral_hexahedron(a, b, c, d, e, f, g, h, main_block->get_vox(57, 1, false) );

// subfloor
  a = castle_center + vec(-26,  7,  26);
  b = castle_center + vec(-26,   5,  26);
  c = castle_center + vec( 26,  7,  26);
  d = castle_center + vec( 26,   5,  26);
  e = castle_center + vec(-26,  7, -26);
  f = castle_center + vec(-26,   5, -26);
  g = castle_center + vec( 26,  7, -26);
  h = castle_center + vec( 26,   5, -26);

  main_block->draw_quadrilateral_hexahedron(a, b, c, d, e, f, g, h, main_block->get_vox( 20, 255, false) );

// red carpet
  a = castle_center + vec(-26,  8,  26);
  b = castle_center + vec(-26,   6,  26);
  c = castle_center + vec( 26,  8,  26);
  d = castle_center + vec( 26,   6,  26);
  e = castle_center + vec(-26,  8, -26);
  f = castle_center + vec(-26,   6, -26);
  g = castle_center + vec( 26,  8, -26);
  h = castle_center + vec( 26,   6, -26);

  main_block->draw_quadrilateral_hexahedron(a, b, c, d, e, f, g, h, main_block->get_vox( 3, 255, false) );


// subfloor
  a = castle_center + vec(-26,  17,  26);
  b = castle_center + vec(-26,   15,  26);
  c = castle_center + vec( 26,  17,  26);
  d = castle_center + vec( 26,   15,  26);
  e = castle_center + vec(-26,  17, -26);
  f = castle_center + vec(-26,   15, -26);
  g = castle_center + vec( 26,  17, -26);
  h = castle_center + vec( 26,   15, -26);

  main_block->draw_quadrilateral_hexahedron(a, b, c, d, e, f, g, h, main_block->get_vox( 20, 255, false) );

// red carpet
  a = castle_center + vec(-26,  18,  26);
  b = castle_center + vec(-26,   16,  26);
  c = castle_center + vec( 26,  18,  26);
  d = castle_center + vec( 26,   16,  26);
  e = castle_center + vec(-26,  18, -26);
  f = castle_center + vec(-26,   16, -26);
  g = castle_center + vec( 26,  18, -26);
  h = castle_center + vec( 26,   16, -26);

  main_block->draw_quadrilateral_hexahedron(a, b, c, d, e, f, g, h, main_block->get_vox( 3, 255, false) );

// subfloor
  a = castle_center + vec(-26,  43,  26);
  b = castle_center + vec(-26,   41,  26);
  c = castle_center + vec( 26,  43,  26);
  d = castle_center + vec( 26,   41,  26);
  e = castle_center + vec(-26,  43, -26);
  f = castle_center + vec(-26,   41, -26);
  g = castle_center + vec( 26,  43, -26);
  h = castle_center + vec( 26,   41, -26);

  main_block->draw_quadrilateral_hexahedron(a, b, c, d, e, f, g, h, main_block->get_vox( 20, 255, false) );

// red carpet
  a = castle_center + vec(-26,  44,  26);
  b = castle_center + vec(-26,   42,  26);
  c = castle_center + vec( 26,  44,  26);
  d = castle_center + vec( 26,   42,  26);
  e = castle_center + vec(-26,  44, -26);
  f = castle_center + vec(-26,   42, -26);
  g = castle_center + vec( 26,  44, -26);
  h = castle_center + vec( 26,   42, -26);

  main_block->draw_quadrilateral_hexahedron(a, b, c, d, e, f, g, h, main_block->get_vox( 3, 255, false) );


  // THE STAIRCASE INSIDE THE KEEP

  vec internal_staircase_location = castle_center + vec(15,8,15);

  main_block->draw_cylinder(internal_staircase_location, internal_staircase_location+vec(0,35,0), 9, main_block->get_vox(57, 1, false) );



  index1 = 0;
  index2 = 1;

  // normalize and multiply to make them all the same lengths
  for(int i = 0; i < 8; i++)
    displacement_vectors[i] = 10.0f * normalize(displacement_vectors[i]);


  for(int i = 0; i < 21; i++)
  {
    // drawing the steps for this level
    main_block->draw_triangle(internal_staircase_location, internal_staircase_location + displacement_vectors[index1], internal_staircase_location + displacement_vectors[index2], 1.5, main_block->get_vox( 20, 255, false) );
    main_block->draw_line_segment(internal_staircase_location + vec(0,0.75,0), internal_staircase_location + displacement_vectors[index1] + vec(0,0.75,0), main_block->get_vox( 21, 255, false) );


    // railing
    main_block->draw_cylinder(internal_staircase_location + displacement_vectors[index1] + vec(0,5,0), internal_staircase_location + displacement_vectors[index2] + vec(0,6.75,0), 1.0, main_block->get_vox( 21, 255, false) );

    // increment the indicies for the displacement vectors
    index1++; index2++;
    if(index1 == 8) index1 = 0;
    if(index2 == 8) index2 = 0;

    // move 'em on up
    internal_staircase_location += vec(0,1.75,0);

  }

  // middle post for the stairs
  main_block->draw_cylinder(internal_staircase_location, internal_staircase_location+vec(0,-35,0), 2, main_block->get_vox(60, 255, false) );


// roof
  a = castle_center + vec(-30,  59,  30);
  b = castle_center + vec(-30,   61,  30);
  c = castle_center + vec( 30,  59,  30);
  d = castle_center + vec( 30,   61,  30);
  e = castle_center + vec(-30,  59, -30);
  f = castle_center + vec(-30,   61, -30);
  g = castle_center + vec( 30,  59, -30);
  h = castle_center + vec( 30,   61, -30);

  main_block->draw_quadrilateral_hexahedron(a, b, c, d, e, f, g, h, main_block->get_vox( 15, 255, false) );


// TREES

  // normalize and multiply to make them all the same lengths
  for(int i = 0; i < 8; i++)
    displacement_vectors[i] = 1.0f * normalize(displacement_vectors[i]);

  main_block->mask_by_state( 57 );
  main_block->mask_invert_mask( ); // mask everything but the air

  vec current_tree_location;
  bool draw_tree = false;
  int treeheight, trianglewidth;

  std::srand(5);

  for(int treex = 0; treex < 512; treex++)
  {
    for(int treez = 0; treez < 256; treez++)
    {

      if(std::rand()%500 == 1)
      {// do a tree
        for(int j = 0; j < 256; j++)
        {// go down to the first grass-containing cell
          current_tree_location = vec(treex, 256-j, treez);

          if(main_block->compare_colors(main_block->get_data_by_vector_index(current_tree_location).color, main_block->palette[25]))
          {
            draw_tree = true;
            break;
          }
        }

        if(treex > (255 - 60) && treex < (255 + 60) && treez > (127 - 60) && treez < (127 + 60)) draw_tree = false;

        //draw the tree
        if(draw_tree)
        {
          cout << "drawing a tree at " << treex << " " << treez << endl;

          treeheight = std::rand()%5;

          index1 = 0;
          index2 = 3;

          switch(treeheight)
          {
            case 0:
              main_block->draw_sphere(current_tree_location+vec(0,20,0), 3.0, main_block->get_vox(64, 255, false) );
              main_block->draw_cylinder(current_tree_location, current_tree_location+vec(0,20,0), 1, main_block->get_vox(21, 255, false) );
              break;
            case 1:
              main_block->draw_sphere(current_tree_location+vec(0,22,0), 4.0, main_block->get_vox(64, 255, false) );
              main_block->draw_cylinder(current_tree_location, current_tree_location+vec(0,22,0), 1.5, main_block->get_vox(21, 255, false) );
              break;
            case 2:
              main_block->draw_sphere(current_tree_location+vec(0,25,0), 5.0, main_block->get_vox(64, 255, false) );
              main_block->draw_cylinder(current_tree_location, current_tree_location+vec(0,25,0), 1.5, main_block->get_vox(21, 255, false) );
              break;
            case 3:
              trianglewidth = 9;
              main_block->draw_cylinder(current_tree_location, current_tree_location+vec(0,28,0), 1.0, main_block->get_vox(21, 255, false) );

              for(int i = 6; i < 36; i+=4)
              {
                // main_block->draw_triangle(current_tree_location+vec(0,i,0), current_tree_location+vec(0,i-5,0)+(float)trianglewidth*displacement_vectors[index1], current_tree_location+vec(0,i-5,0)+(float)trianglewidth*displacement_vectors[index2], 2.0, main_block->get_vox(64, 255, false));
                //
                // index1+=5; index2+=3;
                // if(index1 >= 8) index1 = 0;
                // if(index2 >= 8) index2 = 0;

                main_block->draw_sphere(current_tree_location+vec(0,i,0), trianglewidth, main_block->get_vox(64, 255, false) );


                trianglewidth--;
              }
              break;
            case 4:
              main_block->draw_sphere(current_tree_location+vec(0,32,0), 7.0, main_block->get_vox(64, 255, false) );
              main_block->draw_cylinder(current_tree_location, current_tree_location+vec(0,32,0), 1.75, main_block->get_vox(21, 255, false) );
              break;
            default:
              break;
          }
          draw_tree = false;
        }
      }
    }
  }





//FRAMING
  bool draw_axes = false;
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
