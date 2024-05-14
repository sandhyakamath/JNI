package helloworld;

public class HelloWorldJNI {
    // load the shared library
    static {
        System.loadLibrary("native");
    }

    // declare native method that receives no arguments and returns void
    private native void sayHello();

    public static void main(String[] args) {
        new HelloWorldJNI().sayHello();
    }
}
