//
// Created by yyfu on 2018/5/11.
//

#include "C2DXMobPush.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#include "C2DXiOSMobPush.h"

#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

#include "Android/C2DXAndroidMobPush.h"

#endif

using namespace mob::mobpush;

void getRegistrationId(C2DXGetRegistrationIdResultEvent callback) {
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

    //Andorid
    C2DXAndroidMobPush::getRegistrationId(callback);

#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS

    //iOS
    C2DXiOSMobPush::getRegistrationId(scene, callback);

#endif
}



