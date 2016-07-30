#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>

#include "Level.h";


Level *_Level=NULL;


void (*_Level_tick)(Level *);
void Level_tick(Level *level){
	_Level=level;
	_Level_tick(level);
}

void (*_Level_setTime)(Level*,int);
void Level_setTime(int);
void Level_setTime(int time){
	if(_Level!=NULL){
		_Level_setTime(_Level,time);
	}
}

//Level_setTime(int);

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	MSHookFunction((void*)&Level::tick,(void*)&Level_tick,(void**)&_Level_tick);
	_Level_setTime=(void(*)(Level*,int))&Level::setTime;
	return JNI_VERSION_1_2;
}
