
//  Application.cpp
//  glfw-cmake-boilerplate
//
//  Created by Ackou Jens on 05/08/2016.
//
//

#include "Application.hpp"

Application::Application() {
    window = NULL;
}

Application::~Application() {}

void Application::run(Application *app) {
    using namespace std;
        cout << "Running Application ..." << endl;
    
        // GLFW Init
        if (!glfwInit()) {
            cout << "GLFW initialization failed !" << endl;
        } else {
            cout << "GLFW initialized" << endl;
        }
        
        // Enabled OSX to use a more advanced OpenGL Version
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
        // Create Window
        this->window = glfwCreateWindow(640,
                                        480,
                                        "My Application",
                                        NULL,
                                        NULL);
        if (!window) {
            cout << "Window or OpenGL context creation failed !" << endl;
        } else {
            cout << "Window or OpenGL context created" << endl;
        }
        glfwMakeContextCurrent(this->window);
    
        // Game Loop
        while (true) {
            render(glfwGetTime());
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    
        // Destruct
        glfwDestroyWindow(window);
        glfwTerminate();
}

void Application::render(double currentTime){}

/*int Application::initialize() {
  if (!glfwInit())
  {
    std::cout << "GLFW initialization failed !" << std::endl;
  } else {
    std::cout << "GLFW initialization" << std::endl;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

  // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  this->window = glfwCreateWindow(this->width,
                                  this->height,
                                  this->title,
                                  NULL,
                                  NULL);

  if (!window) {
    std::cout << "Window or OpenGL context creation failed" << std::endl;
  } else {
    std::cout << "Context created" << std::endl;
  }

  glfwMakeContextCurrent(this->window);
  run();

  return 0;
}

int Application::run() {
  loop();
  return 0;
}

void Application::loop() {
  while (!glfwWindowShouldClose(this->window)) {
    if (glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      std::cout << "Closing GLFW window" << std::endl;
      glfwSetWindowShouldClose(this->window, true);
    }

    glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(this->window);
    glfwPollEvents();
  }
}

Application::Application(char *newTitle, int newWidth, int newHeight)  {
  this->title  = newTitle;
  this->width  = newWidth;
  this->height = newHeight;

  initialize();
}

Application::~Application() {
  std::cout << "Application destroyed !" << std::endl;

  glfwDestroyWindow(this->window);
  glfwTerminate();
}*/
