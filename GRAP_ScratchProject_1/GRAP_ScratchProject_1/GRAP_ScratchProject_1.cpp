#include <GLFW/glfw3.h>
#include <cmath> 
#define M_PI 3.14159265358979323846

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    int n = 9;
    double r = 1.0;
    
    // Array to hold the octagon vertices
    GLfloat octagonVertices[30];  // 3 values per vertex (x, y, z), plus 1 for the center

    // Add the center vertex (optional, depending on whether you want to center the octagon)
    octagonVertices[0] = 0.0f;
    octagonVertices[1] = 0.0f;
    octagonVertices[2] = 0.0f;

    for (int i = 0; i < n; i++) {
        // Angle in radians
        double angle = (i * M_PI / 4);  // 45 degrees in radians
        GLfloat x = r * cos(angle);  // Calculate x-coordinate
        GLfloat y = r * sin(angle);  // Calculate y-coordinate

        // Store the vertex in the array
        octagonVertices[3 * (i + 1)] = x;
        octagonVertices[3 * (i + 1) + 1] = y;
        octagonVertices[3 * (i + 1) + 2] = 0.0f;  // z-coordinate is 0 for 2D
    }

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, octagonVertices);
        glDrawArrays(GL_TRIANGLE_FAN, 0, n + 1);  
        glDisableClientState(GL_VERTEX_ARRAY);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}