
#include<stdlib.h>
#include<stdio.h>
#include<GL/glut.h>

const int SPRITE_NUM=8;

const int MOVE_NONE=0;
const int MOVE_FRONT=1;
const int MOVE_RIGHT=2;
const int MOVE_LEFT=3;
const int MOVE_BACK=4;

const int FACE_FRONT=1;
const int FACE_RIGHT=2;
const int FACE_LEFT=3;
const int FACE_BACK=4;

const int KPL=0;
const int BDN=1;
const int TAA=2;
const int TAB=3;
const int TIA=4;
const int TIB=5;
const int KAA=6;
const int KAB=7;
const int KIA=8;
const int KIB=9;

int SPRITE_PROG=8;

int FPS=70;
int finish=0;

float f[10][SPRITE_NUM][6]={
/*
-------| x |---| y |---| z |---
*/
		//head
		0		,0		,0,0,0,0,
		0		,-0.05	,0,0,0,0,
		0		,-0.1	,0,0,0,0,
		0		,-0.05	,0,0,0,0,
		0		,0		,0,0,0,0,
		0		,-0.05	,0,0,0,0,
		0		,-0.1	,0,0,0,0,
		0		,-0.05	,0,0,0,0,
		//body
		0		,-1.5	,0,0,0,0,
		0		,-1.55	,0,0,0,0,
		0		,-1.6	,0,0,0,0,
		0		,-1.55	,0,0,0,0,
		0		,-1.5	,0,0,0,0,
		0		,-1.55	,0,0,0,0,
		0		,-1.6	,0,0,0,0,
		0		,-1.55	,0,0,0,0,
		//right hand up
		1.25	,-0.75	,0		,0	,0	,30,
		1.25	,-0.80	,0		,15	,0	,30,
		1.25	,-0.85	,0		,30	,0	,30,
		1.25	,-0.80	,0		,15	,0	,30,
		1.25	,-0.75	,0		,0	,0	,30,
		1.25	,-0.80	,0		,-15,0	,30,
		1.25	,-0.85	,0		,-30,0	,30,
		1.25	,-0.80	,0		,-15,0	,30,
		//right hand bot
		1.90	,-2.25	,0		,0	,0	,0,
		1.90	,-2.1	,-0.3	,30	,0	,0,
		1.90	,-2		,-0.6	,45	,0	,0,
		1.90	,-2.1	,-0.3	,60	,0	,0,
		1.90	,-2.25	,0		,0	,0	,0,
		1.90	,-2.1	,0.3	,0	,0	,0,
		1.90	,-2		,0.6	,0	,0	,0,
		1.90	,-2.1	,0.3	,0	,0	,0,
		//left hand up
		-1.25	,-0.75	,0		,0	,0	,-30,
		-1.25	,-0.80	,0		,-15,0	,-30,
		-1.25	,-0.85	,0		,-30,0	,-30,
		-1.25	,-0.80	,0		,-15,0	,-30,
		-1.25	,-0.75	,0		,0	,0	,-30,
		-1.25	,-0.80	,0		,15	,0	,-30,
		-1.25	,-0.85	,0		,30	,0	,-30,
		-1.25	,-0.80	,0		,15	,0	,-30,
		//left hand bot
		-1.90	,-2.25	,0		,0	,0	,0,
		-1.90	,-2.1	,0.3	,0	,0	,0,
		-1.90	,-2		,0.6	,0	,0	,0,
		-1.90	,-2.1	,0.3	,0	,0	,0,
		-1.90	,-2.25	,0		,0	,0	,0,
		-1.90	,-2.1	,-0.3	,30	,0	,0,
		-1.90	,-2		,-0.6	,45	,0	,0,
		-1.90	,-2.1	,-0.3	,60	,0	,0,
		//right leg up
		0.5		,-3.7	,0		,0	,0	,0,
		0.5		,-3.75	,0		,-15,0	,0,
		0.5		,-3.8	,0		,-30,0	,0,
		0.5		,-3.75	,0		,-15,0	,0,
		0.5		,-3.7	,0		,0	,0	,0,
		0.5		,-3.75	,0		,15	,0	,0,
		0.5		,-3.8	,0		,30	,0	,0,
		0.5		,-3.75	,0		,15	,0	,0,
		//right leg bot
		0.5		,-5.75	,0,0,0,0,
		0.5		,-5.70	,0.5,-20,0,0,
		0.5		,-5.65	,1.2,-50,0,0,
		0.5		,-5.70	,0.5,-20,0,0,
		0.5		,-5.75	,0,0,0,0,
		0.5		,-5.70	,-0.5,20,0,0,
		0.5		,-5.65	,-1,20,0,0,
		0.5		,-5.70	,-0.5,20,0,0,
		//left leg up
		-0.5	,-3.7	,0		,0	,0	,0,
		-0.5	,-3.75	,0		,15	,0	,0,
		-0.5	,-3.8	,0		,30	,0	,0,
		-0.5	,-3.75	,0		,15	,0	,0,
		-0.5	,-3.7	,0		,0	,0	,0,
		-0.5	,-3.75	,0		,-15,0	,0,
		-0.5	,-3.8	,0		,-30,0	,0,
		-0.5	,-3.75	,0		,-15,0	,0,
		//left leg bot
		-0.5	,-5.75,0,0,0,0,
		-0.5	,-5.70,-0.5,20,0,0,
		-0.5	,-5.65,-1,20,0,0,
		-0.5	,-5.70,-0.5,20,0,0,
		-0.5	,-5.75,0,0,0,0,
		-0.5	,-5.70,0.5,-20,0,0,
		-0.5	,-5.65,1.2,-50,0,0,
		-0.5	,-5.70,0.5,-20,0,0
	};

