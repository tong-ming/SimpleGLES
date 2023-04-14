//
// Created by yiwedai on 4/13/2023.
//

#ifndef GLES_CUBE_CUBE_H
#define GLES_CUBE_CUBE_H

#include <GLES3/gl3.h>
#include <GLES3/gl3ext.h>
#include <GLUtils.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Cube {
public:
    Cube();
    ~Cube();

    void Create();
    void Change(int width, int height);
    void Draw();

private:
    GLuint m_ProgramObj, light_ProgramObj;
    int mwidth, mheight;
    GLuint VBO, VAO, lightVAO;

};


#endif //GLES_CUBE_CUBE_H
