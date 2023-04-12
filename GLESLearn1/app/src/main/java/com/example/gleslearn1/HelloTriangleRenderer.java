package com.example.gleslearn1;

import android.opengl.GLSurfaceView;

import java.lang.annotation.Native;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public class HelloTriangleRenderer implements GLSurfaceView.Renderer {


    static{
//        System.loadLibrary("glnative-lib");
        System.loadLibrary("gleslearn1");
    }

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        NativeImpl.nativeSurfaceCreate();
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        NativeImpl.nativeSurfaceChange(width, height);
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        NativeImpl.nativeDrawFrame();
    }
}

class NativeImpl {
    public static native void nativeSurfaceCreate();
    public static native void nativeSurfaceChange(int width, int height);
    public static native void nativeDrawFrame();
}