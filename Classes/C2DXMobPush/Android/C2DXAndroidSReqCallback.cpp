//
// Created by yyfu on 2018/5/14.
//
#include <jni.h>
#include "C2DXAndroidSReqCallback.h"

C2DXAndroidSReqCallback::C2DXAndroidSReqCallback() {
    callback = NULL;
}

void C2DXAndroidSReqCallback::onCallback(jobject result) {
    C2DXReqResultEvent event = callback;
    if (event) {
        event(result);
    }
}

void C2DXAndroidSReqCallback::setC2DXAndroidSReqCallback(C2DXReqResultEvent event) {
    callback = event;
}

C2DXAndroidSReqCallback::~C2DXAndroidSReqCallback() {

}