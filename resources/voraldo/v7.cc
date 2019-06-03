#include "v7.h"

#include "../perlin.h"
//perlin noise generation


using std::cout;
using std::endl;

using std::vector;

float clamp(float value, float low, float high)
{
  if(value > high)
  {
    return high;
  }
  else if(value < low)
  {
    return low;
  }
  else
  {
    return value;
  }
}





//---------------------------
Voraldo::Voraldo()
{

  //colors

	palette.resize(100);

  palette[0] = {  0,  0,  0,  0}; //black - here used to represent 'emtpy'



//REDS

  palette[ 1] = {254,  0,  0,255};         //MS Light Red High
  palette[ 2] = {235,138, 96,255};        //MS Light Red Low
  palette[ 3] = {126,  0,  0,255};       //MS Dark Red High
  palette[ 4] = {138, 54, 34,255};      //MS Dark Red Low
  palette[ 5] = {120, 24, 38,255};     //T Dark Red
  palette[ 6] = {165, 45, 39,255};    //T Red

//ORANGES

  palette[ 7] = {255, 77,  0,255};      //Orange 1
  palette[ 8] = {255,120, 30,255};     //Orange 2
  palette[ 9] = {243,120, 43,255};    //Orange 3
  palette[10] = {201,109, 69,255};   //T Orange

 //YELLOWS

  palette[11] = {255,255,  4,255};              //MS Light Yellow High
  palette[12] = {255,217, 63,255};             //MS Light Yellow Low
  palette[13] = {127,107,  0,255};            //Dark Gold
  palette[14] = {126,126,  0,255};           //MS Dark Yellow High
  palette[15] = {170, 92, 61,255};          //MS Dark Yellow Low
  palette[16] = {204,165, 98,255};         //T Yellow Dark
  palette[17] = {207,194,129,255};        //T Yellow Tan
  palette[18] = {209,202,128,255};       //T Yellow
  palette[19] = {162,157,107,255};      //T Tan
  palette[20] = {131,107, 63,255};     //T Light Brown
  palette[21] = { 99, 73, 44,255};    //T Brown
  palette[22] = { 65, 51, 37,255};   //T Dark Brown

//GREENS

  palette[23] = {  6,255,  4,255};          //MS Light Green High
  palette[24] = {108,217, 71,255};         //MS Light Green Low
  palette[25] = {  4,126,  0,255};        //MS Dark Green High
  palette[26] = { 12,126, 69,255};       //MS Dark Green Low
  palette[27] = {151,181,138,255};      //T Light Green
  palette[28] = {101,132, 92,255};     //T Med Green
  palette[29] = { 34, 58, 48,255};    //T Med-Dark Green
  palette[30] = { 32, 44, 17,255};   //T Dark Green

//BLUE/INDIGO

  palette[31] = {  0,  0,126,255};             //MS Dark Blue High
  palette[32] = { 34, 52,209,255};            //MS Dark Blue Low
  palette[33] = {  0,  0,255,255};           //MS Light Blue High
  palette[34] = { 76,129,251,255};          //MS Light Blue Low
  palette[35] = { 62, 62,138,255};         //T Med Blue
  palette[36] = { 76,110,173,255};        //T Dark blue
  palette[37] = {124,168,213,255};       //T Blue
  palette[38] = {172,220,241,255};      //T Light Blue
  palette[39] = {  4,126,126,255};     //MS Dark Teal High
  palette[40] = { 68,170,204,255};    //MS Dark Teal Low
  palette[41] = {  6,255,255,255};   //MS Light Teal High
  palette[42] = {123,226,249,255};  //MS Light Teal low

//VIOLET

  palette[43] = {254,  0,255,255};          //MS Light Purple High
  palette[44] = {226, 61,105,255};         //MS Light Purple Low
  palette[45] = { 82, 30, 46,255};        //T Maroon
  palette[46] = {126,  0,126,255};       //MS Dark Purple High
  palette[47] = { 92, 46,120,255};      //MS Dark Purple Low
  palette[48] = { 88, 38, 79,255};     //T Darker Purple
  palette[49] = { 80, 59,104,255};    //T Dark Purple
  palette[50] = {133, 91,105,255};   //T Purple
  palette[51] = {223,185,202,255};  //T Pink

//GREYSCALE

  palette[52] = {255,255,255,255};            //White
  palette[53] = {190,190,190,255};           //MS Light Grey High
  palette[54] = {181,181,181,255};          //MS Light Grey Low
  palette[55] = {126,126,126,255};         //MS Dark Grey High
  palette[56] = { 94, 96,110,255};        //MS Dark Grey Low
  palette[57] = {212,237,237,255};       //T Lighter Grey
  palette[58] = {134,149,152,255};      //T Med Light Grey
  palette[59] = { 95, 99,103,255};     //T Med Grey
  palette[60] = { 58, 59, 61,255};    //T Dark-Med Grey
  palette[61] = { 40, 34, 31,255};   //T Dark Grey
  palette[62] = {  0,  0,  0,255};  //Black


// weird desaturated palette "steam lords"
  palette[63] = { 33, 59, 37,255};	              //#213b25 dark green
  palette[64] = { 58,	96,	74,255};	             //#3a604a medium green
  palette[65] = { 79,119, 84,255};	            //#4f7754 light green
  palette[66] = {161,159,124,255}; 	           //#a19f7c light tan
  palette[67] = {119,116,	79,255};	          //#77744f medium tan
  palette[68] = {119,	92,	79,255};	         //#775c4f light rose
  palette[69] = { 96,	59,	58,255};	        //#603b3a dark rose
  palette[70] = { 59,	33,	55,255};	       //#3b2137 purple
  palette[71] = { 23,	14,	25,255};      	//#170e19 darkest blue (0)
  palette[72] = { 47,	33,	59,255};	     //#2f213b dark blue (1)
  palette[73] = { 67,	58,	96,255};	    //#433a60 dark blue (2)
  palette[74] = { 79,	82,119,255};	   //#4f5277 dark blue (3)
  palette[75] = {101,115,140,255};	  //#65738c light blue (4)
  palette[76] = {124,148,161,255};	 //#7c94a1 light blue (5)
  palette[77] = {160,185,186,255};	//#a0b9ba light blue (6)
  palette[78] = {192,209,204,255}; //#c0d1cc light blue (7)



  data.resize(0);
  // call draw.init_block(x,y,z,noise_fill)
  // to populate the data array
}

