#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//定义动态数组数据结构
typedef int ElemType;
typedef struct{
    ElemType *elem;
    int len;
}SequenceTable;

//初始化数组
void init_seq_table(SequenceTable &seq_table,int len)
{
    seq_table.len=len;
    seq_table.elem=(ElemType*)malloc(sizeof(ElemType)*seq_table.len);
    srand(time(NULL));
    for(int i=0;i<seq_table.len;i++)
    {
        seq_table.elem[i]=rand()%100;
    }
}

//打印数组
void print_seq_table(SequenceTable seq_table)
{
    for(int i=0;i<seq_table.len;i++)
    {
        printf("%3d",seq_table.elem[i]);
    }
    printf("\n");
}

//插入排序
void insert_sort(ElemType *arr,int n)
{
    int i,j;
    ElemType insert_value;
    for(i=1;i<n;i++)
    {
        insert_value=arr[i];
        for(j=i-1;j>=0 && insert_value<arr[j];j--)
        {
            arr[j+1]=arr[j];
        }
        arr[j+1]=insert_value;
    }
}

int main() {
    SequenceTable seq_table;
    int len=10;
    init_seq_table(seq_table,len);
//    ElemType arr[10]={12,63,58,95,41,35,65,0,38,44};
//    memcpy(seq_table.elem,arr,sizeof(arr));//使用前提：动态数组的内存空间已经初始化，即已获得一片连续的内存空间
    print_seq_table(seq_table);
    insert_sort(seq_table.elem,seq_table.len);
    print_seq_table(seq_table);
    return 0;
}