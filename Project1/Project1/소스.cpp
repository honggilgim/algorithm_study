#include <stdio.h>
int main() {
	char name[20];
	int c;
	int java;
	double grade;
	printf("이름 입력:");
	scanf_s("%s", &name, sizeof(name));
	printf("C언어, java 점수 입력:");
	scanf_s("%d %d", &c, &java);
	printf("평점 입력:");
	scanf_s("%lf", &grade);
	printf("이름:%s, C언어:%d, java:%d, 평점:%.1f\n", name, c, java, grade);
	return 0;
}