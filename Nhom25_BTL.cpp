#include <iostream>
#include <Windows.h>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <cstring>
#include <vector>
#include <io.h>
#include <time.h> 
#include <cmath>

 
using namespace std;
 
#define N 256
 
const char *fileLogin = "Login.txt";
 
string taikhoan, matkhau;
string LINE, line1;
string TTCN, _BDHT, _BDRL, _DSMH, _LT;

 
time_t now = time(0);
tm *ltm = localtime(&now);
 
char line[N], c; 
int i, k, u, a=0, dem, diemRL;
float GPA, ts;
FILE* file;
 
 
 
 
void printLine(int n) {
    for (int i = 0; i < n; i++) {
        cout << "-";
    }
    cout << endl;
}

void copyName(string taikhoan) {
    TTCN = taikhoan; 
    _BDHT = taikhoan;
    _BDRL = taikhoan; 
    _DSMH = taikhoan;
    _LT = taikhoan;
    TTCN += "_thongtincanhan.txt";
    _BDHT += "_bangdiemhoctap.txt";
    _BDRL += "_bangdiemrenluyen.txt";
    _DSMH += "_danhsachmonhoc.txt";
    _LT += "_lichthi.txt";
}
 
void taoFile(string tenfile) {
    ofstream file;
    file.open (tenfile.c_str());
}
 
void checkFile(string namefile) {
    if (access(namefile.c_str(), 0) == 1) {
        taoFile(namefile);
    }
}
 
int checkEmptyFile(string namefile) {
    ifstream in(namefile.c_str());
    in.seekg(0, ios::end);
    int spot = in.tellg();
    if( spot == 0)
    {
        cout << "File chua co du lieu" << endl;
        Sleep(2000);
        return 1;
    }
    return 0;
}
 
int _Clock() {
    int C;
    system("cls");
    cout <<(char)(218) <<"------------------------------------------" <<(char)(191) << endl;
    cout << "|             DONG HO POMODORO             |" << endl;
    cout << "|------------------------------------------|" << endl;
    cout << "|                                          |" << endl;
    cout << "|                  25:00                   |" << endl;
    cout << "|                                          |" << endl;
    cout << "|------------------------------------------|" << endl;
    cout << "|                                          |" << endl;
    cout << "|        1.BAT DAU       2.THOAT           |" << endl;
    cout << "|                                          |" << endl;
    cout <<(char)(192)<< "------------------------------------------"<<(char)(217) << endl;
    cout  << "Ban chon ? ";
    cin >> C;
    if (C == 2) return 1;   
    return 0;
}
 
int Clock() {
Refresh:
    int phut=25, giay=0;
    while (true) {
        cout <<(char)(218) <<"------------------------------------------" <<(char)(191) << endl;
        cout << "|             DONG HO POMODORO             |" << endl;
        cout << "|------------------------------------------|" << endl;
        cout << "|                                          |" << endl;
        if (phut < 10 && giay < 10) {
            cout << left << setw(21) << "|"<< phut << ":" << giay << right << setw(20) << "|" << endl;
        }
        if (phut < 10 && giay >= 10) {
            cout << left << setw(20) << "|"<< phut << ":" << giay << right << setw(20) << "|" << endl;
        }
        if (phut >= 10 && giay >= 10) {
            cout << left << setw(19) << "|"<< phut << ":" << giay << right << setw(20) << "|" << endl;
        }
        if (phut >= 10 && giay < 10) {
            cout << left << setw(20) << "|"<< phut << ":" << giay << right << setw(20) << "|" << endl;
        }
            
        cout << "|                                          |" << endl;
        cout << "|------------------------------------------|" << endl;
        cout << "|                                          |" << endl;
        cout << "| TAM DUNG        LAM MOI         KET THUC |" << endl;
        cout << "| (Space)         (Enter)       (Backspace)|" << endl;    
        cout <<(char)(192)<< "------------------------------------------"<<(char)(217) << endl;
            
        giay--;
        if (giay == -1) {
            giay = 59;
            phut--;
        }
        if (phut == 0 && giay == 0) {
            system("Sound.vbs");
            cout << "Ban da hoan thanh mot chu ky. Xin hay nghi giai lao...";
            fflush(stdin);
            cin.get();
            return 0;
        }
            
        if ( kbhit() ) { 
            fflush(stdin);
            c = getch();
            if ((int)c == 13) {
                cout << endl;
                goto Refresh;
            } else if ((int)c == 8) return 0;
            else {
                system("pause");
            }
        }
        Sleep(960);
        system("cls");
            
    } 
}
 
void showLogin(string taikhoan,int sizeofPass){
    string S;
    cout << endl;
    system("cls");
    for(int i = 0; i<sizeofPass; i++){
        S += "*";
    }
    cout << (char)(218) <<"--------------------------------------------"<<(char)(191) << endl;;
    cout << "|                  DANG NHAP                 |" << endl;
    cout << "|--------------------------------------------|" << endl;
    cout << "|Tai khoan:"<<left << setw(34) << taikhoan <<"|" << endl;
    cout << "|--------------------------------------------|" << endl;
    cout << "|Mat khau :"<<left << setw(34) << S <<"|" << endl;
    cout << "|--------------------------------------------|" << endl;
    cout << "|Nhan (Esc) de quay lai                      |" << endl;
    cout << (char)(192)<<"--------------------------------------------"<<(char)(217) << endl;
}
 
void showRegister(string taikhoan,int sizeofPass,int sizeofRePass){
    string S,SS;
    cout << endl;
    system("cls");
    for(int i = 0; i<sizeofPass; i++){
        S += "*";
    }
    for(int i = 0; i<sizeofRePass; i++){
        SS += "*";
    }
    cout << (char)(218) <<"-----------------------------------------------"<<(char)(191) << endl;;
    cout << "|                    DANG KY                    |" << endl;
    cout << "|-----------------------------------------------|" << endl;
    cout << "|Tai khoan:"<<left << setw(37) << taikhoan <<"|" << endl;
    cout << "|-----------------------------------------------|" << endl;
    cout << "|Mat khau :"<<left << setw(37) << S <<"|" << endl;
    cout << "|-----------------------------------------------|" << endl;
    cout << "|Mat khau :"<<left << setw(37) << SS <<"|" << endl;
    cout << "|-----------------------------------------------|" << endl;
    cout << "|Nhan (Esc) de quay lai                         |" << endl;
    cout << (char)(192)<<"-----------------------------------------------"<<(char)(217) << endl;
 
}
 
int MENU(){
    int C=0;
    cout << endl;
    system("cls");
    cout <<(char)(218) <<"------------------------------------------" <<(char)(191) << endl;
    cout << "|             Dang nhap/Dang ky            |" << endl;
    cout << "|------------------------------------------|" << endl;
    cout << "|             1-Dang nhap                  |" << endl;
    cout << "|------------------------------------------|" << endl;
    cout << "|             2-Dang ky                    |" << endl;
    cout << "|------------------------------------------|" << endl;
    cout << "|             3-Quen mat khau              |" << endl;
    cout << "|------------------------------------------|" << endl;
    cout << "|             4-Thoat                      |" << endl;
    cout <<(char)(192)<< "------------------------------------------"<<(char)(217) << endl;
    cout << "Ban chon ? ";
    cin >> C;
    return C;
}
 
class LOGIN {
 
private:
    char username[30];
    char password[30];
    char tmpUsername[30];
    char tmpPassword[30];
    char rePassword[30];
    string user; /// string show username
    string pass; /// string show password
    string repass; /// string show re-enter password
    char tmp;
 
public:
    
    int checkSignUp() {
        file = fopen(fileLogin,"a+");
        while(fgets(line, N, file) != NULL) { 
            sscanf(line, "%s %s", username, password); //&f1, &f2, &f3, &f4, &f5 - %f    
            if (strcmp(username, tmpUsername) == 0) {
                return 1;
            } 
        }
        return 0;
    }
    int importSignUpAccount() {
 
        user = ""; /// string show username
        pass = ""; /// string show password
        repass = ""; /// string show re-enter password
        char tmp; /// get char from input
 
        /// enter username
        showRegister(user,pass.size(),repass.size());
        for(int i = 0;;){
            tmp = getch();
            if((int)(tmp) == 27){  /// ESC
                return 1;
            }
            else if((int)(tmp) == 8){   /// backspace
                if(user.size()>0) user.erase(user.size()-1,1);
            }
            else if((int)(tmp) == 13 && user.size() > 0){    /// enter
                break;
            }
            else
                user += tmp;
            showRegister(user,pass.size(),repass.size());
        }
        for(int i = 0; i<user.size(); i++){
            tmpUsername[i]=user[i];
        }
        tmpUsername[user.size()] = '\0';
 
        ///enter password
        showRegister(user,pass.size(),repass.size());
        for(int i = 0;;){
            tmp = getch();
            if((int)(tmp) == 27){   /// ESC
                return 1;
            }
            else if((int)(tmp) == 8){    /// backspace
                if(pass.size()>0) pass.erase(pass.size()-1,1);
            }
            else if((int)(tmp) == 13 && pass.size() > 0){    /// enter
                break;
            }
            else
                pass += tmp;
            showRegister(user,pass.size(),repass.size());
        }
        for(int i = 0; i<pass.size(); i++){
            tmpPassword[i]= pass[i];
        }
        tmpPassword[pass.size()] = '\0';
 
        /// re-enter password
        showRegister(user,pass.size(),repass.size());
        for(int i = 0;;){
            tmp = getch();
            if((int)(tmp) == 27){   /// ESC
                return 1;
            }
            else if((int)(tmp) == 8){    /// backspace
                if(repass.size()>0) repass.erase(repass.size()-1,1);
            }
            else if((int)(tmp) == 13 && repass.size() > 0){    /// enter
                break;
            }
            else
                repass += tmp;
            showRegister(user,pass.size(),repass.size());
        }
        for(int i = 0; i<repass.size(); i++){
            rePassword[i]= repass[i];
        }
        rePassword[repass.size()] = '\0';
        return 0;
    }
 
