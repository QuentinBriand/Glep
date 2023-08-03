#version 330 core

struct Material {
    vec3 diffuse;
    sampler2D diffuseMap;

    vec3 specular;
    sampler2D specularMap;

    vec3 emissive;
    sampler2D emissiveMap;
    float emissiveStrength;

    int shininess;
    int textureFlag;
};

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

out vec4 FragColor;

in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoords;
in vec3 vertexColor;

uniform vec3 viewPos;
uniform Material material;
uniform Light light;

void main()
{
    vec3 diffuseColorMap = vec3(texture(material.diffuseMap, TexCoords));
    vec3 ambient = light.ambient * material.diffuse;
    if ((material.textureFlag & 0x01) != 0) {
        ambient *= diffuseColorMap;
    }

    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * material.diffuse;
    if ((material.textureFlag & 0x01) != 0) {
        diffuse *= diffuseColorMap;
    }

    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * (spec * material.specular);
    if ((material.textureFlag & 0x02) != 0) {
        specular *= vec3(texture(material.specularMap, TexCoords));
    }
    vec3 result = ambient + diffuse + specular;
    if ((material.textureFlag & 0x04) != 0) {
        result += vec3(texture(material.emissiveMap, TexCoords)) * material.emissiveStrength;
    }
    FragColor = vec4(result * 0.00001 + vec3(1.0), 1.0);
}
