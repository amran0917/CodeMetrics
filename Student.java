public class Student{

	/* some variables*/
   	private String name;
	private String regNumber;
	protected String deptName;
	private int age;
    
	//this is a constructor
	public Student(String name, String reg, String dept, int age){
		this.name = name;
		this.regNumber = reg;
		this.deptName = dept;
		this.age = age;
	}
	public String getName(){
		return this.name;
	}
    
	public String getRegName(){
		return this.regName;
	}
    
	public String getDeptName(){
		return this.deptName;
	}
    
	public int age(){
		return this.age;
	}
    
	public boolean checkDepartmet(String deptCheck){
		return deptName.equals(deptCheck);
	}
    
	public boolean checkAgeGreatedThan18(){
		return age >= 18 ? true : false ;
	}
    
	public String toString(){
		return "Name: " + name + "; Department: " + deptName;
	} 
}
