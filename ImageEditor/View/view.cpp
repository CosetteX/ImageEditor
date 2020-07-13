#include "view.h"
#include "viewnotification.h"
#include "Parameter/parameter.h"

#include <QGraphicsItem>
#include <QDebug>

using namespace std;

View::View(QWidget *parent)
    : QGraphicsView(parent)
    , updateNotification(static_pointer_cast<ICommandNotification>(make_shared<UpdateViewNotification>(this)))
{
    setScene(new QGraphicsScene(this));
    setDragMode(ScrollHandDrag);   // 开启抓手模式
}

std::shared_ptr<ICommandNotification> View::GetUpdateNotification()
{
    return updateNotification;
}

void View::OpenFile(const QString &fileName)
{
    currentFileName = fileName;
    openFileCommand->SetParameter(make_shared<StringParameter>(fileName.toLocal8Bit().toStdString()));
    openFileCommand->Exec();
}

void View::SaveFile()
{
    SaveFile(currentFileName);
}

void View::SaveFile(const QString &fileName)
{
    saveFileCommand->SetParameter(make_shared<StringParameter>(fileName.toLocal8Bit().toStdString()));
    saveFileCommand->Exec();
}

void View::Gray()
{
    grayCommand->Exec();
}

void View::Blur()
{
    blurCommand->SetParameter(make_shared<BlurParameter>());
    blurCommand->Exec();
}

void View::Sharp()
{
    sharpCommand->Exec();
}

void View::Rotate(int angle)
{
    rotateCommand->SetParameter(make_shared<BasicParameter<int>>(angle));
    rotateCommand->Exec();
}

void View::ZoomIn()
{
    zoomCommand->SetParameter(make_shared<ZoomParameter>(1));
    zoomCommand->Exec();
}

void View::ZoomOut()
{
    zoomCommand->SetParameter(make_shared<ZoomParameter>(2));
    zoomCommand->Exec();
}

void View::ResetZoom()
{
    zoomCommand->SetParameter(make_shared<ZoomParameter>(3));
    zoomCommand->Exec();
}

void View::SetOpenFileCommand(std::shared_ptr<ICommandBase> command)
{
    openFileCommand = command;
}

void View::SetSaveFileCommand(std::shared_ptr<ICommandBase> command)
{
    saveFileCommand = command;
}

void View::SetGrayCommand(std::shared_ptr<ICommandBase> command)
{
    grayCommand = command;
}

void View::SetBlurCommand(std::shared_ptr<ICommandBase> command)
{
    blurCommand = command;
}

void View::SetSharpCommand(std::shared_ptr<ICommandBase> command)
{
    sharpCommand = command;
}

void View::SetRotateCommand(std::shared_ptr<ICommandBase> command)
{
    rotateCommand = command;
}

void View::SetZoomCommand(std::shared_ptr<ICommandBase> command)
{
    zoomCommand = command;
}

void View::SetImage(std::shared_ptr<QImage> img)
{
    image = img;
}

void View::UpdateImage()
{
    scene()->clear();

//    scene()->addPixmap(QPixmap::fromImage(*image).scaled(size() - QSize(2, 2), Qt::KeepAspectRatio));
    auto item = scene()->addPixmap(QPixmap::fromImage(*image));

    // 让图片总是居中显示
    QPointF center = mapToScene(viewport()->rect().center());
    QRectF boundingRect = item->boundingRect();
    item->setPos(center.x() - boundingRect.width() / 2, center.y() - boundingRect.height() / 2);
}
