#include"makeHuffmanCode.h"


CODE *makeHuffmanCode(NODE *node) {

	NODE *child = NULL;
	NODE *parent = NULL;
	CODE *code = NULL;
	CODE *top = NULL;
	CODE *add = NULL;

	/* 符号類 */
	int value;
	int bit;


	/* 葉全てに符号を割り当てたらループ終了 */
	/* 葉以外の節の文字は'\0' */
	while (node != NULL && node->chr != '\0') {
		/* 符号とそのビット数を0に初期化 */
		value = 0;
		bit = 0;

		/* CODE構造体を追加 */
		add = (CODE*)malloc(sizeof(CODE));
		if (add == NULL) {
			printf("malloc error\n");
			return NULL;
		}

		/* 追加したCODE構造体の文字を設定 */
		add->chr = node->chr;

		/* childは今注目している節へのポインタ */
		child = node;

		/* parentは今注目している節の親へのポインタ */
		parent = node->parent;

		/* 葉から根まで親を遡っていく */
		/* 根の節はparentがNULL */
		while (parent != NULL) {
			/* 親から見て今注目している節が左の子の場合 */
			if (parent->left == child) {
				/* ビット列（value）の一番左へビット0を追加 */
				value = value + (0 << bit);
				/* 親から見て今注目している節が右の子の場合 */
			}
			else if (parent->right == child) {
				/* ビット列（value）の一番左へビット1を追加 */
				value = value + (1 << bit);
			}
			/* ビット列のビット数を1増やす */
			bit++;

			/* 今注目している節の親を、新たな注目節に更新 */
			child = parent;

			/* 親も親の親に更新 */
			parent = parent->parent;
		}

		/* 符号を求め終わったので、
		追加したCODEに符号そのものとそのビット数を設定 */
		add->value = value;
		add->bit = bit;

		/* CODE構造体がまだ一つもない場合 */
		if (code == NULL) {
			code = add;
			top = code;

			/* CODE構造体がすでにある場合は最後尾に追加 */
		}
		else {
			code->next = add;
			code = code->next;
		}

		/* 次の節に対して符号を算出 */
		node = node->next;
	}

	return top;
}

