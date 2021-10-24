#include<iostream>
using namespace std;

class Tree
{
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr)
			:Data(Data), pLeft(pLeft), pRight(pRight) {}
		~Element() {}
		friend class Tree;

	}*Root;
public:
	int counter;
	Element* getRoot()const
	{
		return Root;
	}
	Tree() {this->Root = nullptr;}
	~Tree() {}
	void insert(int Data)
	{
		insert(Data, Root);
	}
	int minValue()const
	{
		return minValue(Root);
	}
	int maxValue()const
	{
		return maxValue(Root);
	}
	void print()const
	{
		print(this->Root);
		cout << endl;
	}
	int count()const
	{
		return count(this->Root);
	}
	int sum()const
	{
		return sum(Root);
	}
private:
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)
		{
			this->Root = new Element(Data);
			return;
		}
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr) Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else if(Data>Root->Data)
		{
			if (Root->pRight)insert(Data, Root->pRight);
			else Root->pRight = new Element(Data);
		}
	}
	int minValue(Element* Root)const
	{
		/*if (Root->pLeft == nullptr) return Root->Data;
		else return minValue(Root->pLeft);*/
		return Root->pLeft ? minValue(Root->pLeft) : Root->Data;
	}
	int maxValue(Element* Root)const
	{
		return Root->pRight ? maxValue(Root->pRight) : Root->Data;
	}
	void print(Element* Root)const
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << "\t";
		print(Root->pRight);
	}
	int count(Element* Root)const
	{
		return Root? count(Root->pLeft) + count(Root->pRight) + 1:0;
	}
	int sum(Element* Root)const
	{
		return Root ? sum(Root->pLeft) + sum(Root->pRight) + Root->Data : 0;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Enter the tree's size : "; cin >> n;
	Tree tree;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100);
	}
	tree.print();
	cout << "Min Value in tree: " << tree.minValue() << endl;
	cout << "Max Value in tree: " << tree.maxValue() << endl;
	cout << "Count of Value in tree: " << tree.count() << endl;
	cout << "Sum of Value in tree: " << tree.sum() << endl;
}