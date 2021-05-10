#pragma once

#include "opencv2/core.hpp"

#include "common/Common.hpp"

CAMOCAP_NAMESPACE_BEGIN

class IFrame {
    public:
        virtual void get2DImage(cv::Mat& image);
        virtual uint64_t get2DFormat();

        virtual bool hasDepthData();
        virtual void getDepthData(cv::Mat& depth);
        virtual uint64_t getDepthFormat();
};

class IFrameInputStream {
    public:

        virtual bool readNextFrame(IFrame &frame);
        virtual void awaitNextFrame();
        virtual bool hasFrame();


        virtual bool isOpen();
        virtual void close();

        operator bool() { return isOpen(); }

};




CAMOCAP_NAMESPACE_END