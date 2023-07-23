// #include <glad/glad.h>
// #include <GLFW/glfw3.h>
// #define STB_IMAGE_IMPLEMENTATION
// #include <stb_image.h>

// #include <glm/glm.hpp>
// #include <glm/gtc/matrix_transform.hpp>
// #include <glm/gtc/type_ptr.hpp>

// #include "shader.h"
// #include "camera.h"

// #include <iostream>

// void framebuffer_size_callback(GLFWwindow* window, int width, int height);
// void mouse_callback(GLFWwindow* window, double xpos, double ypos);
// void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
// void processInput(GLFWwindow *window);
// unsigned int loadTexture(const char *path);

// // settings
// const unsigned int SCR_WIDTH = 800;
// const unsigned int SCR_HEIGHT = 600;

// // camera
// Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
// float lastX = SCR_WIDTH / 2.0f;
// float lastY = SCR_HEIGHT / 2.0f;
// bool firstMouse = true;

// // timing
// float deltaTime = 0.0f;
// float lastFrame = 0.0f;

// // lighting
// glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

// int main()
// {
//     // glfw: initialize and configure
//     // ------------------------------
//     glfwInit();
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

// #ifdef __APPLE__
//         glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
// #endif

//     // glfw window creation
//     // --------------------
//     GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//     if (window == NULL)
//     {
//         std::cout << "Failed to create GLFW window" << std::endl;
//         glfwTerminate();
//         return -1;
//     }
//     glfwMakeContextCurrent(window);
//     glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//     glfwSetCursorPosCallback(window, mouse_callback);
//     glfwSetScrollCallback(window, scroll_callback);

//     // tell GLFW to capture our mouse
//     glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

//     // glad: load all OpenGL function pointers
//     // ---------------------------------------
//     if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//     {
//         std::cout << "Failed to initialize GLAD" << std::endl;
//         return -1;
//     }

//     // configure global opengl state
//     // -----------------------------
//     glEnable(GL_DEPTH_TEST);

//     // build and compile our shader zprogram
//     // ------------------------------------
//     Shader lightingShader("D:\\opengl-cpp-template-master\\opengl-cpp-template-master\\src\\phong.vs", "D:\\opengl-cpp-template-master\\opengl-cpp-template-master\\src\\phong.fs");
//     Shader lightCubeShader("D:\\opengl-cpp-template-master\\opengl-cpp-template-master\\src\\lightsrc.vs", "D:\\opengl-cpp-template-master\\opengl-cpp-template-master\\src\\lightsrc.fs");

//     // set up vertex data (and buffer(s)) and configure vertex attributes
//     // // ------------------------------------------------------------------
//     // float vertices[] = {
//     //     // positions          // normals           // texture coords
//     //     -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
//     //      0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
//     //      0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
//     //      0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
//     //     -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
//     //     -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,

//     //     -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
//     //      0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
//     //      0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
//     //      0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
//     //     -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
//     //     -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,

//     //     -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//     //     -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
//     //     -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//     //     -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//     //     -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
//     //     -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

//     //      0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//     //      0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
//     //      0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//     //      0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//     //      0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
//     //      0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

//     //     -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
//     //      0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
//     //      0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
//     //      0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
//     //     -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
//     //     -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,

//     //     -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
//     //      0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
//     //      0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
//     //      0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
//     //     -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
//     //     -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
//     // };
//     // // positions all containers
//     // glm::vec3 cubePositions[] = {
//     //     glm::vec3( 0.0f,  0.0f,  0.0f),
//     //     glm::vec3( 2.0f,  5.0f, -15.0f),
//     //     glm::vec3(-1.5f, -2.2f, -2.5f),
//     //     glm::vec3(-3.8f, -2.0f, -12.3f),
//     //     glm::vec3( 2.4f, -0.4f, -3.5f),
//     //     glm::vec3(-1.7f,  3.0f, -7.5f),
//     //     glm::vec3( 1.3f, -2.0f, -2.5f),
//     //     glm::vec3( 1.5f,  2.0f, -2.5f),
//     //     glm::vec3( 1.5f,  0.2f, -1.5f),
//     //     glm::vec3(-1.3f,  1.0f, -1.5f)
//     // };
// const int sides = 8;
//     const float height = 0.2f;
//     const float radius = 1.0f;
//     float breacerVertices[6 * sides * 6];
//     int index = 0;

//     for (int i = 0; i < sides; ++i)
//     {
//         float theta1 = (2 * glm::pi<float>() * (i - 0.5f)) / sides;
//         float theta2 = (2 * glm::pi<float>() * (i + 0.5f)) / sides;
//         float theta3 = (2 * glm::pi<float>() * (i + 0.0f)) / sides;
//         float theta4 = (2 * glm::pi<float>() * (i + 1.0f)) / sides;

//         glm::vec3 normal1(cos(theta1), height / 2, sin(theta1));
//         glm::vec3 normal2(cos(theta2), height / 2, sin(theta2));
//         glm::vec3 normal3(cos(theta3), -height / 2, sin(theta3));
//         glm::vec3 normal4(cos(theta4), -height / 2, sin(theta4));

//         // Quad vertices and normals
//         breacerVertices[index++] = radius * cos(theta3);
//         breacerVertices[index++] = -height / 2;
//         breacerVertices[index++] = radius * sin(theta3);
//         breacerVertices[index++] = normal3.x;
//         breacerVertices[index++] = normal3.y;
//         breacerVertices[index++] = normal3.z;

// breacerVertices[index++] = radius * cos(theta1);
//         breacerVertices[index++] = height / 2;
//         breacerVertices[index++] = radius * sin(theta1);
//         breacerVertices[index++] = normal1.x;
//         breacerVertices[index++] = normal1.y;
//         breacerVertices[index++] = normal1.z;

