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

    static void nhap(vector<NhanVien>&nhanvien , int n) {
        NhanVien nv;
        for (int i = 0; i < n; i++) {
            cin>>nv;
            nhanvien.push_back(nv);
        }
    };
    static void xuat(vector<NhanVien>&nhanvien) {
        for (int i = 0; i < nhanvien.size(); i++) {
            cout<<nhanvien[i];
        }
    };
    static double luong_thang(const int a , const double b){
        return a*b*1.0/20;
    };

    //toan tu nhap
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
        cout<<"Nhap luong theo thang(VNĐ): ";
        is>>nv.luong;
        return is;
    };

    //toan tu xuat
    friend ostream& operator<<(ostream &os, const NhanVien &nv){
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

    //toan tu so sanh nho hon
    bool operator<(const NhanVien& other) const {
        return this->luong < other.luong;
    }

    //toan tu so sanh lon hon
    bool operator>(const NhanVien& other) const {
        return this->tuoi > other.tuoi;
    }

    //phuong thu them nhan vien
    static void addNhanVien(vector<NhanVien>&nhan_viens) {
        NhanVien nv;
        cout<<"NhanVien ho ten: ";
        getline(cin,nv.hoTen);
        cout<<"NhanVien gioi tinh: ";
        getline(cin,nv.gioiTinh);
        cout<<"NhanVien que quan: ";
        getline(cin,nv.queQuan);
        cout<<"NhanVien ma nhan vien: ";
        getline(cin,nv.maNV);
        cout<<"NhanVien chuc vu: ";
        getline(cin,nv.chucVu);
        cout<<"NhanVien tuoi: ";
        cin>>nv.tuoi;
        cout<<"NhanVien so ngay lam: ";
        cin>>nv.soNgayLam;
        cout<<"NhanVien luong theo thang: ";
        cin>>nv.luong;
        nhan_viens.push_back(nv);
    }

    //phuong thuc xoa het nhan vien
    static void resetNhanVien(vector<NhanVien>&nhan_viens) {
        nhan_viens.clear();
        cout<<"Reset thanh cong";
    }

    //phuong thuc xoa 1 nhan vien theo ten
    static void easerNhanVienTheoTen(vector<NhanVien>& nhan_viens) {
        cout << "NhanVien ho ten muon xoa: ";
        string e_name;
        cin.ignore();
        getline(cin, e_name);

        for (auto it = nhan_viens.begin(); it != nhan_viens.end(); ++it) {
            if (it->getHoTen() == e_name) { // Sử dụng getter để truy cập hoTen
                nhan_viens.erase(it); // Xóa nhân viên khỏi danh sách
                cout << "Da xoa nhan vien co ten: " << e_name << endl;
                return; // Thoát khỏi hàm sau khi xóa thành công
            }
        }

        // Nếu không tìm thấy nhân viên
        cout << "Khong tim thay nhan vien co ten: " << e_name << endl;
    }

    static void easerNhanVienTheoMa(vector<NhanVien>& nhan_viens) {
        cout << "NhanVien ma nhan vien muon xoa: ";
        string ma_nv;
        cin.ignore();
        getline(cin, ma_nv);

        for (auto it = nhan_viens.begin(); it != nhan_viens.end(); ++it) {
            if (it->getMaNV() == ma_nv) {
                nhan_viens.erase(it); // Xóa nhân viên khỏi danh sách
                cout << "Da xoa nhan vien co ma nhan vien : " << ma_nv << endl;
                return;
            }
        }

        // Nếu không tìm thấy nhân viên
        cout << "Khong tim thay nhan vien co ma nhan vien: " << ma_nv << endl;
    }

    static void updateNhanVien(vector<NhanVien>& nhan_viens) {
    cout << "Nhap ho ten nhan vien muon cap nhat: ";
    string u_name;
    cin.ignore();
    getline(cin, u_name);

    for (auto &nv : nhan_viens) {
        if (nv.getHoTen() == u_name) {
            cout << "Thong tin can cap nhat:\n";
            cout << "1. Ma nhan vien\n";
            cout << "2. Ho ten\n";
            cout << "3. Tuoi\n";
            cout << "4. Luong\n";
            cout << "5. Thoat\n";

            int choice;
            while (true) {
                cout << "Nhap lua chon: ";
                cin >> choice;
                cin.ignore();

                switch (choice) {
                    case 1: {
                        string newMaNV;
                        cout << "Nhap ma nhan vien moi: ";
                        getline(cin, newMaNV);
                        nv.setMaNV(newMaNV);
                        cout << "Da cap nhat ma nhan vien.\n";
                        break;
                    }
                    case 2: {
                        string newHoTen;
                        cout << "Nhap ho ten moi: ";
                        getline(cin, newHoTen);
                        nv.setHoTen(newHoTen);
                        cout << "Da cap nhat ho ten.\n";
                        break;
                    }
                    case 3: {
                        int newTuoi;
                        cout << "Nhap tuoi moi: ";
                        cin >> newTuoi;
                        nv.setTuoi(newTuoi);
                        cout << "Da cap nhat tuoi.\n";
                        break;
                    }
                    case 4: {
                        double newLuong;
                        cout << "Nhap luong moi: ";
                        cin >> newLuong;
                        nv.setLuong(newLuong);
                        cout << "Da cap nhat luong.\n";
                        break;
                    }
                    case 5:
                        cout << "Thoat cap nhat.\n";
                        return;
                    default:
                        cout << "Lua chon khong hop le, vui long chon lai.\n";
                }
            }
        }
    }

    cout << "Khong tim thay nhan vien co ten: " << u_name << endl;
}

    static void xap_xep_theo_ngay_lam(vector<NhanVien>& nhanviens ) {
        sort(nhanviens.begin(), nhanviens.end(), [](const NhanVien& a, const NhanVien& b) {
            return a.soNgayLam > b.soNgayLam;
        });
        cout << "Danh sach nhan vien sau khi sap xep:\n";
        for (const auto& nv : nhanviens) {
            cout<<nv;
        }
    }

    static void xap_xep_theo_tuoi(vector<NhanVien>& nhanviens ) {
        sort(nhanviens.begin(), nhanviens.end(), [](const NhanVien& a, const NhanVien& b) {
            return a.tuoi> b.tuoi;
        });
        cout << "Danh sach nhan vien sau khi sap xep:\n";
        for (const auto& nv : nhanviens) {
            cout<<nv;
        }
    }

    static void tuoi_lon_nhan(vector<NhanVien>& nhanviens ) {
        sort(nhanviens.begin(),nhanviens.end(), [](const NhanVien& a, const NhanVien& b) {
            return a.tuoi < b.tuoi;
        });
        cout<<"Nhan vien co tuoi lon nhan la :"<<endl;
        cout<< nhanviens[nhanviens.size()-1].getHoTen()<< " " << nhanviens[nhanviens.size()-1].getTuoi() <<endl;
    }

    static void ngay_lam_nho_nhat(vector<NhanVien>& nhanviens ) {
        sort(nhanviens.begin(),nhanviens.end(), [](const NhanVien& a, const NhanVien& b) {
           return a.soNgayLam < b.soNgayLam;
        });

        cout<<"Nhan vien co so ngay lam it nhat la:"<<endl;
        cout << nhanviens[0].getHoTen()<< " " << nhanviens[0].getSoNgayLam() <<endl;
    }


};

