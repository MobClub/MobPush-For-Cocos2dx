//
//  C2DXiOSMobPush.m
//  MobPush-For-Cocos2dx-mobile
//
//  Created by LeeJay on 2018/5/16.
//

#include "C2DXiOSMobPush.h"
#include "cocos2d.h"
#include "../C2DXMobPushCallback.h"

#import <MobPush/MobPush.h>
#import <MobPush/MobPush+Test.h>
#import <MobPush/MPushMessage.h>
#import "C2DXiOSMobPushCallBack.h"

using namespace mob::mobpush;

void C2DXiOSMobPush::setAPNsForProduction(bool isPro)
{
    [C2DXiOSMobPushCallBack defaultCallBack].isPro = isPro == true ? YES : NO;
    [MobPush setAPNsForProduction:isPro == true ? YES : NO];
}

void C2DXiOSMobPush::getRegistrationId(C2DXGetRegistrationIdResultEvent callback)
{
    [MobPush getRegistrationID:^(NSString *registrationID, NSError *error) {
        if (callback)
        {
            callback([registrationID UTF8String]);
        }
    }];
}

void C2DXiOSMobPush::addPushReceiver()
{
    [[C2DXiOSMobPushCallBack defaultCallBack] addPushObserver];
}

void C2DXiOSMobPush::setAlias(const char *alias)
{
    NSString *aliasStr = [NSString stringWithUTF8String:alias];
    [MobPush setAlias:aliasStr result:^(NSError *error) {
        
    }];
}

void C2DXiOSMobPush::getAlias()
{
    [MobPush getAliasWithResult:^(NSString *alias, NSError *error) {
        
    }];
}

void C2DXiOSMobPush::clearAllAlias()
{
    [MobPush deleteAlias:^(NSError *error) {
        
    }];
}

void C2DXiOSMobPush::getTags()
{
    [MobPush getTagsWithResult:^(NSArray *tags, NSError *error) {
        
    }];
}

void C2DXiOSMobPush::addTags(C2DXArray tags)
{
    [MobPush addTags:nil result:^(NSError *error) {
//        C2DXTagsCallBack();
    }];
}

void C2DXiOSMobPush::deleteTags(C2DXArray tags)
{
    [MobPush deleteTags:nil result:^(NSError *error) {
        
    }];
}

void C2DXiOSMobPush::clearAllTags()
{
    [MobPush cleanAllTags:^(NSError *error) {
        
    }];
}

void C2DXiOSMobPush::addLocalNotification(mob::mobpush::C2DXMobPushLocalNotification *noti)
{
    MPushMessage *message = [[MPushMessage alloc] init];
    message.messageType = MPushMessageTypeLocal;
    MPushNotification *notification = [[MPushNotification alloc] init];
    
    notification.title = [NSString stringWithUTF8String:noti->title];
    notification.body = [NSString stringWithUTF8String:noti->content];
    notification.sound = [NSString stringWithUTF8String:noti->sound];
    notification.badge = (NSInteger)noti->badge;
    notification.subTitle = [NSString stringWithUTF8String:noti->subTitle];
    
    long timeStamp = noti->timeStamp;
    if (timeStamp == 0)
    {
        message.isInstantMessage = YES;
    }
    else
    {
        NSDate *currentDate = [NSDate dateWithTimeIntervalSinceNow:0];
        NSTimeInterval nowtime = [currentDate timeIntervalSince1970] * 1000;
        message.taskDate = nowtime + (NSTimeInterval)timeStamp;
    }
    
    message.notification = notification;
    [MobPush addLocalNotification:message];
}

void C2DXiOSMobPush::setCustomNotification(mob::mobpush::C2DXMobPushCustomNotification *noti)
{
    MPushNotificationConfiguration *noticonfig = [[MPushNotificationConfiguration alloc] init];
    noticonfig.types = (MPushAuthorizationOptions)noti->type;
    [MobPush setupNotification:noticonfig];
}

void C2DXiOSMobPush::req(int type, const char *text, int space, const char *extras,
         C2DXReqResultEvent reqResultEvent)
{
    NSString *textStr = [NSString stringWithUTF8String:text];

    [MobPush sendMessageWithMessageType:(MPushMsgType)type
                                content:textStr
                                  space:@(space)
                isProductionEnvironment:[C2DXiOSMobPushCallBack defaultCallBack].isPro
                                 extras:nil
                                 result:^(NSError *error) {
                                     
                                     if (error)
                                     {
                                         if (reqResultEvent)
                                         {
                                             reqResultEvent(true);
                                         }
                                     }
                                     else
                                     {
                                         if (reqResultEvent)
                                         {
                                             reqResultEvent(false);
                                         }
                                     }
                                     
                                 }];
}

