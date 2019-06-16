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


	vec a,b,c,d,e,f,g,h;

	// note:
	// 	a : -x, +y, +z
	// 	b : -x, -y, +z
	// 	c : +x, +y, +z
	// 	d : +x, -y, +z
	// 	e : -x, +y, -z
	// 	f : -x, -y, -z
	// 	g : +x, +y, -z
	// 	h : +x, -y, -z

	Vox material1  =  main_block->get_vox(58, 255.0, false);
	Vox material2  =  main_block->get_vox(27, 255.0, false);
	Vox material3  =  main_block->get_vox(28, 255.0, false);
	Vox rust       =  main_block->get_vox(10, 255.0, false);
	Vox rust2      =  main_block->get_vox( 9,   5.0, false);
	Vox atmosphere =  main_block->get_vox(58,   3.0, false);
	Vox water      =  main_block->get_vox(40,  20.0, false);
	Vox shroud     =  main_block->get_vox(49,  20.0, false);




	cout << endl << "starting " << endl;




	for(int x = 31; x < 512; x+=64)
	{
		for(int y = 31; y < 256; y+=64)
		{

			a = vec( x-7, y+7, 256);
			b = vec( x-7, y-7, 256);
			c = vec( x+7, y+7, 256);
			d = vec( x+7, y-7, 256);
			e = vec( x-7, y+7, 0);
			f = vec( x-7, y-7, 0);
			g = vec( x+7, y+7, 0);
			h = vec( x+7, y-7, 0);

			main_block->draw_quadrilateral_hexahedron( a, b, c, d, e, f, g, h, shroud);

		}
	}

	cout << "xy plane done" << endl;

	for(int x = 31; x < 512; x+=64)
	{
		for(int z = 31; z < 256; z+=64)
		{

			a = vec( x-7, 256, z+7);
			b = vec( x-7,   0, z+7);
			c = vec( x+7, 256, z+7);
			d = vec( x+7,   0, z+7);
			e = vec( x-7, 256, z-7);
			f = vec( x-7,   0, z-7);
			g = vec( x+7, 256, z-7);
			h = vec( x+7,   0, z-7);

			main_block->draw_quadrilateral_hexahedron( a, b, c, d, e, f, g, h, shroud);

		}
	}

	cout << "xz plane done" << endl;

	for(int y = 31; y < 256; y+=64)
	{
		for(int z = 31; z < 256; z+=64)
		{

			a = vec(   0, y+7, z+7);
			b = vec(   0, y-7, z+7);
			c = vec( 512, y+7, z+7);
			d = vec( 512, y-7, z+7);
			e = vec(   0, y+7, z-7);
			f = vec(   0, y-7, z-7);
			g = vec( 512, y+7, z-7);
			h = vec( 512, y-7, z-7);

			main_block->draw_quadrilateral_hexahedron( a, b, c, d, e, f, g, h, shroud);

		}
	}

	cout << "yz plane done" << endl;


	cout << endl << "moving to outer layers" << endl << endl;

	//OUTER LAYERS

	for(int x = 31; x < 512; x+=64)
	{
		for(int y = 31; y < 256; y+=64)
		{

			a = vec( x-5, y+5, 256);
			b = vec( x-5, y-5, 256);
			c = vec( x+5, y+5, 256);
			d = vec( x+5, y-5, 256);
			e = vec( x-5, y+5, 0);
			f = vec( x-5, y-5, 0);
			g = vec( x+5, y+5, 0);
			h = vec( x+5, y-5, 0);

			main_block->draw_quadrilateral_hexahedron( a, b, c, d, e, f, g, h, material2);

		}
	}

	cout << "xy plane done" << endl;

	for(int x = 31; x < 512; x+=64)
	{
		for(int z = 31; z < 256; z+=64)
		{

			a = vec( x-5, 256, z+5);
			b = vec( x-5,   0, z+5);
			c = vec( x+5, 256, z+5);
			d = vec( x+5,   0, z+5);
			e = vec( x-5, 256, z-5);
			f = vec( x-5,   0, z-5);
			g = vec( x+5, 256, z-5);
			h = vec( x+5,   0, z-5);

			main_block->draw_quadrilateral_hexahedron( a, b, c, d, e, f, g, h, material2);

		}
	}

	cout << "xz plane done" << endl;

	for(int y = 31; y < 256; y+=64)
	{
		for(int z = 31; z < 256; z+=64)
		{

			a = vec(   0, y+5, z+5);
			b = vec(   0, y-5, z+5);
			c = vec( 512, y+5, z+5);
			d = vec( 512, y-5, z+5);
			e = vec(   0, y+5, z-5);
			f = vec(   0, y-5, z-5);
			g = vec( 512, y+5, z-5);
			h = vec( 512, y-5, z-5);

			main_block->draw_quadrilateral_hexahedron( a, b, c, d, e, f, g, h, material2);

		}
	}

	cout << "yz plane done" << endl;








	cout << endl << "moving to inner layers" << endl << endl;


	//INNER LAYERS

	for(int x = 31; x < 512; x+=64)
	{
		for(int y = 31; y < 256; y+=64)
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

	cout << "xy plane done" << endl;

	for(int x = 31; x < 512; x+=64)
	{
		for(int z = 31; z < 256; z+=64)
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

	cout << "xz plane done" << endl;

	for(int y = 31; y < 256; y+=64)
	{
		for(int z = 31; z < 256; z+=64)
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

	cout << "yz plane done" << endl << endl;;

	main_block->mask_by_state(27);

	main_block->mask_invert_mask();

	main_block->draw_perlin_noise( 0.1, 0.3, material3);

	main_block->draw_perlin_noise( 0.1, 0.25, rust);

	main_block->draw_perlin_noise( 0.3, 0.4, rust2);

	main_block->mask_unmask_all();

	main_block->mask_all_nonzero();

	main_block->draw_sphere(vec(255.5, 127.5, 127.5), 1000, atmosphere);

	a = vec(   0,   175, 256);
	b = vec(   0,     0, 256);
	c = vec( 512,   175, 256);
	d = vec( 512,     0, 256);
	e = vec(   0,   175, 0);
	f = vec(   0,     0, 0);
	g = vec( 512,   175, 0);
	h = vec( 512,     0, 0);

	main_block->draw_quadrilateral_hexahedron( a, b, c, d, e, f, g, h, water);

	main_block->mask_unmask_all();

	main_block->mask_by_state(40);

	main_block->mask_invert_mask();

	main_block->draw_perlin_noise( 0.3, 0.4, atmosphere);





//FRAMING
  bool draw_axes = false;
  if( draw_axes )
  {
    draw_axes_and_corners();
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
