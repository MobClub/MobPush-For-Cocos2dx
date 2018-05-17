//
// Created by yyfu on 2018/5/16.
//

#include "C2DXMobPushCustomMessage.h"

C2DXMobPushCustomMessage::C2DXMobPushCustomMessage(std::string content, std::string msgId,
                                                   long timestamp, C2DXDictionary *extrasMap) {
    C2DXMobPushCustomMessage::content = content;
    C2DXMobPushCustomMessage::msgId = msgId;
    C2DXMobPushCustomMessage::timestamp = timestamp;
    C2DXMobPushCustomMessage::extrasMap = extrasMap;
}

C2DXMobPushCustomMessage::~C2DXMobPushCustomMessage() {

}

std::string C2DXMobPushCustomMessage::getContent() {
    return C2DXMobPushCustomMessage::content;
}

std::string C2DXMobPushCustomMessage::getMsgId() {
    return C2DXMobPushCustomMessage::msgId;
}

long C2DXMobPushCustomMessage::getTimestamp() {
    return C2DXMobPushCustomMessage::timestamp;
}

C2DXDictionary* C2DXMobPushCustomMessage::getExtrasMap() {
    return C2DXMobPushCustomMessage::extrasMap;
}
