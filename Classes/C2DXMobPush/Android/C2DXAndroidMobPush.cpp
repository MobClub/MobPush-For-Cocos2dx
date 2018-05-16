//
// Created by yyfu on 2018/5/14.
//
#include "C2DXAndroidMobPush.h"
#include "cocos2d.h"
#include "../C2DXMobPushCallback.h"
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

void C2DXAndroidMobPush::addPushReceiver(C2DXMobPushReceiver *receiver) {
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

    C2DXAndroidMobPushReceiver *c2DXAndroidMobPushReceiver = (C2DXAndroidMobPushReceiver *) getCxxObject(
            env, jReceiver);
    c2DXAndroidMobPushReceiver->setC2DXMobPushReceiver(receiver);

    env->CallStaticVoidMethod(jm.classID, jm.methodID, jReceiver);
}

void C2DXAndroidMobPush::removePushReceiver(C2DXMobPushReceiver *receiver) {
    JNIEnv *env = JniHelper::getEnv();
    JniMethodInfo jm;
    JniHelper::getStaticMethodInfo(jm, "com/mob/pushsdk/MobPush", "removePushReceiver",
                                   "(Lcom/mob/pushsdk/MobPushReceiver;)V");

    JniMethodInfo jmJavaMobPushReceiverImpl;
    JniHelper::getStaticMethodInfo(jmJavaMobPushReceiverImpl,
                                   "com/mob/mobpush/cocos2dx/MobPushReceiver", "newInstance",
                                   "()Lcom/mob/pushsdk/MobPushReceiver;");
    jobject jReceiver = env->CallStaticObjectMethod(jmJavaMobPushReceiverImpl.classID,
                                                    jmJavaMobPushReceiverImpl.methodID);

    C2DXAndroidMobPushReceiver *c2DXAndroidMobPushReceiver = (C2DXAndroidMobPushReceiver *) getCxxObject(
            env, jReceiver);
    c2DXAndroidMobPushReceiver->setC2DXMobPushReceiver(receiver);

    env->CallStaticVoidMethod(jm.classID, jm.methodID, jReceiver);
}

void C2DXAndroidMobPush::setAlias(const char *alias) {
    JNIEnv *env = JniHelper::getEnv();
    JniMethodInfo jm;
    JniHelper::getStaticMethodInfo(jm, "com/mob/pushsdk/MobPush", "setAlias",
                                   "(Ljava/lang/String;)V");
    env->CallStaticVoidMethod(jm.classID, jm.methodID, env->NewStringUTF(alias));
}

void C2DXAndroidMobPush::addTags(std::list<std::string> tags) {
    JNIEnv *env = JniHelper::getEnv();
    JniMethodInfo jm;
    JniHelper::getStaticMethodInfo(jm, "com/mob/pushsdk/MobPush", "addTags",
                                   "([Ljava/lang/String;)V");
    jobjectArray joa = env->NewObjectArray(tags.size(), env->FindClass("java/lang/String"), NULL);

    int i = 0;
    for (std::list<std::string>::iterator it = tags.begin(); it != tags.end() ; it++, i++) {
        jstring jString = env->NewStringUTF(it->c_str());
        env->SetObjectArrayElement(joa, i, jString);
    }
    env->CallStaticVoidMethod(jm.classID, jm.methodID, joa);
}

void C2DXAndroidMobPush::addLocalNotification(const char *text, int space) {
    JNIEnv *env = JniHelper::getEnv();
    JniMethodInfo jm;
    JniHelper::getStaticMethodInfo(jm, "com/mob/mobpush/cocos2dx/SendPushHelper", "sendLocalNotify",
                                   "(Ljava/lang/String;I)V");
    env->CallStaticVoidMethod(jm.classID, jm.methodID, env->NewStringUTF(text), space);
}

void C2DXAndroidMobPush::setCustomNotification(long when, const char *tickerText, const char *title,
                                               const char *content, int flag, int style,
                                               const char *styleContent,
                                               std::list<std::string> inboxStyleContent,
                                               const char *smallIcon, boolean voice, boolean shake,
                                               boolean light) {
    JNIEnv *env = JniHelper::getEnv();
    JniMethodInfo jm;
    JniHelper::getStaticMethodInfo(jm, "com/mob/mobpush/cocos2dx/CustomNotification", "newInstance",
                                   "()Lcom/mob/mobpush/cocos2dx/CustomNotification;");
    jobject jo = env->CallStaticObjectMethod(jm.classID, jm.methodID);

    jmethodID jmethodID1 = env->GetMethodID(jm.classID, "getNotificationManager",
                                            "()Landroid/app/NotificationManager;");
    jobject jom = env->CallObjectMethod(jo, jmethodID1);

    jmethodID  jmethodID2 = env->GetMethodID(jm.classID, "getNotification",
                     "Landroid/content/Context;Landroid/app/NotificationManager;JLjava/lang/String;Ljava/lang/String;Ljava/lang/String;IILjava/lang/String;[Ljava/lang/String;Ljava/lang/String;ZZZ)Landroid/app/Notification;");

    JniHelper::getStaticMethodInfo(jm, "com/mob/MobSDK", "getContext",
                                   "()Landroid/content/Context;");
    jobject jc = env->CallStaticObjectMethod(jm.classID, jm.methodID);
    jobject jon = env->CallObjectMethod(jo,jmethodID2, jc, jom, when, tickerText, title, content, flag, style, styleContent, inboxStyleContent, smallIcon, voice, shake, light);

    JniHelper::getStaticMethodInfo(jm, "com/mob/pushsdk/MobPush", "setCustomNotification",
                                   "(Lcom/mob/pushsdk/MobPushCustomNotification)V");

    env->CallStaticVoidMethod(jm.classID, jm.methodID, jon);
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