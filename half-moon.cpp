#include<GL/glut.h>
#include<Math.h>
void DrawCircle(float cx, float cy, float rx, float ry, int num_segments)
{
    glBegin(GL_TRIANGLE_FAN);
    for (int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = rx * cosf(theta);//calculate the x component
        float y = ry * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}
void display()
{
    glClearColor(1, 1, 1, 1);
    glOrtho(-300, 300, -300, 300, -300, 300);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
    DrawCircle(0, 0, 200, 200, 200);
    glColor3f(1, 1, 1);
    DrawCircle(50, 50, 200, 200, 200);


    glFlush();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Moon");

    glutDisplayFunc(display);
    glutMainLoop();


    return 0;

}