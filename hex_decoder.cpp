#include<iostream>
#include<fstream>
using namespace std;
int pow_16(int n){
    if(n==0){
        return 1;
    }
    return 16*pow_16(n-1);
}
int hex_dec(char ch){
    int d;
    if(ch>=48 && ch <=57){
        d=ch-48;
    }
    else if(ch>='A' && ch<='E'){
        d=ch-55;
    }
    return d;
}
                                                            // string hex_decoder(char ch){
                                                            //     int d;
                                                            //     if(ch>=48 && ch <=57){
                                                            //         d=ch-48;
                                                            //     }
                                                            //     else if(ch>='A' && ch<='E'){
                                                            //         d=ch-55;
                                                            //     }

                                                            // }
int main(){
    ifstream f1("input.txt");
    ofstream f2("hex_decoded.txt");
    char chrs[75][2];
                                                                // //int i=0;
                                                                // while(f1.eof()){
                                                                //     cin>>chrs;
                                                                //     //i++;
                                                                // }

    //reading file char by char and putting in blocks of two
    int i;
    for(i=0;!f1.eof(); i++){
        for(int j=0;j<2;j++){
            f1.get(chrs[i][j]);
        }
    }
    chrs[i-1][0]='\0';   //i-1 due to eof() 
                                                            // for(int j=0; chrs[j][0]!='\0'; j++){
                                                            //     for(int k=0;k<2;k++)
                                                            //     cout<<chrs[j][k]<<" ";
                                                           // }
    
    //converting hex into decimal values and storing in char array
    //thus that decimal value represent required character
    char dec[75];
    int j;
    for(j=0;chrs[j][0]!='\0';j++){
        dec[j]=hex_dec(chrs[j][0])*pow_16(1)+hex_dec(chrs[j][1])*pow_16(0);
    }
    dec[j]='\0';
    //storing in file
    for(int j=0;dec[j]!='\0';j++){
        f2<<dec[j];
    }
    return 0;
}