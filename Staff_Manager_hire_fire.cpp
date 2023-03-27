#include <iostream>
#include <string>

class Human
{
public:
    std::string name;
    std::string surname;
    int age;
    Human()
    {
      this->name = "";
      this->surname = "";
      this->age = 0;
    }
    Human(std::string name,std::string surname,int age)
    {
      this->name = name;
      this->surname = surname;
      this->age = age;
    } 
};
//Employee class
class Employee :public Human
{
public:
    std::string company;
    int salary;
    Employee(std::string name, std::string surname, int age , std::string company , int salary)
		{
		        this->name = name;
		   	this->surname = surname;
		        this->age = age;
			this->company = company;
			this->salary = salary;
		}
    Employee() : Human()
		{
			this->company = "";
			this->salary = 0;
		}
};
//Staff Class
class Staff :public Employee
{
public:
  std::string proffesion;
  std::string level;

    Staff(std::string name,std::string surname,int age,std::string company,int salary ,std::string proffesion,std::string level) 
  	  	{
		        this->name = name;
                  	this->surname = surname;
		        this->age = age;
		    	this->company = company;
		     	this->salary = salary;
    			this->proffesion = proffesion;
    			this->level = level;
    		}
        
    Staff() : Employee()
    {
      this->proffesion = "";
      this->level = "";
    }
};
//Manager Class
class Manager:public Employee
{
public:
  int count_staffs = 0;
  Staff arr[5]={};
  void hire(Staff& obj)
  {
      if(count_staffs<5)
      {
        arr[count_staffs]=obj;
        count_staffs++;
      }
  }
  void fire(Staff& obj)
  {
      if(count_staffs>0)
      {
        bool tryfind = true;
        for(int i = 0, j = 0; i < count_staffs; i++ , j++)
	{ 
          if (tryfind)
	  {
            if((arr[i].name==obj.name)||(arr[i].surname==obj.surname)||(arr[i].age==obj.age)||(arr[i].company==obj.company)||(arr[i].salary==obj.salary)) 
            {
              j++;
              count_staffs--;
              tryfind=false;
            }
          }
          arr[i]=arr[j];
	}
      }
  }
  void show_staffs()
		{ 
      std::cout<<"staffs count: "<< count_staffs << std::endl;
			for(int i=0;i<count_staffs;i++)
			{ 
				std::cout<<arr[i].name<<' '<<arr[i].surname<<' '<<arr[i].age<<' '<<arr[i].company<<' '<<arr[i].salary<<std::endl;
			}
		}
  Manager(std::string name,std::string surname,int age,std::string company,int salary) 
  	  	{
     		        this->name = name;
       		   	this->surname = surname;
        		this->age = age;
		    	this->company = company;
		     	this->salary = salary;
    		}
  Manager() : Employee()
	{
	  count_staffs=0;
  }
};

int main()
{
  Staff worker1("Albert","Arakelyan",27,"RandomCompany1",80000,"Engineer","Junior");
  Staff worker2("Ben","Smith",38,"RandomCompany2",90000,"Front-end","Junior");
  Staff worker3("John","Johnson",44,"RandomCompany3",190000,"Back-end","Middle");
  Staff worker4("Anna","Davis",33,"RandomCompany4",120000,"QA","Junior");
  Staff worker5("Robin","Miller",26,"RandomCompany5",320000,"Front-end","Senior");
  Staff worker6("Gorge","Hill",17,"RandomCompany6",320000,"Front-end","Senior");

  Manager manager1;
  //add 5
  manager1.hire(worker1);
  manager1.hire(worker2);
  manager1.hire(worker3);
  manager1.hire(worker4);
  manager1.hire(worker5);
  //fire 1
  manager1.fire(worker2);
  //add 1
  manager1.hire(worker6);
  //all work
  manager1.show_staffs();

  return 0;
}