//         breacerVertices[index++] = radius * cos(theta2);
//         breacerVertices[index++] = height / 2;
//         breacerVertices[index++] = radius * sin(theta2);
//         breacerVertices[index++] = normal2.x;
//         breacerVertices[index++] = normal2.y;
//         breacerVertices[index++] = normal2.z;

//         breacerVertices[index++] = radius * cos(theta4);
//         breacerVertices[index++] = -height / 2;
//         breacerVertices[index++] = radius * sin(theta4);
//         breacerVertices[index++] = normal4.x;
//         breacerVertices[index++] = normal4.y;
//         breacerVertices[index++] = normal4.z;

//         breacerVertices[index++] = radius * cos(theta3);
//         breacerVertices[index++] = -height / 2;
//         breacerVertices[index++] = radius * sin(theta3);
//         breacerVertices[index++] = normal3.x;
//         breacerVertices[index++] = normal3.y;
//         breacerVertices[index++] = normal3.z;

//         breacerVertices[index++] = radius * cos(theta2);
//         breacerVertices[index++] = height / 2;
//         breacerVertices[index++] = radius * sin(theta2);
//         breacerVertices[index++] = normal2.x;
//         breacerVertices[index++] = normal2.y;
//         breacerVertices[index++] = normal2.z;
//     }
//     // positions of the point lights
//     glm::vec3 pointLightPositions[] = {
//         glm::vec3( 0.7f,  0.2f,  2.0f),
//         glm::vec3( 2.3f, -3.3f, -4.0f),
//         glm::vec3(-4.0f,  2.0f, -12.0f),
//         glm::vec3( 0.0f,  0.0f, -3.0f)
//     };
//     // first, configure the cube's VAO (and VBO)
//     unsigned int VBO, cubeVAO;
//     glGenVertexArrays(1, &cubeVAO);
//     glGenBuffers(1, &VBO);

//     glBindBuffer(GL_ARRAY_BUFFER, VBO);
//     glBufferData(GL_ARRAY_BUFFER, sizeof(breacerVertices), breacerVertices, GL_STATIC_DRAW);

//     glBindVertexArray(cubeVAO);
//     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//     glEnableVertexAttribArray(0);
//     glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//     glEnableVertexAttribArray(1);

//     // second, configure the light's VAO (VBO stays the same; the vertices are the same for the light object which is also a 3D cube)
//     unsigned int lightCubeVAO;
//     glGenVertexArrays(1, &lightCubeVAO);
//     glBindVertexArray(lightCubeVAO);

//     glBindBuffer(GL_ARRAY_BUFFER, VBO);
//     // note that we update the lamp's position attribute's stride to reflect the updated buffer data
//     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//     glEnableVertexAttribArray(0);

//     // load textures (we now use a utility function to keep the code more organized)
//     // -----------------------------------------------------------------------------

//     // shader configuration
//     // --------------------
//     lightingShader.use();
//     lightingShader.setVec3("material.ambient", 0.24725,0.1995,0.0745);
//     lightingShader.setVec3("material.diffuse", 0.75164,0.60648,0.22648);
//     lightingShader.setVec3("material.specular", 0.628281,0.555802,0.366065);

//     // render loop
//     // -----------
//     while (!glfwWindowShouldClose(window))
//     {
//         // per-frame time logic
//         // --------------------
//         float currentFrame = static_cast<float>(glfwGetTime());
//         deltaTime = currentFrame - lastFrame;
//         lastFrame = currentFrame;

//         // input
//         // -----
//         processInput(window);

//         // render
//         // ------
//         glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//         // be sure to activate shader when setting uniforms/drawing objects
//         lightingShader.use();
//         lightingShader.setVec3("viewPos", camera.Position);
//         lightingShader.setFloat("material.shininess", 0.4);

