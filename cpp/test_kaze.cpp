/**
 * @file test_kaze_features_port.cpp
 * @brief Main program for testing OpenCV KAZE port
 * @date May 24, 2014
 * @author Pablo F. Alcantarilla
 */

#include "./utils/utils.h"

// System
#include <string>
#include <vector>
#include <iostream>

using namespace std;
using namespace cv;

/* ************************************************************************* */
int main(int argc, char *argv[]) {

  if (argc != 2) {
    cerr << "Error introducing input arguments!" << endl;
    cerr << "The format needs to be: ./test_kaze_features_port img" << endl;
    return -1;
  }

  cv::Mat img;
  string imgFile = argv[1];

  // Open the input image
  img = imread(imgFile, 1);

  // Create KAZE object
  Ptr<Feature2D> dkaze = KAZE::create();

  // Timing information
  double t1 = 0.0, t2 = 0.0;
  double tkaze = 0.0;

  // Detect KAZE features in the input image
  vector<cv::KeyPoint> kpts;

  t1 = cv::getTickCount();
  dkaze->detect(img, kpts, cv::noArray());//, kpts);
  t2 = cv::getTickCount();
  tkaze = 1000.0*(t2-t1) / cv::getTickFrequency();

  cout << " ( x,  y )   response   angle  octave  size  " << endl;
//  for (vector<cv::KeyPoint>::iterator it = kpts.begin(); it!=kpts.end(); ++it) {
  for (int i=0; i<kpts.size(); i++) {
	cout << format("[%3d] (%4.1f %4.1f)  res=%f  a=%f  o=%f  s=%f\n", 
		i,
		kpts[i].pt.x, kpts[i].pt.y, 
		kpts[i].response, 
		kpts[i].angle, 
		kpts[i].octave, 
		kpts[i].size) ;
  }
  cout << " -------------------------------------- " << endl;

  Mat img_kpts1;
  drawKeypoints( img, kpts, img_kpts1, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS );
  imshow ("keypoints 1", img_kpts1);
  waitKey();


  draw_keypoints(img, kpts);

  // Show the detected KAZE features
  cv::imshow("KAZE", img);
  cv::waitKey(0);

  int nr_kpts = kpts.size();

  cout << "KAZE Results" << endl;
  cout << "********************" << endl;
  cout << "# Keypoints:    \t" << nr_kpts << endl;
  cout << "Time (ms):      \t" << tkaze << endl;
  cout << endl;

  return 0;
}
