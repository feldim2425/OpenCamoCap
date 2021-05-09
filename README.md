# OpenCamoCap

OpenSource camera face capture/tracking software.


## Why C++ and not XYZ?

While I would have liked doing it in another language, many frameworks don't support other languages or miss some features in other languages, a lot of porting/wrapping would be required to make this work. I have thought about using Rust, however it would also require wrapping C++ APIs and may slow down things more than it helps. 

MediaPipe for example does allow facetracking in Python but it won't allow iris tracking.
