#include <bits/stdc++.h>
using namespace std;

class Nguoi {
private:
    string name;
    int tuoi;

public:
    Nguoi(string name, int tuoi) : name(name), tuoi(tuoi) {}

    // Getters
    string getName() const {
        return name;
    }

    int getTuoi() const {
        return tuoi;
    }

    // Setters
    void setName(string name) {
        this->name = name;
    }

    void setTuoi(int tuoi) {
        this->tuoi = tuoi;
    }
};

class CauThu : public Nguoi {
private:
    int goal{};
    int minutes{};

public:
    // Constructor calling the base class constructor
    CauThu(string name, int tuoi, int goal, int minutes) : Nguoi(name, tuoi), goal(goal), minutes(minutes) {}

    int getGoal() const {
        return goal;
    }

    int getMinutes() const {
        return minutes;
    }

    void setGoal(int goal) {
        this->goal = goal;
    }

    void setMinutes(int minutes) {
        this->minutes = minutes;
    }

    void print() {
    }
};

void print(vector<CauThu> cau_thu) {
    for(int i = 0; i < cau_thu.size(); i++) {
        cout << cau_thu[i].getName() << endl;
        cout << cau_thu[i].getTuoi() << endl;
        cout << cau_thu[i].getGoal() << endl;
        cout << cau_thu[i].getMinutes() << endl;
    }
}

#include<bits/stdc++.h>
using namespace std;

class NhanVien {
private:
    string hoTen;
    string gioiTinh;
    string queQuan;
    string maNV;
    string chucVu;
    int tuoi,soNgayLam;
    double luong;

public:
    // constructor
    NhanVien(){};
    NhanVien(string hoTen, string gioiTinh, string queQuan, string maNV, string chucVu, int tuoi, int soNgayLam, double luong){
        this->hoTen = hoTen;
        this->gioiTinh = gioiTinh;
        this->queQuan = queQuan;
        this->maNV = maNV;
        this->chucVu = chucVu;
        this->tuoi = tuoi;
        this->soNgayLam = soNgayLam;
        this->luong = luong;

    };
    // destructor
    ~NhanVien()= default;

    // method
    void nhap(){};
    void xuat(){};
    double tinhLuong(){
        return 0;
    };

    //setter
    void setHoTen(string hoTen){
        this->hoTen = hoTen;
    };
    void setGioiTinh(string gioiTinh){
        this->gioiTinh = gioiTinh;
    };
    void setQueQuan(string queQuan){
        this->queQuan = queQuan;
    };
    void setMaNV(string maNV){
        this->maNV = maNV;
    };
    void setChucVu(string chucVu){
        this->chucVu = chucVu;
    };
    void setTuoi(int tuoi){
        this->tuoi = tuoi;
    };
    void setSoNgayLam(int soNgayLam){
        this->soNgayLam = soNgayLam;
    };
    void setLuong(double luong){
        this->luong = luong;
    };
    // setter
    string getHoTen(){
        return this->hoTen;
    };
    string getGioiTinh(){
        return this->gioiTinh;
    };
    string getQueQuan(){
        return this->queQuan;
    };
    string getMaNV(){
        return this->maNV;
    };
    string getChucVu(){
        return this->chucVu;
    };
    int getTuoi(){
        return this->tuoi;
    };
    int getSoNgayLam(){
        return this->soNgayLam;
    };
    double getLuong(){
        return this->luong;
    };

    friend istream& operator>>(istream &is, NhanVien &nv){
        cout<<"Nhap ho ten: ";
        getline(is,nv.hoTen);
        cout<<"Nhap gioi tinh: ";
        getline(is,nv.gioiTinh);
        cout<<"Nhap que quan: ";
        getline(is,nv.queQuan);
        cout<<"Nhap ma nhan vien: ";
        getline(is,nv.maNV);
        cout<<"Nhap chuc vu: ";
        getline(is,nv.chucVu);
        cout<<"Nhap tuoi: ";
        is>>nv.tuoi;
        cout<<"Nhap so ngay lam: ";
        is>>nv.soNgayLam;
        cout<<"Nhap luong: ";
        is>>nv.luong;
        return is;
    }

    friend ostream& operator<<(ostream &os, NhanVien &nv){
        os<<"Ho ten: "<<nv.hoTen<<" ";
        os<<"Gioi tinh: "<<nv.gioiTinh<<" ";
        os<<"Que quan: "<<nv.queQuan<<" ";
        os<<"Ma nhan vien: "<<nv.maNV<<" ";
        os<<"Chuc vu: "<<nv.chucVu<<" ";
        os<<"Tuoi: "<<nv.tuoi<<" ";
        os<<"So ngay lam: "<<nv.soNgayLam<<" ";
        os<<"Luong: "<<nv.luong<<endl;
        return os;
};


};
int main() {
    int n;
    cout << "Nhap so nguoi/cau thu: ";
    cin >> n;

    vector<CauThu> cau_thu;
    for (int i = 0; i < n; i++) {
        cout << "Nhap ten cau thu thu " << i + 1 << ": ";
        cin.ignore();
        string name;
        getline(cin,name);
        cout << "Nhap tuoi cau thu thu " << i + 1 << ": ";
        int tuoi;
        cin >> tuoi;
        cout << "Nhap so ban thang cua cau thu thu " << i + 1 << ": ";
        int sbt;
        cin >> sbt;
        cout << "Nhap so phut thi dau cua cau thu thu " << i + 1 << ": ";
        int minutes;
        cin >> minutes;

        cau_thu.emplace_back(name, tuoi, sbt, minutes);
    }
    print(cau_thu);
    // Find the oldest player
    int max_age = 0;
    for (int i = 0; i < n; i++) {
        max_age = max(max_age, cau_thu[i].getTuoi());
    }

    cout << "Cau thu lon tuoi nhat co so tuoi la: " << max_age << endl;

    // Calculate price based on goals
    vector<int> price;
    for (int i = 0; i < n; i++) {
        if (cau_thu[i].getMinutes() > 300) {
            int m = cau_thu[i].getGoal() * 5 + 10;
            price.emplace_back(m);
        } else {
            price.emplace_back(0);
        }
    }

    // Output calculated prices
    cout << "Gia cua cac cau thu duoc tinh la: ";
    for (int i = 0; i < n; i++) {
        cout << price[i] << " ";
    }
    cout << endl;

    return 0;
}
