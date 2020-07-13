#include "app.h"
#include "View/mainwindow.h"
#include "View/view.h"
#include "Model/imagemodel.h"
#include "ViewModel/imageviewmodel.h"

using namespace std;

App::App()
    : window(new MainWindow)
    , model(make_shared<ImageModel>())
    , viewModel(make_shared<ImageViewModel>())
{
    viewModel->SetModel(model);

    // TODO: multiple view
    auto *view = window->GetCurrentView();
    view->SetOpenFileCommand(viewModel->GetOpenFileCommand());
    view->SetSaveFileCommand(viewModel->GetSaveFileCommand());
    view->SetGrayCommand(viewModel->GetGrayCommand());
    view->SetBlurCommand(viewModel->GetBlurCommand());
    view->SetSharpCommand(viewModel->GetSharpCommand());
    view->SetRotateCommand(viewModel->GetRotateCommand());
    view->SetZoomCommand(viewModel->GetZoomCommand());
    view->SetImage(viewModel->GetImage());

    // Add notification
    viewModel->AddCommandNotification(view->GetUpdateNotification());
}

App::~App()
{
    delete window;
}

void App::Run()
{
    window->show();
}
