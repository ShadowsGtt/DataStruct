#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXBIT 20 //最大编码的值
#define MAXSIZE  300//哈夫曼树的节点数目最大值
//#define MAXLEAVES ((MAXSIZE+1)/2)
//存放哈夫曼节点的结构体
typedef struct 
{
    char ch;
    int weight;   //每个节点的权值
    int parent;  //父节点
    int lchild,rchild; //左右分支
}HNode;

//存放叶子节点信息的结构体
typedef struct 
{
    char ch;         //字符
    int weight; //叶子节点的权值(即字母出现的次数)
    int bit[MAXBIT];  //该字母的哈夫曼编码
    int start;     //bit数组中哈夫曼编码的起始下标
}HCode;

int TongJi(int *cch,HCode *hc)    //统计每个字母出现的次数
{    
    int i = 0;
    char filemsg[1024];
    int n;
    FILE *fp;
    if( (fp = fopen("a.source","r")) == NULL )
    {
        printf("opened error\n");
        exit(1);
    }
    char ch;
    while((ch = fgetc(fp)) !=EOF )
    {
        if(ch == '\r' || ch == '\n')
            continue;
        cch[ch]++;
        filemsg[i++] = ch;
    }
    fclose(fp);
    printf("\n\n**************************");
    printf("文件内容如下");
    printf("******************************\n\n");
    printf("%s\n",filemsg);
    
    ///char press;
    //printf("按 'n' 继续\n");
    ///while((press = getchar()) != 'n' );

    printf("\n\n**************************");
    printf("文件中字符统计结果如下");
    printf("******************************\n\n");
    for(int i = 0; i < 256; i++)
    {
        if(cch[i] != 0)
        {
            n++;
            printf("字符:'%c'\t出现的次数:%d\n",i,cch[i]);
        }
    }
    printf("不同字符个数：%d\n",n);
    return n;
}

