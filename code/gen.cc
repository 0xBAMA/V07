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
void draw_compass_rose();



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


	vec a,b,c,d,e,f,g,h;



	Vox material1  =  main_block->get_vox(58, 255.0, false);
	Vox material2  =  main_block->get_vox(62,  20.0, false);


	//OUTER LAYERS

	for(int x = 223; x < 288; x+=64)
	{
		for(int y = 95; y < 160; y+=64)
		{

			a = vec( x-4, y+4, 256);
			b = vec( x-4, y-4, 256);
			c = vec( x+4, y+4, 256);
			d = vec( x+4, y-4, 256);
			e = vec( x-4, y+4, 0);
			f = vec( x-4, y-4, 0);
			g = vec( x+4, y+4, 0);
			h = vec( x+4, y-4, 0);

			main_block->draw_quadrilateral_hexahedron( a, b, c, d, e, f, g, h, material2);

		}
	}

	for(int x = 223; x < 288; x+=64)
	{
		for(int z = 95; z < 160; z+=64)
		{

			a = vec( x-4, 256, z+4);
			b = vec( x-4,   0, z+4);
			c = vec( x+4, 256, z+4);
			d = vec( x+4,   0, z+4);
			e = vec( x-4, 256, z-4);
			f = vec( x-4,   0, z-4);
			g = vec( x+4, 256, z-4);
			h = vec( x+4,   0, z-4);

			main_block->draw_quadrilateral_hexahedron( a, b, c, d, e, f, g, h, material2);

		}
	}

	for(int y = 95; y < 160; y+=64)
	{
		for(int z = 95; z < 160; z+=64)
		{

			a = vec(   0, y+4, z+4);
			b = vec(   0, y-4, z+4);
			c = vec( 512, y+4, z+4);
			d = vec( 512, y-4, z+4);
			e = vec(   0, y+4, z-4);
			f = vec(   0, y-4, z-4);
			g = vec( 512, y+4, z-4);
			h = vec( 512, y-4, z-4);

			main_block->draw_quadrilateral_hexahedron( a, b, c, d, e, f, g, h, material2);

		}
	}


	//INNER LAYERS

	for(int x = 223; x < 288; x+=64)
	{
		for(int y = 95; y < 160; y+=64)
		{

			a = vec( x-3, y+3, 256);
			b = vec( x-3, y-3, 256);
			c = vec( x+3, y+3, 256);
			d = vec( x+3, y-3, 256);
			e = vec( x-3, y+3, 0);
			f = vec( x-3, y-3, 0);
			g = vec( x+3, y+3, 0);
			h = vec( x+3, y-3, 0);

			main_block->draw_quadrilateral_hexahedron( a, b, c, d, e, f, g, h, material1);

		}
	}

	for(int x = 223; x < 288; x+=64)
	{
		for(int z = 95; z < 160; z+=64)
		{

			a = vec( x-3, 256, z+3);
			b = vec( x-3,   0, z+3);
			c = vec( x+3, 256, z+3);
			d = vec( x+3,   0, z+3);
			e = vec( x-3, 256, z-3);
			f = vec( x-3,   0, z-3);
			g = vec( x+3, 256, z-3);
			h = vec( x+3,   0, z-3);

			main_block->draw_quadrilateral_hexahedron( a, b, c, d, e, f, g, h, material1);

		}
	}

	for(int y = 95; y < 160; y+=64)
	{
		for(int z = 95; z < 160; z+=64)
		{

			a = vec(   0, y+3, z+3);
			b = vec(   0, y-3, z+3);
			c = vec( 512, y+3, z+3);
			d = vec( 512, y-3, z+3);
			e = vec(   0, y+3, z-3);
			f = vec(   0, y-3, z-3);
			g = vec( 512, y+3, z-3);
			h = vec( 512, y-3, z-3);

			main_block->draw_quadrilateral_hexahedron( a, b, c, d, e, f, g, h, material1);

		}
	}

	main_block->mask_all_nonzero();

	main_block->draw_sphere(vec(255.5, 127.5, 127.5), 1000, main_block->get_vox(58, 1.0, false));

	main_block->mask_unmask_all();










//FRAMING
  if( false )
  {
    draw_axes_and_corners();
  }

//COMPASS ROSE
	if(true)
	{
		draw_compass_rose();
	}





  tock = Clock::now();

  cout << endl << endl << "drawing all shapes took " << std::chrono::duration_cast<milliseconds>(tock-tick).count() << " milliseconds" << endl;






  tick = Clock::now();
  main_block->save("current_model/save.png");
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

void draw_compass_rose()
{
	//the compass rose

	main_block->draw_ellipsoid(vec(255.5, 127.5, 127.5), vec(63, 13, 13), main_block->get_vox(62, 20.0, false));
	main_block->draw_ellipsoid(vec(255.5, 127.5, 127.5), vec(13, 63, 13), main_block->get_vox(62, 20.0, false));
	main_block->draw_ellipsoid(vec(255.5, 127.5, 127.5), vec(13, 13, 63), main_block->get_vox(62, 20.0, false));

	main_block->draw_ellipsoid(vec(255.5, 127.5, 127.5), vec(60, 10, 10), main_block->get_vox( 1, 255.0, false));
	main_block->draw_ellipsoid(vec(255.5, 127.5, 127.5), vec(10, 60, 10), main_block->get_vox(23, 255.0, false));
	main_block->draw_ellipsoid(vec(255.5, 127.5, 127.5), vec(10, 10, 60), main_block->get_vox(33, 255.0, false));

	// note:
	// 	a : -x, +y, +z
	// 	b : -x, -y, +z
	// 	c : +x, +y, +z
	// 	d : +x, -y, +z
	// 	e : -x, +y, -z
	// 	f : -x, -y, -z
	// 	g : +x, +y, -z
	// 	h : +x, -y, -z

	vec a = vec( 255.5-20, 127.5+20, 127.5+20);
	vec b = vec( 255.5-20, 127.5-20, 127.5+20);
	vec c = vec( 255.5+20, 127.5+20, 127.5+20);
	vec d = vec( 255.5+20, 127.5-20, 127.5+20);
	vec e = vec( 255.5-20, 127.5+20, 127.5-20);
	vec f = vec( 255.5-20, 127.5-20, 127.5-20);
	vec g = vec( 255.5+20, 127.5+20, 127.5-20);
	vec h = vec( 255.5+20, 127.5-20, 127.5-20);

	main_block->draw_quadrilateral_hexahedron( a, b, c, d, e, f, g, h, main_block->get_vox(58, 1.0, false));
}
