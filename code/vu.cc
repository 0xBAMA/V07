// basic libraries
#include <iostream> //terminal I/O
#include <unistd.h> //sleep
#include <cstdlib>  //random number generation
#include <cstdio>
#include <vector>   //container
#include <string>

#include <math.h>   //sqrt, pow



#include "../resources/lodepng.h"
// Good, simple png library



//stream class shit
using std::cout;
using std::endl;
using std::cin;



//  ___________.___   _____  _____________________
//  \__    ___/|   | /     \ \_   _____/\______   \
//    |    |   |   |/  \ /  \ |    __)_  |       _/
//    |    |   |   /    Y    \|        \ |    |   \
//    |____|   |___\____|__  /_______  / |____|_  /
//                         \/        \/         \/

#include <chrono>
//Chrono class aliases

using Clock=std::chrono::high_resolution_clock;
using milliseconds=std::chrono::milliseconds;

Clock Interval_clock;

auto tick = Clock::now(); //variable to hold start of the timekeeping
auto tock = Clock::now(); //variable to hold end of timekeeping




//    ________.____        ________________________ _________________________
//   /  _____/|    |      /   _____/\__    ___/    |   \_   _____/\_   _____/
//  /   \  ___|    |      \_____  \   |    |  |    |   /|    __)   |    __)
//  \    \_\  \    |___   /        \  |    |  |    |  / |     \    |     \
//   \______  /_______ \ /_______  /  |____|  |______/  \___  /    \___  /
//          \/        \/         \/                         \/         \/


// GLEW
#define GLEW_STATIC
#include <GL/glew.h>


// GLUT
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>


// Shader Compilation
#include "../resources/shaders/Shader.h"


// CImg Image library
#include "../resources/CImg.h"


// Perlin noise - simple-to-use implementation from https://github.com/sol-prog/Perlin_Noise
#include "../resources/perlin.h"


// glsl-style Vector and Matrix Library - separate includes for different functionality
#include "../resources/glm/glm.hpp" //general types
#include "../resources/glm/gtc/matrix_transform.hpp" //orthographic view matrix (glm::ortho( left, right, bottom, top, zNear, zFar ))
#include "../resources/glm/gtc/type_ptr.hpp" //allows the sending of a matrix (weird workaround for glUniform...)




GLfloat left = -1.366f;
GLfloat right = 1.366f;
GLfloat top = -0.768f;
GLfloat bottom = 0.768f;
GLfloat zNear = -1.0f;
GLfloat zFar = 1.0f;

// don't really need this, it's really just for convenience
typedef glm::vec4  color4;
typedef glm::vec4  point4;



// image dimensions, based on laptop screen resolution
const int image_height = 768/2;
const int image_width = 1366/2;


// verticies
const int NumVertices = 3000000;



// Array of rotation angles (in degrees) for each coordinate axis
enum { Xaxis = 0, Yaxis = 1, Zaxis = 2, NumAxes = 3 };
int      Axis = Xaxis;
GLfloat  Theta[NumAxes] = { 0.0, 0.0, 0.0 };

GLuint  theta_loc;  // The location of the "theta" shader uniform variable
GLuint  ortho_matrix_loc; //location of the orthographic view matrix
GLuint  offset_loc;
GLuint  slice_width_loc; //controls the slice

glm::mat4 Projection;

bool rotate = true;
bool rotation_direction = true;


//initial value of point size
GLfloat pointsize = 1.0;


point4 points[NumVertices];
color4 colors[NumVertices];


float slice_width = 0.0f;


//how many slices
const int num_offsets = 512;
// const int num_offsets = 1024;
int current_offset;
float offsets[num_offsets];

// .___ _______  .______________
// |   |\      \ |   \__    ___/
// |   |/   |   \|   | |    |
// |   /    |    \   | |    |
// |___\____|__  /___| |____|
//             \/

//----------------------------------------------------------------------------

int Index = 0; //tracks the number of points generated

