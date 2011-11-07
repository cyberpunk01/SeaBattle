package com.seabattle;

import android.util.Log;

public class Native {
    
    static {
    	Log.i("SeaBattle", "Try load so");
        System.loadLibrary("seabattle");
        Log.i("SeaBattle", "lib loaded");
    }
    
    public native void Init();
    public native int Shoot(int x, int y);
    public native int AIShoot();
    
    public native void GetField(int[] data, boolean mPlayer);
}
