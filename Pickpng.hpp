//
//  Pickpng.hpp
//  opencv
//
//  Created by Jiyang Wang on 2018/1/8.
//  Copyright © 2018年 Jiyang Wang. All rights reserved.
//

#ifndef Pickpng_hpp
#define Pickpng_hpp

#include <iostream>
#include <fstream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.hpp>
#include <opencv2/core/core.hpp>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <list>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;
using namespace cv;

void CaptureFrames();
void CaptureAndGray();
void Delay(int milinseconds);

#endif /* Pickpng_hpp */