void generate_points()
{

	PerlinNoise p;

	GLfloat increment = 1.0/256.0;
	GLfloat increment_offset = 1.0/512.0;
	// GLfloat increment_offset = 0;



	current_offset = 0;


//THE TRIANGLE THING - Slices

		for(float x = 1.0; x >= -1.0; x -= increment )
		{
			// draw quad slices along the x axis, using triangles like so
			// A.____.B
			//  |\   |		^y
			//  | \  |    |
			//  |  \ |    |
			//  |   \|    |____>z
			// D.____.C


			// 'points' are obviously the vertex location for the triangle, slices holds
			// a number which is used to animate a 'pulse' traveling down the block's x axis

	// A quad is two triangles -

			//TRIANGLE ABC
			// POINT A
			points[Index] = point4( x + increment_offset, 0.5, -0.5, 1.0 );
			colors[Index] = point4( 1.0, 1.0, 1.0, 1.0);
			Index++;

			// POINT B
			points[Index] = point4( x + increment_offset, 0.5, 0.5, 1.0 );
			colors[Index] = point4( 1.0, 1.0, 1.0, 1.0);
			Index++;

			// POINT C
			points[Index] = point4( x + increment_offset, -0.5, 0.5, 1.0 );
			colors[Index] = point4( 1.0, 1.0, 1.0, 1.0);
			Index++;


			//TRIANGLE ACD
			// POINT A
			points[Index] = point4( x + increment_offset, 0.5, -0.5, 1.0 );
			colors[Index] = point4( 1.0, 1.0, 1.0, 1.0);
			Index++;

			// POINT C
			points[Index] = point4( x + increment_offset, -0.5, 0.5, 1.0 );
			colors[Index] = point4( 1.0, 1.0, 1.0, 1.0);
			Index++;

			// POINT D
			points[Index] = point4( x + increment_offset, -0.5, -0.5, 1.0 );
			colors[Index] = point4( 1.0, 1.0, 1.0, 1.0);
			Index++;


			cout << "\rgenerate_points() produced " << Index << " points";

			offsets[current_offset] = x + increment_offset;
			current_offset++;

		}

		cout << endl;


		current_offset = 0;
	//done
}


#define STB_IMAGE_IMPLEMENTATION
#include "../resources/stb_image.h" //used to load texture into GPU memory


GLuint texture; //handle for the texture

// OpenGL initialization
void init( Shader s )
{


		// enable z buffer for occlusion
		glEnable( GL_DEPTH_TEST );
		glEnable( GL_TEXTURE_3D );


		// alpha blending
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		// glBlendFunc(GL_ONE, GL_ONE);


		glGenTextures(1, &texture); // Generate an ID
		glBindTexture(GL_TEXTURE_3D, texture); // use the specified ID

		// set the texture wrapping/filtering options (on the currently bound texture object)
		// glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
		// glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
		// glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_MIRRORED_REPEAT);

		glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_REPEAT);

		// glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		// glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		// glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		// glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		// This one looks the best
		glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);


		// load and generate the texture
		// int width, height, nrChannels;
		// unsigned char *data = stbi_load("bigass.png", &width, &height, &nrChannels, 0);
		// unsigned short int *data = stbi_load("save.png", &width, &height, &nrChannels, 0);



		// Load file and decode image.
		// std::vector<unsigned short int> image_data;















		//THIS IS FOR 16 BIT ALPHA

		//
		// std::vector<unsigned char> color_image_data;
		// std::vector<unsigned char> alpha_image_data;
		//
		//
		// unsigned width, height;
		//
		// unsigned error_color = lodepng::decode( color_image_data, width, height, "current_model/save_color_8bit.png", LodePNGColorType::LCT_RGB, 8 );
		//
		// unsigned error_alpha = lodepng::decode( alpha_image_data, width, height, "current_model/save_alpha_16bit.png", LodePNGColorType::LCT_GREY, 16 );
		//
		//
		// //combine the arrays - red, green, blue, alpha - must
		// std::vector<unsigned char> image_data;
		// int color_index = 0;
		// int alpha_index = 0;
		//
		//
		// for(int i = 0; i < width * height; i++)
		// {
		//
		// 	image_data.push_back(0);//low bits
		// 	image_data.push_back(color_image_data[color_index]); //red
		//
		// 	color_index++;
		//
		// 	image_data.push_back(0);//low bits
		// 	image_data.push_back(color_image_data[color_index]); //green
		//
		// 	color_index++;
		//
		// 	image_data.push_back(0);//low bits
		// 	image_data.push_back(color_image_data[color_index]); //blue
		//
		// 	color_index++;
		//
		//
		// 	image_data.push_back(alpha_image_data[alpha_index+1]); // low bits
		// 	image_data.push_back(alpha_image_data[alpha_index]);  // high bits
		//
		// 	alpha_index+=2;
		//
		// }


		unsigned width, height;
		std::vector<unsigned char> image_data;

		unsigned error = lodepng::decode( image_data, width, height, "current_model/save.png", LodePNGColorType::LCT_RGBA, 8 );





		// if (error_color == 0 && error_alpha == 0)

		if( error == 0 )
		{
			// glTexImage3D(GL_TEXTURE_3D, 0, GL_RGBA16, 512, 256, 256, 0,  GL_RGBA, GL_UNSIGNED_SHORT, &image_data[0]);

			glTexImage3D(GL_TEXTURE_3D, 0, GL_RGBA, 512, 256, 256, 0,  GL_RGBA, GL_UNSIGNED_BYTE, &image_data[0]);

	    glGenerateMipmap(GL_TEXTURE_3D);
		}
		else
		{
	    std::cout << "Failed to load texture" << std::endl;

			// if(error_color)
			// 	std::cout << "error (color) " << error_color << ": " << lodepng_error_text(error_color) << std::endl;
			//
			// if(error_alpha)
			// 	std::cout << "error (alpha) " << error_alpha << ": " << lodepng_error_text(error_alpha) << std::endl;


			if(error) std::cout << "error " << error << ": " << lodepng_error_text(error) << std::endl;

		}





		generate_points();

    // Create a vertex array object
    GLuint vao;
    glGenVertexArrays( 1, &vao );
    glBindVertexArray( vao );

    // Create and initialize a buffer object
    GLuint buffer;
    glGenBuffers( 1, &buffer );
    glBindBuffer( GL_ARRAY_BUFFER, buffer );
    glBufferData( GL_ARRAY_BUFFER, sizeof(points) + sizeof(colors), NULL, GL_STATIC_DRAW );
    glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(points), points );
    glBufferSubData( GL_ARRAY_BUFFER, sizeof(points), sizeof(colors), colors );

    // Use the shader program ( input from and compiled in main() )
		s.Use();



    // set up vertex arrays

		// vertex locations
    GLuint vPosition = glGetAttribLocation( s.Program, "vPosition" );
    glEnableVertexAttribArray( vPosition );
    glVertexAttribPointer( vPosition, 4, GL_FLOAT, GL_FALSE, 0, (GLvoid*) (0) );


		// vertex colors
    GLuint vColor = glGetAttribLocation( s.Program, "vColor" );
    glEnableVertexAttribArray( vColor );
    glVertexAttribPointer( vColor, 4, GL_FLOAT, GL_FALSE, 0, (GLvoid*) (sizeof(points)) );


		// uniform value for rotation
    theta_loc = glGetUniformLocation( s.Program, "theta" );
		ortho_matrix_loc = glGetUniformLocation( s.Program, "view" ); //allows the scaling to the screen dimensions
		offset_loc = glGetUniformLocation( s.Program, "offset" );
		slice_width_loc = glGetUniformLocation( s.Program, "slice_width" );


		glUniform1f( offset_loc, offsets[current_offset] );
		glUniform1f( slice_width_loc, slice_width );



		Projection = glm::ortho(left, right, top, bottom, zNear, zFar);

		glUniformMatrix4fv( ortho_matrix_loc, 1, GL_FALSE,  glm::value_ptr( Projection ) );




		// what color background?
    // glClearColor( 0.618, 0.618, 0.618, 1.0 );
		glClearColor(  0.167, 0.5, 0.618,   1.0 );
}



