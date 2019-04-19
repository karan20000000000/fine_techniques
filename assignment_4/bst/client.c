#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
    tree_t tree;
    init_tree(&tree);
    int key;
    int opt;
    scanf("%d", &opt);
    while (opt)
    {
        switch (opt)
        {
        case 1:
            printf("enter key to insert : ");
            scanf("%d", &key);
            insert_key(&tree, key);
            break;
        case 2 : scanf("%d", &key);
        		 delete_key(&tree, key);
        		 break;
        case 3:
            printf("inorder\n");
            display_inorder(&tree);
            break;
        case 4:
            printf("preorder\n");
            display_preorder(&tree);
            break;
        }
        printf("enter option : ");
        scanf("%d", &opt);
    }
}