Voraldo::~Voraldo()
{

}





bool Voraldo::compare_colors(RGBA first, RGBA second)
{

  unsigned char red1 = first.red;
  unsigned char red2 = second.red;

  unsigned char green1 = first.green;
  unsigned char green2 = second.green;

  unsigned char blue1 = first.blue;
  unsigned char blue2 = second.blue;

  unsigned char alpha1 = first.alpha;
  unsigned char alpha2 = second.alpha;



  return ( ( red1 == red2 ) && ( green1 == green2 ) && ( blue1 == blue2 ) && ( alpha1 == alpha2 ) );
}




Vox Voraldo::get_vox(int palette_number, bool mask)
{
  Vox temp;

  temp.color = palette[palette_number];
  temp.mask = mask;

	temp.x = temp.y = temp.z = 0;

  return temp;

}



//  _________________    ________
//  \______   \      \  /  _____/
//   |     ___/   |   \/   \  ___
//   |    |  /    |    \    \_\  \
//   |____|  \____|__  /\______  /
//                   \/        \/ //saving the block to send to OpenGL


void Voraldo::save( std::string filename )
{
  // using namespace cimg_library;

  int width = x_dim;
  int height = y_dim;
  int depth = z_dim;

  // cout << "saving block of " << width << " " << height << " " << depth << endl;


  Vox temp;
  RGBA temporary_color;

  std::vector<unsigned char> image;

  unsigned image_width = width;
  unsigned image_height = height * depth;

  int size = 4 * width * height * depth;

  image.resize( size );

  // cout << "vector declared with " << image.capacity() << " elements" << endl;
  // cout << "vector max size of " << image.max_size() << " elements" << endl << endl;


  int index = 0;



  for(int z = 0; z < depth; z++)
  {
    for(int y = 0; y < height; y++)
    {
      for(int x = 0; x < width; x++)
      {

        temp = get_data_by_vector_index(vec((float)x,(float)y,(float)z));

        temporary_color = temp.color;

        image[index] = temporary_color.red;   index++;
        image[index] = temporary_color.green; index++;
        image[index] = temporary_color.blue;  index++;
        image[index] = temporary_color.alpha; index++;


      }

    }

  }

  //z * height * width  +  y * width  +  x

  unsigned error = lodepng::encode(filename.c_str(), image, image_width, image_height);
  if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
}

// LODEPNG EXAMPLE code

// std::vector<unsigned char> image;
// const char * filename1 = "save.png";
// const char * filename2 = "save2.png";
//
// unsigned width, height;
//
// //decode
// unsigned error = lodepng::decode(image, width, height, filename1);
//
// //if there's an error, display it
// if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
//
// //Encode the image
// error = lodepng::encode(filename2, image, width, height);
//
// //if there's an error, display it
// if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;









void Voraldo::init_block(vec dimensions)
{

	if(data.size() != 0)
	{
		data.resize(0);
	}

	x_dim = dimensions[0];
	y_dim = dimensions[1];
	z_dim = dimensions[2];

	num_cells = x_dim * y_dim * z_dim;

	data.resize( num_cells + 1 );

	Vox temp;

	for( int x = 0; x < x_dim; x++ )
	{
		for( int y = 0; y < y_dim; y++ )
		{
			for( int z = 0; z < z_dim; z++)
			{
				temp.mask = false;
				temp.color = palette[0];
				temp.x = x;
				temp.y = y;
				temp.z = z;
			}
		}
	}
}// init_block does need a nested for loop

void Voraldo::clear_all()
{ // note that this function has a bit more to it than you might initially think -
  //  first - deliberately do not unmask - there is a separate function for that operation - mask_unmask_all()
  //  second - this relies upon the state of the mask variables for each cell, a masked cell is not cleared

   for(int i = 0; i < num_cells; i++)
   {
     if(!data.at(i).mask)
     {
      data.at(i).color = {  0,  0,  0,  0};
     }
   }
}

void Voraldo::mask_unmask_all()
{
  // nlohmann::json j;
  // j["type"] = "unmask_all";
  // std::cout << j.dump() << endl;


 for(int i = 0; i < num_cells; i++)
 {
  data.at(i).mask = false;
 }
}

void Voraldo::mask_invert_mask()
{
  // nlohmann::json j;
  // j["type"] = "invert_mask";
  // std::cout << j.dump() << endl;

 for(int i = 0; i < num_cells; i++)
 {
  data.at(i).mask = data.at(i).mask ? false:true;
 }
}

void Voraldo::mask_all_nonzero()
{
 for(int i = 0; i < num_cells; i++)
 {
  if( !compare_colors( data.at(i).color, {  0,  0,  0,  0} ) )
  {
   data.at(i).mask = true;
  }
 }
}

void Voraldo::mask_by_state(unsigned char s)
{
 for(int i = 0; i < num_cells; i++)
 {
  if( compare_colors( data.at(i).color, palette[s] ) )
  {
   data.at(i).mask = true;
  }
 }
}

void Voraldo::draw_noise(float alpha, float lighting_intensity, int seed, bool draw, bool mask)
{
  // std::srand(seed);
  // for(int i = 0; i < num_cells; i++)
  // {
  //    if(std::rand()%696 == 69 && std::rand()%696 < 30)
  //    {
  //      if(!data.at(i).mask)
  //      {
  //         data.at(i).state = (std::rand()%30)+1;//this is a little different
  //         data.at(i).alpha = alpha;
  //         data.at(i).mask = mask;
  //         data.at(i).lighting_intensity = lighting_intensity;
  //      }
  //    }
  // }


	//replace this with perlin noise

}

