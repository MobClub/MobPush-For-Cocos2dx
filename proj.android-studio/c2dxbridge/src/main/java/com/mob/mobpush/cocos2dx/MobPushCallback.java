package com.mob.mobpush.cocos2dx;

/**
 * Created by yyfu on 2018/5/11.
 */

public class MobPushCallback<T> implements com.mob.pushsdk.MobPushCallback<T> {
    private int cxxObject;

    public MobPushCallback() {
        super();
        cxxObject = nativeOnCreateCxxObject();
    }

    @Override
    public void onCallback(T t) {
        nativeOnCallback(t);
    }

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        nativeOnDestoryCxxObject();
    }

    private native int nativeOnCreateCxxObject();
    public native void nativeOnCallback(T o);
    private native int nativeOnDestoryCxxObject();

    public int getCxxObject() {
        return cxxObject;
    }

    public static MobPushCallback newInstance(){
        return new MobPushCallback();
    }
}
