#include <iostream>
#include <cmath>

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

    inline 	Vec3 floor() const {
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

    inline Vec3 normalize() const {
        T len = length();
        if (len != 0) {
            return Vec3(x / len, y / len, z / len);
        } else {
            return *this;
        }
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

    inline T dot(const Vec3& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    inline T dist(const Vec3& other) const {
        Vec3<T> diff = *this - other;
        return diff.length();
    }

    inline T dist2d(const Vec3& other) const {
        float dx = other.x - x, dy = other.y - y;
        return sqrtf(dx * dx + dy * dy);
    }
};

