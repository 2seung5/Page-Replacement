#include <stdio.h>
#include <stdlib.h>

int fn;
int string[500];

void interface()
{
    printf("페이지 프레임의 개수를 입력하시오.(3~10)\n");
    int fn;
    scanf("%d",&fn);
    if ( fn<3 || fn>10)
        printf("다시 입력하세요 (3~10)\n");
    else{
        printf("데이터 입력 방식을 선택하시오(1,2)\n");
        int ch;
        scanf("%d",&ch);
        if (ch==1)
        {
            getData1();
        }
        else if (ch==2)
        {
            getData2();
        }
        else
            printf("다시 입력하세요 1,2\n");
    }
}

void getData1()  // 프로그램 내부에서 입력 받는 방식
{
    int in[500];

    for (int i = 0; i < 500; i++)
    {
        in[i]=rand()%30;
        string[i] = in[i];
    }
    
}

void getData2() //파일로 저장하여 이를 오픈하여 입력받는 방식??????????????
{   
    int in[500];
    FILE *fp =fopen("string.txt","w");
    for (int i = 0; i < 500; i++)
    {
        in[i]=rand()%30;
        fprintf(fp,"%d\n",in[i]);
    }
    fgets(string,sizeof(string), fp);  //이게 맞나?
    
    fclose(fp);

    

   
}


void optimal()
{
    
}

void fifo()
{
   
}

void lifo()
{

}

void lru()
{
    
}
void lfu()
{
   
}

void sc()
{
  

}

void esc()
{
    
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


