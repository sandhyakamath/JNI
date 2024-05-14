### Build Steps

1. Generate header files for the native code. This will generate a C/C++ header file which contains methods corresponding to the native calls from the java class.

    ```
    javac -h . CArray.java
    ```

2. Compile shared object / dynamic library

    The C file for the header is already created. We will use this file to compile the shared object / dynamic library.

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

3.  Link shared object / dynamic library

    **Linux**

    ```
    g++ -shared -fPIC -o libNative.so CArray.o -lc
    ```

    **Windows**

    ```
    g++ -shared -o native.dll HelloJNI.o -Wl,--add-stdcall-alias
    ```

    **MacOS**

    ```
    g++ -dynamiclib -o libnative.dylib HelloJNI.o -lc
    ```

4. Run the Java program. It will load the dynamic library and then execute the sayHello method.

    ```
    java -cp . -Djava.library.path=. HelloJNI
    ```

Reference : https://www.baeldung.com/jni
