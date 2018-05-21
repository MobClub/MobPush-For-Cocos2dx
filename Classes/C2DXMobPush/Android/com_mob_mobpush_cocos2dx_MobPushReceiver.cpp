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
    message->content = (__String *) content->_string.c_str();
    message->messageId = (__String *) messageId->_string.c_str();
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

    C2DXMobPushMessage *message = new C2DXMobPushMessage();
    message->style = style->getIntValue();
    message->content = content;
    message->messageId = messageId;
    message->voice = voice;
    message->shake = shake;
    message->light = light;
    message->channel = channel->getIntValue();
    if (title != NULL) {
        message->title = title;
    }
    if (styleContent != NULL) {
        message->styleContent = styleContent;
    }
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

    C2DXMobPushMessage *message = new C2DXMobPushMessage();
    message->style = style->getIntValue();
    message->content = content;
    message->messageId = messageId;
    message->voice = voice;
    message->shake = shake;
    message->light = light;
    message->channel = channel->getIntValue();
    if (title != NULL) {
        message->title = title;
    }
    if (styleContent != NULL) {
        message->styleContent = styleContent;
    }
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

    C2DXArray *array = C2DXArray::create();
    if (jobjectArray1 != NULL) {
        for (int i = 0; i < env->GetArrayLength(jobjectArray1); i++) {
            jobject jo = env->GetObjectArrayElement(jobjectArray1, i);

            C2DXString *cs = C2DXString::create(env->GetStringUTFChars((jstring) jo, NULL));
            array->addObject(cs);
        }
        receiver->onTagsCallback(array, jint1, jint2);
    } else {
        receiver->onTagsCallback(array, jint1, jint2);
    }
}

/*
 * Class:     com_mob_mobpush_cocos2dx_MobPushReceiver
 * Method:    nativeOnAliasCallback
 * Signature: (Ljava/lang/String;II)V
 */
JNIEXPORT void JNICALL Java_com_mob_mobpush_cocos2dx_MobPushReceiver_nativeOnAliasCallback
        (JNIEnv *env, jobject jthiz, jstring jstring1, jint jint1, jint jint2) {
    C2DXAndroidMobPushReceiver *receiver = (C2DXAndroidMobPushReceiver *) getCxxObject(env, jthiz);
    if (jstring1 == NULL) {
        receiver->onAliasCallback(NULL, jint1, jint2);
    } else {
        receiver->onAliasCallback(env->GetStringUTFChars(jstring1, NULL), jint1, jint2);
    }
}

