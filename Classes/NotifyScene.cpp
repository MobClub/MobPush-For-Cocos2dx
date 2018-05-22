#include <ui/UIButton.h>
#include <ui/UIEditBox/UIEditBox.h>
#include "NotifyScene.h"
#include "AppDelegate.h"
#include "cocos2d.h"
#include "C2DXMobPush.h"
#include "AppNotifyScene.h"

#define  LOG_TAG    "notifyscene"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)

USING_NS_CC;
using namespace cocos2d::ui;
using namespace mob::mobpush;

Scene *Notify::createScene() {
    return Notify::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char *filename) {
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool Notify::init() {
    //////////////////////////////
    // 1. super init first
    if (!Scene::init()) {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    auto closeItem = MenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            CC_CALLBACK_1(Notify::menuCloseCallback, this));

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


    auto s = Size(visibleSize.width - 40, 30);  //设置编辑框大小
    //Scale9Sprite类似android上的9图工具,可对图片进行拉伸而不失真
    auto m9pic = Scale9Sprite::create();

    mEditBox = EditBox::create(s, m9pic);
    mEditBox->setFontSize(13);        //编辑框文本大小
    mEditBox->setFontColor(Color3B::WHITE);  //编辑框文本颜色
    mEditBox->setPlaceHolder("请输入内容:");  //编辑框提示语句
    mEditBox->setPlaceholderFontColor(Color3B::GRAY); //编辑框提示语句颜色
    mEditBox->setInputFlag(EditBox::InputFlag::SENSITIVE);//编辑框文本框输入类型
    mEditBox->setInputMode(EditBox::InputMode::ANY); //编辑框文本的输入模式
    mEditBox->setPosition(Vec2(visibleSize.width / 2 + origin.x,
                               origin.y + visibleSize.height -
                               mEditBox->getContentSize().height));
    this->addChild(mEditBox);

    auto button = Button::create();
    button->setTitleText("发送");
    button->setTitleFontSize(13);
    button->setPosition(Vec2(visibleSize.width / 2 + origin.x,
                             origin.y + visibleSize.height -
                             button->getContentSize().height * 7));
    button->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type) {
        if (type == ui::Widget::TouchEventType::ENDED) {
        
            C2DXMobPush::req(1, mEditBox->getText(), 0, NULL, &Notify::getSendReqResult);
        }
    });

    this->addChild(button);
    return true;
}


void Notify::menuCloseCallback(Ref *pSender) {
    Director::getInstance()->popScene();
}

void Notify::getSendReqResult(bool result) {
    if (result) {
        CCLOG(">>>getSendReqResult>>>>>%s", "true");
    } else {
        CCLOG(">>>>getSendReqResult>>>>%s", "false");
    }
}
