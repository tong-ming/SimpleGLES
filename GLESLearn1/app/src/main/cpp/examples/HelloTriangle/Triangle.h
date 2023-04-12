//
// Created by yiwedai on 4/6/2023.
//
#include <GLES3/gl3.h>
#include <GLES3/gl3ext.h>
#include <GLUtils.h>

#ifndef GLESLEARN1_TRIANGLE_H
#define GLESLEARN1_TRIANGLE_H

class Triangle {
public:
    Triangle();
    ~Triangle();

    void Create();

    void Change(int width, int height);

    void Draw();

private:
    GLuint m_ProgramObj;
    int mwidth;
    int mheight;
    GLuint VBO, VAO;
};


#endif //GLESLEARN1_TRIANGLE_H
