f (balance > 1 && key < node->left->key)  
        return rightRotate(node);  
  
    // Right Right Case  
    //     if (balance < -1 && key > node->right->key)  
    //             return leftRotate(node);  
    //               
    //                   // Left Right Case  
    //                       if (balance > 1 && key > node->left->key)  
    //                           {  
    //                                   node->left = leftRotate(node->left);  
    //                                           return rightRotate(node);  
    //                                               }  
    //                                                 
    //                                                     // Right Left Case  
    //                                                         if (balance < -1 && key < node->right->key)  
    //                                                             {  
    //                                                                     node->right = rightRotate(node->right);  
    //                                                                             return leftRotate(node);  
    //                                                                                 }  
