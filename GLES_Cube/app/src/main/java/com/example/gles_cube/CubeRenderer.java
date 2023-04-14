package com.example.gles_cube;

import android.app.Activity;
import android.content.res.AssetManager;
import android.opengl.GLSurfaceView;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public class CubeRenderer implements GLSurfaceView.Renderer {
    AssetManager asset_mrg;
    static{
        System.loadLibrary("gles_cube");
    }

    public CubeRenderer(Activity activity){
        asset_mrg = activity.getAssets();
    }

    public void setAssetMrg(AssetManager mrg){
        asset_mrg = mrg;
    }

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        NativeImpl.nativeSurfaceCreate(asset_mrg);
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
    public static native void nativeSurfaceCreate(AssetManager mrg);
    public static native void nativeSurfaceChange(int width, int height);
    public static native void nativeDrawFrame();
}