#include"makeHuffmanTree.h"

/*
* 関数 : makeHuffmanTree
* @param  head  : Listの終端Address
* 概要 : 二分木生成
*/
void makeHuffmanTree(NODE *head)
{
	NODE *first = NULL;    // 出現回数最小NODE
	NODE *second = NULL;   // 出現回数2番目NODE
	NODE *tail = NULL;     // 最後尾NODE
	NODE *add = NULL;      // 新規NODE

	// 先頭の節の確認
	if (head == NULL)
	{
		printf("head null");
		return;
	}

	// リストの終端までtailを移動 
	tail = head;
  
	// tailの後ろに追加していく
	while (tail->next != NULL)
	{
		tail = tail->next;
	}

	// 出現回数の少ない上位2つを取得
	getAppearance(&first, &second, head);

	// 親のいない節が２つ未満になるまで
	// 
	while (first != NULL && second != NULL)
	{
		// 二つ以上あるので、親NODEを作成する
		add = newNode('\0');

		if (add == NULL)
		{
			printf("malloc error\n");
			return;
		}

		// 親NODE init
		first->parent = add;
		second->parent = add;
		add->left = first;
		add->right = second;

		// countの合計
		add->count = first->count + second->count;

		// Listの終端に追加
		tail->next = add;
		tail = add;
		getAppearance(&first, &second, head);
	}
}

/*
* 関数 : getAppearance
* @param  *first : 出現回数最小
* @param  *scond : 出現回数2番目
* @param  head  : Listの先頭address
* 概要 : 一番目と二番に出現回数出現回数が少ないNODEの取り出し
*/
void getAppearance(NODE **first, NODE **scond, NODE *head) 
{
	unsigned int firstNum = 99999;
	unsigned int secondNum = 99999;

	// 初期化
	*first = NULL;
	*scond = NULL;

	// リストの先頭から探索 (SORT)
	while (head != NULL) 
	{
		if (head->parent == NULL) 
		{
			if (firstNum > head->count && secondNum > head->count)
			{
				firstNum = head->count;
				*scond = *first;
				*first = head;
			}
			else if (secondNum > head->count)
			{
				secondNum = head->count;
				*scond = head;
			}
		}

		head = head->next;
	}
}
