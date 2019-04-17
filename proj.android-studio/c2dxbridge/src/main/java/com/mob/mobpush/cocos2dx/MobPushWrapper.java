package com.mob.mobpush.cocos2dx;

import android.text.TextUtils;

import com.mob.MobSDK;
import com.mob.pushsdk.MobPush;
import com.mob.pushsdk.MobPushLocalNotification;
import com.mob.tools.utils.DeviceHelper;
import com.mob.tools.utils.ResHelper;

import java.util.Random;

import static com.mob.MobSDK.getContext;


public class MobPushWrapper {

	public static void sendLocalNotify(String content, int space) {
		MobPushLocalNotification notification = new MobPushLocalNotification();
		String appName = DeviceHelper.getInstance(getContext()).getAppName();
		notification.setTitle(TextUtils.isEmpty(appName) ? getContext().getString(R.string.item_local) : appName);
		notification.setContent(content);
//				notification.setVoice(false);//可设置不进行声音提醒，默认声音、振动、指示灯
		notification.setNotificationId(new Random().nextInt());
		notification.setTimestamp(space * 60 * 1000 + System.currentTimeMillis());
		MobPush.addLocalNotification(notification);
	}

	public static void setNotifyIcon(String resIcon) {
		if (!TextUtils.isEmpty(resIcon)) {
			MobPush.setNotifyIcon(ResHelper.getBitmapRes(MobSDK.getContext(), resIcon));
		}
	}

	public static void setAppForegroundHiddenNotification(boolean hidden) {
		MobPush.setAppForegroundHiddenNotification(hidden);
	}

}
