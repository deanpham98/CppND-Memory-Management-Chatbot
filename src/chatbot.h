#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <iostream>
#include <string>
#include <memory>
#include <functional>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    std::unique_ptr<wxBitmap> _image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////

    // Copy-Constructor
    ChatBot(const ChatBot&) = delete;

    // Move-Constructor
    ChatBot(ChatBot&& src) noexcept : _image(std::move(src._image)), \
                                      _currentNode(src._currentNode), \
                                      _rootNode(src._rootNode), \
                                      _chatLogic(src._chatLogic) {
        std::cout << "ChatBot Move Constructor" << std::endl;
    }

    // Copy-Assignment
    ChatBot& operator=(const ChatBot&) = delete;

    // Move-Assignment
    ChatBot& operator=(ChatBot&&) noexcept;

    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    wxBitmap *GetImageHandle() { return _image.get(); }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */