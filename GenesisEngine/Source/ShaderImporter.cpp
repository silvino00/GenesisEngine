#include "ShaderImporter.h"
#include "ResourceShader.h"
#include "FileSystem.h"

#include "glew/include/glew.h"

void ShaderImporter::CreateandCompile(char* fileBuffer, ResourceShader* shader, const char* path)
{
	std::string path_str = path;
	char* buffer;

	if (path_str.find(".vert") != -1)
	{
		std::string changepath = path_str;
		changepath = changepath.substr(0, path_str.find_last_of("."));
		changepath.append(".frag");

		FileSystem::Load(changepath.c_str(), &buffer);

		shader->vertexShader = VertexCompilation(fileBuffer);
		shader->fragmentShader = FragmentCompilation(buffer);
	}
	else if (path_str.find(".frag") != -1)
	{
		std::string changepath = path_str;
		changepath = changepath.substr(0, path_str.find_last_of("."));
		changepath.append(".vert");

		FileSystem::Load(changepath.c_str(), &buffer);

		shader->fragmentShader = FragmentCompilation(fileBuffer);
		shader->vertexShader = VertexCompilation(buffer);
	}

	ShaderProgram(shader);

}

GLuint ShaderImporter::FragmentCompilation(char* ShaderSource)
{
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
	else {
		return fragmentShader;
	}

}

GLuint ShaderImporter::VertexCompilation(char* ShaderSource)
{
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
	else {
		return vertexShader;
	}
}

void ShaderImporter::ShaderProgram(ResourceShader* shader) {

	GLuint shaderProgram;
	shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, shader->vertexShader);

	glAttachShader(shaderProgram, shader->fragmentShader);
	
	glLinkProgram(shaderProgram);

	GLint success;
	GLchar infoLog[512];
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		LOG_ERROR("Error linking shader program: %s", infoLog);

		glDeleteShader(shader->vertexShader);
		glDeleteShader(shader->fragmentShader);
	}
	else
	{
		shader->shaderProgram = shaderProgram;

		glDetachShader(shaderProgram, shader->vertexShader);
		glDetachShader(shaderProgram, shader->fragmentShader);
		glDeleteShader(shader->vertexShader);
		glDeleteShader(shader->fragmentShader);
	}

}