void Voraldo::draw_point(vec point, Vox set, bool draw, bool mask)
{
 set_data_by_vector_index(point,set,draw,mask);
}

void Voraldo::draw_line_segment(vec v1, vec v2, Vox set, bool draw, bool mask)
{
  vec starting_point = v1;
	vec current_point = starting_point;
	vec line_vector = (v2-v1);

	int length = glm::length(line_vector);

	for(int i = 0; i < length; i++)
	{
		current_point[0] = std::floor(starting_point[0] + i*(line_vector[0]/length));
		current_point[1] = std::floor(starting_point[1] + i*(line_vector[1]/length));
		current_point[2] = std::floor(starting_point[2] + i*(line_vector[2]/length));

    if(current_point[0] < 0 || current_point[0] >= x_dim ||
       current_point[1] < 0 || current_point[1] >= y_dim ||
       current_point[2] < 0 || current_point[2] >= z_dim )
    {
      break;
    }

    draw_point(current_point,set,draw,mask);
	}
}

void Voraldo::draw_triangle(vec v0, vec v1, vec v2, Vox set, bool draw, bool mask)
{

 //point zero is the origin point

 	vec side1 = v1-v0;
 	vec side2 = v2-v0;

 	vec c1(0,0,0);
 	vec c2(0,0,0);
  //c1 and c2 are the ends of the line segment that is going to be drawn
  // these endpoints are ranged along the two sides so as to achieve coverage

 	float length;

 	if(glm::length(side1) > glm::length(side2))
 	{
    // length = std::floor(glm::length(side1));
 		length = glm::length(side1);
 	}
 	else
 	{
 		// length = std::floor(glm::length(side2));
    length = glm::length(side2);
  }

 	if(length <= 2)
  {
 		draw_point(v0,set);
 		draw_point(v1,set);
 		draw_point(v2,set);
 	}
  else
  {

 		side1 = side1/length;
 		side2 = side2/length;

 		for(double i = 0; i < length; i+=0.1)
 		{
 			c1[0] = v0[0] + i*side1[0];
 			c1[1] = v0[1] + i*side1[1];
 			c1[2] = v0[2] + i*side1[2];

 			c2[0] = v0[0] + i*side2[0];
 			c2[1] = v0[1] + i*side2[1];
 			c2[2] = v0[2] + i*side2[2];

 			draw_cylinder(c1,c2,1.0,set,draw,mask); //refit for cylinders rather than line segments
 		}
 	}
}

void Voraldo::draw_sphere(vec center_point, double radius, Vox set, bool draw, bool mask)
{

 vec index;
 for(int i = 0; i < x_dim; i++)
 	{
 		for(int j = 0; j < y_dim; j++)
 		{
 			for(int k = 0; k < z_dim; k++)
 			{
 				double testx = (i-center_point[0])*(i-center_point[0]);	//apply offsets and square
 				double testy = (j-center_point[1])*(j-center_point[1]);
 				double testz = (k-center_point[2])*(k-center_point[2]);

 				if((testx + testy + testz) < radius*radius)
 				{	//pretty self explainatory, equation of sphere
          index = vec(i,j,k);
 					draw_point(index,set,draw,mask);
 				}
 			}
 		}
 	}
}

void Voraldo::draw_ellipsoid(vec center_point, vec radii, Vox set, bool draw, bool mask)
{
 vec index;
 for(int i = 0; i < x_dim; i++)
 	{
 		for(int j = 0; j < y_dim; j++)
 		{
 			for(int k = 0; k < z_dim; k++)
 			{
 				double testx = (i-center_point[0])*(i-center_point[0]);	//apply offsets and square
 				double testy = (j-center_point[1])*(j-center_point[1]);
 				double testz = (k-center_point[2])*(k-center_point[2]);

 				double radx = radii[0]*radii[0];
 				double rady = radii[1]*radii[1];
 				double radz = radii[2]*radii[2];

 				double result = testx/radx + testy/rady + testz/radz;

 				if(result <= 1){	//point inside ellipsoid - do we want to be able to invert this?
 					//(outside, or on the surface, with >= and ==, respectively)
          index = vec(i,j,k);
 					draw_point(index,set,draw,mask);
 				}
 			}
 		}
 	}
}

void Voraldo::draw_cylinder(vec bvec, vec tvec, double radius, Vox set, bool draw, bool mask)
{
 	vec ndirection = tvec - bvec;

	auto bx0 = bvec[0]; auto ba = ndirection[0];	auto tx0 = tvec[0]; auto ta = ndirection[0];
	auto by0 = bvec[1]; auto bb = ndirection[1];	auto ty0 = tvec[1]; auto tb = ndirection[1];
	auto bz0 = bvec[2]; auto bc = ndirection[2];	auto tz0 = tvec[2]; auto tc = ndirection[2];

	//I did this on a whiteboard

	double bplanetest = 0.0;
	double tplanetest = 0.0;

	double point_to_line_distance = 0.0;

 vec index;

	for(int i = 0; i < x_dim; i++){
		for(int j = 0; j < y_dim; j++){
			for(int k = 0; k < z_dim; k++){
				//planetests
				bplanetest = ba * (i - bx0) + bb * (j - by0) + bc * (k - bz0);
				tplanetest = ta * (i - tx0) + tb * (j - ty0) + tc * (k - tz0);

				//using the basic equation for a plane, we can do an interesting test

				//These variables will be greater than zero if the test point is on the side of the plane
				//that the normal vector is pointing towards, and less than zero if the test point is on
				//the side of the plane that the normal vector is not pointing towards. That is to say, in
				//my case - bplanetest tells me whether the point is above the bottom plane, and tplanetest
				//tells me whether the point is above the top plane. If it is above the bottom, and below
				//the top - we are within the ends of the cylinder, and can proceed. Thus, the condition
				//for the following if statement:

				if(bplanetest >= 0 && tplanetest <= 0){

					//do the point to line distance thing
					//algorithm from http://mathworld.wolfram.com/Point-LineDistance3-Dimensional.html

					//This test takes as a precondition that the point is determined to be within the slice
					//of space established by two parallel planes. Now that this is known, we will see how
					//far they are from the line, which runs perpendicular to both planes. If both of these
					//sequential tests evaluate positively, we know we are within the extents of the cylinder.

					point_to_line_distance = glm::length(cross(tvec-bvec,bvec-vec(i,j,k)))/glm::length(tvec-bvec);
					if(point_to_line_distance <= radius)
          {
            //cout << "point to line distance test passed" << endl;
            index = vec(i,j,k);
						draw_point(index,set,draw,mask);
					}
				}
			}
		}
	}
}