int moving=MOVE_NONE;
int facing=FACE_FRONT;

float stageX=0, stageY=0, stageZ=0;
int w=500,h=500;
int  anglex=30,angley,anglez;


void transNow(float temp[10][SPRITE_NUM][6], int ELM){
	glTranslatef(temp[ELM][SPRITE_PROG][0],temp[ELM][SPRITE_PROG][1],temp[ELM][SPRITE_PROG][2]);
	glRotatef(temp[ELM][SPRITE_PROG][3],1,0,0);
	glRotatef(temp[ELM][SPRITE_PROG][4],0,1,0);
	glRotatef(temp[ELM][SPRITE_PROG][5],0,0,1);
}

void head(){
	glColor3f(1,1,1);
	glutSolidCube(1);
	glColor3f(1,1,0);
	glPushMatrix();
	glTranslatef(0.2,0,-0.6);
	glutSolidCube(0.2);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.2,0,-0.6);
	glutSolidCube(0.2);
	glPopMatrix();
}

void hand_u(){
	glColor3f(0,1,0);
	glPushMatrix();
	glutSolidCube(0.5);
	glTranslatef(0,-0.25,0);
	glutSolidCube(0.5);
	glTranslatef(0,-0.25,0);
	glutSolidCube(0.5);
	glTranslatef(0,-0.25,0);
	glutSolidCube(0.5);
	glTranslatef(0,-0.25,0);
	glutSolidCube(0.5);
	glPopMatrix();

}

void hand_d(){
	glColor3f(0,1,1);
	glPushMatrix();
	glutSolidCube(0.5);
	glTranslatef(0,-0.25,0);
	glutSolidCube(0.5);
	glTranslatef(0,-0.25,0);
	glutSolidCube(0.5);
	glTranslatef(0,-0.25,0);
	glutSolidCube(0.5);
	glTranslatef(0,-0.25,0);
	glutSolidCube(0.5);
	glPopMatrix();
}

void body(){
	glColor3f(0,0,1);
	glPushMatrix();
	glutSolidCube(1.5);
	glTranslatef(0,-0.75,0);
	glutSolidCube(1.5);
	glPopMatrix();
}

