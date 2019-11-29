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







  Vox whiteSquare  =  main_block->get_vox(27, 255.0, false);
  Vox whitePiece   =  main_block->get_vox(18, 50.0, false);

  Vox blackSquare  =  main_block->get_vox(28, 255.0, false);
  Vox blackPiece   =  main_block->get_vox(20, 50.0, false);

  Vox ambient   =  main_block->get_vox(35, 1.0, false);





  typedef struct square_t{
    vec center;
    int x;
    int y;
  }square;

  square board[8][8];






  //  |------|------|------|------|------|------|------|------|




  main_block->draw_sphere(vec(200, 127.5, 127.5), 405, ambient);



  vec ao,bo,co,doo,eo,fo,go,ho;

  ao = vec(-15, 3, 15);
  bo = vec(-15,-3, 15);
  co = vec( 15, 3, 15);
  doo = vec( 15,-3, 15);
  eo = vec(-15, 3,-15);
  fo = vec(-15,-3,-15);
  go = vec( 15, 3,-15);
  ho = vec( 15,-3,-15);



  for(int x = 0; x < 8; x++)
  {
    for(int y = 0; y < 8; y++)
    {

      vec loc = vec(x*30 + 24, 30, y*30 + 24);


      board[x][y].x = x;
      board[x][y].y = y;

      board[x][y].center = loc;




      if(x%2)
      {
        if(y%2)
        {
          // main_block->draw_sphere(loc, 5, whiteSquare);
          main_block->draw_quadrilateral_hexahedron(loc+ao, loc+bo, loc+co, loc+doo, loc+eo, loc+fo, loc+go, loc+ho, whiteSquare);
        }
        else
        {
          // main_block->draw_sphere(loc, 5, blackSquare);
          main_block->draw_quadrilateral_hexahedron(loc+ao, loc+bo, loc+co, loc+doo, loc+eo, loc+fo, loc+go, loc+ho, blackSquare);
        }
      }
      else
      {
        if(y%2)
        {
          // main_block->draw_sphere(loc, 5, blackSquare);
          main_block->draw_quadrilateral_hexahedron(loc+ao, loc+bo, loc+co, loc+doo, loc+eo, loc+fo, loc+go, loc+ho, blackSquare);
        }
        else
        {
          // main_block->draw_sphere(loc, 5, whiteSquare);
          main_block->draw_quadrilateral_hexahedron(loc+ao, loc+bo, loc+co, loc+doo, loc+eo, loc+fo, loc+go, loc+ho, whiteSquare);
        }
      }
    }
  }







  for(int i = 0; i < 8; i++)
  {
    //pawns
    main_block->draw_sphere(board[i][1].center + vec(0,7,0), 7, blackPiece);
    main_block->draw_sphere(board[i][1].center + vec(0,10,0), 5, ambient);
    main_block->draw_sphere(board[i][1].center + vec(0,15,0), 2.5, blackPiece);

    switch(i)
    {
      case 0:
      case 7:

      //ROOKS

      ao = vec(-5, 7, 5);
      bo = vec(-5,-7, 5);
      co = vec( 5, 7, 5);
      doo = vec( 5,-7, 5);
      eo = vec(-5, 7,-5);
      fo = vec(-5,-7,-5);
      go = vec( 5, 7,-5);
      ho = vec( 5,-7,-5);

        main_block->draw_sphere(board[i][0].center + vec(0,7,0), 7, blackPiece);
        main_block->draw_sphere(board[i][0].center + vec(0,10,0), 5, ambient);

        main_block->draw_quadrilateral_hexahedron(board[i][0].center + vec(0,15,0)+ao, board[i][0].center + vec(0,15,0)+bo, board[i][0].center + vec(0,15,0)+co, board[i][0].center + vec(0,15,0)+doo, board[i][0].center + vec(0,15,0)+eo, board[i][0].center + vec(0,15,0)+fo, board[i][0].center + vec(0,15,0)+go, board[i][0].center + vec(0,15,0)+ho, blackPiece);

        break;

      case 1:
      case 6:

      //knight

      ao = vec(-3, 7, 3);
      bo = vec(-3,-7, 3);
      co = vec( 3, 7, 3);
      doo = vec( 3,-7, 3);
      eo = vec(-3, 7,-3);
      fo = vec(-3,-7,-3);
      go = vec( 3, 7,-3);
      ho = vec( 3,-7,-3);

        main_block->draw_sphere(board[i][0].center + vec(0,7,0), 7, blackPiece);
        main_block->draw_sphere(board[i][0].center + vec(0,10,0), 5, ambient);

        main_block->draw_quadrilateral_hexahedron(board[i][0].center + vec(0,15,0)+ao, board[i][0].center + vec(0,15,0)+bo, board[i][0].center + vec(0,15,0)+co, board[i][0].center + vec(0,15,0)+doo, board[i][0].center + vec(0,15,0)+eo, board[i][0].center + vec(0,15,0)+fo, board[i][0].center + vec(0,15,0)+go, board[i][0].center + vec(0,15,0)+ho, blackPiece);


        ao = vec(-3, 2, 8);
        bo = vec(-3,-5, 8);
        co = vec( 3, 2, 8);
        doo = vec( 3,-5, 8);
        eo = vec(-3, 4,-8);
        fo = vec(-3,-4,-8);
        go = vec( 3, 4,-8);
        ho = vec( 3,-4,-8);

        main_block->draw_quadrilateral_hexahedron(board[i][0].center + vec(0,20,4)+ao, board[i][0].center + vec(0,20,4)+bo, board[i][0].center + vec(0,20,4)+co, board[i][0].center + vec(0,20,4)+doo, board[i][0].center + vec(0,20,4)+eo, board[i][0].center + vec(0,20,4)+fo, board[i][0].center + vec(0,20,4)+go, board[i][0].center + vec(0,20,4)+ho, blackPiece);










        main_block->draw_sphere(board[i][0].center + vec(0,17,0), 5, blackPiece);

        break;


      default:
        break;


    }


  }



  for(int i = 0; i < 8; i++)
  {
    main_block->draw_sphere(board[i][6].center + vec(0,7,0), 7, whitePiece);
    main_block->draw_sphere(board[i][6].center + vec(0,10,0), 5, ambient);
    main_block->draw_sphere(board[i][6].center + vec(0,15,0), 2.5, whitePiece);
  }
















  cout << "done" << endl;


