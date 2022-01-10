
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


using namespace std;

#define N 256

const char *fileLogin = "D:/code/Login.txt";

string taikhoan;
string TK;
string matkhau;
string LINE;
string line1;
string TTCN, _BDHT, BDRL, DSMH;
vector<string> lines;


char line[N];

int i, a=0;

FILE* file;

void printLine(int n) {
    for (int i = 0; i < n; i++) {
        cout << "-";
    }
    cout << endl;
}
void copyName(string xau) {
    TTCN = xau; 
    _BDHT = xau;
    BDRL = xau; 
    DSMH = xau;
    TTCN += "_thongtincanhan.txt";
    _BDHT += "_bangdiemhoctap.txt";
    BDRL += "_bangdiemrenluyen.txt";
    DSMH += "_danhsachmonhoc.txt";
}

void taoFile(string TK) {
    // TK = TK += ".txt";
    ofstream file1;
    file1.open (TK);
}

void checkFile(string namefile) {
    char path[30];
    for(int i = 0; i<namefile.size(); i++){
            path[i]=namefile[i];
        }
    path[namefile.size()] = '\0';

    if (access(path, 0) == 1) {
        taoFile(namefile);
    }
}
int checkEmptyFile(string namefile) {
    ifstream in(namefile);
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

void showLogin(string ID,int sizeofPass){
    string S;
    cout << endl;
    system("cls");
    for(int i = 0; i<sizeofPass; i++){
        S += "*";
    }
    cout << (char)(218) <<"--------------------------------------------"<<(char)(191) << endl;;
    cout << "|Username:"<<left << setw(35) << ID <<"|" << endl;
    cout << "|--------------------------------------------|" << endl;
    cout << "|Password:"<<left << setw(35) << S <<"|" << endl;
    cout << "|--------------------------------------------|" << endl;
    cout << "|Press (Esc) to exit                         |" << endl;
    cout << (char)(192)<<"--------------------------------------------"<<(char)(217) << endl;
}

void showRegister(string ID,int sizeofPass,int sizeofRePass){
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
    cout << "|Username   :"<<left << setw(35) << ID <<"|" << endl;
    cout << "|-----------------------------------------------|" << endl;
    cout << "|Password   :"<<left << setw(35) << S <<"|" << endl;
    cout << "|-----------------------------------------------|" << endl;
    cout << "|Re-Password:"<<left << setw(35) << SS <<"|" << endl;
    cout << "|-----------------------------------------------|" << endl;
    cout << "|Press (Esc) to exit                            |" << endl;
    cout << (char)(192)<<"-----------------------------------------------"<<(char)(217) << endl;

}

int MENU(){
    int C=0;
    cout << endl;
    system("cls");
    cout <<(char)(218) <<"------------------------------------------" <<(char)(191) << endl;
    cout << "|             Login or register            |" << endl;
    cout << "|------------------------------------------|" << endl;
    cout << "|             1-Login                      |" << endl;
    cout << "|------------------------------------------|" << endl;
    cout << "|             2-Register                   |" << endl;
    cout << "|------------------------------------------|" << endl;
    cout << "|             3-Forgot-Password            |" << endl;
    cout << "|------------------------------------------|" << endl;
    cout << "|             4-Exit                       |" << endl;
    cout <<(char)(192)<< "------------------------------------------"<<(char)(217) << endl;
    cout << "Your choice: ";
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
    // void taoFile(string TK) {
    //     // TK = TK += ".txt";
    //     ofstream file1;
    //     file1.open (TK);
    // }
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
                // importSignUpAccount();
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
                    cout << tmpUsername << "\n" << tmpPassword << endl;
                    // taoFile((string)tmpUsername);
                    TK = (string)tmpUsername;
                    copyName(TK);
                    taoFile(TTCN);
                    taoFile(_BDHT);
                    taoFile(BDRL);
                    taoFile(DSMH);
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
                cout << "Login successfull";
                TK = (string)tmpUsername;
                copyName(TK);
                // checkFile(TTCN);
                // checkFile(_BDHT);
                // checkFile(BDRL);
                // checkFile(DSMH);
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
                cout << "|Username:"<<left << setw(35) << username <<"|" << endl;
                cout << "|--------------------------------------------|" << endl;
                cout << "|Password:"<<left << setw(35) << password <<"|" << endl;
                cout << (char)(192)<<"--------------------------------------------"<<(char)(217) << endl;        
                fclose(file);
                return 1;
            }  
        }
        return 0;
    }
   
};

