#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include <ui/UIButton.h>
#include "cocos2d.h"

using namespace cocos2d;
using namespace cocos2d::ui;

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

    void onTouch(Ref* sender,TouchEventType type);
};



#endif // __HELLOWORLD_SCENE_H__
