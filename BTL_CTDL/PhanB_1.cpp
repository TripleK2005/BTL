#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <algorithm>
using namespace std;

// Lớp Vector tự xây dựng
template <typename T>
class Vector {
private:
    T* data;           // Con trỏ đến vùng nhớ chứa các phần tử
    // size_t kieu du lieu ko dau , bieu dien kich thuoc or so luong vung nho
    size_t vec_size;   // Số lượng phần tử hiện tại
    size_t vec_capacity; // Dung lượng hiện tại của vector

public:
    Vector() : data(nullptr), vec_size(0), vec_capacity(0) {}

    ~Vector() {
        delete[] data;
    }

    size_t size() const { return vec_size; }
    size_t capacity() const { return vec_capacity; }

    void push_back(const T& value) {
        if (vec_size == vec_capacity) {
            reserve(vec_capacity == 0 ? 1 : vec_capacity * 2);
        }
        data[vec_size++] = value;
    }

    //kieu nhu v[i] ; dinh nghia lai toan tu []

    //sua duoc ; co the gan gia tri moi
    T& operator[](size_t index) {
        if (index >= vec_size) throw std::out_of_range("Index out of range");//xu ly ngoai le
        return data[index];
    }

    // ko sua dc ; dung de truy cap
    const T& operator[](size_t index) const {
        if (index >= vec_size) throw std::out_of_range("Index out of range");//xu ly ngoai le
        return data[index];
    }

    void reserve(size_t new_capacity) {
        if (new_capacity > vec_capacity) {
            T* new_data = new T[new_capacity];
            for (size_t i = 0; i < vec_size; ++i) new_data[i] = data[i];
            delete[] data;
            data = new_data;//cap nhap lai con tro
            vec_capacity = new_capacity;//cap nhap lai dung luong
        }
    }

    void replace(size_t index, const T& value) {
        if (index >= vec_size) throw std::out_of_range("Index out of range");
        data[index] = value;
    }

    void erase(size_t index) {
        if (index >= vec_size) throw std::out_of_range("Index out of range");
        for (size_t i = index; i < vec_size - 1; ++i) data[i] = data[i + 1];
        --vec_size;
    }

    void sort(bool ascending = true) {
        if (ascending) {
            std::sort(data, data + vec_size);
        } else {
            std::sort(data, data + vec_size, std::greater<T>());
        }
    }
};
// int main() {
//     cout << "Enter the number of elements you want to enter: ";
//     size_t n;
//     cin >> n;
//     Vector<int> v, k;
//     for (size_t i = 0; i < n; ++i) {
//         cin >> v[i];
//     }
//     for (size_t i = 0; i < n; ++i) {
//         int x;
//         cin >> x;
//         k.push_back(x);
//     }
//     cout << v.size() << endl;
//     for (size_t i = 0; i < v.size(); ++i) {
//         cout << v[i] << endl;
//     }
//     cout << endl;
//
// }
