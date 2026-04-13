#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace icarus
{
	class Window
	{
	public:
		Window(int width, int height, const char* title,GLFWmonitor *monitor, GLFWwindow *window);
		~Window();
	private:
		int initialize_window();
		
		void render_loop();
		int m_width;
		int m_height;
		const char* m_title;
		GLFWmonitor* m_monitor;
		GLFWwindow* m_window;
	};
}	