//
// Created by yyfu on 2018/5/14.
//

#include <jni.h>
#include "C2DXAndroidMobPushReceiver.h"


using namespace mob::mobpush;

C2DXAndroidMobPushReceiver::C2DXAndroidMobPushReceiver() {
    c2DXMobPushReceiver = NULL;
}

void C2DXAndroidMobPushReceiver::onCustomMessageReceive(C2DXMobPushCustomMessage mobPushCustomMessage) {
    c2DXMobPushReceiver->onCustomMessageReceive(mobPushCustomMessage);
}

void C2DXAndroidMobPushReceiver::onNotifyMessageReceive(C2DXMobPushNotifyMessage mobPushNotifyMessage) {
    c2DXMobPushReceiver->onNotifyMessageReceive(mobPushNotifyMessage);
}
void C2DXAndroidMobPushReceiver::onNotifyMessageOpenedReceive(C2DXMobPushNotifyMessage mobPushNotifyMessage) {
    c2DXMobPushReceiver->onNotifyMessageOpenedReceive(mobPushNotifyMessage);
}

void
C2DXAndroidMobPushReceiver::onTagsCallback(std::list<std::string>& tags, int i, int j1) {
    c2DXMobPushReceiver->onTagsCallback(tags, i, j1);
}

void C2DXAndroidMobPushReceiver::onAliasCallback(const char* alias, int i, int j1) {
    c2DXMobPushReceiver->onAliasCallback(alias, i, j1);
}

void C2DXAndroidMobPushReceiver::setC2DXMobPushReceiver(C2DXMobPushReceiver* receiver) {
    c2DXMobPushReceiver = receiver;
}

C2DXMobPushReceiver* C2DXAndroidMobPushReceiver::getC2DXMobPushReceiver() {
    return c2DXMobPushReceiver;
}

C2DXAndroidMobPushReceiver::~C2DXAndroidMobPushReceiver() {

}
