package com.mob.mobpush.cocos2dx;

import android.content.Context;

import com.mob.pushsdk.MobPushCustomMessage;
import com.mob.pushsdk.MobPushNotifyMessage;
import com.mob.tools.utils.Hashon;

/**
 * Created by yyfu on 2018/5/14.
 */

public class MobPushReceiver implements com.mob.pushsdk.MobPushReceiver {
    private int cxxObject;
    private Hashon hashon;

    public MobPushReceiver() {
        System.out.println(">>>>>MobPushReceiver>>>>>");

        hashon = new Hashon();
        this.cxxObject = nativeOnCreateCxxObject();
    }

    @Override
    public void onCustomMessageReceive(Context context, MobPushCustomMessage mobPushCustomMessage) {
        System.out.println(">>>>>onNotifyMessageReceive>>>>>"+mobPushCustomMessage.toString());
        nativeOnCustomMessageReceive(mobPushCustomMessage.getMessageId());
    }

    @Override
    public void onNotifyMessageReceive(Context context, MobPushNotifyMessage mobPushNotifyMessage) {
        System.out.println(">>>>>onNotifyMessageReceive>>>>>"+mobPushNotifyMessage.getMessageId());
        nativeOnNotifyMessageReceive(mobPushNotifyMessage.getMessageId());
    }

    @Override
    public void onNotifyMessageOpenedReceive(Context context, MobPushNotifyMessage mobPushNotifyMessage) {
        System.out.println(">>>>>onNotifyMessageOpenedReceive>>>>>"+mobPushNotifyMessage.getMessageId());
        nativeOnNotifyMessageOpenedReceive(mobPushNotifyMessage.getMessageId());
    }

    @Override
    public void onTagsCallback(Context context, String[] strings, int i, int i1) {
//        nativeOnTagsCallback(strings, i, i1);
    }

    @Override
    public void onAliasCallback(Context context, String s, int i, int i1) {
        nativeOnAliasCallback(s, i, i1);
    }

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        nativeOnDestoryCxxObject();
    }

    private native int nativeOnCreateCxxObject();

    private native void nativeOnDestoryCxxObject();

    private native void nativeOnCustomMessageReceive(String customMessageJson);

    private native void nativeOnNotifyMessageReceive(String notifyMessageJson);

    private native void nativeOnNotifyMessageOpenedReceive(String notifyMessageJson);

    private native void nativeOnTagsCallback(String[] strings, int i, int i1);

    private native void nativeOnAliasCallback(String s, int i, int i1);

    public int getCxxObject() {
        return cxxObject;
    }

    public static MobPushReceiver newInstance() {
        return new MobPushReceiver();
    }

}
