/****************************************************************************
** Meta object code from reading C++ file 'environment.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "environment.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'environment.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Environment[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      40,   12,   12,   12, 0x05,
      51,   12,   12,   12, 0x05,
      66,   12,   12,   12, 0x05,
      84,   12,   12,   12, 0x05,
     107,   12,   12,   12, 0x05,
     121,   12,   12,   12, 0x05,
     136,   12,   12,   12, 0x05,
     190,  156,   12,   12, 0x05,
     262,  259,   12,   12, 0x05,
     291,   12,   12,   12, 0x05,
     311,  309,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
     329,   12,   12,   12, 0x0a,
     335,   12,   12,   12, 0x0a,
     346,  343,   12,   12, 0x0a,
     357,   12,   12,   12, 0x0a,
     368,   12,   12,   12, 0x0a,
     376,  343,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Environment[] = {
    "Environment\0\0sendEM(QMap<int,Entite*>&)\0"
    "sendMort()\0sendScore(int)\0sendTime(envTime)\0"
    "sendTotalTime(envTime)\0sendLife(int)\0"
    "sendTimer(int)\0playerWounded(bool)\0"
    "entity_map,entity_type_map,player\0"
    "send_info_to_ai(QMap<int,Entite*>,QMultiMap<std::string,int>,Player)\0"
    ",,\0display(std::string,int,int)\0"
    "chgMusic(QString)\0,\0mobDeath(int,int)\0"
    "run()\0pause()\0ID\0shoot(int)\0canShoot()\0"
    "waves()\0killMob(int)\0"
};

void Environment::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Environment *_t = static_cast<Environment *>(_o);
        switch (_id) {
        case 0: _t->sendEM((*reinterpret_cast< QMap<int,Entite*>(*)>(_a[1]))); break;
        case 1: _t->sendMort(); break;
        case 2: _t->sendScore((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->sendTime((*reinterpret_cast< envTime(*)>(_a[1]))); break;
        case 4: _t->sendTotalTime((*reinterpret_cast< envTime(*)>(_a[1]))); break;
        case 5: _t->sendLife((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->sendTimer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->playerWounded((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->send_info_to_ai((*reinterpret_cast< const QMap<int,Entite*>(*)>(_a[1])),(*reinterpret_cast< const QMultiMap<std::string,int>(*)>(_a[2])),(*reinterpret_cast< const Player(*)>(_a[3]))); break;
        case 9: _t->display((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 10: _t->chgMusic((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->mobDeath((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->run(); break;
        case 13: _t->pause(); break;
        case 14: _t->shoot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->canShoot(); break;
        case 16: _t->waves(); break;
        case 17: _t->killMob((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Environment::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Environment::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Environment,
      qt_meta_data_Environment, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Environment::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Environment::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Environment::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Environment))
        return static_cast<void*>(const_cast< Environment*>(this));
    return QObject::qt_metacast(_clname);
}

int Environment::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void Environment::sendEM(QMap<int,Entite*> & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Environment::sendMort()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Environment::sendScore(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Environment::sendTime(envTime _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Environment::sendTotalTime(envTime _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Environment::sendLife(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Environment::sendTimer(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Environment::playerWounded(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Environment::send_info_to_ai(const QMap<int,Entite*> & _t1, const QMultiMap<std::string,int> & _t2, const Player & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Environment::display(std::string _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Environment::chgMusic(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Environment::mobDeath(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}
QT_END_MOC_NAMESPACE
