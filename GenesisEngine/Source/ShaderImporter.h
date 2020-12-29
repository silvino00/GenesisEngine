#ifndef _SHADER_IMPORTER_H_
#define _SHADER_IMPORTER_H_
#include "Globals.h"

class ResourceShader;
enum class ShaderType;

#include <string>

namespace ShaderImporter
{
	void CreateandCompile(char* fileBuffer, ResourceShader* shader, const char* path);
	void ShaderProgram(ResourceShader* shaderm, const char* path, ShaderType type);
}

#endif