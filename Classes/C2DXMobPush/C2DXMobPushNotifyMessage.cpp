//
// Created by yyfu on 2018/5/16.
//

#include "C2DXMobPushNotifyMessage.h"


C2DXMobPushNotifyMessage::C2DXMobPushNotifyMessage(int style, std::string title,
                                                   std::string content, std::string styleContent,
                                                   std::list<std::string> inboxStyleContent,
                                                   C2DXDictionary *extrasMap, std::string messageId,
                                                   long timestamp, bool voice, bool shake,
                                                   bool light, int channel) {
    C2DXMobPushNotifyMessage::style = style;
    C2DXMobPushNotifyMessage::title = title;
    C2DXMobPushNotifyMessage::content = content;
    C2DXMobPushNotifyMessage::styleContent = styleContent;
    C2DXMobPushNotifyMessage::inboxStyleContent = inboxStyleContent;
    C2DXMobPushNotifyMessage::extrasMap = extrasMap;
    C2DXMobPushNotifyMessage::messageId = messageId;
    C2DXMobPushNotifyMessage::timestamp = timestamp;
    C2DXMobPushNotifyMessage::voice = voice;
    C2DXMobPushNotifyMessage::shake = shake;
    C2DXMobPushNotifyMessage::light = light;
    C2DXMobPushNotifyMessage::channel = channel;
}

C2DXMobPushNotifyMessage::~C2DXMobPushNotifyMessage() {

}

int C2DXMobPushNotifyMessage::getStyle() {
    return C2DXMobPushNotifyMessage::style;
}


std::string C2DXMobPushNotifyMessage::getTitle() {
    return C2DXMobPushNotifyMessage::title;
}

std::string C2DXMobPushNotifyMessage::getContent() {
    return C2DXMobPushNotifyMessage::content;
}

std::string C2DXMobPushNotifyMessage::getStyleContent() {
    return C2DXMobPushNotifyMessage::styleContent;
}

std::list<std::string> C2DXMobPushNotifyMessage::getInboxStyleContent() {
    return C2DXMobPushNotifyMessage::inboxStyleContent;
}

C2DXDictionary *C2DXMobPushNotifyMessage::getExtrasMap() {
    return C2DXMobPushNotifyMessage::extrasMap;
}

std::string C2DXMobPushNotifyMessage::getMessageId() {
    return C2DXMobPushNotifyMessage::messageId;
}

long C2DXMobPushNotifyMessage::getTimestamp() {
    return C2DXMobPushNotifyMessage::timestamp;
}

bool C2DXMobPushNotifyMessage::getVoice() {
    return C2DXMobPushNotifyMessage::voice;
}

bool C2DXMobPushNotifyMessage::getShake() {
    return C2DXMobPushNotifyMessage::shake;
}

bool C2DXMobPushNotifyMessage::getLight() {
    return C2DXMobPushNotifyMessage::light;
}

int C2DXMobPushNotifyMessage::getChannel() {
    return C2DXMobPushNotifyMessage::channel;
}
