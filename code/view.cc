// basic libraries
#include <iostream> //terminal I/O
#include <unistd.h> //sleep
#include <cstdlib>  //random number generation
#include <cstdio>
#include <vector>   //container
#include <string>

#include <math.h>   //sqrt, pow




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


// this namespace contains, for either platform:
//		ortho() matrix variables
//		vector types, vector arrays for points and colors
//    image dimensions
// 		definition of point size
//		definition of rotation and rotation_direction toggles
//
//

namespace jb_OpenGL_Laptop{

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
	const int image_height = 768;
	const int image_width = 1366;


	// verticies - THINKPAD
	const int NumVertices = 3000000;

	point4 points[NumVertices];
	color4 colors[NumVertices];




	// Array of rotation angles (in degrees) for each coordinate axis
	enum { Xaxis = 0, Yaxis = 1, Zaxis = 2, NumAxes = 3 };
	int      Axis = Xaxis;
	GLfloat  Theta[NumAxes] = { 0.0, 0.0, 0.0 };

	GLuint  theta;  // The location of the "theta" shader uniform variable
	GLuint  ortho_matrix;

	glm::mat4 Projection;

	bool rotate = true;
	bool rotation_direction = true;


	//initial value of point size
	GLfloat pointsize = 1.0;

}

namespace jb_OpenGL_Radeon{

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
	const int image_height = 768;
	const int image_width = 1366;


	// verticies - RADEON
	const int NumVertices = 64000000;

	point4 points[NumVertices];
	color4 colors[NumVertices];




	// Array of rotation angles (in degrees) for each coordinate axis
	enum { Xaxis = 0, Yaxis = 1, Zaxis = 2, NumAxes = 3 };
	int      Axis = Xaxis;
	GLfloat  Theta[NumAxes] = { 0.0, 0.0, 0.0 };

	GLuint  theta;  // The location of the "theta" shader uniform variable
	GLuint  ortho_matrix;

	glm::mat4 Projection;

	bool rotate = true;
	bool rotation_direction = true;


	//initial value of point size
	GLfloat pointsize = 1.0;

}


using namespace jb_OpenGL_Laptop;

//using namespace jb_OpenGL_Radeon;




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

	for( GLfloat x = -1.0; x <= 1.0 ; x += 0.01 )
	{
		for ( GLfloat y = -0.5; y <= 0.5; y += 0.01 )
		{
			for( GLfloat z = -0.5; z <= 0.5; z += 0.01 )

			//	if( p.noise( 10*x, 10*y, 10*z ) > 0.5 && p.noise( 10*x, 10*y, 10*z ) < 0.75)
				{

					// the x and y values here will be used as texture coordinates, taking advantage of wrapping
					points[Index] = point4( x, y, z, 1.0);


					colors[Index] = color4( p.noise( 10*x, 10*y, 10*z ), 0.7*p.noise( 10*x, 10*y, 10*z ), 0.3*p.noise( 10*x, 10*y, 10*z ), p.noise( 10*x, 10*y, 10*z ));



					Index++;

				}
		}
	}

	// for( GLfloat step = -0.3; step <= 0.3; step += 0.01)
	// {
	// 	points[Index] = point4( 0.0, 0.0,   step, 1.0);
	// 	colors[Index] = color4( 0.0, 0.0, 0.0, 1.0);
	//
	//
	// 	Index++;
	//
	// }


	cout << Index << endl;




	//done
}