//         /*
//            Here we set all the uniforms for the 5/6 types of lights we have. We have to set them manually and index
//            the proper PointLight struct in the array to set each uniform variable. This can be done more code-friendly
//            by defining light types as classes and set their values in there, or by using a more efficient uniform approach
//            by using 'Uniform buffer objects', but that is something we'll discuss in the 'Advanced GLSL' tutorial.
//         */
//         // directional light
//         lightingShader.setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
//         lightingShader.setVec3("dirLight.ambient", 0.05f, 0.05f, 0.05f);
//         lightingShader.setVec3("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
//         lightingShader.setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);
//         // point light 1
//         lightingShader.setVec3("pointLights[0].position", pointLightPositions[0]);
//         lightingShader.setVec3("pointLights[0].ambient", 0.05f, 0.05f, 0.05f);
//         lightingShader.setVec3("pointLights[0].diffuse", 0.8f, 0.8f, 0.8f);
//         lightingShader.setVec3("pointLights[0].specular", 1.0f, 1.0f, 1.0f);
//         lightingShader.setFloat("pointLights[0].constant", 1.0f);
//         lightingShader.setFloat("pointLights[0].linear", 0.09f);
//         lightingShader.setFloat("pointLights[0].quadratic", 0.032f);
//         // point light 2
//         lightingShader.setVec3("pointLights[1].position", pointLightPositions[1]);
//         lightingShader.setVec3("pointLights[1].ambient", 0.05f, 0.05f, 0.05f);
//         lightingShader.setVec3("pointLights[1].diffuse", 0.8f, 0.8f, 0.8f);
//         lightingShader.setVec3("pointLights[1].specular", 1.0f, 1.0f, 1.0f);
//         lightingShader.setFloat("pointLights[1].constant", 1.0f);
//         lightingShader.setFloat("pointLights[1].linear", 0.09f);
//         lightingShader.setFloat("pointLights[1].quadratic", 0.032f);
//         // point light 3
//         lightingShader.setVec3("pointLights[2].position", pointLightPositions[2]);
//         lightingShader.setVec3("pointLights[2].ambient", 0.05f, 0.05f, 0.05f);
//         lightingShader.setVec3("pointLights[2].diffuse", 0.8f, 0.8f, 0.8f);
//         lightingShader.setVec3("pointLights[2].specular", 1.0f, 1.0f, 1.0f);
//         lightingShader.setFloat("pointLights[2].constant", 1.0f);
//         lightingShader.setFloat("pointLights[2].linear", 0.09f);
//         lightingShader.setFloat("pointLights[2].quadratic", 0.032f);
//         // point light 4
//         lightingShader.setVec3("pointLights[3].position", pointLightPositions[3]);
//         lightingShader.setVec3("pointLights[3].ambient", 0.05f, 0.05f, 0.05f);
//         lightingShader.setVec3("pointLights[3].diffuse", 0.8f, 0.8f, 0.8f);
//         lightingShader.setVec3("pointLights[3].specular", 1.0f, 1.0f, 1.0f);
//         lightingShader.setFloat("pointLights[3].constant", 1.0f);
//         lightingShader.setFloat("pointLights[3].linear", 0.09f);
//         lightingShader.setFloat("pointLights[3].quadratic", 0.032f);
//         // spotLight
//         lightingShader.setVec3("spotLight.position", camera.Position);
//         lightingShader.setVec3("spotLight.direction", camera.Front);
//         lightingShader.setVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
//         lightingShader.setVec3("spotLight.diffuse", 1.0f, 1.0f, 1.0f);
//         lightingShader.setVec3("spotLight.specular", 1.0f, 1.0f, 1.0f);
//         lightingShader.setFloat("spotLight.constant", 1.0f);
//         lightingShader.setFloat("spotLight.linear", 0.09f);
//         lightingShader.setFloat("spotLight.quadratic", 0.032f);
//         lightingShader.setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
//         lightingShader.setFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));

//         // view/projection transformations
//         glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//         glm::mat4 view = camera.GetViewMatrix();
//         lightingShader.setMat4("projection", projection);
//         lightingShader.setMat4("view", view);

//         // world transformation
//         glm::mat4 model = glm::mat4(1.0f);
//         lightingShader.setMat4("model", model);

//         // bind diffuse ma
//         // render containers
//         glBindVertexArray(cubeVAO);
//         glDrawArrays(GL_TRIANGLES, 0, sizeof(breacerVertices) / sizeof(float));

//          // also draw the lamp object(s)
//          lightCubeShader.use();
//          lightCubeShader.setMat4("projection", projection);
//          lightCubeShader.setMat4("view", view);

//          // we now draw as many light bulbs as we have point lights.
//          glBindVertexArray(lightCubeVAO);
//          for (unsigned int i = 0; i < 4; i++)
//          {
//              model = glm::mat4(1.0f);
//              model = glm::translate(model, pointLightPositions[i]);
//              model = glm::scale(model, glm::vec3(0.2f)); // Make it a smaller cube
//              lightCubeShader.setMat4("model", model);
//              glDrawArrays(GL_TRIANGLES, 0, 36);
//          }

//         // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//         // -------------------------------------------------------------------------------
//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     }

//     // optional: de-allocate all resources once they've outlived their purpose:
//     // ------------------------------------------------------------------------
//     glDeleteVertexArrays(1, &cubeVAO);
//     glDeleteVertexArrays(1, &lightCubeVAO);
//     glDeleteBuffers(1, &VBO);

//     // glfw: terminate, clearing all previously allocated GLFW resources.
//     // ------------------------------------------------------------------
//     glfwTerminate();
//     return 0;
// }

// // process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// // ---------------------------------------------------------------------------------------------------------
// void processInput(GLFWwindow *window)
// {
//     if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//         glfwSetWindowShouldClose(window, true);

//     if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//         camera.ProcessKeyboard(FORWARD, deltaTime);
//     if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//         camera.ProcessKeyboard(BACKWARD, deltaTime);
//     if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//         camera.ProcessKeyboard(LEFT, deltaTime);
//     if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//         camera.ProcessKeyboard(RIGHT, deltaTime);
// }

// // glfw: whenever the window size changed (by OS or user resize) this callback function executes
// // ---------------------------------------------------------------------------------------------
// void framebuffer_size_callback(GLFWwindow* window, int width, int height)
// {
//     // make sure the viewport matches the new window dimensions; note that width and
//     // height will be significantly larger than specified on retina displays.
//     glViewport(0, 0, width, height);
// }

// // glfw: whenever the mouse moves, this callback is called
// // -------------------------------------------------------
// void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
// {
//     float xpos = static_cast<float>(xposIn);
//     float ypos = static_cast<float>(yposIn);

//     if (firstMouse)
//     {
//         lastX = xpos;
//         lastY = ypos;
//         firstMouse = false;
//     }

//     float xoffset = xpos - lastX;
//     float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

//     lastX = xpos;
//     lastY = ypos;

//     camera.ProcessMouseMovement(xoffset, yoffset);
// }

// // glfw: whenever the mouse scroll wheel scrolls, this callback is called
// // ----------------------------------------------------------------------
// void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
// {
//     camera.ProcessMouseScroll(static_cast<float>(yoffset));
// }

// // utility function for loading a 2D texture from file
// // ---------------------------------------------------
// unsigned int loadTexture(char const * path)
// {
//     unsigned int textureID;
//     glGenTextures(1, &textureID);

