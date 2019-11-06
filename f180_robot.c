#include <GL/glut.h>
#include <math.h>

GLfloat angle, aspect;
static int pitch = 0, roll = 0;

void drawWheel(float cx, float cy, float cz, float r1, float l1) {
	glColor3f(0.85f, 0.85f, 0.85f);
	float angle_step = 0.1;
	float s = l1>0?1.0:-1.0;

	glBegin(GL_TRIANGLE_FAN);
		glNormal3f(s, 0.0, 0.0); 	
		for(float theta = 0; theta <= 360; theta += angle_step)
		{
			float rad_theta = 3.1415926f * theta / 180.0f;

			float z = r1 * cosf(rad_theta);
			float y = r1 * sinf(rad_theta);

			glVertex3f(cx, cy + y, cz + z);
		}
	glEnd();
	
	glColor3f(0.4f, 0.4f, 0.4f);
	glBegin(GL_QUAD_STRIP);
		glNormal3f(0.0, 1.0, 0.0);
		for(float theta = 0; theta <= 360; theta += angle_step)
		{
			float rad_theta = 3.1415926f * theta / 180.0f;

			float z = r1 * cosf(rad_theta);
			float y = r1 * sinf(rad_theta);

			glVertex3f(cx, cy + y, cz + z);
			glVertex3f(cx + l1, cy + y, cz + z);
		}
	glEnd();	

	glColor3f(0.85f, 0.85f, 0.85f);
	glBegin(GL_TRIANGLE_FAN);
		glNormal3f(s, 0.0, 0.0); 	
		for(float theta = 0; theta <= 360; theta += angle_step)
		{
			float rad_theta = 3.1415926f * theta / 180.0f;

			float z = r1 * cosf(rad_theta);
			float y = r1 * sinf(rad_theta);

			glVertex3f(cx + l1, cy + y, cz + z);
		}
	glEnd();

	glColor3f(0.4f, 0.4f, 0.4f);
	glBegin(GL_TRIANGLE_FAN);
		glNormal3f(s, 0.0, 0.0); 	
		for(float theta = 0; theta <= 360; theta += angle_step)
		{
			float rad_theta = 3.1415926f * theta / 180.0f;

			float z = 5 * cosf(rad_theta);
			float y = 5 * sinf(rad_theta);

			glVertex3f(cx + l1 + s, cy + y, cz + z);
		}
	glEnd();
}

void drawRobotWheels(float angle1, float angle2) {
	float rad_angle1 = 3.1415926f * angle1 / 180.0f;
	float rad_angle2 = 3.1415926f * angle2 / 180.0f;
	float x1 = 88*cosf(rad_angle1);
	float z1 = 88*sinf(rad_angle1);
	float y  = -17.5;
	float x2 = 88*cosf(rad_angle2);
	float z2 = 88*sinf(rad_angle2);

	glPushMatrix();
	glTranslatef(x1, y, z1);
	glRotatef(-angle1, 0,1,0);
	glTranslatef(-x1, -y, -z1);
	drawWheel(x1, y, z1, 27.5, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-x1, y, z1);
	glRotatef(angle1, 0,1,0);
	glTranslatef(x1, -y, -z1);
	drawWheel(-x1, y, z1, 27.5, -10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x2, y, -z2);
	glRotatef(angle2, 0,1,0);
	glTranslatef(-x2, -y, z2);
	drawWheel(x2, y, -z2, 27.5, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-x2, y, -z2);
	glRotatef(-angle2, 0,1,0);
	glTranslatef(x2, -y, z2);
	drawWheel(-x2, y, -z2, 27.5, -10);
	glPopMatrix();
}

void drawRobotDribbler(float min_x, float min_y, float min_z, float radius, float lenght){
	glColor3f(1.0f, 1.0f, 0.0f);
	float angle_step = 0.1;

	glBegin(GL_TRIANGLE_FAN);
		glNormal3f(-1.0, 0.0, 0.0); 	
		for(float theta = 0; theta <= 360; theta += angle_step)
		{
			float rad_theta = 3.1415926f * theta / 180.0f;

			float z = radius * cosf(rad_theta);
			float y = radius * sinf(rad_theta);

			glVertex3f(min_x, min_y + y, min_z + z);
		}
	glEnd();
	
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_QUAD_STRIP);
		glNormal3f(0.0, 0.0, 1.0);
		for(float theta = 0; theta <= 360; theta += angle_step)
		{
			float rad_theta = 3.1415926f * theta / 180.0f;

			float z = radius * cosf(rad_theta);
			float y = radius * sinf(rad_theta);

			glVertex3f(min_x, min_y + y, min_z + z);
			glVertex3f(min_x + lenght, min_y + y, min_z + z);
		}
	glEnd();	

	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glNormal3f(1.0, 0.0, 0.0); 	
		for(float theta = 0; theta <= 360; theta += angle_step)
		{
			float rad_theta = 3.1415926f * theta / 180.0f;

			float z = radius * cosf(rad_theta);
			float y = radius * sinf(rad_theta);

			glVertex3f(min_x + lenght, min_y + y, min_z + z);
		}
	glEnd();

}