    void SignUpAccount() {
        do {
            if (importSignUpAccount() == 1) break;
            else {
                if (strcmp(tmpPassword, rePassword) != 0) {
                    cout << "Xac nhan mat khau khong chinh xac" << endl;
                    Sleep(2000);
                    continue;
                }
                if (checkSignUp() == 1) {
                    cout << "Tai khoan nay da ton tai" << endl;
                    Sleep(3000);
                    continue;
                } else {
                    cout << "Ban da dang ky thanh cong tai khoan " << tmpUsername << endl;
                    cout << "Nhan phim Enter de tiep tuc...";
                    fflush(stdin);
                    cin.get();
                    fflush(stdin);
                    fprintf(file,"%s %s\n",tmpUsername, tmpPassword);
 
                    taikhoan = (string)tmpUsername;
                    copyName(taikhoan);
                    taoFile(TTCN);
                    taoFile(_BDHT);
                    taoFile(_BDRL);
                    taoFile(_DSMH);
                    taoFile(_LT);
                    fclose(file);
                    break;
                }
            } 
        } while (1);
    }
 
    int importSignInAccount() {
 
        string user = ""; /// string show ID;
        char tmp;
 
        /// enter username
        showLogin(user,0);
        for(int i = 0;;){
            tmp = getch();
            if((int)(tmp) == 27){   /// ESC
                return 1;
            }
            else if((int)(tmp) == 8){    /// backspace
                if(user.size()>0) user.erase(user.size()-1,1);
            }
            else if((int)(tmp) == 13 && user.size() > 0){    /// enter
                break;
            }
            else
                user += tmp;
            showLogin(user,0);
        }
        /// copy string to char array
        for(int i = 0; i<user.size(); i++){
            tmpUsername[i] = user[i];
        }
        tmpUsername[user.size()] = '\0';
 
        /// enter password
        string pass = ""; /// string show PASS;
        showLogin(user,0);
        for(int i = 0;;){
            tmp = getch();
            if((int)(tmp) == 27){   /// ESC
                return 1;
            }
            else if((int)(tmp) == 8){    /// backspace
                if(pass.size()>0) pass.erase(pass.size()-1,1);
            }
            else if((int)(tmp) == 13 && pass.size() > 0){    /// enter
                break;
            }
            else
                pass += tmp;
            showLogin(user,pass.size());
        }
        /// copy string to char array
        for(int i = 0; i<pass.size(); i++){
            tmpPassword[i] = pass[i];
        }
        tmpPassword[pass.size()] = '\0';
        return 0;
    }
 
    int checkSignIn() {
        file = fopen(fileLogin, "r");
        while(fgets(line, N, file) != NULL) { 
            sscanf(line, "%s %s", username, password); //&f1, &f2, &f3, &f4, &f5 - %f    
            if(strcmp(username,tmpUsername) == 0 && strcmp(password,tmpPassword) == 0){
                cout << "Dang nhap thanh cong...";
                taikhoan = (string)tmpUsername;
                copyName(taikhoan);
                Sleep(2000);        
                fclose(file);
                return 1;
            }  
        }
        return 0;
    }
 
    void SignInAccount() {
        do {
            a = importSignInAccount();
            if (a == 1) break;
            else {
                if (checkSignIn() == 0) {
                    cout << "Tai khoan hoac mat khau khong chinh xac" << endl;
                    Sleep(2000);
                    continue;
                } else {
                    break;
                }
            }
        } while (1);
 
    }
 
    int showForgetPass() {
        char ForgetPass[30];
        system("cls");
        cout << "Nhap tai khoan can lay lai: ";
        fflush(stdin);
        gets(ForgetPass);
        file = fopen(fileLogin, "r");
        while(fgets(line, N, file) != NULL) { 
            sscanf(line, "%s %s", username, password); //&f1, &f2, &f3, &f4, &f5 - %f    
            if(strcmp(username,ForgetPass) == 0){
                cout << (char)(218) <<"--------------------------------------------"<<(char)(191) << endl;;
                cout << "|Tai khoan:"<<left << setw(34) << username <<"|" << endl;
                cout << "|--------------------------------------------|" << endl;
                cout << "|Mat khau :"<<left << setw(34) << password <<"|" << endl;
                cout << (char)(192)<<"--------------------------------------------"<<(char)(217) << endl;        
                fclose(file);
                return 1;
            }  
        }
        return 0;
    }
 
};
 
 
class ThongTinCaNhan {
private:
    vector<string> _1;
public:
    void docFile() {
        int i;
        cout << endl;
        system("cls");
        cout <<(char)(218) <<"------------------------------------------------------------" <<(char)(191) << endl;
        cout << "|                      THONG TIN CA NHAN                     |" << endl;
        cout << "|------------------------------------------------------------|" << endl;
        ifstream myfile (TTCN.c_str());
 
        while (getline(myfile, line1)){
            _1.push_back(line1);
        }
 
        for (int i=0; i<=7; i++) {
            if (i == 0) cout << "|1)Ho va ten: "<<left << setw(47) << _1[i] <<"|" << endl;
            if (i == 1) cout << "|2)Ngay sinh: "<<left << setw(47) << _1[i] <<"|" << endl;
            if (i == 2) cout << "|3)Gioi tinh: "<<left << setw(47) << _1[i] <<"|" << endl;
            if (i == 3) cout << "|4)Ma so sinh vien: "<<left << setw(41) << _1[i] <<"|" << endl;
            if (i == 4) cout << "|5)Nam vao hoc: "<<left << setw(45) << _1[i] <<"|" << endl;
            if (i == 5) cout << "|6)Lop: "<<left << setw(53) << _1[i] <<"|" << endl;
            if (i == 6) cout << "|7)Chuong trinh dao tao: "<<left << setw(36) << _1[i] <<"|" << endl;
            if (i == 7) cout << "|8)Email: "<<left << setw(51) << _1[i] <<"|" << endl;
            if (i != 7) cout << "|------------------------------------------------------------|" << endl;
        }
        cout <<(char)(192)<< "------------------------------------------------------------"<<(char)(217) << endl;
        _1.clear();
        myfile.close();
 
    }
    void ghi(FILE *file, int n) {
        string _nhap;
        
        printLine(120);  
 
        ifstream myfile (TTCN.c_str());
 
        while (getline(myfile, line1)){
            _1.push_back(line1);
        }
        myfile.close();
        if (n == 1) {
            cout << "Ho va ten: ";
            fflush(stdin);
            getline(cin, _nhap);
            _1[0] = _nhap;
        }
        if (n == 2) {
            cout << "Ngay sinh: ";
            fflush(stdin);
            getline(cin, _nhap);
            _1[1] = _nhap;
        }
        if (n == 3) {
            cout << "Gioi tinh: ";
            fflush(stdin);
            getline(cin, _nhap);
            _1[2] = _nhap;
        }
        if (n == 4) {
            cout << "Ma so sinh vien: ";
            fflush(stdin);
            getline(cin, _nhap);
            _1[3] = _nhap;
        }
        if (n == 5) {
            cout << "Nam vao hoc: ";
            fflush(stdin);
            getline(cin, _nhap);
            _1[4] = _nhap;
        }
        if (n == 6) {
            cout << "Lop: ";
            fflush(stdin);
            getline(cin, _nhap);
            _1[5] = _nhap;
        }
        if (n == 7) {
            cout << "Chuong trinh dao tao: ";
            fflush(stdin);
            getline(cin, _nhap);
            _1[6] = _nhap;
        }
        if (n == 8) {
            cout << "Email: ";
            fflush(stdin);
            getline(cin, _nhap);
            _1[7] = _nhap;
        }
        ofstream fpInfo;
        fpInfo.open (TTCN.c_str(), ios::out | ios::trunc);
        fpInfo.seekp (0, ios::beg);
 
        fpInfo << _1[0] << "\n" << _1[1] << "\n" << _1[2] << "\n" << _1[3] << "\n" << _1[4];
        fpInfo << "\n" << _1[5] << "\n" << _1[6] << "\n" << _1[7];
 
        fpInfo.close();
        _1.clear();
    }
    void ghiFileSV(FILE *file) {
        string _nhap;
        printLine(120);  
 
        ofstream fpInfo;
        fpInfo.open (TTCN.c_str(), ios::out | ios::trunc);
        fpInfo.seekp (0, ios::beg);
        cout << "Ho va ten: ";
        fflush(stdin);
        getline(cin, _nhap);
        fpInfo << _nhap;
 
        cout << "Ngay sinh: ";
        fpInfo << "\n";  
        fflush(stdin);
        getline(cin, _nhap);
        fpInfo << _nhap;
 
        cout << "Gioi tinh: ";
        fpInfo << "\n"; 
        fflush(stdin);
        getline(cin, _nhap);
        fpInfo << _nhap;
 
        cout << "Ma so sinh vien: ";
        fpInfo << "\n"; 
        fflush(stdin);
        getline(cin, _nhap);
        fpInfo << _nhap;
 
        cout << "Nam vao hoc: ";
        fpInfo << "\n"; 
        fflush(stdin);
        getline(cin, _nhap);
        fpInfo << _nhap;
 
        cout << "Lop: ";
        fpInfo << "\n"; 
        fflush(stdin);
        getline(cin, _nhap);
        fpInfo << _nhap;
 
        cout << "Chuong trinh dao tao: ";
        fpInfo << "\n"; 
        fflush(stdin);
        getline(cin, _nhap);
        fpInfo << _nhap;
 
        cout << "Email: ";
        fpInfo << "\n"; 
        fflush(stdin);
        getline(cin, _nhap);
        fpInfo << _nhap;
 
        fpInfo.close(); 
    }
};
 
 
class BangDiemHoctap {
private:
    int hocky, tinchi;
    float trongso, quatrinh, cuoiky, TBC;
    char hocphan[29], diemchu[14];


