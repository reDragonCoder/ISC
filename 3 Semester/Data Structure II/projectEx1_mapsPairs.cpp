// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

//NAMESPACE
using namespace std;

//FUNCTIONS
bool uppercase(string& word){
    for(auto& c: word) 
        if (c==' '){
            continue; 
        } else{
            if(!isupper(static_cast<unsigned char>(c))) 
                return false;
        }
    return true;
}

bool find(vector<set<string>>& students, string lookfor, int num){
    bool here=false;
    for (int i = 0; i < num; i++){
        if (students[i].find(lookfor)!=students[i].end()){
            students[i].erase(lookfor);
            here=true;
        }
    }
    return here;
}

bool sortByVal(const pair<string, int> &a, const pair<string, int> &b){ 
    return (a.second > b.second); 
} 

//MAIN
int main(){
    int endTestCases=1, num=0, numAux=-1;
    string subject;
    bool end = false;
    vector <string> signUpSheet;
    vector <string> projects;
    vector<set<string>> students;
    map<string, int> summary;
    vector<pair<string, int>> vec;
    while (!end){
        do{
            getline(cin, subject);
            if (subject!="1"){
                signUpSheet.push_back(subject);
            }
        }while (subject !="1");
        cin>>endTestCases;
        if (endTestCases==0){
            end = true;
        }
    }
    for (int i = 0; i < signUpSheet.size(); i++){
        if (uppercase(signUpSheet[i])){
            projects.push_back(signUpSheet[i]);
            num++;
        }
    }
    students =  vector<set<string>>(num);
    for (int i = 0; i < signUpSheet.size(); i++){
        if (uppercase(signUpSheet[i])){
            numAux++;
        } else {
            if (students.empty()){
                students[numAux].insert(signUpSheet[i]);
            }else if(find(students,signUpSheet[i],numAux)==false){
                students[numAux].insert(signUpSheet[i]);
            }
        }
    }
    for (int i = 0; i < num; i++){
        summary[projects[i]] = students[i].size();
    }

    for(auto j : summary){
        vec.push_back(make_pair(j.first, j.second));
    }

    sort(vec.begin(), vec.end(), sortByVal);

    cout<<endl;
    for (int i = 0; i < vec.size(); i++){
		cout << vec[i].first << ": " << vec[i].second << endl;
	}
}