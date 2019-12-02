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


  // Vox all_edge_material  =  main_block->get_vox(11, 100, false);
  //
  // Vox mst_edge_material  =  main_block->get_vox(61, 255, false);
  //
  // Vox vertex_material  =  main_block->get_vox(15, 80, false);
  //
  // Vox ambient_material  =  main_block->get_vox(58, 1, false);
  //
  // main_block->draw_sphere(glm::vec3(0,0,0), 1000, ambient_material);
  //
  //




  Vox route_material    =  main_block->get_vox(57, 4, false);
  Vox star_material     =  main_block->get_vox(11, 30, false);

  Vox moon_material     =  main_block->get_vox(16, 100, false);
  Vox planet1_material  =  main_block->get_vox(8, 100, false);
  Vox planet2_material  =  main_block->get_vox(9, 100, false);
  Vox planet3_material  =  main_block->get_vox(12, 100, false);
  Vox planet4_material  =  main_block->get_vox(14, 100, false);
  Vox planet5_material  =  main_block->get_vox(18, 100, false);
  Vox station_material  =  main_block->get_vox(58, 100, false);

  Vox space_material  =  main_block->get_vox(61, 1, false);

  main_block->draw_sphere(glm::vec3(0,0,0), 1000, space_material);








  main_block->draw_cylinder(glm::vec3(69.0909, 85.2133, 139.173),   glm::vec3(174.592, 188.534, 108.342), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(69.0909, 85.2133, 139.173),   glm::vec3(85.3172, 65.7291, 69.2922), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(69.0909, 85.2133, 139.173),   glm::vec3(57.3066, 130.108, 199.034), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(69.0909, 85.2133, 139.173),   glm::vec3(284.469, 70.8027, 87.7613), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(69.0909, 85.2133, 139.173),   glm::vec3(75.2432, 58.4495, 51.777), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(69.0909, 85.2133, 139.173),   glm::vec3(88.4057, 99.3099, 153.461), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(69.0909, 85.2133, 139.173),   glm::vec3(229.472, 194.14, 64.3294), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(69.0909, 85.2133, 139.173),   glm::vec3(156.357, 127.319, 86.1865), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(69.0909, 85.2133, 139.173),   glm::vec3(127.739, 153.394, 117.2), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(69.0909, 85.2133, 139.173),   glm::vec3(148.56, 123.498, 79.9355), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(69.0909, 85.2133, 139.173),   glm::vec3(208.96, 148.446, 72.4314), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(69.0909, 85.2133, 139.173),   glm::vec3(123.303, 94.7174, 150.073), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(69.0909, 85.2133, 139.173),   glm::vec3(130.944, 103.267, 139.625), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(69.0909, 85.2133, 139.173),   glm::vec3(193.498, 96.0764, 176.227), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(69.0909, 85.2133, 139.173),   glm::vec3(174.838, 108.035, 175.218), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(69.0909, 85.2133, 139.173),   glm::vec3(142.909, 70.2595, 183.506), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(69.0909, 85.2133, 139.173),   glm::vec3(98.1497, 114.563, 130.275), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(69.0909, 85.2133, 139.173),   glm::vec3(101.073, 188.862, 78.3315), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(69.0909, 85.2133, 139.173),   glm::vec3(95.7662, 173.9, 98.2216), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.592, 188.534, 108.342),   glm::vec3(69.0909, 85.2133, 139.173), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.592, 188.534, 108.342),   glm::vec3(85.3172, 65.7291, 69.2922), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.592, 188.534, 108.342),   glm::vec3(57.3066, 130.108, 199.034), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.592, 188.534, 108.342),   glm::vec3(284.469, 70.8027, 87.7613), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.592, 188.534, 108.342),   glm::vec3(75.2432, 58.4495, 51.777), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.592, 188.534, 108.342),   glm::vec3(88.4057, 99.3099, 153.461), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.592, 188.534, 108.342),   glm::vec3(229.472, 194.14, 64.3294), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.592, 188.534, 108.342),   glm::vec3(156.357, 127.319, 86.1865), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.592, 188.534, 108.342),   glm::vec3(127.739, 153.394, 117.2), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.592, 188.534, 108.342),   glm::vec3(148.56, 123.498, 79.9355), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.592, 188.534, 108.342),   glm::vec3(208.96, 148.446, 72.4314), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.592, 188.534, 108.342),   glm::vec3(123.303, 94.7174, 150.073), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.592, 188.534, 108.342),   glm::vec3(130.944, 103.267, 139.625), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.592, 188.534, 108.342),   glm::vec3(193.498, 96.0764, 176.227), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.592, 188.534, 108.342),   glm::vec3(174.838, 108.035, 175.218), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.592, 188.534, 108.342),   glm::vec3(142.909, 70.2595, 183.506), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.592, 188.534, 108.342),   glm::vec3(98.1497, 114.563, 130.275), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.592, 188.534, 108.342),   glm::vec3(101.073, 188.862, 78.3315), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.592, 188.534, 108.342),   glm::vec3(95.7662, 173.9, 98.2216), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(85.3172, 65.7291, 69.2922),   glm::vec3(69.0909, 85.2133, 139.173), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(85.3172, 65.7291, 69.2922),   glm::vec3(174.592, 188.534, 108.342), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(85.3172, 65.7291, 69.2922),   glm::vec3(57.3066, 130.108, 199.034), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(85.3172, 65.7291, 69.2922),   glm::vec3(284.469, 70.8027, 87.7613), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(85.3172, 65.7291, 69.2922),   glm::vec3(75.2432, 58.4495, 51.777), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(85.3172, 65.7291, 69.2922),   glm::vec3(88.4057, 99.3099, 153.461), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(85.3172, 65.7291, 69.2922),   glm::vec3(229.472, 194.14, 64.3294), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(85.3172, 65.7291, 69.2922),   glm::vec3(156.357, 127.319, 86.1865), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(85.3172, 65.7291, 69.2922),   glm::vec3(127.739, 153.394, 117.2), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(85.3172, 65.7291, 69.2922),   glm::vec3(148.56, 123.498, 79.9355), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(85.3172, 65.7291, 69.2922),   glm::vec3(208.96, 148.446, 72.4314), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(85.3172, 65.7291, 69.2922),   glm::vec3(123.303, 94.7174, 150.073), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(85.3172, 65.7291, 69.2922),   glm::vec3(130.944, 103.267, 139.625), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(85.3172, 65.7291, 69.2922),   glm::vec3(193.498, 96.0764, 176.227), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(85.3172, 65.7291, 69.2922),   glm::vec3(174.838, 108.035, 175.218), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(85.3172, 65.7291, 69.2922),   glm::vec3(142.909, 70.2595, 183.506), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(85.3172, 65.7291, 69.2922),   glm::vec3(98.1497, 114.563, 130.275), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(85.3172, 65.7291, 69.2922),   glm::vec3(101.073, 188.862, 78.3315), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(85.3172, 65.7291, 69.2922),   glm::vec3(95.7662, 173.9, 98.2216), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(57.3066, 130.108, 199.034),   glm::vec3(69.0909, 85.2133, 139.173), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(57.3066, 130.108, 199.034),   glm::vec3(174.592, 188.534, 108.342), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(57.3066, 130.108, 199.034),   glm::vec3(85.3172, 65.7291, 69.2922), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(57.3066, 130.108, 199.034),   glm::vec3(284.469, 70.8027, 87.7613), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(57.3066, 130.108, 199.034),   glm::vec3(75.2432, 58.4495, 51.777), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(57.3066, 130.108, 199.034),   glm::vec3(88.4057, 99.3099, 153.461), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(57.3066, 130.108, 199.034),   glm::vec3(229.472, 194.14, 64.3294), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(57.3066, 130.108, 199.034),   glm::vec3(156.357, 127.319, 86.1865), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(57.3066, 130.108, 199.034),   glm::vec3(127.739, 153.394, 117.2), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(57.3066, 130.108, 199.034),   glm::vec3(148.56, 123.498, 79.9355), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(57.3066, 130.108, 199.034),   glm::vec3(208.96, 148.446, 72.4314), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(57.3066, 130.108, 199.034),   glm::vec3(123.303, 94.7174, 150.073), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(57.3066, 130.108, 199.034),   glm::vec3(130.944, 103.267, 139.625), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(57.3066, 130.108, 199.034),   glm::vec3(193.498, 96.0764, 176.227), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(57.3066, 130.108, 199.034),   glm::vec3(174.838, 108.035, 175.218), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(57.3066, 130.108, 199.034),   glm::vec3(142.909, 70.2595, 183.506), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(57.3066, 130.108, 199.034),   glm::vec3(98.1497, 114.563, 130.275), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(57.3066, 130.108, 199.034),   glm::vec3(101.073, 188.862, 78.3315), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(57.3066, 130.108, 199.034),   glm::vec3(95.7662, 173.9, 98.2216), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(284.469, 70.8027, 87.7613),   glm::vec3(69.0909, 85.2133, 139.173), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(284.469, 70.8027, 87.7613),   glm::vec3(174.592, 188.534, 108.342), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(284.469, 70.8027, 87.7613),   glm::vec3(85.3172, 65.7291, 69.2922), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(284.469, 70.8027, 87.7613),   glm::vec3(57.3066, 130.108, 199.034), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(284.469, 70.8027, 87.7613),   glm::vec3(75.2432, 58.4495, 51.777), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(284.469, 70.8027, 87.7613),   glm::vec3(88.4057, 99.3099, 153.461), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(284.469, 70.8027, 87.7613),   glm::vec3(229.472, 194.14, 64.3294), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(284.469, 70.8027, 87.7613),   glm::vec3(156.357, 127.319, 86.1865), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(284.469, 70.8027, 87.7613),   glm::vec3(127.739, 153.394, 117.2), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(284.469, 70.8027, 87.7613),   glm::vec3(148.56, 123.498, 79.9355), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(284.469, 70.8027, 87.7613),   glm::vec3(208.96, 148.446, 72.4314), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(284.469, 70.8027, 87.7613),   glm::vec3(123.303, 94.7174, 150.073), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(284.469, 70.8027, 87.7613),   glm::vec3(130.944, 103.267, 139.625), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(284.469, 70.8027, 87.7613),   glm::vec3(193.498, 96.0764, 176.227), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(284.469, 70.8027, 87.7613),   glm::vec3(174.838, 108.035, 175.218), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(284.469, 70.8027, 87.7613),   glm::vec3(142.909, 70.2595, 183.506), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(284.469, 70.8027, 87.7613),   glm::vec3(98.1497, 114.563, 130.275), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(284.469, 70.8027, 87.7613),   glm::vec3(101.073, 188.862, 78.3315), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(284.469, 70.8027, 87.7613),   glm::vec3(95.7662, 173.9, 98.2216), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(75.2432, 58.4495, 51.777),   glm::vec3(69.0909, 85.2133, 139.173), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(75.2432, 58.4495, 51.777),   glm::vec3(174.592, 188.534, 108.342), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(75.2432, 58.4495, 51.777),   glm::vec3(85.3172, 65.7291, 69.2922), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(75.2432, 58.4495, 51.777),   glm::vec3(57.3066, 130.108, 199.034), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(75.2432, 58.4495, 51.777),   glm::vec3(284.469, 70.8027, 87.7613), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(75.2432, 58.4495, 51.777),   glm::vec3(88.4057, 99.3099, 153.461), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(75.2432, 58.4495, 51.777),   glm::vec3(229.472, 194.14, 64.3294), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(75.2432, 58.4495, 51.777),   glm::vec3(156.357, 127.319, 86.1865), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(75.2432, 58.4495, 51.777),   glm::vec3(127.739, 153.394, 117.2), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(75.2432, 58.4495, 51.777),   glm::vec3(148.56, 123.498, 79.9355), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(75.2432, 58.4495, 51.777),   glm::vec3(208.96, 148.446, 72.4314), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(75.2432, 58.4495, 51.777),   glm::vec3(123.303, 94.7174, 150.073), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(75.2432, 58.4495, 51.777),   glm::vec3(130.944, 103.267, 139.625), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(75.2432, 58.4495, 51.777),   glm::vec3(193.498, 96.0764, 176.227), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(75.2432, 58.4495, 51.777),   glm::vec3(174.838, 108.035, 175.218), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(75.2432, 58.4495, 51.777),   glm::vec3(142.909, 70.2595, 183.506), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(75.2432, 58.4495, 51.777),   glm::vec3(98.1497, 114.563, 130.275), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(75.2432, 58.4495, 51.777),   glm::vec3(101.073, 188.862, 78.3315), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(75.2432, 58.4495, 51.777),   glm::vec3(95.7662, 173.9, 98.2216), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(88.4057, 99.3099, 153.461),   glm::vec3(69.0909, 85.2133, 139.173), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(88.4057, 99.3099, 153.461),   glm::vec3(174.592, 188.534, 108.342), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(88.4057, 99.3099, 153.461),   glm::vec3(85.3172, 65.7291, 69.2922), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(88.4057, 99.3099, 153.461),   glm::vec3(57.3066, 130.108, 199.034), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(88.4057, 99.3099, 153.461),   glm::vec3(284.469, 70.8027, 87.7613), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(88.4057, 99.3099, 153.461),   glm::vec3(75.2432, 58.4495, 51.777), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(88.4057, 99.3099, 153.461),   glm::vec3(229.472, 194.14, 64.3294), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(88.4057, 99.3099, 153.461),   glm::vec3(156.357, 127.319, 86.1865), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(88.4057, 99.3099, 153.461),   glm::vec3(127.739, 153.394, 117.2), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(88.4057, 99.3099, 153.461),   glm::vec3(148.56, 123.498, 79.9355), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(88.4057, 99.3099, 153.461),   glm::vec3(208.96, 148.446, 72.4314), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(88.4057, 99.3099, 153.461),   glm::vec3(123.303, 94.7174, 150.073), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(88.4057, 99.3099, 153.461),   glm::vec3(130.944, 103.267, 139.625), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(88.4057, 99.3099, 153.461),   glm::vec3(193.498, 96.0764, 176.227), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(88.4057, 99.3099, 153.461),   glm::vec3(174.838, 108.035, 175.218), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(88.4057, 99.3099, 153.461),   glm::vec3(142.909, 70.2595, 183.506), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(88.4057, 99.3099, 153.461),   glm::vec3(98.1497, 114.563, 130.275), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(88.4057, 99.3099, 153.461),   glm::vec3(101.073, 188.862, 78.3315), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(88.4057, 99.3099, 153.461),   glm::vec3(95.7662, 173.9, 98.2216), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(229.472, 194.14, 64.3294),   glm::vec3(69.0909, 85.2133, 139.173), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(229.472, 194.14, 64.3294),   glm::vec3(174.592, 188.534, 108.342), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(229.472, 194.14, 64.3294),   glm::vec3(85.3172, 65.7291, 69.2922), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(229.472, 194.14, 64.3294),   glm::vec3(57.3066, 130.108, 199.034), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(229.472, 194.14, 64.3294),   glm::vec3(284.469, 70.8027, 87.7613), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(229.472, 194.14, 64.3294),   glm::vec3(75.2432, 58.4495, 51.777), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(229.472, 194.14, 64.3294),   glm::vec3(88.4057, 99.3099, 153.461), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(229.472, 194.14, 64.3294),   glm::vec3(156.357, 127.319, 86.1865), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(229.472, 194.14, 64.3294),   glm::vec3(127.739, 153.394, 117.2), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(229.472, 194.14, 64.3294),   glm::vec3(148.56, 123.498, 79.9355), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(229.472, 194.14, 64.3294),   glm::vec3(208.96, 148.446, 72.4314), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(229.472, 194.14, 64.3294),   glm::vec3(123.303, 94.7174, 150.073), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(229.472, 194.14, 64.3294),   glm::vec3(130.944, 103.267, 139.625), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(229.472, 194.14, 64.3294),   glm::vec3(193.498, 96.0764, 176.227), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(229.472, 194.14, 64.3294),   glm::vec3(174.838, 108.035, 175.218), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(229.472, 194.14, 64.3294),   glm::vec3(142.909, 70.2595, 183.506), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(229.472, 194.14, 64.3294),   glm::vec3(98.1497, 114.563, 130.275), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(229.472, 194.14, 64.3294),   glm::vec3(101.073, 188.862, 78.3315), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(229.472, 194.14, 64.3294),   glm::vec3(95.7662, 173.9, 98.2216), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(156.357, 127.319, 86.1865),   glm::vec3(69.0909, 85.2133, 139.173), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(156.357, 127.319, 86.1865),   glm::vec3(174.592, 188.534, 108.342), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(156.357, 127.319, 86.1865),   glm::vec3(85.3172, 65.7291, 69.2922), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(156.357, 127.319, 86.1865),   glm::vec3(57.3066, 130.108, 199.034), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(156.357, 127.319, 86.1865),   glm::vec3(284.469, 70.8027, 87.7613), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(156.357, 127.319, 86.1865),   glm::vec3(75.2432, 58.4495, 51.777), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(156.357, 127.319, 86.1865),   glm::vec3(88.4057, 99.3099, 153.461), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(156.357, 127.319, 86.1865),   glm::vec3(229.472, 194.14, 64.3294), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(156.357, 127.319, 86.1865),   glm::vec3(127.739, 153.394, 117.2), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(156.357, 127.319, 86.1865),   glm::vec3(148.56, 123.498, 79.9355), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(156.357, 127.319, 86.1865),   glm::vec3(208.96, 148.446, 72.4314), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(156.357, 127.319, 86.1865),   glm::vec3(123.303, 94.7174, 150.073), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(156.357, 127.319, 86.1865),   glm::vec3(130.944, 103.267, 139.625), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(156.357, 127.319, 86.1865),   glm::vec3(193.498, 96.0764, 176.227), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(156.357, 127.319, 86.1865),   glm::vec3(174.838, 108.035, 175.218), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(156.357, 127.319, 86.1865),   glm::vec3(142.909, 70.2595, 183.506), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(156.357, 127.319, 86.1865),   glm::vec3(98.1497, 114.563, 130.275), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(156.357, 127.319, 86.1865),   glm::vec3(101.073, 188.862, 78.3315), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(156.357, 127.319, 86.1865),   glm::vec3(95.7662, 173.9, 98.2216), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(127.739, 153.394, 117.2),   glm::vec3(69.0909, 85.2133, 139.173), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(127.739, 153.394, 117.2),   glm::vec3(174.592, 188.534, 108.342), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(127.739, 153.394, 117.2),   glm::vec3(85.3172, 65.7291, 69.2922), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(127.739, 153.394, 117.2),   glm::vec3(57.3066, 130.108, 199.034), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(127.739, 153.394, 117.2),   glm::vec3(284.469, 70.8027, 87.7613), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(127.739, 153.394, 117.2),   glm::vec3(75.2432, 58.4495, 51.777), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(127.739, 153.394, 117.2),   glm::vec3(88.4057, 99.3099, 153.461), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(127.739, 153.394, 117.2),   glm::vec3(229.472, 194.14, 64.3294), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(127.739, 153.394, 117.2),   glm::vec3(156.357, 127.319, 86.1865), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(127.739, 153.394, 117.2),   glm::vec3(148.56, 123.498, 79.9355), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(127.739, 153.394, 117.2),   glm::vec3(208.96, 148.446, 72.4314), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(127.739, 153.394, 117.2),   glm::vec3(123.303, 94.7174, 150.073), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(127.739, 153.394, 117.2),   glm::vec3(130.944, 103.267, 139.625), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(127.739, 153.394, 117.2),   glm::vec3(193.498, 96.0764, 176.227), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(127.739, 153.394, 117.2),   glm::vec3(174.838, 108.035, 175.218), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(127.739, 153.394, 117.2),   glm::vec3(142.909, 70.2595, 183.506), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(127.739, 153.394, 117.2),   glm::vec3(98.1497, 114.563, 130.275), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(127.739, 153.394, 117.2),   glm::vec3(101.073, 188.862, 78.3315), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(127.739, 153.394, 117.2),   glm::vec3(95.7662, 173.9, 98.2216), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(148.56, 123.498, 79.9355),   glm::vec3(69.0909, 85.2133, 139.173), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(148.56, 123.498, 79.9355),   glm::vec3(174.592, 188.534, 108.342), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(148.56, 123.498, 79.9355),   glm::vec3(85.3172, 65.7291, 69.2922), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(148.56, 123.498, 79.9355),   glm::vec3(57.3066, 130.108, 199.034), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(148.56, 123.498, 79.9355),   glm::vec3(284.469, 70.8027, 87.7613), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(148.56, 123.498, 79.9355),   glm::vec3(75.2432, 58.4495, 51.777), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(148.56, 123.498, 79.9355),   glm::vec3(88.4057, 99.3099, 153.461), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(148.56, 123.498, 79.9355),   glm::vec3(229.472, 194.14, 64.3294), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(148.56, 123.498, 79.9355),   glm::vec3(156.357, 127.319, 86.1865), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(148.56, 123.498, 79.9355),   glm::vec3(127.739, 153.394, 117.2), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(148.56, 123.498, 79.9355),   glm::vec3(208.96, 148.446, 72.4314), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(148.56, 123.498, 79.9355),   glm::vec3(123.303, 94.7174, 150.073), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(148.56, 123.498, 79.9355),   glm::vec3(130.944, 103.267, 139.625), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(148.56, 123.498, 79.9355),   glm::vec3(193.498, 96.0764, 176.227), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(148.56, 123.498, 79.9355),   glm::vec3(174.838, 108.035, 175.218), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(148.56, 123.498, 79.9355),   glm::vec3(142.909, 70.2595, 183.506), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(148.56, 123.498, 79.9355),   glm::vec3(98.1497, 114.563, 130.275), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(148.56, 123.498, 79.9355),   glm::vec3(101.073, 188.862, 78.3315), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(148.56, 123.498, 79.9355),   glm::vec3(95.7662, 173.9, 98.2216), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(208.96, 148.446, 72.4314),   glm::vec3(69.0909, 85.2133, 139.173), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(208.96, 148.446, 72.4314),   glm::vec3(174.592, 188.534, 108.342), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(208.96, 148.446, 72.4314),   glm::vec3(85.3172, 65.7291, 69.2922), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(208.96, 148.446, 72.4314),   glm::vec3(57.3066, 130.108, 199.034), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(208.96, 148.446, 72.4314),   glm::vec3(284.469, 70.8027, 87.7613), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(208.96, 148.446, 72.4314),   glm::vec3(75.2432, 58.4495, 51.777), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(208.96, 148.446, 72.4314),   glm::vec3(88.4057, 99.3099, 153.461), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(208.96, 148.446, 72.4314),   glm::vec3(229.472, 194.14, 64.3294), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(208.96, 148.446, 72.4314),   glm::vec3(156.357, 127.319, 86.1865), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(208.96, 148.446, 72.4314),   glm::vec3(127.739, 153.394, 117.2), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(208.96, 148.446, 72.4314),   glm::vec3(148.56, 123.498, 79.9355), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(208.96, 148.446, 72.4314),   glm::vec3(123.303, 94.7174, 150.073), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(208.96, 148.446, 72.4314),   glm::vec3(130.944, 103.267, 139.625), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(208.96, 148.446, 72.4314),   glm::vec3(193.498, 96.0764, 176.227), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(208.96, 148.446, 72.4314),   glm::vec3(174.838, 108.035, 175.218), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(208.96, 148.446, 72.4314),   glm::vec3(142.909, 70.2595, 183.506), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(208.96, 148.446, 72.4314),   glm::vec3(98.1497, 114.563, 130.275), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(208.96, 148.446, 72.4314),   glm::vec3(101.073, 188.862, 78.3315), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(208.96, 148.446, 72.4314),   glm::vec3(95.7662, 173.9, 98.2216), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(123.303, 94.7174, 150.073),   glm::vec3(69.0909, 85.2133, 139.173), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(123.303, 94.7174, 150.073),   glm::vec3(174.592, 188.534, 108.342), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(123.303, 94.7174, 150.073),   glm::vec3(85.3172, 65.7291, 69.2922), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(123.303, 94.7174, 150.073),   glm::vec3(57.3066, 130.108, 199.034), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(123.303, 94.7174, 150.073),   glm::vec3(284.469, 70.8027, 87.7613), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(123.303, 94.7174, 150.073),   glm::vec3(75.2432, 58.4495, 51.777), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(123.303, 94.7174, 150.073),   glm::vec3(88.4057, 99.3099, 153.461), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(123.303, 94.7174, 150.073),   glm::vec3(229.472, 194.14, 64.3294), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(123.303, 94.7174, 150.073),   glm::vec3(156.357, 127.319, 86.1865), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(123.303, 94.7174, 150.073),   glm::vec3(127.739, 153.394, 117.2), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(123.303, 94.7174, 150.073),   glm::vec3(148.56, 123.498, 79.9355), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(123.303, 94.7174, 150.073),   glm::vec3(208.96, 148.446, 72.4314), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(123.303, 94.7174, 150.073),   glm::vec3(130.944, 103.267, 139.625), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(123.303, 94.7174, 150.073),   glm::vec3(193.498, 96.0764, 176.227), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(123.303, 94.7174, 150.073),   glm::vec3(174.838, 108.035, 175.218), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(123.303, 94.7174, 150.073),   glm::vec3(142.909, 70.2595, 183.506), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(123.303, 94.7174, 150.073),   glm::vec3(98.1497, 114.563, 130.275), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(123.303, 94.7174, 150.073),   glm::vec3(101.073, 188.862, 78.3315), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(123.303, 94.7174, 150.073),   glm::vec3(95.7662, 173.9, 98.2216), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(130.944, 103.267, 139.625),   glm::vec3(69.0909, 85.2133, 139.173), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(130.944, 103.267, 139.625),   glm::vec3(174.592, 188.534, 108.342), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(130.944, 103.267, 139.625),   glm::vec3(85.3172, 65.7291, 69.2922), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(130.944, 103.267, 139.625),   glm::vec3(57.3066, 130.108, 199.034), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(130.944, 103.267, 139.625),   glm::vec3(284.469, 70.8027, 87.7613), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(130.944, 103.267, 139.625),   glm::vec3(75.2432, 58.4495, 51.777), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(130.944, 103.267, 139.625),   glm::vec3(88.4057, 99.3099, 153.461), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(130.944, 103.267, 139.625),   glm::vec3(229.472, 194.14, 64.3294), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(130.944, 103.267, 139.625),   glm::vec3(156.357, 127.319, 86.1865), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(130.944, 103.267, 139.625),   glm::vec3(127.739, 153.394, 117.2), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(130.944, 103.267, 139.625),   glm::vec3(148.56, 123.498, 79.9355), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(130.944, 103.267, 139.625),   glm::vec3(208.96, 148.446, 72.4314), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(130.944, 103.267, 139.625),   glm::vec3(123.303, 94.7174, 150.073), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(130.944, 103.267, 139.625),   glm::vec3(193.498, 96.0764, 176.227), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(130.944, 103.267, 139.625),   glm::vec3(174.838, 108.035, 175.218), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(130.944, 103.267, 139.625),   glm::vec3(142.909, 70.2595, 183.506), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(130.944, 103.267, 139.625),   glm::vec3(98.1497, 114.563, 130.275), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(130.944, 103.267, 139.625),   glm::vec3(101.073, 188.862, 78.3315), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(130.944, 103.267, 139.625),   glm::vec3(95.7662, 173.9, 98.2216), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(193.498, 96.0764, 176.227),   glm::vec3(69.0909, 85.2133, 139.173), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(193.498, 96.0764, 176.227),   glm::vec3(174.592, 188.534, 108.342), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(193.498, 96.0764, 176.227),   glm::vec3(85.3172, 65.7291, 69.2922), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(193.498, 96.0764, 176.227),   glm::vec3(57.3066, 130.108, 199.034), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(193.498, 96.0764, 176.227),   glm::vec3(284.469, 70.8027, 87.7613), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(193.498, 96.0764, 176.227),   glm::vec3(75.2432, 58.4495, 51.777), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(193.498, 96.0764, 176.227),   glm::vec3(88.4057, 99.3099, 153.461), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(193.498, 96.0764, 176.227),   glm::vec3(229.472, 194.14, 64.3294), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(193.498, 96.0764, 176.227),   glm::vec3(156.357, 127.319, 86.1865), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(193.498, 96.0764, 176.227),   glm::vec3(127.739, 153.394, 117.2), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(193.498, 96.0764, 176.227),   glm::vec3(148.56, 123.498, 79.9355), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(193.498, 96.0764, 176.227),   glm::vec3(208.96, 148.446, 72.4314), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(193.498, 96.0764, 176.227),   glm::vec3(123.303, 94.7174, 150.073), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(193.498, 96.0764, 176.227),   glm::vec3(130.944, 103.267, 139.625), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(193.498, 96.0764, 176.227),   glm::vec3(174.838, 108.035, 175.218), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(193.498, 96.0764, 176.227),   glm::vec3(142.909, 70.2595, 183.506), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(193.498, 96.0764, 176.227),   glm::vec3(98.1497, 114.563, 130.275), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(193.498, 96.0764, 176.227),   glm::vec3(101.073, 188.862, 78.3315), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(193.498, 96.0764, 176.227),   glm::vec3(95.7662, 173.9, 98.2216), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.838, 108.035, 175.218),   glm::vec3(69.0909, 85.2133, 139.173), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.838, 108.035, 175.218),   glm::vec3(174.592, 188.534, 108.342), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.838, 108.035, 175.218),   glm::vec3(85.3172, 65.7291, 69.2922), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.838, 108.035, 175.218),   glm::vec3(57.3066, 130.108, 199.034), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.838, 108.035, 175.218),   glm::vec3(284.469, 70.8027, 87.7613), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.838, 108.035, 175.218),   glm::vec3(75.2432, 58.4495, 51.777), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.838, 108.035, 175.218),   glm::vec3(88.4057, 99.3099, 153.461), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.838, 108.035, 175.218),   glm::vec3(229.472, 194.14, 64.3294), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.838, 108.035, 175.218),   glm::vec3(156.357, 127.319, 86.1865), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.838, 108.035, 175.218),   glm::vec3(127.739, 153.394, 117.2), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.838, 108.035, 175.218),   glm::vec3(148.56, 123.498, 79.9355), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.838, 108.035, 175.218),   glm::vec3(208.96, 148.446, 72.4314), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.838, 108.035, 175.218),   glm::vec3(123.303, 94.7174, 150.073), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.838, 108.035, 175.218),   glm::vec3(130.944, 103.267, 139.625), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.838, 108.035, 175.218),   glm::vec3(193.498, 96.0764, 176.227), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.838, 108.035, 175.218),   glm::vec3(142.909, 70.2595, 183.506), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.838, 108.035, 175.218),   glm::vec3(98.1497, 114.563, 130.275), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.838, 108.035, 175.218),   glm::vec3(101.073, 188.862, 78.3315), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(174.838, 108.035, 175.218),   glm::vec3(95.7662, 173.9, 98.2216), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(142.909, 70.2595, 183.506),   glm::vec3(69.0909, 85.2133, 139.173), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(142.909, 70.2595, 183.506),   glm::vec3(174.592, 188.534, 108.342), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(142.909, 70.2595, 183.506),   glm::vec3(85.3172, 65.7291, 69.2922), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(142.909, 70.2595, 183.506),   glm::vec3(57.3066, 130.108, 199.034), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(142.909, 70.2595, 183.506),   glm::vec3(284.469, 70.8027, 87.7613), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(142.909, 70.2595, 183.506),   glm::vec3(75.2432, 58.4495, 51.777), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(142.909, 70.2595, 183.506),   glm::vec3(88.4057, 99.3099, 153.461), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(142.909, 70.2595, 183.506),   glm::vec3(229.472, 194.14, 64.3294), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(142.909, 70.2595, 183.506),   glm::vec3(156.357, 127.319, 86.1865), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(142.909, 70.2595, 183.506),   glm::vec3(127.739, 153.394, 117.2), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(142.909, 70.2595, 183.506),   glm::vec3(148.56, 123.498, 79.9355), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(142.909, 70.2595, 183.506),   glm::vec3(208.96, 148.446, 72.4314), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(142.909, 70.2595, 183.506),   glm::vec3(123.303, 94.7174, 150.073), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(142.909, 70.2595, 183.506),   glm::vec3(130.944, 103.267, 139.625), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(142.909, 70.2595, 183.506),   glm::vec3(193.498, 96.0764, 176.227), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(142.909, 70.2595, 183.506),   glm::vec3(174.838, 108.035, 175.218), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(142.909, 70.2595, 183.506),   glm::vec3(98.1497, 114.563, 130.275), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(142.909, 70.2595, 183.506),   glm::vec3(101.073, 188.862, 78.3315), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(142.909, 70.2595, 183.506),   glm::vec3(95.7662, 173.9, 98.2216), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(98.1497, 114.563, 130.275),   glm::vec3(69.0909, 85.2133, 139.173), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(98.1497, 114.563, 130.275),   glm::vec3(174.592, 188.534, 108.342), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(98.1497, 114.563, 130.275),   glm::vec3(85.3172, 65.7291, 69.2922), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(98.1497, 114.563, 130.275),   glm::vec3(57.3066, 130.108, 199.034), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(98.1497, 114.563, 130.275),   glm::vec3(284.469, 70.8027, 87.7613), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(98.1497, 114.563, 130.275),   glm::vec3(75.2432, 58.4495, 51.777), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(98.1497, 114.563, 130.275),   glm::vec3(88.4057, 99.3099, 153.461), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(98.1497, 114.563, 130.275),   glm::vec3(229.472, 194.14, 64.3294), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(98.1497, 114.563, 130.275),   glm::vec3(156.357, 127.319, 86.1865), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(98.1497, 114.563, 130.275),   glm::vec3(127.739, 153.394, 117.2), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(98.1497, 114.563, 130.275),   glm::vec3(148.56, 123.498, 79.9355), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(98.1497, 114.563, 130.275),   glm::vec3(208.96, 148.446, 72.4314), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(98.1497, 114.563, 130.275),   glm::vec3(123.303, 94.7174, 150.073), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(98.1497, 114.563, 130.275),   glm::vec3(130.944, 103.267, 139.625), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(98.1497, 114.563, 130.275),   glm::vec3(193.498, 96.0764, 176.227), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(98.1497, 114.563, 130.275),   glm::vec3(174.838, 108.035, 175.218), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(98.1497, 114.563, 130.275),   glm::vec3(142.909, 70.2595, 183.506), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(98.1497, 114.563, 130.275),   glm::vec3(101.073, 188.862, 78.3315), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(98.1497, 114.563, 130.275),   glm::vec3(95.7662, 173.9, 98.2216), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(101.073, 188.862, 78.3315),   glm::vec3(69.0909, 85.2133, 139.173), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(101.073, 188.862, 78.3315),   glm::vec3(174.592, 188.534, 108.342), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(101.073, 188.862, 78.3315),   glm::vec3(85.3172, 65.7291, 69.2922), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(101.073, 188.862, 78.3315),   glm::vec3(57.3066, 130.108, 199.034), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(101.073, 188.862, 78.3315),   glm::vec3(284.469, 70.8027, 87.7613), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(101.073, 188.862, 78.3315),   glm::vec3(75.2432, 58.4495, 51.777), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(101.073, 188.862, 78.3315),   glm::vec3(88.4057, 99.3099, 153.461), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(101.073, 188.862, 78.3315),   glm::vec3(229.472, 194.14, 64.3294), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(101.073, 188.862, 78.3315),   glm::vec3(156.357, 127.319, 86.1865), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(101.073, 188.862, 78.3315),   glm::vec3(127.739, 153.394, 117.2), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(101.073, 188.862, 78.3315),   glm::vec3(148.56, 123.498, 79.9355), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(101.073, 188.862, 78.3315),   glm::vec3(208.96, 148.446, 72.4314), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(101.073, 188.862, 78.3315),   glm::vec3(123.303, 94.7174, 150.073), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(101.073, 188.862, 78.3315),   glm::vec3(130.944, 103.267, 139.625), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(101.073, 188.862, 78.3315),   glm::vec3(193.498, 96.0764, 176.227), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(101.073, 188.862, 78.3315),   glm::vec3(174.838, 108.035, 175.218), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(101.073, 188.862, 78.3315),   glm::vec3(142.909, 70.2595, 183.506), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(101.073, 188.862, 78.3315),   glm::vec3(98.1497, 114.563, 130.275), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(101.073, 188.862, 78.3315),   glm::vec3(95.7662, 173.9, 98.2216), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(95.7662, 173.9, 98.2216),   glm::vec3(69.0909, 85.2133, 139.173), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(95.7662, 173.9, 98.2216),   glm::vec3(174.592, 188.534, 108.342), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(95.7662, 173.9, 98.2216),   glm::vec3(85.3172, 65.7291, 69.2922), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(95.7662, 173.9, 98.2216),   glm::vec3(57.3066, 130.108, 199.034), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(95.7662, 173.9, 98.2216),   glm::vec3(284.469, 70.8027, 87.7613), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(95.7662, 173.9, 98.2216),   glm::vec3(75.2432, 58.4495, 51.777), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(95.7662, 173.9, 98.2216),   glm::vec3(88.4057, 99.3099, 153.461), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(95.7662, 173.9, 98.2216),   glm::vec3(229.472, 194.14, 64.3294), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(95.7662, 173.9, 98.2216),   glm::vec3(156.357, 127.319, 86.1865), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(95.7662, 173.9, 98.2216),   glm::vec3(127.739, 153.394, 117.2), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(95.7662, 173.9, 98.2216),   glm::vec3(148.56, 123.498, 79.9355), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(95.7662, 173.9, 98.2216),   glm::vec3(208.96, 148.446, 72.4314), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(95.7662, 173.9, 98.2216),   glm::vec3(123.303, 94.7174, 150.073), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(95.7662, 173.9, 98.2216),   glm::vec3(130.944, 103.267, 139.625), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(95.7662, 173.9, 98.2216),   glm::vec3(193.498, 96.0764, 176.227), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(95.7662, 173.9, 98.2216),   glm::vec3(174.838, 108.035, 175.218), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(95.7662, 173.9, 98.2216),   glm::vec3(142.909, 70.2595, 183.506), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(95.7662, 173.9, 98.2216),   glm::vec3(98.1497, 114.563, 130.275), 0.618, route_material);
  main_block->draw_cylinder(glm::vec3(95.7662, 173.9, 98.2216),   glm::vec3(101.073, 188.862, 78.3315), 0.618, route_material);
  main_block->draw_sphere(glm::vec3(69.0909, 85.2133, 139.173), 2.28389, star_material);
  main_block->draw_sphere(glm::vec3(174.592, 188.534, 108.342), 1.74198, star_material);
  main_block->draw_sphere(glm::vec3(85.3172, 65.7291, 69.2922), 1.4457, star_material);
  main_block->draw_sphere(glm::vec3(57.3066, 130.108, 199.034), 1.50727, star_material);
  main_block->draw_sphere(glm::vec3(284.469, 70.8027, 87.7613), 2.7407, star_material);
  main_block->draw_sphere(glm::vec3(75.2432, 58.4495, 51.777), 2.46499, star_material);
  main_block->draw_sphere(glm::vec3(88.4057, 99.3099, 153.461), 1.64497, star_material);
  main_block->draw_sphere(glm::vec3(229.472, 194.14, 64.3294), 1.63157, star_material);
  main_block->draw_sphere(glm::vec3(156.357, 127.319, 86.1865), 1.6185, star_material);
  main_block->draw_sphere(glm::vec3(127.739, 153.394, 117.2), 2.64242, star_material);
  main_block->draw_sphere(glm::vec3(148.56, 123.498, 79.9355), 2.09894, star_material);
  main_block->draw_sphere(glm::vec3(208.96, 148.446, 72.4314), 2.98028, star_material);
  main_block->draw_sphere(glm::vec3(123.303, 94.7174, 150.073), 2.0181, star_material);
  main_block->draw_sphere(glm::vec3(130.944, 103.267, 139.625), 2.99728, star_material);
  main_block->draw_sphere(glm::vec3(193.498, 96.0764, 176.227), 2.31312, star_material);
  main_block->draw_sphere(glm::vec3(174.838, 108.035, 175.218), 2.88209, star_material);
  main_block->draw_sphere(glm::vec3(142.909, 70.2595, 183.506), 1.63294, star_material);
  main_block->draw_sphere(glm::vec3(98.1497, 114.563, 130.275), 2.61783, star_material);
  main_block->draw_sphere(glm::vec3(101.073, 188.862, 78.3315), 2.13324, star_material);
  main_block->draw_sphere(glm::vec3(95.7662, 173.9, 98.2216), 1.55331, star_material);
  main_block->draw_sphere(glm::vec3(60.4933, 78.1557, 143.253), 2.12512, planet3_material);
  main_block->draw_sphere(glm::vec3(167.392, 194.038, 100.819), 2.25224, planet1_material);
  main_block->draw_sphere(glm::vec3(91.8097, 55.7445, 81.8659), 1.80784, station_material);
  main_block->draw_sphere(glm::vec3(73.7118, 53.4471, 74.6932), 2.20184, planet1_material);
  main_block->draw_sphere(glm::vec3(97.0705, 65.4039, 67.2093), 1.2197, planet2_material);
  main_block->draw_sphere(glm::vec3(91.3245, 67.1548, 77.5878), 1.28076, planet5_material);
  main_block->draw_sphere(glm::vec3(66.205, 137.138, 191.432), 1.87172, moon_material);
  main_block->draw_sphere(glm::vec3(55.6758, 122.895, 203.08), 1.5146, station_material);
  main_block->draw_sphere(glm::vec3(64.1364, 128.754, 192.311), 2.03047, planet2_material);
  main_block->draw_sphere(glm::vec3(293.926, 65.4466, 74.4425), 1.97213, planet5_material);
  main_block->draw_sphere(glm::vec3(290.277, 64.9621, 92.5445), 1.57409, planet4_material);
  main_block->draw_sphere(glm::vec3(282.678, 75.3371, 88.2735), 1.17283, planet1_material);
  main_block->draw_sphere(glm::vec3(284.21, 77.9026, 80.9227), 1.9074, station_material);
  main_block->draw_sphere(glm::vec3(270.692, 79.7194, 83.3947), 1.17652, station_material);
  main_block->draw_sphere(glm::vec3(270.062, 81.0691, 94.8212), 2.17714, moon_material);
  main_block->draw_sphere(glm::vec3(60.8514, 63.7166, 46.5512), 1.98396, planet5_material);
  main_block->draw_sphere(glm::vec3(86.6305, 61.4621, 63.9033), 1.94301, planet1_material);
  main_block->draw_sphere(glm::vec3(69.6202, 57.5577, 45.3688), 1.59558, planet1_material);
  main_block->draw_sphere(glm::vec3(61.1464, 56.3741, 38.9759), 1.19959, planet5_material);
  main_block->draw_sphere(glm::vec3(66.806, 57.3385, 42.6627), 2.2489, moon_material);
  main_block->draw_sphere(glm::vec3(73.9863, 58.4962, 66.2877), 1.97446, moon_material);
  main_block->draw_sphere(glm::vec3(85.7774, 106.952, 153.747), 1.49792, planet3_material);
  main_block->draw_sphere(glm::vec3(94.3197, 108.918, 147.444), 1.24126, planet5_material);
  main_block->draw_sphere(glm::vec3(90.3354, 106.641, 143.856), 1.12496, planet1_material);
  main_block->draw_sphere(glm::vec3(77.1154, 111.151, 140.478), 1.60226, planet3_material);
  main_block->draw_sphere(glm::vec3(236.721, 203.607, 68.138), 1.44123, station_material);
  main_block->draw_sphere(glm::vec3(226.514, 183.065, 68.975), 1.75739, planet2_material);
  main_block->draw_sphere(glm::vec3(150.761, 123.739, 92.7877), 1.81102, planet5_material);
  main_block->draw_sphere(glm::vec3(167.674, 124.478, 93.7001), 1.95672, moon_material);
  main_block->draw_sphere(glm::vec3(171.301, 136.072, 73.0281), 2.18175, planet4_material);
  main_block->draw_sphere(glm::vec3(138.216, 166.097, 116.875), 2.07363, station_material);
  main_block->draw_sphere(glm::vec3(129.438, 150.47, 119.842), 1.70825, planet1_material);
  main_block->draw_sphere(glm::vec3(140.426, 161.748, 127.576), 1.47759, planet2_material);
  main_block->draw_sphere(glm::vec3(156.959, 109.074, 70.6509), 1.9616, planet3_material);
  main_block->draw_sphere(glm::vec3(138.807, 124.142, 80.7328), 2.03685, moon_material);
  main_block->draw_sphere(glm::vec3(138.52, 128.907, 91.0911), 1.32022, station_material);
  main_block->draw_sphere(glm::vec3(147.914, 121.88, 84.2678), 1.40504, planet3_material);
  main_block->draw_sphere(glm::vec3(156.931, 125.905, 67.2078), 1.12455, station_material);
  main_block->draw_sphere(glm::vec3(223.266, 135.02, 79.3446), 1.73171, planet3_material);
  main_block->draw_sphere(glm::vec3(222.363, 139.433, 58.3854), 1.80317, planet2_material);
  main_block->draw_sphere(glm::vec3(213.626, 146.206, 60.8058), 1.54753, planet5_material);
  main_block->draw_sphere(glm::vec3(195.219, 142.801, 85.9287), 1.41606, planet2_material);
  main_block->draw_sphere(glm::vec3(194.94, 161.671, 75.0848), 2.01956, planet1_material);
  main_block->draw_sphere(glm::vec3(212.303, 144.111, 64.6482), 1.22691, planet3_material);
  main_block->draw_sphere(glm::vec3(202.404, 142.695, 81.8377), 2.12447, moon_material);
  main_block->draw_sphere(glm::vec3(133.628, 106.789, 158.582), 1.8054, moon_material);
  main_block->draw_sphere(glm::vec3(120.265, 89.4339, 161.466), 1.20062, planet4_material);
  main_block->draw_sphere(glm::vec3(133.894, 97.4943, 145.743), 1.53399, planet5_material);
  main_block->draw_sphere(glm::vec3(129.914, 107.398, 142.827), 2.04034, planet1_material);
  main_block->draw_sphere(glm::vec3(132.637, 107.571, 137.316), 1.18327, planet3_material);
  main_block->draw_sphere(glm::vec3(126.267, 112.261, 140.791), 2.22296, planet4_material);
  main_block->draw_sphere(glm::vec3(129.51, 117.48, 138.037), 1.12516, planet1_material);
  main_block->draw_sphere(glm::vec3(120.44, 111.442, 143.298), 2.13808, planet3_material);
  main_block->draw_sphere(glm::vec3(186.079, 86.8362, 162.651), 1.87882, planet3_material);
  main_block->draw_sphere(glm::vec3(207.602, 83.7939, 178.865), 2.21222, planet1_material);
  main_block->draw_sphere(glm::vec3(206.253, 101.573, 178.497), 1.2251, planet5_material);
  main_block->draw_sphere(glm::vec3(183.499, 108.703, 173.21), 1.43807, planet2_material);
  main_block->draw_sphere(glm::vec3(207.859, 99.9905, 185.386), 2.28388, planet2_material);
  main_block->draw_sphere(glm::vec3(183.766, 108.561, 184.238), 1.52447, planet3_material);
  main_block->draw_sphere(glm::vec3(185.94, 108.072, 170.241), 1.93775, planet2_material);
  main_block->draw_sphere(glm::vec3(178.288, 109.659, 166.328), 1.64938, planet2_material);
  main_block->draw_sphere(glm::vec3(155.619, 59.1968, 175.375), 1.38749, planet5_material);
  main_block->draw_sphere(glm::vec3(140.228, 80.1827, 178.629), 1.50295, planet3_material);
  main_block->draw_sphere(glm::vec3(92.615, 109.208, 123.156), 1.12528, planet2_material);
  main_block->draw_sphere(glm::vec3(88.9465, 109.034, 137.971), 1.575, planet2_material);
  main_block->draw_sphere(glm::vec3(107.596, 203.044, 68.2672), 2.22625, moon_material);
  main_block->draw_sphere(glm::vec3(90.6449, 183.814, 82.8839), 1.96496, planet2_material);
  main_block->draw_sphere(glm::vec3(113.471, 200.065, 77.1698), 2.28432, planet2_material);
  main_block->draw_sphere(glm::vec3(87.2022, 198.052, 91.8815), 2.02581, planet2_material);
  main_block->draw_sphere(glm::vec3(96.3077, 193.319, 68.9223), 1.76496, planet5_material);
  main_block->draw_sphere(glm::vec3(104.489, 193.453, 71.0288), 1.93549, planet4_material);
  main_block->draw_sphere(glm::vec3(83.7739, 173.684, 101.8), 1.39463, planet2_material);
  main_block->draw_sphere(glm::vec3(86.9982, 179.571, 86.8121), 2.13206, planet1_material);
  main_block->draw_sphere(glm::vec3(102.027, 161.298, 93.0724), 1.23329, planet5_material);
  main_block->draw_sphere(glm::vec3(81.6656, 177.049, 84.3809), 1.34774, planet2_material);








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
