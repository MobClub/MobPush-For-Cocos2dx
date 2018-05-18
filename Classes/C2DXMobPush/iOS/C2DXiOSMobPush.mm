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

/**
 *    @brief    转换NSDictionary为C2DXDictionary类型
 *
 *    @param     dict     字典
 *
 *    @return    字典类型
 */
C2DXDictionary* convertNSDictToCCDict(NSDictionary *dict);

/**
 *    @brief    转换C2DXDictionary为NSDictionary类型
 *
 *    @param     dict     字典
 *
 *    @return    字典类型
 */
NSMutableDictionary* convertC2DXDictionaryToNSDictionary(C2DXDictionary *Dictionary);

/**
 *    @brief    转换NSString为C2DXString类型
 *
 *    @param     string     字符串
 *
 *    @return    字符类型
 */
C2DXString* convertNSStringToC2DXString(NSString *string);

/**
 *    @brief    转换C2DXString为NSString类型
 *
 *    @param     string     字符串
 *
 *    @return    字符类型
 */
NSString* convertC2DXStringToNSString(C2DXString *String);

/**
 *    @brief    转换NSArray为C2DXArray类型
 *
 *    @param     array     数组
 *
 *    @return    数组类型
 */
C2DXArray* convertNSArrayToC2DXArray(NSArray *array);

/**
 *    @brief    转换C2DXArray为NSArray类型
 *
 *    @param     array     数组
 *
 *    @return    数组类型
 */
NSArray* convertC2DXArrayToNSArray(C2DXArray *Array);

C2DXDictionary* convertNSDictToCCDict(NSDictionary *dict)
{
    if (dict)
    {
        C2DXDictionary *ccDict = C2DXDictionary::create();
        NSArray *allKeys = [dict allKeys];
        for (int i = 0; i < [allKeys count]; i++)
        {
            NSString *key = [allKeys objectAtIndex:i];
            id value = [dict objectForKey:key];
            
            if ([value isKindOfClass:[NSString class]])
            {
                C2DXString *strValue = convertNSStringToC2DXString(value);
                if (strValue)
                {
                    ccDict -> setObject(strValue, [key UTF8String]);
                }
            }
            else if ([value isKindOfClass:[NSNumber class]])
            {
                C2DXString *strValue = convertNSStringToC2DXString([NSString stringWithFormat:@"%@", value]);
                if (strValue)
                {
                    ccDict -> setObject(strValue, [key UTF8String]);
                }
            }
            else if ([value isKindOfClass:[NSDate class]])
            {
                ccDict -> setObject(C2DXDouble::create([value timeIntervalSince1970] * 1000), [key UTF8String]);
            }
            else if ([value isKindOfClass:[NSDictionary class]])
            {
                C2DXDictionary *dictValue = convertNSDictToCCDict(value);
                if (dictValue)
                {
                    ccDict -> setObject(dictValue, [key UTF8String]);
                }
            }
            else if ([value isKindOfClass:[NSArray class]])
            {
                C2DXArray *arrValue = convertNSArrayToC2DXArray(value);
                if (arrValue)
                {
                    ccDict -> setObject(arrValue, [key UTF8String]);
                }
            }
        }
        return ccDict;
    }
    
    return NULL;
}

