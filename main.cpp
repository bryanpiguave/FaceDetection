#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <opencv2/objdetect.hpp>
#include <sys/stat.h>


inline bool exists_file (const std::string& name) {
        /// Checks if the file exists given a path ///
        struct stat buffer;   
        return (stat (name.c_str(), &buffer) == 0); 
        }

int main(int argc, char **argv){
    cv::Mat img;
    bool exists;
    cv::CascadeClassifier faceCascade;
    faceCascade.load("frontalface.xml");
    

    if (faceCascade.empty()){
        std::cout << "file not headed" << std::endl;
        return -1;
    }
    if (argc==2){
        std::string path = argv[1];
        /// Checking if file exists 
        exists = exists_file(path);
        if (!exists){
            std::cout<< "The file is empty" << std::endl;
            return -1;
        }

        img = cv::imread(path);
        std::vector<cv::Rect> faces;
        faceCascade.detectMultiScale(img,faces,1.1,10);
        for(int i=0;i<faces.size();i++){
            cv::rectangle(img,faces[i].tl(),faces[i].br(),cv::Scalar(255,0,255),4);
        }
        cv::resize(img,img,cv::Size(), 0.5, 0.5);
        cv::imshow("Detection",img);
        cv::waitKey(0);
    }
    else{
        cv::VideoCapture cap(0);
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
    }
    
    return 0;
}