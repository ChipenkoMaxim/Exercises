#include <iostream>

using namespace std;

// Rewrite the code that finds the agent with the best monthly sales average so
// that it finds the agent with the highest median sales. As stated earlier, the median
// of a set of values is the “one in the middle,” such that half of the other values
// are higher and half of the other values are lower. If there is an even number
// of values, the median is the simple average of the two values in the middle.
// For example, in the set 10, 6, 2, 14, 7, 9, the values in the middle are 7 and 9.
// The average of 7 and 9 is 8, so 8 is the median.



struct agent {
    int numOfMonthlySales = 0;
    int* monthlySales = NULL;
};

void fillAgentSales(agent* agents, int AGENT_NUM) {
    for(int i = 0; i < AGENT_NUM; i++) {
        cout << "Enter number of monthly sales for " << i + 1 << " agent:";
        cin >> agents[i].numOfMonthlySales;
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


int findMedian(int* sales, int num) {
    qsort(sales, num, sizeof(int), comparator);
    int median = 0;
    if(num % 2 == 0) {
        median = findAverageOfTwo(sales[num / 2], sales[(num / 2) - 1]);
    } else {
        median = sales[num / 2];
    }
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