#include <iostream>
#include <GL/glut.h>

void keyboard(unsigned char key, int x, int y);
void display(void);
void resize(int w, int h);

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutCreateWindow("GLUT Test");
  glutKeyboardFunc(&keyboard);
  glutDisplayFunc(&display);
  glutReshapeFunc(&resize);
  glutMainLoop();

  return EXIT_SUCCESS;
}

void keyboard(unsigned char key, int x, int y) {
  switch (key)
  {
    case '\x1B':
      exit(EXIT_SUCCESS);
      break;
  }
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_POLYGON);
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex2d(-0.9f, -0.9f);
  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex2d(0.9f, -0.9f);
  glColor3f(0.0f, 0.0f, 1.0f);
  glVertex2d(0.9f, 0.9f);
  glColor3f(1.0f, 1.0f, 0.0f);
  glVertex2d(-0.9f, 0.9f);
  glEnd();
  glFlush();
}

void resize(int w, int h) {
  // ウィンドウ全体をビューポートにする
  glViewport(0, 0, w, h);
  // 変換行列の初期化
  glLoadIdentity();
  // スクリーン上の表示領域をビューポートの大きさに比例させる
  glOrtho(-w / 200.0, w / 200.0, -h / 200.0, h / 200.0, -1.0, 1.0);
}
