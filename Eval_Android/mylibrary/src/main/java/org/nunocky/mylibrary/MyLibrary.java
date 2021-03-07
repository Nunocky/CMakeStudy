package org.nunocky.mylibrary;

class MyLibrary {
    public static native String greetingX();

    public static native String greetingY();

    static {
        System.loadLibrary("native-lib");
    }
}