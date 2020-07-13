#include "viewnotification.h"
#include "view.h"

ViewNotification::ViewNotification(View *v)
    : view(v)
{

}

void UpdateViewNotification::OnCommandComplete(const std::string &str, bool)
{
    if (str == "Update")
        view->UpdateImage();
}
