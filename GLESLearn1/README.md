# Hello Triangle

# Solved

- NDK+Java渲染框架编写
抽象类 BaseGLActivity.java // 获取重写的MyRenderer和MySurfaceView，执行setContentView(mGLSurfaceView)
子类 HelloTriangleActivity.java // 重写抽象方法getRenderer()和getSurfaceView()，返回HelloTriangleRenderer对象
构建新Renderer类：HelloTriangleRenderer implements GLSurfaceView.Renderer，重写三个渲染方法，具体由Native方法执行。

- 简单的OpenglES接口使用
不赘述

- Cmakelists 书写语法
大致分为以下几个步骤
1. 规定cmake版本，设定项目名

cmake_minimum_required(...),project("...")
2. 设定头文件路径

include_directories(...)
3. 编译当前项目中的源文件为静态库或动态库

file(GLOB SourcePathVar ALL_SOURCE ...) // 将搜索到的所有源文件路径存入VAR

add_library( // 编译源文件为指定库
<LibName>
STATIC|SHARED
SourcePathVar
)
4. 添加第三方库

set(ThirdPartyVAR "${CMAKE_SOURCE_DIR}/../thirdPartyLibs")
add_library(<ThirdPartyName>
STATIC|SHARED
IMPORTED
)

set_target_properties(<ThirdPartyName>
        PROPERTIES
        IMPORTED_LOCATION
        ${ThirdPartyVAR}/${CMAKE_ANDROID_ARCH_ABI}/<lib-file>)
5. 链接

target_link_libraries(
<LibName>
<ThirdPartyName>
...
)
 
# Problem
没有MVP，翻转屏幕三角形大小变化
没有texture


