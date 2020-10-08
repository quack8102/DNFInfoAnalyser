#ifndef CVALGORITHM_H
#define CVALGORITHM_H

#include <QImage>
#include <QPixmap>
#include <vector>
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

// helper function:
// finds a cosine of angle between vectors
double angle(cv::Point pt1, cv::Point pt2, cv::Point pt0);
// returns sequence of squares detected on the image.
// the sequence is stored in the specified memory storage
void findSquares(const cv::Mat &image, std::vector<std::vector<cv::Point> > &squares);
// the function draws all the squares in the image
void drawSquares( cv::Mat &image, const std::vector<std::vector<cv::Point> > &squares );

void houghTest(const cv::Mat &src);
}

#endif // CVALGORITHM_H
