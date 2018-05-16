LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/cocos)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/cocos/audio/include)
$(call import-add-path,$(LOCAL_PATH)/../../c2dxbridge)

LOCAL_MODULE := MyGame_shared

LOCAL_MODULE_FILENAME := libMyGame

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../../Classes/AppDelegate.cpp \
                   ../../../Classes/HelloWorldScene.cpp \
                   ../../../Classes/AppNotifyScene.cpp \
                   ../../../Classes/NotifyScene.cpp \
                   ../../../Classes/TimeNotifyScene.cpp \
                   ../../../Classes/LocalNotifyScene.cpp \
                   ../../../Classes/NotifyOpenUrlScene.cpp \
                   ../../../Classes/C2DXMobPush/C2DXMobPush.cpp \
                   ../../../Classes/C2DXMobPush/Android/C2DXAndroidMobPush.cpp \
                   ../../../Classes/C2DXMobPush/Android/C2DXAndroidCallback.cpp \
                   ../../../Classes/C2DXMobPush/Android/C2DXAndroidSReqCallback.cpp \
                   ../../../Classes/C2DXMobPush/Android/C2DXAndroidMobPushReceiver.cpp \
                   ../../../Classes/C2DXMobPush/Android/com_mob_mobpush_cocos2dx_MobPushCallback.cpp \
                   ../../../Classes/C2DXMobPush/Android/com_mob_mobpush_cocos2dx_MobPushSReqCallback.cpp \
                   ../../../Classes/C2DXMobPush/Android/com_mob_mobpush_cocos2dx_MobPushReceiver.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../Classes

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
