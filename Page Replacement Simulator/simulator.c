#include <stdio.h>
#include <stdlib.h>

int fn;
int string[500];

void interface()
{
    printf("������ �������� ������ �Է��Ͻÿ�.(3~10)\n");
    int fn;
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

void getData1()  // ���α׷� ���ο��� �Է� �޴� ���
{
    int in[500];

    for (int i = 0; i < 500; i++)
    {
        in[i]=rand()%30;
        string[i] = in[i];
    }
    
}

void getData2() //���Ϸ� �����Ͽ� �̸� �����Ͽ� �Է¹޴� ���??????????????
{   
    int in[500];
    FILE *fp =fopen("string.txt","w");
    for (int i = 0; i < 500; i++)
    {
        in[i]=rand()%30;
        fprintf(fp,"%d\n",in[i]);
    }
    fgets(string,sizeof(string), fp);  //�̰� �³�?
    
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
        printf("Page Replacement �˰��� �ùķ����͸� �����Ͻÿ� (�ִ�3��)\n");
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
            printf("�߸��� �Է��Դϴ�.\n");
            break;
        }
    }
}


