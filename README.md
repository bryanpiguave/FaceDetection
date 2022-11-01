# FaceDetection

The purpose of this project is
to use traditional computer vision methods
to detect a face on a video stream or a photo

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