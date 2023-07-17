#version 330 core
layout (location = 0) in vec3 iPos;
layout (location = 1) in vec3 iColor;
layout (location = 2) in vec2 iTexCoord;

out vec3 vertexColor;
out vec3 vertexPosition;
out vec2 vertexUV;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(iPos, 1.0);
    vertexColor = iColor;
    vertexPosition = gl_Position.xyz;
    vertexUV = iTexCoord;
}
