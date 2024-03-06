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

    // Método para insertar un nodo en el árbol
    void insert(PlayerAction action)
    {
        root = insertRec(root, action);
    }

    // Método de inserción recursiva
    BinaryTreeNode* insertRec(BinaryTreeNode* node, PlayerAction action)
    {
        if (node == nullptr)
        {
            return new BinaryTreeNode(action);
        }

        // Insertar en el subárbol izquierdo si la acción es menor
        if (action < node->action)
        {
            node->left = insertRec(node->left, action);
        }
        // Insertar en el subárbol derecho si la acción es mayor
        else if (action > node->action)
        {
            node->right = insertRec(node->right, action);
        }

        return node;
    }

    // Método para buscar una acción en el árbol
    bool search(PlayerAction action)
    {
        return searchRec(root, action);
    }

    // Método de búsqueda recursiva
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
    // Crear un árbol binario e insertar algunas acciones
    BinaryTree playerActionTree;
    playerActionTree.insert(PlayerAction::ATTACK);
    playerActionTree.insert(PlayerAction::DEFEND);

    // Buscar acciones en el árbol
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