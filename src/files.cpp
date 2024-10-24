#include "files.hpp"

#ifdef __WIN32__
#include <windows.h>
#endif // __WIN32__

#include <cstdio>
#include <filesystem>
#include <string>
#include <vector>

#ifdef __linux__
#include <fstream>
#include <sstream>
#include <ios>
#endif // __linux__

namespace Files {

  std::filesystem::path binPath() {
#ifdef __WIN32__
    wchar_t path[MAX_PATH];
    GetModuleFileNameW(nullptr, path, MAX_PATH);

    return { path };
#elif __linux__
    return std::filesystem::canonical("/proc/self/exe");
#endif // __WIN32__
  }

  std::filesystem::path binDir() {
    return binPath().parent_path();
  }

  std::filesystem::path dataDir() {
      return binDir() / "data/";
  }

  std::filesystem::path shadersDir() {
	return dataDir()/"shaders/";
  }

  std::string readFile(std::filesystem::path path) {
#ifdef __WIN32__
      FILE* f;
      errno_t err = _wfopen_s(&f, path.wstring().c_str(), L"r");
      if (err != 0) {
          // Handle error
          return "";
      }
      std::string content { "" };
      char tmpChar;

      while ((tmpChar = fgetc(f)) != EOF)
          content += tmpChar;

      fclose(f);
      return content;
#else
      std::ifstream ifs(path);
      std::stringstream ss;

      ss << ifs.rdbuf();
      ifs.close();

      return ss.str();
#endif // __WIN32__
  }


  std::string readDataFile(std::filesystem::path path) {
    return readFile(dataDir()/path);
  }

  std::vector<unsigned char> readBinaryFile(std::filesystem::path path) {
      FILE* f;
#ifdef __WIN32__
      errno_t err = _wfopen_s(&f, path.wstring().c_str(), L"rb");
      if (err != 0) {
          // Handle error
          return {};
  }
#else
      f = fopen(path.c_str(), "rb");
      if (f == nullptr) {
          // Handle error
          return {};
      }
#endif // __WIN32__
      std::vector<unsigned char> content {};
      int tmpChar;

      while ((tmpChar = fgetc(f)) != EOF)
          content.push_back((unsigned char)tmpChar);

      fclose(f);
      return content;
}


} // namespace Files