void Voraldo::draw_tube(vec bvec, vec tvec, double inner_radius, double outer_radius, Vox set, bool draw, bool mask)
{
  vec ndirection = tvec - bvec;

 	auto bx0 = bvec[0]; auto ba = ndirection[0];	auto tx0 = tvec[0]; auto ta = ndirection[0];
 	auto by0 = bvec[1]; auto bb = ndirection[1];	auto ty0 = tvec[1]; auto tb = ndirection[1];
 	auto bz0 = bvec[2]; auto bc = ndirection[2];	auto tz0 = tvec[2]; auto tc = ndirection[2];

 	//I did this on a whiteboard

 	double bplanetest = 0.0;
 	double tplanetest = 0.0;

 	double point_to_line_distance = 0.0;
  vec index;

 	for(int i = 0; i < x_dim; i++){
 		for(int j = 0; j < y_dim; j++){
 			for(int k = 0; k < z_dim; k++){
 				//planetests
 				bplanetest = ba * (i - bx0) + bb * (j - by0) + bc * (k - bz0);
 				tplanetest = ta * (i - tx0) + tb * (j - ty0) + tc * (k - tz0);

 				//using the basic equation for a plane, we can do an interesting test

 				//These variables will be greater than zero if the test point is on the side of the plane
 				//that the normal vector is pointing towards, and less than zero if the test point is on
 				//the side of the plane that the normal vector is not pointing towards. That is to say, in
 				//my case - bplanetest tells me whether the point is above the bottom plane, and tplanetest
 				//tells me whether the point is above the top plane. If it is above the bottom, and below
 				//the top - we are within the ends of the cylinder, and can proceed. Thus, the condition
 				//for the following if statement:

 				if(bplanetest >= 0 && tplanetest <= 0){
 					//do the point to line distance thing
 					//algorithm from http://mathworld.wolfram.com/Point-LineDistance3-Dimensional.html

 					//This test takes as a precondition that the point is determined to be within the slice
 					//of space established by two parallel planes. Now that this is known, we will see how
 					//far they are from the line, which runs perpendicular to both planes. If both of these
 					//sequential tests evaluate positively, we know we are within the extents of the cylinder.

 					point_to_line_distance = glm::length(cross(tvec-bvec,bvec-vec(i,j,k)))/glm::length(tvec-bvec);

 					if(point_to_line_distance <= outer_radius && point_to_line_distance >= inner_radius)
          {
            index = vec(i,j,k);
            draw_point(index,set,draw,mask);
 					}
 				}
 			}
 		}
 	}
}

