// Day13_LinkedList.cpp : �������̨Ӧ�ó������ڵ㡣
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
		printf("������༶����\n");			
		scanf("%d",&imax);
		printf("������Ҫ��ʼ��������\n");		
		scanf("%d",&inum);		
		llist->num=inum;
		pAddr=llist->Create(imax,llist->num);
		bool bchoice=true;
		while(bchoice){
			printf("Ҫɾ���ڵ��밴D\n��ӽڵ��밴A\nҪ���³�ʼ�������밴O\n");
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
				printf("��������ȷ�Ĳ�������\n");
			}				

		}
		
	}
	while(ichoice==2){
		printf("������Ҫ���ѧ����ѧ�ź��������Կո�ָ�\n");
		int i_anum=0;char *pName=new char[20];
		scanf("%d %s",&i_anum,pName);
		pAddr=llist->add(i_anum,pName,pAddr);
		printf("��Ӻ�Ľڵ���ϢΪ��\n");
		for(int i=0;i<llist->num;i++){
			printf("%ѧ��:%d\n����:%s\n",((student*)pAddr[i])->num,((student*)pAddr[i])->name);
		}
		bool bchoice=true;
		while(bchoice){
			printf("Ҫɾ���ڵ��밴D\n��ӽڵ��밴A\nҪ���³�ʼ�������밴O\n");
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
				printf("��������ȷ�Ĳ�������\n");
			}				

		}
	}
	while(ichoice==3){
		printf("������Ҫɾ����ѧ��ѧ��\n");
		int inum_del=0;
		scanf("%d",&inum_del);
		pAddr=llist->remove(inum_del,pAddr);
		bool bchoice=true;
		while(bchoice){
			printf("Ҫɾ���ڵ��밴D\n��ӽڵ��밴A\nҪ���³�ʼ�������밴O\n");
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
				printf("��������ȷ�Ĳ�������\n");
			}				

		}
	}
	
	
	return 0;
}
