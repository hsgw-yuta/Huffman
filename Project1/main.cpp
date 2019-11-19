#include "Main.h"

#define MAX_BUFFER 256

typedef struct node NODE;
typedef struct code CODE;

NODE *makeNodes(char *inputstr);
NODE *searchNode(NODE *node, char chr);
NODE *newNode(char chr);

/* ハフマン木の節データ */
struct node {
	NODE *parent;
	NODE *left;
	NODE *right;
	NODE *next;
	unsigned int freq;
	char chr;
};

/* ハフマン符号データ */
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
		printf("nodes[%d]\n文字＝%c：回数＝%d\n", i, temp->chr, temp->freq);
		temp = temp->next;
		system("pause");
	}

	system("pause");

	return 0;
}

/*
指定されたchrを持つ節を探す関数
見つかった場合はその節へのポインタ、
見つからなかった場合はNULLを返却
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

/* 節を追加する関数 */
NODE *newNode(char chr) {
	NODE *node;

	node = (NODE*)malloc(sizeof(NODE));
	if (node == NULL) {
		return NULL;
	}

	/* 親や子を指すポインタはNULLで初期化 */
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

	/* 全文字読み終わるまで１文字ずつ読み取り */
	while (i < 10) {
		chr = *(inputstr + i);
		/* その文字に対応する節を探索 */
		search = searchNode(head, chr);
		if (search == NULL) {
			/* 節がない場合は新しく節を追加 */
			add = newNode(chr);
			if (add == NULL) {
				printf("node malloc error\n");
				return NULL;
			}

			/* 最初の節の場合はheadとtailにその節を指させる */
			if (head == NULL) {
				head = add;
				tail = add;
			}
			else {
				/* すでに節がある場合は終端に節を追加 */
				tail->next = add;
				tail = add;
			}
		}
		else {
			/* その文字に対応する節がある場合は出現関数をカウントアップ */
			search->freq++;
		}
		i++;
	}

	return head;
}