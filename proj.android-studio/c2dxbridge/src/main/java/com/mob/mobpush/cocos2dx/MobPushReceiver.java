package com.mob.mobpush.cocos2dx;

import android.content.Context;
import android.text.TextUtils;

import com.mob.pushsdk.MobPushCustomMessage;
import com.mob.pushsdk.MobPushNotifyMessage;
import com.mob.tools.utils.Hashon;

import java.util.HashMap;

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
        HashMap<String, Object> map = hashon.fromJson(hashon.fromObject(mobPushCustomMessage));
        if(map.containsKey("timestamp")){
            long timestamp = (long) map.get("timestamp");
            map.put("timestamp", timestamp+"");
        }
        String json = hashon.fromHashMap(map);
        System.out.println(">>>>>onNotifyMessageReceive>>>json>>"+json);
        nativeOnCustomMessageReceive(json);
    }

    @Override
    public void onNotifyMessageReceive(Context context, MobPushNotifyMessage mobPushNotifyMessage) {
        System.out.println(">>>>>onNotifyMessageReceive>>>>>"+mobPushNotifyMessage.toString());
        HashMap<String, Object> map = hashon.fromJson(hashon.fromObject(mobPushNotifyMessage));
        if(map.containsKey("timestamp")){
            long timestamp = (long) map.get("timestamp");
            map.put("timestamp", timestamp+"");
        }
        String json = hashon.fromHashMap(map);
        System.out.println(">>>>>onNotifyMessageReceive>>>json>>"+json);
        nativeOnNotifyMessageReceive(json);
    }

    @Override
    public void onNotifyMessageOpenedReceive(Context context, MobPushNotifyMessage mobPushNotifyMessage) {
        System.out.println(">>>>>onNotifyMessageOpenedReceive>>>>>"+mobPushNotifyMessage.toString());
        HashMap<String, Object> map = hashon.fromJson(hashon.fromObject(mobPushNotifyMessage));
        if(map.containsKey("timestamp")){
            long timestamp = (long) map.get("timestamp");
            map.put("timestamp", timestamp+"");
        }
        String json = hashon.fromHashMap(map);
        System.out.println(">>>>>onNotifyMessageOpenedReceive>>>json>>"+json);
        nativeOnNotifyMessageOpenedReceive(json);
    }

    @Override
    public void onTagsCallback(Context context, String[] strings, int i, int i1) {
        System.out.println(">>>>>>>>>>>>>onTagsCallback>>>>>>>>>>>"+strings[0]+">>>>"+i);
        nativeOnTagsCallback(strings, i, i1);
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
