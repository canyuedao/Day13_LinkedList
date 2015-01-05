
struct student{
	char num;
	char *name;
	student *next;
};
class linklist{
public:
	int* Create(int,int);
	int* remove(int,int*);
	int* add(int,char*,int*);
	int num;

};