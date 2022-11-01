# FaceDetection

The purpose of this project is
to use the Cascade Classifier proposed by Paul Viola and Michael Jones 
in [Rapid Object Detection using a Boosted Cascade of Simple
Features](https://www.cs.cmu.edu/~efros/courses/LBMV07/Papers/viola-cvpr-01.pdf)
to detect a face on a video stream or a photo


<img src="https://i.imgur.com/iUQSLm2.png" alt="image" width="50%" margin-left="auto" margin-right="auto" display="block"/>

# Setup

Download the classifier 

```
curl https://raw.githubusercontent.com/opencv/opencv/master/data/haarcascades/haarcascade_frontalface_default.xml -o frontalface.xml
```
# Prepare built and compile 

```
cmake .
make 
```

# Inference 

```
    ./FaceDetection
```

# Author 
Bryan Piguave