#include "Main.h"

/*
* 関数 : main
* @param  argc     
* @param  argc[]   
* @return int 
*/
int main(int argc, char* argv[])
{
	char str[] = { 'A','B','B','B','C','C','D','E','F','F' };

	// インスタンス生成
	NODE *nodes;
	CODE *code;

	// NODE生成
	nodes = makeNodes(&str[0], strLength(&str[0]));

	// 二分木生成
	makeHuffmanTree(nodes);

	// ハフマンコード生成
	code = makeHuffmanCode(nodes);

	// メモリ開放
	freeNode(nodes);

	system("pause");

	return 0;
}

long strLength(char *str) {

	long len = 10;

	return len;
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