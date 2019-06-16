#include "../CImg.h"		//single-header library for image display and saving
//Cimg license - from Cimg.eu - CImg is a free, open-source library distributed
//under the CeCILL-C (close to the GNU LGPL) or CeCILL (compatible with the GNU GPL)
//licenses. It can be used in commercial applications.

//IMPORTANT LINKS RE CIMG LIBRARY docs
//http://cimg.eu/reference/group__cimg__overview.html




// #include "../json.hpp"  	//single-header library for structured output file formatting
//MIT License






#include <cstdlib>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <string>
#include <stack>
#include <map>

#include <iostream>

#include <vector>



#ifndef VORALDO
#define VORALDO


#include "../lodepng.h"
// Good, simple png library


#include "../glm/glm.hpp"
//general vector types







using vec = glm::vec3;
using mat = glm::mat3;

using std::cout;
using std::endl;

using std::vector;

struct RGBA
{
	unsigned char red;
	unsigned char green;
	unsigned char blue;

	unsigned char alpha;
	unsigned char alpha_low;
};

struct Vox
{
	RGBA color;

	bool mask;
};

class Voraldo
{
	//top level class - instantiates IO and Draw classes
	public:
			Voraldo();
			~Voraldo();

			// vector<Vox> data;

			vector<vector<vector<Vox>>> data;

			vector<RGBA> palette;
	//-----------------------------------------
	    //block dimensions - get & set functions
	//-----------------------------------------

			int x_dim;
			int y_dim;
			int z_dim;

			int num_cells;

			Vox get_data_by_vector_index(vec index);
			//return the state value for the selected index... this is going to take a lot more time now

			void set_data_by_vector_index(vec index, Vox set, bool draw=true, bool mask=false, bool force = false);
			//set the data at the selected index, also setting the mask if the
			//mask variable is true

	//-----------------------------------------
			// utilities
	//-----------------------------------------

			bool planetest(vec plane_point, vec plane_normal, vec test_point);
			// returns false if the point is above the plane, true if it is above

			bool intersect_ray_bbox(vec bbox_min, vec bbox_max, vec ray_org, vec ray_dir, float &tmin, float &tmax, float t0=0, float t1=9999);
			// returns true if the vector starting at ray_org doing in direction ray_dir hits the bounding box
			// tmin and tmax let the user know the far and near points of intersection

			Vox get_vox( int desired_color, float alpha, bool mask );
			Vox get_vox( RGBA color, bool mask ); // if you don't care about the alpha channel


			bool compare_colors(RGBA first, RGBA second);

			float clamp(float value, float low, float high);

			//CPU Renderer
			void display(std::string filename, float x_rot, float y_rot, float z_rot, float scale, bool perspective);

			void save(std::string filename); // saves a block to an image - assumes you have a block held in data
			void load(std::string filename); // loads a block from an image - assumes 512 x 256 x 256


			// These are of questionable utility
			void save_16_bit(std::string filename); // saves a block to an image - assumes you have a block held in data - uses 16 bit alpha
			void load_16_bit(std::string filename); // loads a block from an image - assumes 512 x 256 x 256 - uses 16 bit alpha

	//-----------------------------------------
			//drawing, masking and initialization
	//-----------------------------------------


			void init_block(vec dimensions);
			//initializes empty block with selected dimensions

			void clear_all();
			//sets all state and mask values to zero
				//not supported in model files

//      __  ___           __
//     /  |/  /___ ______/ /__
//    / /|_/ / __ `/ ___/ //_/
//   / /  / / /_/ (__  ) ,<
//  /_/  /_/\__,_/____/_/|_|
//

			void mask_unmask_all();
			//sets the value of mask to false for all voxels

			void mask_invert_mask();
			//inverts the value of mask for all voxels

			void mask_all_nonzero();
			//sets mask to true for all cells that have nonzero state values

			void mask_by_state(unsigned char s);
			//sets mask to true for all voxels which bear the given state value.


//      ____
//     / __ \_________ __      __
//    / / / / ___/ __ `/ | /| / /
//   / /_/ / /  / /_/ /| |/ |/ /
//  /_____/_/   \__,_/ |__/|__/
//


//  all of these have the same layout for the set, draw, and mask arguments

		//set is the value to draw
		//draw is whether or not you will draw in the voxels in the shape
		//mask is whether or not you will mask the voxels in that shape
		//draw and mask are exclusive, you might say independent of one another - i.e.
		//	these functions can be used to mask without drawing if desired

