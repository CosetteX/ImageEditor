#ifndef IMAGEMODEL_H
#define IMAGEMODEL_H

#include <opencv2/opencv.hpp>
#include <string>
#include "Common/etl.h"

class ImageModel : public Proxy_CommandNotification<ImageModel>
{
public:
    ImageModel();

    void OpenFile(const std::string &path);
    void SaveFile(const std::string &path);

    void Sharp();
    void Gray();
    void Blur(int ksize, int anchor);
    void Rotate(int angle);
    void Zoom(double sx, double sy);
    void ZoomIn();
    void ZoomOut();
    void ResetZoom();

    void Update();
    cv::Mat GetImage();

private:
    bool zooming;
    cv::Mat currentImage;
    cv::Mat originImage;
    cv::Mat interImage;
};

#endif // IMAGEMODEL_H
