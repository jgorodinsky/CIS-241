#include <stdio.h>
#include <ctype.h>

int main(){
     char ch;
     
     int counter = 0;

     int prevAlphaNum = 0;
     int prevSym = 0;
     int prevSpace = 1;

     int wordCounter = 0;
     int letterCounter = 0;
     int symbolCounter = 0;
  
     puts ("Enter text (Ctrl-D to quit).");
     while( ch= getchar(), ch != EOF){
        if(isalnum(ch) || isdigit(ch)){
           prevAlphaNum = 1;
           if(prevSym == 1){
              symbolCounter++;
              prevSym = 0;
           
           }
           prevSpace = 0;
        }
        
       else if(isspace(ch)){

           if(prevAlphaNum == 1){
             letterCounter++;
             prevAlphaNum = 0;
           }
           
           if(prevSym == 1){
             symbolCounter++;
             prevSym = 0;
           }
 
           if(prevSpace == 0){
              wordCounter++;
           }  
           prevSpace = 1;
       }
      else{
         prevSym = 1;
         if(prevAlphaNum == 1){
           letterCounter++;
           prevAlphaNum = 0;
         }
          prevSpace = 0;
         }
      }
    
    
     printf("\n");
     printf("%s%d%s\n", "There are ", wordCounter, " words");
     printf("%s%d%s\n", "There are ", letterCounter, " letter sequences");
     printf("%s%d%s\n", "There are ", symbolCounter, " symbol sequences");
     printf("\n");

     return 0;
}
