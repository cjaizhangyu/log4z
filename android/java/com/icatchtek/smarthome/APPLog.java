package com.icatchtek.smarthome;

/**
 * Created by j.chen on 2018/5/4.
 */

public class APPLog {

    public static boolean open(String onlyKey) {
        return openLog(onlyKey);
    }

    public static void E(String tag, String log) {
        writeLogE(tag, log);
    }

    public static void I(String tag, String log) {
        writeLogI(tag, log);
    }
    public static void W(String tag, String log) {
        writeLogW(tag, log);
    }

    private static native boolean openLog(String key);
    private static native boolean writeLogE(String tag, String log);
    private static native boolean writeLogW(String tag, String log);
    private static native boolean writeLogI(String tag, String log);
}
