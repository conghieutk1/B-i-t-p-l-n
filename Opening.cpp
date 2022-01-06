#include <iostream>
#include <unistd.h> //sleep
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;

#define N 256

const char *fileLogin = "D:/Login.txt";

string taikhoan;
string TK;
string matkhau;
string LINE;
char line[N];
char str[16];
char str1[16];

FILE* file;


void showLogin(string ID,int sizeofPass){
    string S;
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
    void taoFile(string TK) {
        TK = TK += ".txt";
        ofstream file1;
        file1.open (TK);
    }
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
                    sleep(2);
                    continue;
                }
                if (checkSignUp() == 1) {
                    cout << "Tai khoan nay da ton tai" << endl;
                    sleep(3);
                    continue;
                } else {
                    cout << "Ban da dang ky thanh cong tai khoan " << tmpUsername << endl;
                    cout << "Nhan phim Enter de tiep tuc...";
                    fflush(stdin);
                    cin.get();
                    fflush(stdin);
                    fprintf(file,"%s %s\n",tmpUsername, tmpPassword);
                    cout << tmpUsername << "\n" << tmpPassword << endl;
                    taoFile((string)tmpUsername);
                    fclose(file);
                    break;
                }
            } 
        } while (1);
    }

    bool SignIn() {

    LoginForm:
        string user = ""; /// string show ID;
        char tmp;

        /// enter username
        showLogin(user,0);
        for(int i = 0;;){
            tmp = getch();
            if((int)(tmp) == 27){   /// ESC
                return false;
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
                return false;
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

        cout << endl;
        file = fopen(fileLogin, "r");
        while(fgets(line, N, file) != NULL) { 
            sscanf(line, "%s %s", username, password); //&f1, &f2, &f3, &f4, &f5 - %f    
            if(strcmp(username,tmpUsername) == 0 && strcmp(password,tmpPassword) == 0){
                cout << "Login successfull" << endl;        
                fclose(file);
                return true;
            }  
        }
        cout << "Tai khoan hoac mat khau khong chinh xac" << endl;
        sleep(2);
        goto LoginForm; 
    }
    int showForgetPass() {
        char ForgetPass[30];
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

int MENU(){
    int C=0;
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


int main() {
    LOGIN ACC;
    int choose;
    do {
        choose = MENU();

        switch (choose)
        {
        case 4:
            exit(1);
            break;
        
        case 1:
            if (ACC.SignIn() == false) continue;
            break;

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
                sleep(2);
                continue;   
            }

        default:
            cout << "Sai chuc nang. Vui long lua chon lai";
            continue;
        }
    } while (choose != 1);

    return 0;
}