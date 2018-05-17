//
// Created by yyfu on 2018/5/11.
//

#ifndef PROJ_ANDROID_STUDIO_C2DXANDROIDMOBPUSH_H
#define PROJ_ANDROID_STUDIO_C2DXANDROIDMOBPUSH_H



#include <stdio.h>
#include "cocos2d.h"
#include "jni.h"
#include "../C2DXMobPushCallback.h"

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
            static void removePushReceiver();
            static void addTags(std::list<std::string> tags);
            static void setAlias(const char* alias);
            static void addLocalNotification(const char* text, int space);
            static void setCustomNotification(long when, const char *tickerText, const char *title,
                                              const char *content, int flag, int style,
                                              const char *styleContent,
                                              std::list<std::string> inboxStyleContent,
                                              const char *smallIcon, boolean voice, boolean shake,
                                              boolean light);
            static void req(int type, const char* text, int space, const char* extras, C2DXReqResultEvent reqResultEvent);
        };

        jint getCxxObject(JNIEnv* env, jobject jthiz);
    }
}

#endif //PROJ_ANDROID_STUDIO_C2DXANDROIDMOBPUSH_H