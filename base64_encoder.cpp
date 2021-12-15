#include<iostream>
#include<fstream>
using namespace std;
int pow_2(int n){
    if(n==0){
        return 1;
    }
    return 2*pow_2(n-1);
}
void str_base64(char str[150],char str_64[250]){
    char base_64[64];
    for(int i=0;i<64;i++){
        if(i<26){
            base_64[i]=65+i;
        }
        else if(i>=26 && i<52){
            base_64[i]=(97-26)+i;
        }
        else if(i>=52 && i<62){
            base_64[i]=(48-52)+i;
        }
        else if(i==62){
            base_64[i]='+';
        }
        else if(i==63){
            base_64[i]='/';
        }
    }
    // for(int i=0;i<64;i++){
    //     cout<<base_64[i];
    // }
    
    int str_bin[1000];
    fill_n(str_bin,1000,0);
    int j;
    for(j=0;str[j]!='\0';j++){
        int i=7;
        int temp=str[j];
        // cout<<temp<<" ";
        while(temp>0){
            str_bin[j*8 + i--]=temp%2;
            temp/=2;
        }
    }
    // cout<<endl;
    // for(int i=0; i<j*8; i++){
    //     cout<<str_bin[i]<<" ";
    // }
    // cout<<j;
    int rem=(j*8)%6;
    // cout<<rem;
    int in=0;

    if(rem==2){
        for(int m=j*8;m<j*8+4;m++){
            str_bin[m]=0;
        }
        for(int i=0;i<j*8+4;i=i+6){
            // cout<<" a";
            int ch=0;
            for(int k=0;k<6;k++){
                ch+=str_bin[i + k]*pow_2(5-k);
            }
            // cout<<ch;
            str_64[in++]=base_64[ch];
        }
        str_64[in++]='=';
        str_64[in++]='=';
        str_64[in]='\0';

    }
    else if(rem==4){
        for(int m=j*8;m<j*8+2;m++){
            str_bin[m]=0;
        }
        for(int i=0;i<j*8+2;i=i+6){
            int ch=0;
            for(int k=0;k<6;k++){
                ch+=str_bin[i + k]*pow_2(5-k);
            }
            str_64[in++]=base_64[ch];
        }
        str_64[in++]='=';
        str_64[in]='\0';
    }
    
    else if(rem==0){
        for(int i=0;i<j*8;i=i+6){
            int ch=0;
            for(int k=0;k<6;k++){
                ch+=str_bin[i +k]*pow_2(5-k);
            }
            str_64[in++]=base_64[ch];
        }
        str_64[in]='\0';
    }
}
int main(){
    ifstream f1("input.txt");
    ofstream f2("base64_encoded.txt");
    char str[150];
    f1.getline(str,150);
    char str_64[250];
    str_base64(str,str_64);
    //cout<<str_64;
    f2<<str_64;

    return 0;
}