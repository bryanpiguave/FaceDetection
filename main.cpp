#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <opencv2/objdetect.hpp>



int main(int argc, char **argv){
    cv::Mat img;
    cv::VideoCapture cap(0);

    cv::CascadeClassifier faceCascade;
    faceCascade.load("frontalface.xml");
    

    if (faceCascade.empty()){
        std::cout << "file not headed" << std::endl;
    }
    while (true){
        cap.read(img);

        std::vector<cv::Rect> faces;
        faceCascade.detectMultiScale(img,faces,1.1,10);
        for(int i=0;i<faces.size();i++){
            cv::rectangle(img,faces[i].tl(),faces[i].br(),cv::Scalar(255,0,255),4);
        }
        cv::imshow("Detection",img);
        cv::waitKey(1);
    }
    return 0;
}