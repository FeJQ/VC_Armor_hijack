#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(ARMOR_QT_LIB)
#  define ARMOR_QT_EXPORT Q_DECL_EXPORT
# else
#  define ARMOR_QT_EXPORT Q_DECL_IMPORT
# endif
#else
# define ARMOR_QT_EXPORT
#endif
