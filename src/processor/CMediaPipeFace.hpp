#pragma once

#include <cstdlib>
#include <memory>
#include <string>

#include "mediapipe/framework/calculator_framework.h"

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include "common/Common.hpp"

CAMOCAP_NAMESPACE_BEGIN

/**
 * Mediapipe face mesh tracking.
 * Uses Mediapipes face mesh and iris tracking
 */
class CMediaPipeFace {
    public:
        /**
         * Constructs a new CMediaPipeFace
         */ 
        CMediaPipeFace();
        virtual ~CMediaPipeFace(){}

        bool isOk();

        /**
         * Runs the detection algorithm on the current frame
         */
        //TODO: Need to abstract this call somehow. This supports only one framestream per algorithm.
        //Other Camera+Algortihm combinations may exchange multiple frames (stereoscopic, depth, IR, ...)
        void runDetection(cv::Mat image);
    
    private:
        
        /**
         * Sets up the graph for mediapipe
         */
        void m_setupGraph();

        /**
         * Unique Pointer to the calculator graph
         */
        std::unique_ptr<mediapipe::CalculatorGraph> m_facegraph;

        std::unique_ptr<mediapipe::OutputStreamPoller> m_poller;
};

CAMOCAP_NAMESPACE_END
