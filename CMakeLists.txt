#/****************************************************************************
# Copyright (c) 2013-2014 cocos2d-x.org
# Copyright (c) 2015-2017 Chukong Technologies Inc.
#
# http://www.cocos2d-x.org
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
# ****************************************************************************/

cmake_minimum_required(VERSION 3.6)

set(APP_NAME cocos2dx)

project(${APP_NAME})

include(AndroidNdkModules)
android_ndk_import_module_cpufeatures()

include_directories(D:/~/Mycocos/cocos2dx/cricket/1.6.7/inc)

link_directories(D:/~/Mycocos/cocos2dx/cricket/1.6.7/lib/android/ndk/${ANDROID_ABI}/debug)

link_libraries(D:/~/Mycocos/cocos2dx/cricket/1.6.7/lib/android/ndk/${ANDROID_ABI}/debug/libck.a)

set(COCOS2DX_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cocos2d)
set(CMAKE_MODULE_PATH ${COCOS2DX_ROOT_PATH}/cmake/Modules/)

include(CocosBuildSet)
add_subdirectory(${COCOS2DX_ROOT_PATH}/cocos ${ENGINE_BINARY_PATH}/cocos/core)

# record sources, headers, resources...
set(GAME_SOURCE)
set(GAME_HEADER)

set(GAME_RES_FOLDER
    "${CMAKE_CURRENT_SOURCE_DIR}/Resources"
    )
if(APPLE OR WINDOWS)
    cocos_mark_multi_resources(common_res_files RES_TO "Resources" FOLDERS ${GAME_RES_FOLDER})
endif()

# add cross-platforms source files and header files 
list(APPEND GAME_SOURCE
     Classes/AppDelegate.cpp
     Classes/HelloWorldScene.cpp
     Classes/AnimCtl.cpp
     Classes/EffectCtl.cpp
     Classes/GameScene.cpp
     Classes/MoveCtl.cpp
     Classes/SoundCtl.cpp
     Classes/input/OPRT_KEY.cpp
     Classes/input/OPRT_TOUCH.cpp
     Classes/debug/_DebugConOut.cpp
     Classes/debug/_DebugGraph.cpp
     Classes/Effekseer/Effekseer.cpp
     Classes/Effekseer/EffekseerNative.cpp
     Classes/Effekseer/EffekseerRendererNative.cpp
     Classes/mojule/check/CheckHitObj.cpp
     Classes/mojule/check/CheckKeyData.cpp
     Classes/mojule/check/CheckList.cpp
     Classes/mojule/move/MovIdle.cpp
     Classes/mojule/move/MovLR.cpp
     Classes/mojule/move/MovJump.cpp
     Classes/mojule/move/MovFall.cpp
     Classes/unit/Obj.cpp
     Classes/unit/player.cpp
     Classes/unit/Enemy.cpp
     cricket/1.6.7//lib/win/vs15.0/x86/DebugDynamic/ck.lib
     )
list(APPEND GAME_HEADER
     Classes/AppDelegate.h
     Classes/HelloWorldScene.h
     Classes/AnimCtl.h
     Classes/EffectCtl.h
     Classes/GameScene.h
     Classes/MojuleHeader.h
     Classes/MoveCtl.h
     Classes/SoundCtl.h
     Classes/input/OPRT.h
     Classes/input/OPRT_KEY.h
     Classes/input/OPRT_TOUCH.h
     Classes/debug/_DebugConOut.h
     Classes/debug/_DebugGraph.h
     Classes/Effekseer/Effekseer.h
     Classes/Effekseer/EffekseerNative.h
     Classes/Effekseer/EffekseerRendererNative.h
     Classes/mojule/check/CheckHitObj.h
     Classes/mojule/check/CheckKeyData.h
     Classes/mojule/check/CheckList.h
     Classes/mojule/move/MovIdle.h
     Classes/mojule/move/MovLR.h
     Classes/mojule/move/MovJump.h
     Classes/mojule/move/MovFall.h
     Classes/unit/Obj.h
     Classes/unit/player.h
     Classes/unit/Enemy.h
     cricket/1.6.7/inc/ck/ck.h
     cricket/1.6.7/inc/ck/attenuationmode.h
     cricket/1.6.7/inc/ck/bank.h
     cricket/1.6.7/inc/ck/config.h
     cricket/1.6.7/inc/ck/customfile.h
     cricket/1.6.7/inc/ck/customstream.h
     cricket/1.6.7/inc/ck/effect.h
     cricket/1.6.7/inc/ck/effectbus.h
     cricket/1.6.7/inc/ck/effectparam.h
     cricket/1.6.7/inc/ck/effectprocessor.h
     cricket/1.6.7/inc/ck/effecttype.h
     cricket/1.6.7/inc/ck/mixer.h
     cricket/1.6.7/inc/ck/pathtype.h
     cricket/1.6.7/inc/ck/platform.h
     cricket/1.6.7/inc/ck/sound.h

     )

