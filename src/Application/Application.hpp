
//  Application.hpp
//  glfw-cmake-boilerplate
//
//  Created by Ackou Jens on 05/08/2016.
//
//

#ifndef Application_hpp
#define Application_hpp

#include <iostream>
#include <GLFW/glfw3.h>

class Application {
public:
    GLFWwindow *window;
    
    Application();
    virtual ~Application();

    virtual void run(Application *app);

    virtual void render(double currentTime);
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
