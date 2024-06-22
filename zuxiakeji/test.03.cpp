#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

struct Task {
  std::vector<Task*> dependencies; // 
};

struct Executor {
    void run(Task*);
    void wait();
};

void schedule(Executor executor &Executor, std::vector<Task*> dag) {
    unordered_map<Task*, int> degree;
    for (int i = 0; i < dag.size(); i++) { // 首先用哈希表记录一下每个节点的入度
        degree[dag[i]] = dag[i]->dependencies.size();
    }

    std::queue<Task*> task_q;
    for (int i = 0; i < dag.size(); i++) { // 然后将入度为0的放入队列
           if (degree[dag[i]] == 0) {
            task_q.push(dag[i]);
           }
    }

    while (!task_q.empty()) {  //如果队列不为空
        Task* task = task_q.front();
        task_q.pop();   // 队头结点出队
        executor.run(task); // 执行任务
        executor.wait();

        for (int j = 0; j < task->dependencies.size(); j++) { // 再更新节点的入度数
            degree[task->dependencies[j]]--;
            if (degree[task->dependencies[j]] == 0) { // 如果节点的入度为0，则入队
                task_q.push(task->dependencies[j]);
            }
        }
    }
}
