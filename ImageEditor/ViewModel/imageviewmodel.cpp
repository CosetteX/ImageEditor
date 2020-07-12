#include "imageviewmodel.h"
#include "../Model/imagemodel.h"
#include "Commands/viewmodelcommand.h"

using namespace std;

ImageViewModel::ImageViewModel()
    : openFileCommand(new OpenFileCommand(shared_ptr<ImageViewModel>(this)))
    , saveFileCommand(new SaveFileCommand(shared_ptr<ImageViewModel>(this)))
    , sharpCommand(new SharpCommand(shared_ptr<ImageViewModel>(this)))
    , grayCommand(new GrayCommand(shared_ptr<ImageViewModel>(this)))
    , blurCommand(new BlurCommand(shared_ptr<ImageViewModel>(this)))
{

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
    return static_pointer_cast<ICommandBase>(sharpCommand);
}

std::shared_ptr<ICommandBase> ImageViewModel::GetBlurCommand()
{
    return static_pointer_cast<ICommandBase>(blurCommand);
}

void ImageViewModel::SetModel(std::shared_ptr<ImageModel> model)
{
    imageModel = model;
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


