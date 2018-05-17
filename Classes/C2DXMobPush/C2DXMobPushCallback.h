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
              *  获取mobid之回调
              *
              *  @param C2DXGetRegistrationIdResultEvent 回调registrationId
              */
        typedef void(*C2DXGetRegistrationIdResultEvent) (const char * registrationId);

        /**


         @param C2DXReqResultEvent
         */
        typedef void(*C2DXReqResultEvent) (bool reqResult);


        /**
         <#Description#>

         @param C2DXMessageCallBack <#C2DXMessageCallBack description#>
         */
        typedef void(*C2DXMessageCallBack) (int action, C2DXMobPushMessage* message);

        /**
         <#Description#>

         @param C2DXAlias <#C2DXAlias description#>
         */
        typedef void(*C2DXAliasCallBack) (const char *alias, int operation, int errorCode);

        /**
         <#Description#>

         @param onTags <#onTags description#>
         */
        typedef void(*C2DXTagsCallBack) (std::list<std::string> tags, int operation, int errorCode);
    }
}

#endif /* C2DXMobPushCallBack_h */