NSMutableDictionary * convertC2DXDictionaryToNSDictionary(C2DXDictionary * Dictionary)
{
    if (Dictionary)
    {
        NSMutableDictionary *dict = [NSMutableDictionary dictionary];
        C2DXArray *allkeys = Dictionary -> allKeys();
        
        if (allkeys != NULL)
        {
            for (int i = 0; i < allkeys -> count(); i ++)
            {
                C2DXString * key = dynamic_cast<C2DXString *> (allkeys -> C2DXObjectAtIndex(i));
                C2DXObject * value = Dictionary -> objectForKey(key -> getCString());
                
                if (dynamic_cast<C2DXString*>(value) != NULL)
                {
                    NSString *strValue = convertC2DXStringToNSString(dynamic_cast<C2DXString*>(value) );
                    if (strValue)
                    {
                        [dict setObject:strValue
                                 forKey:[NSString stringWithCString:key -> getCString()
                                                           encoding:NSUTF8StringEncoding]];
                    }
                }
                else if (dynamic_cast<C2DXDictionary*>(value) != NULL)
                {
                    NSMutableDictionary *dictValue = convertC2DXDictionaryToNSDictionary(dynamic_cast<C2DXDictionary*>(value));
                    if (dictValue)
                    {
                        [dict setObject:dictValue
                                 forKey:[NSString stringWithCString:key -> getCString()
                                                           encoding:NSUTF8StringEncoding]];
                    }
                }
                else if (dynamic_cast<C2DXArray*>(value) != NULL)
                {
                    NSArray *arrayValue = convertC2DXArrayToNSArray(dynamic_cast<C2DXArray*>(value));
                    if (arrayValue)
                    {
                        [dict setObject:arrayValue
                                 forKey:[NSString stringWithCString:key -> getCString()
                                                           encoding:NSUTF8StringEncoding]];
                    }
                }
            }
        }
        return  dict;
    }
    return NULL;
}

C2DXString* convertNSStringToC2DXString(NSString *string)
{
    if (string)
    {
        return C2DXString::create([string cStringUsingEncoding:NSUTF8StringEncoding]);
    }
    
    return NULL;
}

NSString* convertC2DXStringToNSString(C2DXString *string)
{
    if (string)
    {
        return [NSString stringWithCString:string -> getCString() encoding:NSUTF8StringEncoding];
    }
    return NULL;
}

C2DXArray* convertNSArrayToC2DXArray(NSArray *array)
{
    if (array)
    {
        C2DXArray *ccArray = C2DXArray::create();
        
        for (int i = 0; i < [array count]; i++)
        {
            id value = [array objectAtIndex:i];
            if ([value isKindOfClass:[NSString class]])
            {
                C2DXString *strValue = convertNSStringToC2DXString(value);
                if (strValue)
                {
                    ccArray -> addObject(strValue);
                }
            }
            else if ([value isKindOfClass:[NSNumber class]])
            {
                C2DXString *strValue = convertNSStringToC2DXString([NSString stringWithFormat:@"%@", value]);
                if (strValue)
                {
                    ccArray -> addObject(strValue);
                }
            }
            else if ([value isKindOfClass:[NSDate class]])
            {
                ccArray -> addObject(C2DXDouble::create([value timeIntervalSince1970] * 1000));
            }
            else if ([value isKindOfClass:[NSDictionary class]])
            {
                C2DXDictionary *dictValue = convertNSDictToCCDict(value);
                if (dictValue)
                {
                    ccArray -> addObject(dictValue);
                }
            }
            else if ([value isKindOfClass:[NSArray class]])
            {
                C2DXArray *arrayValue = convertNSArrayToC2DXArray(value);
                if (arrayValue)
                {
                    ccArray -> addObject(arrayValue);
                }
            }
        }
        
        return ccArray;
    }
    
    return NULL;
}

NSArray* convertC2DXArrayToNSArray(C2DXArray *array)
{
    if (array)
    {
        NSMutableArray *nsArray = [NSMutableArray array];
        for (int i = 0; i < array -> count(); i++)
        {
            C2DXObject * value = array -> C2DXObjectAtIndex(i);
            if (dynamic_cast<C2DXString*>(value) != NULL)
            {
                NSString *strValue = convertC2DXStringToNSString(dynamic_cast<C2DXString*>(value) );
                if (strValue)
                {
                    [nsArray addObject:strValue];
                }
            }
            else if (dynamic_cast<C2DXDictionary*>(value) != NULL)
            {
                NSMutableDictionary *dictValue = convertC2DXDictionaryToNSDictionary(dynamic_cast<C2DXDictionary*>(value));
                if (dictValue)
                {
                    [nsArray addObject:dictValue];
                }
            }
            else if (dynamic_cast<C2DXArray*>(value) != NULL)
            {
                NSArray *arrayValue = convertC2DXArrayToNSArray(dynamic_cast<C2DXArray*>(value));
                if (arrayValue)
                {
                    [nsArray addObject:arrayValue];
                }
            }
        }
        return nsArray;
    }
    return NULL;
}

