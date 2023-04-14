//
// Created by yiwedai on 4/12/2023.
//

#include <jni.h>
#include <string>
#include <Cube.h>
#include <GLUtils.h>

Cube *pDemo = nullptr;

extern "C"
JNIEXPORT void JNICALL
Java_com_example_gles_1cube_NativeImpl_nativeSurfaceCreate(JNIEnv *env, jclass clazz, jobject assetManager) {
    // TODO: implement nativeSurfaceCreate()
    if (!pDemo){
        pDemo = new Cube();
    }
    GLUtils::setEnvAndAssetManager(env, assetManager);
    pDemo->Create();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_gles_1cube_NativeImpl_nativeSurfaceChange(JNIEnv *env, jclass clazz, jint width,
                                                           jint height) {
    // TODO: implement nativeSurfaceChange()
    if (pDemo){
        pDemo->Change(width, height);
    }
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_gles_1cube_NativeImpl_nativeDrawFrame(JNIEnv *env, jclass clazz) {
    // TODO: implement nativeDrawFrame()
    if (pDemo){
        pDemo->Draw();
    }
}
