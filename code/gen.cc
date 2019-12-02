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




int main(int argc, char const *argv[])
{
  char numstring[5];//used when rendering multiple frames

  main_block = new Voraldo();
  main_block->init_block(dimensions);

  vec center = vec(floor(init_x/2),floor(init_y/2),floor(init_z/2));

  auto tick = Clock::now(); //variable to hold start of the timekeeping
  auto tock = Clock::now(); //variable to hold end of timekeeping



  tick = Clock::now();






  //
  // Vox whiteSquare  =  main_block->get_vox(27, 255.0, false);
  // Vox whitePiece   =  main_block->get_vox(18, 50.0, false);
  //
  // Vox blackSquare  =  main_block->get_vox(28, 255.0, false);
  // Vox blackPiece   =  main_block->get_vox(20, 50.0, false);
  //
  // Vox ambient   =  main_block->get_vox(35, 1.0, false);
  //
  //
  //
  //
  //
  // typedef struct square_t{
  //   vec center;
  //   int x;
  //   int y;
  // }square;
  //
  // square board[8][8];
  //
  //
  //
  //
  //
  //
  // //  |------|------|------|------|------|------|------|------|
  //
  //
  //
  //
  // main_block->draw_sphere(vec(200, 127.5, 127.5), 405, ambient);
  //
  //
  //
  // vec ao,bo,co,doo,eo,fo,go,ho;
  //
  // ao = vec(-15, 3, 15);
  // bo = vec(-15,-3, 15);
  // co = vec( 15, 3, 15);
  // doo = vec( 15,-3, 15);
  // eo = vec(-15, 3,-15);
  // fo = vec(-15,-3,-15);
  // go = vec( 15, 3,-15);
  // ho = vec( 15,-3,-15);
  //
  //
  //
  // for(int x = 0; x < 8; x++)
  // {
  //   for(int y = 0; y < 8; y++)
  //   {
  //
  //     vec loc = vec(x*30 + 24, 30, y*30 + 24);
  //
  //
  //     board[x][y].x = x;
  //     board[x][y].y = y;
  //
  //     board[x][y].center = loc;
  //
  //
  //
  //
  //     if(x%2)
  //     {
  //       if(y%2)
  //       {
  //         // main_block->draw_sphere(loc, 5, whiteSquare);
  //         main_block->draw_quadrilateral_hexahedron(loc+ao, loc+bo, loc+co, loc+doo, loc+eo, loc+fo, loc+go, loc+ho, whiteSquare);
  //       }
  //       else
  //       {
  //         // main_block->draw_sphere(loc, 5, blackSquare);
  //         main_block->draw_quadrilateral_hexahedron(loc+ao, loc+bo, loc+co, loc+doo, loc+eo, loc+fo, loc+go, loc+ho, blackSquare);
  //       }
  //     }
  //     else
  //     {
  //       if(y%2)
  //       {
  //         // main_block->draw_sphere(loc, 5, blackSquare);
  //         main_block->draw_quadrilateral_hexahedron(loc+ao, loc+bo, loc+co, loc+doo, loc+eo, loc+fo, loc+go, loc+ho, blackSquare);
  //       }
  //       else
  //       {
  //         // main_block->draw_sphere(loc, 5, whiteSquare);
  //         main_block->draw_quadrilateral_hexahedron(loc+ao, loc+bo, loc+co, loc+doo, loc+eo, loc+fo, loc+go, loc+ho, whiteSquare);
  //       }
  //     }
  //   }
  // }
  //
  //
  //
  //
  //
  //
  //
  // for(int i = 0; i < 8; i++)
  // {
  //   //pawns
  //   main_block->draw_sphere(board[i][1].center + vec(0,7,0), 7, blackPiece);
  //   main_block->draw_sphere(board[i][1].center + vec(0,10,0), 5, ambient);
  //   main_block->draw_sphere(board[i][1].center + vec(0,15,0), 2.5, blackPiece);
  //
  //
  //   main_block->draw_sphere(board[i][1].center + vec(0,7,0), 7, blackPiece);
  //   main_block->draw_sphere(board[i][1].center + vec(0,10,0), 5, ambient);
  //   main_block->draw_sphere(board[i][1].center + vec(0,15,0), 2.5, blackPiece);
  //
  //
  //   //second row bases
  //   main_block->draw_sphere(board[i][0].center + vec(0,7,0), 7, blackPiece);
  //   main_block->draw_sphere(board[i][0].center + vec(0,10,0), 5, ambient);
  //
  //
  //   switch(i)
  //   {
  //     case 0:
  //     case 7:
  //
  //     //ROOKS
  //
  //     ao = vec(-4.5, 4, 4.5);
  //     bo = vec(-3.5,-7, 3.5);
  //     co = vec( 4.5, 4, 4.5);
  //     doo = vec( 3.5,-7, 3.5);
  //     eo = vec(-4.5, 4,-4.5);
  //     fo = vec(-3.5,-7,-3.5);
  //     go = vec( 4.5, 4,-4.5);
  //     ho = vec( 3.5,-7,-3.5);
  //
  //
  //       main_block->draw_quadrilateral_hexahedron(board[i][0].center + vec(0,15,0)+ao, board[i][0].center + vec(0,15,0)+bo, board[i][0].center + vec(0,15,0)+co, board[i][0].center + vec(0,15,0)+doo, board[i][0].center + vec(0,15,0)+eo, board[i][0].center + vec(0,15,0)+fo, board[i][0].center + vec(0,15,0)+go, board[i][0].center + vec(0,15,0)+ho, blackPiece);
  //
  //       main_block->draw_quadrilateral_hexahedron(board[i][0].center + vec(0,20,0)+ao, board[i][0].center + vec(0,20,0)+bo, board[i][0].center + vec(0,20,0)+co, board[i][0].center + vec(0,20,0)+doo, board[i][0].center + vec(0,20,0)+eo, board[i][0].center + vec(0,20,0)+fo, board[i][0].center + vec(0,20,0)+go, board[i][0].center + vec(0,20,0)+ho, ambient);
  //
  //
  //
  //
  //
  //
  //     main_block->draw_quadrilateral_hexahedron(board[i][7].center + vec(0,15,0)+ao, board[i][7].center + vec(0,15,0)+bo, board[i][7].center + vec(0,15,0)+co, board[i][7].center + vec(0,15,0)+doo, board[i][7].center + vec(0,15,0)+eo, board[i][7].center + vec(0,15,0)+fo, board[i][7].center + vec(0,15,0)+go, board[i][7].center + vec(0,15,0)+ho, whitePiece);
  //
  //     main_block->draw_quadrilateral_hexahedron(board[i][7].center + vec(0,20,0)+ao, board[i][7].center + vec(0,20,0)+bo, board[i][7].center + vec(0,20,0)+co, board[i][7].center + vec(0,20,0)+doo, board[i][7].center + vec(0,20,0)+eo, board[i][7].center + vec(0,20,0)+fo, board[i][7].center + vec(0,20,0)+go, board[i][7].center + vec(0,20,0)+ho, ambient);
  //
  //       break;
  //
  //     case 1:
  //     case 6:
  //
  //     //knight
  //
  //
  //     main_block->draw_sphere(board[i][0].center + vec(0,15,0), 3, blackPiece);
  //     main_block->draw_sphere(board[i][0].center + vec(0,16,-4), 2, blackPiece);
  //     main_block->draw_sphere(board[i][0].center + vec(0,17,-5), 2, blackPiece);
  //     main_block->draw_sphere(board[i][0].center + vec(0,14,-6), 1, blackPiece);
  //
  //     main_block->draw_sphere(board[i][0].center + vec(0,16,-1), 3, blackPiece);
  //     main_block->draw_sphere(board[i][0].center + vec(0,17,-3), 2, blackPiece);
  //     main_block->draw_sphere(board[i][0].center + vec(0,18,-4), 2, blackPiece);
  //     main_block->draw_sphere(board[i][0].center + vec(0,17,-5), 1, blackPiece);
  //
  //     main_block->draw_sphere(board[i][0].center + vec(0,17,-3), 3, blackPiece);
  //     main_block->draw_sphere(board[i][0].center + vec(0,18,-4), 2, blackPiece);
  //     main_block->draw_sphere(board[i][0].center + vec(0,19,-5), 2, blackPiece);
  //     main_block->draw_sphere(board[i][0].center + vec(0,18,-7), 1, blackPiece);
  //
  //
  //
  //
  //     main_block->draw_sphere(board[i][7].center + vec(0,15,0), 3, whitePiece);
  //     main_block->draw_sphere(board[i][7].center + vec(0,16,-4), 2, whitePiece);
  //     main_block->draw_sphere(board[i][7].center + vec(0,17,-5), 2, whitePiece);
  //     main_block->draw_sphere(board[i][7].center + vec(0,14,-6), 1, whitePiece);
  //
  //     main_block->draw_sphere(board[i][7].center + vec(0,16,-1), 3, whitePiece);
  //     main_block->draw_sphere(board[i][7].center + vec(0,17,-3), 2, whitePiece);
  //     main_block->draw_sphere(board[i][7].center + vec(0,18,-4), 2, whitePiece);
  //     main_block->draw_sphere(board[i][7].center + vec(0,17,-5), 1, whitePiece);
  //
  //     main_block->draw_sphere(board[i][7].center + vec(0,17,-3), 3, whitePiece);
  //     main_block->draw_sphere(board[i][7].center + vec(0,18,-4), 2, whitePiece);
  //     main_block->draw_sphere(board[i][7].center + vec(0,19,-5), 2, whitePiece);
  //     main_block->draw_sphere(board[i][7].center + vec(0,18,-7), 1, whitePiece);
  //
  //
  //
  //
  //       break;
  //
  //
  //     case 2:
  //     case 5:
  //
  //       ao = vec(-3, 9, 3);
  //       bo = vec(-3,-9, 3);
  //       co = vec( 3, 9, 3);
  //       doo = vec( 3,-9, 3);
  //       eo = vec(-3, 9,-3);
  //       fo = vec(-3,-9,-3);
  //       go = vec( 3, 9,-3);
  //       ho = vec( 3,-9,-3);
  //
  //
  //
  //       main_block->draw_quadrilateral_hexahedron(board[i][0].center + vec(0,15,0)+ao, board[i][0].center + vec(0,15,0)+bo, board[i][0].center + vec(0,15,0)+co, board[i][0].center + vec(0,15,0)+doo, board[i][0].center + vec(0,15,0)+eo, board[i][0].center + vec(0,15,0)+fo, board[i][0].center + vec(0,15,0)+go, board[i][0].center + vec(0,15,0)+ho, blackPiece);
  //
  //
  //       main_block->draw_sphere(board[i][0].center + vec(0,19,0), 4, blackPiece);
  //       main_block->draw_sphere(board[i][0].center + vec(0,23,0), 3, blackPiece);
  //       main_block->draw_sphere(board[i][0].center + vec(0,26,0), 2, blackPiece);
  //
  //
  //
  //       main_block->draw_quadrilateral_hexahedron(board[i][7].center + vec(0,15,0)+ao, board[i][7].center + vec(0,15,0)+bo, board[i][7].center + vec(0,15,0)+co, board[i][7].center + vec(0,15,0)+doo, board[i][7].center + vec(0,15,0)+eo, board[i][7].center + vec(0,15,0)+fo, board[i][7].center + vec(0,15,0)+go, board[i][7].center + vec(0,15,0)+ho, whitePiece);
  //
  //
  //       main_block->draw_sphere(board[i][7].center + vec(0,19,0), 4, whitePiece);
  //       main_block->draw_sphere(board[i][7].center + vec(0,23,0), 3, whitePiece);
  //       main_block->draw_sphere(board[i][7].center + vec(0,26,0), 2, whitePiece);
  //
  //
  //
  //       break;
  //
  //
  //       case 3:
  //
  //
  //         main_block->draw_regular_icosahedron(30,3,5, 4, board[i][0].center + vec(0,26,0),blackPiece, 2, blackPiece, 2,  blackSquare);
  //
  //         main_block->draw_regular_icosahedron(30,3,5, 4, board[i][7].center + vec(0,26,0),whitePiece, 2, whitePiece, 2,  whiteSquare);
  //
  //
  //
  //         break;
  //
  //       case 4:
  //
  //         main_block->draw_regular_icosahedron(30,93,50, 3, board[i][0].center + vec(0,26,0),blackPiece, 2, blackPiece, 2,  blackSquare);
  //
  //         main_block->draw_regular_icosahedron(30,93,50, 3, board[i][0].center + vec(0,26,0),whitePiece, 2, whitePiece, 2,  whiteSquare);
  //
  //
  //         break;
  //
  //
  //
  //
  //
  //
  //
  //
  //     default:
  //       break;
  //
  //
  //   }
  //
  //
  // }
  //
  //
  //
  // for(int i = 0; i < 8; i++)
  // {
  //   main_block->draw_sphere(board[i][6].center + vec(0,7,0), 7, whitePiece);
  //   main_block->draw_sphere(board[i][6].center + vec(0,10,0), 5, ambient);
  //   main_block->draw_sphere(board[i][6].center + vec(0,15,0), 2.5, whitePiece);
  // }
  //
  //
  //
  //






  // Vox all_edge_material_0  =  main_block->get_vox(27, 255.0, false);
  // Vox all_edge_material_1  =  main_block->get_vox(27, 245.0, false);
  // Vox all_edge_material_2  =  main_block->get_vox(27, 255.0/2, false);
  // Vox all_edge_material_3  =  main_block->get_vox(28, 255.0/3, false);
  // Vox all_edge_material_4  =  main_block->get_vox(28, 255.0/4, false);
  // Vox all_edge_material_5  =  main_block->get_vox(28, 255.0/5, false);
  // Vox all_edge_material_6  =  main_block->get_vox(29, 255.0/6, false);
  // Vox all_edge_material_7  =  main_block->get_vox(29, 255.0/7, false);
  // Vox all_edge_material_8  =  main_block->get_vox(29, 255.0/8, false);
  // Vox all_edge_material_9  =  main_block->get_vox(30, 255.0/9, false);
  // Vox all_edge_material_10  =  main_block->get_vox(30, 255.0/10, false);
  //
  // Vox mst_edge_material_0  =  main_block->get_vox(12, 255.0, false);
  // Vox mst_edge_material_1  =  main_block->get_vox(12, 245.0, false);
  // Vox mst_edge_material_2  =  main_block->get_vox(12, 255.0/2, false);
  // Vox mst_edge_material_3  =  main_block->get_vox(14, 255.0/3, false);
  // Vox mst_edge_material_4  =  main_block->get_vox(14, 255.0/4, false);
  // Vox mst_edge_material_5  =  main_block->get_vox(14, 255.0/5, false);
  // Vox mst_edge_material_6  =  main_block->get_vox(44, 255.0/6, false);
  // Vox mst_edge_material_7  =  main_block->get_vox(44, 255.0/7, false);
  // Vox mst_edge_material_8  =  main_block->get_vox(44, 255.0/8, false);
  // Vox mst_edge_material_9  =  main_block->get_vox(18, 255.0/9, false);
  // Vox mst_edge_material_10  =  main_block->get_vox(18, 255.0/10, false);


  Vox all_edge_material  =  main_block->get_vox(41, 3, false);

  Vox mst_edge_material  =  main_block->get_vox(12, 200.0, false);

  Vox vertex_material  =  main_block->get_vox(15, 255.0/3, false);

  Vox ambient_material  =  main_block->get_vox(10, 1, false);

  main_block->draw_sphere(glm::vec3(0,0,0), 1000, ambient_material);







  cout << "writing 543 voraldo commands" << endl;
  main_block->draw_cylinder(glm::vec3(251.354, 80.2382, 115.445),   glm::vec3(251.479, 50.5024, 140.739), 0.618, all_edge_material);
  cout << "\r0 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(281.573, 151.994, 118.424),   glm::vec3(274.759, 110.74, 102.544), 0.618, all_edge_material);
  cout << "\r1 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(226.462, 156.077, 93.9447),   glm::vec3(248.645, 169.631, 161.017), 0.618, all_edge_material);
  cout << "\r2 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(267.546, 111.663, 156.52),   glm::vec3(201.551, 92.8714, 89.0439), 0.618, all_edge_material);
  cout << "\r3 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(251.354, 80.2382, 115.445),   glm::vec3(274.759, 110.74, 102.544), 0.618, all_edge_material);
  cout << "\r4 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(233.132, 95.7902, 158.741),   glm::vec3(270.734, 136.763, 116.777), 0.618, all_edge_material);
  cout << "\r5 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(173.763, 139.293, 155.746),   glm::vec3(289.813, 77.1727, 178.895), 0.618, all_edge_material);
  cout << "\r6 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(261.875, 118.151, 115.041),   glm::vec3(199.958, 136.418, 146.237), 0.618, all_edge_material);
  cout << "\r7 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(215.736, 113.014, 88.8605),   glm::vec3(219.85, 103.914, 152.149), 0.618, all_edge_material);
  cout << "\r8 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(229.842, 130.191, 142.118),   glm::vec3(324.078, 174.582, 137.923), 0.618, all_edge_material);
  cout << "\r9 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(230.611, 147.359, 152.454),   glm::vec3(325.47, 123.933, 144.325), 0.618, all_edge_material);
  cout << "\r10 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(274.463, 192.557, 121.335),   glm::vec3(208.791, 115.508, 110.194), 0.618, all_edge_material);
  cout << "\r11 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(268.698, 129.244, 112.916),   glm::vec3(324.078, 174.582, 137.923), 0.618, all_edge_material);
  cout << "\r12 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(282.586, 101.719, 155.77),   glm::vec3(296.068, 154.366, 120.41), 0.618, all_edge_material);
  cout << "\r13 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(229.842, 130.191, 142.118),   glm::vec3(295.481, 92.2876, 166.223), 0.618, all_edge_material);
  cout << "\r14 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(299.947, 97.1689, 155.855),   glm::vec3(208.791, 115.508, 110.194), 0.618, all_edge_material);
  cout << "\r15 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(249.92, 139.51, 137.883),   glm::vec3(268.213, 112.811, 174.18), 0.618, all_edge_material);
  cout << "\r16 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(295.142, 127.957, 145.268),   glm::vec3(251.354, 80.2382, 115.445), 0.618, all_edge_material);
  cout << "\r17 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(243.085, 150.2, 154.328),   glm::vec3(278.167, 117.29, 130.335), 0.618, all_edge_material);
  cout << "\r18 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(182.219, 136.619, 144.539),   glm::vec3(219.697, 112.623, 133.141), 0.618, all_edge_material);
  cout << "\r19 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(307.501, 76.8321, 162.574),   glm::vec3(213.8, 132.886, 133.383), 0.618, all_edge_material);
  cout << "\r20 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(205.859, 104.949, 128.15),   glm::vec3(173.763, 139.293, 155.746), 0.618, all_edge_material);
  cout << "\r21 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(220.261, 171.091, 119.7),   glm::vec3(295.481, 92.2876, 166.223), 0.618, all_edge_material);
  cout << "\r22 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(230.958, 174.932, 70.4607),   glm::vec3(325.47, 123.933, 144.325), 0.618, all_edge_material);
  cout << "\r23 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(220.261, 171.091, 119.7),   glm::vec3(279.529, 58.4, 138.252), 0.618, all_edge_material);
  cout << "\r24 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(335.054, 120.631, 109.149),   glm::vec3(306.766, 113.821, 90.2533), 0.618, all_edge_material);
  cout << "\r25 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(153.409, 118.287, 124.341),   glm::vec3(289.733, 115.478, 108.894), 0.618, all_edge_material);
  cout << "\r26 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(219.697, 112.623, 133.141),   glm::vec3(217.06, 132.056, 138.933), 0.618, all_edge_material);
  cout << "\r27 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(280.899, 169.051, 84.1632),   glm::vec3(256.979, 174.355, 126.305), 0.618, all_edge_material);
  cout << "\r28 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(220.261, 171.091, 119.7),   glm::vec3(241.857, 166.195, 89.3149), 0.618, all_edge_material);
  cout << "\r29 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(279.947, 94.6431, 121.084),   glm::vec3(256.979, 174.355, 126.305), 0.618, all_edge_material);
  cout << "\r30 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(212.119, 104.205, 154.983),   glm::vec3(289.733, 115.478, 108.894), 0.618, all_edge_material);
  cout << "\r31 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(274.759, 110.74, 102.544),   glm::vec3(306.766, 113.821, 90.2533), 0.618, all_edge_material);
  cout << "\r32 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(289.733, 115.478, 108.894),   glm::vec3(300.438, 145.625, 149.469), 0.618, all_edge_material);
  cout << "\r33 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(231.579, 170.935, 156.162),   glm::vec3(226.462, 156.077, 93.9447), 0.618, all_edge_material);
  cout << "\r34 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(273.309, 111.245, 148.738),   glm::vec3(307.501, 76.8321, 162.574), 0.618, all_edge_material);
  cout << "\r35 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(278.167, 117.29, 130.335),   glm::vec3(274.759, 110.74, 102.544), 0.618, all_edge_material);
  cout << "\r36 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(290.088, 152.628, 127.04),   glm::vec3(251.479, 50.5024, 140.739), 0.618, all_edge_material);
  cout << "\r37 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(300.438, 145.625, 149.469),   glm::vec3(219.85, 103.914, 152.149), 0.618, all_edge_material);
  cout << "\r38 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(230.611, 147.359, 152.454),   glm::vec3(248.645, 169.631, 161.017), 0.618, all_edge_material);
  cout << "\r39 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(281.573, 151.994, 118.424),   glm::vec3(296.068, 154.366, 120.41), 0.618, all_edge_material);
  cout << "\r40 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(280.899, 169.051, 84.1632),   glm::vec3(326.118, 138.141, 168.013), 0.618, all_edge_material);
  cout << "\r41 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(290.088, 152.628, 127.04),   glm::vec3(206.485, 118.456, 166.454), 0.618, all_edge_material);
  cout << "\r42 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(324.078, 174.582, 137.923),   glm::vec3(226.462, 156.077, 93.9447), 0.618, all_edge_material);
  cout << "\r43 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(274.759, 110.74, 102.544),   glm::vec3(270.734, 136.763, 116.777), 0.618, all_edge_material);
  cout << "\r44 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(300.438, 145.625, 149.469),   glm::vec3(230.611, 147.359, 152.454), 0.618, all_edge_material);
  cout << "\r45 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(243.383, 116.649, 103.532),   glm::vec3(268.213, 112.811, 174.18), 0.618, all_edge_material);
  cout << "\r46 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(215.736, 113.014, 88.8605),   glm::vec3(231.579, 170.935, 156.162), 0.618, all_edge_material);
  cout << "\r47 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(268.698, 129.244, 112.916),   glm::vec3(201.551, 92.8714, 89.0439), 0.618, all_edge_material);
  cout << "\r48 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(215.736, 113.014, 88.8605),   glm::vec3(347.647, 130.586, 97.38), 0.618, all_edge_material);
  cout << "\r49 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(213.8, 132.886, 133.383),   glm::vec3(274.759, 110.74, 102.544), 0.618, all_edge_material);
  cout << "\r50 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(226.462, 156.077, 93.9447),   glm::vec3(206.485, 118.456, 166.454), 0.618, all_edge_material);
  cout << "\r51 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(296.068, 154.366, 120.41),   glm::vec3(182.219, 136.619, 144.539), 0.618, all_edge_material);
  cout << "\r52 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(233.132, 95.7902, 158.741),   glm::vec3(230.958, 174.932, 70.4607), 0.618, all_edge_material);
  cout << "\r53 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(215.736, 113.014, 88.8605),   glm::vec3(285.88, 175.664, 147.11), 0.618, all_edge_material);
  cout << "\r54 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(281.573, 151.994, 118.424),   glm::vec3(324.078, 174.582, 137.923), 0.618, all_edge_material);
  cout << "\r55 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(251.151, 111.072, 117.203),   glm::vec3(219.697, 112.623, 133.141), 0.618, all_edge_material);
  cout << "\r56 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(173.763, 139.293, 155.746),   glm::vec3(231.579, 170.935, 156.162), 0.618, all_edge_material);
  cout << "\r57 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(211.15, 194.522, 116.213),   glm::vec3(208.791, 115.508, 110.194), 0.618, all_edge_material);
  cout << "\r58 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(219.85, 103.914, 152.149),   glm::vec3(274.759, 110.74, 102.544), 0.618, all_edge_material);
  cout << "\r59 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(295.481, 92.2876, 166.223),   glm::vec3(265.054, 160.301, 182.015), 0.618, all_edge_material);
  cout << "\r60 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(251.354, 80.2382, 115.445),   glm::vec3(219.85, 103.914, 152.149), 0.618, all_edge_material);
  cout << "\r61 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(212.119, 104.205, 154.983),   glm::vec3(335.054, 120.631, 109.149), 0.618, all_edge_material);
  cout << "\r62 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(291.086, 146.437, 117.919),   glm::vec3(291.086, 146.437, 117.919), 0.618, all_edge_material);
  cout << "\r63 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(208.791, 115.508, 110.194),   glm::vec3(291.086, 146.437, 117.919), 0.618, all_edge_material);
  cout << "\r64 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(326.118, 138.141, 168.013),   glm::vec3(248.645, 169.631, 161.017), 0.618, all_edge_material);
  cout << "\r65 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(323.964, 130.536, 145.928),   glm::vec3(279.947, 94.6431, 121.084), 0.618, all_edge_material);
  cout << "\r66 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(170.902, 95.2746, 107.368),   glm::vec3(274.759, 110.74, 102.544), 0.618, all_edge_material);
  cout << "\r67 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(219.85, 103.914, 152.149),   glm::vec3(323.964, 130.536, 145.928), 0.618, all_edge_material);
  cout << "\r68 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(335.054, 120.631, 109.149),   glm::vec3(173.763, 139.293, 155.746), 0.618, all_edge_material);
  cout << "\r69 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(307.501, 76.8321, 162.574),   glm::vec3(248.645, 169.631, 161.017), 0.618, all_edge_material);
  cout << "\r70 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(153.409, 118.287, 124.341),   glm::vec3(324.078, 174.582, 137.923), 0.618, all_edge_material);
  cout << "\r71 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(306.766, 113.821, 90.2533),   glm::vec3(251.479, 50.5024, 140.739), 0.618, all_edge_material);
  cout << "\r72 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(324.078, 174.582, 137.923),   glm::vec3(217.06, 132.056, 138.933), 0.618, all_edge_material);
  cout << "\r73 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(251.354, 80.2382, 115.445),   glm::vec3(226.462, 156.077, 93.9447), 0.618, all_edge_material);
  cout << "\r74 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(229.842, 130.191, 142.118),   glm::vec3(230.611, 147.359, 152.454), 0.618, all_edge_material);
  cout << "\r75 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(182.219, 136.619, 144.539),   glm::vec3(267.546, 111.663, 156.52), 0.618, all_edge_material);
  cout << "\r76 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(261.875, 118.151, 115.041),   glm::vec3(215.736, 113.014, 88.8605), 0.618, all_edge_material);
  cout << "\r77 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(295.142, 127.957, 145.268),   glm::vec3(274.759, 110.74, 102.544), 0.618, all_edge_material);
  cout << "\r78 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(269.837, 164.91, 98.8019),   glm::vec3(326.118, 138.141, 168.013), 0.618, all_edge_material);
  cout << "\r79 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(231.958, 124.038, 152.657),   glm::vec3(230.611, 147.359, 152.454), 0.618, all_edge_material);
  cout << "\r80 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(226.462, 156.077, 93.9447),   glm::vec3(269.837, 164.91, 98.8019), 0.618, all_edge_material);
  cout << "\r81 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(206.485, 118.456, 166.454),   glm::vec3(231.579, 170.935, 156.162), 0.618, all_edge_material);
  cout << "\r82 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(261.875, 118.151, 115.041),   glm::vec3(205.859, 104.949, 128.15), 0.618, all_edge_material);
  cout << "\r83 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(243.085, 150.2, 154.328),   glm::vec3(279.947, 94.6431, 121.084), 0.618, all_edge_material);
  cout << "\r84 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(251.151, 111.072, 117.203),   glm::vec3(208.791, 115.508, 110.194), 0.618, all_edge_material);
  cout << "\r85 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(289.813, 77.1727, 178.895),   glm::vec3(300.438, 145.625, 149.469), 0.618, all_edge_material);
  cout << "\r86 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(153.409, 118.287, 124.341),   glm::vec3(306.766, 113.821, 90.2533), 0.618, all_edge_material);
  cout << "\r87 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(251.479, 50.5024, 140.739),   glm::vec3(217.06, 132.056, 138.933), 0.618, all_edge_material);
  cout << "\r88 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(326.118, 138.141, 168.013),   glm::vec3(307.501, 76.8321, 162.574), 0.618, all_edge_material);
  cout << "\r89 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(325.47, 123.933, 144.325),   glm::vec3(325.47, 123.933, 144.325), 0.618, all_edge_material);
  cout << "\r90 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(269.837, 164.91, 98.8019),   glm::vec3(230.958, 174.932, 70.4607), 0.618, all_edge_material);
  cout << "\r91 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(251.354, 80.2382, 115.445),   glm::vec3(213.8, 132.886, 133.383), 0.618, all_edge_material);
  cout << "\r92 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(212.119, 104.205, 154.983),   glm::vec3(289.813, 77.1727, 178.895), 0.618, all_edge_material);
  cout << "\r93 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(267.546, 111.663, 156.52),   glm::vec3(241.857, 166.195, 89.3149), 0.618, all_edge_material);
  cout << "\r94 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(219.697, 112.623, 133.141),   glm::vec3(230.611, 147.359, 152.454), 0.618, all_edge_material);
  cout << "\r95 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(289.813, 77.1727, 178.895),   glm::vec3(323.964, 130.536, 145.928), 0.618, all_edge_material);
  cout << "\r96 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(212.119, 104.205, 154.983),   glm::vec3(195.946, 129.407, 166.73), 0.618, all_edge_material);
  cout << "\r97 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(217.06, 132.056, 138.933),   glm::vec3(274.463, 192.557, 121.335), 0.618, all_edge_material);
  cout << "\r98 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(299.947, 97.1689, 155.855),   glm::vec3(282.586, 101.719, 155.77), 0.618, all_edge_material);
  cout << "\r99 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(251.354, 80.2382, 115.445),   glm::vec3(323.964, 130.536, 145.928), 0.618, all_edge_material);
  cout << "\r100 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(236.645, 120.721, 136.753),   glm::vec3(307.501, 76.8321, 162.574), 0.618, all_edge_material);
  cout << "\r101 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(325.47, 123.933, 144.325),   glm::vec3(291.086, 146.437, 117.919), 0.618, all_edge_material);
  cout << "\r102 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(274.759, 110.74, 102.544),   glm::vec3(205.859, 104.949, 128.15), 0.618, all_edge_material);
  cout << "\r103 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(269.837, 164.91, 98.8019),   glm::vec3(241.857, 166.195, 89.3149), 0.618, all_edge_material);
  cout << "\r104 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(280.899, 169.051, 84.1632),   glm::vec3(230.611, 147.359, 152.454), 0.618, all_edge_material);
  cout << "\r105 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(273.309, 111.245, 148.738),   glm::vec3(201.551, 92.8714, 89.0439), 0.618, all_edge_material);
  cout << "\r106 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(270.734, 136.763, 116.777),   glm::vec3(268.698, 129.244, 112.916), 0.618, all_edge_material);
  cout << "\r107 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(265.054, 160.301, 182.015),   glm::vec3(230.958, 174.932, 70.4607), 0.618, all_edge_material);
  cout << "\r108 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(293.453, 177.305, 172.066),   glm::vec3(326.118, 138.141, 168.013), 0.618, all_edge_material);
  cout << "\r109 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(283.146, 160.535, 120.806),   glm::vec3(201.551, 92.8714, 89.0439), 0.618, all_edge_material);
  cout << "\r110 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(261.875, 118.151, 115.041),   glm::vec3(205.859, 104.949, 128.15), 0.618, all_edge_material);
  cout << "\r111 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(347.647, 130.586, 97.38),   glm::vec3(241.857, 166.195, 89.3149), 0.618, all_edge_material);
  cout << "\r112 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(289.813, 77.1727, 178.895),   glm::vec3(229.842, 130.191, 142.118), 0.618, all_edge_material);
  cout << "\r113 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(285.88, 175.664, 147.11),   glm::vec3(273.309, 111.245, 148.738), 0.618, all_edge_material);
  cout << "\r114 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(173.763, 139.293, 155.746),   glm::vec3(219.85, 103.914, 152.149), 0.618, all_edge_material);
  cout << "\r115 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(231.579, 170.935, 156.162),   glm::vec3(326.118, 138.141, 168.013), 0.618, all_edge_material);
  cout << "\r116 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(231.579, 170.935, 156.162),   glm::vec3(281.573, 151.994, 118.424), 0.618, all_edge_material);
  cout << "\r117 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(268.213, 112.811, 174.18),   glm::vec3(219.697, 112.623, 133.141), 0.618, all_edge_material);
  cout << "\r118 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(251.151, 111.072, 117.203),   glm::vec3(256.979, 174.355, 126.305), 0.618, all_edge_material);
  cout << "\r119 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(248.645, 169.631, 161.017),   glm::vec3(231.579, 170.935, 156.162), 0.618, all_edge_material);
  cout << "\r120 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(268.698, 129.244, 112.916),   glm::vec3(229.842, 130.191, 142.118), 0.618, all_edge_material);
  cout << "\r121 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(212.119, 104.205, 154.983),   glm::vec3(233.132, 95.7902, 158.741), 0.618, all_edge_material);
  cout << "\r122 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(229.842, 130.191, 142.118),   glm::vec3(323.964, 130.536, 145.928), 0.618, all_edge_material);
  cout << "\r123 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(201.551, 92.8714, 89.0439),   glm::vec3(199.958, 136.418, 146.237), 0.618, all_edge_material);
  cout << "\r124 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(241.857, 166.195, 89.3149),   glm::vec3(296.068, 154.366, 120.41), 0.618, all_edge_material);
  cout << "\r125 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(249.92, 139.51, 137.883),   glm::vec3(153.409, 118.287, 124.341), 0.618, all_edge_material);
  cout << "\r126 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(230.611, 147.359, 152.454),   glm::vec3(270.734, 136.763, 116.777), 0.618, all_edge_material);
  cout << "\r127 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(295.142, 127.957, 145.268),   glm::vec3(306.766, 113.821, 90.2533), 0.618, all_edge_material);
  cout << "\r128 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(170.902, 95.2746, 107.368),   glm::vec3(251.354, 80.2382, 115.445), 0.618, all_edge_material);
  cout << "\r129 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(269.837, 164.91, 98.8019),   glm::vec3(335.054, 120.631, 109.149), 0.618, all_edge_material);
  cout << "\r130 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(226.462, 156.077, 93.9447),   glm::vec3(230.958, 174.932, 70.4607), 0.618, all_edge_material);
  cout << "\r131 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(251.354, 80.2382, 115.445),   glm::vec3(199.958, 136.418, 146.237), 0.618, all_edge_material);
  cout << "\r132 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(236.645, 120.721, 136.753),   glm::vec3(233.132, 95.7902, 158.741), 0.618, all_edge_material);
  cout << "\r133 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(230.958, 174.932, 70.4607),   glm::vec3(265.054, 160.301, 182.015), 0.618, all_edge_material);
  cout << "\r134 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(293.453, 177.305, 172.066),   glm::vec3(256.979, 174.355, 126.305), 0.618, all_edge_material);
  cout << "\r135 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(213.8, 132.886, 133.383),   glm::vec3(201.551, 92.8714, 89.0439), 0.618, all_edge_material);
  cout << "\r136 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(201.551, 92.8714, 89.0439),   glm::vec3(230.958, 174.932, 70.4607), 0.618, all_edge_material);
  cout << "\r137 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(215.736, 113.014, 88.8605),   glm::vec3(256.979, 174.355, 126.305), 0.618, all_edge_material);
  cout << "\r138 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(267.546, 111.663, 156.52),   glm::vec3(307.501, 76.8321, 162.574), 0.618, all_edge_material);
  cout << "\r139 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(199.958, 136.418, 146.237),   glm::vec3(307.501, 76.8321, 162.574), 0.618, all_edge_material);
  cout << "\r140 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(268.698, 129.244, 112.916),   glm::vec3(281.805, 106.806, 135.233), 0.618, all_edge_material);
  cout << "\r141 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(290.088, 152.628, 127.04),   glm::vec3(289.813, 77.1727, 178.895), 0.618, all_edge_material);
  cout << "\r142 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(243.383, 116.649, 103.532),   glm::vec3(269.837, 164.91, 98.8019), 0.618, all_edge_material);
  cout << "\r143 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(251.354, 80.2382, 115.445),   glm::vec3(283.146, 160.535, 120.806), 0.618, all_edge_material);
  cout << "\r144 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(201.551, 92.8714, 89.0439),   glm::vec3(281.573, 151.994, 118.424), 0.618, all_edge_material);
  cout << "\r145 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(230.611, 147.359, 152.454),   glm::vec3(281.573, 151.994, 118.424), 0.618, all_edge_material);
  cout << "\r146 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(290.088, 152.628, 127.04),   glm::vec3(251.151, 111.072, 117.203), 0.618, all_edge_material);
  cout << "\r147 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(211.15, 194.522, 116.213),   glm::vec3(217.06, 132.056, 138.933), 0.618, all_edge_material);
  cout << "\r148 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(261.875, 118.151, 115.041),   glm::vec3(251.354, 80.2382, 115.445), 0.618, all_edge_material);
  cout << "\r149 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(278.167, 117.29, 130.335),   glm::vec3(231.958, 124.038, 152.657), 0.618, all_edge_material);
  cout << "\r150 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(212.119, 104.205, 154.983),   glm::vec3(251.151, 111.072, 117.203), 0.618, all_edge_material);
  cout << "\r151 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(182.219, 136.619, 144.539),   glm::vec3(279.947, 94.6431, 121.084), 0.618, all_edge_material);
  cout << "\r152 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(208.791, 115.508, 110.194),   glm::vec3(219.697, 112.623, 133.141), 0.618, all_edge_material);
  cout << "\r153 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(153.409, 118.287, 124.341),   glm::vec3(230.958, 174.932, 70.4607), 0.618, all_edge_material);
  cout << "\r154 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(268.213, 112.811, 174.18),   glm::vec3(300.438, 145.625, 149.469), 0.618, all_edge_material);
  cout << "\r155 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(170.902, 95.2746, 107.368),   glm::vec3(279.529, 58.4, 138.252), 0.618, all_edge_material);
  cout << "\r156 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(229.842, 130.191, 142.118),   glm::vec3(212.119, 104.205, 154.983), 0.618, all_edge_material);
  cout << "\r157 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(299.947, 97.1689, 155.855),   glm::vec3(279.529, 58.4, 138.252), 0.618, all_edge_material);
  cout << "\r158 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(274.759, 110.74, 102.544),   glm::vec3(230.611, 147.359, 152.454), 0.618, all_edge_material);
  cout << "\r159 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(268.698, 129.244, 112.916),   glm::vec3(231.579, 170.935, 156.162), 0.618, all_edge_material);
  cout << "\r160 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(296.068, 154.366, 120.41),   glm::vec3(278.167, 117.29, 130.335), 0.618, all_edge_material);
  cout << "\r161 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(300.438, 145.625, 149.469),   glm::vec3(170.902, 95.2746, 107.368), 0.618, all_edge_material);
  cout << "\r162 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(295.142, 127.957, 145.268),   glm::vec3(243.085, 150.2, 154.328), 0.618, all_edge_material);
  cout << "\r163 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(282.586, 101.719, 155.77),   glm::vec3(248.645, 169.631, 161.017), 0.618, all_edge_material);
  cout << "\r164 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(269.837, 164.91, 98.8019),   glm::vec3(243.383, 116.649, 103.532), 0.618, all_edge_material);
  cout << "\r165 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(201.551, 92.8714, 89.0439),   glm::vec3(274.463, 192.557, 121.335), 0.618, all_edge_material);
  cout << "\r166 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(195.946, 129.407, 166.73),   glm::vec3(285.88, 175.664, 147.11), 0.618, all_edge_material);
  cout << "\r167 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(280.899, 169.051, 84.1632),   glm::vec3(243.383, 116.649, 103.532), 0.618, all_edge_material);
  cout << "\r168 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(251.479, 50.5024, 140.739),   glm::vec3(267.546, 111.663, 156.52), 0.618, all_edge_material);
  cout << "\r169 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(219.85, 103.914, 152.149),   glm::vec3(251.479, 50.5024, 140.739), 0.618, all_edge_material);
  cout << "\r170 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(282.586, 101.719, 155.77),   glm::vec3(208.791, 115.508, 110.194), 0.618, all_edge_material);
  cout << "\r171 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(170.902, 95.2746, 107.368),   glm::vec3(268.213, 112.811, 174.18), 0.618, all_edge_material);
  cout << "\r172 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(295.142, 127.957, 145.268),   glm::vec3(273.309, 111.245, 148.738), 0.618, all_edge_material);
  cout << "\r173 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(213.8, 132.886, 133.383),   glm::vec3(325.47, 123.933, 144.325), 0.618, all_edge_material);
  cout << "\r174 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(206.485, 118.456, 166.454),   glm::vec3(251.479, 50.5024, 140.739), 0.618, all_edge_material);
  cout << "\r175 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(273.309, 111.245, 148.738),   glm::vec3(173.763, 139.293, 155.746), 0.618, all_edge_material);
  cout << "\r176 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(153.409, 118.287, 124.341),   glm::vec3(219.85, 103.914, 152.149), 0.618, all_edge_material);
  cout << "\r177 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(295.142, 127.957, 145.268),   glm::vec3(324.078, 174.582, 137.923), 0.618, all_edge_material);
  cout << "\r178 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(208.791, 115.508, 110.194),   glm::vec3(201.551, 92.8714, 89.0439), 0.618, all_edge_material);
  cout << "\r179 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(217.06, 132.056, 138.933),   glm::vec3(269.837, 164.91, 98.8019), 0.618, all_edge_material);
  cout << "\r180 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(283.146, 160.535, 120.806),   glm::vec3(279.529, 58.4, 138.252), 0.618, all_edge_material);
  cout << "\r181 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(249.92, 139.51, 137.883),   glm::vec3(215.736, 113.014, 88.8605), 0.618, all_edge_material);
  cout << "\r182 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(274.463, 192.557, 121.335),   glm::vec3(293.453, 177.305, 172.066), 0.618, all_edge_material);
  cout << "\r183 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(281.573, 151.994, 118.424),   glm::vec3(300.438, 145.625, 149.469), 0.618, all_edge_material);
  cout << "\r184 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(289.813, 77.1727, 178.895),   glm::vec3(325.47, 123.933, 144.325), 0.618, all_edge_material);
  cout << "\r185 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(213.8, 132.886, 133.383),   glm::vec3(230.611, 147.359, 152.454), 0.618, all_edge_material);
  cout << "\r186 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(243.085, 150.2, 154.328),   glm::vec3(219.85, 103.914, 152.149), 0.618, all_edge_material);
  cout << "\r187 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(274.759, 110.74, 102.544),   glm::vec3(236.645, 120.721, 136.753), 0.618, all_edge_material);
  cout << "\r188 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(251.354, 80.2382, 115.445),   glm::vec3(326.118, 138.141, 168.013), 0.618, all_edge_material);
  cout << "\r189 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(201.551, 92.8714, 89.0439),   glm::vec3(269.837, 164.91, 98.8019), 0.618, all_edge_material);
  cout << "\r190 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(268.213, 112.811, 174.18),   glm::vec3(219.85, 103.914, 152.149), 0.618, all_edge_material);
  cout << "\r191 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(307.501, 76.8321, 162.574),   glm::vec3(213.8, 132.886, 133.383), 0.618, all_edge_material);
  cout << "\r192 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(289.813, 77.1727, 178.895),   glm::vec3(153.409, 118.287, 124.341), 0.618, all_edge_material);
  cout << "\r193 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(289.813, 77.1727, 178.895),   glm::vec3(323.964, 130.536, 145.928), 0.618, all_edge_material);
  cout << "\r194 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(324.078, 174.582, 137.923),   glm::vec3(199.958, 136.418, 146.237), 0.618, all_edge_material);
  cout << "\r195 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(285.88, 175.664, 147.11),   glm::vec3(268.213, 112.811, 174.18), 0.618, all_edge_material);
  cout << "\r196 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(213.8, 132.886, 133.383),   glm::vec3(270.734, 136.763, 116.777), 0.618, all_edge_material);
  cout << "\r197 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(291.086, 146.437, 117.919),   glm::vec3(219.85, 103.914, 152.149), 0.618, all_edge_material);
  cout << "\r198 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(251.151, 111.072, 117.203),   glm::vec3(251.354, 80.2382, 115.445), 0.618, all_edge_material);
  cout << "\r199 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(219.697, 112.623, 133.141),   glm::vec3(230.958, 174.932, 70.4607), 0.618, all_edge_material);
  cout << "\r200 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(279.947, 94.6431, 121.084),   glm::vec3(295.481, 92.2876, 166.223), 0.618, all_edge_material);
  cout << "\r201 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(248.645, 169.631, 161.017),   glm::vec3(211.15, 194.522, 116.213), 0.618, all_edge_material);
  cout << "\r202 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(281.573, 151.994, 118.424),   glm::vec3(230.958, 174.932, 70.4607), 0.618, all_edge_material);
  cout << "\r203 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(251.479, 50.5024, 140.739),   glm::vec3(153.409, 118.287, 124.341), 0.618, all_edge_material);
  cout << "\r204 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(199.958, 136.418, 146.237),   glm::vec3(283.146, 160.535, 120.806), 0.618, all_edge_material);
  cout << "\r205 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(326.118, 138.141, 168.013),   glm::vec3(243.085, 150.2, 154.328), 0.618, all_edge_material);
  cout << "\r206 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(206.485, 118.456, 166.454),   glm::vec3(269.837, 164.91, 98.8019), 0.618, all_edge_material);
  cout << "\r207 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(220.261, 171.091, 119.7),   glm::vec3(282.586, 101.719, 155.77), 0.618, all_edge_material);
  cout << "\r208 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(182.219, 136.619, 144.539),   glm::vec3(290.088, 152.628, 127.04), 0.618, all_edge_material);
  cout << "\r209 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(248.645, 169.631, 161.017),   glm::vec3(182.219, 136.619, 144.539), 0.618, all_edge_material);
  cout << "\r210 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(268.213, 112.811, 174.18),   glm::vec3(173.763, 139.293, 155.746), 0.618, all_edge_material);
  cout << "\r211 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(289.733, 115.478, 108.894),   glm::vec3(249.92, 139.51, 137.883), 0.618, all_edge_material);
  cout << "\r212 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(347.647, 130.586, 97.38),   glm::vec3(251.479, 50.5024, 140.739), 0.618, all_edge_material);
  cout << "\r213 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(283.146, 160.535, 120.806),   glm::vec3(261.875, 118.151, 115.041), 0.618, all_edge_material);
  cout << "\r214 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(282.586, 101.719, 155.77),   glm::vec3(267.546, 111.663, 156.52), 0.618, all_edge_material);
  cout << "\r215 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(212.119, 104.205, 154.983),   glm::vec3(236.645, 120.721, 136.753), 0.618, all_edge_material);
  cout << "\r216 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(211.15, 194.522, 116.213),   glm::vec3(206.485, 118.456, 166.454), 0.618, all_edge_material);
  cout << "\r217 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(226.462, 156.077, 93.9447),   glm::vec3(325.47, 123.933, 144.325), 0.618, all_edge_material);
  cout << "\r218 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(251.151, 111.072, 117.203),   glm::vec3(299.947, 97.1689, 155.855), 0.618, all_edge_material);
  cout << "\r219 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(281.573, 151.994, 118.424),   glm::vec3(219.697, 112.623, 133.141), 0.618, all_edge_material);
  cout << "\r220 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(173.763, 139.293, 155.746),   glm::vec3(285.88, 175.664, 147.11), 0.618, all_edge_material);
  cout << "\r221 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(230.958, 174.932, 70.4607),   glm::vec3(274.463, 192.557, 121.335), 0.618, all_edge_material);
  cout << "\r222 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(201.551, 92.8714, 89.0439),   glm::vec3(213.8, 132.886, 133.383), 0.618, all_edge_material);
  cout << "\r223 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(279.947, 94.6431, 121.084),   glm::vec3(291.086, 146.437, 117.919), 0.618, all_edge_material);
  cout << "\r224 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(231.579, 170.935, 156.162),   glm::vec3(285.88, 175.664, 147.11), 0.618, all_edge_material);
  cout << "\r225 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(205.859, 104.949, 128.15),   glm::vec3(195.946, 129.407, 166.73), 0.618, all_edge_material);
  cout << "\r226 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(170.902, 95.2746, 107.368),   glm::vec3(269.837, 164.91, 98.8019), 0.618, all_edge_material);
  cout << "\r227 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(251.479, 50.5024, 140.739),   glm::vec3(241.857, 166.195, 89.3149), 0.618, all_edge_material);
  cout << "\r228 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(231.958, 124.038, 152.657),   glm::vec3(236.645, 120.721, 136.753), 0.618, all_edge_material);
  cout << "\r229 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(251.479, 50.5024, 140.739),   glm::vec3(307.501, 76.8321, 162.574), 0.618, all_edge_material);
  cout << "\r230 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(335.054, 120.631, 109.149),   glm::vec3(291.086, 146.437, 117.919), 0.618, all_edge_material);
  cout << "\r231 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(282.586, 101.719, 155.77),   glm::vec3(219.697, 112.623, 133.141), 0.618, all_edge_material);
  cout << "\r232 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(283.146, 160.535, 120.806),   glm::vec3(296.068, 154.366, 120.41), 0.618, all_edge_material);
  cout << "\r233 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(324.078, 174.582, 137.923),   glm::vec3(173.763, 139.293, 155.746), 0.618, all_edge_material);
  cout << "\r234 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(236.645, 120.721, 136.753),   glm::vec3(219.85, 103.914, 152.149), 0.618, all_edge_material);
  cout << "\r235 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(281.805, 106.806, 135.233),   glm::vec3(296.068, 154.366, 120.41), 0.618, all_edge_material);
  cout << "\r236 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(215.736, 113.014, 88.8605),   glm::vec3(289.733, 115.478, 108.894), 0.618, all_edge_material);
  cout << "\r237 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(323.964, 130.536, 145.928),   glm::vec3(307.501, 76.8321, 162.574), 0.618, all_edge_material);
  cout << "\r238 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(269.837, 164.91, 98.8019),   glm::vec3(249.92, 139.51, 137.883), 0.618, all_edge_material);
  cout << "\r239 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(295.142, 127.957, 145.268),   glm::vec3(241.857, 166.195, 89.3149), 0.618, all_edge_material);
  cout << "\r240 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(226.462, 156.077, 93.9447),   glm::vec3(270.734, 136.763, 116.777), 0.618, all_edge_material);
  cout << "\r241 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(295.481, 92.2876, 166.223),   glm::vec3(251.354, 80.2382, 115.445), 0.618, all_edge_material);
  cout << "\r242 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(295.142, 127.957, 145.268),   glm::vec3(278.167, 117.29, 130.335), 0.618, all_edge_material);
  cout << "\r243 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(249.92, 139.51, 137.883),   glm::vec3(248.645, 169.631, 161.017), 0.618, all_edge_material);
  cout << "\r244 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(215.736, 113.014, 88.8605),   glm::vec3(274.463, 192.557, 121.335), 0.618, all_edge_material);
  cout << "\r245 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(206.485, 118.456, 166.454),   glm::vec3(300.438, 145.625, 149.469), 0.618, all_edge_material);
  cout << "\r246 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(280.899, 169.051, 84.1632),   glm::vec3(269.837, 164.91, 98.8019), 0.618, all_edge_material);
  cout << "\r247 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(289.813, 77.1727, 178.895),   glm::vec3(285.88, 175.664, 147.11), 0.618, all_edge_material);
  cout << "\r248 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(219.85, 103.914, 152.149),   glm::vec3(249.92, 139.51, 137.883), 0.618, all_edge_material);
  cout << "\r249 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(289.813, 77.1727, 178.895),   glm::vec3(282.586, 101.719, 155.77), 0.618, all_edge_material);
  cout << "\r250 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(205.859, 104.949, 128.15),   glm::vec3(173.763, 139.293, 155.746), 0.618, all_edge_material);
  cout << "\r251 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(269.837, 164.91, 98.8019),   glm::vec3(307.501, 76.8321, 162.574), 0.618, all_edge_material);
  cout << "\r252 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(279.529, 58.4, 138.252),   glm::vec3(170.902, 95.2746, 107.368), 0.618, all_edge_material);
  cout << "\r253 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(248.645, 169.631, 161.017),   glm::vec3(231.579, 170.935, 156.162), 0.618, all_edge_material);
  cout << "\r254 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(212.119, 104.205, 154.983),   glm::vec3(295.481, 92.2876, 166.223), 0.618, all_edge_material);
  cout << "\r255 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(265.054, 160.301, 182.015),   glm::vec3(261.875, 118.151, 115.041), 0.618, all_edge_material);
  cout << "\r256 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(199.958, 136.418, 146.237),   glm::vec3(208.791, 115.508, 110.194), 0.618, all_edge_material);
  cout << "\r257 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(293.453, 177.305, 172.066),   glm::vec3(290.088, 152.628, 127.04), 0.618, all_edge_material);
  cout << "\r258 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(283.146, 160.535, 120.806),   glm::vec3(217.06, 132.056, 138.933), 0.618, all_edge_material);
  cout << "\r259 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(205.859, 104.949, 128.15),   glm::vec3(219.697, 112.623, 133.141), 0.618, all_edge_material);
  cout << "\r260 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(267.546, 111.663, 156.52),   glm::vec3(306.766, 113.821, 90.2533), 0.618, all_edge_material);
  cout << "\r261 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(199.958, 136.418, 146.237),   glm::vec3(296.068, 154.366, 120.41), 0.618, all_edge_material);
  cout << "\r262 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(256.979, 174.355, 126.305),   glm::vec3(173.763, 139.293, 155.746), 0.618, all_edge_material);
  cout << "\r263 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(217.06, 132.056, 138.933),   glm::vec3(323.964, 130.536, 145.928), 0.618, all_edge_material);
  cout << "\r264 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(278.167, 117.29, 130.335),   glm::vec3(280.899, 169.051, 84.1632), 0.618, all_edge_material);
  cout << "\r265 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(347.647, 130.586, 97.38),   glm::vec3(280.899, 169.051, 84.1632), 0.618, all_edge_material);
  cout << "\r266 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(274.463, 192.557, 121.335),   glm::vec3(231.579, 170.935, 156.162), 0.618, all_edge_material);
  cout << "\r267 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(261.875, 118.151, 115.041),   glm::vec3(208.791, 115.508, 110.194), 0.618, all_edge_material);
  cout << "\r268 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(265.054, 160.301, 182.015),   glm::vec3(215.736, 113.014, 88.8605), 0.618, all_edge_material);
  cout << "\r269 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(248.645, 169.631, 161.017),   glm::vec3(226.462, 156.077, 93.9447), 0.618, all_edge_material);
  cout << "\r270 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(270.734, 136.763, 116.777),   glm::vec3(274.463, 192.557, 121.335), 0.618, all_edge_material);
  cout << "\r271 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(326.118, 138.141, 168.013),   glm::vec3(325.47, 123.933, 144.325), 0.618, all_edge_material);
  cout << "\r272 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(205.859, 104.949, 128.15),   glm::vec3(289.813, 77.1727, 178.895), 0.618, all_edge_material);
  cout << "\r273 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(213.8, 132.886, 133.383),   glm::vec3(231.958, 124.038, 152.657), 0.618, all_edge_material);
  cout << "\r274 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(282.586, 101.719, 155.77),   glm::vec3(215.736, 113.014, 88.8605), 0.618, all_edge_material);
  cout << "\r275 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(281.573, 151.994, 118.424),   glm::vec3(280.899, 169.051, 84.1632), 0.618, all_edge_material);
  cout << "\r276 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(290.088, 152.628, 127.04),   glm::vec3(280.899, 169.051, 84.1632), 0.618, all_edge_material);
  cout << "\r277 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(323.964, 130.536, 145.928),   glm::vec3(233.132, 95.7902, 158.741), 0.618, all_edge_material);
  cout << "\r278 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(243.085, 150.2, 154.328),   glm::vec3(289.733, 115.478, 108.894), 0.618, all_edge_material);
  cout << "\r279 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(211.15, 194.522, 116.213),   glm::vec3(251.479, 50.5024, 140.739), 0.618, all_edge_material);
  cout << "\r280 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(251.479, 50.5024, 140.739),   glm::vec3(281.573, 151.994, 118.424), 0.618, all_edge_material);
  cout << "\r281 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(280.899, 169.051, 84.1632),   glm::vec3(324.078, 174.582, 137.923), 0.618, all_edge_material);
  cout << "\r282 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(248.645, 169.631, 161.017),   glm::vec3(251.354, 80.2382, 115.445), 0.618, all_edge_material);
  cout << "\r283 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(199.958, 136.418, 146.237),   glm::vec3(251.151, 111.072, 117.203), 0.618, all_edge_material);
  cout << "\r284 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(270.734, 136.763, 116.777),   glm::vec3(300.438, 145.625, 149.469), 0.618, all_edge_material);
  cout << "\r285 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(248.645, 169.631, 161.017),   glm::vec3(326.118, 138.141, 168.013), 0.618, all_edge_material);
  cout << "\r286 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(265.054, 160.301, 182.015),   glm::vec3(335.054, 120.631, 109.149), 0.618, all_edge_material);
  cout << "\r287 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(206.485, 118.456, 166.454),   glm::vec3(231.958, 124.038, 152.657), 0.618, all_edge_material);
  cout << "\r288 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(295.142, 127.957, 145.268),   glm::vec3(279.947, 94.6431, 121.084), 0.618, all_edge_material);
  cout << "\r289 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(249.92, 139.51, 137.883),   glm::vec3(324.078, 174.582, 137.923), 0.618, all_edge_material);
  cout << "\r290 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(295.481, 92.2876, 166.223),   glm::vec3(153.409, 118.287, 124.341), 0.618, all_edge_material);
  cout << "\r291 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(289.733, 115.478, 108.894),   glm::vec3(173.763, 139.293, 155.746), 0.618, all_edge_material);
  cout << "\r292 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(231.579, 170.935, 156.162),   glm::vec3(226.462, 156.077, 93.9447), 0.618, all_edge_material);
  cout << "\r293 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(324.078, 174.582, 137.923),   glm::vec3(256.979, 174.355, 126.305), 0.618, all_edge_material);
  cout << "\r294 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(206.485, 118.456, 166.454),   glm::vec3(281.805, 106.806, 135.233), 0.618, all_edge_material);
  cout << "\r295 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(199.958, 136.418, 146.237),   glm::vec3(236.645, 120.721, 136.753), 0.618, all_edge_material);
  cout << "\r296 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(324.078, 174.582, 137.923),   glm::vec3(295.481, 92.2876, 166.223), 0.618, all_edge_material);
  cout << "\r297 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(215.736, 113.014, 88.8605),   glm::vec3(281.573, 151.994, 118.424), 0.618, all_edge_material);
  cout << "\r298 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(269.837, 164.91, 98.8019),   glm::vec3(282.586, 101.719, 155.77), 0.618, all_edge_material);
  cout << "\r299 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(295.481, 92.2876, 166.223),   glm::vec3(206.485, 118.456, 166.454), 0.618, all_edge_material);
  cout << "\r300 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(267.546, 111.663, 156.52),   glm::vec3(231.958, 124.038, 152.657), 0.618, all_edge_material);
  cout << "\r301 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(289.733, 115.478, 108.894),   glm::vec3(280.899, 169.051, 84.1632), 0.618, all_edge_material);
  cout << "\r302 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(280.899, 169.051, 84.1632),   glm::vec3(256.979, 174.355, 126.305), 0.618, all_edge_material);
  cout << "\r303 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(251.354, 80.2382, 115.445),   glm::vec3(293.453, 177.305, 172.066), 0.618, all_edge_material);
  cout << "\r304 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(153.409, 118.287, 124.341),   glm::vec3(268.698, 129.244, 112.916), 0.618, all_edge_material);
  cout << "\r305 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(195.946, 129.407, 166.73),   glm::vec3(229.842, 130.191, 142.118), 0.618, all_edge_material);
  cout << "\r306 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(335.054, 120.631, 109.149),   glm::vec3(300.438, 145.625, 149.469), 0.618, all_edge_material);
  cout << "\r307 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(201.551, 92.8714, 89.0439),   glm::vec3(280.899, 169.051, 84.1632), 0.618, all_edge_material);
  cout << "\r308 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(299.947, 97.1689, 155.855),   glm::vec3(325.47, 123.933, 144.325), 0.618, all_edge_material);
  cout << "\r309 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(293.453, 177.305, 172.066),   glm::vec3(205.859, 104.949, 128.15), 0.618, all_edge_material);
  cout << "\r310 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(217.06, 132.056, 138.933),   glm::vec3(295.481, 92.2876, 166.223), 0.618, all_edge_material);
  cout << "\r311 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(243.085, 150.2, 154.328),   glm::vec3(347.647, 130.586, 97.38), 0.618, all_edge_material);
  cout << "\r312 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(274.759, 110.74, 102.544),   glm::vec3(268.213, 112.811, 174.18), 0.618, all_edge_material);
  cout << "\r313 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(211.15, 194.522, 116.213),   glm::vec3(285.88, 175.664, 147.11), 0.618, all_edge_material);
  cout << "\r314 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(299.947, 97.1689, 155.855),   glm::vec3(211.15, 194.522, 116.213), 0.618, all_edge_material);
  cout << "\r315 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(281.805, 106.806, 135.233),   glm::vec3(268.698, 129.244, 112.916), 0.618, all_edge_material);
  cout << "\r316 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(211.15, 194.522, 116.213),   glm::vec3(306.766, 113.821, 90.2533), 0.618, all_edge_material);
  cout << "\r317 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(293.453, 177.305, 172.066),   glm::vec3(212.119, 104.205, 154.983), 0.618, all_edge_material);
  cout << "\r318 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(219.697, 112.623, 133.141),   glm::vec3(324.078, 174.582, 137.923), 0.618, all_edge_material);
  cout << "\r319 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(217.06, 132.056, 138.933),   glm::vec3(268.213, 112.811, 174.18), 0.618, all_edge_material);
  cout << "\r320 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(229.842, 130.191, 142.118),   glm::vec3(251.479, 50.5024, 140.739), 0.618, all_edge_material);
  cout << "\r321 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(335.054, 120.631, 109.149),   glm::vec3(249.92, 139.51, 137.883), 0.618, all_edge_material);
  cout << "\r322 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(280.899, 169.051, 84.1632),   glm::vec3(231.579, 170.935, 156.162), 0.618, all_edge_material);
  cout << "\r323 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(282.586, 101.719, 155.77),   glm::vec3(290.088, 152.628, 127.04), 0.618, all_edge_material);
  cout << "\r324 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(274.759, 110.74, 102.544),   glm::vec3(243.383, 116.649, 103.532), 0.618, all_edge_material);
  cout << "\r325 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(217.06, 132.056, 138.933),   glm::vec3(230.958, 174.932, 70.4607), 0.618, all_edge_material);
  cout << "\r326 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(248.645, 169.631, 161.017),   glm::vec3(229.842, 130.191, 142.118), 0.618, all_edge_material);
  cout << "\r327 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(295.142, 127.957, 145.268),   glm::vec3(249.92, 139.51, 137.883), 0.618, all_edge_material);
  cout << "\r328 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(229.842, 130.191, 142.118),   glm::vec3(273.309, 111.245, 148.738), 0.618, all_edge_material);
  cout << "\r329 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(261.875, 118.151, 115.041),   glm::vec3(249.92, 139.51, 137.883), 0.618, all_edge_material);
  cout << "\r330 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(213.8, 132.886, 133.383),   glm::vec3(265.054, 160.301, 182.015), 0.618, all_edge_material);
  cout << "\r331 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(279.529, 58.4, 138.252),   glm::vec3(291.086, 146.437, 117.919), 0.618, all_edge_material);
  cout << "\r332 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(347.647, 130.586, 97.38),   glm::vec3(295.142, 127.957, 145.268), 0.618, all_edge_material);
  cout << "\r333 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(208.791, 115.508, 110.194),   glm::vec3(212.119, 104.205, 154.983), 0.618, all_edge_material);
  cout << "\r334 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(323.964, 130.536, 145.928),   glm::vec3(283.146, 160.535, 120.806), 0.618, all_edge_material);
  cout << "\r335 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(282.586, 101.719, 155.77),   glm::vec3(208.791, 115.508, 110.194), 0.618, all_edge_material);
  cout << "\r336 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(199.958, 136.418, 146.237),   glm::vec3(229.842, 130.191, 142.118), 0.618, all_edge_material);
  cout << "\r337 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(268.213, 112.811, 174.18),   glm::vec3(249.92, 139.51, 137.883), 0.618, all_edge_material);
  cout << "\r338 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(306.766, 113.821, 90.2533),   glm::vec3(219.697, 112.623, 133.141), 0.618, all_edge_material);
  cout << "\r339 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(173.763, 139.293, 155.746),   glm::vec3(270.734, 136.763, 116.777), 0.618, all_edge_material);
  cout << "\r340 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(293.453, 177.305, 172.066),   glm::vec3(295.481, 92.2876, 166.223), 0.618, all_edge_material);
  cout << "\r341 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(220.261, 171.091, 119.7),   glm::vec3(249.92, 139.51, 137.883), 0.618, all_edge_material);
  cout << "\r342 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(289.733, 115.478, 108.894),   glm::vec3(229.842, 130.191, 142.118), 0.618, all_edge_material);
  cout << "\r343 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(213.8, 132.886, 133.383),   glm::vec3(256.979, 174.355, 126.305), 0.618, all_edge_material);
  cout << "\r344 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(274.463, 192.557, 121.335),   glm::vec3(265.054, 160.301, 182.015), 0.618, all_edge_material);
  cout << "\r345 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(236.645, 120.721, 136.753),   glm::vec3(251.354, 80.2382, 115.445), 0.618, all_edge_material);
  cout << "\r346 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(206.485, 118.456, 166.454),   glm::vec3(217.06, 132.056, 138.933), 0.618, all_edge_material);
  cout << "\r347 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(229.842, 130.191, 142.118),   glm::vec3(213.8, 132.886, 133.383), 0.618, all_edge_material);
  cout << "\r348 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(243.383, 116.649, 103.532),   glm::vec3(296.068, 154.366, 120.41), 0.618, all_edge_material);
  cout << "\r349 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(299.947, 97.1689, 155.855),   glm::vec3(289.733, 115.478, 108.894), 0.618, all_edge_material);
  cout << "\r350 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(323.964, 130.536, 145.928),   glm::vec3(265.054, 160.301, 182.015), 0.618, all_edge_material);
  cout << "\r351 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(261.875, 118.151, 115.041),   glm::vec3(296.068, 154.366, 120.41), 0.618, all_edge_material);
  cout << "\r352 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(213.8, 132.886, 133.383),   glm::vec3(274.463, 192.557, 121.335), 0.618, all_edge_material);
  cout << "\r353 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(231.958, 124.038, 152.657),   glm::vec3(229.842, 130.191, 142.118), 0.618, all_edge_material);
  cout << "\r354 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(289.733, 115.478, 108.894),   glm::vec3(201.551, 92.8714, 89.0439), 0.618, all_edge_material);
  cout << "\r355 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(293.453, 177.305, 172.066),   glm::vec3(243.085, 150.2, 154.328), 0.618, all_edge_material);
  cout << "\r356 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(215.736, 113.014, 88.8605),   glm::vec3(273.309, 111.245, 148.738), 0.618, all_edge_material);
  cout << "\r357 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(273.309, 111.245, 148.738),   glm::vec3(289.813, 77.1727, 178.895), 0.618, all_edge_material);
  cout << "\r358 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(299.947, 97.1689, 155.855),   glm::vec3(299.947, 97.1689, 155.855), 0.618, all_edge_material);
  cout << "\r359 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(256.979, 174.355, 126.305),   glm::vec3(173.763, 139.293, 155.746), 0.618, all_edge_material);
  cout << "\r360 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(289.733, 115.478, 108.894),   glm::vec3(265.054, 160.301, 182.015), 0.618, all_edge_material);
  cout << "\r361 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(274.463, 192.557, 121.335),   glm::vec3(281.805, 106.806, 135.233), 0.618, all_edge_material);
  cout << "\r362 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(226.462, 156.077, 93.9447),   glm::vec3(199.958, 136.418, 146.237), 0.618, all_edge_material);
  cout << "\r363 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(256.979, 174.355, 126.305),   glm::vec3(236.645, 120.721, 136.753), 0.618, all_edge_material);
  cout << "\r364 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(274.463, 192.557, 121.335),   glm::vec3(290.088, 152.628, 127.04), 0.618, all_edge_material);
  cout << "\r365 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(281.573, 151.994, 118.424),   glm::vec3(300.438, 145.625, 149.469), 0.618, all_edge_material);
  cout << "\r366 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(251.354, 80.2382, 115.445),   glm::vec3(291.086, 146.437, 117.919), 0.618, all_edge_material);
  cout << "\r367 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(219.85, 103.914, 152.149),   glm::vec3(243.383, 116.649, 103.532), 0.618, all_edge_material);
  cout << "\r368 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(267.546, 111.663, 156.52),   glm::vec3(231.958, 124.038, 152.657), 0.618, all_edge_material);
  cout << "\r369 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(219.85, 103.914, 152.149),   glm::vec3(215.736, 113.014, 88.8605), 0.618, all_edge_material);
  cout << "\r370 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(220.261, 171.091, 119.7),   glm::vec3(243.085, 150.2, 154.328), 0.618, all_edge_material);
  cout << "\r371 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(211.15, 194.522, 116.213),   glm::vec3(251.479, 50.5024, 140.739), 0.618, all_edge_material);
  cout << "\r372 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(251.151, 111.072, 117.203),   glm::vec3(199.958, 136.418, 146.237), 0.618, all_edge_material);
  cout << "\r373 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(274.759, 110.74, 102.544),   glm::vec3(199.958, 136.418, 146.237), 0.618, all_edge_material);
  cout << "\r374 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(215.736, 113.014, 88.8605),   glm::vec3(307.501, 76.8321, 162.574), 0.618, all_edge_material);
  cout << "\r375 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(173.763, 139.293, 155.746),   glm::vec3(212.119, 104.205, 154.983), 0.618, all_edge_material);
  cout << "\r376 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(226.462, 156.077, 93.9447),   glm::vec3(347.647, 130.586, 97.38), 0.618, all_edge_material);
  cout << "\r377 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(281.805, 106.806, 135.233),   glm::vec3(213.8, 132.886, 133.383), 0.618, all_edge_material);
  cout << "\r378 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(335.054, 120.631, 109.149),   glm::vec3(325.47, 123.933, 144.325), 0.618, all_edge_material);
  cout << "\r379 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(219.85, 103.914, 152.149),   glm::vec3(231.958, 124.038, 152.657), 0.618, all_edge_material);
  cout << "\r380 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(295.142, 127.957, 145.268),   glm::vec3(273.309, 111.245, 148.738), 0.618, all_edge_material);
  cout << "\r381 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(201.551, 92.8714, 89.0439),   glm::vec3(270.734, 136.763, 116.777), 0.618, all_edge_material);
  cout << "\r382 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(324.078, 174.582, 137.923),   glm::vec3(236.645, 120.721, 136.753), 0.618, all_edge_material);
  cout << "\r383 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(289.733, 115.478, 108.894),   glm::vec3(220.261, 171.091, 119.7), 0.618, all_edge_material);
  cout << "\r384 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(283.146, 160.535, 120.806),   glm::vec3(256.979, 174.355, 126.305), 0.618, all_edge_material);
  cout << "\r385 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(268.213, 112.811, 174.18),   glm::vec3(270.734, 136.763, 116.777), 0.618, all_edge_material);
  cout << "\r386 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(324.078, 174.582, 137.923),   glm::vec3(279.947, 94.6431, 121.084), 0.618, all_edge_material);
  cout << "\r387 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(231.579, 170.935, 156.162),   glm::vec3(281.573, 151.994, 118.424), 0.618, all_edge_material);
  cout << "\r388 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(299.947, 97.1689, 155.855),   glm::vec3(295.481, 92.2876, 166.223), 0.618, all_edge_material);
  cout << "\r389 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(299.947, 97.1689, 155.855),   glm::vec3(231.579, 170.935, 156.162), 0.618, all_edge_material);
  cout << "\r390 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(278.167, 117.29, 130.335),   glm::vec3(249.92, 139.51, 137.883), 0.618, all_edge_material);
  cout << "\r391 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(280.899, 169.051, 84.1632),   glm::vec3(201.551, 92.8714, 89.0439), 0.618, all_edge_material);
  cout << "\r392 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(324.078, 174.582, 137.923),   glm::vec3(296.068, 154.366, 120.41), 0.618, all_edge_material);
  cout << "\r393 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(230.611, 147.359, 152.454),   glm::vec3(273.309, 111.245, 148.738), 0.618, all_edge_material);
  cout << "\r394 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(219.697, 112.623, 133.141),   glm::vec3(265.054, 160.301, 182.015), 0.618, all_edge_material);
  cout << "\r395 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(295.481, 92.2876, 166.223),   glm::vec3(251.151, 111.072, 117.203), 0.618, all_edge_material);
  cout << "\r396 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(280.899, 169.051, 84.1632),   glm::vec3(265.054, 160.301, 182.015), 0.618, all_edge_material);
  cout << "\r397 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(278.167, 117.29, 130.335),   glm::vec3(279.529, 58.4, 138.252), 0.618, all_edge_material);
  cout << "\r398 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(347.647, 130.586, 97.38),   glm::vec3(243.383, 116.649, 103.532), 0.618, all_edge_material);
  cout << "\r399 of 543 voraldo commands";


  main_block->draw_cylinder(glm::vec3(251.354, 80.2382, 115.445),   glm::vec3(295.142, 127.957, 145.268), 1, mst_edge_material);
  cout << "\r400 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(226.462, 156.077, 93.9447),   glm::vec3(269.837, 164.91, 98.8019), 1, mst_edge_material);
  cout << "\r401 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(323.964, 130.536, 145.928),   glm::vec3(229.842, 130.191, 142.118), 1, mst_edge_material);
  cout << "\r402 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(347.647, 130.586, 97.38),   glm::vec3(295.142, 127.957, 145.268), 1, mst_edge_material);
  cout << "\r403 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(251.151, 111.072, 117.203),   glm::vec3(251.354, 80.2382, 115.445), 1, mst_edge_material);
  cout << "\r404 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(274.463, 192.557, 121.335),   glm::vec3(281.805, 106.806, 135.233), 1, mst_edge_material);
  cout << "\r405 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(199.958, 136.418, 146.237),   glm::vec3(229.842, 130.191, 142.118), 1, mst_edge_material);
  cout << "\r406 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(206.485, 118.456, 166.454),   glm::vec3(211.15, 194.522, 116.213), 1, mst_edge_material);
  cout << "\r407 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(295.481, 92.2876, 166.223),   glm::vec3(229.842, 130.191, 142.118), 1, mst_edge_material);
  cout << "\r408 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(215.736, 113.014, 88.8605),   glm::vec3(282.586, 101.719, 155.77), 1, mst_edge_material);
  cout << "\r409 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(249.92, 139.51, 137.883),   glm::vec3(295.142, 127.957, 145.268), 1, mst_edge_material);
  cout << "\r410 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(220.261, 171.091, 119.7),   glm::vec3(241.857, 166.195, 89.3149), 1, mst_edge_material);
  cout << "\r411 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(248.645, 169.631, 161.017),   glm::vec3(282.586, 101.719, 155.77), 1, mst_edge_material);
  cout << "\r412 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(267.546, 111.663, 156.52),   glm::vec3(241.857, 166.195, 89.3149), 1, mst_edge_material);
  cout << "\r413 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(269.837, 164.91, 98.8019),   glm::vec3(241.857, 166.195, 89.3149), 1, mst_edge_material);
  cout << "\r414 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(219.697, 112.623, 133.141),   glm::vec3(282.586, 101.719, 155.77), 1, mst_edge_material);
  cout << "\r415 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(335.054, 120.631, 109.149),   glm::vec3(249.92, 139.51, 137.883), 1, mst_edge_material);
  cout << "\r416 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(229.842, 130.191, 142.118),   glm::vec3(273.309, 111.245, 148.738), 1, mst_edge_material);
  cout << "\r417 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(326.118, 138.141, 168.013),   glm::vec3(269.837, 164.91, 98.8019), 1, mst_edge_material);
  cout << "\r418 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(236.645, 120.721, 136.753),   glm::vec3(219.85, 103.914, 152.149), 1, mst_edge_material);
  cout << "\r419 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(296.068, 154.366, 120.41),   glm::vec3(241.857, 166.195, 89.3149), 1, mst_edge_material);
  cout << "\r420 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(231.958, 124.038, 152.657),   glm::vec3(229.842, 130.191, 142.118), 1, mst_edge_material);
  cout << "\r421 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(211.15, 194.522, 116.213),   glm::vec3(285.88, 175.664, 147.11), 1, mst_edge_material);
  cout << "\r422 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(265.054, 160.301, 182.015),   glm::vec3(323.964, 130.536, 145.928), 1, mst_edge_material);
  cout << "\r423 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(195.946, 129.407, 166.73),   glm::vec3(229.842, 130.191, 142.118), 1, mst_edge_material);
  cout << "\r424 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(233.132, 95.7902, 158.741),   glm::vec3(323.964, 130.536, 145.928), 1, mst_edge_material);
  cout << "\r425 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(285.88, 175.664, 147.11),   glm::vec3(273.309, 111.245, 148.738), 1, mst_edge_material);
  cout << "\r426 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(281.805, 106.806, 135.233),   glm::vec3(296.068, 154.366, 120.41), 1, mst_edge_material);
  cout << "\r427 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(282.586, 101.719, 155.77),   glm::vec3(296.068, 154.366, 120.41), 1, mst_edge_material);
  cout << "\r428 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(217.06, 132.056, 138.933),   glm::vec3(211.15, 194.522, 116.213), 1, mst_edge_material);
  cout << "\r429 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(279.529, 58.4, 138.252),   glm::vec3(291.086, 146.437, 117.919), 1, mst_edge_material);
  cout << "\r430 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(205.859, 104.949, 128.15),   glm::vec3(261.875, 118.151, 115.041), 1, mst_edge_material);
  cout << "\r431 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(279.947, 94.6431, 121.084),   glm::vec3(295.142, 127.957, 145.268), 1, mst_edge_material);
  cout << "\r432 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(274.759, 110.74, 102.544),   glm::vec3(295.142, 127.957, 145.268), 1, mst_edge_material);
  cout << "\r433 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(268.213, 112.811, 174.18),   glm::vec3(285.88, 175.664, 147.11), 1, mst_edge_material);
  cout << "\r434 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(212.119, 104.205, 154.983),   glm::vec3(229.842, 130.191, 142.118), 1, mst_edge_material);
  cout << "\r435 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(201.551, 92.8714, 89.0439),   glm::vec3(273.309, 111.245, 148.738), 1, mst_edge_material);
  cout << "\r436 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(273.309, 111.245, 148.738),   glm::vec3(295.142, 127.957, 145.268), 1, mst_edge_material);
  cout << "\r437 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(306.766, 113.821, 90.2533),   glm::vec3(295.142, 127.957, 145.268), 1, mst_edge_material);
  cout << "\r438 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(231.579, 170.935, 156.162),   glm::vec3(285.88, 175.664, 147.11), 1, mst_edge_material);
  cout << "\r439 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(219.85, 103.914, 152.149),   glm::vec3(243.383, 116.649, 103.532), 1, mst_edge_material);
  cout << "\r440 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(281.573, 151.994, 118.424),   glm::vec3(296.068, 154.366, 120.41), 1, mst_edge_material);
  cout << "\r441 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(293.453, 177.305, 172.066),   glm::vec3(274.463, 192.557, 121.335), 1, mst_edge_material);
  cout << "\r442 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(280.899, 169.051, 84.1632),   glm::vec3(243.383, 116.649, 103.532), 1, mst_edge_material);
  cout << "\r443 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(278.167, 117.29, 130.335),   glm::vec3(295.142, 127.957, 145.268), 1, mst_edge_material);
  cout << "\r444 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(283.146, 160.535, 120.806),   glm::vec3(296.068, 154.366, 120.41), 1, mst_edge_material);
  cout << "\r445 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(182.219, 136.619, 144.539),   glm::vec3(248.645, 169.631, 161.017), 1, mst_edge_material);
  cout << "\r446 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(213.8, 132.886, 133.383),   glm::vec3(229.842, 130.191, 142.118), 1, mst_edge_material);
  cout << "\r447 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(208.791, 115.508, 110.194),   glm::vec3(282.586, 101.719, 155.77), 1, mst_edge_material);
  cout << "\r448 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(289.733, 115.478, 108.894),   glm::vec3(229.842, 130.191, 142.118), 1, mst_edge_material);
  cout << "\r449 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(291.086, 146.437, 117.919),   glm::vec3(279.947, 94.6431, 121.084), 1, mst_edge_material);
  cout << "\r450 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(270.734, 136.763, 116.777),   glm::vec3(268.698, 129.244, 112.916), 1, mst_edge_material);
  cout << "\r451 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(230.958, 174.932, 70.4607),   glm::vec3(201.551, 92.8714, 89.0439), 1, mst_edge_material);
  cout << "\r452 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(251.479, 50.5024, 140.739),   glm::vec3(229.842, 130.191, 142.118), 1, mst_edge_material);
  cout << "\r453 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(241.857, 166.195, 89.3149),   glm::vec3(295.142, 127.957, 145.268), 1, mst_edge_material);
  cout << "\r454 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(243.383, 116.649, 103.532),   glm::vec3(296.068, 154.366, 120.41), 1, mst_edge_material);
  cout << "\r455 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(307.501, 76.8321, 162.574),   glm::vec3(273.309, 111.245, 148.738), 1, mst_edge_material);
  cout << "\r456 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(289.813, 77.1727, 178.895),   glm::vec3(282.586, 101.719, 155.77), 1, mst_edge_material);
  cout << "\r457 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(299.947, 97.1689, 155.855),   glm::vec3(282.586, 101.719, 155.77), 1, mst_edge_material);
  cout << "\r458 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(325.47, 123.933, 144.325),   glm::vec3(289.813, 77.1727, 178.895), 1, mst_edge_material);
  cout << "\r459 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(173.763, 139.293, 155.746),   glm::vec3(219.85, 103.914, 152.149), 1, mst_edge_material);
  cout << "\r460 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(153.409, 118.287, 124.341),   glm::vec3(219.85, 103.914, 152.149), 1, mst_edge_material);
  cout << "\r461 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(290.088, 152.628, 127.04),   glm::vec3(282.586, 101.719, 155.77), 1, mst_edge_material);
  cout << "\r462 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(324.078, 174.582, 137.923),   glm::vec3(295.142, 127.957, 145.268), 1, mst_edge_material);
  cout << "\r463 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(230.611, 147.359, 152.454),   glm::vec3(273.309, 111.245, 148.738), 1, mst_edge_material);
  cout << "\r464 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(261.875, 118.151, 115.041),   glm::vec3(296.068, 154.366, 120.41), 1, mst_edge_material);
  cout << "\r465 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(268.698, 129.244, 112.916),   glm::vec3(229.842, 130.191, 142.118), 1, mst_edge_material);
  cout << "\r466 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(256.979, 174.355, 126.305),   glm::vec3(279.947, 94.6431, 121.084), 1, mst_edge_material);
  cout << "\r467 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(170.902, 95.2746, 107.368),   glm::vec3(251.354, 80.2382, 115.445), 1, mst_edge_material);
  cout << "\r468 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(300.438, 145.625, 149.469),   glm::vec3(219.85, 103.914, 152.149), 1, mst_edge_material);
  cout << "\r469 of 543 voraldo commands";
  main_block->draw_cylinder(glm::vec3(243.085, 150.2, 154.328),   glm::vec3(295.142, 127.957, 145.268), 1, mst_edge_material);
  cout << "\r470 of 543 voraldo commands";


  main_block->draw_sphere(glm::vec3(295.142, 127.957, 145.268), 2.0, vertex_material);
  cout << "\r471 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(251.354, 80.2382, 115.445), 2.0, vertex_material);
  cout << "\r472 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(226.462, 156.077, 93.9447), 2.0, vertex_material);
  cout << "\r473 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(323.964, 130.536, 145.928), 2.0, vertex_material);
  cout << "\r474 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(347.647, 130.586, 97.38), 2.0, vertex_material);
  cout << "\r475 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(251.151, 111.072, 117.203), 2.0, vertex_material);
  cout << "\r476 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(274.463, 192.557, 121.335), 2.0, vertex_material);
  cout << "\r477 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(199.958, 136.418, 146.237), 2.0, vertex_material);
  cout << "\r478 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(206.485, 118.456, 166.454), 2.0, vertex_material);
  cout << "\r479 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(295.481, 92.2876, 166.223), 2.0, vertex_material);
  cout << "\r480 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(215.736, 113.014, 88.8605), 2.0, vertex_material);
  cout << "\r481 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(249.92, 139.51, 137.883), 2.0, vertex_material);
  cout << "\r482 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(220.261, 171.091, 119.7), 2.0, vertex_material);
  cout << "\r483 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(248.645, 169.631, 161.017), 2.0, vertex_material);
  cout << "\r484 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(267.546, 111.663, 156.52), 2.0, vertex_material);
  cout << "\r485 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(269.837, 164.91, 98.8019), 2.0, vertex_material);
  cout << "\r486 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(219.697, 112.623, 133.141), 2.0, vertex_material);
  cout << "\r487 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(335.054, 120.631, 109.149), 2.0, vertex_material);
  cout << "\r488 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(229.842, 130.191, 142.118), 2.0, vertex_material);
  cout << "\r489 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(326.118, 138.141, 168.013), 2.0, vertex_material);
  cout << "\r490 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(236.645, 120.721, 136.753), 2.0, vertex_material);
  cout << "\r491 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(296.068, 154.366, 120.41), 2.0, vertex_material);
  cout << "\r492 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(231.958, 124.038, 152.657), 2.0, vertex_material);
  cout << "\r493 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(211.15, 194.522, 116.213), 2.0, vertex_material);
  cout << "\r494 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(265.054, 160.301, 182.015), 2.0, vertex_material);
  cout << "\r495 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(195.946, 129.407, 166.73), 2.0, vertex_material);
  cout << "\r496 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(233.132, 95.7902, 158.741), 2.0, vertex_material);
  cout << "\r497 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(285.88, 175.664, 147.11), 2.0, vertex_material);
  cout << "\r498 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(281.805, 106.806, 135.233), 2.0, vertex_material);
  cout << "\r499 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(282.586, 101.719, 155.77), 2.0, vertex_material);
  cout << "\r500 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(217.06, 132.056, 138.933), 2.0, vertex_material);
  cout << "\r501 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(279.529, 58.4, 138.252), 2.0, vertex_material);
  cout << "\r502 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(205.859, 104.949, 128.15), 2.0, vertex_material);
  cout << "\r503 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(279.947, 94.6431, 121.084), 2.0, vertex_material);
  cout << "\r504 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(274.759, 110.74, 102.544), 2.0, vertex_material);
  cout << "\r505 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(268.213, 112.811, 174.18), 2.0, vertex_material);
  cout << "\r506 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(212.119, 104.205, 154.983), 2.0, vertex_material);
  cout << "\r507 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(201.551, 92.8714, 89.0439), 2.0, vertex_material);
  cout << "\r508 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(273.309, 111.245, 148.738), 2.0, vertex_material);
  cout << "\r509 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(306.766, 113.821, 90.2533), 2.0, vertex_material);
  cout << "\r510 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(231.579, 170.935, 156.162), 2.0, vertex_material);
  cout << "\r511 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(219.85, 103.914, 152.149), 2.0, vertex_material);
  cout << "\r512 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(281.573, 151.994, 118.424), 2.0, vertex_material);
  cout << "\r513 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(293.453, 177.305, 172.066), 2.0, vertex_material);
  cout << "\r514 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(280.899, 169.051, 84.1632), 2.0, vertex_material);
  cout << "\r515 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(278.167, 117.29, 130.335), 2.0, vertex_material);
  cout << "\r516 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(283.146, 160.535, 120.806), 2.0, vertex_material);
  cout << "\r517 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(182.219, 136.619, 144.539), 2.0, vertex_material);
  cout << "\r518 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(213.8, 132.886, 133.383), 2.0, vertex_material);
  cout << "\r519 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(208.791, 115.508, 110.194), 2.0, vertex_material);
  cout << "\r520 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(289.733, 115.478, 108.894), 2.0, vertex_material);
  cout << "\r521 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(291.086, 146.437, 117.919), 2.0, vertex_material);
  cout << "\r522 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(270.734, 136.763, 116.777), 2.0, vertex_material);
  cout << "\r523 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(230.958, 174.932, 70.4607), 2.0, vertex_material);
  cout << "\r524 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(251.479, 50.5024, 140.739), 2.0, vertex_material);
  cout << "\r525 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(241.857, 166.195, 89.3149), 2.0, vertex_material);
  cout << "\r526 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(243.383, 116.649, 103.532), 2.0, vertex_material);
  cout << "\r527 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(307.501, 76.8321, 162.574), 2.0, vertex_material);
  cout << "\r528 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(289.813, 77.1727, 178.895), 2.0, vertex_material);
  cout << "\r529 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(299.947, 97.1689, 155.855), 2.0, vertex_material);
  cout << "\r530 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(325.47, 123.933, 144.325), 2.0, vertex_material);
  cout << "\r531 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(173.763, 139.293, 155.746), 2.0, vertex_material);
  cout << "\r532 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(153.409, 118.287, 124.341), 2.0, vertex_material);
  cout << "\r533 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(290.088, 152.628, 127.04), 2.0, vertex_material);
  cout << "\r534 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(324.078, 174.582, 137.923), 2.0, vertex_material);
  cout << "\r535 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(230.611, 147.359, 152.454), 2.0, vertex_material);
  cout << "\r536 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(261.875, 118.151, 115.041), 2.0, vertex_material);
  cout << "\r537 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(268.698, 129.244, 112.916), 2.0, vertex_material);
  cout << "\r538 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(256.979, 174.355, 126.305), 2.0, vertex_material);
  cout << "\r539 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(170.902, 95.2746, 107.368), 2.0, vertex_material);
  cout << "\r540 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(300.438, 145.625, 149.469), 2.0, vertex_material);
  cout << "\r541 of 543 voraldo commands";
  main_block->draw_sphere(glm::vec3(243.085, 150.2, 154.328), 2.0, vertex_material);
  cout << "\r542 of 543 voraldo commands";







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
  // main_block->save("current_model/save.png");
  main_block->save(argv[1]);
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
