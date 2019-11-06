#include <GL/glut.h>
#include <math.h>

GLfloat angle, aspect;

void drawRobotBase(float cx, float cy, float radius) {
	glColor3f(0.7529f, 0.7529f, 0.7529f);
	float angle_step = 0.1;

	glBegin(GL_TRIANGLE_FAN);
		glNormal3f(0.0, -1.0, 0.0); 	
		for(float theta = -251.565; theta <= 71.565; theta += angle_step)
		{
			float rad_theta = 3.1415926f * theta / 180.0f;

			float x = radius * cosf(rad_theta);
			float y = radius * sinf(rad_theta);

			glVertex3f(x + cx, -40.0, y + cy);
		}
	glEnd();
}

void drawRobotSide(float cx, float cy, float radius) {
	glColor3f(0.0f, 0.0f, 0.0f);
	float angle_step = 0.1;
	float height = 150;
	float x_in, y_in, x, y;

	glBegin(GL_QUAD_STRIP);
		glNormal3f(1.0, 0.0, 0.0);
		x_in = radius * cosf(3.1415926f * -251.565 / 180.0f);
		y_in = radius * sinf(3.1415926f * -251.565 / 180.0f); 	
		for(float theta = -251.565; theta <= 71.565; theta += angle_step)
		{
			float rad_theta = 3.1415926f * theta / 180.0f;

			x = radius * cosf(rad_theta);
			y = radius * sinf(rad_theta);

			glVertex3f(x + cx, -40.0, y + cy);
			glVertex3f(x + cx, -40.0 + height, y + cy);
		}
	glEnd();

	glBegin(GL_POLYGON);
		glNormal3f(0.0, 0.0, 1.0);
		glVertex3f(x_in + cx, -40.0 + height, y_in + cy);
		glVertex3f(x + cx, -40.0 + height, y_in + cy);
		glVertex3f(x + cx, 10.0, y + cy);
		glVertex3f(x_in + cx, 10.0, y + cy);               
    glEnd();
}

void drawRobotTop(float cx, float cy, float radius) {
	glColor3f(0.0f, 0.0f, 0.0f);
	float angle_step = 0.1;
	float height = 150;

	glBegin(GL_TRIANGLE_FAN);
		glNormal3f(0.0, 1.0, 0.0); 	
		for(float theta = -251.565; theta <= 71.565; theta += angle_step)
		{
			float rad_theta = 3.1415926f * theta / 180.0f;

			float x = radius * cosf(rad_theta);
			float y = radius * sinf(rad_theta);

			glVertex3f(x + cx, -40.0 + height, y + cy);
		}
	glEnd();

	glColor3f(0.0f, 1.0f, 0.0f);

	glBegin(GL_TRIANGLE_FAN);
		glNormal3f(0.0, 1.0, 0.0); 	
		for(float theta = 0; theta <= 360; theta += angle_step)
		{
			float rad_theta = 3.1415926f * theta / 180.0f;

			float x = 20 * cosf(rad_theta);
			float y = 20 * sinf(rad_theta);

			glVertex3f(x + cx + 30, -40.0 + height + 1, y + cy + 55);
		}
	glEnd();

	glColor3f(0.9882f, 0.0588f, 0.7529f);

	glBegin(GL_TRIANGLE_FAN);
		glNormal3f(0.0, 1.0, 0.0); 	
		for(float theta = 0; theta <= 360; theta += angle_step)
		{
			float rad_theta = 3.1415926f * theta / 180.0f;

			float x = 20 * cosf(rad_theta);
			float y = 20 * sinf(rad_theta);

			glVertex3f(x + cx - 30, -40.0 + height + 1, y + cy + 55);
		}
	glEnd();

	glColor3f(0.0f, 1.0f, 0.0f);

	glBegin(GL_TRIANGLE_FAN);
		glNormal3f(0.0, 1.0, 0.0); 	
		for(float theta = 0; theta <= 360; theta += angle_step)
		{
			float rad_theta = 3.1415926f * theta / 180.0f;

			float x = 20 * cosf(rad_theta);
			float y = 20 * sinf(rad_theta);

			glVertex3f(x + cx + 45, -40.0 + height + 1, y + cy - 40);
		}
	glEnd();

	glColor3f(0.0f, 1.0f, 0.0f);

	glBegin(GL_TRIANGLE_FAN);
		glNormal3f(0.0, 1.0, 0.0); 	
		for(float theta = 0; theta <= 360; theta += angle_step)
		{
			float rad_theta = 3.1415926f * theta / 180.0f;

			float x = 20 * cosf(rad_theta);
			float y = 20 * sinf(rad_theta);

			glVertex3f(x + cx - 45, -40.0 + height + 1, y + cy - 40);
		}
	glEnd();

}
            
void draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	drawRobotBase(0, 0, 90);
	drawRobotSide(0, 0, 90);
	drawRobotTop(0, 0, 90);

	glutSwapBuffers();
}

void init(void)
{ 
	glShadeModel(GL_SMOOTH);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	GLfloat ambient_light[4]={0.2,0.2,0.2,1.0}; 
	GLfloat difuse_light[4]={0.7,0.7,0.7,1.0};
	GLfloat specular_light[4]={1.0, 1.0, 1.0, 1.0};
	GLfloat light_position[4]={0.0, 50.0, 50.0, 1.0};

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light); 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, difuse_light );
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light );
	glLightfv(GL_LIGHT0, GL_POSITION, light_position );

	GLfloat material_spec[4]={1.0,1.0,1.0,1.0}; 
	GLint material_shine = 60;

	glMaterialfv(GL_FRONT,GL_SPECULAR, material_spec);
	glMateriali(GL_FRONT,GL_SHININESS,material_shine);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_light);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);  
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	angle=70;
}

void setVisualizationParams(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(angle,aspect,0.4,500);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0,250,220, 0,35,0, 0,1,0);
}

void windowSizeHandler(GLsizei w, GLsizei h)
{
	if ( h == 0 ) h = 1;

	glViewport(0, 0, w, h);
 
	aspect = (GLfloat)w/(GLfloat)h;

	setVisualizationParams();
}

// Função callback chamada para gerenciar eventos do mouse
void mouseHandler(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) { 
			if (angle >= 10) angle -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) { 
			if (angle <= 130) angle += 5;
		}

	setVisualizationParams();
	glutPostRedisplay();
}

// Programa Principal
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400,350);
	glutCreateWindow("Visualizacao 3D");
	glutDisplayFunc(draw);
	glutReshapeFunc(windowSizeHandler);
	glutMouseFunc(mouseHandler);
	init();
	glutMainLoop();
}