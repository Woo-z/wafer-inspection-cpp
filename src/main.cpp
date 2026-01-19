#include "../include/ImageLoader.h"
#include <iostream>

// 메모리 누수 감지 (Windows 전용)
#ifdef _WIN32
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>

#endif

int main() {
#ifdef _WIN32
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

  std::cout << "=== Wafer Inspection Engine Start ===" << std::endl;

  {
    // Scope를 만들어서 강제로 소멸자 호출 테스트
    ImageLoader loader;
    if (loader.load("data/wafer_001.jpg")) {
      std::cout << "Image Memory Address: " << (void *)loader.getData()
                << std::endl;
    }
  }
  // 여기서 "~ImageLoader" 로그가 찍혀야 함

  std::cout << "=== Engine Shutdown ===" << std::endl;
  return 0;
}
