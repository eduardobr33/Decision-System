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

    // M�todo para insertar un nodo en el �rbol
    void insert(ConversationOption option)
    {
        root = insertRec(root, option);
    }

    // M�todo de inserci�n recursiva
    BinaryConversationNode* insertRec(BinaryConversationNode* node, ConversationOption option)
    {
        if (node == nullptr)
        {
            return new BinaryConversationNode(option);
        }

        // Insertar en el sub�rbol izquierdo si la opci�n es menor
        if (option < node->option)
        {
            node->left = insertRec(node->left, option);
        }
        // Insertar en el sub�rbol derecho si la opci�n es mayor
        else if (option > node->option)
        {
            node->right = insertRec(node->right, option);
        }

        return node;
    }

    // M�todo para buscar una opci�n en el �rbol
    bool search(ConversationOption option)
    {
        return searchRec(root, option);
    }

    // M�todo de b�squeda recursiva
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
    // Crear un �rbol de decisiones en una conversaci�n e insertar algunas opciones
    ConversationTree conversationOptions;
    conversationOptions.insert(ConversationOption::OPTION_A);
    conversationOptions.insert(ConversationOption::OPTION_B);
    conversationOptions.insert(ConversationOption::OPTION_D);

    // Buscar opciones en el �rbol
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