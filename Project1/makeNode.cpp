#include"makeNode.h"

/*
* 関数 : searchNode
* @param  chr   : 検索NODE
* @param  node  : 検索対象文字
* @return NODE* : 検索発見NODE
* 概要 : 第二引数の文字が格納されているNODEを検索
*/
NODE *searchNode(NODE *node, char chr)
{
	while (node != NULL)
	{
		if (node->chr == chr)
		{
			return node;
		}
		node = node->next;
	}
	return node;
}

/*
* 関数 : newNode
* @param  chr   : 格納文字
* @return NODE* : 新規生成NODE
* 概要 : 新規のNODEを生成し、引数の文字を格納/初期化
*/
NODE *newNode(char chr)
{
	// 新規NODE(return用)
	NODE *node;

	node = (NODE*)malloc(sizeof(NODE));

	if (node == NULL)
	{
		return NULL;
	}

	// NODE init
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	node->next = NULL;
	node->count = 1;
	node->chr = chr;

	return node;
}


/*
* 関数 : makeNodes
* @param  inputstr  : 検索文字列の先頭Address
* @return NODE*     : 先頭のNODEAddress
* 概要 : 各文字に対するNODEを生成
*/
NODE *makeNodes(char *instr,long strlen)
{

	NODE *head;		// 先頭NODE
	NODE *tail;		// 末端NODE
	NODE *add;      // 新規ResNODE
	NODE *search;   // 探索ResNODE

	// init
	char chr = NULL;
	head = NULL;
	tail = NULL;
	long i = 0;

	// 全文字読み取り
	while (i < strlen)
	{
		// 一文字読み取り
		chr = *(instr + i);

		// 取得文字に対する節を探索（同じ文字があるかどうか） 
		search = searchNode(head, chr);

		// 同一文字が無い場合
		if (search == NULL)
		{
			// 新しく節を追加 
			add = newNode(chr);

			if (add == NULL)
			{
				printf("node malloc error\n");
				return NULL;
			}

			// 一つもNODEが無い時、新規NODEを設定する
			if (head == NULL)
			{
				head = add;
				tail = add;
			}
			else 
			{
				tail->next = add;
				tail = add;
			}
		}
		else
		{
			// 出現回数のカウント
			search->count++;
		}

		i++;

	}
	return head;
}
