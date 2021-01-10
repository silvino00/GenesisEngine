#ifndef _RESOURCE_SHADER_H_
#define _RESOURCE_SHADER_H_

#include "Globals.h"
#include "Resource.h"

enum class ShaderType
{
	vertexSHADER,
	fragmentSHADER,
	noSHADER
};

class ResourceShader : public Resource {
public:
	ResourceShader(uint UID);
	~ResourceShader();

	void CompileUseProgram();
	void SetMat4(const char* name, float* matrix);

public:
	int vertexShader;
	int fragmentShader;
	int shaderProgram;
};

#endif