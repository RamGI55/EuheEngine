
#include "Euhe.h"
#include "Shader.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void DrawingTriangle();

// Settings
//---------
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main ()
{
    // glfw : initialise and configure
    //--------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // if the programme runs in the Apple Slicon
    // -----------------------------------------
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw Window creation
    //----------------------
    GLFWwindow* window = glfwCreateWindow(800, 600, "Euhe Engine", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // if failed the initialsation
    // ---------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    // build and compile the shader program
    //--------------------------------------
    Euhe::Shader testShader("../Shader/3.3.shader.vs", "../Shader/3.3.shader.fs");
    const float offset = 1000.f;
    testShader.setFloat("xOffset", offset);

    // Set the vertex attributes and send it to the Graphic Card
    //-----------------------------------------------------------
    float vertices[] = {
        // positions            // colours
        -0.5f,   0.5f,  0.0f,   1.0f,   0.0f,   0.0f,   // bottom left
        0.5f,   0.5f,   0.0f,   0.0f,   1.0f,   0.0f,   // bottom right
        0.0f,   -0.5f,   0.0f,   0.0f,   0.0f,   1.0f    // top right
        };

    // indices information
    //--------------------
    unsigned int indices[] = {  // note it starts from 0.
        0, 1, 3,        // first triangle
        1, 2, 3         // second triangle
    };

    // texture coordinate
    //--------------------
    float texCoords[] = {
    0.0f, 0.1f,
    1.0f, 1.0f,
    0.5f, 0.0f};

    // initialise the arrays
    //---------------------
    unsigned int VBO;
    unsigned int VAO;


    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // bind the vertex array object first.
    // -----------------------------------
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6* sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // new colour attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6* sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // linking the vertex attributes
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // Actual Rendering loops
    //------------------------
    while (!glfwWindowShouldClose(window))
    {
        // processing input
        processInput(window);

        // rendering
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        testShader.activate();

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        // check and call events and swap the buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // After finished the window loop, returns the array and pointers
    // --------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    glfwTerminate();
    return 0;
}

// Set the framebuffer - windows size callback
// --------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

// Processing the input, like inputmanager
// ---------------------------------------
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    // Goes the polygon mode if press the F key
    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}


void DrawingTriangle()
{

}