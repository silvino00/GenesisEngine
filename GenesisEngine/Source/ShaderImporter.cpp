#include "ShaderImporter.h"
#include "ResourceShader.h"
#include "FileSystem.h"

#include "glew/include/glew.h"

void ShaderImporter::CreateandCompile(char* ShaderSource, ResourceShader* shader, const char* path)
{

	std::string path_str = path;

	if (path_str.find(".vert") != -1) {

		GLuint vertexShader;
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &ShaderSource, NULL);
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
		glShaderSource(fragmentShader, 1, &ShaderSource, NULL);
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

void ShaderImporter::ShaderProgram(ResourceShader* shader, const char* path, ShaderType type) {

	GLuint shaderProgram;
	shaderProgram = glCreateProgram();

	std::string path_str = path;

	if (type == ShaderType::vertexSHADER)
	{
		glAttachShader(shaderProgram, shader->vertexShader);
	}

	if (type == ShaderType::fragmentSHADER)
	{
		glAttachShader(shaderProgram, shader->fragmentShader);
	}	
	
	glLinkProgram(shaderProgram);

	GLint success;
	GLchar infoLog[512];
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		LOG("Shader link error: %s", infoLog);
	}

}