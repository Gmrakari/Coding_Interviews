#include <iostream>
#include <cstring>
using namespace std;

void Reverse(char *pBegin,char *pEnd)
{
	if(pBegin == NULL || pEnd == NULL)
		return ;

	while( pBegin < pEnd )
	{
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;

		pBegin++,pEnd--;
	}
}

char* ReverseSentence(char *pData)
{
	if( pData == NULL )
		return NULL;

	char* pBegin = pData;
	char* pEnd = pData;
	while(*pEnd != '\0')
			pEnd++;
	pEnd--;
	
	//reverse the whole sentense
	Reverse(pBegin,pEnd);

	//reverse the sentense of the  word
	pBegin = pEnd = pData;
	while( *pBegin != '\0' )
	{
		if( *pBegin == ' ' )
		{
			pBegin++;
			pEnd++;
		}
		else if( *pEnd == ' ' || *pEnd == '\0' )
		{
			Reverse(pBegin,--pEnd);
			pBegin = ++pEnd;
		}
		else
		{
			pEnd++;
		}
	}
	return pData;
}

int main(int argc,const char* argv[])
{
	void Reverse(char *pBegin,char *pEnd);
	char buf[] = "i am a student!";
	int length = strlen(buf);
	char* p1 = buf;
	char* p2 = buf + length - 1;

	/*

	Reverse(p1,p2);

	int i = 0;
	while(buf[i] != '\0')
	{
		printf("%c",buf[i]);
		i++;
	}
	cout << endl;
	
	printf("%s\n",buf);

	cout << buf;
	cout << endl;
	
	*/

	char* ReverseSentence(char *pData);
	ReverseSentence(p1);

	cout << buf << endl;
}
