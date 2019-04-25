//
// Created by yyfu on 2018/5/14.
//
#include <C2DXMobPush/C2DXMobPushCustomNotification.hpp>
#include <C2DXMobPush/C2DXMobPushLocalNotification.hpp>
#include <C2DXMobPush/Android/JSON/CCJSONData.h>
#include <C2DXMobPush/Android/JSON/CCJSONConverter.h>
#include "C2DXAndroidMobPush.h"
#include "cocos2d.h"
#include "C2DXMobPushCallback.h"
#include "C2DXAndroidCallback.h"
#include "C2DXAndroidSReqCallback.h"
#include "C2DXAndroidMobPushReceiver.h"

USING_NS_CC;
using namespace mob::mobpush;
using namespace std;

void C2DXAndroidMobPush::initMobPush(const char *appkey, const char *appScrect) {
    JNIEnv *env = JniHelper::getEnv();
    JniMethodInfo jm;
    JniHelper::getStaticMethodInfo(jm, "com/mob/MobSDK", "getContext",
                                   "()Landroid/content/Context;");
    jobject jc = env->CallStaticObjectMethod(jm.classID, jm.methodID);

    JniHelper::getStaticMethodInfo(jm, "com/mob/MobSDK", "init",
                                   "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V");
    env->CallStaticVoidMethod(jm.classID, jm.methodID, jc, env->NewStringUTF(appkey),
                              env->NewStringUTF(appScrect));
}

void C2DXAndroidMobPush::setShowBadge(bool show) {
    JNIEnv *env = JniHelper::getEnv();
    JniMethodInfo jm;
    JniHelper::getStaticMethodInfo(jm, "com/mob/pushsdk/MobPush", "setShowBadge",
                                   "(Z)V");

    env->CallStaticVoidMethod(jm.classID, jm.methodID, show);
}

void C2DXAndroidMobPush::bindPhoneNum(const char* alias, C2DXReqResultEvent callback) {
    JNIEnv *env = JniHelper::getEnv();
    JniMethodInfo jm;
    JniHelper::getStaticMethodInfo(jm, "com/mob/pushsdk/MobPush", "bindPhoneNum",
                                   "(Ljava/lang/String;Lcom/mob/pushsdk/MobPushCallback;)V");

    JniMethodInfo jniMethodInfo;
    JniHelper::getStaticMethodInfo(jniMethodInfo, "com/mob/mobpush/cocos2dx/MobPushSReqCallback",
                                   "newInstance",
                                   "()Lcom/mob/mobpush/cocos2dx/MobPushSReqCallback;");

    jobject jz = env->CallStaticObjectMethod(jniMethodInfo.classID, jniMethodInfo.methodID);

    C2DXAndroidSReqCallback *c2DXAndroidSReqCallback = (C2DXAndroidSReqCallback *) getCxxObject(env,
                                                                                                jz);
    c2DXAndroidSReqCallback->setC2DXAndroidSReqCallback(callback);

    env->CallStaticVoidMethod(jm.classID, jm.methodID, env->NewStringUTF(alias), jz);
}


void C2DXAndroidMobPush::getRegistrationId(C2DXGetRegistrationIdResultEvent callback) {
    JNIEnv *env = JniHelper::getEnv();

    JniMethodInfo jm;
    JniHelper::getStaticMethodInfo(jm, "com/mob/pushsdk/MobPush", "getRegistrationId",
                                   "(Lcom/mob/pushsdk/MobPushCallback;)V");

    JniMethodInfo jmJavaCallbackImpl;
    JniHelper::getStaticMethodInfo(jmJavaCallbackImpl, "com/mob/mobpush/cocos2dx/MobPushCallback",
                                   "newInstance", "()Lcom/mob/mobpush/cocos2dx/MobPushCallback;");
    jobject jJavaCallBackImpl = env->CallStaticObjectMethod(jmJavaCallbackImpl.classID,
                                                            jmJavaCallbackImpl.methodID);

    C2DXAndroidCallback *c2DXAndroidCallback = (C2DXAndroidCallback *) getCxxObject(env,
                                                                                    jJavaCallBackImpl);
    c2DXAndroidCallback->setC2DXAndroidCallback(callback);

    env->CallStaticVoidMethod(jm.classID, jm.methodID, jJavaCallBackImpl);
}

