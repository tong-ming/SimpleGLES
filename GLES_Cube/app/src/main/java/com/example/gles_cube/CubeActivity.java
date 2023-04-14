package com.example.gles_cube;

import android.content.res.AssetManager;
import android.opengl.GLSurfaceView;

public class CubeActivity extends BaseActivity {
    public GLSurfaceView.Renderer renderer;
    public GLSurfaceView view;
    public AssetManager asset_mrg;

    @Override
    protected GLSurfaceView.Renderer getRenderer() {
        renderer = new CubeRenderer(this);
        return renderer;
    }

    @Override
    protected GLSurfaceView getSurfaceView() {
        view = new GLSurfaceView(this);
        return view;
    }

//    @Override
//    protected AssetManager getAssetMrg() {
//        return getResources().getAssets();
//    }

}