//     int width, height, nrComponents;
//     unsigned char *data = stbi_load(path, &width, &height, &nrComponents, 0);
//     if (data)
//     {
//         GLenum format;
//         if (nrComponents == 1)
//             format = GL_RED;
//         else if (nrComponents == 3)
//             format = GL_RGB;
//         else if (nrComponents == 4)
//             format = GL_RGBA;

//         glBindTexture(GL_TEXTURE_2D, textureID);
//         glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
//         glGenerateMipmap(GL_TEXTURE_2D);

//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

//         stbi_image_free(data);
//     }
//     else
//     {
//         std::cout << "Texture failed to load at path: " << path << std::endl;
//         stbi_image_free(data);
//     }

//     return textureID;
// }

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include "shader.h"
#include "camera.h"
#include "shape.cpp"

#include <iostream>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void mouse_callback(GLFWwindow *window, double xpos, double ypos);
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);
void processInput(GLFWwindow *window);
unsigned int loadCubemap(vector<std::string> faces);
// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;

// lighting
glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
unsigned int loadTexture(const char *path);
int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef APPLE
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

    // build and compile our shader zprogram
    // ------------------------------------
    Shader lightingShader("D:\\opengl-cpp-template-master\\opengl-cpp-template-master\\src\\phong.vs", "D:\\opengl-cpp-template-master\\opengl-cpp-template-master\\src\\phong.fs");
    Shader lightCubeShader("D:\\opengl-cpp-template-master\\opengl-cpp-template-master\\src\\lightsrc.vs", "D:\\opengl-cpp-template-master\\opengl-cpp-template-master\\src\\lightsrc.fs");
    Shader firoozeh("D:\\opengl-cpp-template-master\\opengl-cpp-template-master\\src\\firooz.vs", "D:\\opengl-cpp-template-master\\opengl-cpp-template-master\\src\\firooz.fs");
    Shader skyboxShader("D:\\opengl-cpp-template-master\\opengl-cpp-template-master\\src\\sky.vs", "D:\\opengl-cpp-template-master\\opengl-cpp-template-master\\src\\sky.fs");
    Shader gem("D:\\opengl-cpp-template-master\\opengl-cpp-template-master\\src\\Gem.vs", "D:\\opengl-cpp-template-master\\opengl-cpp-template-master\\src\\Gem.fs");
    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    const int sides = 8;
    const float height = 0.2f;
    const float radius = 1.0f;
    float breacerVertices[6 * sides * 6];
    int index = 0;

    for (int i = 0; i < sides; ++i)
    {
        float theta1 = (2 * glm::pi<float>() * (i - 0.5f)) / sides;
        float theta2 = (2 * glm::pi<float>() * (i + 0.5f)) / sides;
        float theta3 = (2 * glm::pi<float>() * (i + 0.0f)) / sides;
        float theta4 = (2 * glm::pi<float>() * (i + 1.0f)) / sides;

        glm::vec3 normal1(cos(theta1), height / 2, sin(theta1));
        glm::vec3 normal2(cos(theta2), height / 2, sin(theta2));
        glm::vec3 normal3(cos(theta3), -height / 2, sin(theta3));
        glm::vec3 normal4(cos(theta4), -height / 2, sin(theta4));

        // Quad vertices and normals
        breacerVertices[index++] = radius * cos(theta3);
        breacerVertices[index++] = -height / 2;
        breacerVertices[index++] = radius * sin(theta3);
        breacerVertices[index++] = normal3.x;
        breacerVertices[index++] = normal3.y;
        breacerVertices[index++] = normal3.z;

        breacerVertices[index++] = radius * cos(theta1);
        breacerVertices[index++] = height / 2;
        breacerVertices[index++] = radius * sin(theta1);
        breacerVertices[index++] = normal1.x;
        breacerVertices[index++] = normal1.y;
        breacerVertices[index++] = normal1.z;

        breacerVertices[index++] = radius * cos(theta2);
        breacerVertices[index++] = height / 2;
        breacerVertices[index++] = radius * sin(theta2);
        breacerVertices[index++] = normal2.x;
        breacerVertices[index++] = normal2.y;
        breacerVertices[index++] = normal2.z;

        breacerVertices[index++] = radius * cos(theta4);
        breacerVertices[index++] = -height / 2;
        breacerVertices[index++] = radius * sin(theta4);
        breacerVertices[index++] = normal4.x;
        breacerVertices[index++] = normal4.y;
        breacerVertices[index++] = normal4.z;

        breacerVertices[index++] = radius * cos(theta3);
        breacerVertices[index++] = -height / 2;
        breacerVertices[index++] = radius * sin(theta3);
        breacerVertices[index++] = normal3.x;
        breacerVertices[index++] = normal3.y;
        breacerVertices[index++] = normal3.z;

        breacerVertices[index++] = radius * cos(theta2);
        breacerVertices[index++] = height / 2;
        breacerVertices[index++] = radius * sin(theta2);
        breacerVertices[index++] = normal2.x;
        breacerVertices[index++] = normal2.y;
        breacerVertices[index++] = normal2.z;
    }
    float skyboxVertices[] = {
        // positions
        -1.0f, 1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f, 1.0f, -1.0f,
        -1.0f, 1.0f, -1.0f,

        -1.0f, -1.0f, 1.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f, 1.0f, -1.0f,
        -1.0f, 1.0f, -1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f, -1.0f, 1.0f,

        1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,

        -1.0f, -1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, -1.0f, 1.0f,
        -1.0f, -1.0f, 1.0f,

        -1.0f, 1.0f, -1.0f,
        1.0f, 1.0f, -1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, -1.0f,

        -1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f, 1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f, 1.0f,
        1.0f, -1.0f, 1.0f};
    unsigned int skyboxVAO, skyboxVBO;
    glGenVertexArrays(1, &skyboxVAO);
    glGenBuffers(1, &skyboxVBO);
    glBindVertexArray(skyboxVAO);
    glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    float vraf[] = {
        -0.1f, -0.1f, -0.04f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
        0.1f, -0.1f, -0.04f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f,
        0.1f, 0.1f, -0.04f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,
        0.1f, 0.1f, -0.04f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,
        -0.1f, 0.1f, -0.04f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f,
        -0.1f, -0.1f, -0.04f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,

        -0.07f, -0.07f, 0.1f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.07f, -0.07f, 0.1f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
        0.07f, 0.07f, 0.1f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
        0.07f, 0.07f, 0.1f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
        -0.07f, 0.07f, 0.1f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
        -0.07f, -0.07f, 0.1f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,

        -0.07f, 0.07f, 0.1f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        -0.1f, 0.1f, -0.04f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
        -0.1f, -0.1f, -0.04f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        -0.1f, -0.1f, -0.04f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        -0.07f, -0.07f, 0.1f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        -0.07f, 0.07f, 0.1f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,

        0.07f, 0.07f, 0.1f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.1f, 0.1f, -0.04f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.1f, -0.1f, -0.04f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        0.1f, -0.1f, -0.04f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        0.07f, -0.07f, 0.1f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        0.07f, 0.07f, 0.1f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,

        -0.1f, -0.1f, -0.04f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,
        0.1f, -0.1f, -0.04f, 0.0f, -1.0f, 0.0f, 1.0f, 1.0f,
        0.07f, -0.07f, 0.1f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
        0.07f, -0.07f, 0.1f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
        -0.07f, -0.07f, 0.1f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f,
        -0.1f, -0.1f, -0.04f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,

        -0.1f, 0.1f, -0.04f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        0.1f, 0.1f, -0.04f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
        0.07f, 0.07f, 0.1f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
        0.07f, 0.07f, 0.1f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
        -0.07f, 0.07f, 0.1f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
        -0.1f, 0.1f, -0.04f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f};
    float vra[] = {
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
        0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
        0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
        0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,

        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
        0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,

        -0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, 0.5f, -1.0f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f,

        0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,

        -0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,
        0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,

        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f};
    vector<std::string> faces{
        "D:\\opengl-cpp-template-master\\opengl-cpp-template-master\\src\\posx.jpg",
        "D:\\opengl-cpp-template-master\\opengl-cpp-template-master\\src\\negx.jpg",
        "D:\\opengl-cpp-template-master\\opengl-cpp-template-master\\src\\posy.jpg",
        "D:\\opengl-cpp-template-master\\opengl-cpp-template-master\\src\\negy.jpg",
        "D:\\opengl-cpp-template-master\\opengl-cpp-template-master\\src\\posz.jpg",
        "D:\\opengl-cpp-template-master\\opengl-cpp-template-master\\src\\negz.jpg"};
    unsigned int cubemapTexture = loadCubemap(faces);

    unsigned int VBOD, VAOD, FIROOZB, FIROOZA;
    glGenVertexArrays(1, &VAOD);
    glGenBuffers(1, &VBOD);

    glBindBuffer(GL_ARRAY_BUFFER, VBOD);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vra), vra, GL_STATIC_DRAW);

    glBindVertexArray(VAOD);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    // normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // firooz
    glGenVertexArrays(1, &FIROOZA);
    glGenBuffers(1, &FIROOZB);

    glBindBuffer(GL_ARRAY_BUFFER, FIROOZB);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vra), vra, GL_STATIC_DRAW);

    glBindVertexArray(FIROOZA);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    // normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
    glm::vec3 pointLightPositions[] = {
        glm::vec3(0.7f, 0.2f, 2.0f),
        glm::vec3(2.3f, -3.3f, -4.0f),
        glm::vec3(-4.0f, 2.0f, -12.0f),
        glm::vec3(0.0f, 0.0f, -3.0f)};
    // first, configure the cube's VAO (and VBO)
    unsigned int VBO, cubeVAO;
    glGenVertexArrays(1, &cubeVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(breacerVertices), breacerVertices, GL_STATIC_DRAW);

    glBindVertexArray(cubeVAO);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    // normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // second, configure the light's VAO (VBO stays the same; the vertices are the same for the light object which is also a 3D cube)
    unsigned int lightCubeVAO;
    glGenVertexArrays(1, &lightCubeVAO);
    glBindVertexArray(lightCubeVAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // note that we update the lamp's position attribute's stride to reflect the updated buffer data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // firroz texture
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    skyboxShader.use();
    skyboxShader.setInt("skybox", 0);
    firoozeh.use();
    firoozeh.setInt("material.diffuse", 0);
    firoozeh.setInt("material.specular", 1);

    unsigned int diffuseMap = loadTexture("D:\\opengl-cpp-template-master\\opengl-cpp-template-master\\src\\container2 copy.jpg");
    unsigned int specularMap = loadTexture("D:\\opengl-cpp-template-master\\opengl-cpp-template-master\\src\\container2 copy.jpg");
    // render loop
    lightingShader.use();
    lightingShader.setInt("skybox", 0);
    gem.use();
    gem.setInt("skybox", 0);
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // per-frame time logic
        // --------------------
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // be sure to activate shader when setting uniforms/drawing objects
        lightingShader.use();
        lightingShader.setVec3("light.position", lightPos);
        lightingShader.setVec3("viewPos", camera.Position);

        // light properties
        glm::vec3 lightColor;
        lightColor.x = static_cast<float>(sin(glfwGetTime() * 2.0));
        lightColor.y = static_cast<float>(sin(glfwGetTime() * 0.7));
        lightColor.z = static_cast<float>(sin(glfwGetTime() * 1.3));
        glm::vec3 diffuseColor = lightColor * glm::vec3(0.5f);   // decrease the influence
        glm::vec3 ambientColor = diffuseColor * glm::vec3(0.2f); // low influence
        // lightingShader.setVec3("light.ambient", ambientColor);
        // lightingShader.setVec3("light.diffuse", diffuseColor);
        // lightingShader.setVec3("light.specular", 1.0f, 1.0f, 1.0f);

        // material properties of gold
        lightingShader.setVec3("material.ambient", 0.24725f, 0.1995f, 0.0745f);
        lightingShader.setVec3("material.diffuse", 0.75164f, 0.60648f, 0.22648f);
        lightingShader.setVec3("material.specular", 0.628281f, 0.555802f, 0.366065f); // specular lighting doesn't have full effect on this object's material
        lightingShader.setFloat("material.shininess", 0.4f);
        lightingShader.setFloat("material.reflectivity", 0.5f);
        // light
        lightingShader.setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
        lightingShader.setVec3("dirLight.ambient", 0.05f, 0.05f, 0.05f);
        lightingShader.setVec3("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
        lightingShader.setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);

        // point light 1
        lightingShader.setVec3("pointLights[0].position", pointLightPositions[0]);
        lightingShader.setVec3("pointLights[0].ambient", 0.05f, 0.05f, 0.05f);
        lightingShader.setVec3("pointLights[0].diffuse", 0.8f, 0.8f, 0.8f);
        lightingShader.setVec3("pointLights[0].specular", 1.0f, 1.0f, 1.0f);
        lightingShader.setFloat("pointLights[0].constant", 1.0f);
        lightingShader.setFloat("pointLights[0].linear", 0.09f);
        lightingShader.setFloat("pointLights[0].quadratic", 0.032f);
        // point light 2
        lightingShader.setVec3("pointLights[1].position", pointLightPositions[1]);
        lightingShader.setVec3("pointLights[1].ambient", 0.05f, 0.05f, 0.05f);
        lightingShader.setVec3("pointLights[1].diffuse", 0.8f, 0.8f, 0.8f);
        lightingShader.setVec3("pointLights[1].specular", 1.0f, 1.0f, 1.0f);
        lightingShader.setFloat("pointLights[1].constant", 1.0f);
        lightingShader.setFloat("pointLights[1].linear", 0.09f);
        lightingShader.setFloat("pointLights[1].quadratic", 0.032f);
        // point light 3
        lightingShader.setVec3("pointLights[2].position", pointLightPositions[2]);
        lightingShader.setVec3("pointLights[2].ambient", 0.05f, 0.05f, 0.05f);
        lightingShader.setVec3("pointLights[2].diffuse", 0.8f, 0.8f, 0.8f);
        lightingShader.setVec3("pointLights[2].specular", 1.0f, 1.0f, 1.0f);
        lightingShader.setFloat("pointLights[2].constant", 1.0f);
        lightingShader.setFloat("pointLights[2].linear", 0.09f);
        lightingShader.setFloat("pointLights[2].quadratic", 0.032f);
        // point light 4
        lightingShader.setVec3("pointLights[3].position", pointLightPositions[3]);
        lightingShader.setVec3("pointLights[3].ambient", 0.05f, 0.05f, 0.05f);
        lightingShader.setVec3("pointLights[3].diffuse", 0.8f, 0.8f, 0.8f);
        lightingShader.setVec3("pointLights[3].specular", 1.0f, 1.0f, 1.0f);
        lightingShader.setFloat("pointLights[3].constant", 1.0f);
        lightingShader.setFloat("pointLights[3].linear", 0.09f);
        lightingShader.setFloat("pointLights[3].quadratic", 0.032f);
        // spotLight
        lightingShader.setVec3("spotLight.position", camera.Position);
        lightingShader.setVec3("spotLight.direction", camera.Front);
        lightingShader.setVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
        lightingShader.setVec3("spotLight.diffuse", 1.0f, 1.0f, 1.0f);
        lightingShader.setVec3("spotLight.specular", 1.0f, 1.0f, 1.0f);
        lightingShader.setFloat("spotLight.constant", 1.0f);
        lightingShader.setFloat("spotLight.linear", 0.09f);
        lightingShader.setFloat("spotLight.quadratic", 0.032f);
        lightingShader.setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
        lightingShader.setFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));

        // view/projection transformations
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        glm::mat4 view = camera.GetViewMatrix();
        lightingShader.setMat4("projection", projection);
        lightingShader.setMat4("view", view);

        // world transformation
        glm::mat4 model = glm::mat4(1.0f);
        lightingShader.setMat4("model", model);

        // render the cube
        glBindVertexArray(cubeVAO);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
        glDrawArrays(GL_TRIANGLES, 0, sizeof(breacerVertices) / sizeof(float));
        glBindVertexArray(0);
   
        // emer
        gem.use();
        gem.setVec3("light.position", lightPos);
        gem.setVec3("viewPos", camera.Position);
        gem.setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
        gem.setVec3("dirLight.ambient", 0.05f, 0.05f, 0.05f);
        gem.setVec3("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
        gem.setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);

        // point light 1
        gem.setVec3("pointLights[0].position", pointLightPositions[0]);
        gem.setVec3("pointLights[0].ambient", 0.05f, 0.05f, 0.05f);
        gem.setVec3("pointLights[0].diffuse", 0.8f, 0.8f, 0.8f);
        gem.setVec3("pointLights[0].specular", 1.0f, 1.0f, 1.0f);
        gem.setFloat("pointLights[0].constant", 1.0f);
        gem.setFloat("pointLights[0].linear", 0.09f);
        gem.setFloat("pointLights[0].quadratic", 0.032f);
        // point light 2
        gem.setVec3("pointLights[1].position", pointLightPositions[1]);
        gem.setVec3("pointLights[1].ambient", 0.05f, 0.05f, 0.05f);
        gem.setVec3("pointLights[1].diffuse", 0.8f, 0.8f, 0.8f);
        gem.setVec3("pointLights[1].specular", 1.0f, 1.0f, 1.0f);
        gem.setFloat("pointLights[1].constant", 1.0f);
        gem.setFloat("pointLights[1].linear", 0.09f);
        gem.setFloat("pointLights[1].quadratic", 0.032f);
        // point light 3
        gem.setVec3("pointLights[2].position", pointLightPositions[2]);
        gem.setVec3("pointLights[2].ambient", 0.05f, 0.05f, 0.05f);
        gem.setVec3("pointLights[2].diffuse", 0.8f, 0.8f, 0.8f);
        gem.setVec3("pointLights[2].specular", 1.0f, 1.0f, 1.0f);
        gem.setFloat("pointLights[2].constant", 1.0f);
        gem.setFloat("pointLights[2].linear", 0.09f);
        gem.setFloat("pointLights[2].quadratic", 0.032f);
        // point light 4
        gem.setVec3("pointLights[3].position", pointLightPositions[3]);
        gem.setVec3("pointLights[3].ambient", 0.05f, 0.05f, 0.05f);
        gem.setVec3("pointLights[3].diffuse", 0.8f, 0.8f, 0.8f);
        gem.setVec3("pointLights[3].specular", 1.0f, 1.0f, 1.0f);
        gem.setFloat("pointLights[3].constant", 1.0f);
        gem.setFloat("pointLights[3].linear", 0.09f);
        gem.setFloat("pointLights[3].quadratic", 0.032f);
        // spotLight
        gem.setVec3("spotLight.position", camera.Position);
        gem.setVec3("spotLight.direction", camera.Front);
        gem.setVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
        gem.setVec3("spotLight.diffuse", 1.0f, 1.0f, 1.0f);
        gem.setVec3("spotLight.specular", 1.0f, 1.0f, 1.0f);
        gem.setFloat("spotLight.constant", 1.0f);
        gem.setFloat("spotLight.linear", 0.09f);
        gem.setFloat("spotLight.quadratic", 0.032f);
        gem.setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
        gem.setFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));
          gem.setMat4("projection", projection);
        gem.setMat4("view", view);
        //rubby
        gem.setVec3("material.ambient", 0.0215f, 0.1745f, 0.0215f);
        gem.setVec3("material.diffuse", 0.07568f, 0.61424f, 0.07568f);
        gem.setVec3("material.specular", 0.633f, 0.727811f, 0.633f); // specular lighting doesn't have full effect on this object's material
        gem.setFloat("material.shininess", 0.6f);
        gem.setFloat("material.refraction", 1.309f);
        model = glm::scale(model, glm::vec3(0.12f, 0.12f, 0.12f));
        model = glm::translate(model, glm::vec3(0.6f, 0.0f, 8.4f));
     
        gem.setMat4("model", model);
        glBindVertexArray(VAOD);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
        glDrawArrays(GL_TRIANGLES, 0, sizeof(vra) / sizeof(float));
        glBindVertexArray(0);
        // RUBY
        gem.setVec3("material.ambient", 0.1745f, 0.01175f, 0.01175f);
        gem.setVec3("material.diffuse", 0.61424f, 0.04136f, 0.04136f);
        gem.setVec3("material.specular", 0.727811f, 0.626959f, 0.626959f); // specular lighting doesn't have full effect on this object's material
        gem.setFloat("material.shininess", 0.6f);
        gem.setFloat("material.refraction", 1.309f);
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, -16.8f));
        gem.setMat4("model", model);
        glBindVertexArray(VAOD);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
        glDrawArrays(GL_TRIANGLES, 0, sizeof(vra) / sizeof(float));
        glBindVertexArray(0);

        // berillaint
        gem.setVec3("material.ambient",0.0f,0.0f,0.0f);
        gem.setVec3("material.diffuse",0.0f,0.0f,0.0f);
        gem.setVec3("material.specular", 0.0f, 0.0, 0.0f); // specular lighting doesn't have full effect on this object's material
        gem.setFloat("material.shininess", 0.1f);
        gem.setFloat("material.refraction", 1.52f);
        model = glm::translate(model, glm::vec3(7.8f, 0.0f, 8.4f));
        gem.setMat4("model", model);
        glBindVertexArray(VAOD);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
        glDrawArrays(GL_TRIANGLES, 0, sizeof(vra) / sizeof(float));
        glBindVertexArray(0);
        // turquoise
        firoozeh.use();
        firoozeh.setVec3("material.ambient", 0.24725f, 0.1995f, 0.0745f);
        firoozeh.setVec3("material.diffuse", 0.75164f, 0.60648f, 0.22648f);
        firoozeh.setVec3("material.specular", 0.628281f, 0.555802f, 0.366065f); // specular lighting doesn't have full effect on this object's material
        firoozeh.setFloat("material.shininess", 0.4f);

        // light
        firoozeh.setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
        firoozeh.setVec3("dirLight.ambient", 0.05f, 0.05f, 0.05f);
        firoozeh.setVec3("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
        firoozeh.setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);
        // point light 1
        firoozeh.setVec3("pointLights[0].position", pointLightPositions[0]);
        firoozeh.setVec3("pointLights[0].ambient", 0.05f, 0.05f, 0.05f);
        firoozeh.setVec3("pointLights[0].diffuse", 0.8f, 0.8f, 0.8f);
        firoozeh.setVec3("pointLights[0].specular", 1.0f, 1.0f, 1.0f);
        firoozeh.setFloat("pointLights[0].constant", 1.0f);
        firoozeh.setFloat("pointLights[0].linear", 0.09f);
        firoozeh.setFloat("pointLights[0].quadratic", 0.032f);
        // point light 2
        firoozeh.setVec3("pointLights[1].position", pointLightPositions[1]);
        firoozeh.setVec3("pointLights[1].ambient", 0.05f, 0.05f, 0.05f);
        firoozeh.setVec3("pointLights[1].diffuse", 0.8f, 0.8f, 0.8f);
        firoozeh.setVec3("pointLights[1].specular", 1.0f, 1.0f, 1.0f);
        firoozeh.setFloat("pointLights[1].constant", 1.0f);
        firoozeh.setFloat("pointLights[1].linear", 0.09f);
        firoozeh.setFloat("pointLights[1].quadratic", 0.032f);
        // point light 3
        firoozeh.setVec3("pointLights[2].position", pointLightPositions[2]);
        firoozeh.setVec3("pointLights[2].ambient", 0.05f, 0.05f, 0.05f);
        firoozeh.setVec3("pointLights[2].diffuse", 0.8f, 0.8f, 0.8f);
        firoozeh.setVec3("pointLights[2].specular", 1.0f, 1.0f, 1.0f);
        firoozeh.setFloat("pointLights[2].constant", 1.0f);
        firoozeh.setFloat("pointLights[2].linear", 0.09f);
        firoozeh.setFloat("pointLights[2].quadratic", 0.032f);
        // point light 4
        firoozeh.setVec3("pointLights[3].position", pointLightPositions[3]);
        firoozeh.setVec3("pointLights[3].ambient", 0.05f, 0.05f, 0.05f);
        firoozeh.setVec3("pointLights[3].diffuse", 0.8f, 0.8f, 0.8f);
        firoozeh.setVec3("pointLights[3].specular", 1.0f, 1.0f, 1.0f);
        firoozeh.setFloat("pointLights[3].constant", 1.0f);
        firoozeh.setFloat("pointLights[3].linear", 0.09f);
        firoozeh.setFloat("pointLights[3].quadratic", 0.032f);
        // spotLight
        firoozeh.setVec3("spotLight.position", camera.Position);
        firoozeh.setVec3("spotLight.direction", camera.Front);
        firoozeh.setVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
        firoozeh.setVec3("spotLight.diffuse", 1.0f, 1.0f, 1.0f);
        firoozeh.setVec3("spotLight.specular", 1.0f, 1.0f, 1.0f);
        firoozeh.setFloat("spotLight.constant", 1.0f);
        firoozeh.setFloat("spotLight.linear", 0.09f);
        firoozeh.setFloat("spotLight.quadratic", 0.032f);
        firoozeh.setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
        firoozeh.setFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));
        firoozeh.setMat4("projection", projection);
        firoozeh.setMat4("view", view);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, diffuseMap);
        // bind specular map
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, specularMap);
        // firoozeh.setVec3("material.ambient", 0.1f, 0.18725f, 0.1745f);
        // glActiveTexture(GL_TEXTURE0);
        // glBindTexture(GL_TEXTURE_2D, texture);
        //  glActiveTexture(GL_TEXTURE1);
        // glBindTexture(GL_TEXTURE_2D, texture);
        // firoozeh.setInt("material.diffuse", 0);
        // firoozeh.setInt("material.specular", 1);
        // firoozeh.setFloat("material.shininess", 0.1f);
        model = glm::translate(model, glm::vec3(-16.8f, 0.0f, 0.0f));
        firoozeh.setMat4("model", model);

        glBindVertexArray(FIROOZA);
        glDrawArrays(GL_TRIANGLES, 0, sizeof(vraf) / sizeof(float));
        // also draw the lamp object
        glDepthFunc(GL_LEQUAL); // change depth function so depth test passes when values are equal to depth buffer's content
        skyboxShader.use();
        view = glm::mat4(glm::mat3(camera.GetViewMatrix())); // remove translation from the view matrix
        skyboxShader.setMat4("view", view);
        skyboxShader.setMat4("projection", projection);
        // skybox cube
        glBindVertexArray(skyboxVAO);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(0);
        glDepthFunc(GL_LESS);
        lightCubeShader.use();
        lightCubeShader.setMat4("projection", projection);
        lightCubeShader.setMat4("view", view);
        model = glm::mat4(1.0f);
        model = glm::translate(model, lightPos);
        model = glm::scale(model, glm::vec3(0.2f)); // a smaller cube
        lightCubeShader.setMat4("model", model);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &cubeVAO);
    glDeleteVertexArrays(1, &lightCubeVAO);
    glDeleteBuffers(1, &VBO);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow *window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(static_cast<float>(yoffset));
}
unsigned int loadTexture(char const *path)
{
    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char *data = stbi_load(path, &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}
unsigned int loadCubemap(vector<std::string> faces)
{
    unsigned int textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

    int width, height, nrComponents;
    for (unsigned int i = 0; i < faces.size(); i++)
    {
        unsigned char *data = stbi_load(faces[i].c_str(), &width, &height, &nrComponents, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            stbi_image_free(data);
        }
        else
        {
            std::cout << "Cubemap texture failed to load at path: " << faces[i] << std::endl;
            stbi_image_free(data);
        }
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    return textureID;
}