class ThongTinCaNhan {
public:
    void docFile(string taikhoan) {
        int i;
        taikhoan = taikhoan += "_thongtincanhan.txt";
        // taoFile(taikhoan);
        cout << endl;
        system("cls");
        cout <<(char)(218) <<"------------------------------------------------------------" <<(char)(191) << endl;
        cout << "|                      THONG TIN CA NHAN                     |" << endl;
        cout << "|------------------------------------------------------------|" << endl;
        ifstream myfile ((string)taikhoan);
        
        while (getline(myfile, line1)){
            lines.push_back(line1);//Lưu từng dòng như một phần tử vào vector lines.
        }

        for (int i=0; i<=7; i++) {
            if (i == 0) cout << "|Ho va ten: "<<left << setw(49) << lines[i] <<"|" << endl;
            if (i == 1) cout << "|Ngay sinh: "<<left << setw(49) << lines[i] <<"|" << endl;
            if (i == 2) cout << "|Gioi tinh: "<<left << setw(49) << lines[i] <<"|" << endl;
            if (i == 3) cout << "|Ma so sinh vien: "<<left << setw(43) << lines[i] <<"|" << endl;
            if (i == 4) cout << "|Nam vao hoc: "<<left << setw(47) << lines[i] <<"|" << endl;
            if (i == 5) cout << "|Lop: "<<left << setw(55) << lines[i] <<"|" << endl;
            if (i == 6) cout << "|Chuong trinh dao tao: "<<left << setw(38) << lines[i] <<"|" << endl;
            if (i == 7) cout << "|Email: "<<left << setw(53) << lines[i] <<"|" << endl;
            if (i != 7) cout << "|------------------------------------------------------------|" << endl;
        }
        cout <<(char)(192)<< "------------------------------------------------------------"<<(char)(217) << endl;
        lines.clear();
        
    }

    void ghiFileSV(FILE *file, string taikhoan) {
        string sentence;
        taikhoan += "_thongtincanhan.txt";
        printLine(120);  

        ofstream fpInfo;
        fpInfo.open (taikhoan, ios::out | ios::trunc);
        fpInfo.seekp (0, ios::beg);
        cout << "Ho va ten: ";
        // fpInfo << "Ho va ten: ";
        fflush(stdin);
        getline(cin, sentence);
        fpInfo << sentence;

        cout << "Ngay sinh: ";
        fpInfo << "\n"; //Ngay sinh: 
        fflush(stdin);
        getline(cin, sentence);
        fpInfo << sentence;

        cout << "Gioi tinh: ";
        fpInfo << "\n"; //Gioi tinh: 
        fflush(stdin);
        getline(cin, sentence);
        fpInfo << sentence;

        cout << "Ma so sinh vien: ";
        fpInfo << "\n"; //Ma so sinh vien: 
        fflush(stdin);
        getline(cin, sentence);
        fpInfo << sentence;

        cout << "Nam vao hoc: ";
        fpInfo << "\n"; //Nam vao hoc: 
        fflush(stdin);
        getline(cin, sentence);
        fpInfo << sentence;

        cout << "Lop: ";
        fpInfo << "\n"; //Lop: 
        fflush(stdin);
        getline(cin, sentence);
        fpInfo << sentence;

        cout << "Chuong trinh dao tao: ";
        fpInfo << "\n"; //Chuong trinh dao tao: 
        fflush(stdin);
        getline(cin, sentence);
        fpInfo << sentence;

        cout << "Email: ";
        fpInfo << "\n"; //Email: 
        fflush(stdin);
        getline(cin, sentence);
        fpInfo << sentence;
        // fpInfo << "\n" << taikhoan << " " << matkhau;
        // cout << "Dang ky thanh cong" << endl;
        fpInfo.close(); 
    }
};


class BangDiemHoctap {
    public:
    struct SCORE {
        float trongso;
        float quatrinh;
        float cuoiki;
        float tbc;
        char diemchu[5];
    };
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
      
    void ghiFileBDHT(FILE *file, struct BDHT bdht) {
        
        ofstream fpScore;
        fpScore.open (_BDHT, ios::app);
        fpScore << bdht.hocky << " " << bdht.tinchi << " " << bdht.diem.trongso << " ";
        fpScore << bdht.diem.quatrinh << " " << bdht.diem.cuoiki << " " << bdht.diem.tbc << " ";
        fpScore << bdht.diem.diemchu << " " << bdht.hocphan << ".\n";
        fpScore.close();

    }
    void docFileBDHT(FILE *file) { 
        char path[30];
        for(int i = 0; i<_BDHT.size(); i++){
                path[i]=_BDHT[i];
            }
        path[_BDHT.size()] = '\0';
        file = fopen(path, "r");
        int hocky, tinchi;
        float trongso, quatrinh, cuoiky, TBC;
        char hocphan[29], diemchu[14];
        hienthiBDHT();
        while (fgets(line, N, file) != NULL) {
            sscanf(line, "%d %d %f %f %f %f %s %[^.]", &hocky, &tinchi, &trongso, &quatrinh, &cuoiky, &TBC, diemchu, hocphan);
            cout << "|" << left << setw(11) << hocky << left << setw(28) << hocphan;
            cout << left << setw(11) << tinchi << left << setw(14) << trongso;
            cout << left << setw(14) << quatrinh << left << setw(14) << cuoiky;
            cout << left << setw(14) << TBC << left << setw(14) << diemchu << "|" << endl;
        }   

        fclose(file);
    }