void C2DXAndroidMobPush::addPushReceiver() {
    JNIEnv *env = JniHelper::getEnv();
    JniMethodInfo jm;
    JniHelper::getStaticMethodInfo(jm, "com/mob/pushsdk/MobPush", "addPushReceiver",
                                   "(Lcom/mob/pushsdk/MobPushReceiver;)V");

    JniMethodInfo jmJavaMobPushReceiverImpl;
    JniHelper::getStaticMethodInfo(jmJavaMobPushReceiverImpl,
                                   "com/mob/mobpush/cocos2dx/MobPushReceiver", "newInstance",
                                   "()Lcom/mob/mobpush/cocos2dx/MobPushReceiver;");
    jobject jReceiver = env->CallStaticObjectMethod(jmJavaMobPushReceiverImpl.classID,
                                                    jmJavaMobPushReceiverImpl.methodID);
    env->CallStaticVoidMethod(jm.classID, jm.methodID, jReceiver);
}

void C2DXAndroidMobPush::setAlias(const char *alias) {
    JNIEnv *env = JniHelper::getEnv();
    JniMethodInfo jm;
    JniHelper::getStaticMethodInfo(jm, "com/mob/pushsdk/MobPush", "setAlias",
                                   "(Ljava/lang/String;)V");
    env->CallStaticVoidMethod(jm.classID, jm.methodID, env->NewStringUTF(alias));
}

void C2DXAndroidMobPush::getAlias() {
    JNIEnv *env = JniHelper::getEnv();
    JniMethodInfo jm;
    JniHelper::getStaticMethodInfo(jm, "com/mob/pushsdk/MobPush", "getAlias",
                                   "()V");
    env->CallStaticVoidMethod(jm.classID, jm.methodID);
}

void C2DXAndroidMobPush::clearAllAlias() {
    JNIEnv *env = JniHelper::getEnv();
    JniMethodInfo jm;
    JniHelper::getStaticMethodInfo(jm, "com/mob/pushsdk/MobPush", "deleteAlias",
                                   "()V");
    env->CallStaticVoidMethod(jm.classID, jm.methodID);
}

void C2DXAndroidMobPush::addTags(C2DXArray *tags) {
    JNIEnv *env = JniHelper::getEnv();
    JniMethodInfo jm;
    JniHelper::getStaticMethodInfo(jm, "com/mob/pushsdk/MobPush", "addTags",
                                   "([Ljava/lang/String;)V");

    jobjectArray joa = env->NewObjectArray(tags->count(), env->FindClass("java/lang/String"), NULL);

    C2DXObject *obj = NULL;
    int i = 0;
    CCARRAY_FOREACH(tags, obj) {
            C2DXString *s = (__String *) obj;
            env->SetObjectArrayElement(joa, i, env->NewStringUTF(s->_string.c_str()));
            i++;
        }

    env->CallStaticVoidMethod(jm.classID, jm.methodID, joa);
}

void C2DXAndroidMobPush::getTags(){
    JNIEnv *env = JniHelper::getEnv();
    JniMethodInfo jm;
    JniHelper::getStaticMethodInfo(jm, "com/mob/pushsdk/MobPush", "getTags",
                                   "()V");
    env->CallStaticVoidMethod(jm.classID, jm.methodID);
}

