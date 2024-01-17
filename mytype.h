#ifndef MYTYPE_H
#define MYTYPE_H

#include <QObject>
#include <QObjectComputedProperty>
#include <QQmlEngine>

/*[[[cog
import cog
from mytype import classMsg, classMyType


cog.outl(classMsg.getClassHeader(),
        dedent=True, trimblanklines=True)


cog.outl(classMyType.getClassHeader(),
        dedent=True, trimblanklines=True)

]]] */
class Msg : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged )
    
    QML_ELEMENT
public:
    Msg(QObject *parent = nullptr);

    
    
    QString message() const{return m_message;} 
    
void setMessage(const QString &newMessage)
    {
        if (m_message == newMessage)
            return;
        m_message = newMessage;
        emit messageChanged();
    }



signals:
    void messageChanged();
    

private:
    QString m_message;
    
    void ctorClass();
};

class MyType : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString firstName READ firstName WRITE setFirstName NOTIFY firstNameChanged BINDABLE bindableFirstName)
    Q_PROPERTY(QString lastName READ lastName WRITE setLastName NOTIFY lastNameChanged BINDABLE bindableLastName)
    Q_PROPERTY(QString fullName READ fullName  NOTIFY fullNameChanged BINDABLE bindableFullName)
    Q_PROPERTY(Msg * msg READ msg  CONSTANT )
    
    QML_ELEMENT
public:
    MyType(QObject *parent = nullptr);

    
    QBindable<QString> bindableFirstName() { return &m_firstName; }
    QString firstName() const{return m_firstName;} 
    
void setFirstName(const QString &newFirstName)
    {
        if (m_firstName == newFirstName)
            return;
        m_firstName = newFirstName;
        emit firstNameChanged();
    }


    QBindable<QString> bindableLastName() { return &m_lastName; }
    QString lastName() const{return m_lastName;} 
    
void setLastName(const QString &newLastName)
    {
        if (m_lastName == newLastName)
            return;
        m_lastName = newLastName;
        emit lastNameChanged();
    }


    QBindable<QString> bindableFullName() { return &m_fullName; }
    QString fullName() const{return m_fullName;} 
    

    
    Msg * msg() const{return m_msg;} 
    


signals:
    void firstNameChanged();
    void lastNameChanged();
    void fullNameChanged();
    

private:
    Q_OBJECT_BINDABLE_PROPERTY(MyType, QString, m_firstName, &MyType::firstNameChanged)
    Q_OBJECT_BINDABLE_PROPERTY(MyType, QString, m_lastName, &MyType::lastNameChanged)
    Q_OBJECT_BINDABLE_PROPERTY(MyType, QString, m_fullName, &MyType::fullNameChanged)
    Msg * m_msg;
    
    void ctorClass();
};

//[[[end]]]
#endif // MYTYPE_H
