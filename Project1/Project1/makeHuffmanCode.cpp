#include"makeHuffmanCode.h"

/*
* 関数 : makeHuffmanCode
* @param  *node : 二分木NODE
* @return CODE* : 符号化List
* 概要 : 各文字の符号の算出
*/
CODE *makeHuffmanCode(NODE *node)
{
	NODE *child = NULL;   // 子NODE
	NODE *parent = NULL;  // 親NODE
	CODE *code = NULL;    // 符号データ
	CODE *top = NULL;     // 符号データ先頭
	CODE *add = NULL;     // 新規符号データ

	// 符号CODE内データ
	int value = 0;
	int bit = 0;

	// 葉のすべてに符号を割り当てる
	while (node != NULL && node->chr != '\0')
	{

		// 符号とそのビット数を0に初期化
		value = 0;
		bit = 0;

		// 新規CODE生成
		add = (CODE*)malloc(sizeof(CODE));
		if (add == NULL)
		{
			printf("malloc error\n");
			return NULL;
		}

		// 追加CODEに文字をセットする
		add->chr = node->chr;

		// 現在スポットされているNODEの退避
		child = node;

		// 現在スポットされている親NODEへのポインタ 
		parent = node->parent;

		// 葉から根まで親をさかのぼる 
		while (parent != NULL)
		{
			// 親からの節
			if (parent->left == child)
			{
				// ビット列（value）の一番左へビット0を追加 
				value = value + (0 << bit);
			}
			else if (parent->right == child)
			{
				// ビット列（value）の一番左へビット1を追加 
				value = value + (1 << bit);
			}

			// bit数をインクリメント
			bit++;

			// 現在スポットの更新
			child = parent;

			// 親の更新
			parent = parent->parent;
		}

		// 新規CODEへの値セット
		add->value = value;
		add->bit = bit;
		add->next = NULL;

		// CODE構造体がすでにある場合は最後尾に追加
		if (code == NULL)
		{
			code = add;
			top = code;
		}
		else
		{
			code->next = add;
			code = code->next;
		}

		// NODEのインクリメント
		node = node->next;
	}

	return top;
}

