package com.mob.mobpush.cocos2dx;

import android.content.Context;

import com.mob.pushsdk.MobPushCustomMessage;
import com.mob.pushsdk.MobPushNotifyMessage;

/**
 * Created by yyfu on 2018/5/14.
 */

public class MobPushReceiver implements com.mob.pushsdk.MobPushReceiver {
    private int cxxObject;

    public MobPushReceiver() {
        this.cxxObject = nativeOnCreateCxxObject();
    }

    @Override
    public void onCustomMessageReceive(Context context, MobPushCustomMessage mobPushCustomMessage) {
        nativeOnCustomMessageReceive(context, mobPushCustomMessage);
    }

    @Override
    public void onNotifyMessageReceive(Context context, MobPushNotifyMessage mobPushNotifyMessage) {
        nativeOnNotifyMessageReceive(context, mobPushNotifyMessage);
    }

    @Override
    public void onNotifyMessageOpenedReceive(Context context, MobPushNotifyMessage mobPushNotifyMessage) {
        nativeOnNotifyMessageOpenedReceive(context, mobPushNotifyMessage);
    }

    @Override
    public void onTagsCallback(Context context, String[] strings, int i, int i1) {
        nativeOnTagsCallback(context, strings, i, i1);
    }

    @Override
    public void onAliasCallback(Context context, String s, int i, int i1) {
        nativeOnAliasCallback(context, s, i, i1);
    }

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        nativeOnDestoryCxxObject();
    }

    private native int nativeOnCreateCxxObject();

    private native void nativeOnDestoryCxxObject();

    private native void nativeOnCustomMessageReceive(Context context, MobPushCustomMessage mobPushCustomMessage);

    private native void nativeOnNotifyMessageReceive(Context context, MobPushNotifyMessage mobPushNotifyMessage);

    private native void nativeOnNotifyMessageOpenedReceive(Context context, MobPushNotifyMessage mobPushNotifyMessage);

    private native void nativeOnTagsCallback(Context context, String[] strings, int i, int i1);

    private native void nativeOnAliasCallback(Context context, String s, int i, int i1);

    public int getCxxObject() {
        return cxxObject;
    }

    public static MobPushReceiver newInstance() {
        return new MobPushReceiver();
    }

}
