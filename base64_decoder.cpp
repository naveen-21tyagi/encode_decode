#include<iostream>
#include<fstream>
using namespace std;
int pow_2(int n){
    if(n==0){
        return 1;
    }
    return 2*pow_2(n-1);
}
int base64(char ch){
    if(ch>='A'&& ch<='Z'){
        return ch-65;
    }
    else if(ch>='a'&& ch<='z'){
        return ch-(97-26);
    }
    else if(ch=='+'){
        return 62;
    }
    else if(ch=='/'){
        return 63;
    }
    return ch-48+52;
}
void binary(int base_64_eq[150],int count,int bin[900]){
    for(int i=0;i<count;i++){
        int temp =base_64_eq[i];
        int k=5;
        while(temp>0){
            bin[i*6+k--]=temp%2;
            temp/=2;
        }
    }
}
void binary_dec(int bin[900],int quo,char ascii[150]){
    int i;
    for(i=0;i<quo;i++){
        int sum=0;
        for(int j=0;j<8;j++){
            sum+=bin[i*8+j]*pow_2(7-j);
        }
        ascii[i]=sum;
    }
    ascii[i]='\0';
}
int main(){
    ifstream f1("input.txt");
    ofstream f2("base64_decoded.txt");
    char chrs[150];
    f1.getline(chrs,150);
    // cout<<chrs;
    int count=0;
    int base_64_eq[150];
    for(int i=0;chrs[i]!='\0'&& chrs[i]!='='; i++){
        base_64_eq[i]=base64(chrs[i]);
        count++;
    }
    // for(int i=0; i<count; i++){
    //     cout<<base_64_eq[i]<<" ";
    // }
    //cout<<count;
    int bin[900];
    fill_n(bin,900,0);
    binary(base_64_eq,count,bin);
    // for(int i=0; i<count*6; i++){
    //     cout<<bin[i]<<" ";
    // }

    int rem=(count*6)%8;
    int quo=(count*6)/8;
    // cout<<rem<<quo;
    // if(rem==4){
    //     for(int i=0;i<2;i++){
    //         bin[(count-1)*6+i]=bin[count*6-2 +i];
    //     }  
    // }

    // else if(rem==2){
    //     for(int i=0;i<4;i++){
    //         bin[(count-1)*6+i]=bin[count*6-4+i];
    //     } 
    // }
    // cout<<endl;
    // for(int i=0; i<count*6; i++){
    //     cout<<bin[i]<<" ";
    // }
    char ascii[150];
    binary_dec(bin,quo,ascii);
    f2<<ascii;
    return 0;
}