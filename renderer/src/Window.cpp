#include "include/Window.h"

namespace icarus
{
    void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    void processInput(GLFWwindow* window);

	Window::Window(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* window)
		: m_width(width), m_height(height), m_title(title), m_monitor(monitor), m_window(window) 
	{
		Window::initialize_window();
		Window::render_loop();
	}

	int Window::initialize_window()
	{
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        m_window = glfwCreateWindow(m_width, m_height, m_title, m_monitor, m_window);
        if (m_window == NULL)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return -1;
        }
        glfwMakeContextCurrent(m_window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return -1;
        }

        glViewport(0, 0, m_width, m_height);

        glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
	}

    void Window::render_loop()
    {
        while (!glfwWindowShouldClose(m_window))
        {
            processInput(m_window);
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(m_window);
            glfwPollEvents();
        }
	}

    void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }

    void processInput(GLFWwindow* window)
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
    }

	Window::~Window()
    {
        glfwTerminate();
    }
}	