#ifndef _SHADER_IMPORTER_H_
#define _SHADER_IMPORTER_H_
#include "Globals.h"

class ResourceShader;

#include <string>

namespace ShaderImporter
{
	void CreateandCompile(char* fileBuffer, ResourceShader* shader, const char* assets_path);
	void ShaderProgram(ResourceShader* shader);
}

#endif