		void draw_perlin_noise(float scale, float threshold, Vox set, bool draw=true, bool mask=false);
		//scale increases the scale factor on acquisition of noise samples (lower number, larger contiguous shapes)
		// the noise function generates values between 0 and 1 -
			// a positive threshold value tells it to draw if the sampled noise value is less than the threshold
			// a negative threshold value tells it to draw if the sampled noise value is greater than the absolute value of the threshold

		void draw_point(vec point, Vox set, bool draw=true, bool mask=false);
		//draws a point at the location given by the input argument

		void draw_line_segment(vec v1, vec v2, Vox set, bool draw=true, bool mask=false); //dump this in favor of the more flexible draw_cylinder
		//draws a line segment from point1 to point2

		void draw_triangle(vec v0, vec v1, vec v2, float thickness, Vox set, bool draw=true, bool mask=false);
		//draws a triangle between point 1, point 2 and point 3

		void draw_sphere(vec center, double radius, Vox set, bool draw=true, bool mask=false);
		//draws a sphere centered at the point center, with a radius set by radius

		void draw_ellipsoid(vec center, vec radii, Vox set, bool draw=true, bool mask=false);
		//draws an ellipsoid, which is a sphere that has three separate radii
			//this needs to be extended so that this shape can rotate. As we sit right now
			//this shape can change position but the axes can be only along the cardinal
			//axes of the block. It should be a relatively simple thing to use a rotation
			//matrix, but I will need to think about the architecture of the function.

		void draw_cylinder(vec bvec, vec tvec, double radius, Vox set, bool draw=true, bool mask=false);
		//draws a cylinder with circular faces centered at bvec and tvec, with the
			//radius specified by the input argument.

		void draw_tube(vec bvec, vec tvec, double inner_radius, double outer_radius, Vox set, bool draw=true, bool mask=false);
		//draws a cylinder that has a smaller cyilnder taken out of the center
			//	>>	make sure to add validation code for if inner >= outer

		void draw_quadrilateral_hexahedron(vec a, vec b, vec c, vec d, vec e, vec f, vec g, vec h, Vox set, bool draw=true, bool mask=false);
		//draws a block shape that can be stretched, skewed, twisted and rotated.
			//the main issue comes in when the four points making up a face do not lie in
			//the same plane - there the algorithm has to choose between two ambigous
			//cases and the results will be less than predictable i.e. a default is used.

			// note, re: arrangement of verticies on quadrilaterial hexahedron:
						// 	a : -x, +y, +z
						// 	b : -x, -y, +z
						// 	c : +x, +y, +z
						// 	d : +x, -y, +z
						// 	e : -x, +y, -z
						// 	f : -x, -y, -z
						// 	g : +x, +y, -z
						// 	h : +x, -y, -z

		void draw_regular_icosahedron(double x_rot, double y_rot, double z_rot, double scale, vec center_point, Vox vertex_material, double verticies_radius, Vox edge_material, double edge_thickness, Vox face_material, bool draw_faces = true, bool draw=true, bool mask=false);
		//too many arguments? allows for the scaling, rotation and then placement of the icosahedron.
			//in addition, a material can be specified to use for the vertexes, the material for the edges, and that for the faces.
			//the edge width (0 -> don't draw, 0-1 -> draw a line or >1 -> draw a cylinder) and the radius of the spheres for the verticies can be specified.
			//right now there's no way to manipulate the faces, beyond the material.

		void draw_heightmap(/*std::string filename, std::vector<Vox> materials,*/ bool draw=true, bool mask=false);
			//how to handle materials? vector<Vox> as an argument, then equate the ratios of height/max height to index/length

		void draw_minecraft_style_terrain( vec offset=vec(0.0f, 0.0f, 0.0f), vec scale=vec(0.006f, 0.004f, 0.008f), bool draw=true, bool mask=false);
			// scaled perlin noise - there's potentially a lot of directions to go with this

		void blur( int radius, bool change_alpha);


//      __    _       __    __  _
//     / /   (_)___ _/ /_  / /_(_)___  ____ _
//    / /   / / __ `/ __ \/ __/ / __ \/ __ `/
//   / /___/ / /_/ / / / / /_/ / / / / /_/ /
//  /_____/_/\__, /_/ /_/\__/_/_/ /_/\__, /
//          /____/                  /____/



		void lighting_directional();
		//uses nearly the same algorithm as the CPU renderer

		void lighting_ambient_occlusion();

		void lighting_point_lighting();


};


#endif
