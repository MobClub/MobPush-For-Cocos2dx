//
// Created by yyfu on 2018/5/14.
//

#include <jni.h>
#include "C2DXAndroidMobPushReceiver.h"


using namespace mob::mobpush;

C2DXAndroidMobPushReceiver::C2DXAndroidMobPushReceiver() {
    c2DXMobPushReceiver = NULL;
}

void C2DXAndroidMobPushReceiver::onCustomMessageReceive(jobject context,
                                                        jobject mobPushCustomMessage) {
    c2DXMobPushReceiver->onCustomMessageReceive(context, mobPushCustomMessage);
}

void C2DXAndroidMobPushReceiver::onNotifyMessageReceive(jobject context,
                                                        jobject mobPushNotifyMessage) {
    c2DXMobPushReceiver->onNotifyMessageReceive(context, mobPushNotifyMessage);
}
void C2DXAndroidMobPushReceiver::onNotifyMessageOpenedReceive(jobject context,
                                                              jobject mobPushNotifyMessage) {
    c2DXMobPushReceiver->onNotifyMessageOpenedReceive(context, mobPushNotifyMessage);
}

void
C2DXAndroidMobPushReceiver::onTagsCallback(jobject context, jobjectArray tags, jint i, jint j1) {
    c2DXMobPushReceiver->onTagsCallback(context, tags, i, j1);
}

void C2DXAndroidMobPushReceiver::onAliasCallback(jobject context, jstring alias, jint i, jint j1) {
    c2DXMobPushReceiver->onAliasCallback(context, alias, i, j1);
}

void C2DXAndroidMobPushReceiver::setC2DXMobPushReceiver(C2DXMobPushReceiver* receiver) {
    c2DXMobPushReceiver = receiver;
}

C2DXMobPushReceiver* C2DXAndroidMobPushReceiver::getC2DXMobPushReceiver() {
    return c2DXMobPushReceiver;
}

C2DXAndroidMobPushReceiver::~C2DXAndroidMobPushReceiver() {

}
