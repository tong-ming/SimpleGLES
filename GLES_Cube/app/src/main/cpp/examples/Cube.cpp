//
// Created by yiwedai on 4/13/2023.
//

#include "Cube.h"

Cube::Cube() {
    mLastTime = 0;
    angle = 0;
}

Cube::~Cube() {

}

float cube_vertices[] = {
        -0.5, -0.5, -0.5, 0.0, 0.0, -1.0,
        0.5, -0.5, -0.5, 0.0, 0.0, -1.0,
        0.5, 0.5, -0.5, 0.0, 0.0, -1.0,
        0.5, 0.5, -0.5, 0.0, 0.0, -1.0,
        -0.5, 0.5, -0.5, 0.0, 0.0, -1.0,
        -0.5, -0.5, -0.5, 0.0, 0.0, -1.0,

        -0.5, -0.5, 0.5, 0.0, 0.0, 1.0,
        0.5, -0.5, 0.5, 0.0, 0.0, 1.0,
        0.5, 0.5, 0.5, 0.0, 0.0, 1.0,
        0.5, 0.5, 0.5, 0.0, 0.0, 1.0,
        -0.5, 0.5, 0.5, 0.0, 0.0, 1.0,
        -0.5, -0.5, 0.5, 0.0, 0.0, 1.0,

        -0.5, 0.5, 0.5, -1.0, 0.0, 0.0,
        -0.5, 0.5, -0.5, -1.0, 0.0, 0.0,
        -0.5, -0.5, -0.5, -1.0, 0.0, 0.0,
        -0.5, -0.5, -0.5, -1.0, 0.0, 0.0,
        -0.5, -0.5, 0.5, -1.0, 0.0, 0.0,
        -0.5, 0.5, 0.5, -1.0, 0.0, 0.0,

        0.5, 0.5, 0.5, 1.0, 0.0, 0.0,
        0.5, 0.5, -0.5, 1.0, 0.0, 0.0,
        0.5, -0.5, -0.5, 1.0, 0.0, 0.0,
        0.5, -0.5, -0.5, 1.0, 0.0, 0.0,
        0.5, -0.5, 0.5, 1.0, 0.0, 0.0,
        0.5, 0.5, 0.5, 1.0, 0.0, 0.0,

        -0.5, -0.5, -0.5, 0.0, -1.0, 0.0,
        0.5, -0.5, -0.5, 0.0, -1.0, 0.0,
        0.5, -0.5, 0.5, 0.0, -1.0, 0.0,
        0.5, -0.5, 0.5, 0.0, -1.0, 0.0,
        -0.5, -0.5, 0.5, 0.0, -1.0, 0.0,
        -0.5, -0.5, -0.5, 0.0, -1.0, 0.0,

        -0.5, 0.5, -0.5, 0.0, 1.0, 0.0,
        0.5, 0.5, -0.5, 0.0, 1.0, 0.0,
        0.5, 0.5, 0.5, 0.0, 1.0, 0.0,
        0.5, 0.5, 0.5, 0.0, 1.0, 0.0,
        -0.5, 0.5, 0.5, 0.0, 1.0, 0.0,
        -0.5, 0.5, -0.5, 0.0, 1.0, 0.0,
};

void Cube::Create() {
    glEnable(GL_DEPTH_TEST);

    // cube program
    const char* vertex_shader = GLUtils::openTextFile("shader/cube.vert");
    const char* fragment_shader = GLUtils::openTextFile("shader/cube.frag");
    m_ProgramObj = GLUtils::createProgram(&vertex_shader, &fragment_shader);
    if (!m_ProgramObj) {
        LOGD("Could not Create program");
        return;
    }

    // lightning program
    vertex_shader = GLUtils::openTextFile("shader/light.vert");
    fragment_shader = GLUtils::openTextFile("shader/light.frag");
    light_ProgramObj = GLUtils::createProgram(&vertex_shader, &fragment_shader);
    if (!light_ProgramObj) {
        LOGD("Could not Create program");
        return;
    }

    // cube
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cube_vertices), cube_vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // light
    glGenVertexArrays(1, &lightVAO);
    glBindVertexArray(lightVAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cube_vertices), cube_vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glClearColor(1.0, 0.5, 1.0, 1.0);

}

void Cube::Change(int width, int height) {
    mwidth = width;
    mheight = height;
    LOGD("Change() width = %d, height = %d\n", width, height);
    glViewport(0, 0, mwidth, mheight);
}

glm::vec3 lightPos(0.0, 0.0, 1.5);
glm::vec3 viewPos(0, 3, 10);

void Cube::Draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // update angle
    float deltaTime = getDeltaTime();
    angle += (deltaTime);
    if (angle >= 360.0f) {
        angle -= 360.0f;
    }

//    // cube
    glUseProgram(m_ProgramObj);
//
    model = glm::mat4(1.0f);
    view = glm::mat4(1.0f);
    projection = glm::mat4(1.0f);

//    model = glm::rotate(model, glm::radians(45.0f), glm::vec3(-1.5, 0.7, 1.0));
    model = glm::rotate(model, angle, glm::vec3(-1.5, 0.7, 1.0));
//    view = glm::translate(view, glm::vec3(0.0, 0.0, 3.0));

    view = glm::lookAt(
            viewPos, // Camera is at (0,0,1), in World Space
            glm::vec3(0, 0, 0), // and looks at the origin
            glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
    );
    projection = glm::perspective(glm::radians(45.0f), (float)mwidth/(float)mheight, 9.0f, -40.0f);// 移动近平面与远平面不改变看到的物体形状和大小，仅改变是否看得见

    unsigned int modelLoc = glGetUniformLocation(m_ProgramObj, "model");
    unsigned int viewLoc = glGetUniformLocation(m_ProgramObj, "view");
    unsigned int projLoc = glGetUniformLocation(m_ProgramObj, "projection");
    unsigned int lightPosLoc = glGetUniformLocation(m_ProgramObj, "lightPos");
    unsigned int lightColorLoc = glGetUniformLocation(m_ProgramObj, "lightColor");
    unsigned int ObjColorLoc = glGetUniformLocation(m_ProgramObj, "ObjColor");
    unsigned int viewPosLoc = glGetUniformLocation(m_ProgramObj, "viewPos");
    glUniform3fv(lightPosLoc, 1, &lightPos[0]);
    glUniform3fv(viewPosLoc, 1, &viewPos[0]);
    glUniform3f(lightColorLoc, 1.0, 1.0, 1.0);
    glUniform3f(ObjColorLoc, 1.0, 0.5, 0.31);
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);

    // lightning
    glUseProgram(light_ProgramObj);

    model = glm::mat4(1.0f);
    model = glm::translate(model, lightPos);
    model = glm::scale(model, glm::vec3(0.1f)); // a smaller cube

    modelLoc = glGetUniformLocation(light_ProgramObj, "model");
    viewLoc = glGetUniformLocation(light_ProgramObj, "view");
    projLoc = glGetUniformLocation(light_ProgramObj, "projection");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

    glBindVertexArray(lightVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);

}
float Cube::getDeltaTime() {
    if (mLastTime == 0) {
        mLastTime = TimeUtils::currentTimeMillis();
    }
    long currentTime = TimeUtils::currentTimeMillis();
    long elapsedTime = currentTime - mLastTime;
    float deltaTime = (float) elapsedTime / 1000.0f;
    mLastTime = currentTime;
    return deltaTime;
}