//FRAMING
  if( false )
  {
    draw_axes_and_corners();
  }

//COMPASS ROSE
	if( false )
	{
		draw_compass_rose();
	}





  tock = Clock::now();

  cout << endl << endl << "drawing all shapes took " << std::chrono::duration_cast<milliseconds>(tock-tick).count() << " milliseconds" << endl;






  tick = Clock::now();
  main_block->save("current_model/save.png");
  tock = Clock::now();

  std::cout << "saving block to file took " << std::chrono::duration_cast<milliseconds>(tock-tick).count() << " milliseconds" << endl;




  // tick = Clock::now();
  // main_block->display("generate_preview.png",  3.14, 3.14/3.0, 3.14/3.0, 0.4, false);
  // tock = Clock::now();

  // std::cout << "generate's renderer took " << std::chrono::duration_cast<milliseconds>(tock-tick).count() << " milliseconds" << endl << endl << endl;

  return 0;
}


void draw_axes_and_corners()
{

//   main_block->mask_unmask_all();
//
// // along the x axes
//   main_block->draw_cylinder(vec(0,0,0), vec(init_x,0,0),1.5, main_block->get_vox(1,255,false));
//   main_block->draw_cylinder(vec(0,0,init_z-1), vec(init_x,0,init_z-1),1.5, main_block->get_vox(1,255,false));
//   main_block->draw_cylinder(vec(0,init_y-1,0), vec(init_x,init_y-1,0),1.5, main_block->get_vox(1,255,false));
//   main_block->draw_cylinder(vec(0,init_y-1,init_z-1), vec(init_x,init_y-1,init_z-1),1.5, main_block->get_vox(1,255,false));
//
// // along the y axes
//   main_block->draw_cylinder(vec(0,0,0), vec(0,init_y,0),1.5, main_block->get_vox(23,255,false));
//   main_block->draw_cylinder(vec(init_x-1,0,0), vec(init_x-1,init_y,0),1.5, main_block->get_vox(23,255,false));
//   main_block->draw_cylinder(vec(init_x-1,0,init_z-1), vec(init_x-1,init_y,init_z-1),1.5, main_block->get_vox(23,255,false));
//   main_block->draw_cylinder(vec(0,0,init_z-1), vec(0,init_y,init_z-1),1.5, main_block->get_vox(23,255,false));
//
// // along the z axes
//   main_block->draw_cylinder(vec(0,0,0), vec(0,0,init_z),1.5, main_block->get_vox(33,255,false));
//   main_block->draw_cylinder(vec(init_x-1,0,0), vec(init_x-1,0,init_z),1.5, main_block->get_vox(33,255,false));
//   main_block->draw_cylinder(vec(0,init_y-1,0), vec(0,init_y-1,init_z),1.5, main_block->get_vox(33,255,false));
//   main_block->draw_cylinder(vec(init_x-1,init_y-1,0), vec(init_x-1,init_y-1,init_z),1.5, main_block->get_vox(33,255,false));
//
// // points at the corners
//   main_block->draw_sphere(vec(0,0,0), 3, main_block->get_vox(62,255,false));
//   main_block->draw_sphere(vec(0,0,init_z-1), 3, main_block->get_vox(62,255,false));
//   main_block->draw_sphere(vec(0,init_y-1,0), 3, main_block->get_vox(62,255,false));
//   main_block->draw_sphere(vec(init_x-1,0,0), 3, main_block->get_vox(62,255,false));
//
//   main_block->draw_sphere(vec(init_x-1,init_y-1,0), 3, main_block->get_vox(62,255,false));
//   main_block->draw_sphere(vec(0,init_y-1,init_z-1), 3, main_block->get_vox(62,255,false));
//   main_block->draw_sphere(vec(init_x-1,0,init_z-1), 3, main_block->get_vox(62,255,false));
//   main_block->draw_sphere(vec(init_x-1,init_y-1,init_z-1), 3, main_block->get_vox(62,255,false));


	main_block->mask_unmask_all();

	// along the x axes
	main_block->draw_cylinder(vec(0,0,0), vec(init_x,0,0),1.0, main_block->get_vox(1,255,false));
	main_block->draw_cylinder(vec(0,0,init_z-1), vec(init_x,0,init_z-1),1.0, main_block->get_vox(1,255,false));
	main_block->draw_cylinder(vec(0,init_y-1,0), vec(init_x,init_y-1,0),1.0, main_block->get_vox(1,255,false));
	main_block->draw_cylinder(vec(0,init_y-1,init_z-1), vec(init_x,init_y-1,init_z-1),1.0, main_block->get_vox(1,255,false));

	// along the y axes
	main_block->draw_cylinder(vec(0,0,0), vec(0,init_y,0),1.0, main_block->get_vox(23,255,false));
	main_block->draw_cylinder(vec(init_x-1,0,0), vec(init_x-1,init_y,0),1.0, main_block->get_vox(23,255,false));
	main_block->draw_cylinder(vec(init_x-1,0,init_z-1), vec(init_x-1,init_y,init_z-1),1.0, main_block->get_vox(23,255,false));
	main_block->draw_cylinder(vec(0,0,init_z-1), vec(0,init_y,init_z-1),1.0, main_block->get_vox(23,255,false));

	// along the z axes
	main_block->draw_cylinder(vec(0,0,0), vec(0,0,init_z),1.0, main_block->get_vox(33,255,false));
	main_block->draw_cylinder(vec(init_x-1,0,0), vec(init_x-1,0,init_z),1.0, main_block->get_vox(33,255,false));
	main_block->draw_cylinder(vec(0,init_y-1,0), vec(0,init_y-1,init_z),1.0, main_block->get_vox(33,255,false));
	main_block->draw_cylinder(vec(init_x-1,init_y-1,0), vec(init_x-1,init_y-1,init_z),1.0, main_block->get_vox(33,255,false));

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