//   ________.____     ____ ______________
//  /  _____/|    |   |    |   \__    ___/
// /   \  ___|    |   |    |   / |    |
// \    \_\  \    |___|    |  /  |    |
//  \______  /_______ \______/   |____|
// 	    	 \/        \/

//----------------------------------------------------------------------------

int frame_timer_index = 0;
bool show_frame_time = false;


const int num_frames_history = 180;
int frame_times[num_frames_history];


void display( void )
{

		tick = Clock::now();


    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

		// update the value of theta in the shader
    glUniform3fv( theta_loc, 1, Theta );


		// the draw call
    glDrawArrays( GL_TRIANGLES, 0, NumVertices );
		// glDrawArrays( GL_LINE_LOOP, 0, NumVertices );


    glutSwapBuffers();



		tock = Clock::now();

		if( frame_timer_index = num_frames_history ){ frame_timer_index = 0; }else{ frame_timer_index++; }

		frame_times[frame_timer_index] = ( int ) std::chrono::duration_cast<milliseconds>( tock - tick ).count( );

		if ( show_frame_time )
			std::cout << frame_times[frame_timer_index] << " milliseconds" << endl;


}

//----------------------------------------------------------------------------

void keyboard( unsigned char key, int x, int y )
{
    switch( key )
		{
			// quit
			case 033: // Escape Key
			case 'q': case 'Q':
			    exit( EXIT_SUCCESS );
			    break;

			// toggle rotation
			case 'r':
					//condition ? result_if_true : result_if_false
					rotate = rotate ? false : true;
					break;

			// change direction of rotation
			case 't':
					rotation_direction = rotation_direction ? false : true;
					break;

			// change to known rotation
			case 'y':
					Theta[0] = 42;
					Theta[1] = 38;
					Theta[2] = 0;
					rotate = false;
					break;

			// echo to command line the current rotation
			case 'j':
					cout << Theta[0] << " " << Theta[1] << " " << Theta[2] << endl;
					break;

			// resize points
			case 'a':
					pointsize += 1;
					glPointSize( pointsize );
					// glLineWidth( pointsize );
					break;
		  case 'z':
					pointsize -= 1;
					glPointSize( pointsize );
					// glLineWidth( pointsize );

					break;


			// toggle frame counter
			case 'f':
			//condition ? result_if_true : result_if_false
			show_frame_time = show_frame_time ? false : true;
			break;

			//ZOOM
		  case 's':
				 left *= 1.1;
				 right *= 1.1;
				 top *= 1.1;
				 bottom *= 1.1;
				 zNear *= 1.1;
				 zFar *= 1.1;

				 Projection = glm::ortho(left, right, top, bottom, zNear, zFar);

		 			glUniformMatrix4fv( ortho_matrix_loc, 1, GL_FALSE,  glm::value_ptr( Projection ) );
				 break;

		  case 'x':
					left *= 0.9;
					right *= 0.9;
					top *= 0.9;
					bottom *= 0.9;
					zNear *= 0.9;
					zFar *= 0.9;

					Projection = glm::ortho(left, right, top, bottom, zNear, zFar);

				 glUniformMatrix4fv( ortho_matrix_loc, 1, GL_FALSE,  glm::value_ptr( Projection ) );
				break;


			//MOVE THE SLICE
			case '[':
				current_offset+=1;

				if(current_offset >= num_offsets)
					current_offset = 0;

				glUniform1f( offset_loc, offsets[current_offset] );

				break;

			case ']':
				current_offset-=1;

				if(current_offset < 0)
					current_offset = num_offsets-1;

				glUniform1f( offset_loc, offsets[current_offset] );

				break;

			//WIDEN OR SHRINK THE SLICE
			case 'o':
				slice_width += 0.005;
				glUniform1f( slice_width_loc, slice_width );
				break;
			case 'p':
				slice_width -= 0.005;

				if(slice_width < 0)
					slice_width = 0;

				glUniform1f( slice_width_loc, slice_width);
				break;

    }
}

