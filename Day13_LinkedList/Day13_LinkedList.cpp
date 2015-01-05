// Day13_LinkedList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <stdlib.h>
#include "linklist.h"
using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{
	int ichoice=1;
	linklist *llist=new linklist();
	int imax=0;	
	int inum=0;
	int *pAddr=NULL;	
	
	while(ichoice==1){
		printf("请输入班级人数\n");			
		scanf("%d",&imax);
		printf("请输入要初始化的人数\n");		
		scanf("%d",&inum);		
		llist->num=inum;
		pAddr=llist->Create(imax,llist->num);
		bool bchoice=true;
		while(bchoice){
			printf("要删除节点请按D\n添加节点请按A\n要重新初始化链表请按O\n");
			char c=0;
			scanf(" %c",&c);
			if(c=='D'||c=='d'){
				ichoice=3;
				bchoice=false;
			}				
			else if(c=='A'||c=='a'){
				ichoice=2;
				bchoice=false;
			}
			else if(c=='O'||c=='o'){
				ichoice=1;
				bchoice=false;
			}
			else{
				bchoice=true;
				printf("请输入正确的操作命令\n");
			}				

		}
		
	}
	while(ichoice==2){
		printf("请输入要添加学生的学号和姓名，以空格分隔\n");
		int i_anum=0;char *pName=new char[20];
		scanf("%d %s",&i_anum,pName);
		pAddr=llist->add(i_anum,pName,pAddr);
		printf("添加后的节点信息为：\n");
		for(int i=0;i<llist->num;i++){
			printf("%学号:%d\n姓名:%s\n",((student*)pAddr[i])->num,((student*)pAddr[i])->name);
		}
		bool bchoice=true;
		while(bchoice){
			printf("要删除节点请按D\n添加节点请按A\n要重新初始化链表请按O\n");
			char c=0;
			scanf(" %c",&c);
			if(c=='D'||c=='d'){
				ichoice=3;
				bchoice=false;
			}				
			else if(c=='A'||c=='a'){
				ichoice=2;
				bchoice=false;
			}
			else if(c=='O'||c=='o'){
				ichoice=1;
				bchoice=false;
			}
			else{
				bchoice=true;
				printf("请输入正确的操作命令\n");
			}				

		}
	}
	while(ichoice==3){
		printf("请输入要删除的学生学号\n");
		int inum_del=0;
		scanf("%d",&inum_del);
		pAddr=llist->remove(inum_del,pAddr);
		bool bchoice=true;
		while(bchoice){
			printf("要删除节点请按D\n添加节点请按A\n要重新初始化链表请按O\n");
			char c=0;
			scanf(" %c",&c);
			if(c=='D'||c=='d'){
				ichoice=3;
				bchoice=false;
			}				
			else if(c=='A'||c=='a'){
				ichoice=2;
				bchoice=false;
			}
			else if(c=='O'||c=='o'){
				ichoice=1;
				bchoice=false;
			}
			else{
				bchoice=true;
				printf("请输入正确的操作命令\n");
			}				

		}
	}
	
	
	return 0;
}
