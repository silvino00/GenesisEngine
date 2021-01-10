#version 330 core

in vec3 FinalPosition;
out vec4 color;

uniform float time;
uniform float speed;
vec2 moveDir;
vec2 movement;
float cellular_noise(vec2 coord);
vec2 rand2(vec2 coord);


void main()
{
	moveDir = vec2(0.3,0.3);
	movement = vec2((cellular_noise(FinalPosition.xy) + time + moveDir) * speed);
	vec4 watercolor = vec4(0.0, 0.4,0.6,1.0);
    vec4 foamcolor =  vec4(0.5,0.7,1.0,1.0);

	float value = 0.0;
	value += cellular_noise(FinalPosition.xy+movement);
	foamcolor *= value;

	vec3 specular = watercolor.xyz;  

	vec3 foam = vec3(0.0,0.0,0.0);
	
    foam = (vec3(value));

	color = vec4((specular + foam),0.8);
}

vec2 rand2( vec2 coord ) {
  coord = mod(coord, 10000.0);
  return fract(sin(vec2(dot(coord,vec2(127.1,311.7)),dot(coord,vec2(269.5,183.3))))*43758.5453);
}

float cellular_noise(vec2 coord) {

	vec2 i = floor(coord);
	vec2 f = fract(coord);
	
	float min_dist = 99999.0;

	for(float x = -1.0; x <= 1.0; x++) {
		for(float y = -1.0; y <= 1.0; y++) {
			
			vec2 node = rand2(i + vec2(x, y)) + vec2(x, y);
			
			float dist = sqrt((f - node).x * (f - node).x + (f - node).y * (f - node).y);
			min_dist = min(min_dist, dist);
		}
	}
	return min_dist;
}