#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>

#include "Item.h";

int (*_Item_getAttackDamage)(Item *);
int Item_getAttackDamage(Item *item){
	if(item==Item::mItems[280]){
		return 100;
	}else{
		return _Item_getAttackDamage(item);
	}
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	MSHookFunction((void*)&Item::getAttackDamage,(void*)&Item_getAttackDamage,(void**)&_Item_getAttackDamage);
	return JNI_VERSION_1_2;
}
