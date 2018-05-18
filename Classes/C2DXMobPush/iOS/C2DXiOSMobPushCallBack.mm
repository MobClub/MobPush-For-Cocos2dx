//
//  C2DXiOSMobPushCallBack.m
//  MobPush-For-Cocos2dx-mobile
//
//  Created by youzu on 2018/5/17.
//

#import "C2DXiOSMobPushCallBack.h"
#import <MobPush/MobPush.h>
#import "C2DXiOSMobPush.h"

using namespace mob::mobpush;

///**
// *    @brief    转换NSDictionary为C2DXDictionary类型
// *
// *    @param     dict     字典
// *
// *    @return    字典类型
// */
//C2DXDictionary* convertNSDictToCCDict(NSDictionary *dict);
//
///**
// *    @brief    转换C2DXDictionary为NSDictionary类型
// *
// *    @param     dict     字典
// *
// *    @return    字典类型
// */
//NSMutableDictionary* convertC2DXDictionaryToNSDictionary(C2DXDictionary *Dictionary);
//
///**
// *    @brief    转换NSString为C2DXString类型
// *
// *    @param     string     字符串
// *
// *    @return    字符类型
// */
//C2DXString* convertNSStringToC2DXString(NSString *string);
//
///**
// *    @brief    转换C2DXString为NSString类型
// *
// *    @param     string     字符串
// *
// *    @return    字符类型
// */
//NSString* convertC2DXStringToNSString(C2DXString *String);
//
///**
// *    @brief    转换NSArray为C2DXArray类型
// *
// *    @param     array     数组
// *
// *    @return    数组类型
// */
//C2DXArray* convertNSArrayToC2DXArray(NSArray *array);
//
///**
// *    @brief    转换C2DXArray为NSArray类型
// *
// *    @param     array     数组
// *
// *    @return    数组类型
// */
//NSArray* convertC2DXArrayToNSArray(C2DXArray *Array);
//
//C2DXDictionary* convertNSDictToCCDict(NSDictionary *dict)
//{
//    if (dict)
//    {
//        C2DXDictionary *ccDict = C2DXDictionary::create();
//        NSArray *allKeys = [dict allKeys];
//        for (int i = 0; i < [allKeys count]; i++)
//        {
//            NSString *key = [allKeys objectAtIndex:i];
//            id value = [dict objectForKey:key];
//
//            if ([value isKindOfClass:[NSString class]])
//            {
//                C2DXString *strValue = convertNSStringToC2DXString(value);
//                if (strValue)
//                {
//                    ccDict -> setObject(strValue, [key UTF8String]);
//                }
//            }
//            else if ([value isKindOfClass:[NSNumber class]])
//            {
//                C2DXString *strValue = convertNSStringToC2DXString([NSString stringWithFormat:@"%@", value]);
//                if (strValue)
//                {
//                    ccDict -> setObject(strValue, [key UTF8String]);
//                }
//            }
//            else if ([value isKindOfClass:[NSDate class]])
//            {
//                ccDict -> setObject(C2DXDouble::create([value timeIntervalSince1970] * 1000), [key UTF8String]);
//            }
//            else if ([value isKindOfClass:[NSDictionary class]])
//            {
//                C2DXDictionary *dictValue = convertNSDictToCCDict(value);
//                if (dictValue)
//                {
//                    ccDict -> setObject(dictValue, [key UTF8String]);
//                }
//            }
//            else if ([value isKindOfClass:[NSArray class]])
//            {
//                C2DXArray *arrValue = convertNSArrayToC2DXArray(value);
//                if (arrValue)
//                {
//                    ccDict -> setObject(arrValue, [key UTF8String]);
//                }
//            }
//        }
//        return ccDict;
//    }
//
//    return NULL;
//}
//
//NSMutableDictionary * convertC2DXDictionaryToNSDictionary(C2DXDictionary * Dictionary)
//{
//    if (Dictionary)
//    {
//        NSMutableDictionary *dict = [NSMutableDictionary dictionary];
//        C2DXArray *allkeys = Dictionary -> allKeys();
//
//        if (allkeys != NULL)
//        {
//            for (int i = 0; i < allkeys -> count(); i ++)
//            {
//                C2DXString * key = dynamic_cast<C2DXString *> (allkeys -> C2DXObjectAtIndex(i));
//                C2DXObject * value = Dictionary -> objectForKey(key -> getCString());
//
//                if (dynamic_cast<C2DXString*>(value) != NULL)
//                {
//                    NSString *strValue = convertC2DXStringToNSString(dynamic_cast<C2DXString*>(value) );
//                    if (strValue)
//                    {
//                        [dict setObject:strValue
//                                 forKey:[NSString stringWithCString:key -> getCString()
//                                                           encoding:NSUTF8StringEncoding]];
//                    }
//                }
//                else if (dynamic_cast<C2DXDictionary*>(value) != NULL)
//                {
//                    NSMutableDictionary *dictValue = convertC2DXDictionaryToNSDictionary(dynamic_cast<C2DXDictionary*>(value));
//                    if (dictValue)
//                    {
//                        [dict setObject:dictValue
//                                 forKey:[NSString stringWithCString:key -> getCString()
//                                                           encoding:NSUTF8StringEncoding]];
//                    }
//                }
//                else if (dynamic_cast<C2DXArray*>(value) != NULL)
//                {
//                    NSArray *arrayValue = convertC2DXArrayToNSArray(dynamic_cast<C2DXArray*>(value));
//                    if (arrayValue)
//                    {
//                        [dict setObject:arrayValue
//                                 forKey:[NSString stringWithCString:key -> getCString()
//                                                           encoding:NSUTF8StringEncoding]];
//                    }
//                }
//            }
//        }
//        return  dict;
//    }
//    return NULL;
//}
//
//C2DXString* convertNSStringToC2DXString(NSString *string)
//{
//    if (string)
//    {
//        return C2DXString::create([string cStringUsingEncoding:NSUTF8StringEncoding]);
//    }
//
//    return NULL;
//}
//
//NSString* convertC2DXStringToNSString(C2DXString *string)
//{
//    if (string)
//    {
//        return [NSString stringWithCString:string -> getCString() encoding:NSUTF8StringEncoding];
//    }
//    return NULL;
//}
//
//C2DXArray* convertNSArrayToC2DXArray(NSArray *array)
//{
//    if (array)
//    {
//        C2DXArray *ccArray = C2DXArray::create();
//
//        for (int i = 0; i < [array count]; i++)
//        {
//            id value = [array objectAtIndex:i];
//            if ([value isKindOfClass:[NSString class]])
//            {
//                C2DXString *strValue = convertNSStringToC2DXString(value);
//                if (strValue)
//                {
//                    ccArray -> addObject(strValue);
//                }
//            }
//            else if ([value isKindOfClass:[NSNumber class]])
//            {
//                C2DXString *strValue = convertNSStringToC2DXString([NSString stringWithFormat:@"%@", value]);
//                if (strValue)
//                {
//                    ccArray -> addObject(strValue);
//                }
//            }
//            else if ([value isKindOfClass:[NSDate class]])
//            {
//                ccArray -> addObject(C2DXDouble::create([value timeIntervalSince1970] * 1000));
//            }
//            else if ([value isKindOfClass:[NSDictionary class]])
//            {
//                C2DXDictionary *dictValue = convertNSDictToCCDict(value);
//                if (dictValue)
//                {
//                    ccArray -> addObject(dictValue);
//                }
//            }
//            else if ([value isKindOfClass:[NSArray class]])
//            {
//                C2DXArray *arrayValue = convertNSArrayToC2DXArray(value);
//                if (arrayValue)
//                {
//                    ccArray -> addObject(arrayValue);
//                }
//            }
//        }
//
//        return ccArray;
//    }
//
//    return NULL;
//}
//
//NSArray* convertC2DXArrayToNSArray(C2DXArray *array)
//{
//    if (array)
//    {
//        NSMutableArray *nsArray = [NSMutableArray array];
//        for (int i = 0; i < array -> count(); i++)
//        {
//            C2DXObject * value = array -> C2DXObjectAtIndex(i);
//            if (dynamic_cast<C2DXString*>(value) != NULL)
//            {
//                NSString *strValue = convertC2DXStringToNSString(dynamic_cast<C2DXString*>(value) );
//                if (strValue)
//                {
//                    [nsArray addObject:strValue];
//                }
//            }
//            else if (dynamic_cast<C2DXDictionary*>(value) != NULL)
//            {
//                NSMutableDictionary *dictValue = convertC2DXDictionaryToNSDictionary(dynamic_cast<C2DXDictionary*>(value));
//                if (dictValue)
//                {
//                    [nsArray addObject:dictValue];
//                }
//            }
//            else if (dynamic_cast<C2DXArray*>(value) != NULL)
//            {
//                NSArray *arrayValue = convertC2DXArrayToNSArray(dynamic_cast<C2DXArray*>(value));
//                if (arrayValue)
//                {
//                    [nsArray addObject:arrayValue];
//                }
//            }
//        }
//        return nsArray;
//    }
//    return NULL;
//}

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

