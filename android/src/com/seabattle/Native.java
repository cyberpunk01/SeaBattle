package com.seabattle;

public class Native {
    
    static {
        System.loadLibrary("seabattle");
    }
    
    public static native void Init();

}
