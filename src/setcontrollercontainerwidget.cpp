#include "setcontrollercontainerwidget.h"

SetControllerContainerWidget::SetControllerContainerWidget(setControl *setControl, QWidget *parent) : QWidget(parent) {
    this->setController = setControl;
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setController->setParent(this);
    this->setController->setFixedWidth(this->size().width());

    this->setController->setFixedHeight(this->size().height());
}

void SetControllerContainerWidget::resizeEvent(QResizeEvent* event) {
    std::cout << "Height : " << event->size().height() << "  width " << event->size().width() << std::endl;
    std::cout << "setController Height : " << setController->size().height() << "  width " << setController->size().width() << std::endl << std::endl;
    this->setController->setFixedWidth(this->size().width());

    this->setController->setFixedHeight(this->size().height());
    this->setController->update();
}
