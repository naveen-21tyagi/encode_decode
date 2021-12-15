#include<iostream>
#include<fstream>
using namespace std;
int pow_2(int n){
    if(n==0){
        return 1;
    }
    return 2*pow_2(n-1);
}
int dec(char a){
    return a-48;
}

int main(){
    ifstream f1("input.txt");
    ofstream f2("binary_decoded.txt");
    char str[500];
    f1.getline(str,500);
    for(int i=0;str[i]!='\0';i=i+8){
        char sum=0;
        for(int j=0;j<8;j++){
            sum+=dec(str[i + j]) * pow_2(7-j);
        }
        f2<<sum;
    }
    return 0;
}