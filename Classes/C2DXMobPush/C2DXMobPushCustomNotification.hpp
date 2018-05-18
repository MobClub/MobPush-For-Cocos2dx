//
//  C2DXMobPushCustomNotification.hpp
//  MobPush-For-Cocos2dx-mobile
//
//  Created by LeeJay on 2018/5/17.
//

#ifndef C2DXMobPushCustomNotification_hpp
#define C2DXMobPushCustomNotification_hpp

#include <stdio.h>

enum AuthorizationType
{
    AuthorizationTypeNone =  0, //不提醒
    AuthorizationTypeBadge = 1 << 0, //角标提醒
    AuthorizationTypeSound = 1 << 1, //声音提醒
    AuthorizationTypeAlert = 1 << 2, //弹框提醒
};

namespace mob
{
    namespace mobpush
    {
        class C2DXMobPushCustomNotification
        {
        public:
            
            AuthorizationType type;
            
        };
        
    }
    
}

#endif /* C2DXMobPushCustomNotification_hpp */
