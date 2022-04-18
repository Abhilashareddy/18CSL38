# Binary Search Tree

## Algorithm


- [Binary Search Tree](#binary-search-tree)
  - [Algorithm](#algorithm)
    - [Creating Tree : createtree(NODE node, int data)](#creating-tree--createtreenode-node-int-data)
    - [Searching Tree: search(NODE node, int data)](#searching-tree-searchnode-node-int-data)
    - [Traversal Techniques](#traversal-techniques)

### Creating Tree : createtree(NODE node, int data)
1. If node is NULL
    -  Create new node
    -  assign data and links
    -  return node
2. else If data < node->data
   - node->left=createtree(node->left,data)
3. else If data > node->data
   - node->right=createtree(node->right, data)
4. otherwise return node

### Searching Tree: search(NODE node, int data)
1. if node is null
   - print "Element not found"
2. else if data < node->data
   - node->left=search(node->left,data)
3. else If data > node->data
   - node->right=search(node->right, data)
4. otherwise return node


### Traversal Techniques
| In-order  | Pre-order  | Post-order |
|---|---|---|
| left >> data >> right  | data >> left >> right  | left >> right >> data  |


