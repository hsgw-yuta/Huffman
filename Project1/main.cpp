#include "Main.h"

/*
* �֐� : main
* @param  argc     
* @param  argc[]   
* @return int 
*/
int main(int argc, char* argv[])
{
	char str[] = { 'A','B','B','B','C','C','D','E','F','F' };

	// �C���X�^���X����
	NODE *nodes;
	CODE *code;

	// NODE����
	nodes = makeNodes(&str[0], strLength(&str[0]));

	// �񕪖ؐ���
	makeHuffmanTree(nodes);

	// �n�t�}���R�[�h����
	code = makeHuffmanCode(nodes);

	// �������J��
	freeNode(nodes);

	system("pause");

	return 0;
}

long strLength(char *str) {

	long len = 10;

	return len;
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