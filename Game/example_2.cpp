#include <iostream>

enum class ConversationOption
{
    OPTION_A,
    OPTION_B,
    OPTION_C,
    OPTION_D
};

class BinaryConversationNode
{
public:
    ConversationOption option;
    BinaryConversationNode* left;
    BinaryConversationNode* right;

    BinaryConversationNode(ConversationOption o) : option(o), left(nullptr), right(nullptr) {}
};

class ConversationTree
{
private:
    BinaryConversationNode* root;

public:
    ConversationTree() : root(nullptr) {}

    // Método para insertar un nodo en el árbol
    void insert(ConversationOption option)
    {
        root = insertRec(root, option);
    }

    // Método de inserción recursiva
    BinaryConversationNode* insertRec(BinaryConversationNode* node, ConversationOption option)
    {
        if (node == nullptr)
        {
            return new BinaryConversationNode(option);
        }

        // Insertar en el subárbol izquierdo si la opción es menor
        if (option < node->option)
        {
            node->left = insertRec(node->left, option);
        }
        // Insertar en el subárbol derecho si la opción es mayor
        else if (option > node->option)
        {
            node->right = insertRec(node->right, option);
        }

        return node;
    }

    // Método para buscar una opción en el árbol
    bool search(ConversationOption option)
    {
        return searchRec(root, option);
    }

    // Método de búsqueda recursiva
    bool searchRec(BinaryConversationNode* node, ConversationOption option)
    {
        if (node == nullptr)
        {
            return false;
        }

        if (option == node->option)
        {
            return true;
        }

        if (option < node->option)
        {
            return searchRec(node->left, option);
        }

        return searchRec(node->right, option);
    }
};

int main()
{
    // Crear un árbol de decisiones en una conversación e insertar algunas opciones
    ConversationTree conversationOptions;
    conversationOptions.insert(ConversationOption::OPTION_A);
    conversationOptions.insert(ConversationOption::OPTION_B);
    conversationOptions.insert(ConversationOption::OPTION_D);

    // Buscar opciones en el árbol
    if (conversationOptions.search(ConversationOption::OPTION_A))
    {
        printf("NPC ofrece la opcion A en la conversacion.\n");
    }
    if (!conversationOptions.search(ConversationOption::OPTION_A))
    {
        printf("NPC no ofrece la opcion A en la conversacion.\n");
    }

    if (conversationOptions.search(ConversationOption::OPTION_B))
    {
        printf("NPC ofrece la opcion B en la conversacion.\n");
    }
    if (!conversationOptions.search(ConversationOption::OPTION_B))
    {
        printf("NPC no ofrece la opcion B en la conversacion.\n");
    }

    if (conversationOptions.search(ConversationOption::OPTION_C))
    {
        printf("NPC ofrece la opcion C en la conversacion.\n");
    }
    if (!conversationOptions.search(ConversationOption::OPTION_C))
    {
        printf("NPC no ofrece la opcion C en la conversacion.\n");
    }

    if (conversationOptions.search(ConversationOption::OPTION_D))
    {
        printf("NPC ofrece la opcion D en la conversacion.\n");
    }
    if (!conversationOptions.search(ConversationOption::OPTION_D))
    {
        printf("NPC no ofrece la opcion D en la conversacion.\n");
    }

    return 0;
}