#include "viewmodelnotification.h"
#include "imageviewmodel.h"

ViewModelNotification::ViewModelNotification(ImageViewModel *vm)
    : viewModel(vm)
{

}

void UpdateViewModelNotification::OnCommandComplete(const std::string &str, bool bOk)
{
    viewModel->UpdateImage();
    viewModel->Fire_OnCommandComplete(str, bOk);
}
