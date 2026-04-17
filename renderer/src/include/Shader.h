#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace icarus
{
	class Shader
	{
	public:
		Shader();
		~Shader();
		unsigned int m_shaderProgram;
	private:
		int m_success;
		char m_infoLog[512];
		const char* m_vertexShaderSource;
		const char* m_fragmentShaderSource;
		unsigned int m_vertexShader;
		unsigned int m_fragmentShader;
		

		void compile_vertex_shader();
		void compile_fragment_shader();
		void link_shaders();
	};
}