#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "include/Shader.h"

namespace icarus
{
	class Renderer
	{
	public:
		Renderer();
		~Renderer();
		void draw();
	private:
		float m_vertices[12] = {
			0.5f,0.5f,0.0f, // left  
			0.5f,-0.5f,0.0f, // right 
			-0.5f,-0.5f,0.0f,	 
			-0.5f, 0.5f,0.0f // top   
		};

		unsigned int m_indices[6] = {  // note that we start from 0!
		3, 0, 1,  // first Triangle
		1, 2, 3   // second Triangle
		};
		unsigned int m_VBO, m_VAO, m_EBO;
		Shader m_triangle_shader;
	};
}