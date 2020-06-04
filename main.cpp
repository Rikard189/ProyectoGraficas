/*
  Equipo:
    * Ricardo Leonel Acosta Esquivel - A01039456
    * Ivan Muñiz Ramirez - A01039386
 */

#include <GL/glut.h>  // GLUT, include glu.h and gl.h
/* Global variables */
char title[] = "3D Shapes";

double translateA = 0.0, translateB = 0.0, translateC = -9.0;
double rotateA = 25.0, rotateB = 0.9, rotateC = -1.5, rotateD = 0.0;
double scaleA = 1, scaleB = 1, scaleC = 1;
//gcc main.cpp -o main -lGL -lGLU -lglut

#define checkImageWidth 64
#define checkImageHeight 64
static GLubyte checkImage[checkImageHeight][checkImageWidth][4];

void makeCheckImage(void)
{
   int i, j, c;

    //Generating Checker Patterm
   for (i = 0; i < checkImageHeight; i++) {
      for (j = 0; j < checkImageWidth; j++) {
         c = ((((i&0x8)==0)^((j&0x8))==0))*255;
         checkImage[i][j][0] = (GLubyte) c;
         checkImage[i][j][1] = (GLubyte) c;
         checkImage[i][j][2] = (GLubyte) c;
         checkImage[i][j][3] = (GLubyte) 255;
      }
   }
}

/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
   glEnable(GL_CULL_FACE);
   glCullFace(GL_BACK);

   makeCheckImage();
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_NEAREST);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth,
                checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                checkImage);
   // glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
}

/* Draw a floor (possibly textured). */

static GLfloat floorVertices[4][3] = {
  { -20.0, 0.0, 20.0 },
  { 20.0, 0.0, 20.0 },
  { 20.0, 0.0, -20.0 },
  { -20.0, 0.0, -20.0 },
};
static void
displayFloor(void)
{


  glBegin(GL_QUADS);
    glColor3f(0.0f, 0.4f, 0.0f); 
    glTexCoord2f(0.0, 0.0);
    glVertex3fv(floorVertices[0]);
    glTexCoord2f(0.0, 16.0);
    glVertex3fv(floorVertices[1]);
    glTexCoord2f(16.0, 16.0);
    glVertex3fv(floorVertices[2]);
    glTexCoord2f(16.0, 0.0);
    glVertex3fv(floorVertices[3]);
  glEnd();

}

void displayPatas(){
  
  glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
  // PATAS

  // Back face (z = -0.5f)
  glColor3f(1.0f, 1.0f, 0.0f);     
  glTexCoord2f(0, 0);glVertex3f( 0.3f,  0.0f, 0.3f);
  glTexCoord2f(0, 1);glVertex3f( 0.1f,  0.0f, 0.3f);
  glTexCoord2f(1, 1);glVertex3f( 0.1f, -0.7f, 0.3f);
  glTexCoord2f(1, 0);glVertex3f( 0.3f, -0.7f, 0.3f);

  glColor3f(1.0f, 1.0f, 0.0f);     
  glTexCoord2f(0, 0);glVertex3f( 0.8f,  0.0f, 0.3f);
  glTexCoord2f(0, 1);glVertex3f( 0.6f,  0.0f, 0.3f);
  glTexCoord2f(1, 1);glVertex3f( 0.6f, -0.7f, 0.3f);
  glTexCoord2f(1, 0);glVertex3f( 0.8f, -0.7f, 0.3f);

  glColor3f(1.0f, 1.0f, 0.0f);
  glTexCoord2f(0, 0);glVertex3f( 0.85f, -0.7f, 0.2f);
  glTexCoord2f(0, 1);glVertex3f( 0.55f, -0.7f, 0.2f);
  glTexCoord2f(1, 1);glVertex3f( 0.55f, -0.7f, 0.8f);
  glTexCoord2f(1, 0);glVertex3f( 0.85f, -0.7f, 0.8f);

  glColor3f(1.0f, 1.0f, 0.0f);
  glTexCoord2f(0, 0);glVertex3f( 0.35f, -0.7f, 0.2f);
  glTexCoord2f(0, 1);glVertex3f( 0.05f, -0.7f, 0.2f);
  glTexCoord2f(1, 1);glVertex3f( 0.05f, -0.7f, 0.8f);
  glTexCoord2f(1, 0);glVertex3f( 0.35f, -0.7f, 0.8f);


  glEnd();  // End of drawing color-cube

  GLUquadricObj *quadric;
  quadric=gluNewQuadric();
  gluQuadricNormals(quadric, GLU_SMOOTH);
  gluQuadricTexture(quadric, GL_TRUE);
  gluQuadricOrientation(quadric,GLU_INSIDE);

  // Render
  glPushMatrix();
  glTranslated(0,0,-3);

  glPopMatrix();
}

