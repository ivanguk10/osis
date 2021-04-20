#include "algorithm.h"

char *inverse(char * str){
int x = strlen(str);
int start = 0;
int end = 0;
for(int i=0;i<x;i++){
if(str[i]=='\n'){
end=i;
for(int j=start;j<end-(end-start)/2;j++){
std::swap(str[j], str[end-j-1]);
}
start=i+1;
}
}
return str;
}
