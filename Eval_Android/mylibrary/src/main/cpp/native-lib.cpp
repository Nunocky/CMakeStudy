#include <jni.h>
#include <X/libX.h>
#include <Y/libY.h>

// --------------------------------------------------------------------------------
extern "C"
JNIEXPORT jstring JNICALL
Java_org_nunocky_mylibrary_MyLibrary_greetingX(JNIEnv *env, jclass clazz) {
    std::string str = X::greeting();
    return env->NewStringUTF(str.c_str());
}

// --------------------------------------------------------------------------------
extern "C"
JNIEXPORT jstring JNICALL
Java_org_nunocky_mylibrary_MyLibrary_greetingY(JNIEnv *env, jclass clazz) {
    std::string str = Y::greeting();
    return env->NewStringUTF(str.c_str());
}