void displayCuerpo(){
  

  glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
  // CUERPO
   // top face
    glColor3f(0.9f, 0.9f, 0.9f);

    glTexCoord2f(0, 0);glVertex3f( 1.0f, 1.0f, -0.3f);
    glTexCoord2f(0, 2);glVertex3f(-0.0f, 1.0f, -0.3f);
    glTexCoord2f(2, 2);glVertex3f(-0.0f, 1.0f,  1.3f);
    glTexCoord2f(2, 0);glVertex3f( 1.0f, 1.0f,  1.3f);

    // Bottom face (y = -0.5f)
    glColor3f(0.9f, 0.9f, 0.9f);
    glTexCoord2f(0, 0);glVertex3f( 1.0f, -0.0f,  1.3f);
    glTexCoord2f(0, 2);glVertex3f(-0.0f, -0.0f,  1.3f);
    glTexCoord2f(2, 2);glVertex3f(-0.0f, -0.0f, -0.3f);
    glTexCoord2f(2, 0);glVertex3f( 1.0f, -0.0f, -0.3f);
    //
    // front face  (z = 0.5f)
    glColor3f(0.9f, 0.9f, 0.9f);
    glTexCoord2f(0, 0);glVertex3f( 1.0f,  1.0f, 1.3f);
    glTexCoord2f(0, 2);glVertex3f(-0.0f,  1.0f, 1.3f);
    glTexCoord2f(2, 2);glVertex3f(-0.0f, -0.0f, 1.3f);
    glTexCoord2f(2, 0);glVertex3f( 1.0f, -0.0f, 1.3f);

    // Back face (z = -0.5f)
    glColor3f(0.9f, 0.9f, 0.9f);
    glTexCoord2f(0, 0);glVertex3f( 1.0f, -0.0f, -0.3f);
    glTexCoord2f(0, 2);glVertex3f(-0.0f, -0.0f, -0.3f);
    glTexCoord2f(2, 2);glVertex3f(-0.0f,  1.0f, -0.3f);
    glTexCoord2f(2, 0);glVertex3f( 1.0f,  1.0f, -0.3f);
    //
    // Left face (x = -0.5f)
    glColor3f(0.9f, 0.9f, 0.9f);
    glTexCoord2f(0, 0);glVertex3f(0.0f,  1.0f,  1.3f);
    glTexCoord2f(0, 2);glVertex3f(0.0f,  1.0f, -0.3f);
    glTexCoord2f(2, 2);glVertex3f(0.0f, -0.0f, -0.3f);
    glTexCoord2f(2, 0);glVertex3f(0.0f, -0.0f,  1.3f);
    //
    // Right face (x = 0.5f)
    glColor3f(0.9f, 0.9f, 0.9f);
    glTexCoord2f(0, 0);glVertex3f(1.0f,  1.0f, -0.3f);
    glTexCoord2f(0, 2);glVertex3f(1.0f,  1.0f,  1.3f);
    glTexCoord2f(2, 2);glVertex3f(1.0f, -0.0f,  1.3f);
    glTexCoord2f(2, 0);glVertex3f(1.0f, -0.0f, -0.3f);

  glEnd();  // End of drawing color-cube

    GLUquadricObj *quadric;
    quadric=gluNewQuadric();
    gluQuadricNormals(quadric, GLU_SMOOTH);
    gluQuadricTexture(quadric, GL_TRUE);
    gluQuadricOrientation(quadric,GLU_INSIDE);

    // Render
    glPushMatrix();
    glTranslated(0,0,-3);
    // gluSphere(quadric,1,16,16);
    //// gluCylinder (or cone),gluDisk,gluPartialDisk

    glPopMatrix();

}

