// TODO Make available by calling "#include <Application>"

#include "Application/Application.hpp"

// #include <OpenGL/gl.h>
#include <OpenGL/gl3.h>
#include <GLFW/glfw3.h>

class my_application : public Application {
public:

  // Overridden Render Function
  void render(double currentTime) {
    // FIXME Undeclared identifier
    // Clear the window with a red color
    static const GLfloat red[] = { 1.0f, 0.0f, 0.0f, 1.0f };

    glClearBufferfv(GL_COLOR, 0, red);

    /*
        glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(this->window);
     */
  }
};

DECLARE_MAIN(my_application);

// int main() {
//  Application application("glfw-cmake-boilerplate", 640, 480);
// }
