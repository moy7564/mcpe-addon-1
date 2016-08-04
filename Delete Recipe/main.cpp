#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>

#include "Recipes.h";
#include "FurnaceRecipes.h";
#include "MinecraftClient.h";

void (*_MinecraftClient_onPlayerLoaded)(MinecraftClient *,Player&);
void MinecraftClient_onPlayerLoaded(MinecraftClient *minecraft,Player&player){
	_MinecraftClient_onPlayerLoaded(minecraft,player);
	Recipes::getInstance()->clearRecipes();
	FurnaceRecipes::getInstance()->clearFurnaceRecipes();
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	MSHookFunction((void*)&MinecraftClient::onPlayerLoaded,(void*)&MinecraftClient_onPlayerLoaded,(void**)&_MinecraftClient_onPlayerLoaded);
	return JNI_VERSION_1_2;
}
