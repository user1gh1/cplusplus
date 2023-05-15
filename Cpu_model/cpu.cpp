#include <iostream>
#include <vector>
#include <bitset>

class Hdd
{
private:
	std::vector<int> hdd;
public:
	Hdd() 
	{
		hdd.resize(32);
	}
	void writeMemory(int address, int data) 
	{
	    hdd[address] = data;
	}
	void print()
	{
		for(int i = 0; i < hdd.size(); i++)
		{
			std::cout << hdd[i] << ' ';
		}
		std::cout << std::endl;
	}
};

class Alu 
{
public:
	int add(int x, int y) {
        return x + y;
    }

    int subtract(int x, int y) {
        return x - y;
    }

    int multiply(int x, int y) {
        return x * y;
    }

    int divide(int x, int y) {
        if (y == 0) {
		std::cout << "Divide by zero error" << std::endl;
            return 0;
        }
        return x / y;
    }

    int bitwiseOr(int a, int b) {
        return a | b;
    }

    int bitwiseAnd(int a, int b) {
        return a & b;
    }

	int bitwiseXor(int a, int b) {
        return a ^ b;
    }

	int bitwiseNot(int a) {
        return ~a;
    }
};

class Ram
{
private:
	std::vector<int> ozu;
public:
	Ram() {
		ozu.resize(32); // 11111 bytes
    }

    int read(int address) {
        return ozu[address];
    }

    void write(int address, int data) {
        ozu[address] = data;
    }
};

class Cpu
{
private:
	Alu alu;
	Ram ram;
	Hdd hdd;
	int tasks; 
	int inst;
	int hddsize;
public:
	Cpu()
	{
		tasks = 0;
		inst = 0;
	}
	
	void fetch() 
	{
		inst = ram.read(tasks-1);
	}

	void decode()
	{
		int opcode = (inst >> 27) & 0b1111; // 4 bits (16commands)
		int hddpointer = (inst >> 22) & 0b11111; // 5 bits (32sizehdd)
		int op1 = (inst >> 11) & 0x7FF; // 11 bits (number range2047 -2047)
		int op2 = inst & 0x7FF; // 11 bits (number range2047 -2047)
		switch(opcode)
		{
			case 1: //set 
				hdd.writeMemory(hddpointer,op1);
				break;
			case 2:
				hdd.writeMemory(hddpointer, alu.add(op1,op2));
				break;
			case 3:
				hdd.writeMemory(hddpointer, alu.subtract(op1,op2));
				break;
			case 4:		
				hdd.writeMemory(hddpointer, alu.multiply(op1,op2));
				break;
			case 5:
				hdd.writeMemory(hddpointer, alu.divide(op1,op2));
				break;
			case 6:
				hdd.writeMemory(hddpointer, alu.bitwiseOr(op1,op2));
				break;
			case 7:
				hdd.writeMemory(hddpointer, alu.bitwiseAnd(op1,op2));
				break;
			case 8:
				hdd.writeMemory(hddpointer, alu.bitwiseXor(op1,op2));
				break;
			case 9:
				hdd.writeMemory(hddpointer, alu.bitwiseNot(op1));
				break;
			default:
				break;
		}
				
	}
	void exe()
	{
		while(tasks!=0)
		{
			fetch();
			decode();
			tasks--;
		}
	}

	void loadProgram(std::vector<int> program) 
	{
		for (int i = 0; i < program.size(); i++) {
            ram.write(i, program[i]);
			tasks++;
        }
    }
	void hddprint()
	{
		hdd.print();
	}
};

int main() {
	Cpu cpu;
	cpu.loadProgram({266037370,274425978,1209755770});
	cpu.exe();
	cpu.hddprint();
    return 0;
}
