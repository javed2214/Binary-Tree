// Program to Count Occurences of Anagrams in a String
// Brute Force Approach

#include<bits/stdc++.h>
using namespace std;

int checkAnagram(string s1, string s2){

	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end());

	if(s1==s2) return 1;
	return 0;
}

int main(){

	string str="forxxorfxdofr";
	string p="for";
	string s;

	int n1=str.length();
	int n2=p.length();

	int c=0;
	int x=3;

	for(int i=0;i<=n1-n2;i++){
		s=str.substr(i,i+x);
		if(checkAnagram(s,p)){
			cout<<s<<" ";
			c++;
		}
		x--;
	}
	cout<<"\nNo of Anagrams: "<<c;

	return 0;
}