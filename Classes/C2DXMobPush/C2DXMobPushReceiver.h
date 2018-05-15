//
// Created by yyfu on 2018/5/11.
//

#ifndef PROJ_ANDROID_STUDIO_C2DXMOBPUSHRECEIVER_H
#define PROJ_ANDROID_STUDIO_C2DXMOBPUSHRECEIVER_H

#endif //PROJ_ANDROID_STUDIO_C2DXMOBPUSHRECEIVER_H

#include "cocos2d.h"

USING_NS_CC;

namespace mob
{
    namespace mobpush
    {
        class C2DXMobPushReceiver
        {
        public:
            void onCustomMessageReceive(jobject context, jobject mobPushCustomMessage);
            void onNotifyMessageReceive(jobject context, jobject mobPushNotifyMessage);
            void onTagsCallback(jobject context, jobjectArray tags, jint i, jint j1);
            void onAliasCallback(jobject context, jstring alias, jint i, jint j1);
        };
    }
}