    vector<string> _2;
    vector<int> _2HK;
    struct SCORE {
        float trongso;
        float quatrinh;
        float cuoiki;
        float tbc;
        char diemchu[5];
    };
    
public: 
    struct BDHT {
        int hocky;
        char hocphan[35];
        int tinchi;
        struct SCORE diem;  
    };
    void nhapDiem(struct SCORE* diem) {
        cout << "Trong so: ";
        cin >> diem->trongso;
        cout << "Qua trinh: ";
        cin >> diem->quatrinh;
        cout << "Cuoi ki: ";
        cin >> diem->cuoiki;
        diem->tbc = (diem->quatrinh)*(diem->trongso)+(diem->cuoiki)*(1-(diem->trongso));
        if (diem->tbc >= 9.5) strcpy(diem->diemchu, "A+");
        else if (diem->tbc >= 8.5) strcpy(diem->diemchu, "A");
        else if (diem->tbc >= 8.0) strcpy(diem->diemchu, "B+");
        else if (diem->tbc >= 7.0) strcpy(diem->diemchu, "B");
        else if (diem->tbc >= 6.5) strcpy(diem->diemchu, "C+");
        else if (diem->tbc >= 5.5) strcpy(diem->diemchu, "C");
        else if (diem->tbc >= 5.0) strcpy(diem->diemchu, "D+");
        else if (diem->tbc >= 4.0) strcpy(diem->diemchu, "D");
        else strcpy(diem->diemchu, "F");
    }
    struct BDHT nhapBD() {
        struct BDHT bdht;
        cout << "Hoc ki: ";
        cin >> bdht.hocky;
        cout << "Hoc phan: ";
        fflush(stdin);
        gets(bdht.hocphan);
        cout << "So tin chi: ";
        cin >> bdht.tinchi;
        nhapDiem(&bdht.diem);
        return bdht;  
    } 
    void XOA(FILE *file, int n) {
        string sentence;
        printLine(120);  
 
        ifstream myfile (_BDHT.c_str());
        int sodong=0;
        while (getline(myfile, line1)){
            _2.push_back(line1); //doc va luu tung dong vao vector
            sodong++;
        }
        myfile.close();
        _2[n - 1] = "0"; //gan gia tri can xoa bang 0
        ofstream fp;
        fp.open (_BDHT.c_str(), ios::out | ios::trunc);
        fp.seekp (0, ios::beg);
        for (int i = 0; i < sodong; i++) {
            if (_2[i].compare("0") == 0) continue; //phan tu can xoa ko duoc ghi lai vao file
            else {
                fp << _2[i] << "\n"; //ghi vao file
            }
        }
        fp.close();
        _2.clear();
    
    }
 
    void ghiFileBDHT(FILE *file, struct BDHT bdht) {
 
        ofstream fpScore;
        fpScore.open (_BDHT.c_str(), ios::app);
        fpScore << bdht.hocky << " " << bdht.tinchi << " " << bdht.diem.trongso << " ";
        fpScore << bdht.diem.quatrinh << " " << bdht.diem.cuoiki << " " << bdht.diem.tbc << " ";
        fpScore << bdht.diem.diemchu << " " << bdht.hocphan << ".\n";
        fpScore.close();
 
    }
    void docFileBDHT(FILE *file) { 
        ifstream myfile (_BDHT.c_str());
        int sodong=0;
        while (getline(myfile, line1)){
            _2.push_back(line1);         //doc va luu tung dong vao vector
            sodong++;
        }
        myfile.close();
 
        file = fopen(_BDHT.c_str(), "r");
        
        while (fgets(line, N, file) != NULL) {        //doc va luu tung hoc ky vao vector
            sscanf(line, "%d %d %f %f %f %f %s %[^.]", &hocky, &tinchi, &trongso, &quatrinh, &cuoiky, &TBC, diemchu, hocphan);
            _2HK.push_back(hocky);
        }
        fclose(file);
        
        for (int i = 0; i < sodong; i++) {
            for (int j = i+1; j < sodong; j++) {
                if (_2HK[j] < _2HK[i]) {
                    _2[j].swap(_2[i]);   // sap xep hoc ky theo thu tu tang dan
                }
            }
        }
        
        ofstream fp;
        fp.open (_BDHT.c_str(), ios::out | ios::trunc);
        fp.seekp (0, ios::beg);
        for (int i = 0; i < sodong; i++) {
            fp << _2[i] << "\n";
        }
        fp.close();
        
        file = fopen(_BDHT.c_str(), "r");
        hienthiBDHT();
        int STT=1;     
        int z; 
                                             //in ra man hinh bang diem hoc tap
        while (fgets(line, N, file) != NULL) {
            sscanf(line, "%d %d %f %f %f %f %s %[^.]", &hocky, &tinchi, &trongso, &quatrinh, &cuoiky, &TBC, diemchu, hocphan);
            if (STT == 1) {
                z = hocky;
                ts = 0;
                dem = 0;
                if (TBC >= 8.5 && TBC <= 10.0) ts += tinchi*4;
                if (TBC >= 8.0 && TBC < 8.5) ts += tinchi*3.5;
                if (TBC >= 7.0 && TBC < 8.0) ts += tinchi*3;
                if (TBC >= 6.5 && TBC < 7.0) ts += tinchi*2.5;
                if (TBC >= 5.5 && TBC < 6.5) ts += tinchi*2;
                if (TBC >= 5.0 && TBC < 5.5) ts += tinchi*1.5;
                if (TBC >= 4.0 && TBC < 5.0) ts += tinchi;
                else ts += tinchi*0;
 
                dem += tinchi;
            } else if (z != hocky) {
                cout << "|-----------------------------------------------------------------------------------------------------------------------|" << endl;
                cout << "| Hoc ky " << z << ": GPA = "<< left << setw(10) << ts/dem << right << setw(89) << "|" << endl;
                cout << "|-----------------------------------------------------------------------------------------------------------------------|" << endl;
                ts = 0;
                dem = 0;
                if (TBC >= 8.5 && TBC <= 10.0) ts += tinchi*4;
                if (TBC >= 8.0 && TBC < 8.5) ts += tinchi*3.5;
                if (TBC >= 7.0 && TBC < 8.0) ts += tinchi*3;
                if (TBC >= 6.5 && TBC < 7.0) ts += tinchi*2.5;
                if (TBC >= 5.5 && TBC < 6.5) ts += tinchi*2;
                if (TBC >= 5.0 && TBC < 5.5) ts += tinchi*1.5;
                if (TBC >= 4.0 && TBC < 5.0) ts += tinchi;
                else ts += tinchi*0;
 
                dem += tinchi;
                z = hocky;
            } else if (z == hocky) {
                if (TBC >= 8.5 && TBC <= 10.0) ts += tinchi*4;
                if (TBC >= 8.0 && TBC < 8.5) ts += tinchi*3.5;
                if (TBC >= 7.0 && TBC < 8.0) ts += tinchi*3;
                if (TBC >= 6.5 && TBC < 7.0) ts += tinchi*2.5;
                if (TBC >= 5.5 && TBC < 6.5) ts += tinchi*2;
                if (TBC >= 5.0 && TBC < 5.5) ts += tinchi*1.5;
                if (TBC >= 4.0 && TBC < 5.0) ts += tinchi;
                else ts += tinchi*0;
 
                dem += tinchi;
            } 
            
            cout << "| " << left << setw(5) << STT << left << setw(10) << hocky << left << setw(31) << hocphan;
            cout << left << setw(11) << tinchi << left << setw(14) << trongso;
            cout << left << setw(13) << quatrinh << left << setw(12) << cuoiky;
            cout << left << setw(14) << TBC << left << setw(8) << diemchu << "|" << endl;
            STT++;
            if (STT == sodong+1) {
                cout << "|-----------------------------------------------------------------------------------------------------------------------|" << endl;
                cout << "| Hoc ky " << z << ": GPA = "<< left << setw(10) << ts/dem << right << setw(89) << "|" << endl;
            }
        }   
        cout <<(char)(192)<< "-----------------------------------------------------------------------------------------------------------------------"<<(char)(217) << endl;
        fclose(file);
        _2.clear();
        _2HK.clear();
    }
 
