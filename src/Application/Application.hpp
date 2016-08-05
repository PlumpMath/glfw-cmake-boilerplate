
//  Application.hpp
//  glfw-cmake-boilerplate
//
//  Created by Ackou Jens on 05/08/2016.
//
//

#ifndef Application_hpp
#define Application_hpp

#include <string>
#include <GLFW/glfw3.h>

class Application {
private:

  char *title;
  int   width;
  int   height;

  GLFWwindow *window;

  int  initialize();
  int  run();
  void loop();

public:

  Application(char *newTitle,
              int   newWidth,
              int   newHeight);
  ~Application();

protected:
};


#endif /* Application_hpp */
