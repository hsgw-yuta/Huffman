#include "Main.h"


int main(int argc, char* argv[]) 
{
	char str[] = { 'A','B','B','B','C','C','D','E','F','F' };

	// �C���X�^���X����
	NODE *nodes;
	CODE *code;

	// NODE����
	nodes = makeNodes(&str[0]);

	// �񕪖ؐ���
	makeHuffmanTree(nodes);

	// �n�t�}���R�[�h����
	code = makeHuffmanCode(nodes);

	// �������J��
	freeNode(nodes);

	system("pause");

	return 0;
}


/* node���擪���w��NODE�\���̂̃��X�g��S�폜����֐� */
void freeNode(NODE *node) {
	NODE *next;

	while (node != NULL) {
		next = node->next;
		free(node);
		node = next;
	}
}