#include <stdio.h>
#include <stdlib.h>

int fn;              //������ ������ ����
int stream[10];     //���� ������ ��Ʈ��
int hit;             //hit ���� 0 or 1
int pagefaultcnt;    //������ ��Ʈ ī����
int p[100];

void getData1()  // ���α׷� ���ο��� �Է� �޴� ���
{
    int in[10];

    for (int i = 0; i < 10; i++)
    {
        in[i]=rand()%30;
        stream[i] = in[i];
    }
    
}

void getData2() //���Ϸ� �����Ͽ� �̸� �����Ͽ� �Է¹޴� ���??????????????
{   
    int in[10];
    FILE *fp =fopen("string.txt","w");
    for (int i = 0; i < 10; i++)
    {
        in[i]=rand()%30;
        fprintf(fp,"%d\n",in[i]);
    }
    fgets(stream,sizeof(stream), fp);  //�̰� �³�?
    
    fclose(fp);
   
}

void initialize()          // �ʱ�ȭ ���ִ� �Լ�?
{
    pagefaultcnt=0;
    for(int i=0; i<fn; i++)
        p[i]=9999;
}

int isHit(int data)          //hit Ȯ���ϴ� �Լ�
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

void pageFaultCnt()          //������ ��Ʈ ���� ��Ÿ���ִ� �Լ�
{
    printf("\nnumber of page faults: %d",pagefaultcnt);
}

void interface()
{
    printf("������ �������� ������ �Է��Ͻÿ�.(3~10)\n");
    // int fn;
    
    scanf("%d",&fn);
    if ( fn<3 || fn>10)
        printf("�ٽ� �Է��ϼ��� (3~10)\n");
    else{
        printf("������ �Է� ����� �����Ͻÿ�(1,2)\n");
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
            printf("�ٽ� �Է��ϼ��� 1,2\n");
    }
}


void optimal()
{
    interface();
}

void fifo()
{
     interface();
     
     
}

void lifo()
{
     interface();
}

void lru()
{
     interface();
}
void lfu()
{
     interface();
}

void sc()
{
     interface();

}

void esc()
{
     interface();
}

int main()
{
   
    int ch;
    while(1){
        printf("Page Replacement �˰��� �ùķ����͸� �����Ͻÿ� (�ִ�3��)\n");
        printf("1.Optimal  2.FIFO  3.LIFO  4.LRU  5.LFU  6.SC  7.ESC 8.exit\n");

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

        case 8 :
            return 0;
            break;
        
        default:
            printf("�߸��� �Է��Դϴ�.\n");
            break;
        }
    }
}