void InitHaffTree(HCode *hc,HNode *hn,int *cch)//初始化树节点
{                      
    int k = 0;
    for(int i = 0;i < MAXSIZE;i++)
    {
        hn[i].ch = '$';  
        hn[i].lchild = -1;
        hn[i].rchild = -1;
        hn[i].parent = -1;
        hn[i].weight = 0;
        if(i < 256 )
        {
            if(cch[i] != 0)
            {
                hn[k].weight = cch[i];
                hc[k].weight = cch[i];
                hc[k].ch = i;   //i是字符的ascii码值
                hn[k].ch = i;
                k++;
            }
        }
        if(i < MAXSIZE/2)
        {
            hc[i].weight = 0;
            hc[i].start = 19;
            for(int j = 0;j < MAXBIT;j++)
                hc[i].bit[j] = -1;
        }
    }
}
void Print(HNode *hn,HCode *hc)   //打印每个字符最终的编码信息
{
    printf("\n\n**********************");
    printf("每个字符对应的权值与编码如下:");
    printf("*************************\n\n");
    for(int i = 0;i < MAXSIZE/2;i++)  //打印叶节点数组中的信息
    {
        if(hc[i].weight == 0)
            break;
        printf("字符:'%c'   权值:%d    ",hc[i].ch,hc[i].weight);
        printf("编码:");
        for(int j = hc[i].start+1;j < 20;j++)
            printf("%d",hc[i].bit[j]);
        putchar(10);
    }
}
void CreateHuffTree(HNode hn[],HCode hc[],int n ) // n 为叶子节点数目
{
    int i,j,m1,m2,x1,x2;
    for(i = 0 ;i < n; i++)
        hn[i].weight = hc[i].weight;
    for( i = 0 ;i < n-1;i++)
    {
        m1 = m2 = 32767;  //设立最大权值
        x1 = x2 = 0;  
        //选取最小和次小的两个权值节点并将其下标保存到x1,x2中
        //权值保存到m1,m2中
        for(j = 0; j < n + i;j++)
        {
            if(hn[j].parent == -1 && hn[j].weight < m1)
            {
                m2 = m1;
                x2 = x1;
                m1 = hn[j].weight;
                x1 = j;
            }
            else
            {
                if(hn[j].parent == -1 && hn[j].weight < m2) 
                {
                    m2 = hn[j].weight;
                    x2 = j;
                }
            }
        }
        hn[x1].parent = n+i; //两个子树根节点的双亲节点序号是n+i
        hn[x2].parent = n+i;
        //下面这句表示新子树跟节点的权值是两个子树根节点权值的之和
        hn[n+i].weight = hn[x1].weight + hn[x2].weight ;
        hn[n+i].lchild = x1;
        hn[n+i].rchild = x2;
    }
    printf("\n\n**********************");
    printf("存放哈夫曼树的数组如下");
    printf("************************\n\n");
    printf("huff weight   lchild   rchild     parent     char\n");
    for(i = 0; i < 2*n-1;i++)
        printf("%3d%5d%10d%10d%10d\t\t%c\n",i,hn[i].weight,hn[i].lchild,\
               hn[i].rchild,hn[i].parent,hn[i].ch);
}
void CreateHuffCode(HNode *hn,HCode *hc,int n)
{
    HCode cd; //临时存放不完全的哈夫曼编码
    int i,j,c,p;
    for(i = 0;i < n;i++)
    {
        //hc[i].weight = hn[i].weight;
        cd.start = MAXBIT - 1;
        c = i; //c为叶子节点在haff数组中的下标
        p = hn[c].parent;
        while(p != -1)
        {
            if(hn[p].lchild == c)
                cd.bit[cd.start] = 0;
            else
                cd.bit[cd.start] = 1;
            cd.start--;
            c = p;
            p = hn[c].parent;
        }
        for(j = cd.start+1;j < MAXBIT;j++)
            hc[i].bit[j] = cd.bit[j];
        hc[i].start = cd.start;
    }
}
void BianMa(HCode *hc,int n ,char code[])
{
    int i ,k;   //k记录hc数组中与文件中读出来的字符相等的下标
    int j = 0;
    int bit[MAXBIT];
    FILE *fpread,*fpwrite;
    if( (fpread = fopen("a.source","r")) == NULL )
    {
        printf("opened error\n");
        exit(1);
    }
    if( (fpwrite = fopen("a.code","a+")) == NULL )
    {
        printf("opened error\n");
        exit(1);
    }

    char ch;
    while((ch = fgetc(fpread)) !=EOF )
    {
        if(ch == '\r' || ch == '\n')
            continue;
        for(i = 0; i < n;i++)
        {
            if(hc[i].ch == ch)
                k = i;
        }
        for(i = hc[k].start+1;i < MAXBIT;i++)
        {
            if(hc[k].bit[i] == 0)
            {
                //fputc(48,fpwrite);
                //code[j++] = 48;
                fputc('0',fpwrite);
                code[j++] = '0';

            }
            if(hc[k].bit[i] == 1)
            {
                //fputc(49,fpwrite);
                //code[j++] = 49;
                fputc('1',fpwrite);
                code[j++] = '1';
            }
        }
        
    }
    printf("\n\n********************");
    printf("恭喜！编码成功！结果已经存入文件!");
    printf("************************\n\n");
    
    fclose(fpread);
    fclose(fpwrite);
    
}
void LookCode(char code[])   //查看编码结果
{
    printf("编码结果:%s\n",code);
}
void YiMa(HNode *hn,char result[])
{
    FILE *fpread,*fpwrite;
    if( (fpread = fopen("a.code","r")) == NULL )
    {
        printf("opened error\n");
        exit(1);
    }
    if( (fpwrite = fopen("a.decode","a+")) == NULL )
    {
        printf("opened error\n");
        exit(1);
    }
    char readch;// 从文件a.code中读取的字符
    char writech; // 将要写入文件a.decode的字符
    int rooti;  //哈夫曼树根节点的下标
    int temp;
    int k = 0;
    for(int i = 0 ;i < MAXSIZE;i++)
    {
        if(hn[i].weight == 0)
            break;
        if(hn[i].parent == -1)
            rooti = i;
    }
    temp = rooti;
    while((readch = fgetc(fpread)) !=EOF )
    {
        
        if(readch == '\r' || readch == '\n')
            continue;
        if(readch == '1')
            temp = hn[temp].rchild;
        if(readch == '0')
            temp = hn[temp].lchild;
        if(hn[temp].lchild == -1 && hn[temp].lchild == -1)
        {
            writech = hn[temp].ch;
            fputc(writech,fpwrite);
            result[k++] = writech;
            temp = rooti;
        }
        result[k] = '\0';

    }

}
void LookDeCode(char result[])
{
    printf("\n\n********************");
    printf("恭喜！译码成功！结果已经存入文件!");
    printf("************************\n\n");
    printf("译码结果:%s\n",result);

}

int main()
{   
    char code[1024];  //存放编码结果
    char result[1024]; //存放译码结果
    int cch[256] = {0};   //cch记录字符出现的次数 下标是对应字符的ascii码
    HNode hn[MAXSIZE];     //哈夫曼树的所有节点
    HCode hc[MAXSIZE/2];   //叶子节点相关信息
    int n = TongJi(cch,hc);
    InitHaffTree(hc,hn,cch);
    CreateHuffTree(hn,hc,n);
    CreateHuffCode(hn,hc,n);
    Print(hn,hc);
    BianMa(hc,n,code);
    LookCode(code);
    YiMa(hn,result);
    LookDeCode(result);

    return 0;
}

