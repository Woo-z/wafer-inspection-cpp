#include "../include/ImageLoader.h"
#include <opencv2/opencv.hpp> // 이미지 디코딩용으로만 사용 (데이터 카피 후 해제할 것)

ImageLoader::ImageLoader() {}

ImageLoader::~ImageLoader() {
    release();
    std::cout << "[ImageLoader] Resource Released" << std::endl;
}

ImageLoader::ImageLoader(ImageLoader&& other) noexcept {
    m_data = other.m_data;
    m_width = other.m_width;
    m_height = other.m_height;
    m_channels = other.m_channels;

    other.m_data = nullptr; // 원본 초기화 (소유권 이전)
    other.m_width = 0;
    other.m_height = 0;
    other.m_channels = 0;
}

void ImageLoader::release() {
    if (m_data) {
        delete[] m_data; // 할당 방식에 맞춰 해제 (new[] -> delete[])
        m_data = nullptr;
    }
}

bool ImageLoader::load(const std::string& filepath) {
    // 1. OpenCV로 일단 로드 (디코딩 목적)
    cv::Mat temp = cv::imread(filepath, cv::IMREAD_GRAYSCALE);
    if (temp.empty()) {
        std::cerr << "Failed to open image: " << filepath << std::endl;
        return false;
    }

    // 2. 기존 메모리 정리
    release();

    // 3. 메타데이터 설정
    m_width = temp.cols;
    m_height = temp.rows;
    m_channels = temp.channels();

    // 4. Deep Copy (cv::Mat의 스마트 포인터 관리에서 벗어나 내 힙 메모리로 가져옴)
    size_t dataSize = m_width * m_height * m_channels;
    m_data = new unsigned char[dataSize]; 
    memcpy(m_data, temp.data, dataSize);

    // temp는 함수 끝나면 알아서 소멸됨 (OpenCV가 관리)
    // 이제 m_data는 내가 관리함 (RAII)
    
    std::cout << "Loaded: " << filepath << " (" << m_width << "x" << m_height << ")" << std::endl;
    return true;
}
