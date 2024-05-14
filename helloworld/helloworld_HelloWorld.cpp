#include <iostream>
#include <jni.h>
#include "HelloWorldJNI.h"

/*
 * Class:     HelloWorldJNI
 * Method:    sayHello
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_HelloWorldJNI_sayHello
  (JNIEnv *, jobject) {
    std::cout << "Hello From C++ World" << std::endl;
    return;
  }