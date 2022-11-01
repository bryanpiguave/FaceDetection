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

int main(int argc, const char **argv){
    cv::CommandLineParser parser(argc,argv,"{help h||}"
                                "{img_path||}");

    parser.about( "\nThis program demonstrates using the cv::CascadeClassifier class to detect objects (Face + eyes) in a video stream.\n");
    parser.printMessage();
    cv::Mat img;
    bool exists;
    cv::CascadeClassifier faceCascade,eyesCascade;
    faceCascade.load("frontalface.xml");
    eyesCascade.load("eyedetector.xml");
       

    if (faceCascade.empty()){
        std::cout << "Error, face detector model not found" << std::endl;
        return -1;
    }
    if (eyesCascade.empty()){
        std::cout <<"Error, eye detector model not found" << std::endl;
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
            cv::rectangle(img,faces[i].tl(),faces[i].br(),cv::Scalar(255,0,0),3);
            cv::Mat faceROI = img(faces[i]);
        
            //-- In each face, detect eyes
            std::vector<cv::Rect> eyes;
            eyesCascade.detectMultiScale( faceROI, eyes );
            for ( size_t j = 0; j < eyes.size(); j++ )
            {
                cv::Point eye_center( faces[i].x + eyes[j].x + eyes[j].width/2, faces[i].y + eyes[j].y + eyes[j].height/2 );
                int radius = cvRound( (eyes[j].width + eyes[j].height)*0.15 );
                circle( img, eye_center, radius, cv::Scalar( 255, 0, 0 ), 2 );            }
        }
        cv::imshow("Detection",img);
        cv::waitKey(1);
        }
    }
    
    return 0;
}