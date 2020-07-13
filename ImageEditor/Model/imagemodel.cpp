#include "imagemodel.h"
#include <QDebug>
using namespace  std;
using namespace cv;

ImageModel::ImageModel()
{
    zooming = false;
}

void ImageModel::OpenFile(const std::string &path)
{
    originImage = imread(path);
    interImage = originImage.clone();
    currentImage = interImage;
    Update();
}

void ImageModel::SaveFile(const string &path)
{
    // TODO: notify command
    imwrite(path, currentImage);
}

void ImageModel::Sharp()
{
    Mat sharpkernel = (Mat_<float>(3, 3) <<
                       0, -1, 0,
                       -1,10, -1,
                       0, -1, 0);
    filter2D(interImage, interImage, CV_8UC1, sharpkernel);
    Update();
}

void ImageModel::Gray()
{
    if (interImage.empty() || interImage.channels() == 1)
        return;
    cvtColor(interImage, interImage, COLOR_BGR2GRAY);
    Update();
}

void ImageModel::Blur(int ksize, int anchor)
{
    blur(interImage, interImage, Size(ksize, ksize), Point(anchor, anchor));
    Update();
}

void ImageModel::Rotate(int angle)
{
    if (angle == 90)
        rotate(interImage, interImage, ROTATE_90_CLOCKWISE);
    else if (angle == -90)
        rotate(interImage, interImage, ROTATE_90_COUNTERCLOCKWISE);
    else if (angle == 180)
        rotate(interImage, interImage, ROTATE_180);
    Update();
}

void ImageModel::Zoom(double sx, double sy)
{
    // 缩放时以原图进行缩放
    zooming = true;
    resize(interImage, currentImage, Size(currentImage.cols * sx, currentImage.rows * sy), INTER_LINEAR);
    Update();
}

void ImageModel::ZoomIn()
{
    Zoom(1.5, 1.5);
}

void ImageModel::ZoomOut()
{
    Zoom(0.75, 0.75);
}

void ImageModel::ResetZoom()
{
    currentImage = interImage;
    Update();
}

void ImageModel::Update()
{
    // 图像进行过缩放操作
    if (interImage.cols != currentImage.cols || interImage.rows != currentImage.rows) {
        if (!zooming)
            resize(interImage, currentImage, Size(currentImage.cols, currentImage.rows), INTER_LINEAR);
        zooming = false;
    } else currentImage = interImage;

    Fire_OnCommandComplete("Update", true);   // 应该避免使用字符串常量
}

Mat ImageModel::GetImage()
{
    return currentImage;
}
