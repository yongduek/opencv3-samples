//! [includes]
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <string>
//! [includes]

//! [namespace]
using namespace cv;
//! [namespace]

using namespace std;

int main( int argc, char** argv )
{
    //! [load]
    string imageName("../data/HappyFish.jpg"); // by default
    if( argc > 1)
    {
        imageName = argv[1];
    }
    //! [load]

    //! [mat]
    Mat image;
    //! [mat]

    //! [imread]
    image = cv::imread(imageName.c_str(), cv::IMREAD_COLOR); // Read the file
    //! [imread]

    if( image.empty() )                      // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    //! [window]
//    namedWindow( "Display window", cv::WINDOW_AUTOSIZE ); // Create a window for display.
    cv::namedWindow( "Display window", cv::WINDOW_NORMAL ); // Create a window for display.
    //! [window]

    //! [imshow]
    cv::imshow( "Display window", image );                // Show our image inside it.
    //! [imshow]

    //! [wait]
    cv::waitKey(0); // Wait for a keystroke in the window
    //! [wait]
    return 0;
}
