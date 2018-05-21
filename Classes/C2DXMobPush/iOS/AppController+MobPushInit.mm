//
//  AppController+MobPushInit.m
//  MobPush-For-Cocos2dx-mobile
//
//  Created by LeeJay on 2018/5/16.
//

#import "AppController+MobPushInit.h"
#import "C2DXiOSMobPushCallBack.h"

@implementation AppController (MobPushInit)

+ (void)initialize
{
    [[NSNotificationCenter defaultCenter] addObserver:[C2DXiOSMobPushCallBack defaultCallBack]
                                             selector:@selector(didFinishLaunching)
                                                 name:UIApplicationDidFinishLaunchingNotification
                                               object:nil];
}

- (void)dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:[C2DXiOSMobPushCallBack defaultCallBack]];
}

@end
