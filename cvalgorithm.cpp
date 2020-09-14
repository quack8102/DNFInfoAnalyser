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

}