void displayAlaIzq(){
  
  glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
  // ALAS
   // top face
    glColor3f(0.8f, 0.8f, 0.8f);
    glTexCoord2f(0, 0);glVertex3f( 0.0f, 1.0f, -0.0f);
    glTexCoord2f(0, 5);glVertex3f(-0.3f, 1.0f, -0.0f);
    glTexCoord2f(5, 5);glVertex3f(-0.3f, 1.0f,  1.0f);
    glTexCoord2f(5, 0);glVertex3f( 0.0f, 1.0f,  1.0f);

    // Bottom face (y = -0.5f)
    glColor3f(0.8f, 0.8f, 0.8f);
    glTexCoord2f(0, 0);glVertex3f( 0.0f, 0.3f,  1.0f);
    glTexCoord2f(0, 5);glVertex3f(-0.3f, 0.3f,  1.0f);
    glTexCoord2f(5, 5);glVertex3f(-0.3f, 0.3f, -0.0f);
    glTexCoord2f(5, 0);glVertex3f( 0.0f, 0.3f, -0.0f);
    //
    // front face  (z = 0.5f)
    glColor3f(0.8f, 0.8f, 0.8f);
    glTexCoord2f(0, 0);glVertex3f( 0.0f,  1.0f, 1.0f);
    glTexCoord2f(0, 5);glVertex3f(-0.3f,  1.0f, 1.0f);
    glTexCoord2f(5, 5);glVertex3f(-0.3f, 0.3f, 1.0f);
    glTexCoord2f(5, 0);glVertex3f( 0.0f, 0.3f, 1.0f);

    // Back face (z = -0.5f)
    glColor3f(0.8f, 0.8f, 0.8f);
    glTexCoord2f(0, 0);glVertex3f( 0.0f, 0.3f, -0.0f);
    glTexCoord2f(0, 5);glVertex3f(-0.3f, 0.3f, -0.0f);
    glTexCoord2f(5, 5);glVertex3f(-0.3f,  1.0f, -0.0f);
    glTexCoord2f(5, 0);glVertex3f( 0.0f,  1.0f, -0.0f);
    //
    // Left face (x = -0.5f)
    glColor3f(0.8f, 0.8f, 0.8f);
    glTexCoord2f(0, 0);glVertex3f(-0.3f,  1.0f,  1.0f);
    glTexCoord2f(0, 5);glVertex3f(-0.3f,  1.0f, -0.0f);
    glTexCoord2f(5, 5);glVertex3f(-0.3f, 0.3f, -0.0f);
    glTexCoord2f(5, 0);glVertex3f(-0.3f, 0.3f,  1.0f);
    //
    // Right face (x = 0.5f)
    glColor3f(0.8f, 0.8f, 0.8f);
    glTexCoord2f(0, 0);glVertex3f(0.0f,  1.0f, -0.0f);
    glTexCoord2f(0, 5);glVertex3f(0.0f,  1.0f,  1.0f);
    glTexCoord2f(5, 5);glVertex3f(0.0f, 0.3f,  1.0f);
    glTexCoord2f(5, 0);glVertex3f(0.0f, 0.3f, -0.0f);
  glEnd();  // End of drawing color-cube

  GLUquadricObj *quadric;
  quadric=gluNewQuadric();
  gluQuadricNormals(quadric, GLU_SMOOTH);
  gluQuadricTexture(quadric, GL_TRUE);
  gluQuadricOrientation(quadric,GLU_INSIDE);

  // Render
  glPushMatrix();
  glTranslated(0,0,-3);

  glPopMatrix();
}

