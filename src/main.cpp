#include <iostream>

#include "common/Common.hpp"
#include "processor/CMediaPipeFace.hpp"

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"

#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

int main(int argc, char* argv[]) {

    bool running = true;
    cv::Mat frame, frame_mod;

    google::InitGoogleLogging(argv[0]);
    absl::ParseCommandLine(argc, argv);

    cv::VideoCapture capture {1};
    CAMOCAP_NAMESPACE::CMediaPipeFace mediapipe;

    if(!mediapipe.isOk()){
        std::cout << "Mediapipe not ok!" << std::endl;
        return 0;
    }

    if(!capture.isOpened()){
        std::cout << "Capture not open!" << std::endl;
        return 0;
    }
    std::cout << "Capture open!" << std::endl;

    while(running) {
        capture >> frame;
        cv::cvtColor(frame, frame_mod, cv::COLOR_BGR2RGB);

        mediapipe.runDetection(frame_mod);

        int pressed_key = cv::waitKey(5);
        
        if (pressed_key >= 0 && pressed_key != 255){
            running = false;
            std::cout << "Quit" << std::endl;
        }
    }


    return 0;
}