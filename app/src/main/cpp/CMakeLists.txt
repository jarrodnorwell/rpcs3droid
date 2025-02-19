
# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html.
# For more examples on how to use CMake, see https://github.com/android/ndk-samples.

# Sets the minimum CMake version required for this project.
cmake_minimum_required(VERSION 3.22.1)

# Declares the project name. The project name can be accessed via ${ PROJECT_NAME},
# Since this is the top level CMakeLists.txt, the project name is also accessible
# with ${CMAKE_PROJECT_NAME} (both CMake variables are in-sync within the top level
# build script scope).
set(CMAKE_CXX_STANDARD 20)

project("rpcs3droid")

option(USE_NATIVE_INSTRUCTIONS "USE_NATIVE_INSTRUCTIONS makes rpcs3 compile with -march=native, which is useful for local builds, but not good for packages." ON)
option(WITH_LLVM "Enable usage of LLVM library" OFF)
option(BUILD_LLVM "Build LLVM from git submodule" ON)
option(STATIC_LINK_LLVM "Link against LLVM statically. This will get set to ON if you build LLVM from the submodule." OFF)
option(USE_FAUDIO "FAudio audio backend" ON)
option(USE_LIBEVDEV "libevdev-based joystick support" ON)
option(USE_DISCORD_RPC "Discord rich presence integration" OFF)
option(USE_SYSTEM_ZLIB "Prefer system ZLIB instead of the builtin one" OFF)
option(USE_VULKAN "Vulkan render backend" ON)
option(USE_PRECOMPILED_HEADERS "Use precompiled headers" OFF)
option(USE_SDL "Enables SDL input handler" OFF)
option(USE_SYSTEM_SDL "Prefer system SDL instead of the builtin one" OFF)
option(USE_SYSTEM_FFMPEG "Prefer system ffmpeg instead of the prebuild one" OFF)
option(USE_SYSTEM_OPENAL "Prefer system OpenAL instead of the prebuild one" OFF)
option(USE_SYSTEM_CURL "Prefer system Curl instead of the prebuild one" OFF)
option(USE_SYSTEM_OPENCV "Prefer system OpenCV instead of the builtin one" OFF)
option(USE_LTO "Use LTO for building" ON)

set(OPENSSL_ROOT_DIR "C:/Program Files/FireDaemon OpenSSL 3")
set(OPENSSL_INCLUDE_DIR "C:/Program Files/FireDaemon OpenSSL 3/include")
set(OPENSSL_CRYPTO_LIBRARY "C:/Program Files/FireDaemon OpenSSL 3/lib/libcrypto.lib")
set(OPENSSL_SSL_LIBRARY "C:/Program Files/FireDaemon OpenSSL 3/lib/libssl.lib")

add_subdirectory(3rdparty)
add_subdirectory(Emu)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.
#
# In this top level CMakeLists.txt, ${CMAKE_PROJECT_NAME} is used to define
# the target library name; in the sub-module's CMakeLists.txt, ${PROJECT_NAME}
# is preferred for the same purpose.
#
# In order to load a library into your app from Java/Kotlin, you must call
# System.loadLibrary() and pass the name of the library defined here;
# for GameActivity/NativeActivity derived applications, the same library name must be
# used in the AndroidManifest.xml file.
add_library(${CMAKE_PROJECT_NAME} SHARED rpcs3droid.cpp)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE Emu Loader)

# Specifies libraries CMake should link to your target library. You
# can link libraries from various origins, such as libraries defined in this
# build script, prebuilt third-party libraries, or Android system libraries.
target_link_libraries(${CMAKE_PROJECT_NAME} android log rpcs3_emu)