void Voraldo::draw_quadrilateral_hexahedron(vec a, vec b, vec c, vec d, vec e, vec f, vec g, vec h, Vox set, bool draw, bool mask)
{
	  vec center = a + b + c + d + e + f + g + h;
	 	center = vec(center[0]/8, center[1]/8, center[2]/8);

	 	bool plusx1 = false;
	 	bool plusx2 = false;

	 //    888   Y88b  /
	 //  __888__  Y88b/
	 //    888     Y88b
	 //    888     /Y88b
	 //           /  Y88b

	 	//CDGH

	 	//TRIANGLES ARE CDH, CGH

	 	vec plusx_side1 = vec(c[0]-d[0],c[1]-d[1],c[2]-d[2]);
	 	vec plusx_side2 = vec(h[0]-d[0],h[1]-d[1],h[2]-d[2]);

	 	vec plusx_side3 = vec(c[0]-g[0],c[1]-g[1],c[2]-g[2]);
	 	vec plusx_side4 = vec(h[0]-g[0],h[1]-g[1],h[2]-g[2]);

	 	vec plusx_planevec1 = cross(plusx_side1,plusx_side2);
	 	vec plusx_planept1 = d;

	 	vec plusx_planevec2 = cross(plusx_side3,plusx_side4);
	 	vec plusx_planept2 = g;

	 	if(!planetest(plusx_planept1,plusx_planevec1,center))
	 	{	//if the center fails the plane test, flip the normal
	 		plusx_planevec1 = vec(-1*plusx_planevec1[0],-1*plusx_planevec1[1],-1*plusx_planevec1[2]);
	 	}

	 	if(!planetest(plusx_planept2,plusx_planevec2,center))
	 	{	//if the center fails the plane test, flip the normal
	 		plusx_planevec2 = vec(-1*plusx_planevec2[0],-1*plusx_planevec2[1],-1*plusx_planevec2[2]);
	 	}

	 //-------------------------------------------


	 	bool minusx1 = false;
	 	bool minusx2 = false;

	 //       Y88b  /
	 //  ____  Y88b/
	 //         Y88b
	 //         /Y88b
	 //        /  Y88b

	 	//ABEF

	 	//TRIANGLES ARE ABF, AEF

	 	vec minusx_side1 = vec(a[0]-b[0],a[1]-b[1],a[2]-b[2]);
	 	vec minusx_side2 = vec(f[0]-b[0],f[1]-b[1],f[2]-b[2]);

	 	vec minusx_side3 = vec(a[0]-e[0],a[1]-e[1],a[2]-e[2]);
	 	vec minusx_side4 = vec(f[0]-e[0],f[1]-e[1],f[2]-e[2]);

	 	vec minusx_planevec1 = cross(minusx_side1,minusx_side2);
	 	vec minusx_planept1 = b;

	 	vec minusx_planevec2 = cross(minusx_side3,minusx_side4);
	 	vec minusx_planept2 = e;

	 	if(!planetest(minusx_planept1,minusx_planevec1,center))
	 	{	//if the center fails the plane test, flip the normal
	 		minusx_planevec1 = vec(-1*minusx_planevec1[0],-1*minusx_planevec1[1],-1*minusx_planevec1[2]);
	 	}

	 	if(!planetest(minusx_planept2,minusx_planevec2,center))
	 	{	//if the center fails the plane test, flip the normal
	 		minusx_planevec2 = vec(-1*minusx_planevec2[0],-1*minusx_planevec2[1],-1*minusx_planevec2[2]);
	 	}

	 //-------------------------------------------


	 	bool plusy1 = false;
	 	bool plusy2 = false;

	 //    888   Y88b  /
	 //  __888__  Y888/
	 //    888     Y8/
	 //    888      Y
	 //            /
	 //          _/

	 	//ACEG

	 	//TRIANGLES ARE ACG, AEG

	 	vec plusy_side1 = vec(a[0]-c[0],a[1]-c[1],a[2]-c[2]);
	 	vec plusy_side2 = vec(g[0]-c[0],g[1]-c[1],g[2]-c[2]);

	 	vec plusy_side3 = vec(a[0]-e[0],a[1]-e[1],a[2]-e[2]);
	 	vec plusy_side4 = vec(g[0]-e[0],g[1]-e[1],g[2]-e[2]);

	 	vec plusy_planevec1 = cross(plusy_side1,plusy_side2);
	 	vec plusy_planept1 = c;

	 	vec plusy_planevec2 = cross(plusy_side3,plusy_side4);
	 	vec plusy_planept2 = e;

	 	if(!planetest(plusy_planept1,plusy_planevec1,center))
	 	{	//if the center fails the plane test, flip the normal
	 		plusy_planevec1 = vec(-1*plusy_planevec1[0],-1*plusy_planevec1[1],-1*plusy_planevec1[2]);
	 	}

	 	if(!planetest(plusy_planept2,plusy_planevec2,center))
	 	{	//if the center fails the plane test, flip the normal
	 		plusy_planevec2 = vec(-1*plusy_planevec2[0],-1*plusy_planevec2[1],-1*plusy_planevec2[2]);
	 	}

	 //-------------------------------------------


	 	bool minusy1 = false;
	 	bool minusy2 = false;

	 //       Y88b  /
	 //  ____  Y888/
	 //         Y8/
	 //          Y
	 //         /
	 //       _/

	 	//BDFH

	 	//TRIANGLES ARE BDH, BFH
	 	vec minusy_side1 = vec(b[0]-d[0],b[1]-d[1],b[2]-d[2]);
	 	vec minusy_side2 = vec(h[0]-d[0],h[1]-d[1],h[2]-d[2]);

	 	vec minusy_side3 = vec(b[0]-f[0],b[1]-f[1],b[2]-f[2]);
	 	vec minusy_side4 = vec(h[0]-f[0],h[1]-f[1],h[2]-f[2]);

	 	vec minusy_planevec1 = cross(minusy_side1,minusy_side2);
	 	vec minusy_planept1 = d;

	 	vec minusy_planevec2 = cross(minusy_side3,minusy_side4);
	 	vec minusy_planept2 = f;

	 	if(!planetest(minusy_planept1,minusy_planevec1,center))
	 	{	//if the center fails the plane test, flip the normal
	 		minusy_planevec1 = vec(-1*minusy_planevec1[0],-1*minusy_planevec1[1],-1*minusy_planevec1[2]);
	 	}

	 	if(!planetest(minusy_planept2,minusy_planevec2,center))
	 	{	//if the center fails the plane test, flip the normal
	 		minusy_planevec2 = vec(-1*minusy_planevec2[0],-1*minusy_planevec2[1],-1*minusy_planevec2[2]);
	 	}


	 //-------------------------------------------


	 	bool plusz1 = false;
	 	bool plusz2 = false;


	 //    888    ~~~d88P
	 //  __888__    d88P
	 //    888     d88P
	 //    888    d88P
	 //          d88P___

	 	//ABCD

	 	//TRIANGLES ARE ABD, ACD

	 	vec plusz_side1 = vec(a[0]-b[0],a[1]-b[1],a[2]-b[2]);
	 	vec plusz_side2 = vec(d[0]-b[0],d[1]-b[1],d[2]-b[2]);

	 	vec plusz_side3 = vec(a[0]-c[0],a[1]-c[1],a[2]-c[2]);
	 	vec plusz_side4 = vec(d[0]-c[0],d[1]-c[1],d[2]-c[2]);

	 	vec plusz_planevec1 = cross(plusz_side1,plusz_side2);
	 	vec plusz_planept1 = b;

	 	vec plusz_planevec2 = cross(plusz_side3,plusz_side4);
	 	vec plusz_planept2 = c;

	 	if(!planetest(plusz_planept1,plusz_planevec1,center))
	 	{	//if the center fails the plane test, flip the normal
	 		plusz_planevec1 = vec(-1*plusz_planevec1[0],-1*plusz_planevec1[1],-1*plusz_planevec1[2]);
	 	}

	 	if(!planetest(plusz_planept2,plusz_planevec2,center))
	 	{	//if the center fails the plane test, flip the normal
	 		plusz_planevec2 = vec(-1*plusz_planevec2[0],-1*plusz_planevec2[1],-1*plusz_planevec2[2]);
	 	}

	 //-------------------------------------------


	 	bool minusz1 = false;
	 	bool minusz2 = false;

	 //        ~~~d88P
	 //  ____    d88P
	 //         d88P
	 //        d88P
	 //       d88P___

	 	//EFGH

	 	//TRIANGLES ARE EFH, EGH
	 	vec minusz_side1 = vec(e[0]-f[0],e[1]-f[1],e[2]-f[2]);
	 	vec minusz_side2 = vec(h[0]-f[0],h[1]-f[1],h[2]-f[2]);

	 	vec minusz_side3 = vec(e[0]-g[0],e[1]-g[1],e[2]-g[2]);
	 	vec minusz_side4 = vec(h[0]-g[0],h[1]-g[1],h[2]-g[2]);

	 	vec minusz_planevec1 = cross(minusz_side1,minusz_side2);
	 	vec minusz_planept1 = f;

	 	vec minusz_planevec2 = cross(minusz_side3,minusz_side4);
	 	vec minusz_planept2 = g;

	 	if(!planetest(minusz_planept1,minusz_planevec1,center))
	 	{	//if the center fails the plane test, flip the normal
	 		minusz_planevec1 = vec(-1*minusz_planevec1[0],-1*minusz_planevec1[1],-1*minusz_planevec1[2]);
	 	}

	 	if(!planetest(minusz_planept2,minusz_planevec2,center))
	 	{	//if the center fails the plane test, flip the normal
	 		minusz_planevec2 = vec(-1*minusz_planevec2[0],-1*minusz_planevec2[1],-1*minusz_planevec2[2]);
	 	}


	 //-------------------------------------------

	 //  ╔╦╗┌─┐┌─┐┌┬┐  ╦  ┌─┐┌─┐┌─┐
	 //   ║ ├┤ └─┐ │   ║  │ ││ │├─┘
	 //   ╩ └─┘└─┘ ┴   ╩═╝└─┘└─┘┴

	 	vec current;

	 	for(int i = 0; i < x_dim; i++)
	 	{
	 		for(int j = 0; j < y_dim; j++)
	 		{
	 			for(int k = 0; k < z_dim; k++)
	 			{

	 				current = vec(i,j,k);

	 				bool plusxtest = planetest(plusx_planept1,plusx_planevec1,current)&&planetest(plusx_planept2,plusx_planevec2,current);
	 				bool minusxtest = planetest(minusx_planept1,minusx_planevec1,current)&&planetest(minusx_planept2,minusx_planevec2,current);
	 				bool plusytest = planetest(plusy_planept1,plusy_planevec1,current)&&planetest(plusy_planept2,plusy_planevec2,current);
	 				bool minusytest = planetest(minusy_planept1,minusy_planevec1,current)&&planetest(minusy_planept2,minusy_planevec2,current);
	 				bool plusztest = planetest(plusz_planept1,plusz_planevec1,current)&&planetest(plusz_planept2,plusz_planevec2,current);
	 				bool minusztest = planetest(minusz_planept1,minusz_planevec1,current)&&planetest(minusz_planept2,minusz_planevec2,current);

	 				bool xtest = plusxtest&&minusxtest;
	 				bool ytest = plusytest&&minusytest;
	 				bool ztest = plusztest&&minusztest;


	 				if(xtest && ytest && ztest)
	 				{
	 					draw_point(current,set,draw,mask);
	 				}
	 			}
	 		}
	 	}
}

