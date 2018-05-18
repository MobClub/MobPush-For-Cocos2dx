//
//
//  Created by 小新 on 2018/5/11.
//
//
#ifndef __C2DXMobPushSample__C2DXMobPushCallback__
#define __C2DXMobPushSample__C2DXMobPushCallback__

#include <stdio.h>
#include "../../cocos2d/external/jpeg/include/android/jmorecfg.h"
#include "C2DXMobPushMessage.h"

namespace mob {
    namespace mobpush {
        
        /**
         获取mobid之回调

         @param C2DXGetRegistrationIdResultEvent 回调registrationId
         */
        typedef void(*C2DXGetRegistrationIdResultEvent) (const char *registrationId);

        /**
         Demo 回调

         @param C2DXReqResultEvent 是否成功
         */
        typedef void(*C2DXReqResultEvent) (bool reqResult);

        /**
         消息收到回调

         @param C2DXMessageCallBack (action： 0自定义消息, 1收到消息, 2点击消息)，message：消息实体
         */
        typedef void(*C2DXMessageCallBack) (int action, C2DXMobPushMessage* message);

        /**
         别名回调

         @param C2DXAlias alias：别名，（operation：0 获取，1 设置，2 删除）， errorCode：0 成功，其余失败。
         */
        typedef void(*C2DXAliasCallBack) (const char *alias, int operation, int errorCode);

        /**
         标签回调

         @param onTags tags：标签数组，（operation：0 获取，1 设置，2 删除，3 清空），errorCode：0 成功，其余失败。
         */
        typedef void(*C2DXTagsCallBack) (C2DXArray *tags, int operation, int errorCode);
    }
}

#endif /* C2DXMobPushCallBack_h */
