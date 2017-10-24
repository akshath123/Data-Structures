#include<iostream>
#include<vector>
#include<stack>
#include<string>

using namespace std ;

void showstack(stack<char> q){

	while( !q.empty() ){
		cout << q.top() << " " ;
		q.pop();
	}
}

string matchParanthesies(string exp){

	stack<char> resp ;
	stack<int> indexes ;	

	for(int i = 0 ; i < exp.length() ; i++ ){

		if( exp[i] == '[' || exp[i] == '(' || exp[i] == '{' ){
		 resp.push(exp[i]) ;
		 indexes.push(i) ;
		}


		if( exp[i] == ')' ){

			if( resp.empty() || resp.top() != '(' ){
				return to_string(i+1) ;
			}
			resp.pop() ;
			indexes.pop() ;
		}
		else if( exp[i] == '}' ){
			if( resp.empty() || resp.top() != '{' ){
				return to_string(i+1) ;
			}
			resp.pop() ;
			indexes.pop() ;			
		}
		else if( exp[i] == ']' ){
			if( resp.empty() || resp.top() != '[' ){
			  	return to_string(i+1) ;
			}
			resp.pop();
			indexes.pop() ;
		}
	}

	if( !resp.empty() ){
		return to_string((indexes.top()+1));
	}

	return "Success" ;
}

int main(){

	string s ;
	cin >> s ;
	cout << matchParanthesies(s) ;
}
