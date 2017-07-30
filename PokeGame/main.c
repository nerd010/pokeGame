//
//  main.c
//  PokeGame
//
//  Created by chw on 16/2/21.
//  Copyright © 2016年 CHW. All rights reserved.
//

#include <stdio.h>

struct queue
{
    int data[1000];
    int head;
    int tail;
};

struct stack
{
    int data[10];
    int top;
};

int main(void)
{
    struct queue q1,q2;
    struct stack s;
    int book[10];
    int i, t;
    
    q1.head = 1;
    q1.tail = 1;
    q2.head = 1;
    q2.tail = 1;
    s.top = 0;
    
    //标记数组
    for(i = 1; i <= 9; i++)
    {
        book[i] = 0;
    }
    
    //小哼手中的6张牌
    for(i = 1; i <= 6; i++)
    {
        printf("请输入第%d张牌:\n",i);
        scanf("%d",&q1.data[q1.tail]);
        q1.tail++;
    }
    
    //小哈手中的6张牌
    for(i = 1; i <= 6; i++)
    {
        printf("请输入%d张牌：\n",i);
        scanf("%d",&q2.data[q2.tail]);
        q2.tail++;
    }
    
    /*
     开始游戏
     队列不为空时 执行循环
     */
    while (q1.head < q1.tail && q2.head < q2.tail)
    {
        t = q1.data[q1.head];
        
        if (book[t] == 0)
        {
            q1.head++;
            s.top++;
            s.data[s.top] = t; //入栈
            book[t] = 1; //标记现在桌面上已经有了牌面为 t 的牌
        }
        else
        {
            q1.head++;
            q1.data[q1.tail] = t;
            q1.tail++;
            
            while (s.data[s.top] != t)
            {
                book[s.data[s.top]] = 0;//取消标记
                q1.data[q1.tail] = s.data[s.top];
                q1.tail++;
                s.top--;
            }
            
            //取出 t
            book[s.data[s.top]] = 0;
            q1.data[q1.tail] = s.data[s.top];
            q1.tail++;
            s.top--;
        }
        
        //小哼出完牌，游戏结束
        if (q1.head == q1.tail)
        {
            break;
        }
        
        t = q2.data[q2.head];
        if (book[t] == 0)
        {
            q2.head++;
            s.top++;
            s.data[s.top] = t;
            
            book[t] = 1;
        }
        else
        {
            q2.head++;
            q2.data[q2.tail] = t;
            q2.tail++;
            
            while (s.data[s.top] != t)
            {
                book[s.data[s.top]] = 0;
                q2.data[q2.tail] = s.data[s.top];
                s.top--;
                q2.tail++;
            }
            
            book[s.data[s.top]] = 0;
            q2.data[q2.tail] = s.data[s.top];
            s.top--;
            q2.tail++;
        }
    }
    
    //小哈出完牌 游戏结束
    if(q2.head == q2.tail)
    {
        printf("小哼赢了！\n");
        printf("小哼手中的牌是：");
        for(i = q1.head; i <= q1.tail - 1; i++)
        {
            printf("%d ",q1.data[i]);
        }
        
        if (s.top > 0)
        {
            printf("\n桌面上的牌为:");
            for (i = 1; i <= s.top; i++)
            {
                printf("%d ",s.data[i]);
            }
        }
        else
        {
            printf("桌面上没有牌了！\n");
        }
    }
    else
    {
        printf("小哈赢了！\n");
        printf("小哈手中的牌为：");
        for (i = q2.head; i <= q2.tail - 1; i++)
        {
            printf("%d ",q2.data[i]);
        }
        
        if (s.top > 0)
        {
            printf("桌面上的牌为:");
            for (i = 1; i <= s.top; i++)
            {
                printf("%d ",s.data[i]);
            }
        }
        else
        {
            printf("桌面是没有牌了！\n");
        }
    }
    
    getchar();getchar();
    return 0;
}
