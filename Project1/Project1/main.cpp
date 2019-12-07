#include "Main.h"

/*
* 関数 : main
* @param  argc
* @param  argc[]
* @return int
*/
int main(int argc, char* argv[])
{
	char str[] = { 'A','B','B' ,'B' ,'B' ,'B' ,'C' ,'D' ,'E' ,'F' };

	// インスタンス生成
	NODE *nodes = NULL;
	CODE *codes = NULL;

	// NODE生成
	nodes = makeNodes(&str[0], sizeof(str));

	// 二分木生成
	makeHuffmanTree(nodes);

	// ハフマンコード生成
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

	// メモリ開放
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
* 関数 : mfreeNodeain
* @param  node : 検索対象文字
* 概要 : NODEの開放
*/
void freeNode(NODE *node) {
	NODE *next;

	while (node != NULL) {
		next = node->next;
		free(node);    // 開放
		node = next;
	}
}