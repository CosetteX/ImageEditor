#include "viewmodelcommand.h"
#include "ViewModel/imageviewmodel.h"
#include "Parameter/parameter.h"

using namespace  std;

ViewModelCommand::ViewModelCommand(ImageViewModel *vm)
    : viewModel(vm)
{

}

void OpenFileCommand::Exec()
{
    string path = GetParameter<StringParameter>()->str;
    viewModel->ExecOpenFileCommand(path);
}

void SaveFileCommand::Exec()
{
    string path = GetParameter<StringParameter>()->str;
    viewModel->ExecSaveFileCommand(path);
}

void SharpCommand::Exec()
{
    viewModel->ExecSharpCommand();
}

void GrayCommand::Exec()
{
    viewModel->ExecGrayCommand();
}

void BlurCommand::Exec()
{
    auto param = GetParameter<BlurParameter>();
    viewModel->ExecBlurCommand(param->ksize, param->anchor);
}

void RotateCommand::Exec()
{
    int value = GetParameter<BasicParameter<int>>()->value;
    viewModel->ExecRotateCommand(value);
}

void ZoomCommand::Exec()
{
    auto param = GetParameter<ZoomParameter>();

    if (param->flag == 0)
        viewModel->ExecZoomCommand(param->sx, param->sy);
    else if (param->flag == 1)
        viewModel->ExecZoomInCommand();
    else if (param->flag == 2)
        viewModel->ExecZoomOutCommand();
    else if (param->flag == 3)
        viewModel->ExecResetZoomCommand();
}
