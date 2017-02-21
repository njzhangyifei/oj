// --------------------------------------------------------------------------------
  // INPUT:
// --------------------------------------------------------------------------------
// (AB) C((D E)F) /R
// (AB) C((D E)F) /RR
// (AB)C/RS
// A(((DE)F)C/S
// (AB)C((DE)F)/S
// (AB)C((DE)F)/SSRS
// (AB)C((DE)F)(((GGG)GG)G)/S
// (AB)C((DE)F)((GG(GGG)G))/S
// SS((SS)S)/SRS
// (AB)C((DE)F)/S
// (AB)C((DE)F)/SS
// (AB)C((DE)F)/SSS
  
// A(BCD)/RS
// (((AB)CD)EF)(GH)/S
// (((AB)CD)EF)(((((GH)IJ)KL)MN)OP)/S
// (AB)C((DE)F)/
// ABC





// --------------------------------------------------------------------------------
  // OUTPUT:
// --------------------------------------------------------------------------------
// (F(ED))C(BA)
// (AB)C((DE)F)
// C(BA)
// A((DEF)C)
// ABC(DEF)
// FEDCBA
// ABC(DEF)((GGGGG)G)
// ABC(DEF)(GG(GGG)G)
// SSSSS
// ABC(DEF)
// ABC(DEF)
// ABC(DEF)

// DCBA
// ((ABCD)EF)(GH)
// ((ABCD)EF)((((GHIJ)KL)MN)OP)
// (AB)C((DE)F)
// ABC

#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <stack>
#include <numeric>
#include <memory>
#include <set>
#include <map>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

#define TYPE_ELEM  (1)
#define TYPE_EXPR  (2)

class element
{
    public:
        int type;
        element (int t) : type(t){

        };

        element * parent;
        string get_string(){
            return "";
        };
    private:
        /* data */
};

class basic_element:public element
{
    public:
        char name;
        basic_element (char n) : element(TYPE_ELEM), name(n){

        };

        string get_string(){
            return string(1, name);
        }
    private:
        /* data */
};

class expression:public element
{
    public:
        expression (): element(TYPE_EXPR){

        };
        std::vector<element *> v_elements;

        void simplify(){
            std::vector<element *> new_v;
            auto curr = v_elements[0];
            if (curr->type == TYPE_EXPR) {
                while (curr->type == TYPE_EXPR) {
                    auto new_curr = ((expression *) curr)->v_elements[0];
                    curr = new_curr;
                }
                // curr is now the first element
                // cout << "current curr = " << ((basic_element *)curr)->get_string() << endl;
                //
                // double parent
                // unwrap parent of curr
                // cout << "curr is " << ((basic_element *)curr)->get_string() << endl;
                expression * parent = (expression *)(curr->parent);
                // cout << "parent is " << parent->get_string() << endl;
                expression * grandparent = (expression *)parent->parent;
                // cout << "grandparent is " << grandparent->get_string() << endl;
                // expand on this one
                int i;
                vector<element *> new_vec;
                for (i = 0; i < parent->v_elements.size(); ++i) {
                    new_vec.push_back(parent->v_elements[i]);
                }
                for (i = 1; i < grandparent->v_elements.size(); ++i) {
                    new_vec.push_back(grandparent->v_elements[i]);
                }
                for (auto i : new_vec) {
                    i->parent = grandparent;
                }
                grandparent->v_elements = new_vec;
                // cout << "after grandparent is " << grandparent->get_string() << endl;
            }
            new_v.push_back(v_elements[0]);
            int i;
            for (i = 1; i < v_elements.size(); ++i) {
                if (v_elements[i]->type == TYPE_EXPR ) {
                    // the one is an expression
                    expression * expr = (expression *)v_elements[i];
                    expr->simplify();
                }
                new_v.push_back(v_elements[i]);
            }
            v_elements = new_v;
        }

        void reverse(){
            int i;
            std::vector<element *> new_v;
            for (i = v_elements.size()-1; i >= 0; --i) {
                if ( v_elements[i]->type == TYPE_EXPR ) {
                    // expand this element
                    expression * expr = (expression *)v_elements[i];
                    expr->reverse(); // recur call
                }
                new_v.push_back(v_elements[i]);
            }
            v_elements = new_v;
        }

        string get_string(){
            size_t i;
            string s;
            for (i = 0; i < v_elements.size(); ++i) {
                string p = v_elements[i]->get_string();
                if (v_elements[i]->type == TYPE_ELEM) {
                    p = ((basic_element *)v_elements[i])->get_string();
                } else if (v_elements[i]->type == TYPE_EXPR) {
                    p = "(";
                    p += ((expression *)v_elements[i])->get_string();
                    p += ")";
                }
                s += p;
            }
            return s;
        }

    private:
        /* data */
};

void solve(string s){
    // split first
    size_t i;
    expression * root = new expression();
    root->parent = NULL;
    std::stack<expression *> layer;
    layer.push(root);
    for (i = 0; i < s.size(); ++i) {
        if (s[i] == '/') {
            break;
        }
        if (s[i] == ' ') {
            continue;
        }
        if (s[i] == '(') {
            expression * expr = new expression();
            auto curr_layer = layer.top();
            expr->parent = (element *)curr_layer;
            curr_layer->v_elements.push_back((element *)expr);
            layer.push(expr);
            continue;
        }
        if (s[i] == ')') {
            layer.pop();
            continue;
        }
        // this is an element
        auto curr_layer = layer.top();
        basic_element * el = new basic_element(s[i]);
        el->parent = (element *)curr_layer;
        curr_layer->v_elements.push_back((element*) el);
    }
    for (i++; i < s.size(); ++i) {
        // cout << "Operation: " << s[i] << endl;
        if (s[i] == 'S') {
            // cout << "simp    -> " << root->get_string() << endl;
                root->simplify();
            // cout << "simp-ed -> " << root->get_string() << endl;
        } else if (s[i] == 'R') {
            root->reverse();
        } else if (s[i] == ' ') {
            continue;
        }
    }
    cout << root->get_string() << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s;
    while (getline(cin, s)) {
        solve(s);
    }
    return 0;
}

