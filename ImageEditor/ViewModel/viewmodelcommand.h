#ifndef VIEWMODELCOMMAND_H
#define VIEWMODELCOMMAND_H

#include "Common/etl.h"

class ImageViewModel;

class ViewModelCommand : public ICommandBase
{
public:
    ViewModelCommand(ImageViewModel *vm);

protected:
    ImageViewModel *viewModel;   // 这里不能使用shared_ptr或者weak_ptr智能指针
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

class RotateCommand : public ViewModelCommand
{
public:
    using ViewModelCommand::ViewModelCommand;

    virtual void Exec() override;
};

class ZoomCommand : public ViewModelCommand
{
public:
    using ViewModelCommand::ViewModelCommand;

    virtual void Exec() override;
};

#endif // VIEWMODELCOMMAND_H
