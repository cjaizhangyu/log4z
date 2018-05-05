//
// Created by j.chen on 2018/5/5.
//

#ifndef SMARTHOME_JNIUTIL_H
#define SMARTHOME_JNIUTIL_H
#include <jni.h>
#include <string>
std::string convertJStringToString(JNIEnv* env, jstring jvalue);
#endif //SMARTHOME_JNIUTIL_H
