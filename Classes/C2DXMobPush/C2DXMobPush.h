//
//
//  Created by 小新 on 2018/5/11.
//
//

#ifndef __C2DXMobPushSample__C2DXMobPush__
#define __C2DXMobPushSample__C2DXMobPush__

#include "cocos2d.h"
#include "C2DXMobPushCallback.h"
#include "C2DXMobPushReceiver.h"
#include "C2DXMobPushLocalNotification.h"

USING_NS_CC;

namespace mob {
    namespace mobpush {
        class C2DXMobPush {
        public:

            static void initMobPush(const char *appkey, const char *appScrect);

            /**
             *  获取注册id
             *
             *  @param callback 返回注册id的回调
             */
            static void getRegistrationId(C2DXGetRegistrationIdResultEvent callback);

            /**
             *  设置推送监听
             *
             *  @param pushReceiver 设置推送监听
             */
            static void addPushReceiver(C2DXMobPushReceiver *pushReceiver);

            /**
             *  移除推送监听
             *
             *  @param pushReceiver 移除推送监听
             */
            static void removePushReceiver(C2DXMobPushReceiver *pushReceiver);

            /**
             * 设置别名
             *
             * @param alias 别名名称（为空时无效）
             */
            static void setAlias(const char *alias);

            static char getAlias();

            static char clearAllAlias();

            /**
             * 添加标签
             *
             * @param tags 标签集合
             */
            static void addTags(std::list<std::string> tags);

            static void getTags();

            static void deleteTags(std::list<std::string> tags);

            static void clearAllTags();

            /**
             * 添加本地通知
             *
             * @param notification 本地通知对象
             */
            static void addLocalNotification(const char *text, int space);

            static void setCustomNotification(long when, const char *tickerText, const char *title,
                                              const char *content, int flag, int style,
                                              const char *styleContent,
                                              std::list<std::string> inboxStyleContent,
                                              const char *smallIcon, boolean voice, boolean shake,
                                              boolean light);

            /**
			 * 模拟发送推送消息
			 *
			 * @param type 消息类型：1、通知测试；2、内推测试；3、定时
			 * @param text  模拟发送内容，500字节以内，UTF-8
			 * @param space 仅对定时消息有效，单位分钟，默认1分钟
             *
			 */
            static void req(int type, const char *text, int space, const char *extras,
                            C2DXReqResultEvent reqResultEvent);

        };

    }
}

#endif