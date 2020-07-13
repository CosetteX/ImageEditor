#ifndef VIEWNOTIFICATION_H
#define VIEWNOTIFICATION_H

#include "Common/etl.h"

class View;

class ViewNotification : public ICommandNotification
{
public:
    explicit ViewNotification(View *v);

protected:
    View *view;
};

class UpdateViewNotification : public ViewNotification
{
public:
    using ViewNotification::ViewNotification;

    virtual void OnCommandComplete(const std::string& str, bool) override;
};

#endif // VIEWNOTIFICATION_H
