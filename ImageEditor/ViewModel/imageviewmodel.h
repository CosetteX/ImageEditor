#ifndef IMAGEVIEWMODEL_H
#define IMAGEVIEWMODEL_H

#include "../Common/etl.h"

class ImageModel;
class OpenFileCommand;
class SaveFileCommand;
class SharpCommand;
class GrayCommand;
class BlurCommand;

class ImageViewModel : public Proxy_CommandNotification<ImageViewModel>
{
public:
    ImageViewModel();

    std::shared_ptr<ICommandBase> GetOpenFileCommand();
    std::shared_ptr<ICommandBase> GetSaveFileCommand();
    std::shared_ptr<ICommandBase> GetSharpCommand();
    std::shared_ptr<ICommandBase> GetGrayCommand();
    std::shared_ptr<ICommandBase> GetBlurCommand();

    void SetModel(std::shared_ptr<ImageModel> model);
    void ExecOpenFileCommand(const std::string &path);
    void ExecSaveFileCommand(const std::string &path);
    void ExecSharpCommand();
    void ExecGrayCommand();
    void ExecBlurCommand(int ksize, int anchor);

private:
    std::shared_ptr<ImageModel> imageModel;
    std::shared_ptr<OpenFileCommand> openFileCommand;
    std::shared_ptr<SaveFileCommand> saveFileCommand;
    std::shared_ptr<SharpCommand> sharpCommand;
    std::shared_ptr<GrayCommand> grayCommand;
    std::shared_ptr<BlurCommand> blurCommand;
};

#endif // IMAGEVIEWMODEL_H
