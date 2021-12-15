#include<iostream>
#include<fstream>
using namespace std;
string bin(int n){
    char bin[8];
    fill_n(bin,8,48);
    int i=7;
    while(n>0){
        int temp=n%2;
        bin[i--]=48+ n%2;
        n/=2;
    }

    string binary="";
    for(int j=0;j<8;j++){
        binary+=bin[j];
    }
    
    return binary;
}
int main(){
    ifstream f1("input.txt");
    ofstream f2("binary_encoded.txt");
    char str[100];
    f1.getline(str,100);
    
    for(int i=0;str[i]!='\0';i++){
        f2<<bin(str[i]);
    }

    return 0;
}