void leg_u(){
	glColor3f(0,1,0);
	glPushMatrix();
	glutSolidCube(0.6);
	glTranslatef(0,-0.3,0);
	glutSolidCube(0.6);
	glTranslatef(0,-0.3,0);
	glutSolidCube(0.6);
	glTranslatef(0,-0.3,0);
	glutSolidCube(0.6);
	glTranslatef(0,-0.3,0);
	glutSolidCube(0.6);
	glPopMatrix();
}

void leg_d(){
	glColor3f(0,1,0);
	glPushMatrix();
	glutSolidCube(0.6);
	glTranslatef(0,-0.3,0);
	glutSolidCube(0.6);
	glTranslatef(0,-0.3,0);
	glutSolidCube(0.6);
	glTranslatef(0,-0.3,0);
	glutSolidCube(0.6);
	glTranslatef(0,-0.3,0);
	glutSolidCube(0.6);
	glPopMatrix();
}

void head_(){
	int elem=KPL;
	glPushMatrix();
	transNow(f, elem);
	head();
	glPopMatrix();
}

void body_(){
	int elem=BDN;
	glPushMatrix();
	transNow(f, elem);
	body();
	glPopMatrix();
}

void right_hand_u(){
	int elem=TAA;
	glPushMatrix();
	transNow(f, elem);
	hand_u();
	glPopMatrix();
}

void right_hand_d(){
	int elem=TAB;
	glPushMatrix();
	transNow(f, elem);
	hand_d();
	glPopMatrix();
}

void left_hand_u(){
	int elem=TIA;
	glPushMatrix();
	transNow(f, elem);
	hand_u();
	glPopMatrix();
}

void left_hand_d(){
	int elem=TIB;
	glPushMatrix();
	transNow(f, elem);
	hand_d();
	glPopMatrix();
}

void right_leg_u(){
	int elem=KAA;
	glPushMatrix();
	transNow(f, elem);
	leg_u();
	glPopMatrix();
}

void right_leg_d(){
	int elem=KAB;
	glPushMatrix();
	transNow(f, elem);
	leg_d();
	glPopMatrix();
}

void left_leg_u(){
	int elem=KIA;
	glPushMatrix();
	transNow(f, elem);
	leg_u();
	glPopMatrix();
}

void left_leg_d(){
	int elem=KIB;
	glPushMatrix();
	transNow(f, elem);
	leg_d();
	glPopMatrix();
}

void drawPlayer(){
	head_();
	right_hand_u();
	right_hand_d();
	left_hand_u();
	left_hand_d();
	body_();
	right_leg_u();
	right_leg_d();
	left_leg_u();
	left_leg_d();
}

void drawStage(){
	glTranslatef(stageX,stageY,stageZ);
	glBegin(GL_QUADS);
	glVertex3d(10,-7.3,10);
	glVertex3d(-10,-7.3,10);
	glVertex3d(-10,-7.3,-10);
	glVertex3d(10,-7.3,-10);

	glEnd();

}

void drawDoor(){
	glTranslatef(stageX,stageY,stageZ);
	glBegin(GL_QUADS);
	glVertex3d(-2,-7,-10);
	glVertex3d(-8,-7,-10);
	glVertex3d(-8,2,-10);
	glVertex3d(-2,2,-10);

	glEnd();

}

void keyPress (unsigned char key, int x, int y){
	if (key == 'y') anglex+=5;
	else if (key == 'x') angley+=5;
	else if (key == 'z') anglez+=5;
	else if (key == 'b') {
		moving=MOVE_FRONT;
	}else if (key == 'l') {
		moving=MOVE_LEFT;
	}else if (key == 'f') {
		moving=MOVE_BACK;
	}else if (key == 'r') {
		moving=MOVE_RIGHT;
	}else if (key == 'd'){
		FPS=FPS+20;
	}else if (key == 'i'){
		FPS=FPS-20;
	}else if (key == 'e'){

			exit(0);
		}
	}


