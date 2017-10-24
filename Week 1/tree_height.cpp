#include<iostream>
#include<vector>
#include<algorithm>

using namespace std ;

class TreeHeight{

	int n;
	vector<int> parent ;

	public:
		void read(){

			cin >> n ;
			parent.resize(n) ;
			for(int i = 0 ; i < n ; i++ )
           		   cin >> parent[i] ;
		}

		int computeHeight(){

			int maxheight = 0 ;
			vector<int> heights ;
			for(int i = 0 ; i < n ; i++ )
			   heights.push_back(0) ;
			for(int vertex = 0 ; vertex < n ; vertex++ ){
				if( heights[vertex] != 0 ) continue ;
				int height = 0 ;
				for(int i = vertex ; i != -1 ; i = parent[i] ){
					if( heights[i] != 0 ){
						height += heights[i] ;
						break ;
					}
					height++ ;
				}
				maxheight = max(maxheight, height) ;
				for(int i = vertex ; i != -1 ; i = parent[i] ){
					if( heights[i] != 0 ) break ;
					heights[i] = height-- ;
				}
			}
			return maxheight ;
		}
};

int main(){

	ios_base::sync_with_stdio(0) ;
	TreeHeight tree ;
	tree.read() ;
	cout << tree.computeHeight() << endl ;
}
