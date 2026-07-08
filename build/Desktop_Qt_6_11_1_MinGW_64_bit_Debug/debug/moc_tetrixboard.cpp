/****************************************************************************
** Meta object code from reading C++ file 'tetrixboard.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../tetrixboard.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tetrixboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN11TetrixBoardE_t {};
} // unnamed namespace

template <> constexpr inline auto TetrixBoard::qt_create_metaobjectdata<qt_meta_tag_ZN11TetrixBoardE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "TetrixBoard",
        "levelChanged",
        "",
        "level",
        "scoreChanged",
        "score",
        "linesRemovedChanged",
        "numLines",
        "sendAttack",
        "stoneLinesChanged",
        "numStones",
        "shieldActiveChanged",
        "active",
        "earthquakeReadyChanged",
        "ready",
        "showWarning",
        "screenShake",
        "gameOver",
        "finalScore",
        "finalLevel",
        "linesCleared",
        "hitEffect",
        "hitCount",
        "QPoint",
        "pos",
        "bubbleEffect",
        "text",
        "energyChanged",
        "current",
        "max",
        "monsterHealthChanged",
        "lineClearedFlash",
        "monsterAngry",
        "adventureLevelComplete",
        "adventureGameOver",
        "won",
        "luckyMessage",
        "message",
        "monsterHit",
        "start",
        "pause",
        "addGarbageLines",
        "startCollapseShatter",
        "startFreezeShatter"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'levelChanged'
        QtMocHelpers::SignalData<void(int)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'scoreChanged'
        QtMocHelpers::SignalData<void(int)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 5 },
        }}),
        // Signal 'linesRemovedChanged'
        QtMocHelpers::SignalData<void(int)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Signal 'sendAttack'
        QtMocHelpers::SignalData<void(int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Signal 'stoneLinesChanged'
        QtMocHelpers::SignalData<void(int)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 10 },
        }}),
        // Signal 'shieldActiveChanged'
        QtMocHelpers::SignalData<void(bool)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 12 },
        }}),
        // Signal 'earthquakeReadyChanged'
        QtMocHelpers::SignalData<void(bool)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 14 },
        }}),
        // Signal 'showWarning'
        QtMocHelpers::SignalData<void(int)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Signal 'screenShake'
        QtMocHelpers::SignalData<void()>(16, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'gameOver'
        QtMocHelpers::SignalData<void(int, int, int)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 18 }, { QMetaType::Int, 19 }, { QMetaType::Int, 20 },
        }}),
        // Signal 'hitEffect'
        QtMocHelpers::SignalData<void(int, const QPoint &)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 22 }, { 0x80000000 | 23, 24 },
        }}),
        // Signal 'bubbleEffect'
        QtMocHelpers::SignalData<void(const QString &, const QPoint &)>(25, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 26 }, { 0x80000000 | 23, 24 },
        }}),
        // Signal 'energyChanged'
        QtMocHelpers::SignalData<void(int, int)>(27, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 28 }, { QMetaType::Int, 29 },
        }}),
        // Signal 'monsterHealthChanged'
        QtMocHelpers::SignalData<void(int, int)>(30, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 28 }, { QMetaType::Int, 29 },
        }}),
        // Signal 'lineClearedFlash'
        QtMocHelpers::SignalData<void()>(31, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'monsterAngry'
        QtMocHelpers::SignalData<void()>(32, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'adventureLevelComplete'
        QtMocHelpers::SignalData<void()>(33, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'adventureGameOver'
        QtMocHelpers::SignalData<void(bool)>(34, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 35 },
        }}),
        // Signal 'luckyMessage'
        QtMocHelpers::SignalData<void(const QString &)>(36, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 37 },
        }}),
        // Signal 'monsterHit'
        QtMocHelpers::SignalData<void()>(38, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'start'
        QtMocHelpers::SlotData<void()>(39, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'pause'
        QtMocHelpers::SlotData<void()>(40, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'addGarbageLines'
        QtMocHelpers::SlotData<void(int)>(41, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Slot 'startCollapseShatter'
        QtMocHelpers::SlotData<void()>(42, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'startFreezeShatter'
        QtMocHelpers::SlotData<void()>(43, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<TetrixBoard, qt_meta_tag_ZN11TetrixBoardE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject TetrixBoard::staticMetaObject = { {
    QMetaObject::SuperData::link<QFrame::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11TetrixBoardE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11TetrixBoardE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11TetrixBoardE_t>.metaTypes,
    nullptr
} };

void TetrixBoard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<TetrixBoard *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->levelChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->scoreChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->linesRemovedChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->sendAttack((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->stoneLinesChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->shieldActiveChanged((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->earthquakeReadyChanged((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->showWarning((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->screenShake(); break;
        case 9: _t->gameOver((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[3]))); break;
        case 10: _t->hitEffect((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QPoint>>(_a[2]))); break;
        case 11: _t->bubbleEffect((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QPoint>>(_a[2]))); break;
        case 12: _t->energyChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2]))); break;
        case 13: _t->monsterHealthChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2]))); break;
        case 14: _t->lineClearedFlash(); break;
        case 15: _t->monsterAngry(); break;
        case 16: _t->adventureLevelComplete(); break;
        case 17: _t->adventureGameOver((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 18: _t->luckyMessage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 19: _t->monsterHit(); break;
        case 20: _t->start(); break;
        case 21: _t->pause(); break;
        case 22: _t->addGarbageLines((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 23: _t->startCollapseShatter(); break;
        case 24: _t->startFreezeShatter(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (TetrixBoard::*)(int )>(_a, &TetrixBoard::levelChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (TetrixBoard::*)(int )>(_a, &TetrixBoard::scoreChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (TetrixBoard::*)(int )>(_a, &TetrixBoard::linesRemovedChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (TetrixBoard::*)(int )>(_a, &TetrixBoard::sendAttack, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (TetrixBoard::*)(int )>(_a, &TetrixBoard::stoneLinesChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (TetrixBoard::*)(bool )>(_a, &TetrixBoard::shieldActiveChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (TetrixBoard::*)(bool )>(_a, &TetrixBoard::earthquakeReadyChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (TetrixBoard::*)(int )>(_a, &TetrixBoard::showWarning, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (TetrixBoard::*)()>(_a, &TetrixBoard::screenShake, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (TetrixBoard::*)(int , int , int )>(_a, &TetrixBoard::gameOver, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (TetrixBoard::*)(int , const QPoint & )>(_a, &TetrixBoard::hitEffect, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (TetrixBoard::*)(const QString & , const QPoint & )>(_a, &TetrixBoard::bubbleEffect, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (TetrixBoard::*)(int , int )>(_a, &TetrixBoard::energyChanged, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (TetrixBoard::*)(int , int )>(_a, &TetrixBoard::monsterHealthChanged, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (TetrixBoard::*)()>(_a, &TetrixBoard::lineClearedFlash, 14))
            return;
        if (QtMocHelpers::indexOfMethod<void (TetrixBoard::*)()>(_a, &TetrixBoard::monsterAngry, 15))
            return;
        if (QtMocHelpers::indexOfMethod<void (TetrixBoard::*)()>(_a, &TetrixBoard::adventureLevelComplete, 16))
            return;
        if (QtMocHelpers::indexOfMethod<void (TetrixBoard::*)(bool )>(_a, &TetrixBoard::adventureGameOver, 17))
            return;
        if (QtMocHelpers::indexOfMethod<void (TetrixBoard::*)(const QString & )>(_a, &TetrixBoard::luckyMessage, 18))
            return;
        if (QtMocHelpers::indexOfMethod<void (TetrixBoard::*)()>(_a, &TetrixBoard::monsterHit, 19))
            return;
    }
}

const QMetaObject *TetrixBoard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TetrixBoard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11TetrixBoardE_t>.strings))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int TetrixBoard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void TetrixBoard::levelChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void TetrixBoard::scoreChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void TetrixBoard::linesRemovedChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void TetrixBoard::sendAttack(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void TetrixBoard::stoneLinesChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void TetrixBoard::shieldActiveChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void TetrixBoard::earthquakeReadyChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}

// SIGNAL 7
void TetrixBoard::showWarning(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}

// SIGNAL 8
void TetrixBoard::screenShake()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void TetrixBoard::gameOver(int _t1, int _t2, int _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1, _t2, _t3);
}

// SIGNAL 10
void TetrixBoard::hitEffect(int _t1, const QPoint & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 10, nullptr, _t1, _t2);
}

// SIGNAL 11
void TetrixBoard::bubbleEffect(const QString & _t1, const QPoint & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 11, nullptr, _t1, _t2);
}

// SIGNAL 12
void TetrixBoard::energyChanged(int _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 12, nullptr, _t1, _t2);
}

// SIGNAL 13
void TetrixBoard::monsterHealthChanged(int _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 13, nullptr, _t1, _t2);
}

// SIGNAL 14
void TetrixBoard::lineClearedFlash()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void TetrixBoard::monsterAngry()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void TetrixBoard::adventureLevelComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void TetrixBoard::adventureGameOver(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 17, nullptr, _t1);
}

// SIGNAL 18
void TetrixBoard::luckyMessage(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 18, nullptr, _t1);
}

// SIGNAL 19
void TetrixBoard::monsterHit()
{
    QMetaObject::activate(this, &staticMetaObject, 19, nullptr);
}
QT_WARNING_POP
