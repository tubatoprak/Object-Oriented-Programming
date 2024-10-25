#include <iostream>
#include <string>

using namespace std;

//I learned from the internet and got help 
class Document
{
	public:
		Document()      
		{ 
			text = "";
		}
		Document(string text)  
	    { 
	    	this->text = text;   
		}
		string getText() const
		{
			return this->text;
		}
		Document& operator = (const Document& rSide)
		{
			this->text = rSide.text;
			return *this;
		}
	private:
		string text;
};

class Email : public Document
{
	public:
		Email() : Document() 
		{

		}
		Email(string body, string sender, string recipient, string title): Document(body)
		{
			this->sender = sender;
			this->recipient =recipient;
			this->title =title;
		}

		void setRecipient(string str)
		{
			recipient = str;
		}
		string getRecipient()
		{
			return recipient;
		}
		void setSender(string str) 
		{
			sender = str;
		}
		string getSender()
		{
			return sender;
		}
		void setTitle(string str)
		{
			title = str;
		}
		string getTitle()
		{
			return title;
		}
		Email& operator =(const Email& rightSide)
		{
			Document::operator =(rightSide);
			sender = rightSide.sender;recipient = rightSide.recipient;
			title = rightSide.title;
			return *this;
		}
	private:
		string sender;
		string recipient;
		string title;
};

class File : public Document
{
	public:
	File() : Document()
	{
	}
	File(string body, string pathname) :Document(body)
	{
		this->pathname = pathname;
	}
	void setPathname(string str)
	{
		pathname = str;
	}
	string getPathname()
	{
		return pathname;
	}
	File& operator = (const File& rSide)
	{
		Document::operator =(rSide);
		pathname = rSide.pathname;
		return *this;
	}
	private:
		string pathname;
};

bool ContainsKeyword(const Document& docObject, string keyword)
{
	if (docObject.getText().find(keyword) != string::npos) 
		return true;
	return false;
}

int main()
{ 
	Email email1("give back your debt",  "Ahmet", "Mehmet", "a matter of debt");  
	Email email2("we learning C++",  "ayse", "fatma", "Cse241");  
	
	File file1("Contents about your debt", "dept.txt"); 
	File file2("Contents about some C++ file","file.txt"); 

	cout << "debt?" << endl;
	
	if (ContainsKeyword(email1,"debt")) 
		cout << " Email1" << endl;
	if (ContainsKeyword(email2,"debt"))
		cout << " Email2" << endl;
	if (ContainsKeyword(file1,"debt")) 
		cout << " File1" << endl;
	if (ContainsKeyword(file2,"debt")) 
		cout << " File2" << endl; 

	file2.setPathname("c:");
	
	cout << "After assignment file2=file1 and file2.setPathname(\"c:\"): "<<endl;
	cout << "File1's path = " << file1.getPathname() << endl;
	cout << "File2's path = " << file2.getPathname() << endl;

    return 0;
}