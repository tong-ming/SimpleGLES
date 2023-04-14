//
// Created by yiwedai on 4/14/2023.
//

#ifndef GLES_CUBE_TIMEUTILS_H
#define GLES_CUBE_TIMEUTILS_H

#include <sys/time.h>

class TimeUtils{

public:
    static long currentTimeMillis() {
        struct timeval tv {};
        gettimeofday(&tv, (struct timezone*) nullptr);
        return tv.tv_sec * 1000 + tv.tv_usec / 1000;
    }
};

#endif //GLES_CUBE_TIMEUTILS_H
