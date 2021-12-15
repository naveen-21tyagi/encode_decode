#include<iostream>
#include<fstream>
using namespace std;
string ascii_hex(int n){
    char hex[2]={'0','0'};
    int j=0;
    while(n>0){
        int temp=n%16;
        if(temp<10){
            hex[j++]=temp+48;
        }
        else{
            hex[j++]=temp+55;
        }
        n/=16;
    }
    string h="";
    for(int i=1;i>-1;i--){
        h=h+hex[i];
    }
    return h;
}
int main(){
    ifstream f1("input.txt");
    ofstream f2("hex_encoded.txt");
    char string[150];
    f1.getline(string,150);
    for(int i=0; string[i]!='\0'; i++){
        f2<<ascii_hex(string[i]);
    }
    // for(int j=0;j<i;j++){
    //     for(int k=0; words[j][k]!='\0'; k++){
    //         f2<<ascii_hex(words[j][k]);
    //     } 
    //     f2<<"20";
    // }
    f1.close();
    f2.close();
    return 0;
}