class App {
public:
    void menu(vector<NhanVien>&nhan_viens) {
        int choice;
        do {
            cout << "\n--- Quan ly Nhan Vien ---\n";
            cout << "1. Them nhan vien\n";
            cout << "2. Xoa nhan vien\n";
            cout << "3. Cap nhat thong tin nhan vien\n";
            cout << "4. Xem danh sach nhan vien\n";
            cout << "5. Sap xep theo so ngay lam\n";
            cout << "6. Sap xep theo tuoi\n";
            cout << "7. Xem nhan vien co tuoi lon nhat\n";
            cout << "8. Xem nhan vien co so ngay lam it nhat\n";
            cout << "9. Thoat\n";
            cout << "Nhap lua chon cua ban: ";
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1:
                    NhanVien::addNhanVien(nhan_viens);
                break;

                case 2:
                    cout<<"Muon xoa nhan vien\n";
                    cout<<"1.Xoa theo ma nhan vien\n";
                    cout<<"2.Xoa theo ten nhan vien\n";
                    int num; cin>>num;
                    switch (num) {
                      case 1:
                        NhanVien::easerNhanVienTheoMa(nhan_viens);
                        break;
                      case 2:
                        NhanVien::easerNhanVienTheoTen(nhan_viens);
                        break;
                    }
                break;

                case 3:
                    NhanVien::updateNhanVien(nhan_viens);
                break;

                case 4:
                    for (const auto &nv : nhan_viens) cout << nv << endl;
                break;

                case 5:
                    NhanVien::xap_xep_theo_ngay_lam(nhan_viens);
                break;

                case 6:
                    NhanVien::xap_xep_theo_tuoi(nhan_viens);
                break;

                case 7:
                    NhanVien::tuoi_lon_nhan(nhan_viens);
                break;

                case 8:
                    NhanVien::ngay_lam_nho_nhat(nhan_viens);
                break;

                case 9:
                    cout << "Thoat chuong trinh.\n";
                break;

                default:
                    cout << "Lua chon khong hop le, vui long nhap lai.\n";
            }
        } while (choice != 9);
    }
};

int main() {

    int n;
    cout<<"Nhap so nhan vien:"; cin>>n;

    vector<NhanVien> nhan_viens;
    NhanVien::nhap(nhan_viens,n);

    App app;
    app.menu(nhan_viens);
    return 0;
}
