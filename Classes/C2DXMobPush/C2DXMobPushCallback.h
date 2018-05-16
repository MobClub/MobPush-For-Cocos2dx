//
//
//  Created by 小新 on 2018/5/11.
//
//
#ifndef __C2DXMobPushSample__C2DXMobPushCallback__
#define __C2DXMobPushSample__C2DXMobPushCallback__

#include <stdio.h>
#include "../../cocos2d/external/jpeg/include/android/jmorecfg.h"

namespace mob
{
    namespace mobpush
    {
        /**
         *  获取mobid之回调
         *
         *  @param C2DXGetRegistrationIdResultEvent 回调registrationId
         */
        typedef void(*C2DXGetRegistrationIdResultEvent) (const char * registrationId);
        typedef void(*C2DXReqResultEvent) (bool reqResult);
    }
}

#endif /* C2DXMobPushCallBack_h */