//----------------------------------------------------------------------------

void mouse( int button, int state, int x, int y )
{
  if ( state == GLUT_DOWN )
	{
		switch( button )
		{
		    case GLUT_LEFT_BUTTON:    Axis = Xaxis;  break;
		    case GLUT_MIDDLE_BUTTON:  Axis = Yaxis;  break;
		    case GLUT_RIGHT_BUTTON:   Axis = Zaxis;  break;
		}
  }
}

//----------------------------------------------------------------------------

void timer(int)
{

	if( rotate ){
		if( rotation_direction ){
			Theta[Axis] += 0.5;

			if ( Theta[Axis] > 360.0 ) {
					Theta[Axis] -= 360.0;
			}
		}else{ //rotate the other way
			Theta[Axis] -= 0.5;

			if ( Theta[Axis] < 0.0 ) {
					Theta[Axis] += 360.0;
			}
		}
	}

	glutPostRedisplay();
	glutTimerFunc(1000.0/60.0, timer, 0);
}

//----------------------------------------------------------------------------

void idle( void )
{
	// glutPostRedisplay();
}

//----------------------------------------------------------------------------



//    _____      _____  .___ _______
//   /     \    /  _  \ |   |\      \
//  /  \ /  \  /  /_\  \|   |/   |   \
// /    Y    \/    |    \   /    |    \
// \____|__  /\____|__  /___\____|__  /
// 		     \/         \/            \/


int main( int argc, char **argv )
{

	std::cout << "GLUT Initializing...";

	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );
	glutInitWindowSize( image_width, image_height );
	// glutInitWindowSize( 500, 500 );
	glutInitContextVersion( 4, 5 );
	glutInitContextProfile( GLUT_CORE_PROFILE );
	glutCreateWindow( "GLUT Window" );
	glutFullScreen();

	cout << "\rGLUT Initialization Complete." << endl;


	glewExperimental = GL_TRUE;
  glewInit();

	cout << "OpenGL Context established, version is: " << glGetString(GL_VERSION) << endl;


	cout << "Shader Compilation Starting...";

	Shader theShader( "../resources/shaders/vertex_textures3d.glsl", "../resources/shaders/fragment_textures3d.glsl" );

	cout << "\rShader Compilation Complete.  " << endl;


	cout << "Generating Geometry";

  init( theShader );

	cout << "\rInitialization done." << endl;


  glutDisplayFunc( display );
  glutKeyboardFunc( keyboard );
  glutMouseFunc( mouse );
  glutIdleFunc( idle );
	glutTimerFunc(1000.0/60.0, timer, 0);

  glutMainLoop();



	std::cout << "Exiting" << std::endl;

	return 0;
}
