//
//
//  Created by 小新 on 2018/5/11.
//
//

#ifndef __C2DXMobPushSample__C2DXMobPush__
#define __C2DXMobPushSample__C2DXMobPush__

#include "cocos2d.h"
#include "C2DXMobPushCallback.h"
#include "C2DXMobPushLocalNotification.hpp"
#include "C2DXMobPushCustomNotification.hpp"

USING_NS_CC;

namespace mob {
    namespace mobpush {
        class C2DXMobPush {
        public:

            /**
             设置推送环境 （在applicationDidFinishLaunching调用，仅限 iOS，安卓忽略）

             @param isPro false：开发环境 true：生产环境
             */
            static void setAPNsForProduction(bool isPro);

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
             设置通知图标

             @param resIcon 图标资源名（为空时无效，仅限安卓，iOS忽略）
             */
            static void setNotifyIcon(const char *resIcon);

            /**
             设置应用正在运行在前台时接收到推送是否显示通知

             @param hidden 是否显示通知（true 表示不显示通知，false 表示显示通知，仅限安卓，iOS忽略）
             */
            static void setAppForegroundHiddenNotification(bool hidden);

            /**
             添加本地通知

             @param noti 本地通知对象
             */
            static void addLocalNotification(mob::mobpush::C2DXMobPushLocalNotification *noti);


            /**
             定制通知样式

             @param noti 通知对象 (仅限 iOS，安卓忽略)
             */
            static void setCustomNotification(mob::mobpush::C2DXMobPushCustomNotification *noti);

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
             绑定手机号

             @param callback 回调
             */

            static void bindPhoneNum(const char* phoneNum, C2DXReqResultEvent callback);

            /**
             设置显示角标

             @param show 是否显示角标（true 表示显示角标，false 表示不显示角标，仅限安卓，iOS忽略）
             */
            static void setShowBadge(bool show);
        };

    }
}

#endif
