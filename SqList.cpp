#include <iostream>
using namespace std;

#define InitSize 10
struct SqList
{
    int *data; //静态数组存放数局
    int length; //顺序表当前长度
    int MaxSize; //最大长度
};
void InitList(SqList &L)
{
    //L.data =(int *)new int;
    L.data = (int *)malloc(InitSize*sizeof(int));
    L.length=0;
    L.MaxSize=InitSize;
}
int ListLength(SqList &L){
    return L.length;
}
void DispList(SqList &L){
    int i;
    if (!ListLength(L))
        return ;
    for(i = 0; i<L.length;i++)
       {
           cout << L.data[i];
       }
    cout << endl ;
}
void IncreaseSize(SqList &L,int len) //增加动态数组的长度
{
    int *p=L.data;
    L.data=(int *)malloc((L.MaxSize+len)*sizeof(int));
    for(int i=0;i<L.length;i++)
    {
        L.data[i]=p[i];
    }
    L.MaxSize=L.MaxSize+len;
    free(p);
}
bool ListInerst(SqList &L,int i,int e) //在表L的位序i处插入元素e 
{    if(i<1||i>L.length+1) //判断i范围是否有效
        return false;
    if(L.length>=InitSize)  //当前存储空间已满，不能插入
        return false;
    for(int j=L.length;j>=i;j--) //将第i个元素及之后的元素后移
    {
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e; //在位置i处插入e
    L.length++;  //表长+1 
    return true;
}
int GetElem(SqList L, int i)//按位查找
{
    return L.data[i-1];
}
int LocateElem(SqList L, int e)
{
    for(int i=0;i<L.length;i++)
    {
        if(L.data[i]==e)
        {
            return i+1; //查找成功
        }
    }
    return 0; //查找失败
}
bool ListDelete(SqList &L, int i, int &e)
{
    if(i<1||i>L.length) //判断i的范围是否有效
        {
            return false;
        }
    e=L.data[i-1];
    for(int j=i;j<L.length;j++)
    {
        L.data[j-1]=L.data[j];
    }
    L.length--;
    return true;
}
int main()
{
    SqList L;
    int i=1;
    InitList(L);
    ListInerst(L,i++,1);
    ListInerst(L,i++,2);
    ListInerst(L,i++,3);
    ListInerst(L,i++,5);
    ListInerst(L,i++,6);
    cout << "第一次输出当前表中元素:" ;
    DispList(L);
    
    cout << "按位查找第3个位置元素为" << L.data[2] << endl;
    GetElem(L,2);
    
    cout << "按值查找3,返回位序为:" ;
    LocateElem(L,3);
    cout << endl;
    
    if(ListInerst(L,4,4))
    {
        cout << "在第4个位置插入数据" << L.data[3] << endl;
    }else
    {
        cout << "插入失败" << endl;
    }
    cout << "第二次输出当前表中元素:" ;
    DispList(L);
    
    int e = -1;
    if(ListDelete(L,4,e))
    {
        cout << "已经在第4个位置删除数据" << L.data[3] << endl;
    }else
    {
        cout << "删除失败" << endl;
    }
    cout << "第三次输出当前表中元素:" ;
    DispList(L);
    
    return 0;
}