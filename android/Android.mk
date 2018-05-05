LOCAL_PATH := $(call my-dir)
SRCS_PATH :=$(LOCAL_PATH)/..
include $(CLEAR_VARS)
LOCAL_MODULE := icatch_log 
LOCAL_SRC_FILES := $(SRCS_PATH)/log4z.cpp
LOCAL_CPPFLAGS := -std=c++11
LOCAL_LDLIBS := -latomic
LOCAL_EXPORT_LDLIBS := -llog -landroid 
include $(BUILD_SHARED_LIBRARY)
