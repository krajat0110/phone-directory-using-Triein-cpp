													/*N.I.T ROURKELA
													  NAME-NARAYAN SETHI
													  ROLL NO-116CS0233
													  BRANCH-COMPUTER SCIENCE AND ENGINEERING*/
													  
													  
/*Given a list of contacts which exist in a phone directory. The task is to implement search
query for the phone directory.The phonebook dictionary is designed using TRIE data
structure which on input any characters gives the names and numbers of all matching
names(prefix).*/


#include<bits/stdc++.h>
#include<string>
using namespace std;
map<string, long long int> contacts;
struct trie{
	struct trie *ch[26];
	bool islast;
};
struct trie* getnode(void)
{
	struct trie* p=new trie;
	for(int i=0;i<26;i++)
	p->ch[i]=NULL;
	p->islast=false;
}
struct trie *root=getnode();
void insertt(string key)
{
	struct trie *temp=root;
	for(int i=0;i<key.length();i++)
	{
		int id=key[i]-'a';
		if(temp->ch[id]==NULL)
		temp->ch[id]=getnode();
		temp=temp->ch[id];
	}
	temp->islast=true;
}
bool search(string str)
{
	struct trie *temp=root;
	for(int i=0;i<str.length();i++)
	{
		int id=str[i]-'a';
		if(temp->ch[id]==NULL)
		return false;
		temp=temp->ch[id];
	}
	if(temp!=NULL && temp->islast==true)
	return true;
}
void sug(struct trie *cur,string prefix)
{
//	cout<<prefix<<"\n";
	if(cur->islast==true)
	cout<<prefix<<"  "<<contacts[prefix]<<"\n";
	for(int i='a';i<='z';i++)
	{
		struct trie *next=cur->ch[i-'a'];
		if(next!=NULL)
		sug(next,prefix+(char)i);
	
	}
}
void displaycontacts(string str)
{
	string prefix="";
	int i;
	struct trie *prev=root;
	for(i=0;i<str.length();i++)
	{
		prefix+=str[i];
		int id=prefix[i]-'a';
		struct trie *current=prev->ch[id];
		if(current==NULL)
		{
			i++;
			cout<<"Not found";
			break;
		}
		if(i==str.length()-1)
		{
		cout<<"suggestions of "<<prefix<<" are\n";
		sug(current,prefix);
	}
		prev=current;
	//	cout<<"\n";
	}
	for (; i<str.length();i++)
    {
        prefix += (char)str[i];
        cout << "No Results Found for " << prefix
             << "\n";
    }
}
int main()
{
	while(1)
	{
		string name,choice;
		long long int phno;
		cout<<"Enter the contact's Name - ";
		cin>>name;
		cout<<"\nEnter the phone number of the contact - ";
		cin>>phno;
		insertt(name);
		contacts[name]=phno;
		cout<<"\nDo You Want To Add More Contacts\n";
		cin>>choice;
		if(choice=="no")
		break;
	}
	string search;
	cout<<"\nName or Prefix of the contact's name you want to search - ";
	cin>>search;
	displaycontacts(search);
}
