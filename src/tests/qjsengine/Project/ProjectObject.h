#ifndef DIFFSCOPE_PROJECTOBJECT_H
#define DIFFSCOPE_PROJECTOBJECT_H

#include <QHash>
#include <QJSValue>
#include <QObject>

class QWidget;
class QJSEngine;

class ProjectObject : public QObject {
    Q_OBJECT
    Q_PROPERTY(QJSValue window READ jsWindow)
public:
    explicit ProjectObject(QWidget *window);
    ~ProjectObject() override;

    QWidget *window() const;
    QJSValue invoke(const QString &id, int index = -1);

    QJSValue jsWindow() const;

private:
    QWidget *m_win;

    QHash<QString, QJSValue> m_scriptInstanceDict;

    QJSValue m_thisObject;
    QJSValue m_windowObject;
};


#endif // DIFFSCOPE_PROJECTOBJECT_H