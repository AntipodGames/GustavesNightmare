/****************************************************************************
** Meta object code from reading C++ file 'qsfcanvas.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qsfcanvas.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsfcanvas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QSFcanvas[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      22,   10,   10,   10, 0x05,
      34,   10,   10,   10, 0x05,
      43,   10,   10,   10, 0x05,
      54,   10,   10,   10, 0x05,
      67,   65,   10,   10, 0x05,
      89,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     103,   10,   10,   10, 0x0a,
     114,  111,   10,   10, 0x0a,
     144,   10,   10,   10, 0x0a,
     159,   10,   10,   10, 0x0a,
     176,   10,   10,   10, 0x0a,
     193,  188,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QSFcanvas[] = {
    "QSFcanvas\0\0turnLeft()\0turnRight()\0"
    "turnUp()\0turnDown()\0setPause()\0,\0"
    "sendMousePos(int,int)\0sigShoot(int)\0"
    "pause()\0em\0receiveEM(QMap<int,Entite*>&)\0"
    "updateVie(int)\0updateTimer(int)\0"
    "heroDeath()\0,x,y\0dispEvent(std::string,int,int)\0"
};

void QSFcanvas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QSFcanvas *_t = static_cast<QSFcanvas *>(_o);
        switch (_id) {
        case 0: _t->turnLeft(); break;
        case 1: _t->turnRight(); break;
        case 2: _t->turnUp(); break;
        case 3: _t->turnDown(); break;
        case 4: _t->setPause(); break;
        case 5: _t->sendMousePos((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->sigShoot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->pause(); break;
        case 8: _t->receiveEM((*reinterpret_cast< QMap<int,Entite*>(*)>(_a[1]))); break;
        case 9: _t->updateVie((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->updateTimer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->heroDeath(); break;
        case 12: _t->dispEvent((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QSFcanvas::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QSFcanvas::staticMetaObject = {
    { &Qsfml::staticMetaObject, qt_meta_stringdata_QSFcanvas,
      qt_meta_data_QSFcanvas, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QSFcanvas::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QSFcanvas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QSFcanvas::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QSFcanvas))
        return static_cast<void*>(const_cast< QSFcanvas*>(this));
    return Qsfml::qt_metacast(_clname);
}

int QSFcanvas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Qsfml::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void QSFcanvas::turnLeft()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QSFcanvas::turnRight()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QSFcanvas::turnUp()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void QSFcanvas::turnDown()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void QSFcanvas::setPause()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void QSFcanvas::sendMousePos(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void QSFcanvas::sigShoot(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
