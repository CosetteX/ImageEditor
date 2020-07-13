#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>

class ICommandBase;
class ICommandNotification;

class View : public QGraphicsView
{
    Q_OBJECT
public:
    explicit View(QWidget *parent = nullptr);

    std::shared_ptr<ICommandNotification> GetUpdateNotification();

    void OpenFile(const QString &fileName);
    void Gray();
    void Blur();
    void Sharp();

    void SetOpenFileCommand(std::shared_ptr<ICommandBase> command);
    void SetGrayCommand(std::shared_ptr<ICommandBase> command);
    void SetBlurCommand(std::shared_ptr<ICommandBase> command);
    void SetSharpCommand(std::shared_ptr<ICommandBase> command);

    void SetImage(std::shared_ptr<QImage> img);
    void UpdateImage();

private:
    std::shared_ptr<ICommandBase> imageModel;
    std::shared_ptr<ICommandBase> openFileCommand;
    std::shared_ptr<ICommandBase> saveFileCommand;
    std::shared_ptr<ICommandBase> sharpCommand;
    std::shared_ptr<ICommandBase> grayCommand;
    std::shared_ptr<ICommandBase> blurCommand;

    std::shared_ptr<QImage> image;
    std::shared_ptr<ICommandNotification> updateNotification;
};

#endif // VIEW_H
