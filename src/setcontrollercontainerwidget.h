#ifndef SETCONTROLLERCONTAINERWIDGET_H
#define SETCONTROLLERCONTAINERWIDGET_H

#include <QWidget>
#include "src/setcontrol.h"

class SetControllerContainerWidget : public QWidget {
    Q_OBJECT
public:
    explicit SetControllerContainerWidget(setControl *setController, QWidget *parent = nullptr);
    void resizeEvent(QResizeEvent* event);


protected:
    setControl *setController = nullptr;
signals:

};

#endif // SETCONTROLLERCONTAINERWIDGET_H
