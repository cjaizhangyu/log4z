LOCAL_PATH := $(call my-dir)
SRCS_PATH :=$(LOCAL_PATH)/..
JNI_PATH :=$(LOCAL_PATH)/jni
CXX_PATH :=$(LOCAL_PATH)/c++
INC_DIR := $(SRCS_PATH)/ $(CXX_PATH)/ $(JNI_PATH)/


include $(CLEAR_VARS)
LOCAL_MODULE := icatchtek_log 
LOCAL_SRC_FILES := $(SRCS_PATH)/log4z.cpp
LOCAL_SRC_FILES += $(CXX_PATH)/LogHelper.cpp
LOCAL_SRC_FILES += $(CXX_PATH)/LogSet.cpp
LOCAL_SRC_FILES += $(JNI_PATH)/com_icatchtek_smarthome_APPLog.cpp
LOCAL_SRC_FILES += $(JNI_PATH)/com_icatchtek_smarthome_LogConfig.cpp
LOCAL_SRC_FILES += $(JNI_PATH)/JniUtil.cpp

LOCAL_C_INCLUDES:= $(INC_DIR)
LOCAL_CPPFLAGS := -std=c++11
LOCAL_LDLIBS := -latomic -llog 
LOCAL_EXPORT_LDLIBS := -landroid 
include $(BUILD_SHARED_LIBRARY)
