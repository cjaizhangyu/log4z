package com.icatchtek.smarthome;

/**
 * Created by j.chen on 2018/5/4.
 */

public class LogConfig {
    public static final int SDK_LOG = 0;
    public static final int APP_LOG = 1;

    private long object = 0;
    private static LogConfig instance_ = null;

    public static LogConfig instance() {
        if(instance_ == null) {
            instance_ = new LogConfig();
        }
        return instance_;
    }

    public boolean setPath(int logType, String path) {
        return nativeSetPath(logType, path);
    }

    public boolean setEnable(int logType, boolean enable) {
        return nativeSetEnable(logType, enable);
    }

    public boolean setLevel(int logType, int level) {
        return nativeSetLevel(logType, level);
    }

    public boolean setOutScreen(int logType, boolean enable) {
        return nativeSetOutScreen(logType, enable);
    }

    public boolean setOutFile(int logType, boolean enable) {
        return nativeSetOutFile(logType, enable);
    }
    public  boolean setLogStart() {
        return nativeSetLogStart();
    }
    public boolean setFileSize(int logType, int size) {
        return nativeSetFileSize(logType, size);

    }
    private native boolean nativeSetPath(int logType, String path);
    private native boolean nativeSetEnable(int logType, boolean enable);
    private native boolean nativeSetOutScreen(int logType, boolean enable);
    private native boolean nativeSetOutFile(int logType, boolean enable);
    private native boolean nativeSetLevel(int logType, int level);
    private native boolean nativeSetFileSize(int logType, int size);
    private native boolean nativeSetLogStart();

}
