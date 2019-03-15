//introducing binary search tree
//including library
#include<iostream>
using namespace std;
class Node{
    public:
        //data for storing data
	    int data;
	    //pointers to move to left and right child
	    Node *left;
	    Node *right;
        Node(int value){
		          data = value;
		          left = NULL;
		          right = NULL;
	              }
};
class BST{
        public:
	    //pointer that points to root of the tree
	    Node *root;
        //constructor to initialize root as NULL
	    BST(){
		root = NULL;
	         }
	    //insert function
	    void insert(int value){
		           insertHelper(root,value);
	                           }
	   //function to insert values to the tree using recursion
	   void insertHelper(Node *curr, int value){
		                   //Base case if curr is NULL inserting there
		                   if(curr == NULL){
			                               curr = new Node(value);
			                               //update head
                                           if(root == NULL)
				                           root = curr;
                                           return;
                                           }
		 //else compare curr data with value
		 else if(value < curr->data){
                                //checks whether the left child of current is NULL or not and applying further conditions
			                    if(curr->left == NULL)
				                            curr->left = new Node(value);
			                    else
				                            insertHelper(curr->left,value);
                                    }
		 else{
			 if(curr->right == NULL)
				                curr->right = new Node(value);
			 else
				 insertHelper(curr->right,value);
		    }
	        }
	    //display function
	    void display(){
                    //recursive call
		            display2(root);
	                 }
        //display function using recursion
	    void display2(Node *curr){
		                        //applying conditions
		                        if(curr == NULL)
			                                return;
		                       //displays left
		                        display2(curr->left);
                                //displays current
		                        cout<<curr->data<<"->";
                                //displays right
		                        display2(curr->right);
	                             }
	  //function for searching
	  void search(int value){
		                   cout<<endl;
		                   Node * var;
		                   var = search2(root,value);
		                   if(var == NULL)
                                        cout<<"The element does not exist!"<<endl;
                           else
			                    cout<<"The element exist!"<<endl;
	                         }
	 //function for searching defined using recursion
	 //returns the address of the node containing the value to be searched
	 Node * search2(Node *curr,int value){
		                     //condition if value found or not
		                     if(curr == NULL || curr->data == value)
			                 return curr;
			                 //applying other conditions
		                     else if(value < curr->data)
                             return search2(curr->left,value);
                             else
			                 return search2(curr->right,value);
	                         }
};
//driver function
int main(){
	      //Variable declaration
          BST b1;
	      int x;
	      //insertion of values using loops
	      for(int i=1;i<6;i++)
		  b1.insert(i);
	      //display
	       b1.display();
	      //asking user for a value to be searched
	       cout<<endl<<"Enter a value to be searched:\n";
	       cin>>x;
	       b1.search(x);
//closing the programme
return 0;
}