void drawRobotKick(float min_x, float min_y, float min_z, float max_x, float max_y, float max_z, float angle) {
	glColor3f(0.85f, 0.85f, 0.85f);

	glPushMatrix();
	glTranslatef(min_x, min_y, min_z);
	glRotatef(-angle, 1,0,0);
	glTranslatef(-min_x, -min_y, -min_z);

	glBegin(GL_POLYGON);
		glNormal3f(0.0, 0.0, 1.0);
		glVertex3f(min_x, min_y, min_z);
		glVertex3f(max_x, min_y, min_z);
		glVertex3f(max_x, max_y, max_z);
		glVertex3f(min_x, max_y, max_z);               
    glEnd();
	glPopMatrix();

}

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

	drawRobotKick(x_in + cx, -20.0, y_in + cy, x + cx, -45.0, y + cy, 30.0);

	drawRobotDribbler(x_in + cx, 0, y_in, 7, x + cy - x_in);
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

	glColor3f(1.0f, 1.0f, 0.0f);

	glBegin(GL_TRIANGLE_FAN);
		glNormal3f(0.0, 1.0, 0.0); 	
		for(float theta = 0; theta <= 360; theta += angle_step)
		{
			float rad_theta = 3.1415926f * theta / 180.0f;

			float x = 25 * cosf(rad_theta);
			float y = 25 * sinf(rad_theta);

			glVertex3f(x + cx, -40.0 + height + 1, y + cy);
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

			glVertex3f(x + cx + 50, -40.0 + height + 1, y + cy - 35);
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

			glVertex3f(x + cx - 50, -40.0 + height + 1, y + cy - 35);
		}
	glEnd();

}

void drawRobot()
{
	drawRobotBase(0, 0, 90);
	drawRobotSide(0, 0, 90);
	drawRobotTop(0, 0, 90);
	drawRobotWheels(37, 45);
}

void drawField(float w, float h)
{
	glColor3f(0.0f, 0.3922f, 0.0f);
	glBegin(GL_POLYGON);        
        glNormal3f(0.0, 1.0, 0.0);
        glVertex3f(w/2, -45.0, -h/2);
        glVertex3f(-w/2, -45.0, -h/2);
        glVertex3f(-w/2, -45.0, h/2);
        glVertex3f(w/2, -45.0, h/2);
    glEnd();

}
            
void draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	drawField(400, 400);

	glPushMatrix();
   	glTranslatef (0.0, 40.0, 0.0);
   	glRotatef ((GLfloat) pitch, 0.0, 1.0, 0.0);
	glRotatef ((GLfloat) roll, 1.0, 0.0, 0.0);
	glTranslatef (0.0, -40.0, 0.0);
	drawRobot();
	glPopMatrix();

	glutSwapBuffers();
}

void init(void)
{ 
	glShadeModel(GL_SMOOTH);
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

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
	glEnable(GL_MULTISAMPLE_ARB);   
	glEnable(GL_DEPTH_TEST);

	angle=70;
}

void setVisualizationParams(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(angle,aspect,0.4,800);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0,200,400, 0,35,0, 0,1,0);
}

void windowSizeHandler(GLsizei w, GLsizei h)
{
	if ( h == 0 ) h = 1;

	glViewport(0, 0, w, h);
 
	aspect = (GLfloat)w/(GLfloat)h;

	setVisualizationParams();
}

void specialHandler(unsigned char key, int x, int y)
{
	if(key == GLUT_KEY_UP) {
		roll = (roll + 5) % 360;
    	glutPostRedisplay();
	}
	else if(key == GLUT_KEY_DOWN) {
		roll = (roll - 5) % 360;
    	glutPostRedisplay();
	}
	else if(key == GLUT_KEY_RIGHT) {
		pitch = (pitch + 5) % 360;
    	glutPostRedisplay();
	}
	else if(key == GLUT_KEY_LEFT) {
		pitch = (pitch - 5) % 360;
    	glutPostRedisplay();
	}
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
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glutInitWindowSize(600,400);
	glutCreateWindow("Visualizacao 3D");
	glutDisplayFunc(draw);
	glutReshapeFunc(windowSizeHandler);
	glutMouseFunc(mouseHandler);
	glutSpecialFunc(specialHandler);
	init();
	glutMainLoop();
}