#include <stdio.h>


void optimal()
{
    printf("페이지 프레임의 개수를 입력하시오.(3~10)\n");
    int n;
    scanf("%d",&n);
}

void fifo()
{
    printf("페이지 프레임의 개수를 입력하시오.(3~10)\n");
    int n;
    scanf("%d",&n);
}

void lifo()
{
    printf("페이지 프레임의 개수를 입력하시오.(3~10)\n");
    int n;
    scanf("%d",&n);
}

void lru()
{
    printf("페이지 프레임의 개수를 입력하시오.(3~10)\n");
    int n;
    scanf("%d",&n);
}

void lfu()
{
    printf("페이지 프레임의 개수를 입력하시오.(3~10)\n");
    int n;
    scanf("%d",&n);
}

void sc()
{
    printf("페이지 프레임의 개수를 입력하시오.(3~10)\n");
    int n;
    scanf("%d",&n);

}

void esc()
{
    printf("페이지 프레임의 개수를 입력하시오.(3~10)\n");
    int n;
    scanf("%d",&n);
}

int main()
{
   
    int ch;
    while(1){
        printf("Page Replacement 알고리즘 시뮬레이터를 선택하시오 (최대3개)\n");
        printf("1.Optimal  2.FIFO  3.LIFO  4.LRU  5.LFU  6.SC  7.ESC\n");

        scanf("%d",&ch);
        switch (ch)
        {
        case 1 : 
            optimal();
            break;
        case 2 :
            fifo();
            break;
        case 3 :
            lifo();
            break;
        
        case 4 :
            lru();
            break;
        
        case 5 :
            lfu();
            break;
        
        case 6 :
            sc();
            break;
        
        case 7 :
            esc();    
            break;
        
        default:
            printf("잘못된 입력입니다.\n");
            break;
        }
    }
}


