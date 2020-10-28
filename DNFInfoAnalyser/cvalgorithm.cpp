#include "cvalgorithm.h"
#include <QDebug>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc/types_c.h>
#include <opencv2/highgui/highgui.hpp>

namespace CVA {
QImage cvMatToQImage(const cv::Mat &inMat) {
    switch (inMat.type()) {
    // 8-bit, 4 channel
    case CV_8UC4: {
        QImage image(inMat.data,
                     inMat.cols, inMat.rows,
                     static_cast<int>(inMat.step),
                     QImage::Format_ARGB32);
        return image;
    }

    // 8-bit, 3 channel
    case CV_8UC3: {
        QImage image(inMat.data,
                     inMat.cols, inMat.rows,
                     static_cast<int>(inMat.step),
                     QImage::Format_RGB888);
        return image.rgbSwapped();
    }

    // 8-bit, 1 channel
    case CV_8UC1: {
#if QT_VERSION >= QT_VERSION_CHECK(5, 5, 0)
        QImage image(inMat.data,
                     inMat.cols, inMat.rows,
                     static_cast<int>(inMat.step),
                     QImage::Format_Grayscale8);//Format_Alpha8 and Format_Grayscale8 were added in Qt 5.5
#else//这里还有一种写法，最后给出
        static QVector<QRgb>  sColorTable;

        // only create our color table the first time
        if (sColorTable.isEmpty()) {
            sColorTable.resize(256);
            for (int i = 0; i < 256; ++i) {
                sColorTable[i] = qRgb(i, i, i);
            }
        }
        QImage image(inMat.data,
                     inMat.cols, inMat.rows,
                     static_cast<int>(inMat.step),
                     QImage::Format_Indexed8);
        image.setColorTable(sColorTable);
#endif
        return image;
    }

    default:
        qWarning() << "CVA::cvMatToQImage() - cv::Mat image type not handled in switch:" << inMat.type();
        break;
    }

    return QImage();
}

QPixmap cvMatToQPixmap(const cv::Mat &inMat) {
    return QPixmap::fromImage(cvMatToQImage(inMat));
}

cv::Mat QImageToCvMat(const QImage &inImage, bool inCloneImageData/* = true*/) {
    switch (inImage.format()) {
    // 8-bit, 4 channel
    case QImage::Format_ARGB32:
    case QImage::Format_ARGB32_Premultiplied: {
        cv::Mat mat(inImage.height(), inImage.width(),
                    CV_8UC4,
                    const_cast<uchar *>(inImage.bits()),
                    static_cast<size_t>(inImage.bytesPerLine()));

        return (inCloneImageData ? mat.clone() : mat);
    }

    // 8-bit, 3 channel
    case QImage::Format_RGB32:
    case QImage::Format_RGB888: {
        if (!inCloneImageData) {
            qWarning() << "CVA::QImageToCvMat() - Conversion requires cloning because we use a temporary QImage";
        }

        QImage swapped = inImage;

        if (inImage.format() == QImage::Format_RGB32) {
            swapped = swapped.convertToFormat(QImage::Format_RGB888);
        }

        swapped = swapped.rgbSwapped();

        return cv::Mat(swapped.height(), swapped.width(),
                       CV_8UC3,
                       const_cast<uchar *>(swapped.bits()),
                       static_cast<size_t>(swapped.bytesPerLine())).clone();
    }

    // 8-bit, 1 channel
    case QImage::Format_Indexed8: {
        cv::Mat mat(inImage.height(), inImage.width(),
                    CV_8UC1,
                    const_cast<uchar *>(inImage.bits()),
                    static_cast<size_t>(inImage.bytesPerLine()));

        return (inCloneImageData ? mat.clone() : mat);
    }

    default:
        qWarning() << "CVA::QImageToCvMat() - QImage format not handled in switch:" << inImage.format();
        break;
    }

    return cv::Mat();
}

cv::Mat QPixmapToCvMat(const QPixmap &inPixmap, bool inCloneImageData/* = true*/) {
    return QImageToCvMat(inPixmap.toImage(), inCloneImageData);
}

cv::Point matchTemplate(const cv::Mat &mSrc, const cv::Mat &mTemplate) {
    int cols = mSrc.cols - mTemplate.cols + 1;
    int rows = mSrc.rows - mTemplate.rows + 1;
    cv::Mat mResult;
    //qDebug() << cols << " " << rows << endl;
    mResult.create(cols, rows, CV_32FC1);
    int matchMethod = cv::TM_SQDIFF;
    cv::matchTemplate(mSrc, mTemplate, mResult, matchMethod);
    cv::normalize(mResult, mResult, 0, 1, cv::NORM_MINMAX, -1, cv::Mat());
    double minValue, maxValue;
    cv::Point minLocation, maxLocation, matchLocation;
    cv::minMaxLoc(mResult, &minValue, &maxValue, &minLocation, &maxLocation);
    if (matchMethod == cv::TM_SQDIFF || matchMethod == cv::TM_SQDIFF_NORMED) {
        matchLocation = minLocation;
    } else {
        matchLocation = maxLocation;
    }
    return matchLocation;
}

double getPSNR(const cv::Mat &M1, const cv::Mat &M2) {
    cv::Mat Diff;
    Diff.convertTo(Diff, CV_32FC3);
    cv::absdiff(M1, M2, Diff);
    Diff = Diff.mul(Diff);
    cv::Scalar S = cv::sum(Diff);
    double mse = (S.val[0] + S.val[1] + S.val[2]) / (3.0 * M1.rows * M1.cols);
    return 10.0 * log10(255 * 255 / (mse + 1e-8));
}

cv::Mat darken(const cv::Mat &mat) {
    cv::Mat _m = mat.clone();
    for (int i = 0; i < _m.rows; ++i) {
        uchar *data = _m.ptr<uchar>(i);
        for (int j = 0; j < _m.cols * 3; j += 3) {
            data[j] = int(0.3 * data[j]);
            data[j + 1] = int(0.3 * data[j + 1]);
            data[j + 2] = int(0.3 * data[j + 2]);
        }
    }
    return _m;
}

// helper function:
// finds a cosine of angle between vectors
// from pt0->pt1 and from pt0->pt2
double angle(cv::Point pt1, cv::Point pt2, cv::Point pt0) {
    double dx1 = pt1.x - pt0.x;
    double dy1 = pt1.y - pt0.y;
    double dx2 = pt2.x - pt0.x;
    double dy2 = pt2.y - pt0.y;
    return (dx1 * dx2 + dy1 * dy2) / sqrt((dx1 * dx1 + dy1 * dy1) * (dx2 * dx2 + dy2 * dy2) + 1e-10);
}

// returns sequence of squares detected on the image.
// the sequence is stored in the specified memory storage
void findSquares(const cv::Mat &image, std::vector<std::vector<cv::Point> > &squares) {
    int thresh = 50, N = 5;

    squares.clear();

    // blur will enhance edge detection
    cv::Mat timg(image);
    //cv::medianBlur(image, timg, 9);
    cv::Mat gray0(timg.size(), CV_8U), gray;

    std::vector<std::vector<cv::Point> > contours;

    // find squares in every color plane of the image
    for ( int c = 0; c < 3; c++ ) {
        int ch[] = {c, 0};
        cv::mixChannels(&timg, 1, &gray0, 1, ch, 1);

        // try several threshold levels
        for ( int l = 0; l < N; l++ ) {
            // hack: use Canny instead of zero threshold level.
            // Canny helps to catch squares with gradient shading
            if ( l == 0 ) {
                // apply Canny. Take the upper threshold from slider
                // and set the lower to 0 (which forces edges merging)
                cv::Canny(gray0, gray, 1, 5, 3, true);
                // dilate canny output to remove potential
                // holes between edge segments
                cv::dilate(gray, gray, cv::Mat(), cv::Point(-1, -1));
            } else {
                // apply threshold if l!=0:
                //     tgray(x,y) = gray(x,y) < (l+1)*255/N ? 255 : 0
                gray = gray0 >= (l + 1) * 255 / N;
            }

            // find contours and store them all as a list
            cv::findContours(gray, contours, cv::RETR_LIST, cv::CHAIN_APPROX_SIMPLE);

            std::vector<cv::Point> approx;

            // test each contour
            for ( size_t i = 0; i < contours.size(); i++ ) {
                // approximate contour with accuracy proportional
                // to the contour perimeter
                cv::approxPolyDP(cv::Mat(contours[i]), approx, arcLength(cv::Mat(contours[i]), true) * 0.02, true);

                // square contours should have 4 vertices after approximation
                // relatively large area (to filter out noisy contours)
                // and be convex.
                // Note: absolute value of an area is used because
                // area may be positive or negative - in accordance with the
                // contour orientation
                if ( approx.size() == 4 &&
                        fabs(cv::contourArea(cv::Mat(approx))) > 1000 &&
                        cv::isContourConvex(cv::Mat(approx)) ) {
                    double maxCosine = 0;

                    for ( int j = 2; j < 5; j++ ) {
                        // find the maximum cosine of the angle between joint edges
                        double cosine = fabs(angle(approx[j % 4], approx[j - 2], approx[j - 1]));
                        maxCosine = MAX(maxCosine, cosine);
                    }

                    // if cosines of all angles are small
                    // (all angles are ~90 degree) then write quandrange
                    // vertices to resultant sequence
                    if ( maxCosine < 0.3 )
                        squares.push_back(approx);
                }
            }
        }
    }
}


// the function draws all the squares in the image
void drawSquares( cv::Mat &image, const std::vector<std::vector<cv::Point> > &squares ) {
    for ( size_t i = 0; i < squares.size(); i++ ) {
        const cv::Point *p = &squares[i][0];

        int n = (int)squares[i].size();
        //dont detect the border
        if (p-> x > 3 && p->y > 3)
            cv::polylines(image, &p, &n, 1, true, cv::Scalar(0, 255, 0), 1, cv::LINE_AA);
    }

    cv::imshow("result", image);
}

void houghTest(const cv::Mat &src) {
    cv::Mat img(src);
    //cv::medianBlur(src, img, 5);
    cv::Mat dst, dst2, cdst;
    cv::cvtColor(img, dst, CV_BGR2GRAY);
    cv::Canny(dst, dst2, 1, 1, 3, true);
    cv::cvtColor(dst2, cdst, CV_GRAY2BGR);
    std::vector<cv::Vec4i> lines;
    cv::HoughLinesP(dst2, lines, 1, CV_PI / 180 * 90, 50, 50, 0);
    for (size_t i = 0; i < lines.size(); ++i) {
        cv::Vec4i I = lines[i];
        cv::line(cdst, cv::Point(I[0], I[1]), cv::Point(I[2], I[3]), cv::Scalar(0, 0, 255), 1, cv::LINE_AA);
    }

    cv::imshow("result", cdst);
}

}
