/*#include <iostream>
#include <string>
#include <vector>
#include "pugixml.hpp"

class DialogueOption {
public:
    std::string optionText;
    int optionVal;
    class DialogueNode* nextNode;

    DialogueOption(std::string text, class DialogueNode* node, int val = 0)
        : optionText(std::move(text)), nextNode(node), optionVal(val) {}
};

class DialogueNode {
public:
    int nodeID;
    std::string nodeText;
    std::vector<DialogueOption*> options;

    DialogueNode(int id, std::string text) : nodeID(id), nodeText(std::move(text)) {}

    void addDialogueOption(std::string text, DialogueNode* nextNode, int val = 0) {
        options.push_back(new DialogueOption(std::move(text), nextNode, val));
    }

    void removeDialogueOption(int index) {
        if (index >= 0 && index < options.size()) {
            delete options[index];
            options.erase(options.begin() + index);
        }
    }
};

class DialogueTree {
private:
    std::vector<DialogueNode*> nodes;

public:
    DialogueTree() {}

    void addDialogueNode(int id, std::string text) {
        nodes.push_back(new DialogueNode(id, std::move(text)));
    }

    DialogueNode* getDialogueNodeWithID(int id) {
        for (auto node : nodes) {
            if (node->nodeID == id) {
                return node;
            }
        }
        return nullptr;
    }

    void removeDialogueNode(int id) {
        for (auto it = nodes.begin(); it != nodes.end(); ++it) {
            if ((*it)->nodeID == id) {
                delete* it;
                nodes.erase(it);
                break;
            }
        }
    }

    DialogueNode* getFirstNode() {
        return (!nodes.empty()) ? nodes[0] : nullptr;
    }

    const std::vector<DialogueNode*>& getDialogueNodes() const {
        return nodes;
    }

    bool loadFromXML(const std::string& filename);
};

bool DialogueTree::loadFromXML(const std::string& filename) {
    pugi::xml_document doc;
    if (!doc.load_file(filename.c_str())) {
        std::cerr << "Error al cargar el archivo XML." << std::endl;
        return false;
    }

    for (pugi::xml_node node : doc.child("DialogueTree").children("DialogueNode")) {
        int id = node.attribute("ID").as_int();
        std::string text = node.child_value("Text");
        addDialogueNode(id, text);

        DialogueNode* currentNode = getDialogueNodeWithID(id);

        for (pugi::xml_node option : node.child("Options").children("Option")) {
            std::string optionText = option.child_value("Text");
            int nextNodeID = option.attribute("NextNode").as_int();
            int optionVal = option.attribute("Value").as_int();

            DialogueNode* nextNode = getDialogueNodeWithID(nextNodeID);
            currentNode->addDialogueOption(optionText, nextNode, optionVal);
        }
    }

    return true;
}

int main() {
    DialogueTree tree;

    // Cargar el árbol desde un archivo XML
    if (tree.loadFromXML("dialogue.xml")) {
        std::cout << "Árbol cargado desde XML con éxito.\n";

        // Iniciar la conversación
        DialogueNode* currentNode = tree.getFirstNode();

        while (currentNode != nullptr) {
            std::cout << "Node #" << currentNode->nodeID << ": " << currentNode->nodeText << "\n";
            for (int i = 0; i < currentNode->options.size(); ++i)
                std::cout << "\t[" << i + 1 << "] " << currentNode->options[i]->optionText << "\n";

            int input;
            std::cin >> input;
            --input;

            if (input < currentNode->options.size() && input >= 0) {
                if (currentNode->options[input]->optionVal == 1) {
                    DialogueNode* tmp = currentNode;
                    currentNode = currentNode->options[input]->nextNode;

                    for (auto it = tree.getDialogueNodes().begin(); it != tree.getDialogueNodes().end(); ++it) {
                        if ((*it)->nodeID != tmp->nodeID) {
                            for (int i = 0; i < (*it)->options.size(); ++i) {
                                if ((*it)->options[i]->nextNode == tmp) {
                                    tree.getDialogueNodeWithID((*it)->nodeID)->removeDialogueOption(i);
                                    tree.getDialogueNodeWithID((*it)->nodeID)->addDialogueOption(
                                        "A new option! Select this to exit.",
                                        nullptr);
                                }
                            }
                        }
                    }

                    tree.removeDialogueNode(tmp->nodeID);
                }
                else {
                    currentNode = currentNode->options[input]->nextNode;
                }
            }

            std::cout << "\n";
        }
    }
    else {
        std::cerr << "Error al cargar el árbol desde XML.\n";
    }

    return 0;
}*/