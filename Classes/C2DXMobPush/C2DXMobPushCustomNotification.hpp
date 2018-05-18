//
//  C2DXMobPushCustomNotification.hpp
//  MobPush-For-Cocos2dx-mobile
//
//  Created by LeeJay on 2018/5/17.
//

#ifndef C2DXMobPushCustomNotification_hpp
#define C2DXMobPushCustomNotification_hpp

#include <stdio.h>

namespace mob
{
    namespace mobpush
    {
        class C2DXMobPushCustomNotification
        {
        public:
            
            enum AuthorizationType
            {
                None =  0, //不提醒
                Badge = 1 << 0, //角标提醒
                Sound = 1 << 1, //声音提醒
                Alert = 1 << 2, //弹框提醒
            };
            
            AuthorizationType type;
            
        };
        
    }
    
}

#endif /* C2DXMobPushCustomNotification_hpp */
