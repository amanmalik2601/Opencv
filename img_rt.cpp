#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat rotation(Mat img,double angle)
{
    Mat fi;
    Point2f pt((img.cols)/2.0,(img.rows)/2.0);
    Mat rot=getRotationMatrix2D(pt,angle,1.0);
    Rect2f bbox=RotatedRect(Point2f(),img.size(),angle).boundingRect2f();
    rot.at<double>(0,2)+=bbox.width/2.0-img.cols/2.0;
    rot.at<double>(1,2)+=bbox.height/2.0-img.rows/2.0;
    warpAffine(img,fi,rot,bbox.size());
    return fi;
}
void image(int a){
    Mat img=imread("dog.jpg");

    if(img.empty())
        cout<<"ERROR!";
    else
    {
        Mat f=rotation(img,a);
        namedWindow("hey",WINDOW_NORMAL);
        resizeWindow("hey",400,300);
        imshow("hey",f);
        waitKey(0);
    }
    }

int main()
{
    double a;
    char choice;
    cout<<"Enter angle for rotation : ";
    cin>>a;
    cout<<"Enter"<<endl<<"a for Clockwise rotation "<<endl<<"b for Anti-clockwise rotation "<<endl;
    cin>>choice;

    if(choice=='a'||choice=='A')
      {
          a=-a;
          image(a);

      }

    else if(choice=='b'||choice=='B')
        {
          a=a;
          image(a);
        }

    else
        cout<<"Invalid choice"<<endl;

    return 0;
}