if(ANDROID)
    # change APP_NAME to the share library name for Android, it's value depend on AndroidManifest.xml
    set(APP_NAME MyGame)
    list(APPEND GAME_SOURCE
         proj.android/app/jni/hellocpp/main.cpp
         )
elseif(LINUX)
    list(APPEND GAME_SOURCE
         proj.linux/main.cpp
         )
elseif(WINDOWS)
    list(APPEND GAME_HEADER
         proj.win32/main.h
         proj.win32/resource.h
         )
    list(APPEND GAME_SOURCE
         proj.win32/main.cpp
         proj.win32/game.rc
         ${common_res_files}
         )
elseif(APPLE)
    if(IOS)
        list(APPEND GAME_HEADER
             proj.ios_mac/ios/AppController.h
             proj.ios_mac/ios/RootViewController.h
             )
        set(APP_UI_RES
            proj.ios_mac/ios/LaunchScreen.storyboard
            proj.ios_mac/ios/LaunchScreenBackground.png
            proj.ios_mac/ios/Images.xcassets
            )
        list(APPEND GAME_SOURCE
             proj.ios_mac/ios/main.m
             proj.ios_mac/ios/AppController.mm
             proj.ios_mac/ios/RootViewController.mm
             proj.ios_mac/ios/Prefix.pch
             ${APP_UI_RES}
             )
    elseif(MACOSX)
        set(APP_UI_RES
            proj.ios_mac/mac/Icon.icns
            proj.ios_mac/mac/Info.plist
            )
        list(APPEND GAME_SOURCE
             proj.ios_mac/mac/main.cpp
             proj.ios_mac/mac/Prefix.pch
             ${APP_UI_RES}
             )
    endif()
    list(APPEND GAME_SOURCE ${common_res_files})
endif()

# mark app complie info and libs info
set(all_code_files
    ${GAME_HEADER}
    ${GAME_SOURCE}
    )
if(NOT ANDROID)
    add_executable(${APP_NAME} ${all_code_files})
else()
    add_library(${APP_NAME} SHARED ${all_code_files})
    add_subdirectory(${COCOS2DX_ROOT_PATH}/cocos/platform/android ${ENGINE_BINARY_PATH}/cocos/platform)
    target_link_libraries(${APP_NAME} -Wl,--whole-archive cpp_android_spec -Wl,--no-whole-archive)
endif()

target_link_libraries(${APP_NAME} cocos2d)
target_include_directories(${APP_NAME}
        PRIVATE Classes
        PRIVATE ${COCOS2DX_ROOT_PATH}/cocos/audio/include/
)

# mark app resources
setup_cocos_app_config(${APP_NAME})
if(APPLE)
    set_target_properties(${APP_NAME} PROPERTIES RESOURCE "${APP_UI_RES}")
    if(MACOSX)
        set_target_properties(${APP_NAME} PROPERTIES
                              MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_SOURCE_DIR}/proj.ios_mac/mac/Info.plist"
                              )
    elseif(IOS)
        cocos_pak_xcode(${APP_NAME} INFO_PLIST "iOSBundleInfo.plist.in")
        set_xcode_property(${APP_NAME} ASSETCATALOG_COMPILER_APPICON_NAME "AppIcon")
        set_xcode_property(${APP_NAME} DEVELOPMENT_TEAM "")
        set_xcode_property(${APP_NAME} CODE_SIGN_IDENTITY "iPhone Developer")
    endif()
elseif(WINDOWS)
    cocos_copy_target_dll(${APP_NAME})
endif()

if(LINUX OR WINDOWS)
    set(APP_RES_DIR "$<TARGET_FILE_DIR:${APP_NAME}>/Resources")
    cocos_copy_target_res(${APP_NAME} COPY_TO ${APP_RES_DIR} FOLDERS ${GAME_RES_FOLDER})
endif()
