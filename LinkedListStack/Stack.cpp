#include "Stack.h"

void Stack::Push( int val )
{
	if( Size() == 0 )
	{
		top = new Element{ val };
	}
	else
	{
		Element* oldtop = top; //old top element
		top = new Element{ val, oldtop };
		oldtop->next = top;
	}
}

int Stack::Pop()
{
	if( Size() == 0 )
		return -1;
	else
	{
		Element* newtop = top->prev;
		int rvalue = top->content;
		delete top;
		top = newtop;
		if( top )
			top->next = nullptr;
		return rvalue;
	}
}

int Stack::Size() const
{
	int count = 0;
	if( !top )
		return count;
	else
	{
		Element* temp = top;
		count++;
		while( temp->prev )
		{
			temp = temp->prev;
			count++;
		}
		return count;
	}
}

bool Stack::Empty() const
{
	if( Size() == 0 )
		return true;
	else
		return false;
}
