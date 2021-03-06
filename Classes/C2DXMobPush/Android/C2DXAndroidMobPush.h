//
// Created by yyfu on 2018/5/11.
//

#ifndef PROJ_ANDROID_STUDIO_C2DXANDROIDMOBPUSH_H
#define PROJ_ANDROID_STUDIO_C2DXANDROIDMOBPUSH_H



#include <stdio.h>
#include "cocos2d.h"
#include "jni.h"
#include "C2DXMobPushCallback.h"
#include "C2DXMobPushLocalNotification.hpp"
#include "C2DXMobPushCustomNotification.hpp"

USING_NS_CC;

namespace mob
{
    namespace mobpush
    {
        class C2DXAndroidMobPush
        {
        public:
            static void initMobPush(const char* appkey, const char* appScrect);
            static void getRegistrationId(C2DXGetRegistrationIdResultEvent callback);
            static void addPushReceiver();
            static void addTags(C2DXArray *tags);
            static void getTags();
            static void deleteTags(C2DXArray *tags);
            static void clearAllTags();
            static void setAlias(const char* alias);
            static void getAlias();
            static void clearAllAlias();
            static void setNotifyIcon(const char* resIcon);
            static void setAppForegroundHiddenNotification(bool hidden);
            static void addLocalNotification(C2DXMobPushLocalNotification *notification);
            static void bindPhoneNum(const char* alias, C2DXReqResultEvent callback);
            static void setShowBadge(bool show);
            static void req(int type, const char* text, int space, const char* extras, C2DXReqResultEvent reqResultEvent);
            static void updatePrivacyPermissionStatus(bool agree);
        };

        jint getCxxObject(JNIEnv* env, jobject jthiz);
    }
}

#endif //PROJ_ANDROID_STUDIO_C2DXANDROIDMOBPUSH_H