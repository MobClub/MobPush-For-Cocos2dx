//
// Created by yyfu on 2018/5/16.
//

#ifndef PROJ_ANDROID_STUDIO_C2DXMOBPUSHNOTIFYMESSAGE_H
#define PROJ_ANDROID_STUDIO_C2DXMOBPUSHNOTIFYMESSAGE_H


#include "CCDictionary.h"
#include "cocos2d.h"
#include <stdint.h>

USING_NS_CC;

class C2DXMobPushNotifyMessage {
private:
    char *content;
    char *messageId;//消息id
//HashMap<String, String> extrasMap;//附加字段
    long timestamp;//当前服务器时间
    __Dictionary *dictionary;
public:
    C2DXMobPushNotifyMessage();

    virtual ~C2DXMobPushNotifyMessage();
};


#endif //PROJ_ANDROID_STUDIO_C2DXMOBPUSHNOTIFYMESSAGE_H