#define STB_IMAGE_IMPLEMENTATION
#include "../resources/stb_image.h"


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




		glGenTextures(1, &texture); // Generate an ID
		glBindTexture(GL_TEXTURE_3D, texture); // use the specified ID

		// set the texture wrapping/filtering options (on the currently bound texture object)
		glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
		glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
		glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_MIRRORED_REPEAT);

		// glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		// glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);



		// load and generate the texture
		int width, height, nrChannels;
		// unsigned char *data = stbi_load("big grid.png", &width, &height, &nrChannels, 0);
		unsigned char *data = stbi_load("save.png", &width, &height, &nrChannels, 0);

		if (data)
		{
		    glTexImage3D(GL_TEXTURE_3D, 0, GL_RGBA, 256, 128, 128, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		    glGenerateMipmap(GL_TEXTURE_3D);
		}
		else
		{
		    std::cout << "Failed to load texture" << std::endl;
		}
		stbi_image_free(data);





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


		cout << sizeof( points );


		// uniform value for rotation
    theta = glGetUniformLocation( s.Program, "theta" );
		ortho_matrix = glGetUniformLocation( s.Program, "view" ); //allows the scaling to the screen dimensions`


		Projection = glm::ortho(left, right, top, bottom, zNear, zFar);

		glUniformMatrix4fv( ortho_matrix, 1, GL_FALSE,  glm::value_ptr( Projection ) );




		// what color background?
    glClearColor( 0.618, 0.618, 0.618, 1.0 );
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
    glUniform3fv( theta, 1, Theta );

		// the draw call
    glDrawArrays( GL_POINTS, 0, NumVertices );


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

			// resize points
			case 'a':
					pointsize += 1;
					glPointSize( pointsize );
					break;
		  case 'z':
					pointsize -= 1;
					glPointSize( pointsize );
					break;


			// toggle frame counter
			case 'f':
			//condition ? result_if_true : result_if_false
			show_frame_time = show_frame_time ? false : true;
			break;

		  case 's':
				 left *= 1.1;
				 right *= 1.1;
				 top *= 1.1;
				 bottom *= 1.1;
				 zNear *= 1.1;
				 zFar *= 1.1;

				 Projection = glm::ortho(left, right, top, bottom, zNear, zFar);

		 			glUniformMatrix4fv( ortho_matrix, 1, GL_FALSE,  glm::value_ptr( Projection ) );
				 break;

		  case 'x':
					left *= 0.9;
					right *= 0.9;
					top *= 0.9;
					bottom *= 0.9;
					zNear *= 0.9;
					zFar *= 0.9;

					Projection = glm::ortho(left, right, top, bottom, zNear, zFar);

				 glUniformMatrix4fv( ortho_matrix, 1, GL_FALSE,  glm::value_ptr( Projection ) );
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

void idle( void )
{

		if( rotate ){
			if( rotation_direction ){
				Theta[Axis] += 0.1;

				if ( Theta[Axis] > 360.0 ) {
						Theta[Axis] -= 360.0;
				}
			}else{ //rotate the other way
				Theta[Axis] -= 0.1;

				if ( Theta[Axis] < 0.0 ) {
						Theta[Axis] += 360.0;
				}
			}
		}

    glutPostRedisplay();
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
	glutInitContextVersion( 3, 2 );
	glutInitContextProfile( GLUT_CORE_PROFILE );
	glutCreateWindow( "GLUT Window" );
	glutFullScreen();

	std::cout << "\rGLUT Initialization Complete." << std::endl;


	glewExperimental = GL_TRUE;
  glewInit();

	cout << "OpenGL Context established, version is: " << glGetString(GL_VERSION) << endl;


	std::cout << "Shader Compilation Starting...";

	Shader theShader( "../resources/shaders/vertex_textures3d.glsl", "../resources/shaders/fragment_textures3d.glsl" );

	std::cout << "\rShader Compilation Complete.  " << std::endl;




	std::cout << "Generating Geometry";

  init( theShader );

	std::cout << "\rInitialization done." << std::endl;
	std::cout << "generate_points() produced " << Index << " points" << std::endl;



  glutDisplayFunc( display );
  glutKeyboardFunc( keyboard );
  glutMouseFunc( mouse );
  glutIdleFunc( idle );

  glutMainLoop();



	std::cout << "Exiting" << std::endl;

	return 0;
}
