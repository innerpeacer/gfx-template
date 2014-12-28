#ifndef TEMPLATEAPP_H
#define TEMPLATEAPP_H

#ifdef __IPHONE_4_0

	#include "gfx.h"
#else

	#include "../../../common/gfx.h"
#endif



typedef struct
{
void (*Init)(int width, int height);
void (*Draw)(void);
void (*ToucheBegan)(float x, float y, unsigned int tap_count);
void (*ToucheMoved)(float x, float y, unsigned int tap_count);
void (*ToucheEnded)(float x, float y, unsigned int tap_count);
void (*Accelerometer)(float x, float y, float z);
} TEMPLATEAPP;

extern TEMPLATEAPP templateApp;

void templateAppInit(int width, int height);
void templateAppDraw(void);
void templateAppToucheBegan(float x, float y, unsigned int tap_count);
void templateAppToucheMoved(float x, float y, unsigned int tap_count);
void templateAppToucheEnded(float x, float y, unsigned int tap_count);
void templateAppToucheCancelled(float x, float y, unsigned int tap_count);
void templateAppAccelerometer(float x, float y, float z);
void templateAppExit(void);


	#ifndef __IPHONE_4_0

		extern "C"
		{
			JNIEXPORT void JNICALL Java_com_android_templateApp_GL2View_Init(JNIEnv *env, jobject obj, jint width, jint height, jstring apkFilePath );
			JNIEXPORT void JNICALL Java_com_android_templateApp_GL2View_Draw(JNIEnv *env, jobject obj);
			JNIEXPORT void JNICALL Java_com_android_templateApp_GL2View_ToucheBegan(JNIEnv *env, jobject obj, jfloat x, jfloat y, jint tap_count);
			JNIEXPORT void JNICALL Java_com_android_templateApp_GL2View_ToucheMoved(JNIEnv *env, jobject obj, jfloat x, jfloat y, jint tap_count);
			JNIEXPORT void JNICALL Java_com_android_templateApp_GL2View_ToucheEnded(JNIEnv *env, jobject obj, jfloat x, jfloat y, jint tap_count);
			JNIEXPORT void JNICALL Java_com_android_templateApp_templateApp_Accelerometer(JNIEnv *env, jobject obj, jfloat x, jfloat y, jfloat z);
		};

		JNIEXPORT void JNICALL Java_com_android_templateApp_GL2View_Init(JNIEnv *env, jobject obj, jint width, jint height, jstring apkFilePath)
		{
			setenv( "FILESYSTEM", env->GetStringUTFChars(apkFilePath, NULL), 1);
			if(templateApp.Init) templateApp.Init(width, height);
		}

		JNIEXPORT void JNICALL Java_com_android_templateApp_GL2View_Draw(JNIEnv *env, jobject obj)
		{
            if(templateApp.Draw) templateApp.Draw();
        }

		JNIEXPORT void JNICALL Java_com_android_templateApp_GL2View_ToucheBegan(JNIEnv *env, jobject obj, jfloat x, jfloat y, jint tap_count)
		{
            if(templateApp.ToucheBegan) templateApp.ToucheBegan(x, y, tap_count);
        }

		JNIEXPORT void JNICALL Java_com_android_templateApp_GL2View_ToucheMoved(JNIEnv *env, jobject obj, jfloat x, jfloat y, jint tap_count)
		{
            if(templateApp.ToucheMoved) templateApp.ToucheMoved(x, y, tap_count);
        }

		JNIEXPORT void JNICALL Java_com_android_templateApp_GL2View_ToucheEnded(JNIEnv *env, jobject obj, jfloat x, jfloat y, jint tap_count)
		{
            if(templateApp.ToucheEnded) templateApp.ToucheEnded(x, y, tap_count);
        }

		JNIEXPORT void JNICALL Java_com_android_templateApp_templateApp_Accelerometer(JNIEnv *env, jobject obj, jfloat x, jfloat y, jfloat z)
		{
            if(templateApp.Accelerometer) templateApp.Accelerometer(x, y, z);
        }

	#endif

#endif
