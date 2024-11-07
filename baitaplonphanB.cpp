/*1. Xây dựng lớp Vector
2. Xây dựng quản lý một cửa hàng bán tạp hóa, thông tin quản lý của cửa hàng gồm:
+ Danh mục mặt hàng gồm các thông tin: Mã hàng, Tên hàng, nhà sản xuất
+ Hóa đơn mua bán hàng: Mã hóa đơn, Mã hàng, Loại hóa đơn (Bán hoặc Mua), Số
lượng, Ngày mua bán, Giá mua bán.
Với các phương thức:
a. Đọc danh thông tin quản lý của cửa hàng từ file vào chương trình
b. Ghi thông tin quản lý của cửa hàng vào file
c. Nhập xuất các mặt hàng
d. Hiển thị toàn bộ danh sách mặt hàng hiện có
e. Thống kê số lượng mặt hàng tồn của mỗi mặt hàng
2. Viết hàm main thực hiện các chức năng trên*/

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

// Lớp sampham để quản lý sản phẩm
class sampham {
private:
    int id_sp;
    string ten_sp;
    string nsx_sp;

public:
    sampham() : id_sp(0), ten_sp("chuaro"), nsx_sp("chuabiet") {}
    sampham(int id, string ten, string nsx) : id_sp(id), ten_sp(std::move(ten)), nsx_sp(std::move(nsx)) {}

    int get_id_sp() const { return id_sp; }
    string get_ten_sp() const { return ten_sp; }
    string get_nsx_sp() const { return nsx_sp; }

    //toan tu nhap
   friend istream& operator>>(istream& is, sampham& sp) {
        is >> sp.id_sp >> sp.ten_sp >> sp.nsx_sp;
        return is;
    }

    // toan tu xuat
    friend ostream& operator<<(ostream& os, const sampham& sp) {
        os << "ID San Pham: " << sp.id_sp
           << ", Ten: " << sp.ten_sp
           << ", Nha San Xuat: " << sp.nsx_sp;
        return os;
    }
};

// Lớp hoadon để quản lý hóa đơn
class hoadon {
private:
    int id_hoadon;
    int id_sp;
    string loai_hoadon;
    int soluong;
    string ngay;
    double gia;

public:
    hoadon() : id_hoadon(0), id_sp(0), loai_hoadon("Mua"), soluong(0), ngay("10/10/2020"), gia(0.0) {}
    hoadon(int id_hd, int id_sp, string loai, int sl, string ngay, double gia)
        : id_hoadon(id_hd), id_sp(id_sp), loai_hoadon(std::move(loai)), soluong(sl), ngay(std::move(ngay)), gia(gia) {}

    int get_id_sp() const { return id_sp; }
    string get_loai_hoadon() const { return loai_hoadon; }
    int get_soluong() const { return soluong; }

    friend istream& operator>>(istream& is, hoadon& hd) {
        is >> hd.id_hoadon >> hd.id_sp >> hd.loai_hoadon >> hd.soluong >> hd.ngay >> hd.gia;
        return is;
    }

    // Hàm xuất dữ liệu hoadon ra màn hình
    friend ostream& operator<<(ostream& os, const hoadon& hd) {
        os << "ID Hoa Don: " << hd.id_hoadon
           << ", ID San Pham: " << hd.id_sp
           << ", Loai Hoa Don: " << hd.loai_hoadon
           << ", So Luong: " << hd.soluong
           << ", Ngay: " << hd.ngay
           << ", Gia: " << hd.gia;
        return os;
    }
};


// Hàm ghi danh sách sản phẩm vào file
void ghi_danh_sach_san_pham(const string& filename, const Vector<sampham>& danh_muc) {
    ofstream file(filename);
    if (!file) {
        cerr << "can't not open " << filename << endl;
        return;
    }

    for (size_t i = 0; i < danh_muc.size(); ++i) {
        file << danh_muc[i] << endl;
    }
    file.close();
}

