
//  Application.hpp
//  glfw-cmake-boilerplate
//
//  Created by Ackou Jens on 05/08/2016.
//
//

#ifndef Application_hpp
#define Application_hpp

//#include <string>
#include <iostream>
#include <GLFW/glfw3.h>

class Application {
public:
    Application() {
        
    }
    
    virtual ~Application() {
        
    }

  GLFWwindow *window;



  virtual void run(Application *app) {
    std::cout << "Running Application ..." << std::endl;

    if (!glfwInit()) {
      std::cout << "GLFW initialization failed !" << std::endl;
    } else {
      std::cout << "GLFW initialized" << std::endl;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    this->window = glfwCreateWindow(640,
                                    480,
                                    "My Application",
                                    NULL,
                                    NULL);

    if (!window) {
      std::cout << "Window or OpenGL context creation failed !" << std::endl;
    } else {
      std::cout << "Window or OpenGL context created" << std::endl;
    }

    glfwMakeContextCurrent(this->window);
      
      while(true) {
          render(glfwGetTime());
          glfwSwapBuffers(window);
          glfwPollEvents();
      }
      
      glfwDestroyWindow(window);
      glfwTerminate();
  }
    
    virtual void render(double currentTime) {
        
    }
};

#define DECLARE_MAIN(a)                 \
  int main(int argc, const char **argv) \
  {                                     \
                                        \
    a *app = new a;                     \
                                        \
    app->run(app);                      \
    delete app;                         \
    return 0;                           \
  }

#endif /* Application_hpp */
