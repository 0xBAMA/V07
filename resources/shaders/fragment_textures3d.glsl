#version 450 core

in  vec4 color;
out vec4 fColor;

in vec3 TexCoord;
uniform sampler3D ourTexture;


void main()
{

    if(color == vec4(0,0,0,1))
    {
      fColor = color;
    }
    else
    {
      fColor = texture(ourTexture, TexCoord);
    }
}
