#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

void drawMountain() {
//	glColor3f(0, 0.796875f, 0.59765625f);
	glColor3f(0.6f, 0.2f, 0);

	GLfloat mountainVertices[] =
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
	glVertexPointer(3, GL_FLOAT, 0, mountainVertices);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 20);

}

void drawRoad() {
	glColor3f(0.3984375f, 0.3984375f, 0.59765625f);

	GLfloat roadVertices[] =
	{
		325, 200, 0,
		315,200,0,
		340, 0, 0,
		200, 0, 0,
	};
	glVertexPointer(3, GL_FLOAT, 0, roadVertices);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

void drawWood() {
	glColor3f(0.3984375f, 0.1992f, 0);

	GLfloat woodVertices[] =
	{
		530,0,0,
		512,60,0,
		520,80,0,
		440,100,0,
		460,105,0,
		520,80,0,
		520,80,0,
		600,105,0,
		605,100,0,
		540,65,0,
		520,80,0,
		560,0,0,
		530,0,0
	};
	glVertexPointer(3, GL_FLOAT, 0, woodVertices);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 13);
}

void drawLeaf() {
	glColor3f(0, 0.796875f, 0);
	GLfloat leftleafVertices[] =
	{
		440,80,0,
		420,60,0,
		440,150,0,
		400,80,0,
		370,70,0,
		440,150,0,
		380,75,0,
		360,90,0,
		440,150,0,
		370,100,0,
		350,120,0,
		440,150,0,
		380,130,0,
		370,160,0,
		440,150,0,
		390,150,0,
		420,170,0,
		440,150,0,
		440,160,0,
		490,190,0, //20
		440,150,0,
		475,170,0,
		500,150,0,
		440,150,0,
		470,130,0,
		480,120,0,
		440,150,0,
		490,100,0,
		470,80,0,
		440,150,0, //30
		440,80,0,
	};

	GLfloat rightleafVertices[] =
	{
		580,105,0,
		620,160,0,
		630,120,0,
		640,150,0,
		640,80,0,
		630,120,0,
		620,90,0,
		600,70,0,
		630,120,0,
		600,105,0, //10
		580,105,0
	};

	glVertexPointer(3, GL_FLOAT, 0, leftleafVertices);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 31);
	glVertexPointer(3, GL_FLOAT, 0, rightleafVertices);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 11);
}

void drawSun(GLfloat x, GLfloat y, GLfloat radius) {
	int i;
	int triangleAmount = 20; //# of triangles used to draw circle

							 //GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * 3.141592;

	glColor3f(1.0f,1.0f,1.0f);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(x, y, 0); // center of circle

	glColor3f(1.0f, 1.0f, 0.0f);
	for (i = 0; i <= triangleAmount; i++) {
		glVertex3f(
			x + (radius * cos(i *  twicePi / triangleAmount)),
			y + (radius * sin(i * twicePi / triangleAmount)),
			0
			);
	}
	glEnd();
}

void drawRainbow(GLfloat x, GLfloat y, GLfloat radius, GLfloat width) {
	int i;
	int triangleAmount = 40; //# of triangles used to draw circle

							 //GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * 3.141592;



	for (int j = 5; j >= 0; j--) {
		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_TRIANGLE_FAN);
		glVertex3f(x, y, 0); // center of circle

		switch (j) {
		case(0) : glColor3f(1.0f, 0.0f, 1.0f); break;
		case(1) : glColor3f(0.0f, 0.0f, 1.0f); break;
		case(2) : glColor3f(0.0f, 1.0f, 1.0f); break;
		case(3) : glColor3f(0.0f, 1.0f, 0.0f); break;
		case(4) : glColor3f(1.0f, 1.0f, 0.0f); break;
		case(5) : glColor3f(1.0f, 0.0f, 0.0f); break;
		}

		for (i = 0; i <= triangleAmount; i++) {
			glVertex3f(
				x + ((radius - (6 - j)*(width / 6)) * cos(i *  twicePi / triangleAmount)),
				y + ((radius - (6 - j)*(width / 6)) * sin(i * twicePi / triangleAmount)),
				0
				);
		}
		glEnd();
	}

	glColor3f(0, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(x, y, 0); // center of circle
	for (i = 0; i <= triangleAmount; i++) {
		glColor3f(0.4, 1, 1);
		glVertex3f(
			x + ((radius-width) * cos(i *  twicePi / triangleAmount)),
			y + ((radius-width) * sin(i * twicePi / triangleAmount)),
			0
			);
	}
	glEnd();
}

void drawSky() {
	glColor3f(1, 1, 1);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(320, 240, 0); // center of circle
	glColor3f(0.4, 1, 1);
	glVertex3f(0, 200, 0);
	glVertex3f(0, 480, 0);
	glVertex3f(640, 480, 0);
	glVertex3f(640, 200, 0);

	glEnd();
}

void drawPlane() {
	glBegin(GL_QUADS);
	//red color
	glColor3f(1,1,0.796875f);
	glVertex3f(0,200,0);
	glVertex3f(640,200,0);
	//blue color
	glColor3f(1,1,0.3984375f);
	glVertex3f(640,0,0);
	glVertex3f(0,0,0);
	glEnd();
}



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

	 


	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Loop until the user closes the window
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		// render OpenGL here
		glEnableClientState(GL_VERTEX_ARRAY);
		drawSky();
		drawRainbow(320, 240, 200, 30);
		drawSun(320, 240, 100);
		drawPlane();
		drawWood();
		drawRoad();
		drawMountain();
		drawLeaf();
		glDisableClientState(GL_VERTEX_ARRAY);

		// Swap front and back buffers
		glfwSwapBuffers(window);

		// Poll for and process events
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}