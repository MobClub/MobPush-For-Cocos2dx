//
// Created by yyfu on 2018/5/11.
//

#ifndef PROJ_ANDROID_STUDIO_C2DXANDROIDMOBPUSH_H
#define PROJ_ANDROID_STUDIO_C2DXANDROIDMOBPUSH_H



#include <stdio.h>
#include "cocos2d.h"
#include "jni.h"
#include "../C2DXMobPushCallback.h"
#include "../C2DXMobPushReceiver.h"

USING_NS_CC;

namespace mob
{
    namespace mobpush
    {
        class C2DXAndroidMobPush
        {
        public:
            static void getRegistrationId(C2DXGetRegistrationIdResultEvent callback);
            static void addPushReceiver(C2DXMobPushReceiver* receiver);
            static void removePushReceiver(C2DXMobPushReceiver* receiver);
            static void addTags(std::list<std::string> tags);
            static void setAlias(const char* alias);
            static void req(int type, const char* text, int space, const char* extras, C2DXReqResultEvent reqResultEvent);
        };

        jint getCxxObject(JNIEnv* env, jobject jthiz);
    }
}

#endif //PROJ_ANDROID_STUDIO_C2DXANDROIDMOBPUSH_H