#include <stdio.h>
#include <stdlib.h>
#include "a4.h"

int main()
{
    tree_t tree;
    FILE *fp;
    fp = init_tree(&tree, "mytree.dat");
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
            insert_key(&tree, key, fp);
            break;
        case 2 : scanf("%d", &key);
        		 delete_key(&tree, key, fp);
        		 break;
        case 3:
            printf("inorder\n");
            display_inorder(&tree, fp);
            break;
        case 4:
            printf("preorder\n");
            display_preorder(&tree, fp);
            break;
        }
        printf("enter option : ");
        scanf("%d", &opt);
    }
}
