#pragma
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include"data.h"

extern NODE *newNode(char chr);
void getAppearance(NODE **first, NODE **scond, NODE *head); 
void makeHuffmanTree(NODE *head);
