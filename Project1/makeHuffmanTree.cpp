#include"makeHuffmanTree.h"

/* 二分木生成 */
void makeHuffmanTree(NODE *head)
{
	NODE *first = NULL;
	NODE *second = NULL;
	NODE *tail = NULL;
	NODE *add = NULL;

	// 先頭の節の確認
	if (head == NULL)
	{
		printf("頭が無いよ");
	}

	// リストの終端までtailを移動 
	tail = head;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}

	// 出現回数を求める
	getAppearance(&first, &second, head);

	/* 親のいない節が２つ未満になるまでループ */
	while (first != NULL && second != NULL)
	{
		/* 新しいノードを追加 */
		/* 文字情報は'\0'とする */
		add = newNode('\0');
		if (add == NULL)
		{
			printf("malloc error\n");
			return;
		}


		/* 追加した節はleftとrightの親となるようにパラメータ設定 */
		first->parent = add;
		second->parent = add;
		add->left = first;
		add->right = second;
		add->count = first->count + second->count;

		/* 追加した節をリストの終端に登録 */
		tail->next = add;
		tail = add;

		/* 出現回数の少ない二つの節を取得 */
		getAppearance(&first, &second, head);
	}
}

/*
* 関数 : getAppearance
* @param  first : 出現回数最小
* @param  scond : 出現回数2番目
* @param  head  : Listの先頭address
* 概要 : 一番目と二番に出現回数出現回数が少ないNODEの取り出し
*/
void getAppearance(NODE **first, NODE **scond, NODE *head) {

	unsigned int firstNum = 99999;
	unsigned int secondNum = 99999;

	// 初期化
	*first = NULL;
	*scond = NULL;

	/* リストの先頭から探索 */
	while (head != NULL) {
		if (head->parent == NULL) {
			if (firstNum > head->count && secondNum > head->count) {
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
		/* headを次の節へ進ませる */
		head = head->next;
	}
}