// Hiển thị danh sách sản phẩm
void hien_thi_danh_sach_san_pham(const Vector<sampham>& danh_muc) {
    cout << "danh sach san pham:\n";
    for (size_t i = 0; i < danh_muc.size(); ++i) {
        cout << danh_muc[i] << endl;
    }
}

// Hàm thống kê số lượng sản phẩm tồn
void thong_ke_san_pham_ton(const Vector<hoadon>& ds_hoadon, const Vector<sampham>& danh_muc) {
    cout << "thong ke so luong san pham ton:\n";
    for (size_t i = 0; i < danh_muc.size(); ++i) {
        int so_luong_ton = 0;
        for (size_t j = 0; j < ds_hoadon.size(); ++j) {
            if (ds_hoadon[j].get_id_sp() == danh_muc[i].get_id_sp()) {
                so_luong_ton += (ds_hoadon[j].get_loai_hoadon() == "Mua" ? ds_hoadon[j].get_soluong() : -ds_hoadon[j].get_soluong());
            }
        }
        cout << "ma hang: " << danh_muc[i].get_id_sp() << ", ten hang: " << danh_muc[i].get_ten_sp() << ", so luong ton: " << so_luong_ton << endl;
    }
}

// Hàm đọc danh sách sản phẩm từ file
void doc_danh_sach_san_pham(const string& filename, Vector<sampham>& danh_muc) {
    ifstream file(filename);
    if (!file) {
        cerr << "can't not open " << filename << endl;
        return;
    }

    sampham sp;
    while (file >> sp) {
        danh_muc.push_back(sp);
    }
    file.close();
}

// Hàm đọc danh sách hóa đơn từ file
void doc_danh_sach_hoa_don(const string& filename, Vector<hoadon>& ds_hoadon) {
    ifstream file(filename);
    if (!file) {
        cerr << "can't not open " << filename << endl;
        return;
    }

    hoadon hd;
    while (file >> hd) {
        ds_hoadon.push_back(hd);
    }
    file.close();
}

void menu() {
    cout << "\n====== MENU ======" << endl;
    cout << "1. Them san pham moi" << endl;
    cout << "2. Hien thi danh sach san pham" << endl;
    cout << "3. Thong ke so luong san pham" << endl;
    cout << "4. Ghi danh sach san pham vao file" << endl;
    cout << "5. Thoat" << endl;
    cout << "===================" << endl;
    cout << "Nhap lua chon cua ban: ";
}

int main() {
    Vector<sampham> danh_muc;
    Vector<hoadon> ds_hoadon;

    // Đọc danh sách sản phẩm từ file
    doc_danh_sach_san_pham("D:\\CTDL\\clion\\sanpham.txt", danh_muc);

    // Đọc danh sách hóa đơn từ file
    doc_danh_sach_hoa_don("D:\\CTDL\\clion\\hoadon.txt", ds_hoadon);

    int choice;
    do {
        menu();
        cin >> choice;

        switch (choice) {
            case 1: {
                sampham sp;
                cout << "Nhap thong tin san pham (ID Ten Nha San Xuat): ";
                cin >> sp;
                danh_muc.push_back(sp);
                cout << "Da them san pham moi thanh cong!" << endl;
                break;
            }
            case 2:
                cout << "\nDanh sach san pham hien tai:\n";
                hien_thi_danh_sach_san_pham(danh_muc);
                break;
            case 3:
                cout<< "\nthong ke so luong san pham ton:\n";
                thong_ke_san_pham_ton(ds_hoadon,danh_muc);
            case 4:
                // Ghi danh sach san pham vao file
                ghi_danh_sach_san_pham("D:\\CTDL\\clion\\data.txt", danh_muc);
                cout << "Da ghi danh sach san pham vao file data.txt!" << endl;
                break;
            case 5:
                cout << "Thoat chuong trinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
        }
    } while (choice != 5);

    return 0;
}
