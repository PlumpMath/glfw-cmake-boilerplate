
//  Application.cpp
//  glfw-cmake-boilerplate
//
//  Created by Ackou Jens on 05/08/2016.
//
//

#include "Application.hpp"
#include <iostream>

Application::Application() {
    window = NULL;
    title = "";
    width = 0;
    height = 0;
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
        while (!glfwWindowShouldClose(this->window)) {
            if(glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
                cout << "Closing GLFW window" << endl;
                glfwSetWindowShouldClose(this->window, true);
            }
            
            render(glfwGetTime());
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    
        // Destruct
        glfwDestroyWindow(window);
        glfwTerminate();
}

void Application::render(double currentTime){}
/*
 
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