    void hienthiBDHT() {
 
        cout << endl;
        system("cls");
        cout <<(char)(218) <<"-----------------------------------------------------------------------------------------------------------------------" <<(char)(191) << endl;
        cout << "|" << right << setw(68) << "BANG DIEM HOC TAP" << setw(52) << "|" << endl;
        cout << "|-----------------------------------------------------------------------------------------------------------------------|" << endl;
 
        cout << "|" << left << setw(6) << "STT" << left << setw(10) << "Hoc ky" << left << setw(28) << "Ten hoc phan";
        cout << left << setw(11) << "Tin chi" << left << setw(14) << "Trong so";
        cout << left << setw(14) << "Qua trinh" << left << setw(14) << "Cuoi ky";
        cout << left << setw(8) << "TBC" << left << setw(14) << "Diem bang chu" << "|" << endl;
        cout << "|-----------------------------------------------------------------------------------------------------------------------|" << endl;
 
    }
};
 
 
class BangDiemRenLuyen {

private:
    int hocky, hoctap, kyluat, xahoi, congdong, vipham, tongdiem;
    vector<string> _3;
    vector<int> _3HK;
public:
    int checkHK(int data) {
        
        file = fopen(_BDRL.c_str(), "r");
        
 
        while (fgets(line, N, file) != NULL) {
            sscanf(line, "%d %d %d %d %d %d %d", &hocky, &hoctap, &kyluat, &xahoi, &congdong, &vipham, &tongdiem);
            if (hocky == data) {
                cout << "Hoc ky nay da co trong bang diem ren luyen\n";
                Sleep(2000);
                return 1;
            } 
        }
 
        fclose(file);
        return 0;
    }
    void XOA(FILE *file, int n) {
        string sentence;
        printLine(120);  
 
        ifstream myfile (_BDRL.c_str());
        int sodong=0;
        while (getline(myfile, line1)){
            _3.push_back(line1);
            sodong++;
        }
        myfile.close();
        _3[n - 1] = "0";
        ofstream fp;
        fp.open (taikhoan.c_str(), ios::out | ios::trunc);
        fp.seekp (0, ios::beg);
        for (int i = 0; i < sodong; i++) {
            if (_3[i].compare("0") == 0) continue;
            else {
                fp << _3[i] << "\n";
            }
        }
        fp.close();
        _3.clear();
    }
    void ghiFileBDRL(FILE *file) {
 
        int data, b, renluyen = 0; 
        do {
            printLine(120);
            cout << "Hoc ky: ";
            cin >> data;
            if (data < 20000 || data > 30000) {
                cout << "Du lieu hoc ky khong hop le\n";
                Sleep(2000);
                continue;
            }
            b = checkHK(data); //kiem tra xem hoc ky da ton tai trong file chua(tontai => 1, chua => 0)
        } while (data < 20000 || data > 30000 || b == 1);
 
        ofstream fpRL;
        fpRL.open (_BDRL.c_str(), ios::app);
        fpRL << data << " ";
 
        do {
            cout << "Tieu chi hoc tap[0;30]: ";
            cin >> data;
        } while (data < 0 || data > 30); 
        renluyen += data;
        fpRL << data << " ";
 
        do {
            cout << "Tieu chi ky luat[0;25]: ";
            cin >> data;
        } while (data < 0 || data > 25); 
        renluyen += data;
        fpRL << data << " ";
 
        do {
            cout << "Tieu chi xa hoi[0;25]: ";
            cin >> data;
        } while (data < 0 || data > 25); 
        renluyen += data;
        fpRL << data << " ";
 
        do {
            cout << "Tieu chi cong dong[0;20]: ";
            cin >> data;
        } while (data < 0 || data > 20); 
        renluyen += data;
        fpRL << data << " ";
 
        do {
            cout << "Vi pham[0;50]: ";
            cin >> data;
        } while (data < 0 || data > 50); 
        renluyen -= data;
        fpRL << data << " ";
        fpRL << renluyen << "\n";
 
        fpRL.close();
    }
 
    void docFileBDRL(FILE *file) { 
        ifstream myfile (_BDRL.c_str());
        int sodong=0;
        while (getline(myfile, line1)){
            _3.push_back(line1);
            sodong++;
        }
        myfile.close();
 
        file = fopen(_BDRL.c_str(), "r");
        
        while (fgets(line, N, file) != NULL) {
            sscanf(line, "%d %d %d %d %d %d %d ", &hocky, &hoctap, &kyluat, &xahoi, &congdong, &vipham, &tongdiem);
            _3HK.push_back(hocky);
        }
        fclose(file);
        
        for (int i = 0; i < sodong; i++) {
            for (int j = i+1; j < sodong; j++) {
                if (_3HK[j] < _3HK[i]) {
                    _3[j].swap(_3[i]);
                }
            }
        }
        
        ofstream fp;
        fp.open (_BDRL.c_str(), ios::out | ios::trunc);
        fp.seekp (0, ios::beg);
        for (int i = 0; i < sodong; i++) {
            fp << _3[i] << "\n";
        }
        fp.close();
        
        file = fopen(_BDRL.c_str(), "r");
        hienthiBDRL();
        int STT = 1;
        
        while (fgets(line, N, file) != NULL) {
            sscanf(line, "%d %d %d %d %d %d %d ", &hocky, &hoctap, &kyluat, &xahoi, &congdong, &vipham, &tongdiem);
            if (STT < sodong+1 && STT > 1) {cout << "|---------------------------------------------------------------------------------------------------|" << endl;}
            cout << "| " << left << setw(5) << STT << left << setw(20) << hocky << left << setw(12) << hoctap << left << setw(12) << kyluat;
            cout << left << setw(12) << xahoi << left << setw(14) << congdong;
            cout << left << setw(12) << vipham << left << setw(11) << tongdiem << "|" << endl;
            STT++;
        }
        cout <<(char)(192)<< "---------------------------------------------------------------------------------------------------"<<(char)(217) << endl;
        fclose(file);
        _3.clear();
        _3HK.clear();
    }
 
    void hienthiBDRL() {
        cout << endl;
        system("cls");
        cout <<(char)(218) <<"---------------------------------------------------------------------------------------------------" <<(char)(191) << endl;
        cout << "|" << right << setw(59) << "BANG DIEM REN LUYEN" << setw(41) << "|" << endl;
        cout << "|---------------------------------------------------------------------------------------------------|" << endl;
 
        cout << "|" << left << setw(6) << "STT" << left << setw(18) << "Hoc ky/Tieu chi" << left << setw(12) << "Hoc tap" << left << setw(12) << "Ky luat";
        cout << left << setw(11) << "Xa hoi" << left << setw(14) << "Cong dong";
        cout << left << setw(12) << "Vi pham" << left << setw(14) << "Tong diem" << "|" << endl;
        cout << "|---------------------------------------------------------------------------------------------------|" << endl;
 
    }
};
 
 
class HocBong {

private:
    int hocky, tinchi;
    float trongso, quatrinh, cuoiky, TBC;
    char hocphan[29], diemchu[14];

    int hoctap, kyluat, xahoi, congdong, vipham, tongdiem;
public:
 
    void docFileBDHT(FILE *file, int _hocky) { 
        ts = 0;
        dem = 0;
 
        file = fopen(_BDHT.c_str(), "r");
 
        while (fgets(line, N, file) != NULL) {
            sscanf(line, "%d %d %f %f %f %f %s %[^.]", &hocky, &tinchi, &trongso, &quatrinh, &cuoiky, &TBC, diemchu, hocphan);
            if (_hocky == hocky) {
                if (TBC >= 8.5 && TBC <= 10.0) ts += tinchi*4;
                if (TBC >= 8.0 && TBC < 8.5) ts += tinchi*3.5;
                if (TBC >= 7.0 && TBC < 8.0) ts += tinchi*3;
                if (TBC >= 6.5 && TBC < 7.0) ts += tinchi*2.5;
                if (TBC >= 5.5 && TBC < 6.5) ts += tinchi*2;
                if (TBC >= 5.0 && TBC < 5.5) ts += tinchi*1.5;
                if (TBC >= 4.0 && TBC < 5.0) ts += tinchi;
                else ts += tinchi*0;
 
                dem += tinchi;
            }
        } 
 
        GPA = ts/dem;
        fclose(file);
    }
    void docFileBDRL(FILE *file, int _hocky) { 
        diemRL = 0;
        
        file = fopen(_BDRL.c_str(), "r");
 
        while (fgets(line, N, file) != NULL) {
            sscanf(line, "%d %d %d %d %d %d %d ", &hocky, &hoctap, &kyluat, &xahoi, &congdong, &vipham, &tongdiem);
            if (_hocky == hocky) {
                diemRL = tongdiem;
            }
 
        }
        fclose(file);
    }
 