    void hienthiBDHT() {
        
        cout << endl;
        system("cls");
        cout <<(char)(218) <<"------------------------------------------------------------------------------------------------------------------------" <<(char)(191) << endl;
        cout << "|" << right << setw(69) << "BANG DIEM HOC TAP" << setw(52) << "|" << endl;
        cout << "|------------------------------------------------------------------------------------------------------------------------|" << endl;
        
        cout << "|" << left << setw(11) << "Hoc ky" << left << setw(28) << "Ten hoc phan";
        cout << left << setw(11) << "Tin chi" << left << setw(14) << "Trong so";
        cout << left << setw(14) << "Qua trinh" << left << setw(14) << "Cuoi ky";
        cout << left << setw(14) << "TBC" << left << setw(14) << "Diem bang chu" << "|" << endl;
        cout << "|------------------------------------------------------------------------------------------------------------------------|" << endl;

    }
};

int HOME() {
    int C=0;
    cout << endl;
    system("cls");
    cout <<(char)(218) <<"---------------------------------------------------------" <<(char)(191) << endl;
    cout << "|             HE THONG QUAN LY HOC TAP CA NHAN            |" << endl;
    cout << "|---------------------------------------------------------|" << endl;
    cout << "|             1-Thong tin ca nhan                         |" << endl;
    cout << "|---------------------------------------------------------|" << endl;
    cout << "|             2-Bang diem hoc tap                         |" << endl;
    cout << "|---------------------------------------------------------|" << endl;
    cout << "|             3-bang diem ren luyen                       |" << endl;
    cout << "|---------------------------------------------------------|" << endl;
    cout << "|             4-Danh sach mon hoc                         |" << endl;
    cout << "|---------------------------------------------------------|" << endl;
    cout << "|             5-Hoc bong                                  |" << endl;
    cout << "|---------------------------------------------------------|" << endl;
    cout << "|             6-Lich thi                                  |" << endl;
    cout << "|---------------------------------------------------------|" << endl;
    cout << "|             7-Thoat chuong trinh                        |" << endl;
    cout <<(char)(192)<< "---------------------------------------------------------"<<(char)(217) << endl;
    cout << "Your choice: ";
    cin >> C;
    return C;
}


int main() {
    LOGIN ACC;
    ThongTinCaNhan SV;
    BangDiemHoctap BDHT;
    struct BangDiemHoctap::BDHT bdht;

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
                    cout << "Ban co muon chinh sua thong tin ca nhan khong?" << endl;
                    cout << "1. Co\t2. Khong" << endl;
                    cout << "Ban chon ? "; 
                    cin >> i;
                    if (i == 1) {
                        
                        SV.ghiFileSV(file, TK); 
                        cout << "Ban da cap nhat thong tin ca nhan thanh cong" << endl;
                        Sleep(2000);
                    } 
                    break;
                } else {
                    SV.docFile(TK);
                    
                    cout << "Ban co muon chinh sua thong tin ca nhan khong?" << endl;
                    cout << "1. Co\t2. Khong" << endl;
                    cout << "Ban chon ? "; 
                    cin >> i;
                    
                    if ((int)i == 1) {
                        printLine(120);
                        SV.ghiFileSV(file, TK);   
                        cout << "Ban da cap nhat thong tin ca nhan thanh cong" << endl;
                        Sleep(2000);
                    }
                }    
                break;
            case 2:
                if (checkEmptyFile(_BDHT) == 1) {
                    printLine(120);
                    cout << "Ban co muon them hoc phan khong?" << endl;
                    cout << "1. Co\n2. Khong" << endl;
                    cout << "Ban chon ? "; 
                    cin >> i;
                    
                    if ((int)i == 1) {
                        printLine(120);
                        bdht = BDHT.nhapBD();
                        BDHT.ghiFileBDHT(file, bdht);
                        cout << "Da them hoc phan vao danh sach thanh cong" << endl;
                        Sleep(2000);    
                    }
                break;
                } else {
                    BDHT.docFileBDHT(file);
                    cout <<(char)(192)<< "------------------------------------------------------------------------------------------------------------------------"<<(char)(217) << endl;
                    cout << "Ban co muon them hoc phan khong?" << endl;
                    cout << "1. Co\n2. Khong" << endl;
                    cout << "Ban chon ? "; 
                    cin >> i;
                    
                    if ((int)i == 1) {
                        printLine(120);
                        bdht = BDHT.nhapBD();
                        BDHT.ghiFileBDHT(file, bdht);  
                        cout << "Da them hoc phan vao danh sach thanh cong" << endl;
                        Sleep(2000);  
                    }
                }
                break;
            case 3:
                exit(1);
                break;
            case 4:
                exit(1);
                break;
            case 5:
                exit(1);
                break;
            case 6:
                exit(1);
                break;
            case 7:
                exit(1);
                break;
            default:
                cout << "Sai chuc nang. Vui long lua chon lai";
                continue;

        }
    } while (choose != 7);
    return 0;
}