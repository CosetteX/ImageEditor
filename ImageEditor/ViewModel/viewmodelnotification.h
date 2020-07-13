#ifndef VIEWMODELNOTIFICATION_H
#define VIEWMODELNOTIFICATION_H

#include "Common/etl.h"

class ImageViewModel;

class ViewModelNotification : public ICommandNotification
{
public:
    explicit ViewModelNotification(ImageViewModel *vm);

protected:
    ImageViewModel *viewModel;
};

class UpdateViewModelNotification : public ViewModelNotification
{
public:
    using ViewModelNotification::ViewModelNotification;

    virtual void OnCommandComplete(const std::string& str, bool bOk) override;
};

#endif // VIEWMODELNOTIFICATION_H
