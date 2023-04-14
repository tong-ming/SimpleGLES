#version 300 es

precision mediump float;

in vec3 Normal;
in vec3 FragPos;

out vec4 FragColor;

uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec3 ObjColor;
uniform vec3 viewPos;

void main()
{
    // ambient
    float ambientStrenth = 0.1;
    vec3 ambient = ambientStrenth * lightColor;

    // diffuse
    float dist = distance(lightPos, FragPos);
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor * (1.0 / (1.0 + (0.25 * dist * dist)));

    // spectrum
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm); 
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 128.0);
    float specularStrength = 0.5;
    vec3 specular = specularStrength * spec * lightColor;  

    vec3 result = (ambient + diffuse + specular) * ObjColor;
    FragColor = vec4(result, 1.0);
}