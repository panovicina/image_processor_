#pragma once

#include <climits>
#include <exception>
#include <fstream>
#include <iostream>
#include <string>

// 24 bit rgb cell
struct RGBTriple {
    uint8_t b{0};
    uint8_t g{0};
    uint8_t r{0};

    void SetColors(int32_t r, int32_t g, int32_t b) {
        this->r = static_cast<uint8_t>(std::min(UCHAR_MAX, std::max(0, r)));
        this->g = static_cast<uint8_t>(std::min(UCHAR_MAX, std::max(0, g)));
        this->b = static_cast<uint8_t>(std::min(UCHAR_MAX, std::max(0, b)));
    }

    friend std::ostream& operator<<(std::ostream& stream, const RGBTriple& pix) {
        stream << int(pix.r) << ' ' << int(pix.g) << ' ' << int(pix.b);
        return stream;
    }
};

inline bool SafeRead(char* buffer, std::streamsize count, std::ifstream& ifs) {
    return ifs.read(buffer, count) && ifs.gcount() == count;
}

template <typename T>
inline bool SafeRead(T* buffer, std::ifstream& ifs) {
    return SafeRead(reinterpret_cast<char*>(buffer), sizeof(T), ifs);
}

template <typename T>
inline void SafeWrite(T* buffer, std::ofstream& ifs) {
    ifs.write(reinterpret_cast<char*>(buffer), sizeof(T));
}

inline bool SafeStoll(const std::string& str, size_t& to) {
    int64_t target = 0;
    try {
        target = std::stoll(str);
    } catch (std::exception& e) {
        return false;
    }

    if (target < 0) {
        return false;
    }

    to = target;
    return true;
}