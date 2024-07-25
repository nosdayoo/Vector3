#include <iostream>

template <typename T>
class Vec3 {
public:
    T x, y, z;

    Vec3(T x, T y, T z) : x(x), y(y), z(z) {}

    bool operator==(const Vec3& other) const {
        return x == other.x && y == other.y && z == other.z;
    }
    //Add
    Vec3 add(const Vec3& other) const {
        return Vec3(x + other.x, y + other.y, z + other.z);
    }
    Vec3 add(const T& X, const T& Y, const T& Z) const {
        return Vec3(x + X, y + Y, z + Z);
    }
    //Sub
    Vec3 sub(const Vec3& other) const {
        return Vec3(x - other.x, y - other.y, z - other.z);
    }
    Vec3 sub(const T& X, const T& Y, const T& Z) const {
        return Vec3(x - X, y - Y, z - Z);
    }
    //Mul
    Vec3 mul(const Vec3& other) const {
        return Vec3(x * other.x, y * other.y, z * other.z);
    }
    Vec3 mul(const T& X, const T& Y, const T& Z) const {
        return Vec3(x * X, y * Y, z * Z);
    }
    //Div
    Vec3 div(const Vec3& other) const {
        return Vec3(x / other.x, y / other.y, z / other.z);
    }
    Vec3 div(const T& X, const T& Y, const T& Z) const {
        return Vec3(x / X, y / Y, z / Z);
    }
};
