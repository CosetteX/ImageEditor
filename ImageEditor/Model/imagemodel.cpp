#include "imagemodel.h"
#include <QDebug>
using namespace  std;
using namespace cv;

ImageModel::ImageModel()
{

}

void ImageModel::OpenFile(const std::string &path)
{
    originImage = imread(path);
    currentImage = originImage.clone();

    Update();
}

void ImageModel::SaveFile(const string &path)
{
    // TODO: notify command
    imwrite(path, currentImage);
}

void ImageModel::Sharp()
{
    qDebug() << Q_FUNC_INFO;
    Mat sharpkernel = (Mat_<float>(3, 3) <<
                       0, -1, 0,
                       -1,10, -1,
                       0, -1, 0);
    filter2D(currentImage, currentImage, CV_8UC1, sharpkernel);
    Update();
}

void ImageModel::Gray()
{
    qDebug() << Q_FUNC_INFO;
    cvtColor(currentImage, currentImage, COLOR_BGR2GRAY);
    Update();
}

void ImageModel::Blur(int ksize, int anchor)
{
    qDebug() << Q_FUNC_INFO;
    blur(currentImage, currentImage, Size(ksize, ksize), Point(anchor, anchor));
    Update();
}

void ImageModel::Update()
{
    Fire_OnCommandComplete("Update", true);   // 应该避免使用字符串常量
}

Mat ImageModel::GetImage()
{
    return currentImage;
}
