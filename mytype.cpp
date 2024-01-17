#include "mytype.h"

/*[[[cog
import cog
from mytype import classMsg, classMyType


cog.outl(classMsg.getClassCpp(),
        dedent=True, trimblanklines=True)


cog.outl(classMyType.getClassCpp(),
        dedent=True, trimblanklines=True)

]]] */
 Msg:: Msg(QObject *parent)
    : QObject(parent)
{
    ctorClass();
}

 MyType:: MyType(QObject *parent)
    : QObject(parent),m_msg(new Msg(this))
{
    ctorClass();
}

//[[[end]]]

void MyType::ctorClass()
{
    m_fullName.setBinding([&] { return m_firstName + " " + m_lastName; });
}

void Msg::ctorClass() {}
