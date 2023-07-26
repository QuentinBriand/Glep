#version 330 core
out vec4 FragColor;

in vec3 vertexColor;
in vec3 vertexPosition;
in vec2 vertexUV;

uniform sampler2D ourTexture;

void main()
{
   vec3 textureColor = texture(ourTexture, vertexUV).rgb;
   FragColor = vec4(textureColor, 1.0);
}
