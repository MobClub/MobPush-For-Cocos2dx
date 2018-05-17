#include <jni.h>
#include "com_mob_mobpush_cocos2dx_MobPushReceiver.h"
#include "C2DXAndroidMobPushReceiver.h"
#include "C2DXAndroidMobPush.h"
#include "../C2DXMobPushMessage.h"
#include "./JSON/CCJSONConverter.h"

/*
 * Class:     com_mob_mobpush_cocos2dx_MobPushReceiver
 * Method:    nativeOnCreateCxxObject
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_mob_mobpush_cocos2dx_MobPushReceiver_nativeOnCreateCxxObject
        (JNIEnv *, jobject) {
    C2DXAndroidMobPushReceiver *receiver = new C2DXAndroidMobPushReceiver();
    return (jint) receiver;
}

/*
 * Class:     com_mob_mobpush_cocos2dx_MobPushReceiver
 * Method:    nativeOnDestoryCxxObject
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_mob_mobpush_cocos2dx_MobPushReceiver_nativeOnDestoryCxxObject
        (JNIEnv *env, jobject jthiz) {
    C2DXAndroidMobPushReceiver *receiver = (C2DXAndroidMobPushReceiver *) getCxxObject(env, jthiz);
    delete receiver;
}

/*
 * Class:     com_mob_mobpush_cocos2dx_MobPushReceiver
 * Method:    nativeOnCustomMessageReceive
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_mob_mobpush_cocos2dx_MobPushReceiver_nativeOnCustomMessageReceive
        (JNIEnv *env, jobject jthiz, jstring js) {
    C2DXAndroidMobPushReceiver *receiver = (C2DXAndroidMobPushReceiver *) getCxxObject(env, jthiz);
//    CCJSONConverter *ccjsonConverter = CCJSONConverter::sharedConverter();
//    const char *c=env->GetStringUTFChars(js, NULL);
//    C2DXDictionary *dictionary = ccjsonConverter->dictionaryFrom(c);
//    env->ReleaseStringUTFChars(js, c);
//    cocos2d::Ref *dd = dictionary->objectForKey("ddd");
////    dd._string.c_str();
//    cocos2d::Ref *t = dictionary->objectForKey("t");
//    long a = t.intValue();

//C2DXMobPushCustomMessage customMessage = new C2DXMobPushCustomMessage(dd._string,
//dictionary->objectForKey(""),a,dictionary->objectForKey(""));

    C2DXMobPushMessage *message = new C2DXMobPushMessage();
    message->channel = 1;
    receiver->onCustomMessageReceive(message);
}

/*
 * Class:     com_mob_mobpush_cocos2dx_MobPushReceiver
 * Method:    nativeOnNotifyMessageReceive
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_mob_mobpush_cocos2dx_MobPushReceiver_nativeOnNotifyMessageReceive
        (JNIEnv *env, jobject jthiz, jstring js) {
    C2DXAndroidMobPushReceiver *receiver = (C2DXAndroidMobPushReceiver *) getCxxObject(env, jthiz);

    C2DXMobPushMessage *message = new C2DXMobPushMessage();
    message->channel = 1;
    receiver->onNotifyMessageReceive(message);
}

/*
 * Class:     com_mob_mobpush_cocos2dx_MobPushReceiver
 * Method:    nativeOnNotifyMessageOpenedReceive
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL
Java_com_mob_mobpush_cocos2dx_MobPushReceiver_nativeOnNotifyMessageOpenedReceive
        (JNIEnv *env, jobject jthiz, jstring js) {
    C2DXAndroidMobPushReceiver *receiver = (C2DXAndroidMobPushReceiver *) getCxxObject(env, jthiz);

    C2DXMobPushMessage *message = new C2DXMobPushMessage();
    message->channel = 1;
    receiver->onNotifyMessageOpenedReceive(message);
}

/*
 * Class:     com_mob_mobpush_cocos2dx_MobPushReceiver
 * Method:    nativeOnTagsCallback
 * Signature: ([Ljava/lang/String;II)V
 */
JNIEXPORT void JNICALL Java_com_mob_mobpush_cocos2dx_MobPushReceiver_nativeOnTagsCallback
        (JNIEnv *env, jobject jthiz, jobjectArray jobjectArray1, jint jint1, jint jint2) {
    C2DXAndroidMobPushReceiver *receiver = (C2DXAndroidMobPushReceiver *) getCxxObject(env, jthiz);

//    receiver->onTagsCallback(jobjectArray1, jint1, jint2);
}

/*
 * Class:     com_mob_mobpush_cocos2dx_MobPushReceiver
 * Method:    nativeOnAliasCallback
 * Signature: (Ljava/lang/String;II)V
 */
JNIEXPORT void JNICALL Java_com_mob_mobpush_cocos2dx_MobPushReceiver_nativeOnAliasCallback
        (JNIEnv *env, jobject jthiz, jstring jstring1, jint jint1, jint jint2) {
    CCLOG(">>>>>onAlias>>>>%s", env->GetStringUTFChars(jstring1, NULL));
    C2DXAndroidMobPushReceiver *receiver = (C2DXAndroidMobPushReceiver *) getCxxObject(env, jthiz);
    receiver->onAliasCallback(env->GetStringUTFChars(jstring1, NULL), jint1, jint2);
}

