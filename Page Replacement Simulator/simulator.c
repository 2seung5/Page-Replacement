#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int fn;              //페이지 프레임 개수
int stream[10];     //참조 페이지 스트링
int hit;             //hit 변수 0 or 1
int pagefaultcnt;    //페이지 폴트 카운터
int p[100];         //page 
int i,j,k;




void getData1()  // 프로그램 내부에서 입력 받는 방식
{
    int in[10];
    srand((unsigned)time(NULL));

    for (int i = 0; i < 10; i++)
    {
        
        in[i]=1+rand()%30;
        stream[i] = in[i];
    }
    
}

void getData2() //파일로 저장하여 이를 오픈하여 입력받는 방식??????????????
{   
    int in[10];
    FILE *fp =fopen("string.txt","w");
    for (int i = 0; i < 10; i++)
    {
        in[i]=rand()%30;
        fprintf(fp,"%d\n",in[i]);
    }
    // fgets(stream,sizeof(stream), fp);  //이게 맞나?
    
    fclose(fp);
   
}

void initialize()          // 초기화 해주는 함수
{
    pagefaultcnt=0;
    for(int i=0; i<fn; i++)
        p[i]=9999;
}

int pageindex()
{
    for(i=0;i<fn-1;i++)
    {
        p[i] = 9999;
        return 1;
    }

    return 0;
}

int isHit(int data)          //hit 확인하는 함수
{
    hit=0;
    for(int j=0; j<fn; j++)
    {
        if(p[j]==data)
        {
            hit=1;
            break;
        }

    }
    return hit;
}

void pageFaultCnt()          //페이지 폴트 개수 나타내주는 함수
{
    printf("number of page faults: %d\n",pagefaultcnt);
}

void interface()
{
    printf("페이지 프레임의 개수를 입력하시오.(3~10)\n");
    // int fn;
    
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


void optimal()
{
    interface();
    initialize();
    int near[50];
    for(i=0; i<10; i++)
    {
 
        //printf("\nFor %d :",stream[i]);
 
        if(isHit(stream[i])==0)
        {
 
            for(j=0; j<fn; j++)
            {
                int pg=p[j];
                int found=0;
                for(k=i; k<10; k++)
                {
                    if(pg==stream[k])
                    {
                        near[j]=k;
                        found=1;
                        break;
                    }
                    else
                        found=0;
                }
                if(!found)
                    near[j]=9999;
            }
            int max=-9999;
            int repindex;
            for(j=0; j<fn; j++)
            {
                if(near[j]>max)
                {
                    max=near[j];
                    repindex=j;
                }
            }
            p[repindex]=stream[i];
            pagefaultcnt++;
 
           
        }
        //else
         //   printf("No page fault");
    }
    printf("optimal ");
    pageFaultCnt();
}

void fifo()
{
     interface();
     initialize();
     for(i=0; i<10; i++)
     {
        //printf("\nFor %d :",stream[i]);

        if (pageindex())
        {
            /* code */
        }
        
 
        if(isHit(stream[i])==0)
        {
 
            for(k=0; k<fn-1; k++)
                p[k]=p[k+1];
 
            p[k]=stream[i];
            pagefaultcnt++;
            
        }
        //else
            // printf("No page fault");
     }
     printf("fifo ");
     pageFaultCnt();
     
     
}

void lifo()
{
     interface();
     initialize();
     for(i=0; i<10; i++)
     {
        printf("\nFor %d :",stream[i]);
 
        if(isHit(stream[i])==0)
        {   
            for(k=0 ; k < fn-1; k++)
                p[k+1]=p[k];
            p[0]=stream[i];
            pagefaultcnt++;   
        }
        
     }
     printf("lifo ");
     pageFaultCnt();
}

void lru()
{
     interface();
     initialize();
     int least[50];
     for(i=0; i<10; i++)
     {
 
        //printf("\nFor %d :",stream[i]);
 
        if(isHit(stream[i])==0)
        {
 
            for(j=0; j<fn; j++)
            {
                int pg=p[j];
                int found=0;
                for(k=i-1; k>=0; k--)
                {
                    if(pg==stream[k])
                    {
                        least[j]=k;
                        found=1;
                        break;
                    }
                    else
                        found=0;
                }
                if(!found)
                    least[j]=-9999;
            }
            int min=9999;
            int repindex;
            for(j=0; j<fn; j++)
            {
                if(least[j]<min)
                {
                    min=least[j];
                    repindex=j;
                }
            }
            p[repindex]=stream[i];
            pagefaultcnt++;
 
           
        }
        //else
          //  printf("No page fault!");
     }
     printf("lru ");
     pageFaultCnt();
}
void lfu()
{
     interface();
     initialize();
}

void sc()
{
     interface();
     initialize();

}

void esc()
{
     interface();
     initialize();
}

int main()
{
    char buffer[10];
    int select[3];
    int cnt=0;
    
    while(1){
        printf("Page Replacement 알고리즘 시뮬레이터를 선택하시오 (최대3개)\n");
        printf("1.Optimal  2.FIFO  3.LIFO  4.LRU  5.LFU  6.SC  7.ESC 8.exit\n");

        scanf("%s",&buffer);
        char *ptr = strtok(buffer," ");
        
        while (ptr !=NULL)
        { 
            
            select[cnt++] = atoi(ptr);
            ptr=strtok(NULL, "");
        }
        if (cnt > 3) {
            printf("wrong\n");
            continue;
        }
        for (int i = 0; i < cnt; i++)
        {
            printf("%d\n",cnt);
            printf("%d\n",select[i]);
        }
        
        for (int i = 0; i < cnt; i++) {
            switch (select[i])
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

            case 8 :
                return 0;
                break;
            
            default:
                printf("잘못된 입력입니다.\n");
                break;
            }
        }
    }
}



