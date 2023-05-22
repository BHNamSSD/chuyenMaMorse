#include <iostream>
#include <string>
#include <fstream>
const int BCC = 26;
//mang morse
std::string* getStringMaMorse()
{
	int cLine = 0;
	std::string *mString = new std::string[BCC];//mang ma morse
	std::ifstream file("ma.txt");
	if(!file)
	{
		std::cout << "erro";
	}
	else
	{
		std::string line;
		//nap mang
		while(std::getline(file,line))
		{	
			mString[cLine] = line;
			cLine++;
			//std::cout << cLine;		
		}
	}
	file.close();
	return mString;
}
std::string* getStringBCC()
{
	std::string* mStringBCC = new std::string[BCC];//mang chua cai
	std::ifstream file("ma2.txt");
	int cLineBCC = 0;
	if(!file)
	{
		std::cout << "erro";
	}
	else
	{
		std::string lineBCC;
		while(std::getline(file,lineBCC))
		{
			mStringBCC[cLineBCC] = lineBCC;
			cLineBCC++;
		}
	}
	file.close();
	return mStringBCC;
}


int getBCC(std::string s, std::string* mBCC)
{
	for(int i=0;i<BCC;i++)
	{
		if(s == mBCC[i])
		{
			return i;
		}
	}
	
	return -1;
}

std::string getMM(int viTri, std::string* mMM)
{
	for(int i=0;i<BCC;i++)
	{
		if(viTri == i)
		{
			return mMM[i];
		}
	}
	return "#";
}


//mo doc file
std::string cover(std::string s, std::string* mSMM, std::string* mBCC)
{

	//s = stringTolower(s);
	/*
	for(int i=0;i<cLine;i++)
	{
		std::cout << mString[i] << " ";	
	}
	*/
	std::string sNew; 
	//thuc hien thuat toan
	std::string tam;
	int viTri;
	for(int i=0;i<s.length();i++)
	{
		//gap dau cach
		if(s[i] == ' ')
		{
			sNew += "   ";
			continue;
		}
		std::string newString;
		newString.push_back(s[i]);
		viTri = getBCC(newString, mBCC);
		if(viTri == -1)
		{
			std::cout << "\nerro\n";
		}
		tam = getMM(viTri,mSMM);
		if(tam == "#")
		{
			std::cout <<  "\nerro\n";
		}
		sNew = sNew + tam + " ";
	}
	return sNew;
}


//chuan hoa xua
std::string chuanHoa(std::string sP)
{
	for (char& c : sP) 
	{
        	c = std::tolower(c);
    	}
	std::string s = sP;
	//xoa dau
	int i=0;
	while(i<s.length())
	{
		if(s[i] == ' ')
		{
			s.erase(i,1);
		}
		else
		{
			break;
		}
	}
	//xoa giua	
	i = 0;
	while(i < s.length())
	{
		if(s[i] == ' ' && s[i+1] == ' ')
		{
			s.erase(i,1);
		}
		else
		{
			i++;
		}
	}



	int n2 = s.length();
	if(s[n2-1] == ' ')
	{
		s.erase(n2-1,1);
	}
    	return s;
}

int main()
{
	std::string* mStringMaMorse = getStringMaMorse();
	std::string* mStringBCC = getStringBCC();
	

	std::string s;
	int v;
	std::cout << "nhap ma morse: ";	
	

	std::getline(std::cin, s);
	std::cout << s.length() << "\n";
	s = chuanHoa(s);
	std::cout << s.length() << "\n";

	std::cout << cover(s,mStringMaMorse,mStringBCC);
	
	return 0;
}



















