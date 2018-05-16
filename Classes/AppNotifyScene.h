#ifndef __APPNOTIFY_SCENE_H__
#define __APPNOTIFY_SCENE_H__

#include <ui/UIButton.h>
#include <ui/UIEditBox/UIEditBox.h>
#include "cocos2d.h"
#include "./C2DXMobPush/C2DXMobPushReceiver.h"

using namespace cocos2d;
using namespace cocos2d::ui;
using namespace mob::mobpush;

class AppNotify : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(AppNotify);

    void onTouch(Ref* sender,TouchEventType type);

    static void getId(const char* c);
    static void getSendReqResult(bool result);

private:
    EditBox* mEditBox;
};

class PushReceiver : public C2DXMobPushReceiver
{
    void onCustomMessageReceive(C2DXMobPushCustomMessage mobPushCustomMessage);
    void onNotifyMessageReceive(C2DXMobPushNotifyMessage mobPushNotifyMessage);
    void onNotifyMessageOpenedReceive(C2DXMobPushNotifyMessage mobPushNotifyMessage);
    void onTagsCallback(std::list<std::string>& tags, int i, int j1);
    void onAliasCallback(const char* alias, int i, int j1);
};

#endif // __APPNOTIFY_SCENE_H__
