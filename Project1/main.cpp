#include "Main.h"

#define MAX_BUFFER 256

typedef struct node NODE;
typedef struct code CODE;

NODE *makeNodes(char *inputstr);
NODE *searchNode(NODE *node, char chr);
NODE *newNode(char chr);

/* �n�t�}���؂̐߃f�[�^ */
struct node {
	NODE *parent;
	NODE *left;
	NODE *right;
	NODE *next;
	unsigned int freq;
	char chr;
};

/* �n�t�}�������f�[�^ */
struct code {
	char chr;
	int value;
	char bit;
	CODE *next;
};

int main(int argc, char* argv[]) {
	char str[] = { 'A','B','B','B','C','C','D','E','F','F' };

	NODE *nodes;
	CODE *code;

	nodes = makeNodes(&str[0]);

	NODE *temp = nodes;

	for (int i = 0; i < 10; i++) {
		printf("nodes[%d]\n������%c�F�񐔁�%d\n", i, temp->chr, temp->freq);
		temp = temp->next;
		system("pause");
	}

	system("pause");

	return 0;
}

/*
�w�肳�ꂽchr�����߂�T���֐�
���������ꍇ�͂��̐߂ւ̃|�C���^�A
������Ȃ������ꍇ��NULL��ԋp
*/
NODE *searchNode(NODE *node, char chr) {
	while (node != NULL) {
		if (node->chr == chr) {
			return node;
		}
		node = node->next;
	}
	return node;
}

/* �߂�ǉ�����֐� */
NODE *newNode(char chr) {
	NODE *node;

	node = (NODE*)malloc(sizeof(NODE));
	if (node == NULL) {
		return NULL;
	}

	/* �e��q���w���|�C���^��NULL�ŏ����� */
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	node->next = NULL;

	node->freq = 1;
	node->chr = chr;

	return node;
}

NODE *makeNodes(char *inputstr) {
	NODE *head;
	NODE *tail;
	NODE *add;
	NODE *search;
	char chr = NULL;


	head = NULL;
	tail = NULL;
	long i = 0;

	/* �S�����ǂݏI���܂łP�������ǂݎ�� */
	while (i < 10) {
		chr = *(inputstr + i);
		/* ���̕����ɑΉ�����߂�T�� */
		search = searchNode(head, chr);
		if (search == NULL) {
			/* �߂��Ȃ��ꍇ�͐V�����߂�ǉ� */
			add = newNode(chr);
			if (add == NULL) {
				printf("node malloc error\n");
				return NULL;
			}

			/* �ŏ��̐߂̏ꍇ��head��tail�ɂ��̐߂��w������ */
			if (head == NULL) {
				head = add;
				tail = add;
			}
			else {
				/* ���łɐ߂�����ꍇ�͏I�[�ɐ߂�ǉ� */
				tail->next = add;
				tail = add;
			}
		}
		else {
			/* ���̕����ɑΉ�����߂�����ꍇ�͏o���֐����J�E���g�A�b�v */
			search->freq++;
		}
		i++;
	}

	return head;
}