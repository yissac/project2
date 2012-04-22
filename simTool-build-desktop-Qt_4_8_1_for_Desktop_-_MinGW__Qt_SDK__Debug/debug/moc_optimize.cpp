/****************************************************************************
** Meta object code from reading C++ file 'optimize.h'
**
** Created: Sun Apr 22 15:16:36 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/optimize.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'optimize.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_optimize[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x0a,
      31,    9,    9,    9, 0x0a,
      52,    9,    9,    9, 0x0a,
      77,    9,    9,    9, 0x0a,
     102,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_optimize[] = {
    "optimize\0\0on_pushMax_clicked()\0"
    "on_pushMin_clicked()\0on_pushShowMax_clicked()\0"
    "on_pushShowMin_clicked()\0"
    "on_spinVar_valueChanged()\0"
};

void optimize::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        optimize *_t = static_cast<optimize *>(_o);
        switch (_id) {
        case 0: _t->on_pushMax_clicked(); break;
        case 1: _t->on_pushMin_clicked(); break;
        case 2: _t->on_pushShowMax_clicked(); break;
        case 3: _t->on_pushShowMin_clicked(); break;
        case 4: _t->on_spinVar_valueChanged(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData optimize::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject optimize::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_optimize,
      qt_meta_data_optimize, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &optimize::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *optimize::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *optimize::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_optimize))
        return static_cast<void*>(const_cast< optimize*>(this));
    return QWidget::qt_metacast(_clname);
}

int optimize::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
