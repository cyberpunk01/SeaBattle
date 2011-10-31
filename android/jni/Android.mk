LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE    := seabattle
LOCAL_SRC_FILES := Native.cpp MainApplication.cpp
LOCAL_LDLIBS    := -llog -lGLESv2 -lz 
include $(BUILD_SHARED_LIBRARY)
