/*#include <iostream>

enum class PlayerAction
{
    ATTACK,
    DEFEND,
    IDLE
};

class BinaryTreeNode
{
public:
    PlayerAction action;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(PlayerAction a) : action(a), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
private:
    BinaryTreeNode* root;

public:
    BinaryTree() : root(nullptr) {}

    // M�todo para insertar un nodo en el �rbol
    void insert(PlayerAction action)
    {
        root = insertRec(root, action);
    }

    // M�todo de inserci�n recursiva
    BinaryTreeNode* insertRec(BinaryTreeNode* node, PlayerAction action)
    {
        if (node == nullptr)
        {
            return new BinaryTreeNode(action);
        }

        // Insertar en el sub�rbol izquierdo si la acci�n es menor
        if (action < node->action)
        {
            node->left = insertRec(node->left, action);
        }
        // Insertar en el sub�rbol derecho si la acci�n es mayor
        else if (action > node->action)
        {
            node->right = insertRec(node->right, action);
        }

        return node;
    }

    // M�todo para buscar una acci�n en el �rbol
    bool search(PlayerAction action)
    {
        return searchRec(root, action);
    }

    // M�todo de b�squeda recursiva
    bool searchRec(BinaryTreeNode* node, PlayerAction action)
    {
        if (node == nullptr)
        {
            return false;
        }

        if (action == node->action)
        {
            return true;
        }

        if (action < node->action)
        {
            return searchRec(node->left, action);
        }

        return searchRec(node->right, action);
    }
};

int main()
{
    // Crear un �rbol binario e insertar algunas acciones
    BinaryTree playerActionTree;
    playerActionTree.insert(PlayerAction::ATTACK);
    playerActionTree.insert(PlayerAction::DEFEND);

    // Buscar acciones en el �rbol
    if (playerActionTree.search(PlayerAction::ATTACK))
    {
        std::cout << "Player has the ATTACK action." << std::endl;
    }

    if (!playerActionTree.search(PlayerAction::ATTACK))
    {
        std::cout << "Player does not have the ATTACK action." << std::endl;
    }

    if (playerActionTree.search(PlayerAction::IDLE))
    {
        std::cout << "Player has the IDLE action." << std::endl;
    }

    if (!playerActionTree.search(PlayerAction::IDLE))
    {
        std::cout << "Player does not have the IDLE action." << std::endl;
    }

    if (playerActionTree.search(PlayerAction::DEFEND))
    {
        std::cout << "Player has the MOVE action." << std::endl;
    }

    if (!playerActionTree.search(PlayerAction::DEFEND))
    {
        std::cout << "Player does not have the MOVE action." << std::endl;
    }

    return 0;
}*/