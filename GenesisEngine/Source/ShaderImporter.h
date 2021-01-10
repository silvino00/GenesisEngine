#ifndef _SHADER_IMPORTER_H_
#define _SHADER_IMPORTER_H_
#include "Globals.h"

class ResourceShader;
enum class ShaderType;

typedef unsigned int GLuint;
#include <string>

namespace ShaderImporter
{
	void CreateandCompile(char* fileBuffer, ResourceShader* shader, const char* path);
	GLuint VertexCompilation(char* ShaderSource);
	GLuint FragmentCompilation(char* ShaderSource);

	void ShaderProgram(ResourceShader* shaderm);
}

#endif