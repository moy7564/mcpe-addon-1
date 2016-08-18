#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>
#include <string>

#include "GuiData.h";

GuiData* guidata=NULL;

void clientMessage(std::string const&);

void (*_GuiData_tick)(GuiData *);
void GuiData_tick(GuiData *guiData){
	guidata=guiData;
	_GuiData_tick(guiData);
}

void clientMessage(std::string const& m){
	if(guidata!=NULL){
		guidata->displayClientMessage(m);
	}
}

//clientMessage("HelloWorld");

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	MSHookFunction((void*)&GuiData::tick,(void*)&GuiData_tick,(void**)&_GuiData_tick);
	return JNI_VERSION_1_2;
}