void Voraldo::draw_regular_icosahedron(double x_rot, double y_rot, double z_rot, double scale, vec center_point, Vox vertex_material, double verticies_radius, Vox edge_material, double edge_thickness, Vox face_material,bool draw_faces, bool draw, bool mask)
{
  double phi = (1 + std::sqrt(5.0))/2.0;

//rotation matricies allowing rotation of the polyhedron
 	mat rotation_x_axis;
 //refernces [column][row] - sin and cos take arguments in radians
 		rotation_x_axis[0][0] = 1;                       rotation_x_axis[1][0] = 0;                      rotation_x_axis[2][0] = 0;
 		rotation_x_axis[0][1] = 0;                       rotation_x_axis[1][1] = std::cos(x_rot);        rotation_x_axis[2][1] = -1.0*std::sin(x_rot);
 		rotation_x_axis[0][2] = 0;                       rotation_x_axis[1][2] = std::sin(x_rot);        rotation_x_axis[2][2] = std::cos(x_rot);

 	mat rotation_y_axis;
 		rotation_y_axis[0][0] = std::cos(y_rot);         rotation_y_axis[1][0] = 0;                      rotation_y_axis[2][0] = std::sin(y_rot);
 		rotation_y_axis[0][1] = 0;                       rotation_y_axis[1][1] = 1;                      rotation_y_axis[2][1] = 0;
 		rotation_y_axis[0][2] = -1.0*std::sin(y_rot);    rotation_y_axis[1][2] = 0;                      rotation_y_axis[2][2] = std::cos(y_rot);

 	mat rotation_z_axis;
 		rotation_z_axis[0][0] = std::cos(z_rot);         rotation_z_axis[1][0] = -1.0*std::sin(z_rot);   rotation_z_axis[2][0] = 0;
 		rotation_z_axis[0][1] = std::sin(z_rot);         rotation_z_axis[1][1] = std::cos(z_rot);        rotation_z_axis[2][1] = 0;
 		rotation_z_axis[0][2] = 0;                       rotation_z_axis[1][2] = 0;                      rotation_z_axis[2][2] = 1;

  mat rotation = rotation_x_axis * rotation_y_axis * rotation_z_axis; //multiply these all together

  vec a,b,c,d,e,f,g,h,i,j,k,l;
//the work for this is in my journal, the entry on 3/1/2019
//it is based on the idea that the points of a regular icosahedron lie on the points defined by three mutually orthogonal golden rectangles that share a center point at the origin
//i.e. these rectanges are abcd,efgh and ijkl
  a = rotation * vec(  0,  1*scale,  phi*scale) + center_point; e = rotation * vec(  1*scale,  phi*scale,  0) + center_point; i = rotation * vec(  phi*scale,  0,  1*scale) + center_point;
  b = rotation * vec(  0,  1*scale, -phi*scale) + center_point; f = rotation * vec( -1*scale, -phi*scale,  0) + center_point; j = rotation * vec(  phi*scale,  0, -1*scale) + center_point;
  c = rotation * vec(  0, -1*scale,  phi*scale) + center_point; g = rotation * vec( -1*scale,  phi*scale,  0) + center_point; k = rotation * vec( -phi*scale,  0,  1*scale) + center_point;
  d = rotation * vec(  0, -1*scale, -phi*scale) + center_point; h = rotation * vec(  1*scale, -phi*scale,  0) + center_point; l = rotation * vec( -phi*scale,  0, -1*scale) + center_point;
//nonzero components of the coordinates are scaled by the scale input argument. The result of that operation is multiplied by the composed rotation matrix, then added to the shape's center point


  if(draw_faces)
  {//draw the faces -
    draw_triangle( a, g, e, face_material, draw, mask); //AGE
    draw_triangle( a, i, e, face_material, draw, mask); //AIE
    draw_triangle( a, c, i, face_material, draw, mask); //ACI
    draw_triangle( a, c, k, face_material, draw, mask); //ACK
    draw_triangle( a, g, k, face_material, draw, mask); //AGK
    draw_triangle( l, b, g, face_material, draw, mask); //LBG
    draw_triangle( l, g, k, face_material, draw, mask); //LGK
    draw_triangle( l, f, k, face_material, draw, mask); //LFK
    draw_triangle( l, d, f, face_material, draw, mask); //LDF
    draw_triangle( l, d, b, face_material, draw, mask); //LDB
    draw_triangle( k, f, c, face_material, draw, mask); //KFC
    draw_triangle( f, h, c, face_material, draw, mask); //FHC
    draw_triangle( h, i, c, face_material, draw, mask); //HIC
    draw_triangle( e, j, i, face_material, draw, mask); //EJI
    draw_triangle( b, g, e, face_material, draw, mask); //BGE
    draw_triangle( f, h, d, face_material, draw, mask); //FHD
    draw_triangle( d, h, j, face_material, draw, mask); //DHJ
    draw_triangle( d, b, j, face_material, draw, mask); //DBJ
    draw_triangle( b, j, e, face_material, draw, mask); //BJE
    draw_triangle( h, i, j, face_material, draw, mask); //HIJ
  }




  if(edge_thickness)
  {//nonzero value passed for edge thickness
    //draw the edges
   //use cylinders of radius edge_thickness - more general than line segments
      draw_cylinder(a,c, edge_thickness, edge_material, draw, mask); //AC
      draw_cylinder(a,e, edge_thickness, edge_material, draw, mask); //AE
      draw_cylinder(a,g, edge_thickness, edge_material, draw, mask); //AG
      draw_cylinder(a,i, edge_thickness, edge_material, draw, mask); //AI
      draw_cylinder(a,k, edge_thickness, edge_material, draw, mask); //AK

      draw_cylinder(b,d, edge_thickness, edge_material, draw, mask); //BD
      draw_cylinder(b,e, edge_thickness, edge_material, draw, mask); //BE
      draw_cylinder(b,g, edge_thickness, edge_material, draw, mask); //BG
      draw_cylinder(b,j, edge_thickness, edge_material, draw, mask); //BJ
      draw_cylinder(b,l, edge_thickness, edge_material, draw, mask); //BL

      draw_cylinder(c,f, edge_thickness, edge_material, draw, mask); //CF
      draw_cylinder(c,h, edge_thickness, edge_material, draw, mask); //CH
      draw_cylinder(c,i, edge_thickness, edge_material, draw, mask); //CI
      draw_cylinder(c,k, edge_thickness, edge_material, draw, mask); //CK

      draw_cylinder(d,f, edge_thickness, edge_material, draw, mask); //DF
      draw_cylinder(d,h, edge_thickness, edge_material, draw, mask); //DH
      draw_cylinder(d,j, edge_thickness, edge_material, draw, mask); //DJ
      draw_cylinder(d,l, edge_thickness, edge_material, draw, mask); //DL

      draw_cylinder(e,g, edge_thickness, edge_material, draw, mask); //EG
      draw_cylinder(e,i, edge_thickness, edge_material, draw, mask); //EI
      draw_cylinder(e,j, edge_thickness, edge_material, draw, mask); //EJ

      draw_cylinder(f,h, edge_thickness, edge_material, draw, mask); //FH
      draw_cylinder(f,k, edge_thickness, edge_material, draw, mask); //FK
      draw_cylinder(f,l, edge_thickness, edge_material, draw, mask); //FL

      draw_cylinder(g,k, edge_thickness, edge_material, draw, mask); //GK
      draw_cylinder(g,l, edge_thickness, edge_material, draw, mask); //GL

      draw_cylinder(h,i, edge_thickness, edge_material, draw, mask); //HI
      draw_cylinder(h,j, edge_thickness, edge_material, draw, mask); //HJ

      draw_cylinder(i,j, edge_thickness, edge_material, draw, mask); //IJ

      draw_cylinder(k,l, edge_thickness, edge_material, draw, mask); //KL

  }

  if(verticies_radius)
  {//nonzero value passed for vertex radius
    //draw the vertexes
    draw_sphere(a, verticies_radius, vertex_material, draw, mask);
    draw_sphere(b, verticies_radius, vertex_material, draw, mask);
    draw_sphere(c, verticies_radius, vertex_material, draw, mask);
    draw_sphere(d, verticies_radius, vertex_material, draw, mask);

    draw_sphere(e, verticies_radius, vertex_material, draw, mask);
    draw_sphere(f, verticies_radius, vertex_material, draw, mask);
    draw_sphere(g, verticies_radius, vertex_material, draw, mask);
    draw_sphere(h, verticies_radius, vertex_material, draw, mask);

    draw_sphere(i, verticies_radius, vertex_material, draw, mask);
    draw_sphere(j, verticies_radius, vertex_material, draw, mask);
    draw_sphere(k, verticies_radius, vertex_material, draw, mask);
    draw_sphere(l, verticies_radius, vertex_material, draw, mask);
  }
}

