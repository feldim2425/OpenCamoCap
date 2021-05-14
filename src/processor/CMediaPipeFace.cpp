#include "CMediaPipeFace.hpp"

#include <iostream>
#include <fstream>

#include "mediapipe/framework/port/parse_text_proto.h"
#include "mediapipe/framework/formats/image_frame.h"
#include "mediapipe/framework/formats/image_frame_opencv.h"

#include "absl/status/status.h"

CAMOCAP_NAMESPACE_BEGIN

//TODO: Temporary Path for development. Move to permanent location (maybe modifyable with cli arguments)
//static const std::string MEDIAPIPE_GRAPH_PATH = "bazel-bin/external/com_google_mediapipe/mediapipe/graphs/face_mesh/subgraphs/face_renderer_cpu.binarypb";
static const std::string MEDIAPIPE_GRAPH_PATH = "graphs/face_mesh/face_mesh_desktop_live.pbtxt";

constexpr char kInputStream[] = "input_video";
constexpr char kOutputStream[] = "output_video";

CMediaPipeFace::CMediaPipeFace() {
    this -> m_setupGraph();
}

void CMediaPipeFace::m_setupGraph() {
    std::ifstream inputFile{ MEDIAPIPE_GRAPH_PATH };

    if(inputFile) {
        //TODO: Implement Glog or other logging system
        std::cout << "Alright" << std::endl;
    }
    else {
         std::cout << "File not found" << std::endl;
         return;
    }
    
    std::string content(std::istreambuf_iterator<char>(inputFile), {});

    mediapipe::CalculatorGraphConfig config =
      mediapipe::ParseTextProtoOrDie<mediapipe::CalculatorGraphConfig>(
          content);
    //bool parsed = config.ParseFromIstream(&inputFile);
    /*if(parsed){
        std::cout << "Alright" << std::endl;
    }
    else {
        std::cout << "Parse Error" << std::endl;
        return;
    }*/

    this -> m_facegraph = std::make_unique<mediapipe::CalculatorGraph>();
    absl::Status status = this -> m_facegraph -> Initialize(config);
    if(status.ok()){
        std::cout << "Alright" << std::endl;
    }
    else {
        std::cout << status.ToString() << std::endl;
        return;
    }


    {
        mediapipe::StatusOrPoller storpoll = this -> m_facegraph -> AddOutputStreamPoller(kOutputStream);
        if(!storpoll.ok()) {
            std::cout << "ERROR: " << status.message() << std::endl;
            return;
        }

        this -> m_poller = std::make_unique<mediapipe::OutputStreamPoller>(std::move(storpoll).value());
    }
    
    status = this -> m_facegraph -> StartRun({});

    if(status.ok()){
        std::cout << "Alright" << std::endl;
    }
    else {
        std::cout << status.ToString() << std::endl;
        return;
    }
}

bool CMediaPipeFace::isOk() {
    return this->m_facegraph && this->m_poller;
}

void CMediaPipeFace::runDetection(cv::Mat image) {
    auto input_frame = absl::make_unique<mediapipe::ImageFrame>(
        mediapipe::ImageFormat::SRGB, image.cols, image.rows,
        mediapipe::ImageFrame::kDefaultAlignmentBoundary);

    size_t frame_timestamp_us =
        (double)cv::getTickCount() / (double)cv::getTickFrequency() * 1e6;
    this -> m_facegraph -> AddPacketToInputStream(
        kInputStream, mediapipe::Adopt(input_frame.release()).At(mediapipe::Timestamp(frame_timestamp_us)));

    mediapipe::Packet packet;
    
    if (!this -> m_poller -> Next(&packet)) {
        std::cout << "Fail" << std::endl;
        return;
    }
    std::cout << "HELLO" << std::endl;
    auto& output_frame = packet.Get<mediapipe::ImageFrame>();

    cv::Mat output_frame_mat = mediapipe::formats::MatView(&output_frame);
    cv::cvtColor(output_frame_mat, output_frame_mat, cv::COLOR_RGB2BGR);
    cv::imshow("Hello", output_frame_mat);
}

CAMOCAP_NAMESPACE_END