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