// void Voraldo::draw_heightmap(/*std::string filename, std::vector<Vox> materials,*/ bool draw, bool mask)
// {
//   using namespace cimg_library;
//   unsigned char current_color;
//   unsigned char current_height;
//   unsigned char current_colormap;
//
//   CImg<unsigned char> heightmap("heights.png");
//   CImg<unsigned char> colormap("greycolors.png");
//
//   for(int x = 0; x < 512; x++){
//     for(int z = 0; z < 512; z++){
//
//       current_height = heightmap.atXY(x,z);
//       current_colormap = colormap.atXY(x,z);
//
//       if(current_colormap < 30){
//         current_color = 62; //black
//       }else if(current_colormap < 60){
//         current_color = 61; // t dark grey
//       }else if(current_colormap < 90){
//         current_color = 60; // t dark med
//       }else if(current_colormap < 120){
//         current_color = 59; // t med light
//       }else if(current_colormap < 150){
//         current_color = 58; // t light
//       }else{
//         current_color = 57; // t lighter
//       }
//
//       draw_point(vec(x,current_height/3,z),get_vox(current_color,1,0.3,false),draw,mask);
//
//
//       //for(int y = 0; y < current_height/3; y++){
//         //draw_point(vec(x,y,z),get_vox(current_color,1,0.3,false),draw,mask);
//       //}
//       //cout << heightmap.atXY(x,z) << " ";
//     }
//     //cout << endl;
//   }
//
//
//     //go up to y
//
//   return;
// }



