/*5. WAP to check if two strings are anagram*/
#include<stdio.h>
int anagram(char [], char []);

int main(){
    char a[50],b[50];
    printf("Enter two strings:\n");
    gets(a);
    gets(b);
    if(anagram(a,b)){
        printf("The strings are anagram.");
    }
    else{
        printf("The strings are not anagram.");
    }
    return 0;
}

int anagram(char a[], char b[]){
    int x[26]={0},y[26]={0},z=0;
    while(a[z]!='\0'){
        x[a[z]-'a']++;
        z++;
    }
    z=0;
    while(b[z]!='\0'){
        y[b[z]-'a']++;
        z++;
    }
    for(z=0;z<26;z++){
        if(x[z]!=y[z]){
            return 0;
        }
    }
    return 1;
}