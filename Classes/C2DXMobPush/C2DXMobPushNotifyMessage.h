//
// Created by yyfu on 2018/5/16.
//

#ifndef PROJ_ANDROID_STUDIO_C2DXMOBPUSHNOTIFYMESSAGE_H
#define PROJ_ANDROID_STUDIO_C2DXMOBPUSHNOTIFYMESSAGE_H


#include "C2DXMobPushTypeDef.h"

USING_NS_CC;

class C2DXMobPushNotifyMessage {

private:
    int style;//标题栏样式
    std::string title;//标题，如果为空，则默认显示为应用名称
    std::string content;//内容
    std::string styleContent;//大段文本和大图模式的样式内容
    std::list<std::string> inboxStyleContent;//收件箱样式的内容
    C2DXDictionary *extrasMap;//附加字段
    std::string messageId;//消息id
    long timestamp;//发送时间
    bool voice = true;
    bool shake = true;
    bool light = true;
    int channel;

public:
    int getStyle();
    std::string getTitle();
    std::string getContent();
    std::string getStyleContent();
    std::list<std::string> getInboxStyleContent();
    C2DXDictionary* getExtrasMap();
    std::string getMessageId();
    long getTimestamp();
    bool getVoice();
    bool getShake();
    bool getLight();
    int getChannel();

public:
    C2DXMobPushNotifyMessage(int style, std::string title, std::string content, std::string styleContent,
                             std::list<std::string> inboxStyleContent, C2DXDictionary *extrasMap, std::string messageId,
                             long timestamp, bool voice, bool shake, bool light, int channel);

    virtual ~C2DXMobPushNotifyMessage();
};


#endif //PROJ_ANDROID_STUDIO_C2DXMOBPUSHNOTIFYMESSAGE_H