Vox Voraldo::get_data_by_vector_index(vec index)
{
  //std::cout << "beginning" << endl;
  int data_index = index[2]*y_dim*x_dim + index[1]*x_dim + index[0];
  //std::cout << "index calculated" << endl;

  bool x_valid = index[0] < x_dim && index[0] >= 0;
  bool y_valid = index[1] < y_dim && index[1] >= 0;
  bool z_valid = index[2] < z_dim && index[2] >= 0;

  bool point_valid = x_valid && y_valid && z_valid;

  //std::cout << "the index is " << index[0] << " " << index[1] << " " << index[2] << endl;

  //std::cout << "index validated: " << data_index << " versus max array size of " << num_cells << endl;


  if(point_valid)
   return data.at(data_index);
  else
  {
    Vox default_val;
    default_val.color = {  0,  0,  0,  0};
    default_val.mask = false;
    return default_val;
  }
}

void Voraldo::set_data_by_vector_index(vec index, Vox set, bool draw, bool mask, bool force)
{
 int data_index = index[2]*y_dim*x_dim + index[1]*x_dim + index[0];

 bool x_valid = index[0] < x_dim && index[0] >= 0;
 bool y_valid = index[1] < y_dim && index[1] >= 0;
 bool z_valid = index[2] < z_dim && index[2] >= 0;

 bool point_valid = x_valid && y_valid && z_valid;

 if(point_valid)
 {
  if(!data.at(data_index).mask)
  {
   if(draw)
   {
    data.at(data_index) = set;
   }
    data.at(data_index).mask = mask; //this takes precedence over the Vox value of mask
  }

  if(force)
  {
    data.at(data_index) = set;
  }
 }
}

bool Voraldo::planetest(vec plane_point, vec plane_normal, vec test_point)
{
 //return false if the point is above the plane
	//return true if the point is below the plane

	double result = 0.0;

	//equation of plane

	// a (x-x1) + b (y-y1) + c (z-z1) = 0

	double a = plane_normal[0];
	double b = plane_normal[1];
	double c = plane_normal[2];

	double x1 = plane_point[0];
	double y1 = plane_point[1];
	double z1 = plane_point[2];

	double x = test_point[0];
	double y = test_point[1];
	double z = test_point[2];

	result = a * (x - x1) + b * (y - y1) + c * (z - z1);

	return (result < 0)?true:false;
}

bool Voraldo::intersect_ray_bbox(vec bbox_min, vec bbox_max, vec ray_org, vec ray_dir, double &tmin, double &tmax, double t0, double t1)
{/*
 * Ray-box intersection using IEEE numerical properties to ensure that the
 * test is both robust and efficient, as described in:
 *
 *      Amy Williams, Steve Barrus, R. Keith Morley, and Peter Shirley
 *      "An Efficient and Robust Ray-Box Intersection Algorithm"
 *      Journal of graphics tools, 10(1):49-54, 2005
 *
 */
//I pulled this code after three attempts at my own implementation didn't work
  vec bbox[2];
	int sign[3];

	vec inv_direction = vec(1/ray_dir[0],1/ray_dir[1],1/ray_dir[2]);

	sign[0] = (inv_direction[0] < 0);
	sign[1] = (inv_direction[1] < 0);
	sign[2] = (inv_direction[2] < 0);

	bbox[0] = bbox_min;
	bbox[1] = bbox_max;


	//already declared (passed in by reference so that they can be used)
  tmin = (bbox[sign[0]][0] - ray_org[0]) * inv_direction[0];
  tmax = (bbox[1-sign[0]][0] - ray_org[0]) * inv_direction[0];

  double tymin = (bbox[sign[1]][1] - ray_org[1]) * inv_direction[1];
  double tymax = (bbox[1-sign[1]][1] - ray_org[1]) * inv_direction[1];

  if ( (tmin > tymax) || (tymin > tmax) )
    return false;
  if (tymin > tmin)
    tmin = tymin;
  if (tymax < tmax)
    tmax = tymax;

  double tzmin = (bbox[sign[2]][2] - ray_org[2]) * inv_direction[2];
  double tzmax = (bbox[1-sign[2]][2] - ray_org[2]) * inv_direction[2];

  if ( (tmin > tzmax) || (tzmin > tmax) )
    return false;
  if (tzmin > tmin)
    tmin = tzmin;
  if (tzmax < tmax)
    tmax = tzmax;
  return ( (tmin < t1) && (tmax > t0) );

}
