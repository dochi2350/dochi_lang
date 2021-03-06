#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    char input[10003];
    char variables[1030][1030];
    int variablesvalue[1030] = {0, };

    scanf("%s", input); //코드 입력
    int inputlength = strlen(input); //코드 길이

    int i, codeerror = 0;
    int variablecnt = 0;

    for(i = 0; i < inputlength; i++) { //코드 처음부터 끝까지 한글자씩 확인
        if(input[i] == 73) { //i번째 글자가 대문자 i(I)라면... 한개라면 입력
            if(input[i + 1] == 73) { //만약 i + 1번째 글자가 대문자 i(I)라면... 두개라면 출력
                int j = 0;
                while(input[i + 3] != 33) {
                    variables[variablecnt][j++] = input[i + 3];
                    i++;
                }
                int newvariablelength = strlen(variables[variablecnt]);

                int k, variablewhere = 0;
                for(k = newvariablelength - 1; k >= 0; k--) {
                    if(variables[variablecnt][k] == 41) variablewhere += pow(2, newvariablelength - k - 1);
                    else if(variables[variablecnt][k] == 40) variablewhere += 0;
                    else codeerror = 1;
                }
                if(codeerror == 1) break;
                printf("%d", variablesvalue[variablewhere]);
            }
            else if(input[i + 1] != 33) { //만약 i + 1번째 글자가 느낌표(!)가 아닌 다른 글자라면
                codeerror = 1; //코드에러
                break; //컴파일 종료
            }
            else { //입력
                int j = 0;
                while(input[i + 2] != 33) {
                    variables[variablecnt][j++] = input[i + 2];
                    i++;
                }
                //printf("%s\n", variables[variablecnt]);
                int newvariablelength = strlen(variables[variablecnt]);
                //printf("len %d\n", newvariablelength);

                int k, variablewhere = 0;
                for(k = newvariablelength - 1; k >= 0; k--) {
                    if(variables[variablecnt][k] == 41) variablewhere += pow(2, newvariablelength - k - 1);
                    else if(variables[variablecnt][k] == 40) variablewhere += 0;
                    else codeerror = 1;
                    //printf("k %d %d %c\n", k, variablewhere, variables[variablecnt][k]);
                }
                if(codeerror == 1) break;
                variablesvalue[variablewhere] = 1;
                variablecnt++;
                //printf("where %d %d\n", variablewhere, variablesvalue[variablewhere]);
            }
        }
    }
    if(codeerror == 1) printf("error\n");
    return 0;
}

/*
Il1!()|
대문자 i I : 73
소문자 l l : 108
숫자 1 1 : 49
느낌표 ! ! : 33
왼괄호 ( ( : 40
오른괄호 ) ) : 41
or 기호 | | : 124
*/