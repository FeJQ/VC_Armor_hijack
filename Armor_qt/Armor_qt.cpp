#include <Windows.h>
#include "Armor_qt.h"

#include "InlineHook.hpp"
#include "Process.hpp"

hook::InlineHook hooker;
hook::InlineHook hooker2;

typedef void *(* QtConnect)(QObject* _this, const QObject* asender, const char* asignal, const QObject*,const char* amember, Qt::ConnectionType atype) ;
typedef void* (*Connection_dtor)(QMetaObject::Connection* _this);
void* proxyConnectDtor(QMetaObject::Connection* _this) {

	return nullptr;
}
void* proxyConnect(QObject* _this, const QObject* asender, const char* asignal, const QObject* receiver,const char* amember, Qt::ConnectionType atype)
{
	
	if ((std::string(asignal) == "2verifyFinished(int)"  &&std::string(amember) == "1slotVerifyFinished(int)")||(std::string(asignal) == "2registerFinished(int)" && std::string(amember) == "1slotRegisterFinished(int)"))
	{
		return (void*)_this;
	}
	 QtConnect  originFun = (QtConnect)hooker.originalFunction();
	return  originFun(_this,asender, asignal, receiver,amember, atype);
}


void Armor::setupRegLog(QString)
{
}



void Armor::ensureRegInfoValid(QSharedPointer<struct Armor::RegisterBag>)
{
}

Armor::RegManager* Armor::RegManager::sharedInstance(void)
{

	static auto eatFood = []() {
		auto qt5ModuleHandle = LoadLibraryA("Qt5Core.dll");
		auto qt5ProcConnect = GetProcAddress(qt5ModuleHandle, "?connect@QObject@@SA?AVConnection@QMetaObject@@PEBV1@PEBD01W4ConnectionType@Qt@@@Z");
		auto qt5ProcConnect_dtor = GetProcAddress(qt5ModuleHandle, "??1Connection@QMetaObject@@QEAA@XZ");
		QtConnect* connect = reinterpret_cast<QtConnect*>(qt5ProcConnect);

		hooker.hook(connect, proxyConnect);
		hooker2.hook(qt5ProcConnect_dtor, proxyConnectDtor);
	};
	
	
	return nullptr;
}
