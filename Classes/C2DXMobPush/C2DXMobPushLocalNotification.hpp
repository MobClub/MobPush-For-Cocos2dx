//
//  C2DXMobPushLocalNotification.hpp
//  MobPush-For-Cocos2dx-mobile
//
//  Created by LeeJay on 2018/5/17.
//

#ifndef C2DXMobPushLocalNotification_hpp
#define C2DXMobPushLocalNotification_hpp

#include <stdio.h>

namespace mob {
    namespace mobpush {
        class C2DXMobPushLocalNotification {
        public:

            const char *content;

            const char *title;

            long timeStamp;

            const char *subTitle;

            const char *sound;

            int badge;

//        public:
//
//            C2DXMobPushLocalNotification(){
//
//            }
//
//            virtual ~C2DXMobPushLocalNotification(){
//
//            }
        };

    }

}

#endif /* C2DXMobPushLocalNotification_hpp */
