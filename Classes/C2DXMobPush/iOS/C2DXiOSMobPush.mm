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
//    [[C2DXiOSMobPushCallBack defaultCallBack] addPushObserver]
}

void C2DXiOSMobPush::setAlias(const char *alias)
{
    [MobPush setAlias:nil result:^(NSError *error) {
        
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

void C2DXiOSMobPush::addTags(std::list<std::string> tags)
{
    [MobPush addTags:nil result:^(NSError *error) {
        
    }];
}

void C2DXiOSMobPush::deleteTags(std::list<std::string> tags)
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
    [MobPush addLocalNotification:nil];
}

void C2DXiOSMobPush::setCustomNotification(mob::mobpush::C2DXMobPushCustomNotification *noti)
{
    
}

void C2DXiOSMobPush::req(int type, const char *text, int space, const char *extras,
         C2DXReqResultEvent reqResultEvent)
{
    [MobPush sendMessageWithMessageType:MPushMsgTypeNotification
                                content:nil
                                  space:@(1)
                isProductionEnvironment:[C2DXiOSMobPushCallBack defaultCallBack].isPro
                                 extras:nil
                                 result:^(NSError *error) {
                                     
                                     NSMutableDictionary *resultDict = [NSMutableDictionary dictionary];
                                     
                                     if (error)
                                     {
                                         [resultDict setObject:@(0) forKey:@"action"];
                                     }
                                     else
                                     {
                                         [resultDict setObject:@(1) forKey:@"action"];
                                     }
                                     
                                 }];
}

