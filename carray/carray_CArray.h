#include <jni.h>
/* Header for class carray_CArray */

#ifndef _Included_carray_CArray
#define _Included_carray_CArray
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     carray_CArray
 * Method:    createStrs
 * Signature: (I)[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_carray_CArray_createStrs
  (JNIEnv *, jobject, jint);

/*
 * Class:     carray_CArray
 * Method:    createVals
 * Signature: (I)[I
 */
JNIEXPORT jintArray JNICALL Java_carray_CArray_createVals
  (JNIEnv *, jobject, jint);

/*
 * Class:     carray_CArray
 * Method:    sortStrs
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_carray_CArray_sortStrs
  (JNIEnv *, jobject);

/*
 * Class:     carray_CArray
 * Method:    reverseArray
 * Signature: ([I)V
 */
JNIEXPORT void JNICALL Java_carray_CArray_reverseArray
  (JNIEnv *, jobject, jintArray);

/*
 * Class:     carray_CArray
 * Method:    genException
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_carray_CArray_genException
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
