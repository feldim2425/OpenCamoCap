# OpenCamoCap

OpenSource camera face capture/tracking software.

## Plans and Progress

The plan for this software is to track facial features using normal webcams.
In the future the software should also be able to track using depth cameras like the Microsoft Kinect, Intel Realsense or the Onion Tau (when it comes out).
Further plans may include hand and full body tracking.

The current plan is to support multiple protocols/tracking solutions like VMC and drop in replacments for OpenSeeFace and Apple ARKit. However actual support will highly depend on the challanges faced for a given implementation.

You can find the current progress on our [Trello Board](https://trello.com/b/5q2Pj84p/opencamocap).


## Why C++ and not XYZ?

While I would have liked doing it in another language, many frameworks don't support other languages or miss some features in other languages, a lot of porting/wrapping would be required to make this work. I have thought about using Rust, however it would also require wrapping C++ APIs and may slow down things more than it helps. 

MediaPipe for example does allow facetracking in Python but it won't allow iris tracking.
