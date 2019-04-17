//
//  C2DXiOSMobPush.h
//  MobPush-For-Cocos2dx-mobile
//
//  Created by LeeJay on 2018/5/16.
//


#include "cocos2d.h"
#include "C2DXMobPushCallback.h"

#include "C2DXMobPushLocalNotification.hpp"
#include "C2DXMobPushCustomNotification.hpp"

USING_NS_CC;

namespace mob {
    namespace mobpush {
        class C2DXiOSMobPush {
        public:
            
            /**
             设置推送环境 （在applicationDidFinishLaunching调用，仅限 iOS，安卓忽略）
             
             @param isPro false：开发环境 true：生产环境
             */
            static void setAPNsForProduction(bool isPro);
            
            /**
             初始化 SDK（仅限安卓，iOS 在 infoplist 配置 appkey 和 secret）
             
             @param appkey appkey
             @param appScrect appScrect
             */
            static void initMobPush(const char *appkey, const char *appScrect);
            
            /**
             获取注册id
             
             @param callback 返回注册id的回调
             */
            static void getRegistrationId(C2DXGetRegistrationIdResultEvent callback);
            
            /**
             设置推送监听
             */
            static void addPushReceiver();
            
            /**
             设置别名
             
             @param alias 别名名称（为空时无效）
             */
            static void setAlias(const char *alias);
            
            /**
             获取当前设置的别名
             */
            static void getAlias();
            
            /**
             删除别名
             */
            static void clearAllAlias();
            
            /**
             添加标签
             
             @param tags 标签集合
             */
            static void addTags(C2DXArray *tags);
            
            /**
             获取标签集合
             */
            static void getTags();
            
            /**
             删除标签
             
             @param tags 标签集合
             */
            static void deleteTags(C2DXArray *tags);
            
            /**
             清空标签
             */
            static void clearAllTags();
            
            /**
             添加本地通知
             
             @param noti 本地通知对象
             */
            static void addLocalNotification(mob::mobpush::C2DXMobPushLocalNotification *noti);
            
            /**
             定制通知样式
             
             @param noti 通知对象
             */
            static void setCustomNotification(mob::mobpush::C2DXMobPushCustomNotification *noti);
            
            
            /**
             设置应用在前台是否展示通知横幅

             @param hidden 是否展示
             */
            static void setAppForegroundHiddenNotification(bool hidden);
            
            /**
             绑定手机号，短信补量

             @param phoneNum 手机号
             */
            static void bindPhoneNum(const char *phoneNum, C2DXReqResultEvent callback);
            
/**
 模拟发送推送消息
 
 @param type 消息类型：1、通知测试；2、内推测试；3、定时
 @param text 模拟发送内容，500字节以内，UTF-8
 @param space 仅对定时消息有效，单位分钟，默认1分钟
 @param extras 附加字段
 @param reqResultEvent 回调
 */
static void req(int type, const char *text, int space, const char *extras,
                C2DXReqResultEvent reqResultEvent);
            
            /**
             收到消息回调 （需要先调用 addPushReceiver）
             
             @param messageCallBack 回调
             */
            static void setC2DXMessageCallBack(C2DXMessageCallBack messageCallBack);
            
            /**
             别名回调
             
             @param aliasCallBack 回调
             */
            static void setC2DXAliasCallBack(C2DXAliasCallBack aliasCallBack);
            
            /**
             标签回调
             
             @param tagsCallBack 回调
             */
            static void setC2DXTagsCallBack(C2DXTagsCallBack tagsCallBack);
            
            /**
             iOS 收到消息回调 （开发者忽略）

             @param action (action： 0自定义消息, 1收到消息, 2点击消息)
             @param message 消息实体
             */
            static void iOSMessageCallBack(int action, const char *message);
            
        };
        
    }
}

