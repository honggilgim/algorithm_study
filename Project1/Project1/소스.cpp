#include <stdio.h>
int main() {
	char name[20];
	int c;
	int java;
	double grade;
	printf("�̸� �Է�:");
	scanf_s("%s", &name, sizeof(name));
	printf("C���, java ���� �Է�:");
	scanf_s("%d %d", &c, &java);
	printf("���� �Է�:");
	scanf_s("%lf", &grade);
	printf("�̸�:%s, C���:%d, java:%d, ����:%.1f\n", name, c, java, grade);
	return 0;
}