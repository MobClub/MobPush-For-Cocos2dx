#include <jni.h>
//#include <jni/JniHelper.h>
#include "C2DXAndroidCallback.h"
#include "C2DXAndroidMobPush.h"
#include "com_mob_mobpush_cocos2dx_MobPushCallback.h"

USING_NS_CC;
using namespace mob::mobpush;

/*
 * Class:     com_mob_mobpush_cocos2dx_MobPushCallback
 * Method:    nativeOnCreateCxxObject
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_mob_mobpush_cocos2dx_MobPushCallback_nativeOnCreateCxxObject
        (JNIEnv *, jobject) {
    C2DXAndroidCallback *callback = new C2DXAndroidCallback();
    return (jint) callback;
}

/*
 * Class:     com_mob_mobpush_cocos2dx_MobPushCallback
 * Method:    nativeOnCallback
 * Signature: (Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_com_mob_mobpush_cocos2dx_MobPushCallback_nativeOnCallback
        (JNIEnv *env, jobject jthiz, jobject jresult) {
    C2DXAndroidCallback *callback = (C2DXAndroidCallback *) getCxxObject(env, jthiz);
    const char *cresult = env->GetStringUTFChars((jstring)jresult, JNI_FALSE);
    callback->onCallback((const char *) cresult);
    env->ReleaseStringUTFChars((jstring)jresult, cresult);
}

/*
 * Class:     com_mob_mobpush_cocos2dx_MobPushCallback
 * Method:    nativeOnDestoryCxxObject
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_mob_mobpush_cocos2dx_MobPushCallback_nativeOnDestoryCxxObject
        (JNIEnv *env, jobject jthiz) {
    C2DXAndroidCallback *callback = (C2DXAndroidCallback *) getCxxObject(env, jthiz);
    delete callback;
    return 0;
}
