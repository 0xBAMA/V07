#version 450 core

in  vec4 vColor;
in  vec4 vPosition;

out vec4 color;
out vec4 vPosition_passthrough;


out vec3 TexCoord;

uniform vec3 theta;
uniform mat4 view;

uniform float offset;
uniform float slice_width;

void main()
{
    // Compute the sines and cosines of theta for each of
    //   the three axes in one computation.
    vec3 angles = radians( theta );
    vec3 c = cos( angles );
    vec3 s = sin( angles );

    // Remember: these matrices are column-major
    mat4 rx = mat4( 1.0,  0.0,  0.0, 0.0,
		    0.0,  c.x,  s.x, 0.0,
		    0.0, -s.x,  c.x, 0.0,
		    0.0,  0.0,  0.0, 1.0 );

    mat4 ry = mat4( c.y, 0.0, -s.y, 0.0,
		    0.0, 1.0,  0.0, 0.0,
		    s.y, 0.0,  c.y, 0.0,
		    0.0, 0.0,  0.0, 1.0 );

    // Workaround for bug in ATI driver
    ry[1][0] = 0.0;
    ry[1][1] = 1.0;

    mat4 rz = mat4( c.z, -s.z, 0.0, 0.0,
		    s.z,  c.z, 0.0, 0.0,
		    0.0,  0.0, 1.0, 0.0,
		    0.0,  0.0, 0.0, 1.0 );

    // Workaround for bug in ATI driver
    rz[2][2] = 1.0;

    color = vColor;

    //if(vPosition.x == offset){
    //  color = vec4(0,0,0,1);
    // }

    vPosition_passthrough = vPosition;


    TexCoord = vec3( 1* 0.5 * (vPosition.x + 1.0), 1* 1 * (vPosition.y + 0.5), 1* 1 *(vPosition.z + 0.5));

    gl_Position = view * rz * ry * rx * vPosition;
}
