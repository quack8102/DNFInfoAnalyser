#ifndef CVALGORITHM_H
#define CVALGORITHM_H

#include <QImage>
#include <QPixmap>
#include <opencv2/core/core.hpp>

namespace CVA {
// 将Mat转化为QImage
QImage cvMatToQImage(const cv::Mat &inMat);
//将Mat转化为QPixmap
QPixmap cvMatToQPixmap(const cv::Mat &inMat);
//将QImage转化为Mat
cv::Mat QImageToCvMat(const QImage &inImage, bool inCloneImageData = true);
//将QPixmap转化为Mat
cv::Mat QPixmapToCvMat(const QPixmap &inPixmap, bool inCloneImageData = true);

cv::Point matchTemplate(const cv::Mat &mSrc, const cv::Mat &mTemplate);

double getPSNR(const cv::Mat &M1, const cv::Mat &M2);

cv::Mat darken(const cv::Mat &mat);
}

#endif // CVALGORITHM_H
