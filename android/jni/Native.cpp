#include <jni.h>
#include <android/log.h>

#define  LOG_TAG    "SeaBattle"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGW(...)  __android_log_print(ANDROID_LOG_WARN,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

#include "MainApplication.h"

extern "C" {
	JNIEXPORT void 		JNICALL Java_com_seabattle_Native_Init(JNIEnv* env, jobject obj);
	JNIEXPORT jint 		JNICALL Java_com_seabattle_Native_Shoot(JNIEnv* env, jobject obj, jint x, jint y);
	JNIEXPORT jint 		JNICALL Java_com_seabattle_Native_AIShoot(JNIEnv* env, jobject obj);
	JNIEXPORT jintArray JNICALL Java_com_seabattle_Native_GetField(JNIEnv* env, jobject obj);
}

static MainApplication* app = 0;
	
JNIEXPORT void JNICALL Java_com_seabattle_Native_Init(JNIEnv* env, jobject obj)
{
	app = new MainApplication();
}

JNIEXPORT jint JNICALL Java_com_seabattle_Native_Shoot(JNIEnv* env, jobject obj, jint x, jint y)
{
	return (jint)app->Shoot(x, y);
}

JNIEXPORT jint JNICALL Java_com_seabattle_Native_AIShoot(JNIEnv* env, jobject obj)
{
	return (jint)app->AIShoot();
}

JNIEXPORT jintArray JNICALL Java_com_seabattle_Native_GetField(JNIEnv* env, jobject obj)
{
	jintArray data;
	LOGI("Try to get array region");
	env->SetIntArrayRegion(data, 0, 100, (jint *)app->GetFieldArray());
	LOGI("Got Array region");
	return data;
}
