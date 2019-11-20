#include <stdio.h>
#include <string.h>

#contoh inputan
#adamatamatamendekat-mata
#                    ^^^^kata kunci

int main(){
    char input[100], string[100], key[20];
    int i = 0, j = 0, k = 0, c = 0, n;
    
    //input
    while(input[i-1] != '-'){
        scanf(" %c", &input[i]);
        if(input[i] != '-'){
            string[i] = input[i];
        }
        i++;
    }

    string[i-1] = '\0';//supaya tidak muncul simbol aneh"
    int nstring = strlen(string);
    char keyword[nstring];
    //input key
    scanf("%s", key);
    int nkey = strlen(key);
    char cek[(nkey)+1];
    cek[nkey] = '\0';//supaya tidak muncul simbol aneh"

    i = 0, j = 0, k = 0;
    int indeksloc[50];//menyimpan indeks yg mengandung kata kunci
    int a = 0;//counter untuk indeks
    //mencari indeks sukukata yg sama dengan katakunci
    while(i < strlen(string)){
        if(string[i] == key[j]){
            j++;
        }
        else{
            j = 0;
        }
        if(j == nkey){
            int index = i-nkey+1;
            k = index;
            while(k < index + nkey){//menyimpan indeks ke dalam array
                indeksloc[a] = k;
                k++;
                a++;
            }
            j = 0;
        }  
        ++i;
    }
    j = 0, a = 0, i = 0;
    //memasukan katakunci baru yg tanpa "kunci"
    while(i < nstring){
        if(i != indeksloc[j]){
            keyword[a] = string[i];
            a++;
        }
        else{
            j++;
        }
        i++;
    }
    //print akhir
    int nkeyword = a;
    if(nkeyword > 0){
        keyword[a]='\0';
        printf("Kata Kunci    : %s\n", keyword);
        int cdepan = 0, cbelakang = nkeyword-1;
        if(nkeyword%2 == 1){//jika jumlah katakunci ganjil maka dikurang 1
            nkeyword--;
        }
        char enkrip1[nkeyword+1], enkrip2[nkeyword+1];
        i = 0;
        //enkrip ke 1
        while(i < nkeyword){
            if(i % 2 == 0){
                enkrip1[i] = keyword[cbelakang];
                cbelakang--;
            }
            else{
                enkrip1[i] = keyword[cdepan];
                cdepan++;
            }
            i++;
        }
        enkrip1[i] = '\0';
        printf("Hasil Enkrip1 : %s\n", enkrip1);
        //enkrip ke 2
        cdepan = 0, cbelakang = nkeyword-1;
        i = 0;
        while(i < nkeyword){
            if(i % 2 == 0){
                enkrip2[i] = enkrip1[cbelakang];
                cbelakang--;
            }
            else{
                enkrip2[i] = enkrip1[cdepan];
                cdepan++;
            }
            i++;
        }
        enkrip2[i] = '\0';
        printf("Hasil Enkrip2 : %s\n", enkrip2);
    }
    else{
        printf("DATA TELAH TERCURI !\n");
    }

    return 0;
}