void displayAlaDer(){
  
  glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
  // ALAS
   // top face
    glColor3f(0.8f, 0.8f, 0.8f);
    glTexCoord2f(0, 0);glVertex3f( 1.3f, 1.0f, -0.0f);
    glTexCoord2f(0, 5);glVertex3f(1.0f, 1.0f, -0.0f);
    glTexCoord2f(5, 5);glVertex3f(1.0f, 1.0f,  1.0f);
    glTexCoord2f(5, 0);glVertex3f( 1.3f, 1.0f,  1.0f);

    // Bottom face (y = -0.5f)
    glColor3f(0.8f, 0.8f, 0.8f);
    glTexCoord2f(0, 0);glVertex3f( 1.3f, 0.3f,  1.0f);
    glTexCoord2f(0, 5);glVertex3f(1.0f, 0.3f,  1.0f);
    glTexCoord2f(5, 5);glVertex3f(1.0f, 0.3f, -0.0f);
    glTexCoord2f(5, 0);glVertex3f( 1.3f, 0.3f, -0.0f);
    //
    // front face  (z = 0.5f)
    glColor3f(0.8f, 0.8f, 0.8f);
    glTexCoord2f(0, 0);glVertex3f( 1.3f,  1.0f, 1.0f);
    glTexCoord2f(0, 5);glVertex3f(1.0f,  1.0f, 1.0f);
    glTexCoord2f(5, 5);glVertex3f(1.0f, 0.3f, 1.0f);
    glTexCoord2f(5, 0);glVertex3f( 1.3f, 0.3f, 1.0f);

    // Back face (z = -0.5f)
    glColor3f(0.8f, 0.8f, 0.8f);
    glTexCoord2f(0, 0);glVertex3f( 1.3f, 0.3f, -0.0f);
    glTexCoord2f(0, 5);glVertex3f(1.0f, 0.3f, -0.0f);
    glTexCoord2f(5, 5);glVertex3f(1.0f,  1.0f, -0.0f);
    glTexCoord2f(5, 0);glVertex3f( 1.3f,  1.0f, -0.0f);
    //
    // Left face (x = -0.5f)
    glColor3f(0.8f, 0.8f, 0.8f);
    glTexCoord2f(0, 0);glVertex3f(1.0f,  1.0f,  1.0f);
    glTexCoord2f(0, 5);glVertex3f(1.0f,  1.0f, -0.0f);
    glTexCoord2f(5, 5);glVertex3f(1.0f, 0.3f, -0.0f);
    glTexCoord2f(5, 0);glVertex3f(1.0f, 0.3f,  1.0f);
    //
    // Right face (x = 0.5f)
    glColor3f(0.8f, 0.8f, 0.8f);
    glTexCoord2f(0, 0);glVertex3f(1.3f,  1.0f, -0.0f);
    glTexCoord2f(0, 5);glVertex3f(1.3f,  1.0f,  1.0f);
    glTexCoord2f(5, 5);glVertex3f(1.3f, 0.3f,  1.0f);
    glTexCoord2f(5, 0);glVertex3f(1.3f, 0.3f, -0.0f);
  glEnd();  // End of drawing color-cube
  GLUquadricObj *quadric;
  quadric=gluNewQuadric();
  gluQuadricNormals(quadric, GLU_SMOOTH);
  gluQuadricTexture(quadric, GL_TRUE);
  gluQuadricOrientation(quadric,GLU_INSIDE);

  // Render
  glPushMatrix();
  glTranslated(0,0,-3);

  glPopMatrix();
}