    void HB() {
        int hocky;
        do {
            system("cls");
            printLine(120);
            cout << "Thong tin hoc bong cua hoc ky: ";
            cin >> hocky;
        } while (hocky < 20000 || hocky > 30000);
 
        docFileBDHT(file, hocky);
        docFileBDRL(file, hocky);
        if (dem == 0) {
            cout << "Chua co thong tin cac mon hoc cua hoc ky " << hocky;
            Sleep(4000);
        }else if (diemRL == 0) {
            cout << "Chua co thong tin diem ren luyen cua hoc ky " << hocky;
            Sleep(4000);
        } else {
            
            cout << "GPA: " << GPA << endl;
            cout << "Diem ren luyen: " << diemRL << endl;
            cout << endl;
            if (GPA >= 3.6 && diemRL >= 90) {
                cout << "Ban co du dieu kien xet cap hoc bong loai A" << endl;
            } else if (GPA >= 3.2 && diemRL >= 80) {
                cout << "Ban co du dieu kien xet cap hoc bong loai B" << endl;
            } else if (GPA >= 2.5 && diemRL >= 65) {
                cout << "Ban co du dieu kien xet cap hoc bong loai C" << endl;
            } else {
                cout << "Ban chua co du dieu kien xet cap hoc bong" << endl;
            }
            Sleep(3000);
            cout << "Nhan phim Enter de tiep tuc...";
            fflush(stdin);
            cin.get();
        }
    }
};
 
 
class DanhSachMonHoc {

private:
    int hocky, kip, thu;
    char tenhocphan[30], ghichu[46];
    vector<string> _4;
    vector<int> _4HK, _4kip, _4thu;
public:
    
    int checkTHP(int _HK, string _THP) {
 
        file = fopen(_DSMH.c_str(), "r");
        
        while (fgets(line, N, file) != NULL) {
            sscanf(line, "%d %d %d %[^'] %[^.]", &hocky, &kip, &thu, ghichu, tenhocphan);
            string tenhocphan_;
            for (int i=2; i < strlen(tenhocphan); i++) {
                tenhocphan_ += tenhocphan[i];
            }
            if (hocky == _HK && strcmp(_THP.c_str(), tenhocphan_.c_str()) == 0) {
                cout << "Hoc phan nay da co trong danh sach\n";
                Sleep(2000);
                return 1;
            }
        }
 
        fclose(file);
        return 0;
    }
    void XOA(FILE *file, int n) {
        string sentence;
        printLine(120);  
 
        ifstream myfile (_DSMH.c_str());
        int sodong=0;
        while (getline(myfile, line1)){
            _4.push_back(line1);
            sodong++;
        }
        myfile.close();
        _4[n - 1] = "0";
 
        ofstream fp;
        fp.open (_DSMH.c_str(), ios::out | ios::trunc);
        fp.seekp (0, ios::beg);
        for (int i = 0; i < sodong; i++) {
            if (_4[i].compare("0") == 0) continue;
            else fp << _4[i] << "\n";
        }
 
        fp.close();
        _4.clear();
    }
    void docFileDSMH(FILE *file) { 
 
        ifstream myfile (_DSMH.c_str());
        int sodong=0;
        while (getline(myfile, line1)){
            _4.push_back(line1);
            sodong++;
        }
        myfile.close();
 
        file = fopen(_DSMH.c_str(), "r");
        
        while (fgets(line, N, file) != NULL) {
            sscanf(line, "%d %d %d %[^'] %[^.]", &hocky, &kip, &thu, ghichu, tenhocphan);
            _4HK.push_back(hocky);
            _4kip.push_back(kip);
            _4thu.push_back(thu);
        }
        fclose(file);
        
        for (int i = 0; i < sodong; i++) {
            for (int j = i+1; j < sodong; j++) {
                if (_4HK[j] < _4HK[i]) {
                    _4[j].swap(_4[i]);
                } else if (_4HK[j] == _4HK[i] && _4thu[j] < _4thu[i]) {
                    _4[j].swap(_4[i]);
                } else if (_4HK[j] == _4HK[i] && _4thu[j] == _4thu[i] && _4kip[j] < _4kip[i]) {
                    _4[j].swap(_4[i]);
                }
            }
        }
        ofstream fp;
        fp.open (_DSMH.c_str(), ios::out | ios::trunc);
        fp.seekp (0, ios::beg);
        for (int i = 0; i < sodong; i++) {
            fp << _4[i] << "\n";
        }
        fp.close();   
 
        file = fopen(_DSMH.c_str(), "r");
        hienthiDSMH();
        int STT=1;
        int z;
        while (fgets(line, N, file) != NULL) {
            sscanf(line, "%d %d %d %[^']%[^.]", &hocky, &kip, &thu, ghichu, tenhocphan);
            string tenhocphan_;
            for (int i=2; i < strlen(tenhocphan); i++) {
                tenhocphan_ += tenhocphan[i];
            }
            if (STT == 1) {z = hocky;}
            else if (z != hocky) {
                cout << "|-----------------------------------------------------------------------------------------------------------|" << endl;
                z = hocky;
            }
            cout << "| " << left << setw(6) << STT << left << setw(10) << hocky << left << setw(31) << tenhocphan_ ;
            cout << left << setw(7) << kip << left << setw(6) << thu << left << setw(46) << ghichu << "|" << endl;
            STT++;
        }
        cout <<(char)(192)<< "-----------------------------------------------------------------------------------------------------------"<<(char)(217) << endl;
        fclose(file);
        _4.clear();
        _4kip.clear();
        _4thu.clear();
        _4HK.clear();
    }
    
    void ghiFileDSMH(FILE *file) {
        int data, b, renluyen = 0; 
        string THP, ghichu;
        
        do {
            printLine(120);
            cout << "Hoc ky: ";
            cin >> data;
            if (data < 20000 || data > 30000) {
                cout << "Du lieu hoc ky khong hop le\n";
                Sleep(2000);
                continue;
            }
            cout << "Ten hoc phan: ";
            fflush(stdin);
            getline(cin, THP);
 
            b = checkTHP(data, THP);
        } while (data < 20000 || data > 30000 || b == 1);
 
        ofstream fpDSMH;
        fpDSMH.open (_DSMH.c_str(), ios::app);
        fpDSMH << data << " ";
 
        cout << "Kip: ";
        cin >> data;
        fpDSMH << data << " ";
 
        cout << "Thu: ";
        cin >> data;
        fpDSMH << data << " ";
 
        cout << "Ghi chu: ";
        fflush(stdin);
        getline(cin, ghichu);
 
        fpDSMH << ghichu << "' ";
        fpDSMH << THP << ".\n";
        fpDSMH.close();
    }
 
    void hienthiDSMH() {
 
        cout << endl;
        system("cls");
        cout <<(char)(218) <<"-----------------------------------------------------------------------------------------------------------" <<(char)(191) << endl;
        cout << "|" << right << setw(63) << "DANH SACH MON HOC" << setw(45) << "|" << endl;
        cout << "|-----------------------------------------------------------------------------------------------------------|" << endl;
        cout << "|" << left << setw(7) << "STT" << left << setw(10) << "Hoc ky" << left << setw(30) << "Ten hoc phan" ;
        cout << left << setw(7) << "Kip" << left << setw(7) << "Thu" << left << setw(46) << "Ghi chu" << "|" << endl;
        cout << "|-----------------------------------------------------------------------------------------------------------|" << endl;
 
    }
 
 
};
 
 
class LichThi {

private:
    vector<string> _6;
    vector<int> _6ngay, _6thang, _6nam, _6KT, g;
    string ngay, thang, nam;
    int _ngay, _thang, _nam;

    int kipthi, malopthi;
    char hinhthuc[30];
    char tenhocphan[30], mahocphan[30], ngaythi[30], diadiem[30];
        
public:
    
