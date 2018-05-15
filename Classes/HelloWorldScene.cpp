#include <ui/UIButton.h>
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "AppNotifyScene.h"

#define  LOG_TAG    "hellowordscene"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)

USING_NS_CC;
using namespace cocos2d::ui;

Scene *HelloWorld::createScene() {
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char *filename) {
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init() {
    //////////////////////////////
    // 1. super init first
    if (!Scene::init()) {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0) {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    } else {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
        float y = origin.y + closeItem->getContentSize().height / 2;
        closeItem->setPosition(Vec2(x, y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr) {
        problemLoading("'fonts/Marker Felt.ttf'");
    } else {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width / 2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
//        this->addChild(label, 1);
    }

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    if (sprite == nullptr) {
        problemLoading("'HelloWorld.png'");
    } else {
        // position the sprite on the center of the screen
        sprite->setPosition(
                Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

        // add the sprite as a child to this layer
//        this->addChild(sprite, 0);
    }

    auto button = Button::create();
    button->setTitleText("App内推送");
    button->setTitleFontSize(13);
    button->_ID = 1;
    button->setPosition(Vec2(visibleSize.width / 2 + origin.x,
                             origin.y + visibleSize.height - button->getContentSize().height * 2));
    button->addTouchEventListener(this, (SEL_TouchEvent) &HelloWorld::onTouch);
    this->addChild(button);

    button = Button::create();
    button->setTitleText("通知");
    button->setTitleFontSize(13);
    button->_ID = 2;
    button->setPosition(Vec2(visibleSize.width / 2 + origin.x,
                             origin.y + visibleSize.height - button->getContentSize().height * 4));
    button->addTouchEventListener(this, (SEL_TouchEvent) &HelloWorld::onTouch);
    this->addChild(button);

    button = Button::create();
    button->setTitleText("定时通知");
    button->setTitleFontSize(13);
    button->_ID = 3;
    button->setPosition(Vec2(visibleSize.width / 2 + origin.x,
                             origin.y + visibleSize.height - button->getContentSize().height * 6));
    button->addTouchEventListener(this, (SEL_TouchEvent) &HelloWorld::onTouch);
    this->addChild(button);

    button = Button::create();
    button->setTitleText("本地通知");
    button->setTitleFontSize(13);
    button->_ID = 4;
    button->setPosition(Vec2(visibleSize.width / 2 + origin.x,
                             origin.y + visibleSize.height - button->getContentSize().height * 8));
    button->addTouchEventListener(this, (SEL_TouchEvent) &HelloWorld::onTouch);
    this->addChild(button);

    button = Button::create();
    button->setTitleText("通过推送打开指定页面");
    button->setTitleFontSize(13);
    button->_ID = 5;
    button->setPosition(Vec2(visibleSize.width / 2 + origin.x,
                             origin.y + visibleSize.height - button->getContentSize().height * 10));
    button->addTouchEventListener(this, (SEL_TouchEvent) &HelloWorld::onTouch);
    this->addChild(button);

    return true;
}


void HelloWorld::menuCloseCallback(Ref *pSender) {
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}


void HelloWorld::onTouch(Ref *sender, TouchEventType type) {
    auto id = sender->_ID;
    switch (type) {
        case TOUCH_EVENT_ENDED:
            if (id == 1) {
                Director::getInstance()->pushScene(AppNotify::createScene());
            } else if (id == 2) {
                CCLOG(">>>>>>>>>>>%d", 2);
            } else if (id == 3) {
                CCLOG(">>>>>>>>>>>%d", 3);
            } else if (id == 4) {
                CCLOG(">>>>>>>>>>>%d", 4);
            } else if (id == 5) {
                CCLOG(">>>>>>>>>>>%d", 5);
            }
            break;

    }
}