void displayCabeza(){
  
  glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
  // CABEZA


    // Bottom face (y = -0.5f)
    glColor3f(0.9f, 0.9f, 0.9f);
    glTexCoord2f(0, 0);glVertex3f( 0.7f, 0.5f, 0.2f);
    glTexCoord2f(0, 3.5);glVertex3f( 0.1f, 0.5f, 0.2f);
    glTexCoord2f(3.5, 3.5);glVertex3f( 0.1f, 0.5f, 1.2f);
    glTexCoord2f(3.5, 0);glVertex3f( 0.7f, 0.5f, 1.2f);
    // //
    // Back face (z = -0.5f)
    glColor3f(0.9f, 0.9f, 0.9f);
    glTexCoord2f(0, 0);glVertex3f( 0.7f,  1.3f, 0.2f);
    glTexCoord2f(0, 3.5);glVertex3f( 0.1f,  1.3f, 0.2f);
    glTexCoord2f(3.5, 3.5);glVertex3f( 0.1f, 0.5f, 0.2f);
    glTexCoord2f(3.5, 0);glVertex3f( 0.7f, 0.5f, 0.2f);
    // //
    // Left face (x = -0.5f)
    glColor3f(0.9f, 0.9f, 0.9f);
    glTexCoord2f(0, 0);glVertex3f(0.1f, 1.3f, 0.2f);
    glTexCoord2f(0, 3.5);glVertex3f(0.1f, 1.3f, 1.2f);
    glTexCoord2f(3.5, 3.5);glVertex3f(0.1f, 0.5f, 1.2f);
    glTexCoord2f(3.5, 0);glVertex3f(0.1f, 0.5f, 0.2f);
    // //
    // Right face (x = 0.5f)
    glColor3f(0.9f, 0.9f, 0.9f);
    glTexCoord2f(0, 0);glVertex3f(0.7f, 1.3f, 0.2f);
    glTexCoord2f(0, 3.5);glVertex3f(0.7f, 1.3f, 1.2f);
    glTexCoord2f(3.5, 3.5);glVertex3f(0.7f, 0.5f, 1.2f);
    glTexCoord2f(3.5, 0);glVertex3f(0.7f, 0.5f, 0.2f);

    // top face
     glColor3f(0.9f, 0.9f, 0.9f);
     glTexCoord2f(0, 0);glVertex3f( 0.7f, 1.3f, 0.2f);
     glTexCoord2f(0, 3.5);glVertex3f( 0.1f, 1.3f, 0.2f);
     glTexCoord2f(3.5, 3.5);glVertex3f( 0.1f, 1.3f, 1.2f);
     glTexCoord2f(3.5, 0);glVertex3f( 0.7f, 1.3f, 1.2f);

    // front face  (z = 0.5f)
    glColor3f(0.9f, 0.9f, 0.9f);     // Rosa izquierda
    glTexCoord2f(0, 0);glVertex3f( 0.7f,  1.3f, 1.2f);
    glTexCoord2f(0, 3.5);glVertex3f( 0.1f,  1.3f, 1.2f);
    glTexCoord2f(3.5, 3.5);glVertex3f( 0.1f, 0.5f, 1.2f);
    glTexCoord2f(3.5, 0);glVertex3f( 0.7f, 0.5f, 1.2f);
    //
  glEnd();  // End of drawing color-cube
  GLUquadricObj *quadric;
  quadric=gluNewQuadric();
  gluQuadricNormals(quadric, GLU_SMOOTH);
  gluQuadricTexture(quadric, GL_TRUE);
  gluQuadricOrientation(quadric,GLU_INSIDE);

  // Render
  glPushMatrix();
  glTranslated(0,0,-3);

  glPopMatrix();
}

