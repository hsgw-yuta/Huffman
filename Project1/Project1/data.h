#pragma once
// typedef
typedef struct node NODE;
typedef struct code CODE;


/* ハフマン木の節データ */
struct node {
	NODE *parent;        // 親address
	NODE *left;          // 左節address
	NODE *right;         // 右節address
	NODE *next;          // 子節address
	unsigned int count;  // 出現回数
	char chr;            // 文字
};

/* ハフマン符号データ */
struct code {
	char chr;
	int value;
	char bit;
	CODE *next;
};

