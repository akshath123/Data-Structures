#include<iostream>
#include<queue>
#include<vector>

using namespace std ;

int main(){

	int S, n ;
	cin >> S >> n ;
	
	queue<int> timeOfArrival ;
	queue<int> processingtime ;

	vector<int> cputime ;

	int start_time ;
	int flag = 0 ;
	int temp ;

	// Time of arrival for new packet and previous packet
	int newpacket_t, prevpacket_t ;

	for(int i = 0 ; i < n ; i++ ){

		cin >> temp ;
		timeOfArrival.push(temp) ;
		cin >> temp ;
		processingtime.push(temp) ;

		if( flag == 0 ){
			flag = 1 ;
			start_time = prevpacket_t = timeOfArrival.front() ;
			timeOfArrival.pop() ;
			cputime.push_back(start_time) ;
		}
		else{
			newpacket_t = timeOfArrival.front() ;
			if( (newpacket_t != prevpacket_t && timeOfArrival.size() != S+1) || processingtime.front() == 0 ){
				start_time += processingtime.front() ;
				start_time = ( start_time < timeOfArrival.front() ) ? timeOfArrival.front() : start_time ;
				cputime.push_back(start_time) ;
				prevpacket_t = newpacket_t ;
				timeOfArrival.pop() ;
				processingtime.pop() ;
			}
			else{
				cputime.push_back(-1) ;
			}	
		}
	}

	for(int i = 0 ; i < cputime.size() ; i++ )
		cout << cputime[i] << endl ;

	return 0 ;
	
}
