#ifndef APP_H
#define APP_H

#include <memory>

class MainWindow;
class View;
class ImageModel;
class ImageViewModel;

class App
{
public:
    App();
    ~App();

    void Run();

private:
    MainWindow *window;

    std::shared_ptr<ImageModel> model;
    std::shared_ptr<ImageViewModel> viewModel;
};

#endif // APP_H