void displayPico(){
  
  glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
  // PICO


    // Bottom face (y = -0.5f)
    glColor3f(1.0f, 1.0f, 0.5f);
    glTexCoord2f(0, 0);glVertex3f( 0.7f, 0.8f, 1.2f);
    glTexCoord2f(0, .5);glVertex3f( 0.1f, 0.8f, 1.2f);
    glTexCoord2f(.5, .5);glVertex3f( 0.1f, 0.8f, 1.4f);
    glTexCoord2f(.5, 0);glVertex3f( 0.7f, 0.8f, 1.4f);
    // //
    //Back face (z = -0.5f)
    glColor3f(1.0f, 1.0f, 0.5f);
    glTexCoord2f(0, 0);glVertex3f( 0.7f,  1.0f, 1.2f);
    glTexCoord2f(0, .5);glVertex3f( 0.1f,  1.0f, 1.2f);
    glTexCoord2f(.5, .5);glVertex3f( 0.1f, 0.8f, 1.2f);
    glTexCoord2f(.5, 0);glVertex3f( 0.7f, 0.8f, 1.2f);
    // //
    // // Left face (x = -0.5f)
    glColor3f(1.0f, 1.0f, 0.5f);
    glTexCoord2f(0, 0);glVertex3f(0.1f, 0.8f, 1.2f);
    glTexCoord2f(0, .5);glVertex3f(0.1f, 1.0f, 1.2f);//
    glTexCoord2f(.5, .5);glVertex3f(0.1f, 0.8f, 1.4f);
    glTexCoord2f(.5, 0);glVertex3f(0.1f, 1.0f, 1.4f);
    // //
    // // Right face (x = 0.5f)
    glColor3f(1.0f, 1.0f, 0.5f);
    glTexCoord2f(0, 0);glVertex3f(0.7f, 0.8f, 1.2f);
    glTexCoord2f(0, .5);glVertex3f(0.7f, 1.0f, 1.2f);//
    glTexCoord2f(.5, .5);glVertex3f(0.7f, 0.8f, 1.4f);
    glTexCoord2f(.5, 0);glVertex3f(0.7f, 1.0f, 1.4f);
    //
    // top face
    glColor3f(1.0f, 1.0f, 0.5f);
    glTexCoord2f(0, 0);glVertex3f( 0.7f, 1.0f, 1.2f);
    glTexCoord2f(0, .5);glVertex3f( 0.1f, 1.0f, 1.2f);
    glTexCoord2f(.5, .5);glVertex3f( 0.1f, 1.0f, 1.4f);
    glTexCoord2f(.5, 0);glVertex3f( 0.7f, 1.0f, 1.4f);

    // // front face  (z = 0.5f)
    glColor3f(1.0f, 1.0f, 0.5f);
    glTexCoord2f(0, 0);glVertex3f( 0.7f,  1.0f, 1.4f);
    glTexCoord2f(0, .5);glVertex3f( 0.1f,  1.0f, 1.4f);
    glTexCoord2f(.5, .5);glVertex3f( 0.1f, 0.8f, 1.4f);
    glTexCoord2f(.5, 0);glVertex3f( 0.7f, 0.8f, 1.4f);

  glEnd();  // End of drawing color-cube
  GLUquadricObj *quadric;
  quadric=gluNewQuadric();
  gluQuadricNormals(quadric, GLU_SMOOTH);
  gluQuadricTexture(quadric, GL_TRUE);
  gluQuadricOrientation(quadric,GLU_INSIDE);

  // Render
  glPushMatrix();
  glTranslated(0,0,-3);

  glPopMatrix();
}

