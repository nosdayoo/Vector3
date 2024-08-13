#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

template <typename T>
class Vec3 {
public:
    T x, y, z;

    Vec3(T x, T y, T z) : x(x), y(y), z(z) {}

    inline bool operator==(const Vec3& other) const {
        return x == other.x && y == other.y && z == other.z;
    }
    inline Vec3 operator+(const Vec3& other) const {
        return Vec3(x + other.x, y + other.y, z + other.z);
    }
    inline Vec3 operator+(const T& other) const {
        if (other == 0) return *this;
        return Vec3(x + other, y + other, z + other);
    }

    inline Vec3 operator-(const Vec3& other) const {
        return Vec3(x - other.x, y - other.y, z - other.z);
    }
    inline Vec3 operator-(const T& other) const {
        if (other == 0) return *this;
        return Vec3(x - other, y - other, z - other);
    }

    inline Vec3 operator*(const Vec3& other) const {
        if (other.x == 0 || other.y == 0 || other.z == 0) return *this;
        return Vec3(x * other.x, y * other.y, z * other.z);
    }
    inline Vec3 operator*(const T& other) const {
        if (other == 0) return *this;
        return Vec3(x * other, y * other, z * other);
    }

    inline Vec3 operator/(const Vec3& other) const {
        if (other.x == 0 || other.y == 0 || other.z == 0) return *this;
        return Vec3(x / other.x, y / other.y, z / other.z);
    }
    inline Vec3 operator/(const T& other) const {
        if (other == 0) return *this;
        return Vec3(x / other, y / other, z / other);
    }


    //Add
    inline Vec3 add(const Vec3& other) const {
        return Vec3(x + other.x, y + other.y, z + other.z);
    }
    inline Vec3 add(const T& X, const T& Y, const T& Z) const {
        return Vec3(x + X, y + Y, z + Z);
    }
    //Sub
    inline Vec3 sub(const Vec3& other) const {
        return Vec3(x - other.x, y - other.y, z - other.z);
    }
    inline Vec3 sub(const T& X, const T& Y, const T& Z) const {
        return Vec3(x - X, y - Y, z - Z);
    }
    //Mul
    inline Vec3 mul(const Vec3& other) const {
        return Vec3(x * other.x, y * other.y, z * other.z);
    }
    inline Vec3 mul(const T& X, const T& Y, const T& Z) const {
        return Vec3(x * X, y * Y, z * Z);
    }
    //Div
    inline Vec3 div(const Vec3& other) const {
        return Vec3(x / other.x, y / other.y, z / other.z);
    }
    inline Vec3 div(const T& X, const T& Y, const T& Z) const {
        return Vec3(x / X, y / Y, z / Z);
    }

    inline Vec3 floor() const {
        return Vec3(floorf(x), floorf(y), floorf(z));
    };

    inline Vec3 below(const T& down) const {
        return Vec3(x, y - down, z);
    }

    inline Vec3 above(const T& up) const {
        return Vec3(x, y + up, z);
    }

    inline Vec3 cross(const Vec3& other) const {
        return Vec3<T>(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
    }

    inline Vec3 lerp(const Vec3& end, float t) const {
        return (*this) * (1.0f - t) + end * t;
    }
    
    inline Vec3 scale(const T& other) const {
        return Vec3(x * other, y * other, z * other);
    }

    inline Vec3 lerpVectors(const Vec3& b, const T& t) const {
        return (*this) + (b - (*this)) * t;
    }

    inline Vec3 rotateX(float angle) const {
        float s = sin(angle);
        float c = cos(angle);
        return Vec3(x, y * c - z * s, y * s + z * c);
    }

    inline Vec3 rotateY(float angle) const {
        float s = sin(angle);
        float c = cos(angle);
        return Vec3(x * c + z * s, y, -x * s + z * c);
    }

    inline Vec3 rotateZ(float angle) const {
        float s = sin(angle);
        float c = cos(angle);
        return Vec3(x * c - y * s, x * s + y * c, z);
    }

    inline Vec3 clamp(const T& minVal, const T& maxVal) const {
        return Vec3(
            std::clamp(x, minVal, maxVal),
            std::clamp(y, minVal, maxVal),
            std::clamp(z, minVal, maxVal)
        );
    }
    
    inline Vec3 sign() const {
        return Vec3(
            (T)((x > 0) - (x < 0)),
            (T)((y > 0) - (y < 0)),
            (T)((z > 0) - (z < 0))
        );
    }

    inline Vec3 reflect(const Vec3& normal) const {
        return *this - normal * (2.0f * this->dot(normal));
    }
    
    inline Vec3 abs() const {
        return Vec3(std::abs(x), std::abs(y), std::abs(z));
    }
    
    inline Vec3 min(const Vec3& other) const {
        return Vec3(std::min(x, other.x), std::min(y, other.y), std::min(z, other.z));
    }

    inline Vec3 max(const Vec3& other) const {
        return Vec3(std::max(x, other.x), std::max(y, other.y), std::max(z, other.z));
    }

    inline Vec3 negate() const {
        return Vec3(-x, -y, -z);
    }

    inline bool isNaN() const {
        return std::isnan(x) || std::isnan(y) || std::isnan(z);
    }

    static Vec3 random(T minVal, T maxVal) {
        T range = maxVal - minVal;
        return Vec3(
            minVal + static_cast<T>(rand()) / static_cast<T>(RAND_MAX) * range,
            minVal + static_cast<T>(rand()) / static_cast<T>(RAND_MAX) * range,
            minVal + static_cast<T>(rand()) / static_cast<T>(RAND_MAX) * range
        );
    }

    inline Vec3 sqrt() const {
        return Vec3(std::sqrt(x), std::sqrt(y), std::sqrt(z));
    }

    inline Vec3 center(const Vec3& other) const {
        return Vec3((x + other.x) / 2, (y + other.y) / 2, (z + other.z) / 2);
    }
    
    inline Vec3 round() const {
        return Vec3(std::round(x), std::round(y), std::round(z));
    }

    inline Vec3 normalize() const {
        T len = length();
        if (len != 0) {
            return Vec3(x / len, y / len, z / len);
        } else {
            return *this;
        }
    }

    inline Vec3 zero() {
        return Vec3(0, 0, 0);
    }

    inline bool iszero() const { 
        return (x == 0 && y == 0 && z == 0);
    }

    inline void set(const Vec3& other) {
        x = other.x;
        y = other.y;
        z = other.z;
    }

    inline T squaredlength() const {
        return x * x + y * y + z * z;
    }

    inline T length() const {
        return std::sqrt(squaredLength());
    }

    inline T sum() const {
        return x + y + z;
    }

    inline T dot(const Vec3& other) const {
        return x * other.x + y * other.y + z * other.z;
    }
    
    inline float angle2d() const {
        return atan2(y, x);
    }

    inline T dist(const Vec3& other) const {
        Vec3<T> diff = *this - other;
        return diff.length();
    }

    inline T dist2d(const Vec3& other) const {
        float dx = other.x - x, dy = other.y - y;
        return sqrtf(dx * dx + dy * dy);
    }

    inline std::string tostring() {
        return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z);
    }
};

