#include "Main.h"

/*
* �֐� : main
* @param  argc
* @param  argc[]
* @return int
*/
int main(int argc, char* argv[])
{
	char str[] = { 'A','B','B' ,'B' ,'B' ,'B' ,'C' ,'D' ,'E' ,'F' };

	// �C���X�^���X����
	NODE *nodes = NULL;
	CODE *codes = NULL;

	// NODE����
	nodes = makeNodes(&str[0], sizeof(str));

	// �񕪖ؐ���
	makeHuffmanTree(nodes);

	// �n�t�}���R�[�h����
	codes = makeHuffmanCode(nodes);
	int i = 0;
	while (codes != NULL)
	{
		printf("%c:", codes->chr);
		printBi(codes->value);
		codes = codes->next;
		printf("\n");
	}

	system("pause");

	// �������J��
	freeNode(nodes);

	return 0;
}


void printBi(int num) {
	int len = 4;
	int bit[8];
	int x;

	for (int i = 0; i < len; i++) {
		x = 1 << i;
		x = num & x;
		bit[len - i - 1] = x >> i;
	}

	for (int i = 0; i < len; i++) {
		printf("%d", bit[i]);
	}
}

/*
* �֐� : mfreeNodeain
* @param  node : �����Ώە���
* �T�v : NODE�̊J��
*/
void freeNode(NODE *node) {
	NODE *next;

	while (node != NULL) {
		next = node->next;
		free(node);    // �J��
		node = next;
	}
}