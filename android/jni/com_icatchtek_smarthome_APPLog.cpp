//
// Created by j.chen on 2018/5/4.
//

#include "com_icatchtek_smarthome_APPLog.h"
#include "JniUtil.h"
#include "LogHelper.h"


/*
 * Class:     com_icatchtek_smarthome_APPLog
 * Method:    openLog
 * Signature: (Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_icatchtek_smarthome_APPLog_openLog
        (JNIEnv *, jclass, jstring) {
    return true;
}

/*
 * Class:     com_icatchtek_smarthome_APPLog
 * Method:    writeLogE
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_icatchtek_smarthome_APPLog_writeLogE
        (JNIEnv *env, jclass, jstring jTag, jstring jLog) {
    return LogHelper::instance()->writeLogE(convertJStringToString(env, jTag), convertJStringToString(env, jLog));
}

/*
 * Class:     com_icatchtek_smarthome_APPLog
 * Method:    writeLogW
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_icatchtek_smarthome_APPLog_writeLogW
        (JNIEnv *env, jclass, jstring jTag, jstring jLog) {
    return LogHelper::instance()->writeLogW(convertJStringToString(env, jTag), convertJStringToString(env, jLog));
}

/*
 * Class:     com_icatchtek_smarthome_APPLog
 * Method:    writeLogI
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_icatchtek_smarthome_APPLog_writeLogI
        (JNIEnv *env, jclass, jstring jTag, jstring jLog) {
    return LogHelper::instance()->writeLogI(convertJStringToString(env, jTag), convertJStringToString(env, jLog));
}

