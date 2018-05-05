//
// Created by j.chen on 2018/5/5.
//
#include "com_icatchtek_smarthome_LogConfig.h"
#include "JniUtil.h"
#include "LogSet.h"
/*
 * Class:     com_icatchtek_smarthome_LogConfig
 * Method:    nativeSetPath
 * Signature: (ILjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_icatchtek_smarthome_LogConfig_nativeSetPath
        (JNIEnv *env, jobject, jint jLogType, jstring jPath) {
    return LogSet::instance()->setPath(convertJStringToString(env, jPath));
}

/*
 * Class:     com_icatchtek_smarthome_LogConfig
 * Method:    nativeSetEnable
 * Signature: (IZ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_icatchtek_smarthome_LogConfig_nativeSetEnable
        (JNIEnv *env, jobject, jint jLogType, jboolean jBoolen) {
    return LogSet::instance()->setEnable(jBoolen);
}

/*
 * Class:     com_icatchtek_smarthome_LogConfig
 * Method:    nativeSetOutScreen
 * Signature: (IZ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_icatchtek_smarthome_LogConfig_nativeSetOutScreen
        (JNIEnv *env, jobject, jint jLogType, jboolean jBoolen) {
    return LogSet::instance()->setOutToScreen(jBoolen);

}

/*
 * Class:     com_icatchtek_smarthome_LogConfig
 * Method:    nativeSetOutFile
 * Signature: (IZ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_icatchtek_smarthome_LogConfig_nativeSetOutFile
        (JNIEnv *env, jobject, jint jLogType, jboolean jBoolen) {
    return LogSet::instance()->setOutToFile(jBoolen);
}

/*
 * Class:     com_icatchtek_smarthome_LogConfig
 * Method:    nativeSetLevel
 * Signature: (II)Z
 */
JNIEXPORT jboolean JNICALL Java_com_icatchtek_smarthome_LogConfig_nativeSetLevel
        (JNIEnv *env, jobject, jint jLogType, jint jInt) {
    return LogSet::instance()->setLevel(jInt);
}

/*
 * Class:     com_icatchtek_smarthome_LogConfig
 * Method:    nativeSetFileSize
 * Signature: (II)Z
 */
JNIEXPORT jboolean JNICALL Java_com_icatchtek_smarthome_LogConfig_nativeSetFileSize
        (JNIEnv *, jobject, jint jLogType, jint jSize) {

        return LogSet::instance()->setFileSizeLimit(jSize);
}

/*
 * Class:     com_icatchtek_smarthome_LogConfig
 * Method:    nativeSetLogStart
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_icatchtek_smarthome_LogConfig_nativeSetLogStart
        (JNIEnv *, jobject) {
    return LogSet::instance()->logStart();
}

