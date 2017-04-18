#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(void)
{
	GLFWwindow *window;

	// Initialize the library
	if (!glfwInit())
	{
		return -1;
	}

	// Create a windowed mode window and its OpenGL context
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	// Make the window's context current
	glfwMakeContextCurrent(window);

	glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT); // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
	glMatrixMode(GL_PROJECTION); // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
	glLoadIdentity(); // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1); // essentially set coordinate system
	glMatrixMode(GL_MODELVIEW); // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
	glLoadIdentity(); // same as above comment

	GLfloat polygonVertices[] =
	{
		0, 200, 0,
		106, 320, 0,
		160, 200, 0,
		148, 340, 0,
		160, 345, 0,
		160, 200, 0,
		172, 340, 0,
		212, 320, 0,
		160, 200, 0,
		320, 200, 0,
		320, 200, 0,
		426, 320, 0,
		480, 200, 0,
		468, 340, 0,
		480, 345, 0,
		480, 200, 0,
		492, 340, 0,
		532, 320, 0,
		480, 200, 0,
		640, 200, 0,
	};
	GLfloat polygonVertices2[] =
	{
		0, 0, 0,
		106, 120, 0,
		160, 0, 0,
	};

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Loop until the user closes the window
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		// render OpenGL here
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, polygonVertices);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 20);
		glVertexPointer(3, GL_FLOAT, 0, polygonVertices2);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 3);
		glDisableClientState(GL_VERTEX_ARRAY);

		// Swap front and back buffers
		glfwSwapBuffers(window);

		// Poll for and process events
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}