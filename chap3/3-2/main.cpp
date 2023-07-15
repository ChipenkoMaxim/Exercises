#include <iostream>

using namespace std;

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

void printSalesInfo(agent* agents, int AGENT_NUM) {
    for(int i = 0; i < AGENT_NUM; i++) {
        cout << "Agent number " << i + 1 << " sales: ";
        for(int j = 0; j < agents[i].numOfMonthlySales; j++) {
            cout << agents[i].monthlySales[j] << " ";
        }
        cout << "\n";
    }
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
    releaseMemory(&agents, AGENT_NUM);

    return 0;
}