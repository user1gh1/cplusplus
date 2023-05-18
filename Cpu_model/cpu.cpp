#include <iostream>
#include <vector>
#include <bitset>
#include <cassert>

class Reg
{
private:
	std::vector<int> reg_mem;
public:
	Reg()
	{
		reg_mem.resize(6);
	}
	void write_reg(int address, int data) 
	{
		//be care , Don't give index Out of Range
		assert ((address >= 0) && (address < reg_mem.size() ));
	    reg_mem[address] = data;
	}
	int read_reg(int address)
	{
		//be care , Don't give index Out of Range
		assert ((address >= 0) && (address < reg_mem.size() ));
		return reg_mem[address];
	}
	void print()
	{
		for(int i = 0; i < reg_mem.size(); i++)
		{
			std::cout << reg_mem[i] << ' ';
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
		ozu.resize(512); // for avoid to rewrite instruction code use 0-255 and 256-512 for data
    }

    int read(int address) {
		//be care , Don't give index Out of Range
		assert ((address >= 0) && (address < ozu.size() ));
        return ozu[address];
    }

    void write(int address, int data) {
		//be care , Don't give index Out of Range
		assert ((address >= 0) && (address < ozu.size() ));
        ozu[address] = data;
    }
	void print()
	{
		for(int i = 0; i < ozu.size(); i++)
		{
			std::cout << ozu[i] << ' ';
		}
		std::cout << "this ozu" << std::endl;
	}
};

class Cpu
{
private:
	Alu alu;
	Ram ram;
	Reg reg;
	int tasks; 
	int code;
public:
	Cpu()
	{
		tasks = 0;
		code = 0;
	}
	
	void fetch() 
	{
		code = ram.read(tasks-1);
		reg.write_reg(0, (code >> 27) & 0b1111 ); //	  4 bits Opcode
		reg.write_reg(1, (code >> 18) & 0b111111111 ); // 9 bits Ram_save pointer 
		reg.write_reg(2, (code >> 9) & 0b111111111 ); //  9 bits Pointer_first argument
		reg.write_reg(3, (code & 0b111111111) );//		  9 bits Pointer_second argument
		reg.write_reg(4, (reg.read_reg(2)) ); //		  Data first argument
		reg.write_reg(5, (reg.read_reg(3)) ); //		  Data second argument
	}

	void decode()
	{
		int opcode = reg.read_reg(0);
		int rampointer = reg.read_reg(1);
		int op1 = reg.read_reg(4); 
		int op2 = reg.read_reg(5);
		switch(opcode)
		{
			case 1: //set 
				ram.write(rampointer,op1);
				break;
			case 2:
				ram.write(rampointer, alu.add(op1,op2));
				break;
			case 3:
				ram.write(rampointer, alu.subtract(op1,op2));
				break;
			case 4:		
				ram.write(rampointer, alu.multiply(op1,op2));
				break;
			case 5:
				ram.write(rampointer, alu.divide(op1,op2));
				break;
			case 6:
				ram.write(rampointer, alu.bitwiseOr(op1,op2));
				break;
			case 7:
				ram.write(rampointer, alu.bitwiseAnd(op1,op2));
				break;
			case 8:
				ram.write(rampointer, alu.bitwiseXor(op1,op2));
				break;
			case 9:
				ram.write(rampointer, alu.bitwiseNot(op1));
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
		//be care , Don't give programs more then memory place
		assert (program.size() < 512);

		for (int i = 0; i < program.size(); i++) {
            ram.write(i, program[i]);
			tasks++;
        }
    }
	void print()
	{
		std::cout << "this Reg " << std::endl;
		reg.print();
		std::cout << std::endl;
		ram.print();

	}
};

int main() {
	Cpu cpu;
	cpu.loadProgram({135004159});
	cpu.exe();
	cpu.print();
    return 0;
}
