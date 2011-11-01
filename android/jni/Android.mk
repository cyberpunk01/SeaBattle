LOCAL_PATH := $(call my-dir)


include $(CLEAR_VARS)
LOCAL_MODULE    := seabattle
LOCAL_SRC_FILES := Native.cpp MainApplication.cpp

LOCAL_SRC_FILES += ../../src/AIPlayer.cpp 
LOCAL_SRC_FILES += ../../src/HumanPlayer.cpp 
LOCAL_SRC_FILES += ../../src/Player.cpp
LOCAL_SRC_FILES += ../../src/Ship.cpp
LOCAL_SRC_FILES += ../../src/BattleField.cpp

LOCAL_C_INCLUDES+= $(LOCAL_PATH)/
LOCAL_C_INCLUDES+= $(LOCAL_PATH)/../../include
LOCAL_LDLIBS    := -llog -lz 
include $(BUILD_SHARED_LIBRARY)
