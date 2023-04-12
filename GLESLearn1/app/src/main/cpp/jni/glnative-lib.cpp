//
// Created by yiwedai on 4/6/2023.
//

#include <jni.h>
#include <string>
#include "Triangle.h"

Triangle* pDemo = nullptr;

extern "C"
JNIEXPORT void JNICALL
Java_com_example_gleslearn1_NativeImpl_nativeSurfaceCreate(JNIEnv *env, jclass clazz) {
    if (!pDemo){
        pDemo = new Triangle();
    }
    pDemo->Create();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_gleslearn1_NativeImpl_nativeSurfaceChange(JNIEnv *env, jclass clazz, jint width, jint height) {
    if (pDemo){
        pDemo->Change(width, height);
    }
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_gleslearn1_NativeImpl_nativeDrawFrame(JNIEnv *env, jclass clazz) {
    if (pDemo){
        pDemo->Draw();
    }
}