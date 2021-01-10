#include "ResourceShader.h"
#include "glew/include/glew.h"

ResourceShader::ResourceShader(uint UID) : Resource(UID, ResourceType::RESOURCE_SHADER)
{
	vertexShader = 0;
	fragmentShader = 0;
	shaderProgram = 0;
}

ResourceShader::~ResourceShader()
{}

void ResourceShader::CompileUseProgram()
{
	glUseProgram(shaderProgram);
}

void ResourceShader::SetMat4(const char* name, float* matrix)
{
	GLint modelLoc = glGetUniformLocation(shaderProgram, name);

	GLenum error = glGetError();
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, matrix);
}

void ResourceShader::SetFloat(const char* name, float value)
{
	GLint variableLoc = glGetUniformLocation(shaderProgram, name);

	glUniform1f(variableLoc, value);
}
