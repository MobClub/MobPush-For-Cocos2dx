//
// Created by yyfu on 2018/5/16.
//

#ifndef PROJ_ANDROID_STUDIO_C2DXMOBPUSHMESSAGE_H
#define PROJ_ANDROID_STUDIO_C2DXMOBPUSHMESSAGE_H

#include "C2DXMobPushTypeDef.h"


class C2DXMobPushMessage {
    enum MessageType {
        Custom, //自定义消息
        Notify,//远程通知
        Local //本地通知(ios区分本地和远程通知两种类型，android只有Notify一种通知类型)
    };

public:
    int style;//标题栏样式
    std::string title;//标题，如果为空，则默认显示为应用名称
    std::string content;//内容
    std::string styleContent;//大段文本和大图模式的样式内容
    std::list<std::string> inboxStyleContent;//收件箱样式的内容
    C2DXDictionary *extrasMap;//附加字段
    std::string messageId;//消息id
    long long timestamp;//发送时间
    bool voice = true;
    bool shake = true;
    bool light = true;
    MessageType messageType;
    int channel;

public:
    C2DXMobPushMessage() {

    }

    virtual ~C2DXMobPushMessage() {

    }
};


#endif //PROJ_ANDROID_STUDIO_C2DXMOBPUSHCUSTOMMESSAGE_H
