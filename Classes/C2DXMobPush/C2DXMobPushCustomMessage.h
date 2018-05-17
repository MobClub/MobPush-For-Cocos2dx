//
// Created by yyfu on 2018/5/16.
//

#ifndef PROJ_ANDROID_STUDIO_C2DXMOBPUSHCUSTOMMESSAGE_H
#define PROJ_ANDROID_STUDIO_C2DXMOBPUSHCUSTOMMESSAGE_H

#include "C2DXMobPushTypeDef.h"


class C2DXMobPushCustomMessage {
private:
    std::string content;//消息内容
    std::string msgId;//消息id
    long timestamp;//当前服务器时间
    C2DXDictionary *extrasMap;//附加字段

public:
    std::string getContent();
    std::string getMsgId();
    long getTimestamp();
    C2DXDictionary* getExtrasMap();

public:
    C2DXMobPushCustomMessage(std::string content, std::string msgId, long timestamp, C2DXDictionary *extrasMap);

    virtual ~C2DXMobPushCustomMessage();
};


#endif //PROJ_ANDROID_STUDIO_C2DXMOBPUSHCUSTOMMESSAGE_H
