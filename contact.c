#include "contact.h"
void InitContact(Contact* pc)
{
	assert(pc);
	pc->count = 0;
	memset(pc->date, 0, sizeof(pc->date));//设置内存
}
void AddContact(Contact* pc)
{
	assert(pc);
	if (pc->count == MAX)//满了
	{
		printf("通讯录已满，无法添加\n");
		return;
	}
	printf("请输入名字：>");
	scanf("%s", pc->date[pc->count].name);
	printf("请输入年龄：>");
	scanf("%d", &(pc->date[pc->count].age));
	printf("请输入性别：>");
	scanf("%s", pc->date[pc->count].sex);
	printf("请输入电话：>");
	scanf("%s", pc->date[pc->count].tele);
	printf("请输入地址：>");
	scanf("%s", pc->date[pc->count].addr);
	pc->count++;
	printf("增加成功\n");
}
void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%-20s\t%-5s\t%-5s\t%12s\t%30s\n", "名字", "年龄", "性别", "电话", "地址");
	for (i = 0; i < pc->count; i++)
	{
		printf("%20s\t%3d\t%5s\t%12s\t%30s\n", pc->date[i].name,
			     
			pc->date[i].age,
			                                   pc->date[i].sex,
                                   pc->date[i].tele,
			                                    pc->date[i].addr);
	}
}
static int FindByName(Contact* pc, char name[])
{
	assert(pc);
	int i = 0;
	for(i=0;i<pc->count;i++)
		if (0 == strcmp(pc->date[i].name, name))
		{
			return i;
        }
	return -1;
}
void DelContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
		assert(pc);//判断若为空不删除
		int i = 0;
		if (pc->count == 0)
		{
			printf("通讯录为空，没有信息可以删除\n");
			return;
		}
	printf("请输入要删除人的名字：>");
	scanf("%s", name);
	//删除
	//1.查找
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	//2.删除//防止越界
	for (i = pos; i < pc->count - 1; i++)
	{
		pc->date[i] = pc->date[i + 1];
	}
	pc->count--;
	printf("删除成功\n");
}
void SearchContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找人的名字：>");
	scanf("%s ", &name);
	//1.查找
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
		return;
	}
	//2.打印
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", pc->date[pos].name,
			pc->date[pos].age,
			pc->date[pos].sex,
			pc->date[pos].tele,
			pc->date[pos].addr);
}
//修改
void ModifyContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改人的名字：>");
	scanf("%s", &name);
	//1.查找
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}
	printf("要修改的人信息已经查找到，接下来开始修改\n");
	//2.修改
	printf("请输入名字：>");
	scanf("%s", pc->date[pos].name);
	printf("请输入年龄:>");
	scanf("%s", &(pc->date[pos].age));
	printf("请输入性别:>");
	scanf("%s", pc->date[pos].sex);
	printf("请输入电话:>");
	scanf("%s", pc->date[pos].sex);
	printf("请输入地址:>");
	scanf("%s", pc->date[pos].addr);
	printf("修改成功\n");
}
int cmp_peo_by_name(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}
//按照名字来排序
void SortContact(Contact* pc)
{
	assert(pc);
	qsort(pc->date, pc->count, sizeof(PeoInfo), cmp_peo_by_name);
	printf("排序成功\n");
}
