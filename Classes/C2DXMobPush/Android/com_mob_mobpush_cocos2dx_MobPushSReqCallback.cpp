#include <jni.h>
//#include <jni/JniHelper.h>
#include "C2DXAndroidSReqCallback.h"
#include "C2DXAndroidMobPush.h"
#include "com_mob_mobpush_cocos2dx_MobPushSReqCallback.h"

USING_NS_CC;
using namespace mob::mobpush;

/*
 * Class:     com_mob_mobpush_cocos2dx_MobPushSReqCallback
 * Method:    nativeOnCreateCxxObject
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_mob_mobpush_cocos2dx_MobPushSReqCallback_nativeOnCreateCxxObject
        (JNIEnv *, jobject) {
    C2DXAndroidSReqCallback *callback = new C2DXAndroidSReqCallback();
    return (jint) callback;
}

/*
 * Class:     com_mob_mobpush_cocos2dx_MobPushSReqCallback
 * Method:    nativeOnCallback
 * Signature: (Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_com_mob_mobpush_cocos2dx_MobPushSReqCallback_nativeOnCallback
        (JNIEnv *env, jobject jthiz, jobject jresult) {

    C2DXAndroidSReqCallback *callback = (C2DXAndroidSReqCallback *) getCxxObject(env, jthiz);

    callback->onCallback(jresult);
}

/*
 * Class:     com_mob_mobpush_cocos2dx_MobPushSReqCallback
 * Method:    nativeOnDestoryCxxObject
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_mob_mobpush_cocos2dx_MobPushSReqCallback_nativeOnDestoryCxxObject
        (JNIEnv *env, jobject jthiz) {
    C2DXAndroidSReqCallback *callback = (C2DXAndroidSReqCallback *) getCxxObject(env, jthiz);
    delete callback;
}
