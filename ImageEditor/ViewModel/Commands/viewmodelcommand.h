#ifndef VIEWMODELCOMMAND_H
#define VIEWMODELCOMMAND_H

#include "../../Common/etl.h"

class ImageViewModel;

class ViewModelCommand : public ICommandBase
{
public:
    ViewModelCommand(std::shared_ptr<ImageViewModel> vm);

protected:
    std::weak_ptr<ImageViewModel> viewModel;   // 使用weak_ptr避免循环引用问题，导致资源得不到释放
};

class OpenFileCommand : public ViewModelCommand
{
public:
    using ViewModelCommand::ViewModelCommand;

    virtual void Exec() override;
};

class SaveFileCommand : public ViewModelCommand
{
public:
    using ViewModelCommand::ViewModelCommand;

    virtual void Exec() override;
};

class SharpCommand : public ViewModelCommand
{
public:
    using ViewModelCommand::ViewModelCommand;

    virtual void Exec() override;
};

class GrayCommand : public ViewModelCommand
{
public:
    using ViewModelCommand::ViewModelCommand;

    virtual void Exec() override;
};

class BlurCommand : public ViewModelCommand
{
public:
    using ViewModelCommand::ViewModelCommand;

    virtual void Exec() override;
};

#endif // VIEWMODELCOMMAND_H
