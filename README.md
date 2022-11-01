# FaceDetection

The purpose of this project is
to use the Cascade Classifier proposed by Paul Viola and Michael Jones 
in [Rapid Object Detection using a Boosted Cascade of Simple
Features](https://www.cs.cmu.edu/~efros/courses/LBMV07/Papers/viola-cvpr-01.pdf)
to detect a face on a video stream or a photo.


<img src="https://i.imgur.com/ET1PioV.png" alt="image" width="50%" margin-left="auto" margin-right="auto" display="block"/>

# Setup
Please, clone the repository, download the classifiers and compile the project.

```
git clone git@github.com:bryanpiguave/FaceDetection.git

curl https://raw.githubusercontent.com/opencv/opencv/master/data/haarcascades/haarcascade_frontalface_default.xml -o frontalface.xmls

curl https://raw.githubusercontent.com/opencv/opencv/master/data/haarcascades/haarcascade_eye_tree_eyeglasses.xml -o eyedetector.xml

cmake CMakeLists.txt
make 
```


# Inference 
You can add the path of your image or you can skip this to get inference on a webcam.
```
    ./FaceDetection path/of/your/image.jpg
```

# Author 
Bryan Piguave