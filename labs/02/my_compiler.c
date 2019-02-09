#include <stdio.h>

int main(int arg, char *arv[]) {
    int c = 0;
    int temp = 0;
    int parentheses = 0;
    int brackets = 0;
    int braces = 0;
    int comments = 0;
    int single_quote = 0;
    int double_quote = 0;
    
    while((c = getchar()) != EOF) {
        if(c == '('){
            parentheses++;
        } else if(c == '{'){
            braces++;
        } else if(c == '['){
            brackets++;
        } else if(c == '\''){ 
            single_quote++;
        } else if(c == '"'){
            double_quote++;
        } else if(c == '*' && temp == '/'){
            comments++;
        } else if(c == ')'){
            parentheses--;
        } else if(c == '}'){
            braces--;
        } else if(c == ']'){
            brackets--;
        } else if(c == '/' && temp == '*'){
            comments--;
        }
        temp = c;
    }
    
    if(parentheses != 0) {
        printf("There is a missing parentheses!!\n");
    }
    if(braces != 0) {
        printf("There is a missing brace!!\n");
    }
    if(brackets != 0) {
        printf("There is a missing bracket!!\n");
    }
    if((single_quote % 2) != 0) {
        printf("There is a missing single quote!!\n");
    }
    if((double_quote % 2) != 0) {
        printf("There is a missing single quote!!\n");
    }
    if(comments != 0) {
        printf("There is a missing double quote!!\n");
    }
    
    return 0;
}