    void Ngaythi(string ngaythi) {
        ngay = "";
        thang = "";  
        nam = "";
        
        for (int i = 0;i<10;i++) {
            if (ngaythi[i] == '/') g.push_back(i);
        }
        
        if (g[0] == 2 && g[1] == 5) {
            if (ngaythi[0] == 0) {ngay = ngaythi[1];}
            else {
                ngay += ngaythi[0];
                ngay += ngaythi[1];
            }
            if (ngaythi[3] == 0) {thang = ngaythi[4];}
            else {
                thang += ngaythi[3];
                thang += ngaythi[4];
            }
            nam += ngaythi[6];
            nam += ngaythi[7];
            nam += ngaythi[8];
            nam += ngaythi[9];
        }
        
        if (g[0] == 2 && g[1] == 4) {
            ngay += ngaythi[0];
            ngay += ngaythi[1];
            thang = ngaythi[3];
            nam += ngaythi[5];
            nam += ngaythi[6];
            nam += ngaythi[7];
            nam += ngaythi[8];
            
        }
        if (g[0] == 1 && g[1] == 4) {
            ngay = ngaythi[0];
            thang += ngaythi[2];
            thang += ngaythi[3];
            nam += ngaythi[5];
            nam += ngaythi[6];
            nam += ngaythi[7];
            nam += ngaythi[8];
            
        }
        if (g[0] == 1 && g[1] == 3) {
            ngay = ngaythi[0];
            thang = ngaythi[2];
            nam += ngaythi[4];
            nam += ngaythi[5];
            nam += ngaythi[6];
            nam += ngaythi[7];    
        }
        _ngay = atoi(ngay.c_str());
        _thang = atoi(thang.c_str());
        _nam = atoi(nam.c_str());
 
        g.clear();
    }
    int tinhNgay(int ngay, int thang, int nam) {
        if (nam < 1900+ltm->tm_year) {
            return -1;
        } else if (nam == 1900+ltm->tm_year && thang < 1+ltm->tm_mon) {
            return -1;
        } else if (nam == 1900+ltm->tm_year && thang == 1+ltm->tm_mon && ngay < ltm->tm_mday) {
            return -1;
        } else if (nam == 1900+ltm->tm_year && thang == 1+ltm->tm_mon && ngay == ltm->tm_mday) {
            return 0;
        } else if (nam == 1900+ltm->tm_year && thang == 1+ltm->tm_mon && ngay > ltm->tm_mday) {
            return (ngay - ltm->tm_mday);
        } else if (nam == 1900+ltm->tm_year && thang > 1+ltm->tm_mon) {
            int x;
            if ((1900+ltm->tm_year) % 4 == 0) {
                if (1+ltm->tm_mon == 1) x = 31 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 2) x = 29 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 3) x = 31 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 4) x = 30 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 5) x = 31 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 6) x = 30 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 7) x = 31 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 8) x = 31 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 9) x = 30 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 10) x = 31 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 11) x = 30 - (1+ltm->tm_mday) + 1;
 
                for (int i = 2+ltm->tm_mon; i < thang; i++) {
                    if (i == 2) x += 29;
                    if (i == 3) x += 31;
                    if (i == 4) x += 30;
                    if (i == 5) x += 31;
                    if (i == 6) x += 30;
                    if (i == 7) x += 31;
                    if (i == 8) x += 31;
                    if (i == 9) x += 30;
                    if (i == 10) x += 31;
                    if (i == 11) x += 30;
                }
 
                x += ngay;
                return x;
            }
            if ((1900+ltm->tm_year) % 4 != 0) {
                if (1+ltm->tm_mon == 1) x = 31 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 2) x = 28 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 3) x = 31 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 4) x = 30 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 5) x = 31 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 6) x = 30 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 7) x = 31 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 8) x = 31 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 9) x = 30 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 10) x = 31 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 11) x = 30 - (1+ltm->tm_mday) + 1;
        
                for (int i = 2+ltm->tm_mon; i < thang; i++) {
                    if (i == 2) x += 28;
                    if (i == 3) x += 31;
                    if (i == 4) x += 30;
                    if (i == 5) x += 31;
                    if (i == 6) x += 30;
                    if (i == 7) x += 31;
                    if (i == 8) x += 31;
                    if (i == 9) x += 30;
                    if (i == 10) x += 31;
                    if (i == 11) x += 30;
                }
 
                x += ngay;
                return x;
            }
        } else if (nam > 1900+ltm->tm_year) {
            int x;
            if ((1900+ltm->tm_year) % 4 != 0 && nam % 4 != 0) {
                if (1+ltm->tm_mon == 1) x = 31 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 2) x = 28 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 3) x = 31 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 4) x = 30 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 5) x = 31 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 6) x = 30 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 7) x = 31 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 8) x = 31 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 9) x = 30 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 10) x = 31 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 11) x = 30 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 12) x = 31 - (1+ltm->tm_mday) + 1;
 
                for (int i = 2+ltm->tm_mon; i < thang+12; i++) {
                    if (i == 2 || i == 14) x += 28;
                    if (i == 3 || i == 15) x += 31;
                    if (i == 4 || i == 16) x += 30;
                    if (i == 5 || i == 17) x += 31;
                    if (i == 6 || i == 18) x += 30;
                    if (i == 7 || i == 19) x += 31;
                    if (i == 8 || i == 20) x += 31;
                    if (i == 9 || i == 21) x += 30;
                    if (i == 10 || i == 22) x += 31;
                    if (i == 11 || i == 23) x += 30;
                    if (i == 12) x += 31;
                    if (i == 13) x += 31;
                }
 
                x += ngay;
                return x;
            }
            if ((1900+ltm->tm_year) % 4 != 0 && nam % 4 == 0) {
                if (1+ltm->tm_mon == 1) x = 31 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 2) x = 29 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 3) x = 31 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 4) x = 30 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 5) x = 31 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 6) x = 30 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 7) x = 31 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 8) x = 31 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 9) x = 30 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 10) x = 31 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 11) x = 30 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 12) x = 31 - (1+ltm->tm_mday) + 1;
 
                for (int i = 2+ltm->tm_mon; i < thang+12; i++) {
                    if (i == 2) x += 29;
                    if (i == 3 || i == 15) x += 31;
                    if (i == 4 || i == 16) x += 30;
                    if (i == 5 || i == 17) x += 31;
                    if (i == 6 || i == 18) x += 30;
                    if (i == 7 || i == 19) x += 31;
                    if (i == 8 || i == 20) x += 31;
                    if (i == 9 || i == 21) x += 30;
                    if (i == 10 || i == 22) x += 31;
                    if (i == 11 || i == 23) x += 30;
                    if (i == 12) x += 31;
                    if (i == 13) x += 31;
                    if (i == 14) x += 28;
                }
 
                x += ngay;
                return x;
            }
            if ((1900+ltm->tm_year) % 4 == 0 && nam % 4 != 0) {
                if (1+ltm->tm_mon == 1) x = 31 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 2) x = 28 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 3) x = 31 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 4) x = 30 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 5) x = 31 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 6) x = 30 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 7) x = 31 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 8) x = 31 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 9) x = 30 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 10) x = 31 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 11) x = 30 - (1+ltm->tm_mday) + 1;
                if (1+ltm->tm_mon == 12) x = 31 - (1+ltm->tm_mday) + 1;
 
                for (int i = 2+ltm->tm_mon; i < thang+12; i++) {
                    if (i == 2 || i == 14) x += 28;
                    if (i == 3 || i == 15) x += 31;
                    if (i == 4 || i == 16) x += 30;
                    if (i == 5 || i == 17) x += 31;
                    if (i == 6 || i == 18) x += 30;
                    if (i == 7 || i == 19) x += 31;
                    if (i == 8 || i == 20) x += 31;
                    if (i == 9 || i == 21) x += 30;
                    if (i == 10 || i == 22) x += 31;
                    if (i == 11 || i == 23) x += 30;
                    if (i == 12) x += 31;
                    if (i == 13) x += 31;
                }
 
                x += ngay;
                return x;
            }
        }
    }
 
    int checkLT(string _tenhocphan, string _mahocphan) {
        
        file = fopen(_LT.c_str(), "r");
        
        while (fgets(line, N, file) != NULL) {
            sscanf(line, "%s %d %d %s %s %s %[^.]", mahocphan, &malopthi, &kipthi, ngaythi, hinhthuc, diadiem, tenhocphan);
            if (strcmp(tenhocphan, _tenhocphan.c_str()) == 0 && strcmp(mahocphan, _mahocphan.c_str()) == 0) {
                cout << "Hoc phan nay da co trong lich thi\n";
                Sleep(2000);
                return 1;
            } 
        }
 
        fclose(file);
        return 0;
    }
    void XOA(FILE *file, int n) {
        string sentence;
        printLine(120);  
 
        ifstream myfile (_LT.c_str());
        int sodong=0;
        while (getline(myfile, line1)){
            _6.push_back(line1); //doc va luu tung dong vao vector
            sodong++;
        }
        myfile.close();
        _6[n - 1] = "0"; //gan gia tri can xoa bang 0
        ofstream fp;
        fp.open (_LT.c_str(), ios::out | ios::trunc);
        fp.seekp (0, ios::beg);
        for (int i = 0; i < sodong; i++) {
            if (_6[i].compare("0") == 0) continue; //phan tu can xoa ko duoc ghi lai vao file
            else {
                fp << _6[i] << "\n"; //ghi vao file
            }
        }
        fp.close();
        _6.clear();
    
    }
    void ghiFileLT() {
        
        int _nhap1, b, renluyen = 0; 
        string _nhap, _nhapten;
        
        do {
            printLine(120);
            cout << "Ten hoc phan: ";
            fflush(stdin);
            getline(cin, _nhapten);
            cout << "Ma hoc phan: ";
            fflush(stdin);
            getline(cin, _nhap);
            b = checkLT(_nhapten, _nhap);
        } while (b == 1);
 
        ofstream fpLT;
        fpLT.open (_LT.c_str(), ios::app);
        fpLT << _nhap << " ";
 
        cout << "Ma lop thi: ";
        cin >> _nhap1;
        fpLT << _nhap1 << " ";
 
        do {
            cout << "Kip thi: ";
            fflush(stdin);
            cin >> _nhap1;
        } while (_nhap1 < 1 || _nhap1 > 5); 
        fpLT << _nhap1 << " ";
 
        cout << "Ngay thi: ";
        fflush(stdin);
        getline(cin, _nhap);
        fpLT << _nhap << " ";
 
        // int conlai;
        // Ngaythi(_nhap);
        // conlai = tinhNgay(_ngay, _thang, _nam);
        // fpLT << conlai << " ";
 
        do {
            cout << "Hinh thuc thi: 1.Online\t2.Offline" << endl;
            cout << "Ban chon ? ";
            cin >> b;
            if (b == 1) fpLT << "Online ";
            if (b == 2) fpLT << "Offline ";
        } while(b != 1 && b != 2);
 
        cout << "Dia diem: ";
        fflush(stdin);
        getline(cin, _nhap);
        fpLT << _nhap << " " << _nhapten << ".\n";
 
        fpLT.close();
    }
 
    void docFileLT() {
        
        do {
            ifstream myfile (_LT.c_str());
            int sodong=0;
            while (getline(myfile, line1)){
                _6.push_back(line1);         //doc va luu tung dong vao vector
                sodong++;
            }
            myfile.close();
 
            file = fopen(_LT.c_str(), "r");
    
            while (fgets(line, N, file) != NULL) {
                
                sscanf(line, "%s %d %d %s %s %s %[^.]", mahocphan, &malopthi, &kipthi, ngaythi, hinhthuc, diadiem, tenhocphan);
                
                Ngaythi((string)ngaythi);
                _6ngay.push_back(_ngay);
                _6thang.push_back(_thang);
                _6nam.push_back(_nam);
                _6KT.push_back(kipthi);
                
            }
            fclose(file);
        
            for (int i = 0; i < sodong-1; i++) {
                for (int j = i+1; j < sodong; j++) {
                    if (_6nam[j] < _6nam[i]) {
                        _6[i].swap(_6[j]);
                    }
                    else if (_6nam[j] == _6nam[i] && _6thang[j] < _6thang[i]) {
                        _6[i].swap(_6[j]);
                    }
                    else if (_6nam[j] == _6nam[i] && _6thang[j] == _6thang[i] && _6ngay[j] < _6ngay[i]) {
                        _6[i].swap(_6[j]);
                    }
                    else if (_6nam[j] == _6nam[i] && _6thang[j] == _6thang[i] && _6ngay[j] == _6ngay[i] && _6KT[j] < _6KT[i]) {
                        _6[i].swap(_6[j]);
                    }
                }
            }
        
            ofstream fp;
            fp.open (_LT.c_str(), ios::out | ios::trunc);
            fp.seekp (0, ios::beg);
            for (int i = 0; i < sodong; i++) {
                fp << _6[i] << "\n";
            }
            fp.close();
 
            file = fopen(_LT.c_str(), "r");
            hienthiLT();
            int STT=1, k=0;     
            vector<string> monthi;                              //in ra man hinh bang diem hoc tap
            while (fgets(line, N, file) != NULL) {
                sscanf(line, "%s %d %d %s %s %s %[^.]", mahocphan, &malopthi, &kipthi, ngaythi, hinhthuc, diadiem, tenhocphan);
                
                int conlai;
                Ngaythi((string)ngaythi);
                conlai = tinhNgay(_ngay, _thang, _nam);
                if (conlai == 0) {
                    k++;
                    monthi.push_back((string)tenhocphan);
                }
                cout << "| " << left << setw(7) << STT << left << setw(26) << tenhocphan << left << setw(14) << mahocphan; 
                cout << left << setw(13) << malopthi;
                if (conlai == -1) {cout << left << setw(11) << "Qua";}
                else if (conlai > 366) {cout << left << setw(11) << ">1nam";}
                else if (_nam - 1900 - ltm->tm_year >= 2) {cout << left << setw(11) << ">1nam";}
                else if (conlai != -1 && conlai < 366) {cout << left << setw(11) << conlai;}
                cout << left << setw(7) << kipthi << left << setw(14) << ngaythi;
                cout << left << setw(13) << hinhthuc << left << setw(11) << diadiem << "|" << endl;
                STT++;
            }   
            if (k != 0) {
                cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
                for (int i = 0; i < k; i++) {
                    cout << left << setw(30) << "| Hom nay la ngay thi cua mon " << left << setw(87) << monthi[i] << " |" << endl;
                }
            }
            cout <<(char)(192)<< "---------------------------------------------------------------------------------------------------------------------"<<(char)(217) << endl;
            cout << "1.Them\t\t2.Xoa\t\t3.Quay lai" << endl;
            cout << "Ban chon ? ";
            if ( kbhit() ) { 
                fflush(stdin);
                c = getch();
                cout << endl;
                if ((int)c == 49) {
                    u = 1;
                    _6.clear();
                    monthi.clear();
                    _6ngay.clear();
                    _6thang.clear();
                    _6nam.clear();
                    _6KT.clear();
                    break;
                } else if ((int)c == 50) {
                    u = 2; 
                    _6.clear();
                    monthi.clear();
                    _6ngay.clear();
                    _6thang.clear();
                    _6nam.clear();
                    _6KT.clear();
                    break;
                }
                else if ((int)c == 51) {
                    u = 3;
                    _6.clear();
                    monthi.clear();
                    _6ngay.clear();
                    _6thang.clear();
                    _6nam.clear();
                    _6KT.clear();
                    break;
                }
            }
            Sleep(1000);
            fclose(file);
 
            _6.clear();
            monthi.clear();
            _6ngay.clear();
            _6thang.clear();
            _6nam.clear();
            _6KT.clear();
        } while (1);
    }
 
    void hienthiLT() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        system("cls");
        cout <<(char)(218) <<"---------------------------------------------------------------------------------------------------------------------" <<(char)(191) << endl;
        cout << "|" << right << setw(64) << "LICH THI" << right << setw(54) << "|" << endl;
        cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
                
        cout << "| TIME:" << right << setw(25) << ltm->tm_hour << ":"  << left << setw(2); 
        cout << ltm->tm_min << ":"  << left << setw(2) << ltm->tm_sec << right << setw(24) << "|";
        cout << " DAY:" <<right << setw(22) << ltm->tm_mday << "/" << left << setw(2)  << 1 + ltm->tm_mon;
        cout << "/"  << left << setw(2) << 1900 + ltm->tm_year << right << setw(22) << "|" << endl;
        cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
        
        cout << "|" << left << setw(8) << "STT" << left << setw(24) << "Ten hoc phan" << left << setw(14) << "Ma hoc phan" << left << setw(15) << "Ma lop thi";
        cout << left << setw(8) << "Con" << left << setw(10) << "Kip thi" << left << setw(13) << "Ngay thi";
        cout << left << setw(13) << "Hinh thuc" << left << setw(12) << "Dia diem" << "|" << endl;
        cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
 
 
    }
};


