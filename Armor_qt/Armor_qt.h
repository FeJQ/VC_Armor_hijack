#pragma once


#include <QString.h>
#include <QSharedPointer>


namespace Armor {

	struct RegisterBag {


	};
	struct __declspec(dllexport) LicenseInfo {

	};
	class  __declspec(dllexport) RegManager {
	public:
		 static RegManager* sharedInstance(void);
		 LicenseInfo  getLicenseInfo(void) {
			return LicenseInfo();
		};
	};



	__declspec(dllexport) void setupRegLog(QString regLog);
	__declspec(dllexport) QString getRegisterInfo();

	__declspec(dllexport) bool checkDevice(class QString const&, class QSharedPointer<struct RegisterBag>, bool) {
		return true;
	}



	__declspec(dllexport) void ensureRegInfoValid(QSharedPointer<struct RegisterBag>);

	__declspec(dllexport) bool hasRegisterSuccessOnline(void) {
		return true;
	}

	__declspec(dllexport) void popupRegisterInfoDlg(class QSharedPointer<struct Armor::RegisterBag>, bool) {

	}

	__declspec(dllexport) QString getRegisterInfo(void) {
		return QString();
	}

	__declspec(dllexport) void popupRegisterDlg(class QSharedPointer<struct Armor::RegisterBag>) {

	}


};
