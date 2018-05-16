//
// Created by yyfu on 2018/5/14.
//

#ifndef PROJ_ANDROID_STUDIO_C2DXANDROIDMOBPUSHRECEIVER_H
#define PROJ_ANDROID_STUDIO_C2DXANDROIDMOBPUSHRECEIVER_H

#include <jni.h>
#include "../C2DXMobPushReceiver.h"

using namespace mob::mobpush;

class C2DXAndroidMobPushReceiver
{
public:
    C2DXAndroidMobPushReceiver();

    virtual ~C2DXAndroidMobPushReceiver();

private:
    C2DXMobPushReceiver* c2DXMobPushReceiver;

public:
    void onCustomMessageReceive(C2DXMobPushCustomMessage mobPushCustomMessage);
    void onNotifyMessageReceive(C2DXMobPushNotifyMessage mobPushNotifyMessage);
    void onNotifyMessageOpenedReceive(C2DXMobPushNotifyMessage mobPushNotifyMessage);
    void onTagsCallback(std::list<std::string>& tags, int i, int j1);
    void onAliasCallback(const char* alias, int i, int j1);

    void setC2DXMobPushReceiver(C2DXMobPushReceiver* receiver);
    C2DXMobPushReceiver* getC2DXMobPushReceiver();
};


#endif //PROJ_ANDROID_STUDIO_C2DXANDROIDMOBPUSHRECEIVER_H