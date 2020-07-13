#include "imageviewmodel.h"
#include "Model/imagemodel.h"
#include "Common/utils.h"
#include "viewmodelcommand.h"
#include "viewmodelnotification.h"
#include <QDebug>
using namespace std;

ImageViewModel::ImageViewModel()
    : openFileCommand(new OpenFileCommand(this))
    , saveFileCommand(new SaveFileCommand(this))
    , sharpCommand(new SharpCommand(this))
    , grayCommand(new GrayCommand(this))
    , blurCommand(new BlurCommand(this))
    , image(new QImage)
    , updateNotification(new UpdateViewModelNotification(this))
{
}

ImageViewModel::~ImageViewModel()
{
    qDebug() << Q_FUNC_INFO;
}

std::shared_ptr<ICommandBase> ImageViewModel::GetOpenFileCommand()
{
    return static_pointer_cast<ICommandBase>(openFileCommand);
}

std::shared_ptr<ICommandBase> ImageViewModel::GetSaveFileCommand()
{
    return static_pointer_cast<ICommandBase>(saveFileCommand);
}

std::shared_ptr<ICommandBase> ImageViewModel::GetSharpCommand()
{
    return static_pointer_cast<ICommandBase>(sharpCommand);
}

std::shared_ptr<ICommandBase> ImageViewModel::GetGrayCommand()
{
    return static_pointer_cast<ICommandBase>(grayCommand);
}

std::shared_ptr<ICommandBase> ImageViewModel::GetBlurCommand()
{
    return static_pointer_cast<ICommandBase>(blurCommand);
}

std::shared_ptr<QImage> ImageViewModel::GetImage()
{
    return image;
}

void ImageViewModel::SetModel(std::shared_ptr<ImageModel> model)
{
    // FIXME: 可能之前已经存在model了，所以需要移除notification
    imageModel = model;
    imageModel->AddCommandNotification(updateNotification);
}

void ImageViewModel::ExecOpenFileCommand(const std::string &path)
{
    imageModel->OpenFile(path);
}

void ImageViewModel::ExecSaveFileCommand(const std::string &path)
{
    imageModel->SaveFile(path);
}

void ImageViewModel::ExecSharpCommand()
{
    imageModel->Sharp();
}

void ImageViewModel::ExecGrayCommand()
{
    imageModel->Gray();
}

void ImageViewModel::ExecBlurCommand(int ksize, int anchor)
{
    imageModel->Blur(ksize, anchor);
}

void ImageViewModel::UpdateImage()
{
    *image = Mat2QImage(imageModel->GetImage());
}


