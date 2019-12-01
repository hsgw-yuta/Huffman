#include "Main.h"


int main(int argc, char* argv[]) 
{
	char str[] = { 'A','B','B','B','C','C','D','E','F','F' };

	// インスタンス生成
	NODE *nodes;
	CODE *code;

	// NODE生成
	nodes = makeNodes(&str[0]);

	// 二分木生成
	makeHuffmanTree(nodes);

	// ハフマンコード生成
	code = makeHuffmanCode(nodes);

	// メモリ開放
	freeNode(nodes);

	system("pause");

	return 0;
}


/* nodeが先頭を指すNODE構造体のリストを全削除する関数 */
void freeNode(NODE *node) {
	NODE *next;

	while (node != NULL) {
		next = node->next;
		free(node);
		node = next;
	}
}