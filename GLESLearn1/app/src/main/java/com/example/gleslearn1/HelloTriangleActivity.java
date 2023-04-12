package com.example.gleslearn1;

import android.opengl.GLSurfaceView;

public class HelloTriangleActivity extends BaseGLActivity {
    public GLSurfaceView.Renderer renderer;
    public GLSurfaceView view;

    @Override
    protected GLSurfaceView.Renderer getRenderer() {
        renderer = new HelloTriangleRenderer();
        return renderer;
    }

    @Override
    protected GLSurfaceView getSurfaceView() {
        view = new GLSurfaceView(this);
        return view;
    }
}
