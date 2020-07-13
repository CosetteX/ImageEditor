#include "view.h"
#include "viewnotification.h"
#include "Parameter/parameter.h"

#include <QGraphicsItem>

using namespace std;

View::View(QWidget *parent)
    : QGraphicsView(parent)
    , updateNotification(static_pointer_cast<ICommandNotification>(make_shared<UpdateViewNotification>(this)))
{
    setScene(new QGraphicsScene(this));
}

std::shared_ptr<ICommandNotification> View::GetUpdateNotification()
{
    return updateNotification;
}

void View::OpenFile(const QString &fileName)
{
    openFileCommand->SetParameter(make_shared<StringParameter>(fileName.toLocal8Bit().toStdString()));
    openFileCommand->Exec();
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

void View::SetOpenFileCommand(std::shared_ptr<ICommandBase> command)
{
    openFileCommand = command;
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

void View::SetImage(std::shared_ptr<QImage> img)
{
    image = img;
}

void View::UpdateImage()
{
    scene()->clear();

    scene()->addPixmap(QPixmap::fromImage(*image).scaled(size() - QSize(2, 2), Qt::KeepAspectRatio));
}
