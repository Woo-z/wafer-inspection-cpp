#include <iostream>
#include <opencv2/opencv.hpp>


int main() {
  // 1. 이미지 읽기 (상대 경로 주의: build 폴더 위치에 따라 ../data 로 접근해야 할 수도 있음)
  //  일단 절대 경로로 테스트해보는 게 제일 확실함. (경로 수정 필요!)
  std::string imagePath =
      "C:/Users/Woo/Desktop/C++Project/wafer-inspection-cpp/data/wafer_01.jpg";

  cv::Mat img = cv::imread(imagePath);

  // 2. 예외 처리
  if (img.empty()) {
    std::cerr << "Error: Image not found at " << imagePath << std::endl;
    return -1;
  }

  // 3. 윈도우 창 띄우기
  cv::namedWindow("Wafer Viewer", cv::WINDOW_AUTOSIZE);
  cv::imshow("Wafer Viewer", img);

  std::cout << "Success: Image Loaded (" << img.cols << "x" << img.rows << ")"
            << std::endl;

  // 4. 키 입력 대기 (아무 키나 누르면 종료)
  cv::waitKey(0);
  return 0;
}
