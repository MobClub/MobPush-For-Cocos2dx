//
// Created by yyfu on 2018/5/14.
//
#include "C2DXAndroidMobPush.h"
#include "cocos2d.h"
#include "../C2DXMobPushCallback.h"
#include "C2DXAndroidCallback.h"
#include "C2DXAndroidMobPushReceiver.h"

USING_NS_CC;
using namespace mob::mobpush;

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

void C2DXAndroidMobPush::addPushReceiver(C2DXMobPushReceiver receiver) {
    JNIEnv *env = JniHelper::getEnv();
    JniMethodInfo jm;
    JniHelper::getStaticMethodInfo(jm, "com/mob/pushsdk/MobPush", "addPushReceiver",
                                   "(Lcom/mob/pushsdk/MobPushReceiver;)V");

    JniMethodInfo jmJavaMobPushReceiverImpl;
    JniHelper::getStaticMethodInfo(jmJavaMobPushReceiverImpl,
                                   "com/mob/mobpush/cocos2dx/MobPushReceiver", "newInstance", "()Lcom/mob/pushsdk/MobPushReceiver;");
    jobject jReceiver = env->CallStaticObjectMethod(jmJavaMobPushReceiverImpl.classID, jmJavaMobPushReceiverImpl.methodID);

    C2DXAndroidMobPushReceiver* c2DXAndroidMobPushReceiver = (C2DXAndroidMobPushReceiver *) getCxxObject(env, jReceiver);
    c2DXAndroidMobPushReceiver->setC2DXMobPushReceiver(receiver);

    env->CallStaticVoidMethod(jm.classID, jm.methodID, jReceiver);
}

void C2DXAndroidMobPush::removePushReceiver(C2DXMobPushReceiver receiver) {
    JNIEnv *env = JniHelper::getEnv();
    JniMethodInfo jm;
    JniHelper::getStaticMethodInfo(jm, "com/mob/pushsdk/MobPush", "removePushReceiver",
                                   "(Lcom/mob/pushsdk/MobPushReceiver;)V");

    JniMethodInfo jmJavaMobPushReceiverImpl;
    JniHelper::getStaticMethodInfo(jmJavaMobPushReceiverImpl,
                                   "com/mob/mobpush/cocos2dx/MobPushReceiver", "newInstance", "()Lcom/mob/pushsdk/MobPushReceiver;");
    jobject jReceiver = env->CallStaticObjectMethod(jmJavaMobPushReceiverImpl.classID, jmJavaMobPushReceiverImpl.methodID);

    C2DXAndroidMobPushReceiver* c2DXAndroidMobPushReceiver = (C2DXAndroidMobPushReceiver *) getCxxObject(env, jReceiver);
    c2DXAndroidMobPushReceiver->setC2DXMobPushReceiver(receiver);

    env->CallStaticVoidMethod(jm.classID, jm.methodID, jReceiver);
}




jint mob::mobpush::getCxxObject(JNIEnv *env, jobject jthiz) {
    jclass jthizclass = env->GetObjectClass(jthiz);
    jmethodID method = env->GetMethodID(jthizclass, "getCxxObject", "()I");
    jint result = env->CallIntMethod(jthiz, method);
    return result;
}