#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std ;

class Worker{

	public:
		int id ;
		long long nextfreetime ;
		Worker(int id){
			this->id = id ;
			nextfreetime = 0 ;
		}
};

struct WorkCompare{

  bool operator()(const Worker &w1, const Worker &w2) const{
	if( w1.nextfreetime == w2.nextfreetime ){
		return w1.id > w2.id ;
        }
	else
		return w1.nextfreetime > w2.nextfreetime ;
  } 
};

class JobQueue{

 	private:
		int num_workers ;
		vector<int> jobs ;

		vector<int> assigned_worker ;
		vector<long long> start_time ;

		void writeResponse() const {
			for(int i = 0 ; i < jobs.size() ; i++ ){
				cout << assigned_worker[i] << " " << start_time[i] << endl ;
			}			
		}

		void readData(){
			int m ;
			cin >> num_workers >> m ;
			jobs.resize(m); 
			for(int i = 0 ; i < m ; i++ ){
				cin >> jobs[i] ;
			}
 		}

		void assignWork(){
			assigned_worker.resize(jobs.size());
			start_time.resize(jobs.size()); 

			priority_queue<Worker, vector<Worker>, WorkCompare> pq;

			for(int i = 0 ; i < num_workers ; i++ ){
				pq.push(Worker(i));
			}

			for(int i = 0 ; i < jobs.size() ; i++ ){
				Worker free_worker = pq.top() ;
				pq.pop() ;
				assigned_worker[i] = free_worker.id ;
				start_time[i] = free_worker.nextfreetime ;
				free_worker.nextfreetime += jobs[i] ;
				pq.push(free_worker) ;
			}
		}

	public:
		void solve(){
			readData();
			assignWork() ;
			writeResponse() ;
		}
} ;

int main(){

	JobQueue q ;
	q.solve() ;
	return 0 ;
}
