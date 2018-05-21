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

            static void setAPNsForProduction(bool isPro);
            
            static void initMobPush(const char *appkey, const char *appScrect);

            /**
             *  获取注册id
             *
             *  @param callback 返回注册id的回调
             */
            static void getRegistrationId(C2DXGetRegistrationIdResultEvent callback);

            /**
             *  设置推送监听
             */
            static void addPushReceiver();

            /**
             * 设置别名
             *
             * @param alias 别名名称（为空时无效）
             */
            static void setAlias(const char *alias);

            /**
             * 获取当前设置的别名
             */
            static void getAlias();

            /**
	         * 删除别名
	         */
            static void clearAllAlias();

            /**
             * 添加标签
             *
             * @param tags 标签集合
             */
            static void addTags(C2DXArray *tags);

            static void getTags();

            static void deleteTags(C2DXArray *tags);

            static void clearAllTags();

            /**
             * 添加本地通知
             *
             * @param notification 本地通知对象
             */
            static void addLocalNotification(mob::mobpush::C2DXMobPushLocalNotification *noti);
            
            static void setCustomNotification(mob::mobpush::C2DXMobPushCustomNotification *noti);

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
            
            static void setC2DXMessageCallBack(C2DXMessageCallBack messageCallBack);
            
            static void setC2DXAliasCallBack(C2DXAliasCallBack aliasCallBack);
            
            static void setC2DXTagsCallBack(C2DXTagsCallBack tagsCallBack);

        };

    }
}

#endif
