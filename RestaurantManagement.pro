
QT       += core gui
QT += sql
QT += printsupport

#CONFIG += qt warn_off release


#CONFIG(release, debug|release):DEFINES += QT_NO_DEBUG_OUTPUT
#CONFIG(release, debug|release):DEFINES += QT_NO_DEBUG

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RestaurantManagement
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    adminwindow.cpp \
    addnewcatagory.cpp \
    foodcatagory.cpp \
    util.cpp \
    catagory.cpp \
    food.cpp \
    order.cpp \
    tempfooditem.cpp \
    formtempfooditem.cpp \
    boys.cpp \
    tables.cpp \
    tablestatus.cpp \
    calculator.cpp \
    button.cpp \
    adminlogin.cpp \
    updatefoodcatagory.cpp \
    addnewtable.cpp \
    updatetable.cpp \
    diningtables.cpp \
    boyrow.cpp \
    addboy.cpp \
    updateboy.cpp \
    boyview.cpp \
    foodrow.cpp \
    updatefood.cpp \
    addfood.cpp \
    qcustomplot.cpp \
    userregistrationform.cpp \
    users.cpp \
    userregidata.cpp \
    userrow.cpp \
    userview.cpp \
    useredit.cpp \
    userwisetransaction.cpp \
    userlogin.cpp

HEADERS  += mainwindow.h \
    adminwindow.h \
    addnewcatagory.h \
    foodcatagory.h \
    util.h \
    catagory.h \
    food.h \
    order.h \
    tempfooditem.h \
    formtempfooditem.h \
    boys.h \
    tables.h \
    tablestatus.h \
    calculator.h \
    button.h \
    adminlogin.h \
    updatefoodcatagory.h \
    addnewtable.h \
    updatetable.h \
    diningtables.h \
    boyrow.h \
    addboy.h \
    updateboy.h \
    boyview.h \
    foodrow.h \
    updatefood.h \
    addfood.h \
    qcustomplot.h \
    userregistrationform.h \
    users.h \
    userregidata.h \
    userrow.h \
    userview.h \
    useredit.h \
    userwisetransaction.h \
    userlogin.h

FORMS    += mainwindow.ui \
    adminwindow.ui \
    addnewcatagory.ui \
    foodcatagory.ui \
    formtempfooditem.ui \
    tablestatus.ui \
    adminlogin.ui \
    updatefoodcatagory.ui \
    addnewtable.ui \
    updatetable.ui \
    diningtables.ui \
    boyrow.ui \
    addboy.ui \
    updateboy.ui \
    boyview.ui \
    foodrow.ui \
    updatefood.ui \
    addfood.ui \
    userregistrationform.ui \
    users.ui \
    userrow.ui \
    userview.ui \
    useredit.ui \
    userwisetransaction.ui \
    userlogin.ui

RESOURCES += \
    graphImage.qrc \
    handle.qrc \
    statusLed.qrc

OTHER_FILES += \
    Icon.rc
RC_FILE = Icon.rc
