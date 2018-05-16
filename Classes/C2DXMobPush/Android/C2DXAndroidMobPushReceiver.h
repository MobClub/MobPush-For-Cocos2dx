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
    void onCustomMessageReceive(jobject context, jobject mobPushCustomMessage);
    void onNotifyMessageReceive(jobject context, jobject mobPushNotifyMessage);
    void onNotifyMessageOpenedReceive(jobject context, jobject mobPushNotifyMessage);
    void onTagsCallback(jobject context, jobjectArray tags, jint i, jint j1);
    void onAliasCallback(jobject context, jstring alias, jint i, jint j1);

    void setC2DXMobPushReceiver(C2DXMobPushReceiver* receiver);
    C2DXMobPushReceiver* getC2DXMobPushReceiver();
};


#endif //PROJ_ANDROID_STUDIO_C2DXANDROIDMOBPUSHRECEIVER_H