#include <stdio.h>


void optimal()
{
    printf("������ �������� ������ �Է��Ͻÿ�.(3~10)\n");
    int n;
    scanf("%d",&n);
}

void fifo()
{
    printf("������ �������� ������ �Է��Ͻÿ�.(3~10)\n");
    int n;
    scanf("%d",&n);
}

void lifo()
{
    printf("������ �������� ������ �Է��Ͻÿ�.(3~10)\n");
    int n;
    scanf("%d",&n);
}

void lru()
{
    printf("������ �������� ������ �Է��Ͻÿ�.(3~10)\n");
    int n;
    scanf("%d",&n);
}

void lfu()
{
    printf("������ �������� ������ �Է��Ͻÿ�.(3~10)\n");
    int n;
    scanf("%d",&n);
}

void sc()
{
    printf("������ �������� ������ �Է��Ͻÿ�.(3~10)\n");
    int n;
    scanf("%d",&n);

}

void esc()
{
    printf("������ �������� ������ �Է��Ͻÿ�.(3~10)\n");
    int n;
    scanf("%d",&n);
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