void XinChao(string taikhoan) {
    ifstream in(TTCN.c_str());
    in.seekg(0, ios::end);
    int spot = in.tellg();
    if( spot == 0)
    {
        cout << "|" << right << setw(29) << "Xin chao sinh vien " << left << setw(25) << taikhoan << right << setw(4) << "|" << endl;
        in.close();
    } else {
        ifstream myfile (TTCN.c_str());
        getline(myfile, line1);
        myfile.close();
        cout << "|" << right << setw(29) << "Xin chao sinh vien " << left << setw(25) << line1 << right << setw(4) << "|" << endl;
    }
}
 
int HOME() {
    int C=0;
    cout << endl;
    system("cls");
    cout <<(char)(218) <<"---------------------------------------------------------" <<(char)(191) << endl;
    cout << "|             HE THONG QUAN LY HOC TAP CA NHAN            |" << endl;
    cout << "|                                                         |" << endl;
    XinChao(taikhoan);
    cout << "|---------------------------------------------------------|" << endl;
    cout << "|             1-Thong tin ca nhan                         |" << endl;
    cout << "|---------------------------------------------------------|" << endl;
    cout << "|             2-Bang diem hoc tap                         |" << endl;
    cout << "|---------------------------------------------------------|" << endl;
    cout << "|             3-Bang diem ren luyen                       |" << endl;
    cout << "|---------------------------------------------------------|" << endl;
    cout << "|             4-Danh sach mon hoc                         |" << endl;
    cout << "|---------------------------------------------------------|" << endl;
    cout << "|             5-Hoc bong                                  |" << endl;
    cout << "|---------------------------------------------------------|" << endl;
    cout << "|             6-Lich thi                                  |" << endl;
    cout << "|---------------------------------------------------------|" << endl;
    cout << "|             7-Dong ho Pomodoro                          |" << endl;
    cout << "|---------------------------------------------------------|" << endl;
    cout << "|             8-Dang xuat                                 |" << endl;
    cout <<(char)(192)<< "---------------------------------------------------------"<<(char)(217) << endl;
    cout << "Ban chon ? ";
    cin >> C;
    return C;
}
 
 
int main() {
    LOGIN ACC;
    ThongTinCaNhan SV;
    BangDiemHoctap BDHT;
    struct BangDiemHoctap::BDHT bdht;
    BangDiemRenLuyen BDRL;
    DanhSachMonHoc DSMH;
    HocBong HB;
    LichThi LT;
 
LOGIN:
    int choose;
    do {
        choose = MENU();
 
        switch (choose)
        {
        case 1:
            ACC.SignInAccount();
            if (a == 1) continue;
            goto HOME;
 
        case 2:
            ACC.SignUpAccount();
            continue;
 
        case 3:
            if (ACC.showForgetPass() == 1) {
                cout << "Nhan phim Enter de tiep tuc...";
                cin.get();
                continue;
            } else {
                cout << "Tai khoan nay chua duoc dang ky. Vui long chon tai khoan khac" << endl;
                Sleep(2000);
                continue;   
            }
        case 4:
            exit(1);
            break;
 
        default:
            cout << "Sai chuc nang. Vui long lua chon lai";
            continue;
        }
    } while (1);
HOME:
 
    do {
        choose = HOME();
        switch(choose)
        {
            case 1:
                if (checkEmptyFile(TTCN) == 1) {
                    printLine(120);
                    cout << "Ban co muon cap nhat thong tin ca nhan khong?" << endl;
                    cout << "1. Co\t2. Khong" << endl;
                    cout << "Ban chon ? "; 
                    cin >> i;
                    if (i == 1) {
                        SV.ghiFileSV(file); 
                        cout << "Ban da cap nhat thong tin ca nhan thanh cong...";
                        Sleep(2000);
                    } 
                    break;
                } else {
                    SV.docFile();
 
                    cout << "1.Chinh sua mot thong tin\t2.Chinh sua tat ca\t3.Quay lai" << endl;
                    cout << "Ban chon ? "; 
                    cin >> i;
 
                    if ((int)i == 2) {
                        printLine(120);
                        SV.ghiFileSV(file);   
                        cout << "Ban da cap nhat thong tin ca nhan thanh cong...";
                        Sleep(2000);
                    }
                    if ((int)i == 1) {
                        int x;
                        printLine(120);
                        cout << "Ban muon sua thong tin so bao nhieu ? ";
                        cin >> x;
                        SV.ghi(file, x);
                        cout << "Ban da cap nhat thong tin ca nhan thanh cong...";
                        Sleep(2000);
                    } else {
                        goto HOME;
                    }
                }    
                break;
            case 2:
                if (checkEmptyFile(_BDHT) == 1) {
                    printLine(120);
                    cout << "Ban co muon cap nhat bang diem hoc tap khong?" << endl;
                    cout << "1. Co\t2. Khong" << endl;
                    cout << "Ban chon ? "; 
                    cin >> i;
 
                    if ((int)i == 1) {
                        printLine(120);
                        bdht = BDHT.nhapBD();
                        BDHT.ghiFileBDHT(file, bdht);
                        cout << "Ban da cap nhat bang diem hoc tap thanh cong...";
                        Sleep(2000);    
                    }
                break;
                } else {
                    BDHT.docFileBDHT(file);
                    
                    cout << "1.Them hoc phan\t\t2.Xoa hoc phan\t\t3.Quay lai" << endl;
                    cout << "Ban chon ? "; 
                    cin >> i;
 
                    if ((int)i == 1) {
                        printLine(120);
                        bdht = BDHT.nhapBD();
                        BDHT.ghiFileBDHT(file, bdht);  
                        cout << "Ban da cap nhat bang diem hoc tap thanh cong...";
                        Sleep(2000);  
                    }
                    if ((int)i == 2) {
                        int x;
                        printLine(120);
                        cout << "Ban muon xoa hoc phan so bao nhieu ? ";
                        cin >> x;
                        BDHT.XOA(file, x);
                        cout << "Ban da cap nhat bang diem hoc tap thanh cong...";
                        Sleep(2000);
                    }
                    if ((int)i == 3) {
                        goto HOME;
                    }
                }
                break;
            case 3:
                if (checkEmptyFile(_BDRL) == 1) {
                    printLine(120);
                    cout << "Ban co muon cap nhat bang diem ren luyen khong?" << endl;
                    cout << "1. Co\t2. Khong" << endl;
                    cout << "Ban chon ? "; 
                    cin >> i;
 
                    if ((int)i == 1) {
                        BDRL.ghiFileBDRL(file);
                        cout << "Ban da cap nhat bang diem ren luyen thanh cong...";
                        Sleep(2000);    
                    }
                break;
                } else {
                    BDRL.docFileBDRL(file);
                    
                    cout << "1.Them\t\t2.Xoa\t\t3.Quay lai" << endl;
                    cout << "Ban chon ? "; 
                    cin >> i;
 
                    if ((int)i == 1) {
                        BDRL.ghiFileBDRL(file);
                        cout << "Ban da cap nhat bang diem ren luyen thanh cong...";
                        Sleep(2000);  
                    }
                    if ((int)i == 2) {
                        int x;
                        printLine(120);
                        cout << "Ban muon xoa hoc hoc ky nao (Nhap STT) ? ";
                        cin >> x;
                        BDRL.XOA(file, x);
                        cout << "Ban da cap nhat bang diem ren luyen thanh cong...";
                        Sleep(2000);  
                    }
                    if ((int)i == 3) {
                        goto HOME;
                    }
                    
                }
                break;
            case 4:
                if (checkEmptyFile(_DSMH) == 1) {
                    printLine(120);
                    cout << "Ban co muon cap nhat danh sach mon hoc khong?" << endl;
                    cout << "1. Co\t2. Khong" << endl;
                    cout << "Ban chon ? "; 
                    cin >> i;
 
                    if ((int)i == 1) {
                        DSMH.ghiFileDSMH(file);
                        cout << "Ban da cap nhat danh sach mon hoc thanh cong...";
                        Sleep(2000);    
                    }
                break;
                } else {
                    DSMH.docFileDSMH(file);
                    
                    cout << "1.Them\t\t2.Xoa\t\t3.Quay lai" << endl;
                    cout << "Ban chon ? "; 
                    cin >> i;
 
                    if ((int)i == 1) {
                        DSMH.ghiFileDSMH(file);
                        cout << "Ban da cap nhat danh sach mon hoc thanh cong...";
                        Sleep(2000);  
                    }
                    if ((int)i == 2) {
                        int x;
                        printLine(120);
                        cout << "Ban muon xoa hoc phan nao (Nhap STT) ? ";
                        cin >> x;
                        DSMH.XOA(file, x);
                        cout << "Ban da cap nhat danh sach mon hoc thanh cong...";
                        Sleep(2000);  
                    }
                    if ((int)i == 3) {
                        goto HOME;
                    }
                }
                break;
            case 5:
                HB.HB();
                break;
            case 6:
                if (checkEmptyFile(_LT) == 1) {
                    printLine(120);
                    cout << "Ban co muon cap nhat lich thi khong?" << endl;
                    cout << "1. Co\t2. Khong" << endl;
                    cout << "Ban chon ? "; 
                    cin >> i;
 
                    if ((int)i == 1) {
                        LT.ghiFileLT();
                        cout << "Ban da cap nhat lich thi thanh cong...";
                        Sleep(2000);    
                    }
                break;
                } else {
                    LT.docFileLT();
 
                    if (u == 1) {
                        LT.ghiFileLT();
                        cout << "Ban da cap nhat lich thi thanh cong...";
                        Sleep(2000);  
                    }
                    if (u == 2) {
                        int x;
                        printLine(120);
                        cout << "Ban muon xoa hoc phan nao (Nhap STT) ? ";
                        cin >> x;
                        LT.XOA(file, x);
                        cout << "Ban da cap nhat lich thi thanh cong...";
                        Sleep(2000);  
                    }
                    if (u == 3) {
                        goto HOME;
                    }
                }
                break;
            case 7:
                do {
                    if (_Clock() == 1) {
                        break;
                    }
                } while (Clock() == 0);
                break;
            case 8:
                goto LOGIN;
                break;
            default:
                cout << "Sai chuc nang. Vui long lua chon lai";
                Sleep(2000);
                goto HOME;
 
        }
    } while ((int)choose != 8);
    return 0;
}