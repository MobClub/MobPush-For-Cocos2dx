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

void C2DXMobPush::getRegistrationId(C2DXGetRegistrationIdResultEvent callback) {
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

    //Andorid
    C2DXAndroidMobPush::getRegistrationId(callback);

#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS

    //iOS
    C2DXiOSMobPush::getRegistrationId(scene, callback);
#endif

}

void C2DXMobPush::addPushReceiver(C2DXMobPushReceiver *pushReceiver) {
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

    //Andorid
    C2DXAndroidMobPush::addPushReceiver(pushReceiver);

#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS

    //iOS
    C2DXiOSMobPush::addPushReceiver(pushReceiver);
#endif
}

void C2DXMobPush::removePushReceiver(C2DXMobPushReceiver *pushReceiver) {
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

    //Andorid
    C2DXAndroidMobPush::removePushReceiver(pushReceiver);

#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS

    //iOS
    C2DXiOSMobPush::removePushReceiver(pushReceiver);
#endif
}

void C2DXMobPush::addTags(std::list<std::string> tags) {
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

    //Andorid
    C2DXAndroidMobPush::addTags(tags);

#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS

    //iOS
    C2DXiOSMobPush::addTags(tags);
#endif
}

void C2DXMobPush::setAlias(const char *alias) {
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

    //Andorid
    C2DXAndroidMobPush::setAlias(alias);

#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS

    //iOS
    C2DXiOSMobPush::setAlias(tags);
#endif
}

void C2DXMobPush::req(int type, const char *text, int space, const char *extras,
                      C2DXReqResultEvent reqResultEvent) {
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

    //Andorid
    C2DXAndroidMobPush::req(type, text, space, extras, reqResultEvent);

#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS

    //iOS
    C2DXiOSMobPush::req(type, text, space, extras, reqResultEvent);
#endif
}



