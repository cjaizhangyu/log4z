//
// Created by j.chen on 2018/5/5.
//

#include "JniUtil.h"

using namespace std;
string convertJStringToString(JNIEnv* env, jstring jvalue)
{
    /* get string's length and value */
    const char* cvalue = env->GetStringUTFChars(jvalue, 0);

    if (cvalue == NULL) {
        return "";
    }

    /* get value */
    string value = cvalue;

    /* release strings */
    env->ReleaseStringUTFChars(jvalue, cvalue);

    return value;
}