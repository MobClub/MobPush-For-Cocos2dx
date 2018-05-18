//
//  C2DXiOSMobPushCallBack.m
//  MobPush-For-Cocos2dx-mobile
//
//  Created by youzu on 2018/5/17.
//

#import "C2DXiOSMobPushCallBack.h"
#import <MobPush/MobPush.h>
#import "C2DXiOSMobPush.h"
#import <MOBFoundation/MOBFJson.h>

using namespace mob::mobpush;

@implementation C2DXiOSMobPushCallBack

+ (instancetype)defaultCallBack
{
    static id instance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        instance = [[self alloc] init];
    });
    return instance;
}

- (void)addPushObserver
{
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(didReceiveMessage:) name:MobPushDidReceiveMessageNotification
                                               object:nil];
}

// 收到通知回调
- (void)didReceiveMessage:(NSNotification *)notification
{
    MPushMessage *message = notification.object;
    int action;
    
    NSMutableDictionary *reslut = [NSMutableDictionary dictionary];

    switch (message.messageType)
    {
        case MPushMessageTypeCustom:
        {// 自定义消息
            action = 0;

            [reslut setObject:@1 forKey:@"msgType"];

            if (message.extraInfomation)
            {
                [reslut setObject:message.extraInfomation forKey:@"extra"];
            }
            
            if (message.content)
            {
                [reslut setObject:message.content forKey:@"content"];
            }
            
            if (message.messageID)
            {
                [reslut setObject:message.messageID forKey:@"messageId"];
            }
            
            if (message.currentServerTimestamp)
            {
                [reslut setObject:@(message.currentServerTimestamp) forKey:@"timeStamp"];
            }
        }
            break;
        case MPushMessageTypeAPNs:
        {// APNs 回调
            /*
             {
             1 = 2;
             aps =     {
             alert =         {
             body = 1;
             subtitle = 1;
             title = 1;
             };
             "content-available" = 1;
             "mutable-content" = 1;
             };
             mobpushMessageId = 159346875878223872;
             }
             */
            
            [reslut setObject:@2 forKey:@"msgType"];

            if (message.apnsDict.count)
            {
                NSDictionary *aps = message.apnsDict[@"aps"];
                if ([aps isKindOfClass:[NSDictionary class]])
                {
                    NSDictionary *alert = aps[@"alert"];
                    if ([alert isKindOfClass:[NSDictionary class]])
                    {
                        NSString *body = alert[@"body"];
                        if (body)
                        {
                            [reslut setObject:body forKey:@"content"];
                        }
                        
                        NSString *subtitle = alert[@"subtitle"];
                        if (subtitle)
                        {
                            [reslut setObject:subtitle forKey:@"subtitle"];
                        }
                        
                        NSString *title = alert[@"title"];
                        if (title)
                        {
                            [reslut setObject:title forKey:@"title"];
                        }
                    }
                    
                    NSString *sound = aps[@"sound"];
                    if (sound)
                    {
                        [reslut setObject:sound forKey:@"sound"];
                    }
                    
                    NSInteger badge = [aps[@"badge"] integerValue];
                    if (badge)
                    {
                        [reslut setObject:@(badge) forKey:@"badge"];
                    }
                    
                }
            }
            
            NSString *mobpushMessageId = message.apnsDict[@"mobpushMessageId"];
            if (mobpushMessageId)
            {
                [reslut setObject:mobpushMessageId forKey:@"messageId"];
            }
            
            NSMutableDictionary *extra = [NSMutableDictionary dictionary];
            [message.apnsDict enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, id  _Nonnull obj, BOOL * _Nonnull stop) {
                
                if (![key isEqualToString:@"aps"] && ![key isEqualToString:@"mobpushMessageId"])
                {
                    [extra setObject:obj forKey:key];
                }
                
            }];
            
            if (extra.count)
            {
                [reslut setObject:extra forKey:@"extra"];
            }
            
            if ([UIApplication sharedApplication].applicationState == UIApplicationStateActive)
            {
                // 前台收到
                action = 1;
            }
            else
            {
                // 点击通知
                action = 2;
            }
        }
            break;
        case MPushMessageTypeLocal:
        { // 本地通知回调
            [reslut setObject:@3 forKey:@"msgType"];
            
            NSString *body = message.notification.body;
            NSString *title = message.notification.title;
            NSString *subtitle = message.notification.subTitle;
            NSInteger badge = message.notification.badge;
            NSString *sound = message.notification.sound;
            if (body)
            {
                [reslut setObject:body forKey:@"content"];
            }

            if (title)
            {
                [reslut setObject:title forKey:@"title"];
            }

            if (subtitle)
            {
                [reslut setObject:subtitle forKey:@"subtitle"];
            }

            if (badge)
            {
                [reslut setObject:@(badge) forKey:@"badge"];
            }

            if (sound)
            {
                [reslut setObject:sound forKey:@"sound"];
            }
            
            if ([UIApplication sharedApplication].applicationState == UIApplicationStateActive)
            {
                // 前台收到
                action = 1;
            }
            else
            {
                // 点击通知
                action = 2;
            }
        }
            break;
        default:
            break;
    }
    
    if (reslut.count)
    {
        NSString *resultStr = [MOBFJson jsonStringFromObject:reslut];
        C2DXiOSMobPush::iOSMessageCallBack(action, [resultStr UTF8String]);
    }
    
}

- (void)dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

@end
