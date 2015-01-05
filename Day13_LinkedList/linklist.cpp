#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"
int* linklist::Create(int imax,int inum){
	int num=0;
	int *pAddr=new int[imax];//����һ��ָ�����������ָ�����Դ��ÿ���ڵ�ĵ�ַ
	for(int i=0;i<inum;i++){//����һ���༶����Ϊmax������
		printf("�������%d��ѧ����ѧ�š��������Կո�ָ�\n",i+1);
		char *pName=new char[20];
		scanf("%d %s",&num,pName);//��ȡѧ��ѧ�ź�����������
		student *pStu=new student;//�ڶѿռ��п���һ���ڵ�
		pStu->num=num;//��ѧ�ź�����
		pStu->name=pName;//���뿪�ٵĽڵ���
		pAddr[i]=(int)pStu;//���ڵ�ĵ�ַǿת�����int���͵�ָ��

	}	
	//��ѧ������ð�ݷ�
	for(int j=0;j<inum;j++){
		int num_min=((student*)pAddr[j])->num;//ѧ����Сֵ��ʼ��Ϊѭ���ĵ�һ��
		int k=j;
		for(int i=j+1;i<inum;i++){			
			if((((student*)pAddr[i])->num)<num_min){
				num_min=((student*)pAddr[i])->num;		//ÿ�������������СֵС���ͽ���ֵ������Сֵ		
				k=i;//����ȡ��Сֵʱ��Ӧ��λ��				
			}
		}
		int temp=0;
		temp=pAddr[k];//�����β��ҵ���Сֵ��Ӧ�ĵ�ַ
		pAddr[k]=pAddr[j];//��ѭ���ĵ�һ�����ĵ�ַ����
		pAddr[j]=temp;
	}
	for (int i=0;i<inum-1;i++)	{//���������������ݰ�˳���ӡ������̨
		((student*)pAddr[i])->next=(student*)pAddr[i+1];
		printf("ѧ��:%d\n����:%s\n",((student*)pAddr[i])->num,((student*)pAddr[i])->name);
	}
	printf("ѧ��:%d\n����:%s\n",((student*)pAddr[inum-1])->num,((student*)pAddr[inum-1])->name);
	((student*)pAddr[inum-1])->next=NULL;//
	return pAddr;//���ر����ַ��intָ��
}

//�Ƴ��ڵ�
int* linklist::remove(int iIndex,int *pAddr){
	//int *pAddr_Out=new int[max];
	for(int i=0;i<num;i++){
		if(((student*)pAddr[i])->num==iIndex){			
			printf("ɾ����ѧ��ѧ�ţ�%d\n������%s\n",iIndex,((student*)pAddr[i])->name);
			delete (student*)pAddr[i];	//ɾ����Ӧ�ڵ�		
			if(i>0&&i<num-1){
				((student*)pAddr[i-1])->next=(student*)pAddr[i+1];//��ɾ���ڵ�ǰһ�ڵ��nextָ��ָ��ɾ���ڵ�ĺ�һ�ڵ�
			}
			if(i==num-1){
				((student*)pAddr[i-1])->next=NULL;//�����β�ڵ㣬����ǰһ�ڵ��next��ΪNULL
			}
			for(int j=i;j<num-1;j++){
				pAddr[j]=pAddr[j+1];//��ɾ���ڵ�֮������нڵ��ַ������ǰ�ƶ�
			}
			pAddr[num-1]=0;
			printf("ɾ����Ľڵ���ϢΪ��\n");
			for(int i=0;i<num-1;i++){
				printf("ѧ��:%d\n����:%s\n",((student*)pAddr[i])->num,((student*)pAddr[i])->name);
			}
			num--;
			return pAddr;//���ر����ַ��intָ��
		}
	}
	printf("û�иýڵ㣬ԭ�ڵ���ϢΪ��\n");
	for(int i=0;i<num;i++){
		printf("%ѧ��:%d\n����:%s\n",((student*)pAddr[i])->num,((student*)pAddr[i])->name);
	}
	return pAddr;

}

int* linklist::add(int iIndex,char *pName,int *pAddr){
	for(int i=0;i<num;i++){
		if(((student*)pAddr[i])->num==iIndex){
			printf("���и�ѧ�ţ��޷���ӣ�\n");
			return pAddr;
		}
	}
	if((((student*)pAddr[0])->num)>iIndex){
		student *pStu=new student;//�ڶѿռ��п���һ���ڵ�
		pStu->num=iIndex;//��ѧ�ź�����
		pStu->name=pName;//���뿪�ٵĽڵ���
		pStu->next=(student*)pAddr[0];
		for(int i=num;i>=1;i--){
			pAddr[i]=pAddr[i-1];
		}		
		pAddr[0]=(int)pStu;		
		num++;
		return pAddr;
	}
	if((((student*)pAddr[num-1])->num)<iIndex){
		student *pStu=new student;//�ڶѿռ��п���һ���ڵ�
		pStu->num=iIndex;//��ѧ�ź�����
		pStu->name=pName;//���뿪�ٵĽڵ���
		pStu->next=NULL;			
		((student*)pAddr[num-1])->next=pStu;
		pAddr[num]=(int)pStu;		
		num++;
		return pAddr;
	}
	for(int i=0;i<num-1;i++){		
		if((((student*)pAddr[i])->num)<iIndex&&(((student*)pAddr[i+1])->num)>iIndex){
			student *pStu=new student;//�ڶѿռ��п���һ���ڵ�
			pStu->num=iIndex;//��ѧ�ź�����
			pStu->name=pName;//���뿪�ٵĽڵ���		
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