#include<iostream>
using namespace std;
#include<bits/stdc++.h>
vector<int> twoSum(vector<int> &numbers, int target)
{
    //Key is the number and value is its index in the vector.
    
    // VVIP## Traverse and check and add elements in the map 
    // so that there wont be any jhanjat for duplicate elements!!!!
    
	unordered_map<int, int> hash;
	vector<int> result;
	for (int i = 0; i < numbers.size(); i++) {
		int numberToFind = target - numbers[i];

            //if numberToFind is found in map, return them
		if (hash.find(numberToFind) != hash.end()) {
            
			result.push_back(hash[numberToFind]);
			result.push_back(i );			
			return result;
		}

            //number was not found. Put it in the map.
		hash[numbers[i]] = i;
	}
	return result;
}
int main(){
    
}