- (void)didFinishLaunching
{
    [MobPush setAPNsForProduction:_isPro];
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
    
    C2DXMobPushMessage *ccMessage = new C2DXMobPushMessage();
    
    switch (message.messageType)
    {
        case MPushMessageTypeCustom:
        {// 自定义消息
            action = 0;
            
//            if (message.extraInfomation.count)
//            {
//                ccMessage->extrasMap = convertNSDictToCCDict(message.extraInfomation);
//            }
//
//            if (message.content)
//            {
//                ccMessage->content = convertNSStringToC2DXString(message.content);
//            }
//
//            if (message.messageID)
//            {
//                [reslut setObject:message.messageID forKey:@"messageId"];
//            }
//
//            if (message.currentServerTimestamp)
//            {
//                [reslut setObject:@(message.currentServerTimestamp) forKey:@"timeStamp"];
//            }
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
//            if (message.apnsDict.count)
//            {
//                NSDictionary *aps = message.apnsDict[@"aps"];
//                if ([aps isKindOfClass:[NSDictionary class]])
//                {
//                    NSDictionary *alert = aps[@"alert"];
//                    if ([alert isKindOfClass:[NSDictionary class]])
//                    {
//                        NSString *body = alert[@"body"];
//                        if (body)
//                        {
//                            [reslut setObject:body forKey:@"content"];
//                        }
//
//                        NSString *subtitle = alert[@"subtitle"];
//                        if (subtitle)
//                        {
//                            [reslut setObject:subtitle forKey:@"subtitle"];
//                        }
//
//                        NSString *title = alert[@"title"];
//                        if (title)
//                        {
//                            [reslut setObject:title forKey:@"title"];
//                        }
//                    }
//
//                    NSString *sound = aps[@"sound"];
//                    if (sound)
//                    {
//                        [reslut setObject:sound forKey:@"sound"];
//                    }
//
//                    NSInteger badge = [aps[@"badge"] integerValue];
//                    if (badge)
//                    {
//                        [reslut setObject:@(badge) forKey:@"badge"];
//                    }
//
//                }
//            }
//
//            NSString *mobpushMessageId = message.apnsDict[@"mobpushMessageId"];
//            if (mobpushMessageId)
//            {
//                [reslut setObject:mobpushMessageId forKey:@"mobpushMessageId"];
//            }
//
//            NSMutableDictionary *extra = [NSMutableDictionary dictionary];
//            [message.apnsDict enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, id  _Nonnull obj, BOOL * _Nonnull stop) {
//
//                if (![key isEqualToString:@"aps"] && ![key isEqualToString:@"mobpushMessageId"])
//                {
//                    [extra setObject:obj forKey:key];
//                }
//
//            }];
//
//            if (extra.count)
//            {
//                [reslut setObject:extra forKey:@"extra"];
//            }
//
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
//            NSString *body = message.notification.body;
//            NSString *title = message.notification.title;
//            NSString *subtitle = message.notification.subTitle;
//            NSInteger badge = message.notification.badge;
//            NSString *sound = message.notification.sound;
//            if (body)
//            {
//                [reslut setObject:body forKey:@"content"];
//            }
//
//            if (title)
//            {
//                [reslut setObject:title forKey:@"title"];
//            }
//
//            if (subtitle)
//            {
//                [reslut setObject:subtitle forKey:@"subtitle"];
//            }
//
//            if (badge)
//            {
//                [reslut setObject:@(badge) forKey:@"badge"];
//            }
//
//            if (sound)
//            {
//                [reslut setObject:sound forKey:@"sound"];
//            }
            
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
    
//    if (reslut.count)
//    {
//        [resultDict setObject:reslut forKey:@"result"];
//    }
    
    C2DXiOSMobPush::iOSMessageCallBack(action, ccMessage);
}

- (void)dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

@end
