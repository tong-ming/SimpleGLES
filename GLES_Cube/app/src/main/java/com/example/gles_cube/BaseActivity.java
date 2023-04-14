package com.example.gles_cube;
import android.content.res.AssetManager;
import android.opengl.GLSurfaceView;
import android.app.Activity;
import android.os.Bundle;
import androidx.annotation.Nullable;


public abstract class BaseActivity extends Activity{
    protected GLSurfaceView mGLSurfaceView;
    protected GLSurfaceView.Renderer mrenderer;

    protected abstract GLSurfaceView.Renderer getRenderer();
    protected abstract GLSurfaceView getSurfaceView();
//    protected abstract AssetManager getAssetMrg();

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
        // set app's content view
        mrenderer = getRenderer();
        mGLSurfaceView = getSurfaceView();
        mGLSurfaceView.setEGLContextClientVersion(3);
        mGLSurfaceView.setRenderer(mrenderer);
        setContentView(mGLSurfaceView);
    }

    @Override
    protected void onResume(){
        super.onResume();
        mGLSurfaceView.onResume();
    }

    @Override
    protected void onPause(){
        super.onPause();
        mGLSurfaceView.onPause();
    }

}