#include<iostream>
#include "algorithm.h"

int main(){
int size = 150;
char str[size];
while(fgets(str,size,stdin) !=NULL){
std::cout<<(inverse(str));
}
}
