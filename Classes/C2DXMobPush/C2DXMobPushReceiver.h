//
// Created by yyfu on 2018/5/11.
//

#ifndef PROJ_ANDROID_STUDIO_C2DXMOBPUSHRECEIVER_H
#define PROJ_ANDROID_STUDIO_C2DXMOBPUSHRECEIVER_H

#include "cocos2d.h"
#include "C2DXMobPushNotifyMessage.h"
#include "C2DXMobPushCustomMessage.h"

USING_NS_CC;

namespace mob
{
    namespace mobpush
    {
        class C2DXMobPushReceiver
        {
        public:
            virtual void onCustomMessageReceive(C2DXMobPushCustomMessage mobPushCustomMessage) = 0;
            virtual void onNotifyMessageReceive(C2DXMobPushNotifyMessage mobPushNotifyMessage) = 0;
            virtual void onNotifyMessageOpenedReceive(C2DXMobPushNotifyMessage mobPushNotifyMessage) = 0;
            virtual void onTagsCallback(std::list<std::string>& tags, int i, int j1) = 0;
            virtual void onAliasCallback(const char* alias, jint i, int j1) = 0;
        };
    }
}
#endif //PROJ_ANDROID_STUDIO_C2DXMOBPUSHRECEIVER_H