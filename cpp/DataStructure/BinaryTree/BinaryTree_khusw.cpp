/*
    Binary Tree

    이진 트리란 자식 노드를 최대 두개를 갖는 트리 구조를 말하며,
    각 트리의 노드들은 데이터, 좌우 자식 노드에 관한 포인터 값을 갖는다.

    이진 트리와 이진 탐색 트리의 차이점은
    이진 트리는 노드간 정렬이 되어있지 않고
    이진 탐색 트리는 노드간 키값 정렬이 되어 있는 구조이다.
    자세한 부분은 아래 링크 참조
    https://www.geeksforgeeks.org/difference-between-binary-tree-and-binary-search-tree/

    이를 c++ 로 직접 구현해보면 아래와 같다.
*/

#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left_child;
    Node* right_child;
};

class Tree {
   private:
    Node* root;
    int size;

   public:
    Tree();
    void insert_node(int data);
    void delete_node(int data);
    void delete_deepest_node(Node* root, Node* d_node);
    void search_node(int data);
    void print_size();
    void print_all_nodes();
};

Tree::Tree() {
    this->root = NULL;
    this->size = 0;
}

void Tree::insert_node(int data) {
    if (this->root == NULL) {
        root = new Node;
        root->data = data;
        root->left_child = NULL;
        root->right_child = NULL;
        this->size++;
    } else {
        queue<Node*> q;
        q.push(root);

        Node* temp;
        while (!q.empty()) {
            temp = q.front();
            q.pop();

            if (!(temp->left_child)) {
                temp->left_child = new Node;
                temp->left_child->data = data;
                temp->left_child->left_child = NULL;
                temp->left_child->right_child = NULL;
                this->size++;
                return;
            } else if (temp->left_child) {
                q.push(temp->left_child);
            }

            if (!(temp->right_child)) {
                temp->right_child = new Node;
                temp->right_child->data = data;
                temp->right_child->left_child = NULL;
                temp->right_child->right_child = NULL;
                this->size++;
                return;
            } else if (temp->right_child) {
                q.push(temp->right_child);
            }
        }
    }
}

void Tree::delete_node(int data) {
    if (this->root == NULL) {
        cout << "empty tree" << endl;
        return;
    } else {
        queue<Node*> q;
        q.push(this->root);

        Node* temp;             // 끝노드
        Node* key_node = NULL;  // data 와 일치하는 노드

        while (!q.empty()) {
            temp = q.front();
            q.pop();

            if (temp->data == data) {
                key_node = temp;
            }

            if (temp->left_child) {
                q.push(temp->left_child);
            }

            if (temp->right_child) {
                q.push(temp->right_child);
            }
        }

        if (key_node != NULL) {
            int tmp = temp->data;
            delete_deepest_node(root, temp);
            size--;
            key_node->data = tmp;
        }
    }
    return;
}

void Tree::delete_deepest_node(Node* root, Node* d_node) {
    queue<Node*> q;
    q.push(root);

    struct Node* temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp == d_node) {
            temp = NULL;
            delete (d_node);
            return;
        }
        if (temp->right_child) {
            if (temp->right_child == d_node) {
                temp->right_child = NULL;
                delete (d_node);
                return;
            } else
                q.push(temp->right_child);
        }

        if (temp->left_child) {
            if (temp->left_child == d_node) {
                temp->left_child = NULL;
                delete (d_node);
                return;
            } else
                q.push(temp->left_child);
        }
    }
}

void Tree::search_node(int data) {
    if (this->root->data == data) {
        cout << root->data << '\n';
        return;
    } else if (this->root == NULL) {
        cout << "empty tree" << '\n';
        return;
    }

    queue<Node*> q;
    q.push(this->root);

    Node* temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();

        if (temp->data == data) {
            cout << temp->data << '\n';
            return;
        }

        if (temp->left_child) {
            if (temp->left_child->data == data) {
                cout << temp->left_child->data << '\n';
                return;
            } else {
                q.push(temp->left_child);
            }
        }

        if (temp->right_child) {
            if (temp->right_child->data == data) {
                cout << temp->right_child->data << '\n';
                return;
            } else {
                q.push(temp->right_child);
            }
        }
    }
}

void Tree::print_size() {
    cout << this->size << '\n';
    return;
}

void Tree::print_all_nodes() {
    if (!(this->root)) {
        cout << "empty tree" << '\n';
        return;
    } else {
        queue<Node*> q;
        q.push(this->root);

        Node* temp;
        while (!q.empty()) {
            temp = q.front();
            cout << temp->data << ' ';
            q.pop();

            if (temp->left_child) {
                q.push(temp->left_child);
            }

            if (temp->right_child) {
                q.push(temp->right_child);
            }
        }
    }
    cout << '\n';
    return;
}

int main() {
    Tree* tree = new Tree();
    tree->insert_node(10);
    tree->insert_node(9);
    tree->insert_node(98);
    tree->insert_node(43);
    tree->insert_node(5);

    cout << " -- after insert -- " << '\n';
    tree->print_all_nodes();

    cout << " -- tree size : ";
    tree->print_size();

    cout << " -- search 9 : ";
    tree->search_node(9);

    tree->delete_node(98);
    cout << " -- after delete -- " << '\n';
    tree->print_all_nodes();

    cout << " -- tree size : ";
    tree->print_size();

    delete tree;

    return 0;
}