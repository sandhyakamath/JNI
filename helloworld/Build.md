### Build Steps

1. Generate header files for the native code. This will generate a C/C++ header file which contains methods corresponding to the native calls from the java class.

    ```
    javac -h . HelloWorldJNI.java
    ```

3. Compile shared object / dynamic library

    The C file for the header is already created. We will use this file to compile the shared object / dynamic library.
    Set JAVA_HOME on mac: export JAVA_HOME=$(/usr/libexec/java_home)

    **Linux**

    ```
    g++ -c -fPIC -I"${JAVA_HOME}/include" -I"${JAVA_HOME}/include/linux" helloworld_HelloWorldJNI.cpp -o HelloWorldJNI.o
    ```

    **Windows**

    ```
    g++ -c -I%JAVA_HOME%\include -I%JAVA_HOME%\include\win32 helloworld_HelloWorldJNI.cpp -o HelloWorldJNI.o
    ```

    **MacOS**

    ```
    g++ -c -fPIC -I"${JAVA_HOME}/include" -I"${JAVA_HOME}/include/darwin" helloworld_HelloWorldJNI.cpp -o HelloWorldJNI.o
    ```

5.  Link shared object / dynamic library

    **Linux**

    ```
    g++ -shared -fPIC -o libnative.so HelloWorldJNI.o -lc
    ```

    **Windows**

    ```
    g++ -shared -o native.dll HelloWorldJNI.o -Wl,--add-stdcall-alias
    ```

    **MacOS**

    ```
    g++ -dynamiclib -o libnative.dylib HelloWorldJNI.o -lc
    ```

6. Run the Java program. It will load the dynamic library and then execute the sayHello method.

    ```
    java -cp . -Djava.library.path=. HelloWorldJNI
    ```

Reference : https://www.baeldung.com/jni
