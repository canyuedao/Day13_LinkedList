#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"
int* linklist::Create(int imax,int inum){
	int num=0;
	int *pAddr=new int[imax];//创建一个指向堆区的整型指针用以存放每个节点的地址
	for(int i=0;i<inum;i++){//创建一个班级人数为max的链表
		printf("请输入第%d个学生的学号、姓名并以空格分隔\n",i+1);
		char *pName=new char[20];
		scanf("%d %s",&num,pName);//读取学生学号和姓名并存入
		student *pStu=new student;//在堆空间中开辟一个节点
		pStu->num=num;//将学号和姓名
		pStu->name=pName;//存入开辟的节点中
		pAddr[i]=(int)pStu;//将节点的地址强转后存入int类型的指针

	}	
	//按学号排序，冒泡法
	for(int j=0;j<inum;j++){
		int num_min=((student*)pAddr[j])->num;//学号最小值初始化为循环的第一个
		int k=j;
		for(int i=j+1;i<inum;i++){			
			if((((student*)pAddr[i])->num)<num_min){
				num_min=((student*)pAddr[i])->num;		//每当后面的数比最小值小，就将该值赋给最小值		
				k=i;//保存取最小值时对应的位置				
			}
		}
		int temp=0;
		temp=pAddr[k];//将当次查找的最小值对应的地址
		pAddr[k]=pAddr[j];//和循环的第一个数的地址交换
		pAddr[j]=temp;
	}
	for (int i=0;i<inum-1;i++)	{//将排序后的链表数据按顺序打印到控制台
		((student*)pAddr[i])->next=(student*)pAddr[i+1];
		printf("学号:%d\n姓名:%s\n",((student*)pAddr[i])->num,((student*)pAddr[i])->name);
	}
	printf("学号:%d\n姓名:%s\n",((student*)pAddr[inum-1])->num,((student*)pAddr[inum-1])->name);
	((student*)pAddr[inum-1])->next=NULL;//
	return pAddr;//返回保存地址的int指针
}

//移除节点
int* linklist::remove(int iIndex,int *pAddr){
	//int *pAddr_Out=new int[max];
	for(int i=0;i<num;i++){
		if(((student*)pAddr[i])->num==iIndex){			
			printf("删除的学生学号：%d\n姓名：%s\n",iIndex,((student*)pAddr[i])->name);
			delete (student*)pAddr[i];	//删除对应节点		
			if(i>0&&i<num-1){
				((student*)pAddr[i-1])->next=(student*)pAddr[i+1];//将删除节点前一节点的next指针指向删除节点的后一节点
			}
			if(i==num-1){
				((student*)pAddr[i-1])->next=NULL;//如果是尾节点，则将它前一节点的next置为NULL
			}
			for(int j=i;j<num-1;j++){
				pAddr[j]=pAddr[j+1];//将删除节点之后的所有节点地址依次向前移动
			}
			pAddr[num-1]=0;
			printf("删除后的节点信息为：\n");
			for(int i=0;i<num-1;i++){
				printf("学号:%d\n姓名:%s\n",((student*)pAddr[i])->num,((student*)pAddr[i])->name);
			}
			num--;
			return pAddr;//返回保存地址的int指针
		}
	}
	printf("没有该节点，原节点信息为：\n");
	for(int i=0;i<num;i++){
		printf("%学号:%d\n姓名:%s\n",((student*)pAddr[i])->num,((student*)pAddr[i])->name);
	}
	return pAddr;

}

int* linklist::add(int iIndex,char *pName,int *pAddr){
	for(int i=0;i<num;i++){
		if(((student*)pAddr[i])->num==iIndex){
			printf("已有该学号，无法添加！\n");
			return pAddr;
		}
	}
	if((((student*)pAddr[0])->num)>iIndex){
		student *pStu=new student;//在堆空间中开辟一个节点
		pStu->num=iIndex;//将学号和姓名
		pStu->name=pName;//存入开辟的节点中
		pStu->next=(student*)pAddr[0];
		for(int i=num;i>=1;i--){
			pAddr[i]=pAddr[i-1];
		}		
		pAddr[0]=(int)pStu;		
		num++;
		return pAddr;
	}
	if((((student*)pAddr[num-1])->num)<iIndex){
		student *pStu=new student;//在堆空间中开辟一个节点
		pStu->num=iIndex;//将学号和姓名
		pStu->name=pName;//存入开辟的节点中
		pStu->next=NULL;			
		((student*)pAddr[num-1])->next=pStu;
		pAddr[num]=(int)pStu;		
		num++;
		return pAddr;
	}
	for(int i=0;i<num-1;i++){		
		if((((student*)pAddr[i])->num)<iIndex&&(((student*)pAddr[i+1])->num)>iIndex){
			student *pStu=new student;//在堆空间中开辟一个节点
			pStu->num=iIndex;//将学号和姓名
			pStu->name=pName;//存入开辟的节点中		
			pStu->next=(student*)pAddr[i+1];
			((student*)pAddr[i])->next=pStu;
			for(int j=num-2;j>=i;j--){
				pAddr[j+2]=pAddr[j+1];
			}
			pAddr[i+1]=(int)pStu;
			num++;
			return pAddr;
		}
	}
	return pAddr;
}