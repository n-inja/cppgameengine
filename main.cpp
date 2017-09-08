#include <iostream>
#include <stdio.h>
#include <GL/glut.h>

void keyboard(unsigned char key, int x, int y);
void display(void);
void resize(int w, int h);
void mouse(int button, int state, int x, int y);

class Mouse {
private:
  static int x, y, button, state;
  Mouse();
  ~Mouse();
public:
  static void func(int _button, int _state, int _x, int _y) {
    button = _button;
    state = _state;
    x = _x;
    y = _y;
  }
  static void print() {
    printf("%d %d %d %d", x, y, state, button);
  }
};

int Mouse::button = 0;
int Mouse::state = 0;
int Mouse::x = 0;
int Mouse::y = 0;

Mouse::Mouse() {}
Mouse::~Mouse() {}

int main(int argc, char** argv) {

  Mouse::print();
  Mouse::func(10, 10, 10, 10);
  Mouse::print();
  glutInit(&argc, argv);
  glutCreateWindow("GLUT Test");
  glutKeyboardFunc(&keyboard);
  glutDisplayFunc(&display);
  glutReshapeFunc(&resize);
  glutMouseFunc(&mouse);
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

void mouse(int button, int state, int x, int y) {
  printf("button : %d, state : %d, x : %d, y : %d\n", button, state, x, y);
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
