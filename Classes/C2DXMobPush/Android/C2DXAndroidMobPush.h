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
            static void addLocalNotification(C2DXMobPushLocalNotification *notification);
            static void setCustomNotification(C2DXMobPushCustomNotification *notification);
            static void req(int type, const char* text, int space, const char* extras, C2DXReqResultEvent reqResultEvent);
        };

        jint getCxxObject(JNIEnv* env, jobject jthiz);
    }
}

#endif //PROJ_ANDROID_STUDIO_C2DXANDROIDMOBPUSH_H