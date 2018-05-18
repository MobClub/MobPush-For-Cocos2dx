//
//  C2DXiOSMobPushCallBack.h
//  MobPush-For-Cocos2dx-mobile
//
//  Created by youzu on 2018/5/17.
//

#import <Foundation/Foundation.h>

@interface C2DXiOSMobPushCallBack : NSObject

+ (instancetype)defaultCallBack;

@property (nonatomic, assign) BOOL isPro;

- (void)addPushObserver;

@end