void keyUp (unsigned char key, int x, int y) {
	if(key == 'b'){
		moving=MOVE_NONE;
		facing=FACE_FRONT;
	}else if(key == 'l'){
		moving=MOVE_NONE;
		facing=FACE_LEFT;
	}else if(key == 'f'){
		moving=MOVE_NONE;
		facing=FACE_BACK;
	}else if(key == 'r'){
		moving=MOVE_NONE;
		facing=FACE_RIGHT;
	}
}

void init()
{
	GLfloat LightPosition[]={10.0F, 10.0F, 20.0F, 0.0F};
	GLfloat LightAmbient[]={0.0F, 1.0F, 0.0F, 1.0F};
	GLfloat LightDiffuse[]={0.7F, 0.7F, 0.7F, 1.0F};
	GLfloat LightSpecular[]={0.5F, 0.5F, 0.5F, 1.0F};
	GLfloat Shine[]={80};
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f,0.0f,0.0f,0.5f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glMaterialfv(GL_FRONT, GL_AMBIENT, LightAmbient);
	glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	return;
}

void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0,5,-17);
	if(finish!=1){
		glPushMatrix();
		glRotated(anglex,1,0,0);
		glRotated(angley,0,1,0);
		glRotated(anglez,0,0,1);
		glEnable(GL_COLOR_MATERIAL);
		printf("%i\n",stageZ);
		// ------ player ---------
		glPushMatrix();
		switch(moving){
		case MOVE_FRONT:
			glRotatef(0,0,1,0);
			if(stageZ<9)
			stageZ+=1;
			break;
		case MOVE_RIGHT:
			glRotatef(-90,0,1,0);
			if(stageX>-9)
			stageX-=1;
			break;
		case MOVE_LEFT:
			glRotatef(90,0,1,0);
			if(stageX<9)
			stageX+=1;
			break;
		case MOVE_BACK:
			glRotatef(180,0,1,0);
			if(stageZ>-9)
			stageZ-=1;
			break;
		case MOVE_NONE:
			switch(facing){
			case FACE_FRONT:
				glRotatef(0,0,1,0);
				break;
			case FACE_RIGHT:
				glRotatef(-90,0,1,0);
				break;
			case FACE_LEFT:
				glRotatef(90,0,1,0);
				break;
			case FACE_BACK:
				glRotatef(180,0,1,0);
				break;
			}
			SPRITE_PROG=0;
			break;
		}
		drawPlayer();
		glPopMatrix();
		// ------ player end ------
		glPushMatrix();
		glColor3f(1,1,1);
		drawStage();
		glPopMatrix();
		glPushMatrix();
		glColor3f(1,0,1);
		drawDoor();
		glPopMatrix();
	}else{
		//place ending here
	}
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();
	glutSwapBuffers();
}

void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
	glMatrixMode (GL_MODELVIEW);
}


void update (int value) {
	if(moving!=MOVE_NONE){
		if(SPRITE_PROG<SPRITE_NUM){
			SPRITE_PROG++;
		}
	}

	if(SPRITE_PROG==SPRITE_NUM){
		SPRITE_PROG=0;
	}

	glutPostRedisplay();
	glutTimerFunc(FPS,update,FPS);
}
void glutmenu(void)
{

    glutCreateMenu(NULL);
    glutAddMenuEntry("right----->r",0);
    glutAddMenuEntry("left------>l",0);
    glutAddMenuEntry("front----->f",0);
    glutAddMenuEntry("back------>b",0);
    glutAddMenuEntry("x-axis---->x",0);
    glutAddMenuEntry("y-axis---->y",0);
    glutAddMenuEntry("z-axis---->z",0);
    glutAddMenuEntry("speed dc-->d",0);
    glutAddMenuEntry("speed ic-->i",0);
    glutAddMenuEntry("exit------>e",0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}



int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("3D Walking Animation");
	init();
	glutDisplayFunc(renderScene);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyPress);
	glutKeyboardUpFunc(keyUp);
	glutTimerFunc(1,update,FPS);
	glutmenu();
	glutMainLoop();
	return 0;
}

