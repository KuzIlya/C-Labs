#include <iostream>
#include <stack>
#include <iomanip>

using namespace std;

struct Elem {
    char data;
    Elem* left;
    Elem* right;
    Elem(char val) : data(val), left(nullptr), right(nullptr) {}
};

bool is_op(char t) {
    return (t == '+' || t == '-' || t == '/' || t == '*');
}

std::string infixToPostfix(const std::string& expression) {
    std::stack<char> operators;
    std::string postfix;

    for (char c : expression) {
        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '(') {
            operators.push(c);
        }
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();
        }
        else {
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

Elem* buildExpressionTree(const string& infix) {
    string postfix = infixToPostfix(infix);
    stack<Elem*> st;

    for (char c : postfix) {
        if (isalnum(c)) {
            st.push(new Elem(c));
        }
        else if (is_op(c)) {
            Elem* right = st.top();
            st.pop();
            Elem* left = st.top();
            st.pop();
            Elem* newNode = new Elem(c);
            newNode->left = left;
            newNode->right = right;
            st.push(newNode);
        }
    }

    return st.top();
}

void printExpressionTree(Elem* root, int indent = 0) {
    if (root) {
        if (root->right) {
            printExpressionTree(root->right, indent + 5);
            cout << setw(indent) << "/" << "\n";
        }
        cout << setw(indent) << root->data << "\n";
        if (root->left) {
            cout << setw(indent) << "\\" << "\n";
            printExpressionTree(root->left, indent + 5);
        }
    }
}

int main() {
    string infix_expression = "(((a+b)*(c+d))+d)";

    Elem* expression_tree_root = buildExpressionTree(infix_expression);
    printExpressionTree(expression_tree_root);

    return 0;
}
