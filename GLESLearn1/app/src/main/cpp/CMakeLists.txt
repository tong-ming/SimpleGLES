# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.18.1)

# Declares and names the project.

project("gleslearn1")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

# from /cpp/..., each *.h file can be found using the prefix of include dir
include_directories(
        include
        include/glm

        examples/HelloTriangle

        utils
)

message(${CMAKE_PROJECT_NAME})
message(${CMAKE_SOURCE_DIR})
message(${CMAKE_SOURCE_DIR})

# this lib
# search and store the path of all *.cpp (source files) into variable src_files.
file(GLOB src_files ALL_SOURCE
        ${CMAKE_SOURCE_DIR}/*.cpp

        ${CMAKE_SOURCE_DIR}/*/*.cpp

        ${CMAKE_SOURCE_DIR}/*/*/*.cpp

        ${CMAKE_SOURCE_DIR}/*/*/*/*.cpp

        ${CMAKE_SOURCE_DIR}/*/*/*/*/*.cpp

        ${CMAKE_SOURCE_DIR}/*/*/*/*/*/*.cpp

        ${CMAKE_SOURCE_DIR}/*/*/*/*/*/*/*.cpp
        )

add_library( # Sets the name of the library.
        gleslearn1
        SHARED
        ${src_files})

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# third-party libs


# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.
target_link_libraries( # Specifies the target library.
        gleslearn1
        GLESv3
        android
        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})