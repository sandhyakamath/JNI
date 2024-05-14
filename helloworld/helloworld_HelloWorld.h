#include <jni.h>
/* Header for class HelloWorldJNI */

#ifndef _Included_HelloWorldJNI
#define _Included_HelloWorldJNI
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     HelloWorldJNI
 * Method:    sayHello
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_HelloWorldJNI_sayHello
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
