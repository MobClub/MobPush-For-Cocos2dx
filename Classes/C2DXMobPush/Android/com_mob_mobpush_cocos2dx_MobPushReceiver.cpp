#include <jni.h>
#include "com_mob_mobpush_cocos2dx_MobPushReceiver.h"
#include "C2DXAndroidMobPushReceiver.h"
#include "C2DXAndroidMobPush.h"
#include "C2DXMobPushMessage.h"
#include "CCJSONConverter.h"

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
    CCJSONConverter *ccjsonConverter = CCJSONConverter::sharedConverter();
    const char *c = env->GetStringUTFChars(js, NULL);
    C2DXDictionary *dictionary = ccjsonConverter->dictionaryFrom(c);
    env->ReleaseStringUTFChars(js, c);
    C2DXString *content = (C2DXString *) dictionary->objectForKey("content");
    C2DXString *messageId = (C2DXString *) dictionary->objectForKey("messageId");
    C2DXString *tt = (C2DXString *) dictionary->objectForKey("timestamp");
    const char *cs = tt->_string.c_str();
    long long ll = atoll(cs);
    C2DXMobPushMessage *message = new C2DXMobPushMessage();
    message->content = content->_string.c_str();
    message->messageId = messageId->_string.c_str();
    message->timestamp = ll;
    receiver->onCustomMessageReceive(message);
    dictionary->autorelease();
}

/*
 * Class:     com_mob_mobpush_cocos2dx_MobPushReceiver
 * Method:    nativeOnNotifyMessageReceive
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_mob_mobpush_cocos2dx_MobPushReceiver_nativeOnNotifyMessageReceive
        (JNIEnv *env, jobject jthiz, jstring js) {
    C2DXAndroidMobPushReceiver *receiver = (C2DXAndroidMobPushReceiver *) getCxxObject(env, jthiz);

    CCJSONConverter *ccjsonConverter = CCJSONConverter::sharedConverter();
    const char *c = env->GetStringUTFChars(js, NULL);
    C2DXDictionary *dictionary = ccjsonConverter->dictionaryFrom(c);
    env->ReleaseStringUTFChars(js, c);
    CCNumber *style = (CCNumber *) dictionary->objectForKey("style");
    C2DXString *title = (C2DXString *) dictionary->objectForKey("title");
    C2DXString *content = (C2DXString *) dictionary->objectForKey("content");
    C2DXString *styleContent = (C2DXString *) dictionary->objectForKey("styleContent");
    C2DXString *messageId = (C2DXString *) dictionary->objectForKey("messageId");
    bool voice = (bool) dictionary->objectForKey("voice");
    bool shake = (bool) dictionary->objectForKey("shake");
    bool light = (bool) dictionary->objectForKey("light");
    CCNumber *channel = (CCNumber *) dictionary->objectForKey("channel");

    CCLOG(">>>>style>>>>>>%d", style->getIntValue());
    CCLOG(">>>>title>>>>>>%d", title->_string.c_str());
    CCLOG(">>>>content>>>>>>%d", content->_string.c_str());
    CCLOG(">>>>styleContent>>>>>>%d", styleContent->_string.c_str());
    CCLOG(">>>>messageId>>>>>>%d", messageId->_string.c_str());
    CCLOG(">>>>channel>>>>>>%d", channel->getIntValue());
    if (voice) {
        CCLOG(">>>>voice>>>>>>%s", "true");
    } else {
        CCLOG(">>>>voice>>>>>>%s", "false");
    }
    if (shake) {
        CCLOG(">>>>shake>>>>>>%s", "true");
    } else {
        CCLOG(">>>>shake>>>>>>%s", "false");
    }
    if (light) {
        CCLOG(">>>>light>>>>>>%s", "true");
    } else {
        CCLOG(">>>>light>>>>>>%s", "false");
    }

    C2DXMobPushMessage *message = new C2DXMobPushMessage();
    message->style = style->getIntValue();
    message->title = title->_string.c_str();
    message->content = content->_string.c_str();
    message->styleContent = styleContent->_string.c_str();
    message->messageId = messageId->_string.c_str();
    message->voice = voice;
    message->shake = shake;
    message->light = light;
    message->channel = channel->getIntValue();
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

