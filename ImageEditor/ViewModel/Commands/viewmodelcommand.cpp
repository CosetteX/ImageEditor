#include "viewmodelcommand.h"
#include "../imageviewmodel.h"
#include "../../Parameter/parameter.h"

using namespace  std;

ViewModelCommand::ViewModelCommand(std::shared_ptr<ImageViewModel> vm)
    : viewModel(vm)
{

}

void OpenFileCommand::Exec()
{
    string path = GetParameter<StringParameter>()->str;
    viewModel.lock()->ExecOpenFileCommand(path);
}

void SaveFileCommand::Exec()
{
    string path = GetParameter<StringParameter>()->str;
    viewModel.lock()->ExecSaveFileCommand(path);
}

void SharpCommand::Exec()
{
    viewModel.lock()->ExecSharpCommand();
}

void GrayCommand::Exec()
{
    viewModel.lock()->ExecGrayCommand();
}

void BlurCommand::Exec()
{
    auto param = GetParameter<BlurParameter>();
    viewModel.lock()->ExecBlurCommand(param->ksize, param->anchor);
}
