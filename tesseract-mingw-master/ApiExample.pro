QT          =

TARGET      = ApiExample
TEMPLATE    = app

OBJECTS_DIR += temp
MOC_DIR     += temp
UI_DIR      += temp
RCC_DIR     += temp

INCLUDEPATH += ./lib/

SOURCES += ApiExample.cpp
LIBS    += -llept -ltesseract

