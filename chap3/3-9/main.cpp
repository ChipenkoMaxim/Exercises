#include <iostream>

using namespace std;


// Consider this modification of the sales array: Because salespeople come and
// go throughout the year, we are now marking months prior to a sales agent’s
// hiring, or after a sales agent’s last month, with a –1. Rewrite your highest
// sales average, or highest sales median, code to compensate.


struct agent {
    int numOfMonthlySales = 12;
    int* monthlySales = NULL;
};

void fillAgentSales(agent* agents, int AGENT_NUM) {
    for(int i = 0; i < AGENT_NUM; i++) {
        agents[i].monthlySales = new int[agents[i].numOfMonthlySales];
        cout << "Enter figures of sales for " << i + 1 << " agent:";
        for(int j = 0; j < agents[i].numOfMonthlySales; j++) {
            cin >> agents[i].monthlySales[j];
        }
    }
}

void printAgent(int* sales, int num) {
        for(int j = 0; j < num; j++) {
            cout << sales[j] << " ";
        }
        cout << "\n";
}


void printSalesInfo(agent* agents, int AGENT_NUM) {
    for(int i = 0; i < AGENT_NUM; i++) {
        cout << "Agent number " << i + 1 << " sales: ";
        printAgent(agents[i].monthlySales, agents[i].numOfMonthlySales);
    }
}

int comparator(const void* first, const void* second) {
    int* A = (int*)first;
    int* B = (int*)second;
    return *A - *B;
}

int findAverageOfTwo(int first, int second) {
    return (first + second) / 2;
}

int findStart(int* sales, int num) {
    int start = 0;
    for(int i = 0; i < num; i++) {
        if(sales[i] != -1) {
            start = i;
            break;
        }
    }
    return start;
}


int findMedian(int* sales, int num) {
    qsort(sales, num, sizeof(int), comparator);
    int median = 0;
    int end = num - 1;
    int start = findStart(sales, num);
    if((end + start + 1) % 2 == 0) {
        median = findAverageOfTwo(sales[(end + start + 1) / 2], sales[((end + start + 1) / 2) - 1]);
    } else {
        median = sales[(end + start + 1) / 2];
    }
    cout << "Median is :" << median << "\n";
    return median;
}

 int findHighestMedian(agent* agents, int AGENT_NUM) {
    int highestMedian = findMedian(agents[0].monthlySales, agents[0].numOfMonthlySales);
    for(int i = 1; i < AGENT_NUM; i++) {
        int salesMedian = findMedian(agents[i].monthlySales, agents[i].numOfMonthlySales);
        if(salesMedian > highestMedian) {
            highestMedian = salesMedian;
        }
    }
    return highestMedian;
 }


void releaseMemory(agent** agents, int AGENT_NUM) {
    for(int i = 0; i < AGENT_NUM; i++) {
        delete[] (*agents)[i].monthlySales;
        (*agents)[i].monthlySales = NULL;
    }
    delete[] *agents;
    *agents = NULL;
}

int main() {
    int AGENT_NUM;
    cout << "Enter number of agents: ";
    cin >> AGENT_NUM;
    cout << "\n";
    
    agent* agents = new agent[AGENT_NUM];
    fillAgentSales(agents, AGENT_NUM);
    printSalesInfo(agents, AGENT_NUM);
    int highestMedian = findHighestMedian(agents, AGENT_NUM);
    releaseMemory(&agents, AGENT_NUM);
    cout << "Highest median is equal " << highestMedian;
    return 0;
}