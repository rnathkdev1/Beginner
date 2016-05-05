public class student implements Comparable  <student>{

    private int roll;
    private String name;
    private int gpa;
    
    public student(int roll, String name, int gpa){
        
        this.name=name;
        this.roll=roll;
        this.gpa=gpa;
    }
    
    public String toString(){
        return("Name: "+this.name+" Roll: "+this.roll+" GPA: "+this.gpa);
    }
    
    public int compareTo(student newStud){
        if (this.gpa>newStud.gpa)
            return 1;
        else if (this.gpa<newStud.gpa)
            return -1;
        else return 0;
    }

        public static void main(String args[]){
        student Ram = new student (1,"Ramnath",4);
        student Varun=new student(2,"Varun",3);
        
        //Ram.display();
        //Varun.display();
        
        int result=Ram.compareTo(Varun);
        
        if (result<0)
            System.out.println("Ram<Varun");
        else if (result>0)
            System.out.println("Ram>Varun");
        else
            System.out.println("Ram=Varun");
        
    }

    
}