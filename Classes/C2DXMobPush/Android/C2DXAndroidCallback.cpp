//
// Created by yyfu on 2018/5/14.
//
#include <jni.h>
#include "C2DXAndroidCallback.h"

C2DXAndroidCallback::C2DXAndroidCallback() {
    callback = NULL;
}

void C2DXAndroidCallback::onCallback(const char *result) {
    C2DXGetRegistrationIdResultEvent event = callback;
    if (event) {
        event(result);
    }
}

void C2DXAndroidCallback::setC2DXAndroidCallback(C2DXGetRegistrationIdResultEvent event) {
    callback = event;
}

C2DXAndroidCallback::~C2DXAndroidCallback() {

}