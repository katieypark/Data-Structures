#include <iostream>
// IntItem definition from above inserted here
// your printLL function is here as well.
using namespace std;

struct IntItem {
	int value;
	IntItem *next;
	IntItem (int v, IntItem *n) { value = v; next = n; }
};

void printLL (IntItem* head) {
	if(head == NULL) {
		cout << endl;
		return;
	}
	else {
		cout << head->value << " ";
		printLL(head->next);
	}
}

IntItem* mystery1 (int start, int end) {
	if(start < end) return new IntItem(start, mystery1(start+1,end));
	else return NULL;
}
IntItem* mystery2 (IntItem* head, IntItem* prev) {
	if(head != NULL) return mystery2(head->next, new IntItem(head->value, prev));
	else return prev;
}
int main() {
	IntItem* p1 = mystery1(0,5);
	printLL(p1);
	IntItem* p2 = mystery2(p1, NULL);
	printLL(p2);
return 0;
}