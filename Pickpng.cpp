//
//  Pickpng.cpp
//  opencv
//
//  Created by Jiyang Wang on 2018/1/8.
//  Copyright © 2018年 Jiyang Wang. All rights reserved.
//

#include "Pickpng.hpp"


void CaptureFrames(){
    //set the ascii vector
    ofstream fout;
    fout.open("path to txt file",ios::trunc);//path to txt file
    vector<string> vec_ascii;
    string ascii;
    string ascii_string("$ @ B % 8 & W M # Z O 0 Q L C J U Y X * o a h k b d p q w m z c v u n x r j f t / \\ | ( ) 1 { } [ ] ? - _ + ~ < > i ! l I ; : , \" ^ ` ' .");//
    istringstream iss(ascii_string);
    while (iss >> ascii) {
        vec_ascii.push_back(ascii);
    }
    vec_ascii.push_back(" ");
    
    int length = static_cast<int>(vec_ascii.size());
    
    VideoCapture *cap = new VideoCapture("path to mp4 film");//path to mp4 film
    //Mat Lastframe;
    long count = 0;
    while(++count <= 4340){//4340 means all the film //24fps 3min37s
        //set the property
        cap->set(CV_CAP_PROP_POS_MSEC, count * 50);
        Mat frame;
        //capture the frame
        cap->read(frame);
        if (frame.empty()) {
            break;
        }
        int rows = frame.rows;
        int cols = frame.cols;
        for (int i = 0; i < rows; i++) {
            Vec3b *p = frame.ptr<Vec3b>(i);
            for (int j = 0; j < cols; j++) {
                Vec3b &pix = *p++;
                uchar pix2;
                pix2 = pix[0] * 0.114 + pix[1] * 0.587 + pix[2] * 0.299;
                fout<<vec_ascii[69 - static_cast<int>(pix2)*length/256];//change the outstream and add a delay can cout directly but
            }                                                      //will cost lots of resources, have a bad delay.
            fout<<endl;
        }
        fout<<"end"<<endl;//end is a flag for the end of a frame
    }
    fout.close();
}

void Delay(int milinseconds)
{
    clock_t start = clock();
    clock_t lay = ((clock_t)milinseconds * 1000);//ms
    while ((clock()-start) < lay);
}
