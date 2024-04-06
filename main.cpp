#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
class recipe{
    public :
        string name;
        string ingredients[100];
        int calories;
        string category;
        recipe* next;
        int n1;
};
void dis(string s1);
int main(){
    int n;
    ifstream file;
    file.open("file.csv");
    string line="";
    while(getline(file,line)){
        recipe* temp = new recipe;
        stringstream input(line);
        string tem;
        getline(input,temp->name,',');
        getline(input,tem,',');
        temp->n1=atoi(tem.c_str());
        for(int i=0;i<temp->n1;i++){
            getline(input,temp->ingredients[i],',');
        }
        tem="";
        getline(input,tem,',');
        temp->calories=atoi(tem.c_str());
        getline(input,temp->category);
        add(temp);
        line="";
    }
    file.close();
    cout << "Enter 1 to add recipe\nEnter 2 to display all recipe\nEnter 3 to find recipe which can be made using a particular ingredient\nEnter 4 to find using category\nEnter 5 to find details of a particular dish\nEnter 6 to plan a single meal for you if you are confused\nEnter 7 to plan your meal for a day\n0 to end\n";
    cin >> n;
    while(n){
        if(n==1){
            cout << "Enter recipe name to be entered : ";
            recipe* temp=new recipe;
            cin >> temp->name;
            cout << "Enter the no of ingredients requirded : ";
            int n1;
            cin >> n1;
            temp->n1=n1;
            cout << "Enter name of all the ingredients we need with entering enter after typing the name of each ingredients "<< endl;
            for(int i=0;i<n1;i++){
                cin >> temp->ingredients[i];
            }
            cout << "Enter  no of calories of the recipe : ";
            cin >> temp->calories;
            cout << "Enter the category ofthe dish : ";
            cin >> temp->category;
            temp->next=nullptr;
            ofstream file1;
            file1.open("file.csv",ios::app);
            line=temp->name+ "," + to_string(temp->n1) + ",";
            for(int i=0;i<temp->n1;i++){
                line=line + temp->ingredients[i] + ",";
            }
            line=line + to_string(temp->calories) + "," + temp->category;
            file1 << "\n" << line ;
            file1.close();
            add(temp);
        }
        else if(n==2){
            display();
        }
        else if(n==3){
            cout << "Enter ingredient : ";
            string s;
            cin >> s;
            search(s);
        }
        else if(n==4){
            string s1;
            cout << "Enter the category : ";
            cin >> s1;
            categ(s1);
        }
        else if(n==5){
            string s1;
            cout << "Enter the name of the recipe you want to find details of : ";
            cin >> s1;
            dis(s1);
        }
        else if(n==6){
            meal_dec();
        }
        else if(n==7){
            meal_planner();
        }
        else{
            cout << "Wrong choice";
        }
       cout << "Enter 1 to add recipe\nEnter 2 to display all recipe\nEnter 3 to find recipe which can be made using a particular ingredient\nEnter 4 to find using category\nEnter 5 to find details of a particular dish\nEnter 6 to plan a single meal for you if you are confused\nEnter 7 to plan your meal for a day\n0 to end\n";
       cin >> n; 
    }
}