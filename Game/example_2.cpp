/*#include <iostream>
#include <string>
#include <vector>

class DialogueOption {
public:
    std::string optionText;
    int optionVal; // Optional integer argument for additional processing
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
};

int main() {
    DialogueTree tree;

    tree.addDialogueNode(1, "You don't look like you are from around here. (1)");
    tree.addDialogueNode(2, "Newton, eh? I heard there's trouble brewing down there. (2)");
    tree.addDialogueNode(3, "Oh really? Then you must know Mr. Bowler. (3)");
    tree.addDialogueNode(4, "You liar! There ain't no Mr. Bowler, I made him up! (4)");
    tree.addDialogueNode(5, "Don't worry about it. Say do you have something to eat? I'm starving. (5)");

    tree.getDialogueNodeWithID(1)->addDialogueOption("I came here from Newton. (1-2)", tree.getDialogueNodeWithID(2));
    tree.getDialogueNodeWithID(1)->addDialogueOption("I've lived here all my life! (1-3)", tree.getDialogueNodeWithID(3));
    tree.getDialogueNodeWithID(1)->addDialogueOption("An option in node 1. Select to exit.", nullptr);

    tree.getDialogueNodeWithID(2)->addDialogueOption("Did i say Newton? I'm actually from Springville. (2-3)", tree.getDialogueNodeWithID(3));
    tree.getDialogueNodeWithID(2)->addDialogueOption("I haven't heard about any trouble. (2-5)", tree.getDialogueNodeWithID(5));
    tree.getDialogueNodeWithID(2)->addDialogueOption("An option in node 2. Select to exit.", nullptr);

    tree.getDialogueNodeWithID(3)->addDialogueOption("Who?. (3-5)", tree.getDialogueNodeWithID(5));
    tree.getDialogueNodeWithID(3)->addDialogueOption("Mr. Bowler is a good friend of mine! (3-4)", tree.getDialogueNodeWithID(4));
    tree.getDialogueNodeWithID(3)->addDialogueOption("An option in node 3. Select to exit.", nullptr);

    tree.getDialogueNodeWithID(3)->addDialogueOption("Select to go to node 1 and remove node 3 from the tree.",tree.getDialogueNodeWithID(1),1);

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

    return 0;
}*/