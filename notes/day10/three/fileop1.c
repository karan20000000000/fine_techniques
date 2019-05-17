#include <stdio.h>
struct what
{
	char name[20];
	int age;
};
typedef struct what what_t;

int main()
{
	what_t w;
	int pos; int opt;
	FILE *fp = fopen("what.txt", "r+");
	scanf("%d", &opt);
	while(opt)
	{
		switch(opt)
		{
			case 1 : scanf("%s %d %d", w.name, &w.age, &pos);
					 fseek(fp, pos * sizeof(what_t), 0);
					 fwrite(&w, sizeof(what_t), 1, fp);
					 break;
			case 2 : scanf("%d", &pos);
					 fseek(fp, pos * sizeof(what_t), 0);
					 fread(&w, sizeof(what_t), 1, fp);
					 printf("name : %s age : %d\n", w.name, w.age);
					 break;
		}
		scanf("%d", &opt);
	}
	fclose(fp);
}
