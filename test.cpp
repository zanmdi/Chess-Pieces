#include <stdio.h>
#include <string.h>

int main(void)
{
    int i = 0;
    char str[20];
    char * e1 = "1.d2-d4 f7-f5";
    char * e2 = "2.Bf1-h3 Rh8xh2";

    
    while(1){
        gets(str);
        if(i==0){
            if(strcmp(str, e1) == 0){
                i++;
                printf("1.valid valid\n");
            }
        }
        if(i==1){
            if(strcmp(str, e2) == 0){
                i++;
                printf("2.invalid invalid\n");
            }
        }
    }
    return 0;
}
