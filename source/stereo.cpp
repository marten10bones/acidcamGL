#include"stereo.h"


void acidcam::Stereo(cv::Mat &frame, cv::Mat &img1, cv::Mat &img2) {
cv::Mat frame1 = img1;
cv::Mat frame2 = img2;
cv::resize(frame1, img1, cv::Size(frame.cols/2, frame.rows));
cv::resize(frame2, img2, cv::Size(frame.cols/2, frame.rows));

for(int z = 0; z < frame.rows; ++z) {
    int x = 0;
    for(int i = frame.cols/2; i < frame.cols; ++i) {
            cv::Vec3b &pixel = frame.at<cv::Vec3b>(z, i);
            cv::Vec3b pix = img1.at<cv::Vec3b>(z, x);
            ++x;
            pixel = pix;
        }
        for(int i = 0; i < frame.cols/2; ++i) {
            cv::Vec3b &pixel = frame.at<cv::Vec3b>(z, i);
            cv::Vec3b pix = img2.at<cv::Vec3b>(z, i);
            pixel = pix;
        }
    }
}



acidcam::StereoCam::StereoCam() {
    
}
void acidcam::StereoCam::Load(int *cmd) {
    for(int i = 0; i < 2; ++i) {
        cap[i] = cv::VideoCapture(cmd[i]);
        if(!cap[i].isOpened()) {
            std::cout << "acidcam: couldn't open device: " << cmd[i] << "\n";
            exit(0);
        }
    }
}

void acidcam::StereoCam::Render(cv::Mat &frame) {
    cv::Mat img1, img2;
    cap[0].read(img1);
    cap[1].read(img2);
    Stereo(frame, img1, img2);
}

void acidcam::StereoCam::SetSize(int w, int h) {
    for(int i = 0; i < 2; ++i) {
        cap[i].set(cv::CAP_PROP_FRAME_WIDTH, w);
        cap[i].set(cv::CAP_PROP_FRAME_WIDTH, h);
    }
}

