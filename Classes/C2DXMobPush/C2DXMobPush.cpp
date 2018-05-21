//
// Created by yyfu on 2018/5/11.
//

#include "C2DXMobPush.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#include "C2DXiOSMobPush.h"

#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

#include <C2DXAndroidMobPushReceiver.h>
#include "Android/C2DXAndroidMobPush.h"

#endif

using namespace mob::mobpush;

void C2DXMobPush::setAPNsForProduction(bool isPro)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    //Andorid
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    //iOS
    C2DXiOSMobPush::setAPNsForProduction(isPro);
#endif
}

void C2DXMobPush::getRegistrationId(C2DXGetRegistrationIdResultEvent callback) {
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

    //Andorid
    C2DXAndroidMobPush::getRegistrationId(callback);

#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS

    //iOS
    C2DXiOSMobPush::getRegistrationId(callback);
#endif

}

void C2DXMobPush::addPushReceiver() {
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

    //Andorid
    C2DXAndroidMobPush::addPushReceiver();

#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS

    //iOS
    C2DXiOSMobPush::addPushReceiver();
#endif
}

void C2DXMobPush::setAlias(const char *alias) {
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    //Andorid
    C2DXAndroidMobPush::setAlias(alias);
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    //iOS
    C2DXiOSMobPush::setAlias(alias);
#endif
}

void C2DXMobPush::getAlias()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    //Andorid
    C2DXAndroidMobPush::getAlias();
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    //iOS
    C2DXiOSMobPush::getAlias();
#endif
}

void C2DXMobPush::clearAllAlias() {
    
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    //Andorid
    C2DXAndroidMobPush::clearAllAlias();
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    //iOS
    C2DXiOSMobPush::clearAllAlias();
#endif
}

void C2DXMobPush::addTags(C2DXArray *tags) {
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    //Andorid
    C2DXAndroidMobPush::addTags(tags);
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    //iOS
    C2DXiOSMobPush::addTags(tags);
#endif
}

void C2DXMobPush::getTags()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    //Andorid
    C2DXAndroidMobPush::getTags();
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    //iOS
    C2DXiOSMobPush::getTags();
#endif
}

void C2DXMobPush::deleteTags(C2DXArray *tags)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    //Andorid
    C2DXAndroidMobPush::deleteTags(tags);
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    //iOS
    C2DXiOSMobPush::deleteTags(tags);
#endif
}

void C2DXMobPush::clearAllTags()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    //Andorid
    C2DXAndroidMobPush::clearAllTags();
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    //iOS
    C2DXiOSMobPush::clearAllTags();
#endif
}

void C2DXMobPush::addLocalNotification(mob::mobpush::C2DXMobPushLocalNotification *noti) {
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

    //Andorid
    C2DXAndroidMobPush::addLocalNotification(noti);

#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS

    //iOS
    C2DXiOSMobPush::addLocalNotification(noti);
#endif
}

void C2DXMobPush::setCustomNotification(mob::mobpush::C2DXMobPushCustomNotification *noti) {
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

    //Andorid

#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS

    //iOS
    C2DXiOSMobPush::setCustomNotification(noti);
#endif
}

void C2DXMobPush::setC2DXMessageCallBack(C2DXMessageCallBack messageCallBack){
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

    //Andorid
    C2DXAndroidMobPushReceiver::messageCallBack = messageCallBack;

#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS

    //iOS
    C2DXiOSMobPush::setC2DXMessageCallBack(messageCallBack);

#endif
}

void C2DXMobPush::setC2DXAliasCallBack(C2DXAliasCallBack aliasCallBack){
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

    //Andorid
    C2DXAndroidMobPushReceiver::aliasCallBack = aliasCallBack;

#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS

    //iOS
    C2DXiOSMobPush::setC2DXAliasCallBack(aliasCallBack);
    
#endif
}

void C2DXMobPush::setC2DXTagsCallBack(C2DXTagsCallBack tagsCallBack){
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

    //Andorid
    C2DXAndroidMobPushReceiver::tagsCallBack = tagsCallBack;

#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS

    //iOS
    C2DXiOSMobPush::setC2DXTagsCallBack(tagsCallBack);
    
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

