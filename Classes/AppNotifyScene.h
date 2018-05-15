#ifndef __APPNOTIFY_SCENE_H__
#define __APPNOTIFY_SCENE_H__

#include <ui/UIButton.h>
#include <ui/UIEditBox/UIEditBox.h>
#include "cocos2d.h"

using namespace cocos2d;
using namespace cocos2d::ui;

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

private:
    EditBox* mEditBox;
};

class Ed : public cocos2d::ui::EditBoxDelegate
{
    void editBoxReturn(EditBox* editBox);
};

#endif // __APPNOTIFY_SCENE_H__
