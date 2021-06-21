
//直接獲取mat對象像素數據指針，基於指針操作，實現快速像素方法
void method_3(Mat &image) {
    double t1 = getTickCount();
    int w = image.cols;
    int h = image.rows;
    for (int row = 0; row < h; row++) {
        uchar* uc_pixel = image.data + row*image.step;
        for (int col = 0; col < w; col++) {
            uc_pixel[0] = 255 - uc_pixel[0];
            uc_pixel[1] = 255 - uc_pixel[1];
            uc_pixel[2] = 255 - uc_pixel[2];
            uc_pixel += 3;
        }
    }
    double t2 = getTickCount();
    double t = ((t2 - t1) / getTickFrequency()) * 1000;
    ostringstream ss;
    ss << "Execute time : " << std::fixed << std::setprecision(2) << t << " ms ";
    putText(image, ss.str(), Point(20, 20), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0, 0, 255), 2, 8);
    imshow("result", image);
}
