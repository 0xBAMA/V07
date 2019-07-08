#version 450 core

in  vec4 color;
in  vec4 vPosition_passthrough;
out vec4 fColor;

in vec3 TexCoord;
uniform sampler3D ourTexture;

uniform float offset;
uniform float slice_width;

void main()
{
  if(slice_width == 0.0)
  {// regular navigation of the slice, like what there was before

    if(vPosition_passthrough.x == offset)
    {
      //fColor = color;
      fColor = vec4(1.0,1.0,1.0,0.3) + texture(ourTexture, TexCoord);
    }
    else
    {
      fColor = texture(ourTexture, TexCoord);
    }
  }
  else
  {// we are dealing with a nonzero slice width - blank out slices except those within slice_width of offset
    if(abs(vPosition_passthrough.x - offset) <= (slice_width/2.0))
    {
      fColor = texture(ourTexture, TexCoord);
    }
    else
    {
      fColor = vec4(0,0,0,0);
    }
  }
}