void displayOjos(){
  
  glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads


  glColor3f(0.0f, 0.0f, 0.0f);
  glTexCoord2f(0, 0);glVertex3f( 0.4f,  1.2f, 1.4f);
  glTexCoord2f(0, .5);glVertex3f( 0.2f,  1.2f, 1.4f);
  glTexCoord2f(.5, .5);glVertex3f( 0.2f, 1.0f, 1.4f);
  glTexCoord2f(.5, 0);glVertex3f( 0.4f, 1.0f, 1.4f);

  glColor3f(0.0f, 0.0f, 0.0f);
  glTexCoord2f(0, 0);glVertex3f( 0.7f,  1.2f, 1.4f);
  glTexCoord2f(0, .5);glVertex3f( 0.5f,  1.2f, 1.4f);
  glTexCoord2f(.5, .5);glVertex3f( 0.5f, 1.0f, 1.4f);
  glTexCoord2f(.5, 0);glVertex3f( 0.7f, 1.0f, 1.4f);

  glEnd();
  GLUquadricObj *quadric;
  quadric=gluNewQuadric();
  gluQuadricNormals(quadric, GLU_SMOOTH);
  gluQuadricTexture(quadric, GL_TRUE);
  gluQuadricOrientation(quadric,GLU_INSIDE);

  // Render
  glPushMatrix();
  glTranslated(0,0,-3);

  glPopMatrix();
}
/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */
void displayPapada(){
  
  glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads

    // Bottom face (y = -0.5f)
    glColor3f(1.0f, 0.0f, 0.0f);
    glTexCoord2f(0, 0);glVertex3f( 0.5f, 0.6f, 1.2f);
    glTexCoord2f(0, .5);glVertex3f( 0.3f, 0.6f, 1.2f);
    glTexCoord2f(.5, .5);glVertex3f( 0.3f, 0.6f, 1.4f);
    glTexCoord2f(.5, 0);glVertex3f( 0.5f, 0.6f, 1.4f);
    // //
    //Back face (z = -0.5f)
    glColor3f(1.0f, 0.0f, 0.0f);
    glTexCoord2f(0, 0);glVertex3f( 0.5f,  0.8f, 1.2f);
    glTexCoord2f(0, .5);glVertex3f( 0.3f,  0.8f, 1.2f);
    glTexCoord2f(.5, .5);glVertex3f( 0.3f, 0.6f, 1.2f);
    glTexCoord2f(.5, 0);glVertex3f( 0.5f, 0.6f, 1.2f);
    // //
    // // Left face (x = -0.5f)
    glColor3f(1.0f, 0.0f, 0.0f);
    glTexCoord2f(0, 0);glVertex3f(0.3f, 0.6f, 1.2f);
    glTexCoord2f(0, .5);glVertex3f(0.3f, 0.8f, 1.2f);//
    glTexCoord2f(.5, .5);glVertex3f(0.3f, 0.6f, 1.4f);
    glTexCoord2f(.5, 0);glVertex3f(0.3f, 0.8f, 1.4f);
    // //
    // // Right face (x = 0.5f)
    glColor3f(1.0f, 0.0f, 0.0f);
    glTexCoord2f(0, 0);glVertex3f(0.5f, 0.6f, 1.2f);
    glTexCoord2f(0, .5);glVertex3f(0.5f, 0.8f, 1.2f);//
    glTexCoord2f(.5, .5);glVertex3f(0.5f, 0.6f, 1.4f);
    glTexCoord2f(.5, 0);glVertex3f(0.5f, 0.8f, 1.4f);
    //
    // top face
    glColor3f(1.0f, 0.0f, 0.0f);
    glTexCoord2f(0, 0);glVertex3f( 0.5f, 0.8f, 1.2f);
    glTexCoord2f(0, .5);glVertex3f( 0.3f, 0.8f, 1.2f);
    glTexCoord2f(.5, .5);glVertex3f( 0.3f, 0.8f, 1.4f);
    glTexCoord2f(.5, 0);glVertex3f( 0.5f, 0.8f, 1.4f);

    // // front face  (z = 0.5f)
    glColor3f(1.0f, 0.0f, 0.0f);
    glTexCoord2f(0, 0);glVertex3f( 0.5f,  0.8f, 1.4f);
    glTexCoord2f(0, .5);glVertex3f( 0.3f,  0.8f, 1.4f);
    glTexCoord2f(.5, .5);glVertex3f( 0.3f, 0.6f, 1.4f);
    glTexCoord2f(.5, 0);glVertex3f( 0.5f, 0.6f, 1.4f);

  glEnd();
  GLUquadricObj *quadric;
  quadric=gluNewQuadric();
  gluQuadricNormals(quadric, GLU_SMOOTH);
  gluQuadricTexture(quadric, GL_TRUE);
  gluQuadricOrientation(quadric,GLU_INSIDE);

  // Render
  glPushMatrix();
  glTranslated(0,0,-3);

  glPopMatrix();
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix

   // Render a color-cube consisting of 6 quads with different colors
   glLoadIdentity();                 // Reset the model-view matrix
   glTranslatef(translateA, translateB, translateC);  // Move right and into the screen
   glRotatef(rotateA, rotateB, rotateC, rotateD);
   glScalef(scaleA, scaleB, scaleC);
   // glRotatef(45.0f, 0.5f, -0.5f, -0.0f);

   displayFloor();
   displayPatas();
   displayAlaIzq();
   displayCuerpo();
   displayAlaDer();
   displayCabeza();
   displayPico();
   displayOjos();
   displayPapada();


   glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);

   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);


}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    glutInit(&argc, argv);            // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
    glutInitWindowSize(1000, 1000);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow(title);          // Create window with the given title
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    glutReshapeFunc(reshape);       // Register callback handler for window re-size event
    initGL();                       // Our own OpenGL initialization
    glutMainLoop();                 // Enter the infinite event-processing loop
    return 0;
}
