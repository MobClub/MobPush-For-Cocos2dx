#ifndef __TIMENOTIFY_SCENE_H__
#define __TIMENOTIFY_SCENE_H__

#include <ui/UIButton.h>
#include <ui/UIEditBox/UIEditBox.h>
#include "cocos2d.h"
#include "C2DXMobPush/C2DXMobPushReceiver.h"

using namespace cocos2d;
using namespace cocos2d::ui;
using namespace mob::mobpush;

class TimeNotify : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(TimeNotify);

    void onTouch(Ref* sender,TouchEventType type);

    static void getId(const char* c);
    static void getSendReqResult(jobject result);

private:
    EditBox* mEditBox;
};

class PushReceiver2 : public C2DXMobPushReceiver
{
    void onCustomMessageReceive(jobject context, jobject mobPushCustomMessage);
    void onNotifyMessageReceive(jobject context, jobject mobPushNotifyMessage);
    void onNotifyMessageOpenedReceive(jobject context, jobject mobPushNotifyMessage);
    void onTagsCallback(jobject context, jobjectArray tags, jint i, jint j1);
    void onAliasCallback(jobject context, jstring alias, jint i, jint j1);
};

#endif // __APPNOTIFY_SCENE_H__
