//
// Created by yyfu on 2018/5/14.
//

#ifndef PROJ_ANDROID_STUDIO_C2DXANDROIDSREQCALLBACK_H
#define PROJ_ANDROID_STUDIO_C2DXANDROIDSREQCALLBACK_H

#include <jni.h>
#include "C2DXMobPushCallback.h"

using namespace mob::mobpush;

class C2DXAndroidSReqCallback {
public:
    C2DXAndroidSReqCallback();

    virtual ~C2DXAndroidSReqCallback();

private:
    C2DXReqResultEvent callback;

public:
    void onCallback(jobject result);

    void setC2DXAndroidSReqCallback(C2DXReqResultEvent event);

    C2DXReqResultEvent getC2DXAndroidSReqCallback();
};

#endif //PROJ_ANDROID_STUDIO_C2DXANDROIDSREQCALLBACK_H