#version 330 core
out vec4 FragColor;

in vec3 vertexColor;
in vec3 vertexPosition;
in vec2 vertexUV;

uniform sampler2D ourTexture;

void main()
{
   FragColor = vec4(vertexColor, 1.0, 1.0);
}
