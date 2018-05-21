

//
//  C2DXMobPushCustomNotification.hpp
//  MobPush-For-Cocos2dx-mobile
//
//  Created by LeeJay on 2018/5/17.
//

#ifndef C2DXMobPushCustomNotification_hpp
#define C2DXMobPushCustomNotification_hpp

#include <stdio.h>
#include "C2DXMobPushTypeDef.h"

enum AuthorizationType {
    AuthorizationTypeNone = 0, //不提醒
    AuthorizationTypeBadge = 1 << 0, //角标提醒
    AuthorizationTypeSound = 1 << 1, //声音提醒
    AuthorizationTypeAlert = 1 << 2, //弹框提醒
};

enum StyleType {
    STYLE_NORMAL = 0,
    STYLE_BIG_TEXT = 1,
    STYLE_BIG_PICTURE = 2,
    STYLE_INBOX = 3
};

namespace mob {
    namespace mobpush {
        class C2DXMobPushCustomNotification {
        public:
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
            StyleType style;//标题栏样式
            C2DXString *tickerText;//设置通知在状态栏的提示文本
            C2DXString *iconName;//设置通知显示图标
            C2DXString *title;//设置通知标题
            C2DXString *content;//设置通知内容
            C2DXString *styleContent;//设置BIG样式显示的文本内容
            C2DXString *inboxStyleContent;//设置BIG样式展开的文本内容,多个文本使用，号间隔
            int shake;//设置震动，1是震动，2是不震动
            int light;//设置闪光，1是闪光，2是不闪光
            int voice;//设置声音，1是声音，2是静音
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
            AuthorizationType type;
#endif

        };

    }

}

#endif /* C2DXMobPushCustomNotification_hpp */