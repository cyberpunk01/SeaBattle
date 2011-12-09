#include <jni.h>
#include <android/log.h>
#include <time.h>
#include <stdlib.h>

#define  LOG_TAG    "SeaBattle"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGW(...)  __android_log_print(ANDROID_LOG_WARN,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

#include "MainApplication.h"

extern "C" {
	JNIEXPORT void JNICALL Java_com_seabattle_Native_Init(JNIEnv* env, jobject obj);
	JNIEXPORT int  JNICALL Java_com_seabattle_Native_Shoot(JNIEnv* env, jobject obj, jint x, jint y);
	JNIEXPORT int  JNICALL Java_com_seabattle_Native_AIShoot(JNIEnv* env, jobject obj);
	JNIEXPORT void JNICALL Java_com_seabattle_Native_SetEasyGame(JNIEnv* env, jboolean level);
	JNIEXPORT void JNICALL Java_com_seabattle_Native_GetField(JNIEnv* env, jobject obj, jintArray data, jboolean player);
}

static MainApplication* app = NULL;
	
JNIEXPORT void JNICALL Java_com_seabattle_Native_Init(JNIEnv* env, jobject obj)
{
//TODO app already initialized after first launch (between different launchs)
//    if (NULL == app)
    {
        LOGI("INIT native main -------- \n");
        srand (time(NULL));
    	app = new MainApplication();
    }
}

JNIEXPORT int JNICALL Java_com_seabattle_Native_Shoot(JNIEnv* env, jobject obj, jint x, jint y)
{
	return (jint)app->Shoot(x, y);
}

JNIEXPORT int JNICALL Java_com_seabattle_Native_AIShoot(JNIEnv* env, jobject obj)
{
	return (jint)app->AIShoot();
}

JNIEXPORT void JNICALL Java_com_seabattle_Native_GetField(JNIEnv* env, jobject obj, jintArray data, jboolean player)
{
    jint* field = (jint*) app->GetFieldArray(player);
	env->SetIntArrayRegion(data, 0, 100, field);
}

JNIEXPORT void JNICALL Java_com_seabattle_Native_SetEasyGame(JNIEnv* env, jboolean level)
{
    app->SetEasyGame(level);
}
