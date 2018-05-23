//
// Created by yyfu on 2018/5/14.
//

#include "C2DXAndroidMobPushReceiver.h"
#include "C2DXMobPushCallback.h"

using namespace mob::mobpush;


C2DXMessageCallBack C2DXAndroidMobPushReceiver::messageCallBack = NULL;
C2DXTagsCallBack C2DXAndroidMobPushReceiver::tagsCallBack = NULL;
C2DXAliasCallBack C2DXAndroidMobPushReceiver::aliasCallBack = NULL;

C2DXAndroidMobPushReceiver::C2DXAndroidMobPushReceiver() {
}

void C2DXAndroidMobPushReceiver::onCustomMessageReceive(C2DXMobPushMessage* mobPushCustomMessage) {
    messageCallBack(0,mobPushCustomMessage);
}

void C2DXAndroidMobPushReceiver::onNotifyMessageReceive(C2DXMobPushMessage* mobPushNotifyMessage) {
    messageCallBack(1,mobPushNotifyMessage);
}
void C2DXAndroidMobPushReceiver::onNotifyMessageOpenedReceive(C2DXMobPushMessage* mobPushNotifyMessage) {
    messageCallBack(2,mobPushNotifyMessage);
}

void
C2DXAndroidMobPushReceiver::onTagsCallback(C2DXArray *tags, int i, int j1) {
    tagsCallBack(tags, i, j1);
}

void C2DXAndroidMobPushReceiver::onAliasCallback(const char* alias, int i, int j1) {
    aliasCallBack(alias, i, j1);
}

C2DXAndroidMobPushReceiver::~C2DXAndroidMobPushReceiver() {

}
