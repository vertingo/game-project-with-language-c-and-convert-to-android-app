#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring

JNICALL
Java_com_vertin_1go_android_1c_1c_1game_1project_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
