#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct person
{
	char name[20];
	int cm;
	int kg;
	double bmi;
}PERSON;
struct person cal_max_BMI(struct person* sp, int size);
int main(void)
{
	PERSON people[5], max;
	int i;
	srand((unsigned)time(NULL));
	for (i = 0; i < 5; i++)
	{
		printf("%d. 이름 : ", i + 1);
		scanf("%s", people[i].name);
		people[i].cm = rand() % 21 + 160;
		people[i].kg = rand() % 41 + 50;
		people[i].bmi = people[i].kg / ((people[i].cm / 100.0) * (people[i].cm / 100.0));
	}
	max = cal_max_BMI(people, 5);
	printf("가장 bmi가 큰 사람 : %s (%.2lf bmi)", max.name, max.bmi);
	return 0;
}
struct person cal_max_BMI(struct person* sp, int size)
{
	PERSON max = sp[0];
	int i;
	for (i = 0; i < size; i++)
	{
		if (max.bmi < sp[i].bmi)
		{
			max.bmi = sp[i].bmi;
			strcpy(max.name, sp[i].name);
			max.cm = sp[i].cm;
			max.kg = sp[i].kg;
		}
	}
	return max;
}