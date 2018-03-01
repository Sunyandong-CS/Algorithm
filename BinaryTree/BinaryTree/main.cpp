//
//  main.cpp
//  BinaryTree
//
//  Created by 孙艳东 on 2018/2/28.
//  Copyright © 2018年 com.xidian.edu.cn. All rights reserved.
//

#include <iostream>
#include "binaryTree.cpp"

int main(int argc, const char * argv[]) {
    BiTree tree;
    string str;
    str = "ABD##E#F##C##";
    tree.createBiTree(str);
    cout<<"前序遍历: "<<endl;
    tree.preOrder();
    tree.preOrderNonrecursion();
    cout<<"中序遍历: "<<endl;
    tree.inOrder();
    tree.inOrderNonrecursion();  
    cout<<"后序遍历: "<<endl;
    tree.postOrder();
    tree.postOrderNonrecursion();
    cout<<"层序遍历: "<<endl;
    tree.levelOrder();
    return 0;
}
