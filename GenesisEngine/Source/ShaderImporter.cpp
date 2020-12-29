#include "ShaderImporter.h"
#include "ResourceShader.h"
#include "FileSystem.h"

#include "glew/include/glew.h"

void ShaderImporter::CreateandCompile(char* fileBuffer, ResourceShader* shader, const char* assets_path)
{

	std::string path_str = assets_path;

	if (path_str.find(".vert") != -1) {

		GLuint vertexShader;
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &fileBuffer, NULL);
		glCompileShader(vertexShader);
		GLint success;
		GLchar infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (success == 0)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			LOG("Shader compilation error: %s", infoLog);
			glDeleteShader(vertexShader);
		}

	}

	else if (path_str.find(".frag") != -1) {
	
		GLuint fragmentShader;
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fileBuffer, NULL);
		glCompileShader(fragmentShader);
		GLint success;
		GLchar infoLog[512];
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (success == 0)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			LOG("Shader compilation error: %s", infoLog);
			glDeleteShader(fragmentShader);
		}

	}

}
void ShaderImporter::ShaderProgram(ResourceShader* shader) {

	/*GLuint shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	GLint success;
	GLchar infoLog[512];
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		LOG("Shader link error: %s", infoLog);
	}*/

}