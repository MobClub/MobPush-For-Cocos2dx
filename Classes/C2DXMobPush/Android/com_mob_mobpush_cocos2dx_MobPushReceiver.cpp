#include <jni.h>
#include "com_mob_mobpush_cocos2dx_MobPushReceiver.h"
#include "C2DXAndroidMobPushReceiver.h"
#include "C2DXAndroidMobPush.h"

/*
 * Class:     com_mob_mobpush_cocos2dx_MobPushReceiver
 * Method:    nativeOnCreateCxxObject
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_mob_mobpush_cocos2dx_MobPushReceiver_nativeOnCreateCxxObject
  (JNIEnv *, jobject)
{
    C2DXAndroidMobPushReceiver *receiver = new C2DXAndroidMobPushReceiver();
    return (jint) receiver;
}

/*
 * Class:     com_mob_mobpush_cocos2dx_MobPushReceiver
 * Method:    nativeOnDestoryCxxObject
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_mob_mobpush_cocos2dx_MobPushReceiver_nativeOnDestoryCxxObject
  (JNIEnv * env, jobject jthiz)
{
    C2DXAndroidMobPushReceiver *receiver = (C2DXAndroidMobPushReceiver *) getCxxObject(env, jthiz);
    delete receiver;
}

/*
 * Class:     com_mob_mobpush_cocos2dx_MobPushReceiver
 * Method:    nativeOnCustomMessageReceive
 * Signature: (Landroid/content/Context;Lcom/mob/pushsdk/MobPushCustomMessage;)V
 */
JNIEXPORT void JNICALL Java_com_mob_mobpush_cocos2dx_MobPushReceiver_nativeOnCustomMessageReceive
  (JNIEnv *env, jobject jthiz, jobject jobject1, jobject jobject2)
{
    C2DXAndroidMobPushReceiver *receiver = (C2DXAndroidMobPushReceiver *) getCxxObject(env, jthiz);
//    receiver->onCustomMessageReceive(jobject2);
}

/*
 * Class:     com_mob_mobpush_cocos2dx_MobPushReceiver
 * Method:    nativeOnNotifyMessageReceive
 * Signature: (Landroid/content/Context;Lcom/mob/pushsdk/MobPushNotifyMessage;)V
 */
JNIEXPORT void JNICALL Java_com_mob_mobpush_cocos2dx_MobPushReceiver_nativeOnNotifyMessageReceive
  (JNIEnv *env, jobject jthiz, jobject jobject1, jobject jobject2)
{
    C2DXAndroidMobPushReceiver *receiver = (C2DXAndroidMobPushReceiver *) getCxxObject(env, jthiz);
//    receiver->onNotifyMessageReceive(jobject2);
}

/*
 * Class:     com_mob_mobpush_cocos2dx_MobPushReceiver
 * Method:    nativeOnNotifyMessageOpenedReceive
 * Signature: (Landroid/content/Context;Lcom/mob/pushsdk/MobPushNotifyMessage;)V
 */
JNIEXPORT void JNICALL Java_com_mob_mobpush_cocos2dx_MobPushReceiver_nativeOnNotifyMessageOpenedReceive
  (JNIEnv *env, jobject jthiz, jobject jobject1, jobject jobject2)
{
    C2DXAndroidMobPushReceiver *receiver = (C2DXAndroidMobPushReceiver *) getCxxObject(env, jthiz);
//    receiver->onNotifyMessageOpenedReceive(jobject2);
}

/*
 * Class:     com_mob_mobpush_cocos2dx_MobPushReceiver
 * Method:    nativeOnTagsCallback
 * Signature: (Landroid/content/Context;[Ljava/lang/String;II)V
 */
JNIEXPORT void JNICALL Java_com_mob_mobpush_cocos2dx_MobPushReceiver_nativeOnTagsCallback
  (JNIEnv *env, jobject jthiz, jobject jobject1, jobjectArray jobjectArray1, jint jint1, jint jint2)
{
    C2DXAndroidMobPushReceiver *receiver = (C2DXAndroidMobPushReceiver *) getCxxObject(env, jthiz);
//    receiver->onTagsCallback(jobjectArray1, jint1, jint2);
}

/*
 * Class:     com_mob_mobpush_cocos2dx_MobPushReceiver
 * Method:    nativeOnAliasCallback
 * Signature: (Landroid/content/Context;Ljava/lang/String;II)V
 */
JNIEXPORT void JNICALL Java_com_mob_mobpush_cocos2dx_MobPushReceiver_nativeOnAliasCallback
  (JNIEnv *env, jobject jthiz, jobject jobject1, jstring jstring1, jint jint1, jint jint2)
{
    C2DXAndroidMobPushReceiver *receiver = (C2DXAndroidMobPushReceiver *) getCxxObject(env, jthiz);
//    receiver->onAliasCallback(jstring1, jint1, jint2);
}

