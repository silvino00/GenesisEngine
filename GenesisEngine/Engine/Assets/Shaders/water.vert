#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec3 normals;

out vec3 FinalPosition;
uniform mat4 transform_matrix;
uniform mat4 view_matrix;
uniform mat4 projection_matrix;
uniform float time;
vec3 dir = normalize(vec3(1.0,1.0,0.25));
float l = 0.9;
float pi = 3.142;
float w = sqrt(9.8*2*pi/l);

void main() {

	float Amp = 0.03;
	float Amp2 = 0.01;
	float Amp3 = 0.01;
	float Qa =	1/(w*Amp);
	float Qb = 1/(w*Amp2);
	float Qc = 1/(w*Amp3);
	vec3 wave1;
	vec3 wave2;
	vec3 wave3;
	float phase = 0.5;
	FinalPosition = position;
	
	wave1.x = (Qa*Amp*dir.x*cos(dot(w*dir,position)+phase*time));
	wave1.y = -(Qa*Amp*dir.y*cos(dot(w*dir,position)+phase*time));
	wave1.z = Amp*sin(dot(w*dir,position)+phase*time);
	
	wave2.x = (Qb*Amp2*dir.x*cos(dot(w*dir,position)+phase*time));
	wave2.y = -(Qb*Amp2*dir.y*cos(dot(w*dir,position)+phase*time));
	wave2.z = Amp2*sin(dot(w*dir,position)+phase*time);
	
	wave3.x = (Qc*Amp3*dir.x*cos(dot(w*dir,position)+phase*time));
	wave3.y = -(Qc*Amp3*dir.y*cos(dot(w*dir,position)+phase*time));
	wave3.z = Amp3*sin(dot(w*dir,position)+phase*time);
	FinalPosition.z += wave1.z + wave2.z + wave3.z;
	 
 
  gl_Position = projection_matrix * view_matrix * transform_matrix * vec4(FinalPosition, 1.0);
}
