/*
有n个任务需要完成（编号1到n），任务之间有一些依赖关系，如果任务a依赖于任务b和c，那么只有当任务b和任务c完成之后才能完成任务a。给定所有的依赖关系，判断这些任务是否能够完成。如果能够完成，请给出一个合法的任务完成序列。

样例：
n=5
1->2,3
3->4

上述样例中任务1依赖于任务2和任务3，任务3依赖于任务4，那么存在合法的任务完成序列4,3,2,1,5
*/

typedef int JobID;

/*
 * deps[id]表示任务id所依赖的任务
 * 如果存在合法的任务完成序列，返回true，否则返回false
 * 合法的任务序列请存放在参数result中（已经分配空间，不需要push_back）
 */
bool jobSchedule(const map<JobID, vector<JobID> > &deps, int n,
                                   vector<JobID> &result) {
    
    int deps_num[n+1];
    for(int i =0 ; i<=n; i++)
        deps_num[i] = 0;
    
    unordered_map<JobID, vector<JobID> > ref_deps;
    map<JobID, vector<JobID> >::const_iterator it = deps.begin();
    for(;it!=deps.end(); ++it){
        int job = it->first;
        vector<JobID> job_list = it->second;
        int job_size = job_list.size();
        for(int i =0; i<job_size; i++){
            if(ref_deps.find(job_list[i])==ref_deps.end()){
                vector<JobID> tmp;
                tmp.push_back(job);
                ref_deps.insert(make_pair(job_list[i], tmp));
            }else{
                ((ref_deps.find(job_list[i]))->second).push_back(job);
            }
            deps_num[job]++;
        }
    }
    
    stack<JobID> undeps;
    for(int i = 1; i<=n; i++){
        if(!deps_num[i])
            undeps.push(i);
    }
    
    for(int i =0; i<n; i++){
        if(undeps.empty())
            return false;
        int job = undeps.top();
        undeps.pop();
        result[i]=job;
        unordered_map<JobID, vector<JobID> >::iterator it;
        it = ref_deps.find(job);
        if(it!=ref_deps.end()){
            vector<JobID> job_list = it->second;
            for(int i=0; i<job_list.size(); i++){
                deps_num[job_list[i]]--;
                if(!deps_num[job_list[i]])
                   undeps.push(job_list[i]);
            }
        }
    }
    return true;
}
