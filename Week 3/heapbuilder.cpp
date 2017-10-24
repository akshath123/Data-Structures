#include<iostream>
#include<vector>
#include<algorithm>

using namespace std ;

class HeapBuilder{

 private:
	vector<int> data ;
	vector< pair<int, int> > swaps ;

	void writeResponse() const{
		cout << swaps.size() << endl ;
		for(int i = 0 ; i < swaps.size() ; i++ ){
			cout << swaps[i].first << " " << swaps[i].second << endl ;
  		}
        }

	void generateSwaps(){
		for(int i = data.size()/2 ; i >= 0  ; i-- ){
			shiftDown(i) ;
		}
	}

	void shiftDown(int i){
		int min_index = i;
		int l = 2*i + 1 ;
		if( l < data.size() && data[l] < data[min_index] ){
			min_index = l ;
		}
		int r = 2*i + 2 ;
		if( r < data.size() && data[r] < data[min_index] ){
			min_index = r ;
		}
		if( i != min_index ){
			swap(data[i], data[min_index]) ;
			swaps.push_back(make_pair(i, min_index)) ;
			shiftDown(min_index) ;
		}
	}

	void readData(){
		int n ;
		cin >> n ;
		data.resize(n) ;
		for(int i = 0 ; i < n ; i++ ){
			cin >> data[i] ;
		}
 	}

 public:
 	void solve(){

		readData() ;
		generateSwaps();
		writeResponse();
 	}	
} ;

int main(){
 std::ios_base::sync_with_stdio(false) ;
 HeapBuilder heap_builder ;
 heap_builder.solve() ;
 return 0 ;
}
