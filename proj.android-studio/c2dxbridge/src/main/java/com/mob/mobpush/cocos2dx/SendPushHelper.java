package com.mob.mobpush.cocos2dx;

import android.text.TextUtils;
import android.widget.Toast;

import com.mob.pushsdk.*;
import com.mob.pushsdk.MobPushCallback;
import com.mob.tools.utils.DeviceHelper;

import org.json.JSONException;
import org.json.JSONObject;

import java.util.Random;

import static com.mob.MobSDK.getContext;

/**
 * Created by yyfu on 2018/5/16.
 */

public class SendPushHelper {
    //这个参数不可以修改，从demo的接口发推送，只能接收这么一个字段，其他扩展需要在后台下发
    private final static String MOB_PUSH_DEMO_URL = "url";

    public static void sendLocalNotify(String content, int space){
        MobPushLocalNotification notification = new MobPushLocalNotification();
        String appName = DeviceHelper.getInstance(getContext()).getAppName();
        notification.setTitle(TextUtils.isEmpty(appName) ? getContext().getString(R.string.item_local) : appName);
        notification.setContent(content);
//				notification.setVoice(false);//可设置不进行声音提醒，默认声音、振动、指示灯
        notification.setNotificationId(new Random().nextInt());
        notification.setTimestamp(space * 60 * 1000 + System.currentTimeMillis());
        MobPush.addLocalNotification(notification);
    }

}
