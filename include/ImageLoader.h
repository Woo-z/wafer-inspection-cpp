#pragma once
#include <iostream>
#include <string>
#include <vector>

class ImageLoader {
public:
  ImageLoader();
  ~ImageLoader(); // 소멸자에서 메모리 해제

  // 복사 방지 (댕글링 포인터 방지)
  ImageLoader(const ImageLoader &) = delete;
  ImageLoader &operator=(const ImageLoader &) = delete;

  // 이동 허용 (std::vector에 넣으려면 필수)
  ImageLoader(ImageLoader &&other) noexcept;
  ImageLoader &operator=(ImageLoader &&other) noexcept;

  bool load(const std::string &filepath);

  // 데이터 접근자 (Read-Only)
  const unsigned char *getData() const { return m_data; }
  int getWidth() const { return m_width; }
  int getHeight() const { return m_height; }
  int getChannels() const { return m_channels; }

private:
  unsigned char *m_data = nullptr; // Raw Data Pointer
  int m_width = 0;
  int m_height = 0;
  int m_channels = 0;

  void release(); // 메모리 해제
};
