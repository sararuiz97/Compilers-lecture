#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool operator(char c) {
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '<' || c == '>' || c == '=') {
        return (true);   
    }
    return (false);
}

bool keyword(char* str) {
    if(!strcmp(str, "if") || !strcmp(str, "else") || !strcmp(str, "do") || 
       !strcmp(str, "while") || !strcmp(str, "break") || !strcmp(str, "continue") ||
       !strcmp(str, "int") || !strcmp(str, "double") || !strcmp(str, "float") ||
       !strcmp(str, "char") || !strcmp(str, "long") || !strcmp(str, "return") ||
       !strcmp(str, "case") || !strcmp(str, "switch") || !strcmp(str, "sizeof") || 
       !strcmp(str, "typedef") || !strcmp(str, "void") || !strcmp(str, "static") ||
       !strcmp(str, "short") || !strcmp(str, "unsigned") || !strcmp(str, "struct")) {
        return (true);   
    }
    return (false);
}

bool delimeter(char c){
    if(c == " " || c == "+" || c == "-" || c == "*" || c == "/" ||
       c == ";" || c == "," || c == "<" || c == ">" || c == "=" ||
       c == "(" || c == ")" || c == "{" || c == "}" || c == "[" || c == "]"){
        return (true);  
    }  
    return (false); 
}

bool identifier(char* str){
    if(str[0] == "0" || str[0] == "1" || str[0] == "2" || str[0] == "3" ||
       str[0] == "4" || str[0] == "5" || str[0] == "6" || str[0] == "7" ||
       str[0] == "8" || str[0] == "9" || delimeter(str[0]) == true){
        return (false);  
    }  
    return (true); 
}

char* subString(char* str, int left, int right){
    char* substr = (char*)malloc(sizeof(char) * (right - left + 2));
    for(int i = left; i <= right; i++){
        substr[i - left] = str[i];
    }
    substr[right - left + 1] = '\0';
    return (substr);
}

void parse(char* str){
    int left = 0, right = 0, len = strlen(str);
    while(right <= len && left <= right){
        if(delimeter(str[right]) == false){
            right++;
        }
        if(delimeter(str[right]) == true && left == right){
            if(operator(str[right]) == true){
                printf("'%c' operator\n", str[right]);
            }
            right++;
            left = right;
        } else if (delimeter(str[right]) == true && left != right || 
                   (right == len && left != right)){
            char* substr = subString(str, left, right - 1);
            if(keyword(substr) == true){
                printf("'%s' keyword\n", substr);
            } else if(identifier(substr) == true && delimeter(str[right - 1]) == false){
                printf("'%s' id\n", substr);
            }
            left = right;
        }
    }
    return;
}

int main(){
    char str[100] = "int temp = 10 + 23h;";
    parse(str);
    return (0);
}
