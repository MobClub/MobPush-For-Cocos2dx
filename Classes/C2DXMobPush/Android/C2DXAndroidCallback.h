//
// Created by yyfu on 2018/5/14.
//

#ifndef PROJ_ANDROID_STUDIO_C2DXANDROIDCALLBACK_H
#define PROJ_ANDROID_STUDIO_C2DXANDROIDCALLBACK_H

#include <jni.h>
#include "../C2DXMobPushCallback.h"

using namespace mob::mobpush;

class C2DXAndroidCallback {
public:
    C2DXAndroidCallback();

    virtual ~C2DXAndroidCallback();

private:
    C2DXGetRegistrationIdResultEvent callback;

public:
    void onCallback(const char * result);

    void setC2DXAndroidCallback(C2DXGetRegistrationIdResultEvent event);

    C2DXGetRegistrationIdResultEvent getC2DXAndroidCallback();
};

#endif //PROJ_ANDROID_STUDIO_C2DXANDROIDCALLBACK_H