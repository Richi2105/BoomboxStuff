/*
 * SharedMemoryAccess.cpp
 *
 *  Created on: Dec 26, 2015
 *      Author: richard
 */

#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>

#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/un.h>

#include <jni.h>
#include <linux/jni_md.h>

#include <SocketIO.h>
#include <SocketIOLocal.h>
#include <SocketSlave.h>

#define PACKAGENAME shmtest
#define CLASSNAME Shmtest

#define JAVA_FUNCTION(name) Java_eventSystem_socketIO_SocketSlave_##name
#define JAVA_FUNC_DECLARATION(name, returnType) JNIEXPORT returnType JNICALL JAVA_FUNCTION(name)

/* static variables */

static Socket_Slave* socketslave;

/* Function Declaration */

extern "C"
JAVA_FUNC_DECLARATION(SocketSlaveinit, void)(JNIEnv* env, jobject caller);

extern "C"
JAVA_FUNC_DECLARATION(SocketSlavesend, jint)(JNIEnv* env, jobject caller, jbyteArray arr, jint numOfBytes);

extern "C"
JAVA_FUNC_DECLARATION(SocketSlavereceive, jint)(JNIEnv* env, jobject caller, jbyteArray arr, jint numOfBytes);

extern "C"
JAVA_FUNC_DECLARATION(SocketSlavegetAddress, void)(JNIEnv* env, jobject caller, jbyteArray arr);

extern "C"
JAVA_FUNC_DECLARATION(SocketSlaveGetUniqueID, jstring)(JNIEnv* env, jobject caller);


/* Function Bodies */

extern "C"
JAVA_FUNC_DECLARATION(SocketSlaveinit, void)(JNIEnv* env, jobject caller)
{
	socketslave = new Socket_Slave();
}

extern "C"
JAVA_FUNC_DECLARATION(SocketSlavesend, jint)(JNIEnv* env, jobject caller, jbyteArray arr, jint numOfBytes)
{
	jboolean isCopy = 0;
	jbyte* data = env->GetByteArrayElements(arr, &isCopy);
	jint sentBytes = socketslave->send((void*) data, numOfBytes);
	env->ReleaseByteArrayElements(arr, data, JNI_ABORT);
	return sentBytes;
}

extern "C"
JAVA_FUNC_DECLARATION(SocketSlavereceive, jint)(JNIEnv* env, jobject caller, jbyteArray arr, jint numOfBytes)
{
	jboolean isCopy = 0;
	jbyte* data = env->GetByteArrayElements(arr, &isCopy);
	jint receivedBytes = socketslave->receive((void*) data, numOfBytes);
	env->ReleaseByteArrayElements(arr, data, 0);
	return receivedBytes;
}

extern "C"
JAVA_FUNC_DECLARATION(SocketSlavegetAddress, void)(JNIEnv* env, jobject caller, jbyteArray arr)
{
	SocketAddressLocal* address = (SocketAddressLocal*) socketslave->getAddress();

	jboolean isCopy = 0;
	jbyte* data = env->GetByteArrayElements(arr, &isCopy);
	address->serialize((void*)data);
	env->ReleaseByteArrayElements(arr, data, 0);

	printf("Address:\n%d :: %s\nlen: %d, size: %d\n", ((sockaddr_un*)address->getAddress())->sun_family, ((sockaddr_un*)address->getAddress())->sun_path, address->getLen(), address->getSize());
}

extern "C"
JAVA_FUNC_DECLARATION(SocketSlaveGetUniqueID, jstring)(JNIEnv* env, jobject caller)
{
	jstring uniqueID = env->NewStringUTF(socketslave->getUniqueID().c_str());
	return uniqueID;
}


