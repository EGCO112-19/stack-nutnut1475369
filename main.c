#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"

int main(int argc, char **argv){
  printf("Checking the parentheses in argv arguments\n");
  Stack s;
  s.size=0;
  s.top=NULL;
  int check=0;
  char out;
  for(int i=1;i<argc;i++){
    for(int j=0;j<strlen(argv[i]);j++){
      switch(argv[i][j]){
        case '{'  : push(&s, argv[i][j]);
                    break;
        case '['  : push(&s, argv[i][j]);
                    break;
        case '}'  : out = pop(&s);
                    if(out != '{'){
                      check = 1;
                      break;
                    }
        case ']'  : out = pop(&s);
                    if(out != '['){
                      check = 1;
                      break;
                    }
       }
/*      if(argv[i][j] == '{' || argv[i][j] == '['){
          push(&s,argv[i][j]);
        }
        if(argv[i][j] == '}'){
          out = pop(&s);
          if(out != '{'){
            check = 1;
            break;
          }
        }
        if(argv[i][j] == ']'){
          out = pop(&s);
          if(out != '['){
            check = 1;
            break;
          }
        }*/
     
  }
  if(s.size>0){
    printf("The parentheses do not match successfully in %s\n", argv[i]);
    check=0;
    pop_all(&s);
  }else if(check==1){
    printf("The parentheses do not match successfully in %s\n", argv[i]);
  }else{
    printf("The parentheses match successfull in %s\n",argv[i]);
  }
}
   return 0;
}
