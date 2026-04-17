#include "include/Shader.h"

namespace icarus
{
	Shader::Shader()
	{
		m_vertexShaderSource = "#version 330 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"void main()\n"
			"{\n"
			"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
			"}\0";

		m_fragmentShaderSource = "#version 330 core\n"
			"out vec4 FragColor;\n"
			"void main()\n"
			"{\n"
			"   FragColor = vec4(0.4f, 0.7f, 1.0f, 1.0f);\n"
			"}\n\0";

		compile_vertex_shader();
		compile_fragment_shader();
		link_shaders();
	}

	Shader::~Shader()
	{
		glDeleteShader(m_vertexShader);
		glDeleteShader(m_fragmentShader);
		glDeleteProgram(m_shaderProgram);
	}	

	void Shader::compile_vertex_shader()
	{
		// build and compile our shader program
		// ------------------------------------
		// vertex shader
		m_vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(m_vertexShader, 1, &m_vertexShaderSource, NULL);
		glCompileShader(m_vertexShader);
		// check for shader compile errors
		glGetShaderiv(m_vertexShader, GL_COMPILE_STATUS, &m_success);
		if (!m_success)
		{
			glGetShaderInfoLog(m_vertexShader, 512, NULL, m_infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << m_infoLog << std::endl;
		}
	}

	void Shader::compile_fragment_shader()
	{
		// build and compile our shader program
		// ------------------------------------
		// fragment shader
		m_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(m_fragmentShader, 1, &m_fragmentShaderSource, NULL);
		glCompileShader(m_fragmentShader);
		// check for shader compile errors
		glGetShaderiv(m_fragmentShader, GL_COMPILE_STATUS, &m_success);
		if (!m_success)
		{
			glGetShaderInfoLog(m_fragmentShader, 512, NULL, m_infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << m_infoLog << std::endl;
		}
	}

	void Shader::link_shaders()
	{
		// link shaders
		m_shaderProgram = glCreateProgram();
		glAttachShader(m_shaderProgram, m_vertexShader);
		glAttachShader(m_shaderProgram, m_fragmentShader);
		glLinkProgram(m_shaderProgram);
		// check for linking errors
		glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &m_success);
		if (!m_success) {
			glGetProgramInfoLog(m_shaderProgram, 512, NULL, m_infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << m_infoLog << std::endl;
		}
	}
}