void C2DXAndroidMobPush::deleteTags(C2DXArray *tags){
    JNIEnv *env = JniHelper::getEnv();
    JniMethodInfo jm;
    JniHelper::getStaticMethodInfo(jm, "com/mob/pushsdk/MobPush", "deleteTags",
                                   "([Ljava/lang/String;)V");

    jobjectArray joa = env->NewObjectArray(tags->count(), env->FindClass("java/lang/String"), NULL);

    C2DXObject *obj = NULL;
    int i = 0;
    CCARRAY_FOREACH(tags, obj) {
            C2DXString *s = (__String *) obj;
            env->SetObjectArrayElement(joa, i, env->NewStringUTF(s->_string.c_str()));
            i++;
        }

    env->CallStaticVoidMethod(jm.classID, jm.methodID, joa);
}

void C2DXAndroidMobPush::clearAllTags(){
    JNIEnv *env = JniHelper::getEnv();
    JniMethodInfo jm;
    JniHelper::getStaticMethodInfo(jm, "com/mob/pushsdk/MobPush", "cleanTags",
                                   "()V");

    env->CallStaticVoidMethod(jm.classID, jm.methodID);
}

void C2DXAndroidMobPush::setNotifyIcon(const char* resIcon){
    JNIEnv *env = JniHelper::getEnv();
    JniMethodInfo jm;
    JniHelper::getStaticMethodInfo(jm, "com/mob/mobpush/cocos2dx/MobPushWrapper", "setNotifyIcon",
                                   "(Ljava/lang/String;)V");

    env->CallStaticVoidMethod(jm.classID, jm.methodID, env->NewStringUTF(resIcon));
}

void C2DXAndroidMobPush::setAppForegroundHiddenNotification(bool hidden){
    JNIEnv *env = JniHelper::getEnv();
    JniMethodInfo jm;
    JniHelper::getStaticMethodInfo(jm, "com/mob/mobpush/cocos2dx/MobPushWrapper", "setAppForegroundHiddenNotification",
                                   "(Z)V");

    env->CallStaticVoidMethod(jm.classID, jm.methodID, hidden);
}

void C2DXAndroidMobPush::addLocalNotification(C2DXMobPushLocalNotification *notification) {
    JNIEnv *env = JniHelper::getEnv();
    JniMethodInfo jm;
    JniHelper::getStaticMethodInfo(jm, "com/mob/mobpush/cocos2dx/MobPushWrapper", "sendLocalNotify",
                                   "(Ljava/lang/String;I)V");
    env->CallStaticVoidMethod(jm.classID, jm.methodID, env->NewStringUTF(notification->content),
                              notification->timeStamp);
}

void C2DXAndroidMobPush::req(int type, const char *text, int space, const char *extras,
                             C2DXReqResultEvent reqResultEvent) {
    JNIEnv *env = JniHelper::getEnv();
    JniMethodInfo jm;
    JniHelper::getStaticMethodInfo(jm, "com/mob/mobpush/cocos2dx/SimulateRequest", "sendPush",
                                   "(ILjava/lang/String;ILjava/lang/String;Lcom/mob/pushsdk/MobPushCallback;)V");

    JniMethodInfo jniMethodInfo;
    JniHelper::getStaticMethodInfo(jniMethodInfo, "com/mob/mobpush/cocos2dx/MobPushSReqCallback",
                                   "newInstance",
                                   "()Lcom/mob/mobpush/cocos2dx/MobPushSReqCallback;");

    jobject jz = env->CallStaticObjectMethod(jniMethodInfo.classID, jniMethodInfo.methodID);

    C2DXAndroidSReqCallback *c2DXAndroidSReqCallback = (C2DXAndroidSReqCallback *) getCxxObject(env,
                                                                                                jz);
    c2DXAndroidSReqCallback->setC2DXAndroidSReqCallback(reqResultEvent);

    env->CallStaticVoidMethod(jm.classID, jm.methodID, type, env->NewStringUTF(text), space,
                              env->NewStringUTF(extras), jz);

}

jint mob::mobpush::getCxxObject(JNIEnv *env, jobject jthiz) {
    jclass jthizclass = env->GetObjectClass(jthiz);
    jmethodID method = env->GetMethodID(jthizclass, "getCxxObject", "()I");
    jint result = env->CallIntMethod(jthiz, method);
    return result;
}