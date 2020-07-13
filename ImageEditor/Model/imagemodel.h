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

    void Update();
    cv::Mat GetImage();
private:
    cv::Mat currentImage;
    cv::Mat originImage;
};

#endif // IMAGEMODEL_H
