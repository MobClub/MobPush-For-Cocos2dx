#ifndef __APPNOTIFY_SCENE_H__
#define __APPNOTIFY_SCENE_H__

#include <ui/UIButton.h>
#include <ui/UIEditBox/UIEditBox.h>
#include "cocos2d.h"
#include "C2DXMobPushMessage.h"

using namespace cocos2d;
using namespace cocos2d::ui;

class AppNotify : public cocos2d::Scene {
public:
    static cocos2d::Scene *createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref *pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(AppNotify);

    void onTouch(Ref *sender, TouchEventType type);

    static void getId(const char *c);

    static void getSendReqResult(bool result);

    static void onC2DXAliasCallBack(const char *alias, int operation, int errorCode);

    static void onC2DXTagsCallBack(C2DXArray *tags, int operation, int errorCode);

private:
    EditBox *mEditBox;
};


#endif // __APPNOTIFY_SCENE_H__
