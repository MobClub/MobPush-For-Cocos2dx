//
// Created by yyfu on 2018/5/14.
//

#ifndef PROJ_ANDROID_STUDIO_C2DXANDROIDMOBPUSHRECEIVER_H
#define PROJ_ANDROID_STUDIO_C2DXANDROIDMOBPUSHRECEIVER_H

#include <jni.h>
#include <C2DXMobPush/C2DXMobPushCallback.h>

using namespace mob::mobpush;

class C2DXAndroidMobPushReceiver
{
public:
    C2DXAndroidMobPushReceiver();

    virtual ~C2DXAndroidMobPushReceiver();

public:
    static C2DXMessageCallBack messageCallBack;
    static C2DXAliasCallBack aliasCallBack;
    static C2DXTagsCallBack tagsCallBack;

public:
    void onCustomMessageReceive(C2DXMobPushMessage *mobPushCustomMessage);
    void onNotifyMessageReceive(C2DXMobPushMessage *mobPushNotifyMessage);
    void onNotifyMessageOpenedReceive(C2DXMobPushMessage *mobPushNotifyMessage);
    void onTagsCallback(std::list<std::string>& tags, int i, int j1);
    void onAliasCallback(const char* alias, int i, int j1);
};

//C2DXAndroidMobPushReceiver::messageCallBack = NULL;


#endif //PROJ_ANDROID_STUDIO_C2DXANDROIDMOBPUSHRECEIVER_H