#include <jni.h>
#include <android/log.h>

#include "MainApplication.h"

extern "C" {
	JNIEXPORT void JNICALL Java_com_seabattle_Native_Init(JNIEnv* env, jobject obj);
	JNIEXPORT int JNICALL Java_com_seabattle_Native_Shoot(JNIEnv* env, jobject obj, jint x, jint y);
	JNIEXPORT int JNICALL Java_com_seabattle_Natives_AIShoot(JNIEnv* env, jobject obj);
}

static MainApplication* app = 0;
	
JNIEXPORT void JNICALL Java_com_seabattle_Native_Init(JNIEnv* env, jobject obj)
{

	app = new MainApplication();
}

JNIEXPORT int JNICALL Java_com_seabattle_Native_Shoot(JNIEnv* env, jobject obj, jint x, jint y)
{
	return (jint)app->Shoot(x, y);
}

JNIEXPORT int JNICALL Java_com_seabattle_Native_AIShoot(JNIEnv* env, jobject obj)
{
	return (jint)app->AIShoot();
}
