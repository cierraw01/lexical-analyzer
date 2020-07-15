
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// returns count of non-overlapping occurrences of 'sub' in 'str'
int countSubstring(const string& str, const string& sub)
{
	if (sub.length() == 0) return 0;
	int count = 0;
	for (int offset = str.find(sub); offset != string::npos; 
		offset = str.find(sub, offset + sub.length()))
	{
		++count;
	}
	return count;
}

int countWordCount(string& str)
{  //ok so copy str one by one into another string, then if its numerical of two spaces in a row delete/skip
  string noNum;
  for(int i = 0; i< (signed) (str.length()); i++){
    if(!isdigit(str[i])){
      noNum+=str[i];
    }
  }
  string noSpacesNum;
  for(int i = 0; i<(signed)(noNum.length()); i++){
    if(!(noNum[i-1] == ' ' && noNum[i]== ' ')){
      noSpacesNum+=noNum[i];
    }
  }
  return countSubstring(noSpacesNum," ")+1;
  
}

int uniqueWords(string& str)
{
  string noNum;
  for(int i = 0; i< (signed) (str.length()); i++){
    if(!isdigit(str[i])){
      noNum+=str[i];
    }
  }
  string noSpacesNum;
  for(int i = 0; i<(signed)(noNum.length()); i++){
    if(!(noNum[i-1] == ' ' && noNum[i]== ' ')){
      noSpacesNum+=noNum[i];
    }
  }
  string newStr;
  for(int i = 0; i<(signed)(noSpacesNum.length()); i++){
    if(!(noSpacesNum[i]== '.')){
      newStr+=noSpacesNum[i];
    }
  }
  string finalStr = newStr + " ";
  int count = 0;
  int countSub = 0;
  int finder = 0;
  string mini = "";
  while (!(finalStr == "")){
    for(int i; i<(signed)(finalStr.length()); i++){
      if(!(finalStr[i]==' ')){
        mini+=finalStr[i];
      }
      else{
        mini+=finalStr[i];
        count++;
        countSub = countSubstring(finalStr,mini);
        for(int x = 0; x<countSub; x++){
          finder = finalStr.find(mini);
          finalStr.erase(finder,mini.length());
        }
      }
    }
  }
  return count;
}  
//make sure it doesnt count multiples

int lexicalDensity(string& str)
{
  return uniqueWords(str)/countWordCount(str);
}

int main()
{
  string source = ("I was born in Lousiana down on the ol bayou raised on shrimps and catfish mamas good gumbo. I got the ramblin fever. Said goodbye to ma and pa. Crossed that ol red river and this is what I saw. I saw miles and miles of Texas 1000 stars up in the sky. I saw miles and miles of Texas gonna live here till I die.");
	cout << "substring count: " << countSubstring(source, "is")        << '\n';
  cout << "word count: " << countWordCount(source) << '\n';
  cout << "sentences count: " << countSubstring(source,".") << '\n';
  cout << "average number of words per sentence: " << countWordCount(source)/(double)(countSubstring(source, ".")) <<  '\n';
  cout << "lexical density: " << lexicalDensity(source) << '\n';
  return 0;
}
