/****************************************************************************
** Meta object code from reading C++ file 'ai_player.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ai_player.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ai_player.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AI_Player[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      21,   10,   10,   10, 0x05,
      32,   10,   10,   10, 0x05,
      40,   10,   10,   10, 0x05,
      50,   10,   10,   10, 0x05,
      61,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      81,   10,   10,   10, 0x0a,
     129,   95,   10,   10, 0x0a,
     193,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AI_Player[] = {
    "AI_Player\0\0go_left()\0go_right()\0go_up()\0"
    "go_down()\0shoot(int)\0go_to_angle(double)\0"
    "exec_action()\0entity_map,entity_type_map,player\0"
    "compute_ed(QMap<int,Entite*>,QMultiMap<std::string,int>,Player)\0"
    "death()\0"
};

void AI_Player::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AI_Player *_t = static_cast<AI_Player *>(_o);
        switch (_id) {
        case 0: _t->go_left(); break;
        case 1: _t->go_right(); break;
        case 2: _t->go_up(); break;
        case 3: _t->go_down(); break;
        case 4: _t->shoot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->go_to_angle((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->exec_action(); break;
        case 7: _t->compute_ed((*reinterpret_cast< const QMap<int,Entite*>(*)>(_a[1])),(*reinterpret_cast< const QMultiMap<std::string,int>(*)>(_a[2])),(*reinterpret_cast< const Player(*)>(_a[3]))); break;
        case 8: _t->death(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AI_Player::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AI_Player::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AI_Player,
      qt_meta_data_AI_Player, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AI_Player::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AI_Player::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AI_Player::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AI_Player))
        return static_cast<void*>(const_cast< AI_Player*>(this));
    return QObject::qt_metacast(_clname);
}

int AI_Player::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void AI_Player::go_left()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void AI_Player::go_right()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void AI_Player::go_up()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void AI_Player::go_down()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void AI_Player::shoot(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void AI_Player::go_to_angle(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
