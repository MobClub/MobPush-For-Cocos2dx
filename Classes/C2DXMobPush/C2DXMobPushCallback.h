//
//
//  Created by 小新 on 2018/5/11.
//
//
#ifndef __C2DXMobPushSample__C2DXMobPushCallback__
#define __C2DXMobPushSample__C2DXMobPushCallback__

#include <stdio.h>

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
    }
}

#endif /* C2DXMobPushCallBack_h */