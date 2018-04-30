#pragma once

class Stack
{
public:
	Stack() = default;
	~Stack()
	{
		while( Pop() != -1 )
		{
		}

	}
	Stack( const Stack& other )
	{
		Element* temp = other.top;
		while( temp->prev != nullptr )
		{
			temp = temp->prev;
		}
		if( temp )
		{
			Push( temp->content );
			while( temp->next )
			{
				temp = temp->next;
				Push( temp->content );
			}
		}
	}
	Stack& operator=( const Stack& other )
	{
		while( Pop() != -1 )
		{
		}

		Element* temp = other.top;
		while( temp->prev )
		{
			temp = temp->prev;
		}
		if( temp != nullptr )
		{
			Push( temp->content );
			while( temp->next )
			{
				temp = temp->next;
				Push( temp->content );
			}
		}

		return *this;
	}

	void Push( int val );
	int Pop();
	int Size() const;
	bool Empty() const;
private:
	struct Element
	{
		Element() = default;
		Element( int val )
		{
			content = val;
		}
		Element( int val, Element* ptr )
		{
			content = val;
			prev = ptr;
		}

		int content;
		Element* prev = nullptr;
		Element* next = nullptr;
	};
	Element* top = nullptr;
};