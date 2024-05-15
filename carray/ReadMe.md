### Build Steps

1. Generate header files for the native code. This will generate a C/C++ header file which contains methods corresponding to the native calls from the java class.

    ```
    javac -h . CArray.java
    ```

2. Compile shared object / dynamic library

    The C file for the header is already created. We will use this file to compile the shared object / dynamic library.
    Set JAVA_HOME on mac: export JAVA_HOME=$(/usr/libexec/java_home)

    **Linux**

    ```
    g++ -c -fPIC -I"${JAVA_HOME}/include" -I"${JAVA_HOME}/include/linux" carray_CArray.cpp -o CArray.o
    ```

    **Windows**

    ```
    g++ -c -I%JAVA_HOME%\include -I%JAVA_HOME%\include\win32 carray_CArray.cpp -o CArray.o
    ```

    **MacOS**

    ```
    g++ -c -fPIC -I"${JAVA_HOME}/include" -I"${JAVA_HOME}/include/darwin" carray_CArray.cpp -o CArray.o
    ```

4.  Link shared object / dynamic library

    **Linux**

    ```
    g++ -shared -fPIC -o libNativeClass.so CArray.o -lc
    ```

    **Windows**

    ```
    g++ -shared -o NativeClass.dll CArray.o -Wl,--add-stdcall-alias
    ```

    **MacOS**

    ```
    g++ -dynamiclib -o libNativeClass.dylib CArray.o -lc
    ```

5. Run the Java program. It will load the dynamic library and then execute the sayHello method.
   Hint: One should navigate outside of the folder where library is created

    ```
    java -cp . -Djava.library.path=. CArray
    ```

Reference : https://www.baeldung.com/jni