static mob::mobpush::C2DXMessageCallBack _messageCallBack;
static mob::mobpush::C2DXAliasCallBack _aliasCallBack;
static mob::mobpush::C2DXTagsCallBack _tagsCallBack;

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
        
        int errorCode;
        if (error)
        {
            errorCode = (int)error.code;
        }
        else
        {// operation = 1 设置
            errorCode = 0;
        }
        
        if (_aliasCallBack)
        {
            _aliasCallBack([aliasStr UTF8String], 1, errorCode);
        }
    }];
}

void C2DXiOSMobPush::getAlias()
{
    [MobPush getAliasWithResult:^(NSString *alias, NSError *error) {
        
        int errorCode;
        if (error)
        {
            errorCode = (int)error.code;
        }
        else
        {
            errorCode = 0;
        }
        
        if (_aliasCallBack)
        { // operation = 0 获取
            _aliasCallBack([alias UTF8String], 0, errorCode);
        }
    }];
}

void C2DXiOSMobPush::clearAllAlias()
{
    [MobPush deleteAlias:^(NSError *error) {
        int errorCode;
        if (error)
        {
            errorCode = (int)error.code;
        }
        else
        {
            errorCode = 0;
        }
        
        NSString *alias = nil;
        
        if (_aliasCallBack)
        { // operation = 2 删除
            _aliasCallBack([alias UTF8String], 2, errorCode);
        }
        
    }];
}

void C2DXiOSMobPush::getTags()
{
    [MobPush getTagsWithResult:^(NSArray *tags, NSError *error) {
        C2DXArray *tagsArr = convertNSArrayToC2DXArray(tags);
        int errorCode;
        if (error)
        {
            errorCode = (int)error.code;
        }
        else
        {
            errorCode = 0;
        }
        
        if (_tagsCallBack)
        { // operation = 0 获取
            _tagsCallBack(tagsArr, 0, errorCode);
        }
    }];
}

void C2DXiOSMobPush::addTags(C2DXArray *tags)
{
    NSArray *tagsArr = convertC2DXArrayToNSArray(tags);
    [MobPush addTags:tagsArr result:^(NSError *error) {
        int errorCode;
        if (error)
        {
            errorCode = (int)error.code;
        }
        else
        {
            errorCode = 0;
        }
        
        if (_tagsCallBack)
        { // operation = 1 设置
            _tagsCallBack(tags, 1, errorCode);
        }
    }];
}

void C2DXiOSMobPush::deleteTags(C2DXArray *tags)
{
    NSArray *tagsArr = convertC2DXArrayToNSArray(tags);
    [MobPush deleteTags:tagsArr result:^(NSError *error) {
        int errorCode;
        if (error)
        {
            errorCode = (int)error.code;
        }
        else
        {
            errorCode = 0;
        }
        
        if (_tagsCallBack)
        { // operation = 2 删除
            _tagsCallBack(tags, 2, errorCode);
        }
    }];
}

void C2DXiOSMobPush::clearAllTags()
{
    [MobPush cleanAllTags:^(NSError *error) {
        int errorCode;
        if (error)
        {
            errorCode = (int)error.code;
        }
        else
        {
            errorCode = 0;
        }
        
        if (_tagsCallBack)
        { // operation = 3 清空
            _tagsCallBack(nil, 3, errorCode);
        }
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

void C2DXiOSMobPush::setC2DXMessageCallBack(C2DXMessageCallBack messageCallBack)
{
    _messageCallBack = messageCallBack;
}

void C2DXiOSMobPush::setC2DXAliasCallBack(C2DXAliasCallBack aliasCallBack)
{
    _aliasCallBack = aliasCallBack;
}

void C2DXiOSMobPush::setC2DXTagsCallBack(C2DXTagsCallBack tagsCallBack)
{
    _tagsCallBack = tagsCallBack;
}

void C2DXiOSMobPush::iOSMessageCallBack(int action, C2DXMobPushMessage *message)
{
    if (_messageCallBack)
    {
        _messageCallBack(action, message);
    }
}
