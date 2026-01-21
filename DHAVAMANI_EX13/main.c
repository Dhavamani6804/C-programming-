#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// BINARY TREE NODE STRUCTURE
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// FUNCTION PROTOTYPES
struct TreeNode *createNode(int data);
struct TreeNode *insert(struct TreeNode *root, int data);
struct TreeNode *delete(struct TreeNode *root, int data);
struct TreeNode *search(struct TreeNode *root, int data);
void displayTree(struct TreeNode *root, int space);
struct TreeNode *findMin(struct TreeNode *root);
struct TreeNode *findMax(struct TreeNode *root);
int getHeight(struct TreeNode *root);
int countNodes(struct TreeNode *root);
void inorderTraversal(struct TreeNode *root);
void preorderTraversal(struct TreeNode *root);
void postorderTraversal(struct TreeNode *root);
void freeTree(struct TreeNode *root);

// FUNCTION IMPLEMENTATIONS

// Create a new tree node
struct TreeNode *createNode(int data)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a node into the binary tree
struct TreeNode *insert(struct TreeNode *root, int data)
{
    // If tree is empty, create new node
    if (root == NULL)
    {
        printf("Inserted %d as root node\n", data);
        return createNode(data);
    }

    // Otherwise, recur down the tree
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        printf("Value %d already exists in tree (duplicates not allowed)\n", data);
    }

    return root;
}

// Find minimum value node in a subtree
struct TreeNode *findMin(struct TreeNode *root)
{
    struct TreeNode *current = root;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

// Find maximum value node in a subtree
struct TreeNode *findMax(struct TreeNode *root)
{
    struct TreeNode *current = root;
    while (current && current->right != NULL)
    {
        current = current->right;
    }
    return current;
}

// Delete a node from the binary tree
struct TreeNode *delete(struct TreeNode *root, int data)
{
    if (root == NULL)
    {
        printf("Value %d not found in tree\n", data);
        return root;
    }

    // Find the node to be deleted
    if (data < root->data)
    {
        root->left = delete(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = delete(root->right, data);
    }
    else
    {
        // Node with the data found

        // Case 1: Node with no children (leaf node)
        if (root->left == NULL && root->right == NULL)
        {
            printf("Deleted leaf node with value %d\n", data);
            free(root);
            return NULL;
        }

        // Case 2: Node with only right child
        else if (root->left == NULL)
        {
            struct TreeNode *temp = root->right;
            printf("Deleted node with value %d (only right child)\n", data);
            free(root);
            return temp;
        }

        // Case 3: Node with only left child
        else if (root->right == NULL)
        {
            struct TreeNode *temp = root->left;
            printf("Deleted node with value %d (only left child)\n", data);
            free(root);
            return temp;
        }

        // Case 4: Node with two children
        else
        {
            // Find inorder successor (smallest in right subtree)
            struct TreeNode *temp = findMin(root->right);

            // Copy the inorder successor's data to this node
            root->data = temp->data;
            printf("Deleted node with value %d (replaced with inorder successor %d)\n", data, temp->data);

            // Delete the inorder successor
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

// Search for a node in the binary tree
struct TreeNode *search(struct TreeNode *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }

    // Search in left subtree
    if (data < root->data)
    {
        return search(root->left, data);
    }

    // Search in right subtree
    return search(root->right, data);
}

// Get height of the tree
int getHeight(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Count total nodes in the tree
int countNodes(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Inorder traversal (Left, Root, Right) - Returns sorted order for BST
void inorderTraversal(struct TreeNode *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Preorder traversal (Root, Left, Right)
void preorderTraversal(struct TreeNode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Postorder traversal (Left, Right, Root)
void postorderTraversal(struct TreeNode *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Display tree in a visual format
void displayTree(struct TreeNode *root, int space)
{
    if (root == NULL)
    {
        return;
    }

    // Increase distance between levels
    space += 5;

    // Process right child first
    displayTree(root->right, space);

    // Print current node after space
    printf("\n");
    for (int i = 5; i < space; i++)
    {
        printf(" ");
    }
    printf("%d\n", root->data);

    // Process left child
    displayTree(root->left, space);
}

// Free all allocated memory
void freeTree(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// MAIN FUNCTION
int main()
{
    struct TreeNode *root = NULL;
    int choice, data;

    printf("========== BINARY SEARCH TREE OPERATIONS ==========\n");

    while (1)
    {
        printf("\n========== MAIN MENU ==========\n");
        printf("1. Create/Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Search Node\n");
        printf("4. Display Tree\n");
        printf("5. Tree Traversals\n");
        printf("6. Tree Statistics\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // Create/Insert
            printf("Enter value to insert: ");
            scanf("%d", &data);
            if (root == NULL)
            {
                root = createNode(data);
                printf("Created tree with root node %d\n", data);
            }
            else
            {
                root = insert(root, data);
            }
            break;

        case 2: // Delete
            if (root == NULL)
            {
                printf("Tree is empty! Create a tree first.\n");
                break;
            }
            printf("Enter value to delete: ");
            scanf("%d", &data);
            root = delete(root, data);
            break;

        case 3: // Search
            if (root == NULL)
            {
                printf("Tree is empty! Create a tree first.\n");
                break;
            }
            printf("Enter value to search: ");
            scanf("%d", &data);
            struct TreeNode *result = search(root, data);
            if (result != NULL)
            {
                printf("Value %d found in the tree\n", data);
            }
            else
            {
                printf("Value %d not found in the tree\n", data);
            }
            break;

        case 4: // Display Tree
            if (root == NULL)
            {
                printf("Tree is empty!\n");
            }
            else
            {
                printf("\nBinary Tree Structure (rotated 90° clockwise):\n");
                printf("============================================\n");
                displayTree(root, 0);
                printf("\n");
            }
            break;

        case 5: // Tree Traversals
            if (root == NULL)
            {
                printf("Tree is empty!\n");
                break;
            }

            printf("\n--- Tree Traversals ---\n");
            printf("1. Inorder (Sorted Order): ");
            inorderTraversal(root);
            printf("\n");

            printf("2. Preorder: ");
            preorderTraversal(root);
            printf("\n");

            printf("3. Postorder: ");
            postorderTraversal(root);
            printf("\n");
            break;

        case 6: // Tree Statistics
            if (root == NULL)
            {
                printf("Tree is empty!\n");
                break;
            }
            printf("\n--- Tree Statistics ---\n");
            printf("Total Nodes: %d\n", countNodes(root));
            printf("Tree Height: %d\n", getHeight(root));

            struct TreeNode *minNode = findMin(root);
            struct TreeNode *maxNode = findMax(root);
            if (minNode != NULL)
            {
                printf("Minimum Value: %d\n", minNode->data);
            }
            if (maxNode != NULL)
            {
                printf("Maximum Value: %d\n", maxNode->data);
            }
            printf("Root Value: %d\n", root->data);
            break;
        case 7: // Exit
            printf("\nExiting program...\n");
            freeTree(root);
            printf("All memory freed. Program terminated.\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}